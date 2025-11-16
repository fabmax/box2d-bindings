#pragma once

#include <box2d/box2d.h>

class B2Base {
    public:
    static b2Version getVersion() { return b2GetVersion(); }
};
