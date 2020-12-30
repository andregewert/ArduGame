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

#include "AnalogStickController.h"

AnalogStickController::AnalogStickController(uint8_t pinSwitch = ARDUGAME_CTRL_STICK_PIN_SWITCH, uint8_t pinX = ARDUGAME_CTRL_STICK_PIN_X, uint8_t pinY = ARDUGAME_CTRL_STICK_PIN_Y) {
    this->pinSwitch = pinSwitch;
    this->pinX = pinX;
    this->pinY = pinY;
}

void AnalogStickController::begin() {
    pinMode(this->pinSwitch, INPUT_PULLUP);
}

word AnalogStickController::readControllerState() {
    currentX = analogRead(pinX);
    currentY = analogRead(pinY);
    currentSwitch = digitalRead(pinSwitch);

    word state = BUTTON_NONE;
    state |= (currentSwitch == LOW)? BUTTON_A : 0;
    state |= (getRelativeX() >= threshold) ? BUTTON_RIGHT : 0;
    state |= (getRelativeX() <= -threshold) ? BUTTON_LEFT : 0;
    state |= (getRelativeY() >= threshold) ? BUTTON_DOWN : 0;
    state |= (getRelativeY() <= -threshold) ? BUTTON_UP : 0;

    return state;
}

int AnalogStickController::getPositionX() {
    return currentX;
}

int AnalogStickController::getPositionY() {
    return currentY;
}

float AnalogStickController::getRelativeX() {
    return (512 - currentX) /512.0;
}

float AnalogStickController::getRelativeY() {
    return -(512 - currentY) /512.0;
}