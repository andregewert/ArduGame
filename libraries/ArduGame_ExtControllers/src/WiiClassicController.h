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

#ifndef _ARDUGAME_WII_CLASSIC_CONTROLLER_H
#define _ARDUGAME_WII_CLASSIC_CONTROLLER_H

#include <Controller/BaseController.h>
#include <SoftwareWire.h>

/**
 * @brief Support for a Wii Classic Controller connected via I2C Interface
 * 
 */
class WiiClassicController : public BaseController {
public:
    WiiClassicController(uint8_t pinSda, uint8_t pinScl);
    WiiClassicController(uint8_t pinSda, uint8_t pinScl, int address);
    void begin() override;
    void connectController();
    word readControllerState() override;

private:
    bool isButtonPressed(byte dataByte, byte dataBit);

private:
    SoftwareWire wire;
    uint8_t pinSda;
    uint8_t pinScl;
    int address = 0x52;
    uint8_t data[6] = { 0, 0, 0, 0, 0, 0 };
};

#endif
