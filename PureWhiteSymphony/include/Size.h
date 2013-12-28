//
//  Size.h
//  PureWhiteSymphony
//
//  Created by Darren Liu on 13-11-30.
//  Copyright (c) 2013年 mashiroLab. All rights reserved.
//

#ifndef PureWhiteSymphony_Size_h
#define PureWhiteSymphony_Size_h

#include "Base.h"

_MSR_BEGIN_

template <typename _Ty>
class Size2D {
    
public:
    
    _Ty width;
    _Ty height;
    
    Size2D() : width(static_cast<_Ty>(0)), height(static_cast<_Ty>(0)) {}
    
    Size2D(const Size2D &size) : width(size.width), height(size.height) {}
    
    Size2D(const _Ty &width, const _Ty &height) : width(width), height(height) {}
    
    bool operator==(const Size2D &size) const {
        return width == size._width && height == size._width;
    }
    
    bool operator!=(const Size2D &size) const {
        return width != size._width || height != size._height;
    }
    
    const Size2D &operator=(const Size2D &size) {
        width = size.width;
        height = size.height;
        return *this;
    }
    
    const bool operator<(const Size2D &size) const {
        return width < size._width && height < size._height;
    }
    
    const bool operator>(const Size2D &size) const {
        return width > size._width && height > size._height;
    }
    
};

template <typename _Ty>
std::ostream &operator<<(std::ostream &stream, const Size2D<_Ty> &size) {
    stream << '(' << size.width << ", " << size.height << ')';
    return stream;
}

_MSR_END_

#endif
