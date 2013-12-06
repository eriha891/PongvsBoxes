#include "block.h"

// Default constructor
block::block()
{
    x = y = z = 0.0f;
    lives = widthB = heightB = 0;
}

// Construcor to set position, size of block and lives
block::block(float a, float b, float c, int l, int wB, int hB)
{
    x = a;
    y = b;
    z = c;

    widthB = wB;
    heightB = hB;

    lives = l;
}

int hits()
{
    return 0;
}
