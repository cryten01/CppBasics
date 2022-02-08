
#ifndef CPPBASICS_G00_STRUCT_H
#define CPPBASICS_G00_STRUCT_H

/**
 * Structs are public by default.
 * Exist because of backwards compatibility with C.
 * Use for plain old data (POD).
 */
struct Coord2D {
    float x;
    float y;
};

#endif //CPPBASICS_G00_STRUCT_H
