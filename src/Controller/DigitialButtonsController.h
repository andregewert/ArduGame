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

#ifndef _ARDUGAME_DIGITAL_BUTTONS_CONTROLLER_H
#define _ARDUGAME_DIGITAL_BUTTONS_CONTROLLER_H

#include "BaseController.h"

// Geht nicht: A7, A6, D13
// Geht: A5, A4, A3, A2, A1, A0, D2

#ifndef ARDUGAME_CTRL_DIGITAL_UP
#define ARDUGAME_CTRL_DIGITAL_UP A5
#endif
#ifndef ARDUGAME_CTRL_DIGITAL_DOWN
#define ARDUGAME_CTRL_DIGITAL_DOWN A4
#endif
#ifndef ARDUGAME_CTRL_DIGITAL_LEFT
#define ARDUGAME_CTRL_DIGITAL_LEFT A3
#endif
#ifndef ARDUGAME_CTRL_DIGITAL_RIGHT
#define ARDUGAME_CTRL_DIGITAL_RIGHT A2
#endif
#ifndef ARDUGAME_CTRL_DIGITAL_MIDDLE
#define ARDUGAME_CTRL_DIGITAL_MIDDLE A1
#endif
#ifndef ARDUGAME_CTRL_DIGITAL_SET
#define ARDUGAME_CTRL_DIGITAL_SET A0
#endif
#ifndef ARDUGAME_CTRL_DIGITAL_RESET
#define ARDUGAME_CTRL_DIGITAL_RESET 2
#endif

/**
 * @brief A simple interface for a controller consisting of a set of digital switches / buttons
 * 
 */
class DigitalButtonsController : public BaseController {
public:
    DigitalButtonsController(
        uint8_t pinUp = ARDUGAME_CTRL_DIGITAL_UP,
        uint8_t pinDown = ARDUGAME_CTRL_DIGITAL_DOWN,
        uint8_t pinLeft = ARDUGAME_CTRL_DIGITAL_LEFT,
        uint8_t pinRight = ARDUGAME_CTRL_DIGITAL_RIGHT,
        uint8_t pinMiddle = ARDUGAME_CTRL_DIGITAL_MIDDLE,
        uint8_t pinSet = ARDUGAME_CTRL_DIGITAL_SET,
        uint8_t pinReset = ARDUGAME_CTRL_DIGITAL_RESET
    );
    void begin() override;
    word readControllerState() override;

private:
    uint8_t pinUp;
    uint8_t pinDown;
    uint8_t pinLeft;
    uint8_t pinRight;
    uint8_t pinMiddle;
    uint8_t pinSet;
    uint8_t pinReset;
};

#endif
