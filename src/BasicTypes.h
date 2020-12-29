/**
 * Copyright (c) 2020 André Gewert <agewert@ubergeek.de>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef _ARDUGAME_BASICTYPES_H
#define _ARDUGAME_BASICTYPES_H

#include <Arduino.h>

#define COLOR_WHITE 1
#define COLOR_BLACK 0
#define COLOR_INVERT 2

/**
 * @brief A rectangle object for collision functions.
 *
 * The X and Y coordinates specify the top left corner of a rectangle with the
 * given width and height.
 */
struct Rect {
    float x;      /**< The X coordinate of the top left corner */
    float y;      /**< The Y coordinate of the top left corner */
    uint8_t width;  /**< The width of the rectangle */
    uint8_t height; /**< The height of the rectangle */

    /**
     * @brief The default constructor
     */
    Rect() = default;

    /**
     * @brief The fully initializing constructor

     * @param x The X coordinate of the top left corner. Copied to variable `x`.
     * @param y The Y coordinate of the top left corner. Copied to variable `y`.
     * @param width The width of the rectangle. Copied to variable `width`.
     * @param height The height of the rectangle. Copied to variable `height`.
     */
    constexpr Rect(float x, float y, uint8_t width, uint8_t height)
        : x(x), y(y), width(width), height(height) {}
};

/**
 * @brief An object to define a single point for collision functions.
 *
 * The location of the point is given by X and Y coordinates.
 */
struct Point {
    float x; /**< The X coordinate of the point */
    float y; /**< The Y coordinate of the point */

    /**
     * @brief The default constructor
     */
    Point() = default;

    /**
     * @brief The fully initializing constructor
     *
     * @param x The X coordinate of the point. Copied to variable `x`.
     * @param y The Y coordinate of the point. Copied to variable `y`.
     */
    constexpr Point(float x, float y)
        : x(x), y(y) {}
};

struct Vector2d : public Point {
    Vector2d* normalize() {
        float mag = sqrt(x * x + y * y);
        if (mag != 0) {
            x = x/mag;
            y = y/mag;
        }
        return this;
    }
};

#endif
