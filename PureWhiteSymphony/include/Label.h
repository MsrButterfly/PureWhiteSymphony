//
//  Label.h
//  PureWhiteSymphony
//
//  Created by Darren Liu on 13-12-1.
//  Copyright (c) 2013年 mashiroLab. All rights reserved.
//

#ifndef PureWhiteSymphony_Label_h
#define PureWhiteSymphony_Label_h

#include "Base.h"

_MSR_BEGIN_

class Label : public Shape {
    
public:
    
    std::string      text;
    Font             font;
    Vertex2D<float>  position;
    
    Label(const std::string &text, const Font &font)
    : text(text), font(font) {}
    Label(const std::string &text)
    : text(text) {}
    
    void draw() {
        glEnable(GL_LINE_SMOOTH);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glLoadIdentity();
        glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
        font.oglftFont() -> setHorizontalJustification(OGLFT::Face::LEFT);
        font.oglftFont() -> draw(position.x, position.y, text.c_str());
    }
    
    ~Label() {}
    
};

_MSR_END_

#endif
