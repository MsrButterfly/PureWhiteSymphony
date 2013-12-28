//
//  main.cpp
//  PureWhiteSymphony
//
//  Created by Darren Liu on 13-11-30.
//  Copyright (c) 2013年 mashiroLab. All rights reserved.
//

#include <iostream>
#include "include/Base.h"

MSR::Window *window = nullptr;
std::vector<MSR::Shape *> shapes;

float x = 0.0f;
float y = 0.0f;

static void keyCallback(int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_RELEASE) {
        window -> setShouldClose(true);
    }
}

static void scrollCallback(double xoffset, double yoffset) {
//    MSR::Size2D<int> size = window -> frameButterSize();
//    float ratio = 1.f * size.width / size.height;
//    x += xoffset / 100;
//    y -= yoffset / 100;
//    if (x > ratio) {
//        x = -ratio;
//    }
//    if (x < -ratio) {
//        x = ratio;
//    }
//    if (y > 1.f) {
//        y = -1.f;
//    }
//    if (y < -1.f) {
//        y = 1.f;
//    }
    std::cout << MSR::Vertex2D<double>(x, y) << std::endl;
}

int main(int argc, const char * argv[])
{
    if (!MSR::Init()) {
        exit(EXIT_FAILURE);
    }
    
    std::vector<MSR::Monitor *> monitors = MSR::Monitor::AllMonitors();
    for (int i = 0; i < monitors.size(); i++) {
        std::cout << monitors[i] -> name() << std::endl
        << monitors[i] -> physicalSize() << std::endl;
    }
    
    window = new MSR::Window(MSR::Size2D<int>(1280, 720), "Test");
//    window = new MSR::Window(MSR::Size2D<int>(1920, 1080), "Test", MSR::Monitor::PrimaryMonitor());
    
    window -> create();
    window -> setKeyCallback(keyCallback);
    window -> setScrollCallback(scrollCallback);
    window -> focus();
    
//    MSR::Font avenir("/System/Library/Fonts/Avenir.ttc");
    MSR::Playground playground(*window, 7, .15f);
    
    uint32_t texture = MSR::Texture("/Volumes/Backup/Others/Butterfly_flat.png");
    if (!texture) {
        exit(EXIT_FAILURE);
    }
    std::cout << "Texture loading completed: " << texture << std::endl;
    
    while (!window -> shouldClose()) {
        
        MSR::Size2D<int> size = window -> frameButterSize();
        float ratio = 1.f * size.width / size.height;
//        float scale = static_cast<float>(size.height) / 720;
//        avenir.size = 32.f * scale;
        
        {
            glViewport(0, 0, size.width, size.height);
            glClear(GL_COLOR_BUFFER_BIT);
            glClearColor(1.f, 1.f, 1.f, 1.f);
            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();
            glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
            glMatrixMode(GL_MODELVIEW);
        }
        
        
        
        shapes.push_back(&playground);

        for (auto &shape : shapes) {
            shape -> draw();
        }
        
        shapes.clear();
        
        glLoadIdentity();
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, texture);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_QUADS); {
            glTexCoord2f(0.0f, 1.0f); glVertex3f(ratio - 0.3, 0.9f, 0);
            glTexCoord2f(0.0f, 0.0f); glVertex3f(ratio - 0.3, 0.7f, 0);
            glTexCoord2f(1.0f, 0.0f); glVertex3f(ratio - 0.1, 0.7f, 0);
            glTexCoord2f(1.0f, 1.0f); glVertex3f(ratio - 0.1, 0.9f, 0);
        } glEnd();
        
        window -> swapBuffers();
        playground.update();
        MSR::PollEvents();
    }
    
    window -> destory();
    MSR::Terminate();
    exit(EXIT_SUCCESS);
    
}

