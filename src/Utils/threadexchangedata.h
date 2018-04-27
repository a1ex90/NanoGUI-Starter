/*****************************************************/
/** @copyright    2018 Alex Sommer All rights reserved.
 *     @author    Alex Sommer
 *    @version    1.0
 *       @date    24.04.18
 *****************************************************/

#ifndef THESIS_THREADEXCHANGEDATA_H
#define THESIS_THREADEXCHANGEDATA_H

#include <Eigen/Dense>

/**
 * Data that needs to be exchanged between threads
 * try to keep it a minimum amount to prevent from synchronization errors
 */
struct ThreadExchangeData {
    // Vertice to be drawn
    Eigen::Matrix3Xf* vertices;
    // Indice data
    Eigen::Matrix3Xi* indices;
    // Weather there is new data to draw
    bool newData;
};

#endif //THESIS_THREADEXCHANGEDATA_H
