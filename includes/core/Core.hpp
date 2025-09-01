#pragma once

#define TOLERENCE 0.0000001

enum class RELATIVE_POSITION {
    LEFT,
    RIGHT,
    BEHIND,
    BEYOND,
    BETWEEN,
    ORIGIN,
    DESTINATION
};

bool xor(bool x, bool y) {
    return x ^ y;
}