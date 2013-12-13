//
//  Playground.h
//  PureWhiteSymphony
//
//  Created by Darren Liu on 13-12-1.
//  Copyright (c) 2013年 mashiroLab. All rights reserved.
//

#ifndef PureWhiteSymphony_Playground_h
#define PureWhiteSymphony_Playground_h

#include "Base.h"

_MSR_BEGIN_

class Playground : public Shape {
    
public:
    
    int   lineAmount;
    float interval;
    
    Playground()
    : _window(nullptr), lineAmount(0), interval(0.f) {
        update();
    }
    
    Playground(const Window &window)
    : _window(&window), lineAmount(0), interval(0.f) {
        update();
    }
    
    Playground(const Window &window, const int &lineAmount)
    : _window(&window), lineAmount(lineAmount), interval(0.f) {
        update();
    }
    
    Playground(const Window &window, const int &lineAmount, const float &interval)
    : _window(&window), lineAmount(lineAmount), interval(interval) {
        update();
    }
    
    void addNote(int line) {
        _notes.push_back(new Note(line));
    }
    
    void update() {
        double updateTime = glfwGetTime();
        if (static_cast<int>(updateTime * 5) > __lastAddNoteTime) {
            __lastAddNoteTime = static_cast<int>(updateTime * 5);
            addNote((float)rand() / RAND_MAX * lineAmount);
        }
        for (auto &note : _notes) {
            note -> position -= updateTime - _lastUpdateTime;
        }
        _notes.remove_if([](const Note *note) {
            if (note -> position < -1.f - .01f) {
                delete note;
                return true;
            }
            return false;
        });
        _lastUpdateTime = updateTime;
    }
    
    void draw() {
        for (int i = 0; i < lineAmount; i++) {
            float pos = (lineAmount / -2.0 + i + 0.5) * interval;
            Line2D(Vertex2D<float>(pos, 1.f), Vertex2D<float>(pos, -1.f)).draw();
        }
        for (const auto &note : _notes) {
            float pos = (lineAmount / -2.0 + note -> line + 0.5) * interval;
            Rectangle(Vertex2D<float>(pos - .05f, note -> position - .01f), Size2D<float>(.1f, .02f), Color::BlackColor()).draw();
        }
    }
    
private:
    
    std::list<Note *>     _notes;
    const Window         *_window;
    double                _lastUpdateTime;
    double                __lastAddNoteTime;
    
};

_MSR_END_

#endif
