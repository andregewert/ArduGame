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

#include "AnalogButtonsController.h"

AnalogButtonsController::AnalogButtonsController(uint8_t pinInput = ARDUGAME_CTRL_ANALOG_INPUT) {
    this->pinInput = pinInput;
}

void AnalogButtonsController::begin() {
    pinMode(pinInput, INPUT);
}

word AnalogButtonsController::readControllerState() {
    word state = BUTTON_NONE;
    int input = analogRead(pinInput);

    state |= (input < 16)? BUTTON_LEFT : 0;
    state |= (input >= 16 && input < 48)? BUTTON_UP : 0;
    state |= (input >= 80 && input < 112)? BUTTON_DOWN : 0;
    state |= (input >= 144 && input < 176)? BUTTON_RIGHT : 0;
    state |= (input >= 336 && input < 368)? BUTTON_A : 0;

    return state;
}