//
//  Window.h
//  PureWhiteSymphony
//
//  Created by Darren Liu on 13-11-30.
//  Copyright (c) 2013年 mashiroLab. All rights reserved.
//

#ifndef PureWhiteSymphony_Window_h
#define PureWhiteSymphony_Window_h

#include "Base.h"

_MSR_BEGIN_

typedef void (*KeyCallback)(int key, int scancode, int action, int mods);
typedef void (*ScrollCallback)(double xoffset, double yoffset);

std::map<GLFWwindow *, KeyCallback> _windowKeyCallbackMap;
std::map<GLFWwindow *, ScrollCallback> _windowScrollCallbackMap;

static void _glfwKeyCallback(GLFWwindow *window, int key, int scancode, int action, int mods) {
    if (!_windowKeyCallbackMap[window]) {
        return;
    }
    _windowKeyCallbackMap[window](key, scancode, action, mods);
}

static void _glfwScrollCallback(GLFWwindow *window, double xoffset, double yoffset) {
    if (!_windowScrollCallbackMap[window]) {
        return;
    }
    _windowScrollCallbackMap[window](xoffset, yoffset);
}

class Window {
    
public:
    
    Window(const Size2D<int> &size, std::string title, Monitor *monitor, Window *share)
    : _size(size), _title(title), _monitor(monitor), _share(share), _glfwWindow(NULL) {}
    
    Window(const Size2D<int> &size, std::string title, Monitor *monitor)
    : _size(size), _title(title), _monitor(monitor), _share(NULL), _glfwWindow(NULL) {}
    
    Window(const Size2D<int> &size, std::string title)
    : _size(size), _title(title), _monitor(NULL), _share(NULL), _glfwWindow(NULL) {}
    
    bool create() {
        if (_glfwWindow) {
            return false;
        } else if (!_monitor || !_monitor -> glfwMonitor()) {
            _glfwWindow = glfwCreateWindow(_size.width, _size.height, _title.c_str(), NULL, NULL);
            if (!_glfwWindow) {
                return false;
            }
        } else if (!_share || !_share -> _glfwWindow) {
            _glfwWindow = glfwCreateWindow(_size.width, _size.height, _title.c_str(), _monitor -> glfwMonitor(), NULL);
            if (!_glfwWindow) {
                return false;
            }
        } else {
            _glfwWindow = glfwCreateWindow(_size.width, _size.height, _title.c_str(), _monitor -> glfwMonitor(), _share -> _glfwWindow);
            if (!_glfwWindow) {
                return false;
            }
        }
        initCallbacks();
        return true;
    }
    
    void destory() {
        if (!_glfwWindow) {
            return;
        }
        glfwDestroyWindow(_glfwWindow);
    }
    
    const bool shouldClose() const {
        return glfwWindowShouldClose(_glfwWindow)? true : false;
    }
    
    void setShouldClose(const bool& shouldClose) {
        glfwSetWindowShouldClose(_glfwWindow, shouldClose? GL_TRUE : GL_FALSE);
    }
    
    const Size2D<int> frameButterSize() const {
        int width, height;
        glfwGetFramebufferSize(_glfwWindow, &width, &height);
        return Size2D<int>(width, height);
    }
    
    void setClipboardString(const std::string& str) {
        glfwSetClipboardString(_glfwWindow, str.c_str());
    }
    
    const std::string clipboardString() {
        return static_cast<std::string>(glfwGetClipboardString(_glfwWindow));
    }
    
    void setKeyCallback(const KeyCallback &keyCallback) {
        if (!_glfwWindow) {
            return;
        }
        glfwSetKeyCallback(_glfwWindow, _glfwKeyCallback);
        _windowKeyCallbackMap[_glfwWindow] = keyCallback;
    }
    
    void setScrollCallback(const ScrollCallback &scrollCallback) {
        if (!_glfwWindow) {
            return;
        }
        glfwSetScrollCallback(_glfwWindow, _glfwScrollCallback);
        _windowScrollCallbackMap[_glfwWindow] = scrollCallback;
    }
    
    void focus() {
        glfwMakeContextCurrent(_glfwWindow);
    }
    
    GLFWwindow *glfwWindow() const {
        return _glfwWindow;
    }
    
    void swapBuffers() {
        glfwSwapBuffers(_glfwWindow);
    }
    
    void initCallbacks() {
        setKeyCallback(NULL);
        setScrollCallback(NULL);
    }
    
    Window &operator=(const Window &window) {
        this -> _size = window._size;
        this -> _title = window._title;
        this -> _monitor = window._monitor;
        this -> _share = window._share;
        this -> _glfwWindow = window._glfwWindow;
        return *this;
    }
    
    const bool operator==(const Window &window) const {
        return this -> _glfwWindow == window._glfwWindow;
    }
    
    const bool operator!=(const Window &window) const {
        return this -> _glfwWindow != window._glfwWindow;
    }
    
    ~Window() {
        _windowKeyCallbackMap.erase(_glfwWindow);
    }
    
private:
    
    Size2D<int>  _size;
    std::string  _title;
    Monitor     *_monitor;
    Window      *_share;
    GLFWwindow  *_glfwWindow;
    
};

_MSR_END_

#endif
