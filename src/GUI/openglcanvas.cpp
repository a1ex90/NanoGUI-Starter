/*****************************************************/
/** @copyright    2018 Alex Sommer All rights reserved.
 *     @author    Alex Sommer
 *    @version    1.0
 *       @date    21.04.18
 *****************************************************/

#include "openglcanvas.h"
/******************************************************
 * Constructors
 *****************************************************/

OpenGLCanvas::OpenGLCanvas(Widget *parent, ThreadExchangeData* data) : nanogui::GLCanvas(parent)
{
    m_camera = new Camera(glm::vec3(0,0,-3), 70.0f, 1.0f, 0.01f, 1000.0f);

    m_transform = new Transform();
    
    m_shader.initFromFiles("basicShader", "src/GUI/Shader/basicShader.vs", "src/GUI/Shader/basicShader.fs");

    m_verts = data->vertices;
    m_indices = data->indices;
    m_drawCount = 0;
    m_newData = &data->newData;
    m_mouseMode = 0;

    m_shader.bind();

    m_transform->setScale(glm::vec3(0.5f, 0.5f, 0.5f));

    nanogui::Vector4f color = nanogui::Vector4f(1.0f, 0.0f, 0.0f, 1.0f);

    m_shader.setUniform("color", color);
}

/******************************************************
 * Destructor
 *****************************************************/

/******************************************************
 * Public Functions
 *****************************************************/

bool OpenGLCanvas::keyboardEvent(int key, int scancode, int action, int modifiers) {
    if (key == GLFW_KEY_R && action == GLFW_PRESS) {
        m_transform->setPos(glm::vec3(0.0f, 0.0f, 0.0f));
        m_transform->setRot(glm::quat());
        m_transform->setScale(glm::vec3(1.0f, 1.0f, 1.0f));
        return true;
    }
    return false;
}

bool OpenGLCanvas::mouseButtonEvent(const nanogui::Vector2i &p, int button, bool down, int modifiers)
{
    if (button == GLFW_MOUSE_BUTTON_LEFT) {
        if(m_mouseMode == 0 || m_mouseMode == 1) {
            m_pan->button(p[0], p[1], down);
        } else if(m_mouseMode == 2) {
            m_zoom->button(p[1], down);
        } else if(m_mouseMode == 3) {
            m_arcball->button(p[0], p[1], down);
        }
        return true;
    }

    if (button == GLFW_MOUSE_BUTTON_MIDDLE && m_mouseMode == 0 ) {
        m_zoom->button(p[1], down);
        return true;
    }

    if (button == GLFW_MOUSE_BUTTON_RIGHT && m_mouseMode == 0 ) {
        m_arcball->button(p[0], p[1], down);
        return true;
    }
    return false;
}

bool OpenGLCanvas::mouseMotionEvent(const nanogui::Vector2i &p, const nanogui::Vector2i &rel, int button, int modifiers)
{
    if(m_arcball->isActive()) {
        float angle;
        glm::vec3 axis;
        m_arcball->motion(p[0], p[1], angle, axis);
        // transfer axis to object coords
        axis = glm::inverse(glm::mat3(m_transform->getModel())) * axis;
        m_transform->setRot(glm::rotate(m_transform->getRot(), angle, axis));
    } else if(m_pan->isActive()) {
        glm::vec3 translation;
        m_pan->motion(p[0], p[1], translation);
        // transfer axis to object coords
        translation = glm::inverse(glm::mat3(glm::scale(m_transform->getScale()))) * translation;
        m_transform->setPos(m_transform->getPos() + translation);
    } else if(m_zoom->isActive()) {
        float scale = 1;
        m_zoom->motion(p[1], scale);
        // apply to scaling transform
        m_transform->setScale(m_transform->getScale() * scale);
    }
    return false;
}

void OpenGLCanvas::drawGL()
{
    m_shader.bind();
    if(*m_newData) {
        // New data to draw arrived
        m_drawCount = m_indices->cols();
        m_shader.uploadIndices(*m_indices);
        m_shader.uploadAttrib("position", *m_verts);
        *m_newData = false;
    }

    glm::mat4 cameraU = m_camera->getViewProjection();
    glm::mat4 modelU = m_transform->getModel();

    glUniformMatrix4fv(m_shader.uniform("model", 1), 1, GL_FALSE, &modelU[0][0]);
    glUniformMatrix4fv(m_shader.uniform("camera", 1), 1, GL_FALSE, &cameraU[0][0]);

    glEnable(GL_DEPTH_TEST);

    m_shader.drawIndexed(GL_TRIANGLES, 0, m_drawCount);

    glDisable(GL_DEPTH_TEST);
}

void OpenGLCanvas::setSize(const nanogui::Vector2i &size) {
    mSize = size;
    m_arcball = new Arcball(size[0], size[1]);
    m_pan = new Pan(size[0], size[1]);
    m_zoom = new Zoom(size[1]);
}

bool OpenGLCanvas::setInteractionMode(int mode, bool active) {
    if(!active) {
        // Unset mode
        m_mouseMode = 0;
        return false;
    } else {
        // New mode
        m_mouseMode = mode;
        return true;
    }
}

/******************************************************
 * Private Functions
 *****************************************************/
