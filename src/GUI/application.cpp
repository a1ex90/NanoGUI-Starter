/*****************************************************/
/** @copyright    2018 Alex Sommer All rights reserved.
 *     @author    Alex Sommer
 *    @version    1.0
 *       @date    21.04.18
 *****************************************************/

#include "application.h"

/******************************************************
 * Constructors
 *****************************************************/

Application::Application(ThreadExchangeData* data) : nanogui::Screen(Eigen::Vector2i(800, 600), "NanoGUI Starter", false) {
    nanogui::Window *window = new nanogui::Window(this, "OpenGL Canvas");
    window->setPosition(Eigen::Vector2i(15, 15));
    window->setLayout(new nanogui::GroupLayout());

    m_canvas = new OpenGLCanvas(window, data);
    m_canvas->setBackgroundColor({100, 100, 100, 255});
    m_canvas->setSize({400, 400});

    createGUI(window);

    performLayout();
}

/******************************************************
 * Destructor
 *****************************************************/

/******************************************************
 * Public Functions
 *****************************************************/

bool Application::keyboardEvent(int key, int scancode, int action, int modifiers) {
    if (Screen::keyboardEvent(key, scancode, action, modifiers))
        return true;
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        setVisible(false);
        return true;
    } else {
        m_canvas->keyboardEvent(key, scancode, action, modifiers);
    }
    return false;
}

void Application::draw(NVGcontext *ctx) {
    /* Draw the user interface */
    Screen::draw(ctx);
}

/******************************************************
 * Private Functions
 *****************************************************/

void Application::createGUI(nanogui::Window *window) {
    Widget *tools = new Widget(window);
    tools->setLayout(new nanogui::BoxLayout(nanogui::Orientation::Horizontal,
                                            nanogui::Alignment::Middle, 0, 5));

    nanogui::Button *b0 = new nanogui::Button(tools, "Random Color");
    b0->setCallback([this]() { m_canvas->setBackgroundColor(Eigen::Vector4i(rand() % 256, rand() % 256, rand() % 256, 255)); });

    nanogui::Button *btn_pan = new nanogui::ToolButton(tools, ENTYPO_ICON_HAND);
    btn_pan->setChangeCallback([this](bool active) { m_canvas->setInteractionMode(1, active); });
    nanogui::Button *btn_zoom= new nanogui::ToolButton(tools, ENTYPO_ICON_MAGNIFYING_GLASS);
    btn_zoom->setChangeCallback([this](bool active) { m_canvas->setInteractionMode(2, active); });
    nanogui::Button *btn_rotate = new nanogui::ToolButton(tools, ENTYPO_ICON_CW);
    btn_rotate->setChangeCallback([this](bool active) { m_canvas->setInteractionMode(3, active); });
}
