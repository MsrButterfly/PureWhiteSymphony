//
//  Rectangle.h
//  PureWhiteSymphony
//
//  Created by Darren Liu on 13-12-1.
//  Copyright (c) 2013年 mashiroLab. All rights reserved.
//

#ifndef PureWhiteSymphony_Rectangle_h
#define PureWhiteSymphony_Rectangle_h

#include "Base.h"

_MSR_BEGIN_

class Rectangle : public Shape {
    
public:
    
    Rectangle(const Vertex2D<float> &position, const Size2D<float> &size, const Color &color)
    : _position(position), _size(size), _color(color) {}
    
    Rectangle(const Size2D<float> &size, const Vertex2D<float> &position, const Color &color)
    : _size(size), _position(position), _color(color) {}
    
    Rectangle(const Vertex2D<float> &position, const Size2D<float> &size)
    : _position(position), _size(size) {}
    
    Rectangle(const Vertex2D<float> &position, const Color &color)
    : _position(position), _color(color) {}
    
    Rectangle(const Size2D<float> &size, const Color &color)
    : _size(size), _color(color) {}
    
    Rectangle(const Color &color)
    : _color(color) {}
    
    Rectangle() {}
    
    void draw() {
        glLoadIdentity();
        glBegin(GL_QUADS); {
            glColor3f(_color.r, _color.g, _color.b); glVertex3f(_position.x, _position.y, 0.f);
            glColor3f(_color.r, _color.g, _color.b); glVertex3f(_position.x + _size.width, _position.y, 0.f);
            glColor3f(_color.r, _color.g, _color.b); glVertex3f(_position.x + _size.width, _position.y + _size.height, 0.f);
            glColor3f(_color.r, _color.g, _color.b); glVertex3f(_position.x, _position.y + _size.height, 0.f);
        } glEnd();
    }
    
    Vertex2D<float> _position;
    Size2D<float>   _size;
    Color           _color;
    
};

_MSR_END_

#endif
