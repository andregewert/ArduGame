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


#ifndef _ARDUGAME_SH1106_H
#define _ARDUGAME_SH1106_H

#ifndef _ARDUGAME_CFG
#define ARDUGAME_PIN_AUDIO 11
#define ARDUGAME_PIN_LED_R 7
#define ARDUGAME_PIN_LED_G 6
#define ARDUGAME_PIN_LED_B 5
#define ARDUGAME_CTRL_STICK_PIN_SWITCH A0
#define ARDUGAME_CTRL_STICK_PIN_Y A1
#define ARDUGAME_CTRL_STICK_PIN_X A2
#define ARDUGAME_CTRL_DIGITAL_UP A5
#define ARDUGANE_CTRL_DIGITAL_DOWN A4
#define ARDUGAME_CTRL_DIGITAL_LEFT A3
#define ARDUGAME_CTRL_DIGITAL_RIGHT A2
#define ARDUGAME_CTRL_DIGITAL_MIDDLE A1
#define ARDUGAME_CTRL_DIGITAL_SET A0
#define ARDUGAME_CTRL_DIGITAL_RESET 2
#define ARDUGAME_CTRL_ANALOG_INPUT A5
#endif

#include <ArduGame.h>
#include <lcdgfx.h>

class ArduGame_SH1106 : public ArduGame {
public:
    ArduGame_SH1106();

    void begin() override;
    
    // Graphics
    void clearScreen() override;
    void setFont(const unsigned char* f) override;
    void drawText(const char str[]) override;
    void drawCenteredText(uint8_t y, const char str[]) override;
    void setCursor(uint8_t x, uint8_t y) override;
    void fillScreen(uint8_t color) override;
    void shiftScreen(uint8_t distance, uint8_t direction) override;
    void drawPixel(int8_t x, int8_t y, uint8_t color = COLOR_WHITE) override;
    void drawRect(int8_t x, int8_t y, uint8_t width, uint8_t height, uint8_t color = COLOR_WHITE) override;
    void fillRect(int8_t x, int8_t y, uint8_t width, uint8_t height, uint8_t color = COLOR_WHITE) override;
    void drawBitmap(int8_t x, int8_t y, const uint8_t* bitmap, uint8_t width = 0, uint8_t height = 0) override;
    void drawCircle(int8_t x0, int8_t y0, uint8_t r, uint8_t color = COLOR_WHITE) override;
    void fillCircle(int8_t x0, int8_t y0, uint8_t r, uint8_t color = COLOR_WHITE) override;
    void drawLine(int8_t x0, int8_t y0, int8_t x1, int8_t y1, uint8_t color = COLOR_WHITE) override;

public:
    DisplaySH1106_128x64_I2C *display;
};

#endif
