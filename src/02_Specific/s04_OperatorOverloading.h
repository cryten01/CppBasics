
#ifndef CPPBASICS_S04_OPERATOROVERLOADING_H
#define CPPBASICS_S04_OPERATOROVERLOADING_H

#import <iostream>

struct Vector2 {
    float x, y;

    Vector2(float x, float y) : x(x), y(y) {}

    // Approach how C# would add Vectors because no operator overloading exists
    Vector2 Add(const Vector2& other) const
    {
        return Vector2(x + other.x, y + other.y);
    }

    Vector2 Multiply(const Vector2& other) const
    {
        return Vector2(x * other.x, y * other.y);
    }

    // Overloads the operator so we can use + instead of Add()
    Vector2 operator+(const Vector2 &other) const {
        return Add(other);
    }

    Vector2 operator*(const Vector2 &other) const {
        return Multiply(other);
    }

    bool operator==(const Vector2 &other) const {
        return x == other.x && y == other.y;
    }

    bool operator!=(const Vector2 &other) const {
        return!(*this == other);
    }
};

// Overloads the left shift ostream operator instead of writing ToString()
std::ostream &operator<<(std::ostream &stream, const Vector2 &other) {
    stream << other.x << ", " << other.y;
    return stream;
}

class Operator {
public:
    void PerformOperatorOverloading() {
        Vector2 speed(0.5f, 0.5f);
        Vector2 powerup(1.5f, 1.5f);

        Vector2 addResult = speed + powerup;
        Vector2 multResult = speed * powerup;
    }
};


#endif //CPPBASICS_S04_OPERATOROVERLOADING_H
