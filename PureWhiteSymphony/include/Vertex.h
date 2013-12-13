//
//  Vertex.h
//  PureWhiteSymphony
//
//  Created by Darren Liu on 13-12-1.
//  Copyright (c) 2013年 mashiroLab. All rights reserved.
//

#ifndef PureWhiteSymphony_Vertex_h
#define PureWhiteSymphony_Vertex_h

#include "Base.h"

_MSR_BEGIN_

template <typename _Ty>
class Vertex2D {
    
public:
    
    _Ty x;
    _Ty y;
    
    Vertex2D() {}
    
    Vertex2D(const Vertex2D &vertex) : x(vertex.x), y(vertex.y) {}
    
    Vertex2D(const _Ty &x, const _Ty &y) : x(x), y(y) {}
    
    const bool operator==(const Vertex2D &vertex) const {
        return x == vertex.x && y == vertex.x;
    }
    
    const bool operator!=(const Vertex2D &vertex) const {
        return x != vertex.x || y != vertex.y;
    }
    
    const Vertex2D &operator=(const Vertex2D &vertex) {
        x = vertex.x;
        y = vertex.y;
        return *this;
    }
    
};

template <typename _Ty>
std::ostream &operator<<(std::ostream &stream, const Vertex2D<_Ty> &vertex) {
    stream << '(' << vertex.x << ", " << vertex.y << ')';
    return stream;
}

_MSR_END_

#endif
