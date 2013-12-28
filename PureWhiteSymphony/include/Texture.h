//
//  Texture.h
//  PureWhiteSymphony
//
//  Created by Darren Liu on 13-12-28.
//  Copyright (c) 2013年 mashiroLab. All rights reserved.
//

#ifndef PureWhiteSymphony_Texture_h
#define PureWhiteSymphony_Texture_h

#include "Base.h"
#include <SOIL.h>

_MSR_BEGIN_

GLuint Texture(std::string path) {
    GLuint texture = SOIL_load_OGL_texture(path.c_str(),
                                           SOIL_LOAD_RGBA,
                                           SOIL_CREATE_NEW_ID,
                                           SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_MULTIPLY_ALPHA);
                                           // SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
    if (!texture) {
        return 0;
    }
    return texture;
}

_MSR_END_

#endif
