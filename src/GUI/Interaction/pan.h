/*****************************************************/
/** @copyright    2018 Alex Sommer All rights reserved.
 *     @author    Alex Sommer
 *    @version    1.0
 *       @date    26.04.18
 *****************************************************/

#ifndef THESIS_PAN_H
#define THESIS_PAN_H

#include <glm/glm.hpp>

/**
 * \class Pan
 *
 * \brief Pan class for panning
 */
class Pan
{
public:
    Pan(int width, int height);

    /**
     * Handles mouse button events. Starts pan on button press and ends it on release.
     * @param x,y screen coordinates of the mouse button press in pixels
     * @param down true for button press, false for release
     */
    void button(float x, float y, bool down);

    /**
     * Checks if a panning is currently active
     * @return true if a panning is currently active, false otherwise
     */
    bool isActive() { return m_doPanning; };

    /**
     * Mouse motion handling event. Updates an translation vector representing
     * the current panning.
     * \note translation vector needs to be updated to model scale
     * @param x,y screen coordinates of the current mouse position in pixels
     * @param[out] translation output parameter for the translation vector
     */
    void motion(float x, float y, glm::vec3& translation);
private:
    // Screen dimensions
    int m_width, m_height;
    // If a panning is currently ongoing
    bool m_doPanning;
    // Start position of an ongoing panning
    glm::vec2 m_startP;
};

#endif //THESIS_PAN_H
