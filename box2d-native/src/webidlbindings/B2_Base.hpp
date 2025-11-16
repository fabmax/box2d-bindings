#pragma once

#include <box2d/box2d.h>

class B2_Base {
    public:
    static inline b2Version getVersion() { return b2GetVersion(); }
};
