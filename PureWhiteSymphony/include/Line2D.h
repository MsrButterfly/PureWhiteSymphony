//
//  LinewD.h
//  PureWhiteSymphony
//
//  Created by Darren Liu on 13-12-1.
//  Copyright (c) 2013年 mashiroLab. All rights reserved.
//

#ifndef PureWhiteSymphony_Line2D_h
#define PureWhiteSymphony_Line2D_h

#include "Base.h"

_MSR_BEGIN_

class Line2D : public Shape {
    
public:
    
    Vertex2D<float> start;
    Vertex2D<float> end;
    float           width;
    
    Line2D()
    : start(Vertex2D<float>(0.f, 0.f)), end(Vertex2D<float>(0.f, 0.f)), width(1.f) {}
    
    Line2D(const Vertex2D<float> &start, const Vertex2D<float> &end)
    : start(start), end(end), width(1.f) {}
    
    void draw() {
        glLoadIdentity();
        glLineWidth(width);
        glBegin(GL_LINES); {
            glVertex3f(start.x, start.y, 0.f);
            glVertex3f(end.x, end.y, 0.f);
        } glEnd();
    }
    
};

_MSR_END_

#endif
