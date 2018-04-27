/*****************************************************/
/** @copyright    2018 Alex Sommer All rights reserved.
 *     @author    Alex Sommer
 *    @version    1.0
 *       @date    24.04.18
 *****************************************************/

#ifndef THESIS_CAMERAOLD_H
#define THESIS_CAMERAOLD_H

#include <glm/glm.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/transform.hpp>
#include <glm/gtc/quaternion.hpp>

/**
 * \class Camera
 *
 * \brief Camera object for viewer placement in OpenGL scene
 */
class Camera
{
public:
    /**
     * Creates a camera object
     * @param pos camera position
     * @param fov field of view (70° is a typical value)
     * @param aspect aspect ration (width/height)
     * @param zNear near field of viewing frustum
     * @param zFar far field of viewing frustum
     */
    Camera(const glm::vec3& pos, float fov, float aspect, float zNear, float zFar) {
        m_perspective = glm::perspective(fov, aspect, zNear, zFar);
        m_position = pos;
        m_forward = glm::vec3(0, 0, 1);
        m_up = glm::vec3(0, 1, 0);

    }

    /**
     * Returns the view projection matrix
     * @return view projection matrix
     */
    inline glm::mat4 getViewProjection() const {
        return m_perspective * glm::lookAt(m_position, m_position + m_forward, m_up);
    }

    /**
     * Returns the postion of the camera
     * @return camera position
     */
    inline glm::vec3 getPos() const {
        return m_position;
    }
private:
    // perspective matrix
    glm::mat4 m_perspective;
    // camera position
    glm::vec3 m_position;
    // forward direction of the camera
    glm::vec3 m_forward;
    // up direction of the camera
    glm::vec3 m_up;
};

#endif //THESIS_CAMERAOLD_H
