/*****************************************************/
/** @copyright    2018 Alex Sommer All rights reserved.
 *     @author    Alex Sommer
 *    @version    1.0
 *       @date    24.04.18
 *****************************************************/

#include <glm/glm.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/transform.hpp>
#include <glm/gtc/quaternion.hpp>

#ifndef THESIS_TRANSFORMOLD_H
#define THESIS_TRANSFORMOLD_H

/**
 * \class Transform
 *
 * \brief Transformation class for position, rotation and scaling transformations
 *        done directly by the shader
 */
class Transform
{
public:
    /**
     * Creates a transformation object
     * @param pos position transformation default 0,0,0
     * @param rot rotation transformation default 0,0,0
     * @param scale scaling transformation default 1,1,1
     */
    Transform(const glm::vec3& pos = glm::vec3(), const glm::vec3& rot = glm::vec3(), const glm::vec3& scale = glm::vec3(1.0f, 1.0f, 1.0f)) :
            m_pos(pos),
            m_rot(rot),
            m_scale(scale) {}

    /**
     * Returns the model matrix resulting from the present transformation
     * @return model matrix
     */
    inline glm::mat4 getModel() const {
        glm::mat4 posMatrix = glm::translate(m_pos);
        glm::mat4 scaleMatrix = glm::scale(m_scale);
        glm::mat4 rotMatrix = glm::mat4_cast(m_rot);

        return posMatrix * rotMatrix * scaleMatrix;
    }

    /**
     * Returns the position part of the transformation
     * @return position transformation
     */
    inline glm::vec3& getPos() { return m_pos; }

    /**
     * Returns the rotation part of the transformation
     * @return rotation transformation as quaternion
     */
    inline glm::quat& getRot() { return m_rot; }

    /**
     * Returns the scaling part of the transformation
     * @return scaling transformation
     */
    inline glm::vec3& getScale() { return m_scale; }

    /**
     * Set the position part of the transformation
     * @param pos position transformation
     */
    inline void setPos(const glm::vec3& pos) { m_pos = pos; }

    /**
     * Set the rotation part of the transformation
     * @param rot rotation transformation
     */
    inline void setRot(const glm::quat &rot) { m_rot = rot; }

    /**
     * Set the scaling part of the transformation
     * @param scale position transformation
     */
    inline void setScale(const glm::vec3& scale) { m_scale = scale; }
private:
    // position transformation
    glm::vec3 m_pos;

    // rotation transformation
    glm::quat m_rot;

    // scaling transformation
    glm::vec3 m_scale;
};

#endif //THESIS_TRANSFORMOLD_H
