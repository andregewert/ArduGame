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

#include <Arduino.h>

#ifndef _ARDUGAME_H
#define _ARDUGAME_H

#include "BasicTypes.h"

class ArduGame {
public:
    ArduGame();
    virtual void begin();

    #pragma region Basic flow control

    /**
     * @brief Sets the refresh rate in frames per second
     *
     * @param fps New (preferred) number of frames per second
     */
    void setFps(uint8_t fps);

    /**
     * @brief Checks if the next frame should be calculated and drawn
     *
     * @return true If the next frame should be rendered
     * @return false If the game loop should wait for the next frame
     */
    bool nextFrame();

    /**
     * @brief Returns true every x frames
     *
     * @param frames The desired number of elapsed frames
     * @return true if the specified number of frames has elapsed
     * @return false if the specified number of frames has not elapsed
     */
    bool everyXFrames(uint8_t frames);

    /**
     * @brief Delays the execution of the game for the specified number of milli seconds
     *
     * @param ms Time to delay
     */
    virtual void delay(unsigned int ms);

    #pragma endregion


    #pragma region Audio

    /**
     * @brief Plays a tone
     *
     * @param frequency Frequency
     * @param duration_ms Length of the tone output
     */
    virtual void tone(unsigned int frequency, unsigned long duration_ms);

    /**
     * @brief Stops the playback of audio, if any
     */
    virtual void noTone();

    #pragma endregion


    #pragma region Graphics
    
    virtual void clearScreen() = 0;
    virtual void setFont(const unsigned char* f) = 0;
    virtual void drawText(const char str[]) = 0;
    virtual void drawCenteredText(uint8_t y, const char str[]) = 0;
    virtual void setCursor(uint8_t x, uint8_t y) = 0;
    virtual void fillScreen(uint8_t color) = 0;
    virtual void shiftScreen(uint8_t distance, uint8_t direction) = 0;
    virtual void drawPixel(int8_t x, int8_t y, uint8_t color = COLOR_WHITE) = 0;
    virtual void drawRect(int8_t x, int8_t y, uint8_t width, uint8_t height, uint8_t color = COLOR_WHITE) = 0;
    virtual void fillRect(int8_t x, int8_t y, uint8_t width, uint8_t height, uint8_t color = COLOR_WHITE) = 0;
    virtual void drawBitmap(int8_t x, int8_t y, const uint8_t* bitmap, uint8_t width = 0, uint8_t height = 0) = 0;
    virtual void drawCircle(int8_t x0, int8_t y0, uint8_t r, uint8_t color = COLOR_WHITE) = 0;
    virtual void fillCircle(int8_t x0, int8_t y0, uint8_t r, uint8_t color = COLOR_WHITE) = 0;
    virtual void drawLine(int8_t x0, int8_t y0, int8_t x1, int8_t y1, uint8_t color = COLOR_WHITE) = 0;
    virtual void updateDisplay();

    #pragma endregion


    #pragma region Collision detection

    /**
     * @brief Checks if the given point collides with the given rectangle
     * 
     * @param point The point to check
     * @param rect The rectangle to check
     * @return true if point and rectangle collide (point lies within the rectangle)
     * @return false if the point is outside the rectangle
     */
    static bool collide(Point point, Rect rect);

    /**
     * @brief Checks if two given rectangles collide with each other / overlap each other
     * 
     * @param rect1 First rectangle to check
     * @param rect2 Second rectangle to check
     * @return true if the given rectangles overlap / collide
     * @return false if the given rectangles do not overlap / collide
     */
    static bool collide(Rect rect1, Rect rect2);

    #pragma endregion

public:
    /**
     * @brief Width of the game screen
     */
    uint8_t width = 128;

    /**
     * @brief Height of the game screen
     */
    uint8_t height = 64;

    /**
     * @brief Current frame count (loops every desired fps)
     */
    uint8_t frameCount;

    /**
     * @brief Calculated actually fps
     */
    float currentFps;

protected:
    /**
     * @brief Width of the currently set font
     */
    uint8_t fontWidth = 6;

    /**
     * @brief Height of the currently set font
     */
    uint8_t fontHeight = 8;

    /**
     * @brief Desired frames per second
     */
    uint8_t fps = 20;

    unsigned long lastFrameMillis = 0;
    unsigned long currentMillis = 0;
    unsigned long diffMillis = 0;
    unsigned long overtime = 0;
    unsigned long frameCounterTime = 0;
};

#endif
