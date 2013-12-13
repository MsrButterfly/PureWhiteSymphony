//
//  Font.h
//  PureWhiteSymphony
//
//  Created by Darren Liu on 13-12-1.
//  Copyright (c) 2013年 mashiroLab. All rights reserved.
//

#ifndef PureWhiteSymphony_Font_h
#define PureWhiteSymphony_Font_h

_MSR_BEGIN_

class Font {
    
public:
    
    enum Style {
        Outline     = 1,
        Filled      = 2,
        Monochrome  = 3,
        Grayscale   = 4,
        Translucent = 5
    };
    
public:
    
    std::string path;
    float       size;
    Style       style;
    
private:
    
    std::string _lastPath;
    float       _lastSize;
    Style       _lastStyle;
    
public:
    
    Font()
    : path("/System/Library/Fonts/Avenir Next.ttc"), size(24.f), style(Translucent), _oglftFont(NULL) {}
    
    Font(Style style, std::string path, float size)
    : path(path), size(size), style(style), _oglftFont(NULL) {}
    
    Font(std::string path, float size)
    : path(path), size(size), style(Translucent), _oglftFont(NULL) {}
    
    Font(std::string path)
    : path(path), size(24.f), _oglftFont(NULL) {}
    
    Font(const Font &font)
    : path(font.path), size(font.size), style(font.style), _oglftFont(NULL) {}
    
    OGLFT::Face *oglftFont() {
        if (path != _lastPath || size != _lastSize || style != _lastStyle) {
            _lastPath = path;
            _lastSize = size;
            _lastStyle = style;
            if (_oglftFont) {
                delete _oglftFont;
                _oglftFont = NULL;
            }
            switch (style) {
                default:
                case Translucent:
                    _oglftFont = new OGLFT::Translucent(path.c_str(), size);
                    break;
                case Outline:
                    _oglftFont = new OGLFT::Outline(path.c_str(), size);
                    break;
                case Filled:
                    _oglftFont = new OGLFT::Filled(path.c_str(), size);
                    break;
                case Monochrome:
                    _oglftFont = new OGLFT::Monochrome(path.c_str(), size);
                    break;
                case Grayscale:
                    _oglftFont = new OGLFT::Grayscale(path.c_str(), size);
                    break;
            }

        }
        return _oglftFont;
    }
    
    const Font &operator=(const Font &font) {
        path = font.path;
        size = font.size;
        style = font.style;
        return *this;
    }
    
    bool operator==(const Font &font) const {
        return path == font.path && size == font.size && style == font.style;
    }
    
    bool operator!=(const Font &font) const {
        return path != font.path || size != font.size || style != font.style;
    }
    
    ~Font() {
        if (_oglftFont) {
            delete _oglftFont;
        }
    }
    
private:
    
    OGLFT::Face *_oglftFont;
    
};

_MSR_END_


#endif
