/*****************************************************/
/** @copyright    2018 Alex Sommer All rights reserved.
 *     @author    Alex Sommer
 *    @version    1.0
 *       @date    23.04.18
 *****************************************************/

#ifndef THESIS_TESTCALC_H
#define THESIS_TESTCALC_H

#include <chrono>
#include <thread>
#include <Eigen/Dense>
#include "../Utils/threadexchangedata.h"


namespace TestCalc
{
    /**
     * Example mech changing calculation function done concurrently in
     * a second thread, while GUI is running on another thread.
     * @param test
     */
    void foo(ThreadExchangeData* test) {
        Eigen::Matrix3Xf verts;
        verts.resize(3, 8);
        Eigen::Matrix3Xi indices;
        indices.resize(3, 12);
        indices.col( 0) << 0, 1, 3;
        indices.col( 1) << 3, 2, 1;
        indices.col( 2) << 3, 2, 6;
        indices.col( 3) << 6, 7, 3;
        indices.col( 4) << 7, 6, 5;
        indices.col( 5) << 5, 4, 7;
        indices.col( 6) << 4, 5, 1;
        indices.col( 7) << 1, 0, 4;
        indices.col( 8) << 4, 0, 3;
        indices.col( 9) << 3, 7, 4;
        indices.col(10) << 5, 6, 2;
        indices.col(11) << 2, 1, 5;
        verts.col(0) << -1,  1,  1;
        verts.col(1) << -1,  1, -1;
        verts.col(2) <<  1,  1, -1;
        verts.col(3) <<  1,  1,  1;
        verts.col(4) << -1, -1,  1;
        verts.col(5) << -1, -1, -1;
        verts.col(6) <<  1, -1, -1;
        verts.col(7) <<  1, -1,  1;

        test->vertices = &verts;
        test->indices = &indices;
        test->newData = true;

        // Crashes when thread closes too fast
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));

        // Do some calculations and update mech while GUI is running
    }
}


#endif //THESIS_TESTCALC_H
