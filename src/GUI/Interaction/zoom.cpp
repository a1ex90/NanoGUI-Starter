/*****************************************************/
/** @copyright    2018 Alex Sommer All rights reserved.
 *     @author    Alex Sommer
 *    @version    1.0
 *       @date    26.04.18
 *****************************************************/

#include "zoom.h"

/******************************************************
 * Constructors
 *****************************************************/

Zoom::Zoom(int height) {
    m_height = height;
    m_startP = 0.0f;
    m_doZooming = false;
}

/******************************************************
 * Destructor
 *****************************************************/

/******************************************************
 * Public Functions
 *****************************************************/

void Zoom::button(float y, bool down)
{
    if(down) {
        m_doZooming = true;
        m_startP = y;
    } else {
        m_doZooming = false;
    }
}

void Zoom::motion(float y, float &scale) {
    float moveP = y;
    scale = 1.0f + (moveP - m_startP)/m_height;
    m_startP = moveP;
}

/******************************************************
 * Private Functions
 *****************************************************/


