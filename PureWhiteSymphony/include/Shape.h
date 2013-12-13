//
//  Shape.h
//  PureWhiteSymphony
//
//  Created by Darren Liu on 13-12-1.
//  Copyright (c) 2013年 mashiroLab. All rights reserved.
//

#ifndef PureWhiteSymphony_Shape_h
#define PureWhiteSymphony_Shape_h

_MSR_BEGIN_

class Shape {
    
public:
    
    Shape() {}
    
    virtual void draw() = 0;
    
    virtual ~Shape() {}

};

_MSR_END_

#endif
