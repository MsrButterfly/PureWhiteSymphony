//
//  Monitor.h
//  PureWhiteSymphony
//
//  Created by Darren Liu on 13-11-30.
//  Copyright (c) 2013年 mashiroLab. All rights reserved.
//

#ifndef PureWhiteSymphony_Monitor_h
#define PureWhiteSymphony_Monitor_h

#include "Base.h"

_MSR_BEGIN_

class Monitor {
    
public:
    
    Monitor() : _glfwMonitor(NULL) {}
    
    Monitor(const Monitor &monitor) : _glfwMonitor(monitor._glfwMonitor) {}
    
    static Monitor *PrimaryMonitor() {
        return new Monitor(glfwGetPrimaryMonitor());
    }
    
    static std::vector<Monitor *> AllMonitors() {
        int size;
        GLFWmonitor **glfwMonitors = glfwGetMonitors(&size);
        std::vector<Monitor *> monitors;
        for (int i = 0; i < size; i++) {
            monitors.push_back(new Monitor(glfwMonitors[i]));
        }
        return monitors;
    }
    
    const std::string name() const {
        return std::string(glfwGetMonitorName(_glfwMonitor));
    }
    
    const Size2D<int> physicalSize() const {
        int width, height;
        glfwGetMonitorPhysicalSize(_glfwMonitor, &width, &height);
        return Size2D<int>(width, height);
    }
    
    const Vertex2D<int> position() const {
        int x, y;
        glfwGetMonitorPos(_glfwMonitor, &x, &y);
        return Vertex2D<int>(x, y);
    }
    
    GLFWmonitor *glfwMonitor() const {
        return _glfwMonitor;
    }
    
    const bool operator==(const Monitor &monitor) const {
        return _glfwMonitor == monitor._glfwMonitor;
    }
    
    const bool operator!=(const Monitor &monitor) const {
        return _glfwMonitor != monitor._glfwMonitor;
    }
    
    const Monitor &operator=(const Monitor &monitor) {
        _glfwMonitor = monitor._glfwMonitor;
        return *this;
    }
    
private:
    
    Monitor(GLFWmonitor *monitor) : _glfwMonitor(monitor) {}
    
    GLFWmonitor *_glfwMonitor;
    
};

_MSR_END_

#endif
