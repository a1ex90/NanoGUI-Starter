/*****************************************************/
/** @copyright    2018 Alex Sommer All rights reserved.
 *     @author    Alex Sommer
 *    @version    1.0
 *       @date    25.04.18
 *****************************************************/

#include "arcball.h"

/******************************************************
 * Constructors
 *****************************************************/

Arcball::Arcball(int width, int height, float radius) {
    m_width = width;
    m_height = height;
    m_startP = glm::vec3();
    if( radius <= 0 ) {
        m_r = glm::min(width, height) / 2.0f;
    } else {
        m_r = radius;
    }

    m_doRotation = false;
}

/******************************************************
 * Destructor
 *****************************************************/

/******************************************************
 * Public Functions
 *****************************************************/

void Arcball::button(float x, float y, bool down)
{
    if(down) {
        m_doRotation = true;
        m_startP = projectOnSphere(x, y, m_r);
    } else {
        m_doRotation = false;
    }
}

void Arcball::motion(float x, float y, float& angle, glm::vec3& axis) {
    glm::vec3 moveP = projectOnSphere(x, y, m_r);
    angle = acos(glm::dot(m_startP, moveP));
    axis = glm::cross(m_startP, moveP);
    m_startP = moveP;
}

/******************************************************
 * Private Functions
 *****************************************************/

glm::vec3 Arcball::projectOnSphere(float x, float y, float r) {
    x = (x - m_width / 2.0f);
    y = -(m_height / 2.0f - y);
    float a = glm::min(r*r, x*x + y*y);
    float z = sqrt(r*r - a);
    float l = sqrt(x*x + y*y + z*z);
    return glm::vec3(x / l, y / l, z / l);
}

