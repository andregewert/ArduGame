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

#include "BaseController.h"

BaseController::BaseController() {
}

void BaseController::begin() {
    currentState = BUTTON_NONE;
    lastState = BUTTON_NONE;
}

void BaseController::updateControllerState() {
    lastState = currentState;
    currentState = readControllerState();
}

bool BaseController::pressed(word buttons) {
    return (currentState & buttons) == buttons;
}

bool BaseController::notPressed(word buttons) {
    return (currentState & buttons) == 0;
}

bool BaseController::anyPressed(word buttons = 0) {
    return (currentState & buttons) != 0;
}

bool BaseController::justPressed(word button) {
    return (!(lastState & button) && (currentState & button));
}

bool BaseController::justReleased(word button) {
    return ((lastState & button) && !(currentState & button));
}

float BaseController::getRelativeX() {
    if (currentState & BUTTON_LEFT) return -1;
    if (currentState & BUTTON_RIGHT) return 1;
    return 0;
}

float BaseController::getRelativeY() {
    if (currentState & BUTTON_DOWN) return 1;
    if (currentState & BUTTON_UP) return -1;
    return 0;
}
