/*****************************************************/
/** @copyright    2018 Alex Sommer All rights reserved.
 *     @author    Alex Sommer
 *    @version    1.0
 *       @date    20.04.18
 *****************************************************/

#include "GUI/appbuilder.h"
#include "Calc/testCalc.h"
#include "Utils/threadexchangedata.h"
#include <thread>


int main(int /* argc */, char ** /* argv */) {
    ThreadExchangeData data;
    data.newData = false;

    std::thread guiThread(AppBuilder::build, &data);
    std::thread calcExampleThread(TestCalc::foo, &data);

    guiThread.join();
    calcExampleThread.join();

    return 0;
}