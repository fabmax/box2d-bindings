#pragma once

#include "box2d/base.h"

class B2Base {
    public:
    static b2Version getVersion() { return b2GetVersion(); }
};
