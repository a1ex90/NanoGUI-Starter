/*****************************************************/
/** @copyright    2018 Alex Sommer All rights reserved.
 *     @author    Alex Sommer
 *    @version    1.0
 *       @date    21.04.18
 *****************************************************/

#ifndef THESIS_APPLICATION_H
#define THESIS_APPLICATION_H

#include "nanogui/nanogui.h"
#include <nanogui/entypo.h>
#include "openglcanvas.h"
#include "../Utils/threadexchangedata.h"

#include <Eigen/Dense>

/**
 * \class Application
 *
 * \brief Creates the main application window with everything attached
 * to it. Edit GUI in here.
 */
class Application : public nanogui::Screen
{
public:
    /**
     * Creates an application window for the GUI and OpenGL Output
     * @param data data exchange object between threads
     */
    Application(ThreadExchangeData* data);

    /**
     * Handles application closing if exit key is pressed
     */
    virtual bool keyboardEvent(int key, int scancode, int action, int modifiers);

    /**
     * Draws the application elements
     * @param ctx userinterface context
     */
    virtual void draw(NVGcontext *ctx);
private:
    // OpenGL canvas for drawing objects
    OpenGLCanvas *m_canvas;

    /**
     * Creates the GUI (edit this for new GUI Buttons and Toolbars)
     * @param window main window
     */
    void createGUI(nanogui::Window *window);
};

#endif //THESIS_APPLICATION_H
