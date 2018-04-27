/*****************************************************/
/** @copyright    2018 Alex Sommer All rights reserved.
 *     @author    Alex Sommer
 *    @version    1.0
 *       @date    25.04.18
 *****************************************************/

#ifndef THESIS_ARCBALL_H
#define THESIS_ARCBALL_H

#include <glm/glm.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/transform.hpp>
#include <glm/gtc/quaternion.hpp>

/**
 * \class Arcball
 *
 * \brief Arcball class for arcball rotations
 */
class Arcball
{
public:
    /**
     * Creates an arcball object for arcball rotations
     * @param width,height screen size in pixels
     * @param radius arcball radius. default value minimum of width and height
     */
    Arcball(int width, int height, float radius = -1.0f);

    /**
     * Handles mouse button events. Starts rotation on button press and ends it on release.
     * @param x,y screen coordinates of the mouse button press in pixels
     * @param down true for button press, false for release
     */
    void button(float x, float y, bool down);

    /**
     * Checks if a rotation is currently active
     * @return true if a rotation is currently active, false otherwise
     */
    bool isActive() { return m_doRotation; };

    /**
     * Mouse motion handling event. Updates an axis angle pair representing
     * the current roation.
     * \note angle axis pair needs to be updated to model coordiantes
     * @param x,y screen coordinates of the current mouse position in pixels
     * @param[out] angle output parameter for the rotation angle
     * @param[out] axis output parameter for the rotation axis
     */
    void motion(float x, float y, float& angle, glm::vec3& axis);
private:
    // screen size in pixels
    int m_width, m_height;
    // arcball radius
    float m_r;
    // if a rotation is currently ongoing
    bool m_doRotation;
    // start position of an ongoing rotation
    glm::vec3 m_startP;

    /**
     * Returns the 3D location as vector of given pixel coordiantes
     * on the 3D Sphere with radius r at the center of the window.
     * @param x,y window coordinates in pixels
     * @param r sphere radius in pixels
     * @return 3D location in pixels
     */
    glm::vec3 projectOnSphere(float x, float y, float r);
};

#endif //THESIS_ARCBALL_H
