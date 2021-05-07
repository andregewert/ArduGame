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

#include "DigitalButtonsController.h"

DigitalButtonsController::DigitalButtonsController(
    uint8_t pinUp = ARDUGAME_CTRL_DIGITAL_UP,
    uint8_t pinDown = ARDUGAME_CTRL_DIGITAL_DOWN,
    uint8_t pinLeft = ARDUGAME_CTRL_DIGITAL_LEFT,
    uint8_t pinRight = ARDUGAME_CTRL_DIGITAL_RIGHT,
    uint8_t pinMiddle = ARDUGAME_CTRL_DIGITAL_MIDDLE,
    uint8_t pinSet = ARDUGAME_CTRL_DIGITAL_SET,
    uint8_t pinReset = ARDUGAME_CTRL_DIGITAL_RESET
) {
    this->pinUp = pinUp;
    this->pinDown = pinDown;
    this->pinLeft = pinLeft;
    this->pinRight = pinRight;
    this->pinMiddle = pinMiddle;
    this->pinSet = pinSet;
    this->pinReset = pinReset;
}

void DigitalButtonsController::begin() {
    pinMode(pinUp, INPUT_PULLUP);
    pinMode(pinDown, INPUT_PULLUP);
    pinMode(pinLeft, INPUT_PULLUP);
    pinMode(pinRight, INPUT_PULLUP);
    pinMode(pinMiddle, INPUT_PULLUP);
    pinMode(pinSet, INPUT_PULLUP);
    pinMode(pinReset, INPUT_PULLUP);
}

word DigitalButtonsController::readControllerState() {
    word state = BUTTON_NONE;
    state |= (digitalRead(pinUp) == LOW) ? BUTTON_UP : 0;
    state |= (digitalRead(pinDown) == LOW) ? BUTTON_DOWN : 0;
    state |= (digitalRead(pinLeft) == LOW) ? BUTTON_LEFT : 0;
    state |= (digitalRead(pinRight) == LOW) ? BUTTON_RIGHT : 0;
    state |= (digitalRead(pinMiddle) == LOW) ? BUTTON_A : 0;
    state |= (digitalRead(pinSet) == LOW) ? BUTTON_START : 0;
    state |= (digitalRead(pinReset) == LOW) ? BUTTON_HOME : 0;
    return state;
}
