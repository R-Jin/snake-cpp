#ifndef UTIL_H
#define UTIL_H

struct Vector2Int {
    int x;
    int y;

    bool operator==(const Vector2Int& other) const {
        return x == other.x && y == other.y;
    }

    bool operator!=(const Vector2Int& other) const {
        return x != other.x || y != other.y;
    }

    Vector2Int(int xValue = 0, int yValue = 0) : x(xValue), y(yValue) {}

    Vector2Int operator+(const Vector2Int& other) const {
        return Vector2Int(x + other.x, y + other.y);
    }

    Vector2Int operator-(const Vector2Int& other) const {
        return Vector2Int(x - other.x, y - other.y);
    }
};

#endif