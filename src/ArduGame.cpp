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

#include "ArduGame.h"

#ifndef ARDUGAME_PIN_AUDIO
#define ARDUGAME_PIN_AUDIO 2
#endif

ArduGame::ArduGame() {
}

void ArduGame::begin() {
}


#pragma region Basic flow control

void ArduGame::setFps(uint8_t fps) {
    this->fps = fps;
}

bool ArduGame::nextFrame() {
    currentMillis = millis();
    diffMillis = currentMillis - lastFrameMillis;

    if (diffMillis >= 1000 / fps) {
        overtime = diffMillis - (1000 / fps);
        lastFrameMillis = currentMillis - overtime;
        frameCount++;

        if (currentMillis - frameCounterTime >= 1000) {
            currentFps = frameCount;
            frameCount = 0;
            frameCounterTime = currentMillis;
        }
        return true;
    }
    return false;
}

bool ArduGame::everyXFrames(uint8_t frames) {
    return frameCount % frames == 0;
}

void ArduGame::delay(unsigned int ms) {
    ::delay(ms);
}

#pragma endregion


#pragma region Audio

void ArduGame::tone(unsigned int frequency, unsigned long duration_ms) {
    ::tone(ARDUGAME_PIN_AUDIO, frequency, duration_ms);
}

void ArduGame::noTone() {
    ::noTone(ARDUGAME_PIN_AUDIO);
}

#pragma endregion


#pragma region Graphics

void ArduGame::update() {
    // empty default implementation
}

#pragma endregion


#pragma region Collision detection

bool ArduGame::collide(Point point, Rect rect) {
    return ((point.x >= rect.x) && (point.x < rect.x + rect.width) &&
        (point.y >= rect.y) && (point.y < rect.y + rect.height));
}

bool ArduGame::collide(Rect rect1, Rect rect2) {
    return !(rect2.x >= rect1.x + rect1.width ||
        rect2.x + rect2.width <= rect1.x ||
        rect2.y >= rect1.y + rect1.height ||
        rect2.y + rect2.height <= rect1.y);
}

#pragma endregion

