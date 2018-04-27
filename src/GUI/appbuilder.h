/*****************************************************/
/** @copyright    2018 Alex Sommer All rights reserved.
 *     @author    Alex Sommer
 *    @version    1.0
 *       @date    21.04.18
 *****************************************************/

#ifndef THESIS_APPLOADER_H
#define THESIS_APPLOADER_H

#include "application.h"
#include "../Utils/threadexchangedata.h"

/**
 * AppBuilder handels application start to make main function more readable
 */
namespace AppBuilder
{
    /**
     * Builds the application with given parameters for shared use with other threads
     * @param pos shared variable
     */
    static int build(ThreadExchangeData* data)
    {
        try
        {
            nanogui::init();

            /* scoped variables */ {
                nanogui::ref<Application> app = new Application(data);
                app->drawAll();
                app->setVisible(true);
                nanogui::mainloop();
            }

            nanogui::shutdown();
        }
        catch (const std::runtime_error &e)
        {
            std::string error_msg = std::string("Caught a fatal error: ") + std::string(e.what());
#if defined(_WIN32)
            MessageBoxA(nullptr, error_msg.c_str(), NULL, MB_ICONERROR | MB_OK);
#else
            std::cerr << error_msg << std::endl;
#endif
            return -1;
        }
    }
};

#endif //THESIS_APPLOADER_H
