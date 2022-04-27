#pragma once
#include <vector>


enum Space {
    WALL = -1,
    OPEN = 0,
    END = 1,
};

enum DirectionPointer {
    LEFT = '<',
    RIGHT = '>',
    UP = '^',
    DOWN = 'v',
    TOP_LEFT = '\\',
    TOP_RIGHT = '/',
    BOTTOM_RIGHT = '\\',
    BOTTOM_LEFT = '/'
};