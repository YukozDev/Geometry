#include <gtest/gtest.h>
#include "operations/Vector.hpp"

// ------------------- Tests pour norm -------------------
TEST(VectorTest, Norm2D) {
    Vector2 v(3.0, 4.0);

    EXPECT_TRUE(norm(v) == 5.0);
}
