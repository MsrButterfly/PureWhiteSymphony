//
//  Base.h
//  PureWhiteSymphony
//
//  Created by Darren Liu on 13-11-30.
//  Copyright (c) 2013年 mashiroLab. All rights reserved.
//

#ifndef PureWhiteSymphony_Base_h
#define PureWhiteSymphony_Base_h

#define _MSR_BEGIN_ namespace MSR {
#define _MSR_END_ }

#include <GLFW/glfw3.h>

#define OGLFT_NO_SOLID
#define OGLFT_NO_QT
#include <oglft/OGLFT.h>

_MSR_BEGIN_

bool Init() {
    return glfwInit()? true : false;
}

void Terminate() {
    glfwTerminate();
}

void PollEvents() {
    glfwPollEvents();
}

_MSR_END_

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

#include "Texture.h"
#include "Vertex.h"
#include "Size.h"
#include "Color.h"
#include "Monitor.h"
#include "Window.h"
#include "Shape.h"
#include "Rectangle.h"
#include "Note.h"
#include "Font.h"
#include "Label.h"
#include "Line2D.h"
#include "Playground.h"

#endif
