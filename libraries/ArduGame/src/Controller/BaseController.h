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

#ifndef _ARDUGAME_BASE_CONTROLLER_H
#define _ARDUGAME_BASE_CONTROLLER_H

#include <Arduino.h>

#define BUTTON_NONE 0;
#define BUTTON_UP 2
#define BUTTON_DOWN 4
#define BUTTON_LEFT 8
#define BUTTON_RIGHT 16
#define BUTTON_START 32
#define BUTTON_A 64
#define BUTTON_B 128
#define BUTTON_C 256
#define BUTTON_X 512
#define BUTTON_Y 1024
#define BUTTON_Z 2048
#define BUTTON_HOME 4096

/**
 * @brief Base class for different controller implementations
 * 
 */
class BaseController {
public:
    BaseController();
    void updateControllerState();
    bool pressed(word buttons);
    bool notPressed(word button);
    bool anyPressed(word buttons);
    bool justPressed(word button);
    bool justReleased(word button);

    // Virtual methods which must be implemented by concrete classes
    virtual void begin();
    virtual word readControllerState();
    virtual float getRelativeX();
    virtual float getRelativeY();

// Public properties
public:
    word lastState = 0;
    word currentState = 0;
};

#endif
