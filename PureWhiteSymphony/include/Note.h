//
//  Note.h
//  PureWhiteSymphony
//
//  Created by Darren Liu on 13-12-1.
//  Copyright (c) 2013年 mashiroLab. All rights reserved.
//

#ifndef PureWhiteSymphony_Note_h
#define PureWhiteSymphony_Note_h

#include "Base.h"

_MSR_BEGIN_

class Note {

public:
    
    enum Status {
        Normal,
        CleanHitted,
        NormalHitted,
        BadHitted,
        Missed
    };

    Note()
    : position(1.f), line(0) {}
    
    Note(int line)
    : position(1.f), line(line) {}
    
    int line;
    float position;
    Status status;
    
};

_MSR_END_

#endif
