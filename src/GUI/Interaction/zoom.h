/*****************************************************/
/** @copyright    2018 Alex Sommer All rights reserved.
 *     @author    Alex Sommer
 *    @version    1.0
 *       @date    26.04.18
 *****************************************************/

#ifndef THESIS_ZOOM_H
#define THESIS_ZOOM_H

#include <glm/glm.hpp>

/**
 * \class Zoom
 *
 * \brief Zoom class for zooming
 */
class Zoom
{
public:
    Zoom(int height);

    /**
     * Handles mouse button events. Starts pan on button press and ends it on release.
     * @param x,y screen coordinates of the mouse button press in pixels
     * @param down true for button press, false for release
     */
    void button(float y, bool down);

    /**
     * Checks if a panning is currently active
     * @return true if a panning is currently active, false otherwise
     */
    bool isActive() { return m_doZooming; };

    /**
     * Mouse motion handling event. Updates an translation vector representing
     * the current panning.
     * \note translation vector needs to be updated to model scale
     * @param x,y screen coordinates of the current mouse position in pixels
     * @param[out] scaling output parameter for the scaling vector
     */
    void motion(float y, float &scale);
private:
    // Screen dimensions
    int m_height;
    // If a zooming is currently ongoing
    bool m_doZooming;
    // Start position of an ongoing zooming
    float m_startP;
};

#endif //THESIS_ZOOM_H
