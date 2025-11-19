#pragma once

#include <box2d/box2d.h>

class B2_Base {
    public:
    static inline b2Version getVersion() { return b2GetVersion(); }
    static inline int getByteCount() { return b2GetByteCount(); }
    
    static inline uint64_t storeWorldId(b2WorldId worldId) {
        return b2StoreWorldId(worldId);
    }

    static inline void loadWorldId(uint64_t worldId, b2WorldId& result) {
        result = b2LoadWorldId(worldId);
    }

    static inline uint64_t storeBodyId(b2BodyId bodyId) {
        return b2StoreBodyId(bodyId);
    }

    static inline void loadBodyId(uint64_t bodyId, b2BodyId& result) {
        result = b2LoadBodyId(bodyId);
    }

    static inline uint64_t storeShapeId(b2ShapeId shapeId) {
        return b2StoreShapeId(shapeId);
    }

    static inline void loadShapeId(uint64_t shapeId, b2ShapeId& result) {
        result = b2LoadShapeId(shapeId);
    }

    static inline uint64_t storeChainId(b2ChainId chainId) {
        return b2StoreChainId(chainId);
    }

    static inline void loadChainId(uint64_t chainId, b2ChainId& result) {
        result = b2LoadChainId(chainId);
    }

    static inline uint64_t storeJointId(b2JointId jointId) {
        return b2StoreJointId(jointId);
    }

    static inline void loadJointId(uint64_t jointId, b2JointId& result) {
        result = b2LoadJointId(jointId);
    }

};
