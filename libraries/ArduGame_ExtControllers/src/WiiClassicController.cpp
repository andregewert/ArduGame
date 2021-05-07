/**
 * Copyright (c) 2021 André Gewert <agewert@ubergeek.de>
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

#include "WiiClassicController.h"

WiiClassicController::WiiClassicController(uint8_t pinSda, uint8_t pinScl, int address)
    : BaseController() {
    this->pinSda = pinSda;
    this->pinScl = pinScl;
    this->address = address;
    wire = SoftwareWire(this->pinSda, this->pinScl);
}

WiiClassicController::WiiClassicController(uint8_t pinSda, uint8_t pinScl)
    : WiiClassicController(pinSda, pinScl, 0x52) {
}

void WiiClassicController::begin() {
    BaseController::begin();
    wire.begin();
    connectController();
}

void WiiClassicController::connectController() {
    wire.beginTransmission(address);
    wire.write((uint8_t)0xF0);
    wire.write((uint8_t)0x55);
    wire.endTransmission();

    wire.beginTransmission(address);
    wire.write((uint8_t)0xFB);
    wire.write((uint8_t)0x00);
    wire.endTransmission();
}

word WiiClassicController::readControllerState() {
    uint8_t count = 0;
    word state = BUTTON_NONE;

    wire.requestFrom(address, 6, true);
    while (wire.available()) {
        data[count] = wire.read();
        count++;
    }
    wire.beginTransmission(address);
    wire.write(byte(0x00));
    wire.endTransmission();

    if (count == 6) {
        state |= (isButtonPressed(5, 4)) ? BUTTON_A : 0;
        state |= (isButtonPressed(5, 6)) ? BUTTON_B : 0;
        state |= (isButtonPressed(5, 5)) ? BUTTON_Y : 0;
        state |= (isButtonPressed(5, 3)) ? BUTTON_X : 0;

        state |= (isButtonPressed(5, 0))? BUTTON_UP : 0;
        state |= (isButtonPressed(4, 6)) ? BUTTON_DOWN : 0;
        state |= (isButtonPressed(5, 1)) ? BUTTON_LEFT : 0;
        state |= (isButtonPressed(4, 7)) ? BUTTON_RIGHT : 0;
    }
    return state;
}

bool WiiClassicController::isButtonPressed(byte dataByte, byte dataBit) {
    return !((data[dataByte] >> dataBit) & 1);
}
