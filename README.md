# NanoGUI-Starter

This is an example starterproject for nanoGUI. It has an OpenGL canvas with panning, zooming and rotating functions. Futhermore it allows calculations concurrently to UI display with multithreading and variable passing between threads.

## Screenshot

![title picture](https://raw.githubusercontent.com/a1ex90/NanoGUI-Starter/master/resources/screenshot.png)

## Installing

Make sure you have installed and set up path variables for [OpenGL](https://www.khronos.org/opengl/) and [GLM](https://glm.g-truc.net) so CMake can find them. 

Clone [nanogui](https://github.com/wjakob/nanogui) from the git to the ext folder in the project (don't rename the nanogui folder)

```
git clone "https://github.com/wjakob/nanogui.git"
```

Make sure you have all dependencies for nanogui installed on your system.

Set your working direction in your IDE to the root direction of this project to ensure shader loading or change the path to the shader.