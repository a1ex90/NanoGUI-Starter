/*****************************************************/
/** @copyright    2018 Alex Sommer All rights reserved.
 *     @author    Alex Sommer
 *    @version    1.0
 *       @date    26.04.18
 *****************************************************/

#include "pan.h"

/******************************************************
 * Constructors
 *****************************************************/

Pan::Pan(int width, int height) {
    m_width = width;
    m_height = height;
    m_startP = glm::vec2();
    m_doPanning = false;
}

/******************************************************
 * Destructor
 *****************************************************/

/******************************************************
 * Public Functions
 *****************************************************/

void Pan::button(float x, float y, bool down)
{
    if(down) {
        m_doPanning = true;
        m_startP = glm::vec2(x, y);
    } else {
        m_doPanning = false;
    }
}

void Pan::motion(float x, float y, glm::vec3& translation) {
    glm::vec2 moveP = glm::vec2(x, y);
    translation = glm::vec3(
            (-moveP.x + m_startP.x)/m_width,
            (-moveP.y + m_startP.y)/m_height,
            0.0f
    );
    m_startP = moveP;
}

/******************************************************
 * Private Functions
 *****************************************************/


