//
//  Color.h
//  PureWhiteSymphony
//
//  Created by Darren Liu on 13-12-1.
//  Copyright (c) 2013年 mashiroLab. All rights reserved.
//

#ifndef PureWhiteSymphony_Color_h
#define PureWhiteSymphony_Color_h

_MSR_BEGIN_

class Color {
    
public:
    
    float r;
    float g;
    float b;
    
    Color() : r(1.f), g(1.f), b(1.f) {}
    
    Color(const float &r, const float &g, const float &b) : r(r), g(g), b(b) {}
    
    Color(Color const &color) : r(color.r), g(color.g), b(color.b) {}
    
    static Color WhiteColor() {
        return Color(1.f, 1.f, 1.f);
    }
    
    static Color BlackColor() {
        return Color(0.f, 0.f, 0.f);
    }
    
    const bool operator==(const Color& color) const {
        return r == color.r && g == color.g && b == color.b;
    }
    
    const bool operator!=(const Color& color) const {
        return r != color.r || g != color.g || b != color.b;
    }
    
    const Color &operator=(const Color& color) {
        r = color.r;
        g = color.g;
        b = color.b;
        return *this;
    }
    
};

_MSR_END_

#endif
