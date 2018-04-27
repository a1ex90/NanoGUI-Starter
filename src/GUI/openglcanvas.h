/*****************************************************/
/** @copyright    2018 Alex Sommer All rights reserved.
 *     @author    Alex Sommer
 *    @version    1.0
 *       @date    21.04.18
 *****************************************************/

#ifndef THESIS_OPENGLCANVAS_H
#define THESIS_OPENGLCANVAS_H

#include "nanogui/nanogui.h"
#include "../Utils/threadexchangedata.h"
#include "OpenGL/transform.h"
#include "OpenGL/camera.h"
#include "Interaction/arcball.h"
#include "Interaction/pan.h"
#include "Interaction/zoom.h"

#include <Eigen/Geometry>

#include <glm/glm.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/transform.hpp>
#include <glm/gtc/quaternion.hpp>

/**
 * \class OpenGLCanvas
 *
 * \brief A canvas for OpenGL drawings. Can get fed in data from outside the GUI thread
 * and display them in the drawGL function. Has panning (Left-Mouse-Click), zooming
 * (Middle-Mouse-Click) and rotating (Right-Mouse-Click) functionality.
 */
class OpenGLCanvas : public nanogui::GLCanvas
{
public:
    /**
     * Creates a GLCanvas attached to the specified parent.
     * @param parent widget to attach this GLCanvas to.
     * @param data data exchange object between threads
     */
    OpenGLCanvas(Widget *parent, ThreadExchangeData* data);

    ~OpenGLCanvas() {
        m_shader.free();
    }

    /**
     * Handles application closing if exit key is pressed
     */
    virtual bool keyboardEvent(int key, int scancode, int action, int modifiers) override;

    /**
     * Handles mouse click events for arcball rotation
     */
    virtual bool mouseButtonEvent(const nanogui::Vector2i &p, int button, bool down, int modifiers) override;

    /**
     * Handles mouse motion for arcball rotation
     */
    virtual bool mouseMotionEvent(const nanogui::Vector2i &p, const nanogui::Vector2i &rel, int button, int modifiers) override;

    /**
     * Actual OpenGL drawings
     */
    virtual void drawGL() override;

    /**
     * Overrides the setSize function of widget. Sets the windowsize and
     * furthermore initializes pan, arcball and zoom with the windowsize
     * @param size window size
     */
    void setSize(const nanogui::Vector2i &size);

    /**
     * Switches the mouse interaction mode. Sets the mode to 0
     * if called again with the same mode (unsetting)
     * @param mode 0 = none, 1 = 'pan', 2 = 'zoom', 3 = 'rotate'
     * @return true if set to new mode, false if mode unset
     */
    bool setInteractionMode(int mode, bool active);

private:
    // Shader for OpenGL drawings
    nanogui::GLShader m_shader;
    // Camera Object
    Camera* m_camera;
    // Transform
    Transform* m_transform;
    // Exchange Object for mesh vertices
    Eigen::Matrix3Xf* m_verts;
    // Exchange Object for mesh indices
    Eigen::Matrix3Xi* m_indices;
    // total number of vertices to draw (number of indices)
    int m_drawCount;
    // New data pointer
    bool* m_newData;
    // Mouse interaction mode 0 = none, 1 = 'pan', 2 = 'zoom', 3 = 'rotate'
    int m_mouseMode;
    // Arcball Object for arcball rotation
    Arcball* m_arcball;
    // Pan Object for view panning
    Pan* m_pan;
    // Zoom Object for zooming
    Zoom* m_zoom;
};

#endif //THESIS_OPENGLCANVAS_H
