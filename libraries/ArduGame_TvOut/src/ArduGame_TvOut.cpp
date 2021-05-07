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

#include "ArduGame_TvOut.h"

ArduGame_TvOut::ArduGame_TvOut(uint8_t width, uint8_t height) {
    this->width = width;
    this->height = height;
}

ArduGame_TvOut::ArduGame_TvOut() : ArduGame_TvOut(128, 64) {
}

void ArduGame_TvOut::begin() {
    randomSeed(analogRead(0));
    display.begin(NTSC, width, height);
    setTextSize(1);
}


#pragma region Basic flow control

void ArduGame_TvOut::delay(unsigned int ms) {
    display.delay(ms);
}

unsigned long ArduGame_TvOut::getSystemTime() {
    return display.millis();
}

#pragma endregion


#pragma region Audio

void ArduGame_TvOut::tone(unsigned int frequency, unsigned long duration_ms) {
    display.tone(frequency, duration_ms);
}

void ArduGame_TvOut::noTone() {
    display.noTone();
}

#pragma endregion


#pragma region Graphics

void ArduGame_TvOut::clear() {
    display.clear_screen();
}

void ArduGame_TvOut::setTextSize(uint8_t size = 1) {
    switch (size) {
        case 3:
            display.select_font(font8x8);
            fontWidth = font8x8[0];
            fontHeight = font8x8[1];
            break;
        case 2:
            display.select_font(font6x8);
            fontWidth = font6x8[0];
            fontHeight = font6x8[1];
            break;
        default:
            display.select_font(font4x6);
            fontWidth = font4x6[0];
            fontHeight = font4x6[1];
            break;
    }
}

void ArduGame_TvOut::drawText(char str[]) {
    display.print(str);
}

void ArduGame_TvOut::drawCenteredText(uint8_t y, char str[]) {
    int x = (width / 2) - ((strlen(str) * (int)fontWidth) / 2);
    display.set_cursor(x, y);
    display.print(str);
}

void ArduGame_TvOut::setCursor(uint8_t x, uint8_t y) {
    display.set_cursor(x, y);
}

void ArduGame_TvOut::fillScreen(uint8_t color) {
    display.fill(color);
}

void ArduGame_TvOut::shiftScreen(uint8_t distance, uint8_t direction) {
    display.shift(distance, direction);
}

void ArduGame_TvOut::drawPixel(int8_t x, int8_t y, uint8_t color = COLOR_WHITE) {
    display.set_pixel(x, y, color);
}

void ArduGame_TvOut::drawRect(int8_t x, int8_t y, uint8_t width, uint8_t height, uint8_t color = COLOR_WHITE) {
    display.draw_rect(x, y, width - 1, height - 1, color);
}

void ArduGame_TvOut::fillRect(int8_t x, int8_t y, uint8_t width, uint8_t height, uint8_t color = COLOR_WHITE) {
    display.draw_rect(x, y, width - 1, height - 1, color);
}

void ArduGame_TvOut::drawCircle(int8_t x0, int8_t y0, uint8_t r, uint8_t color = COLOR_WHITE) {
    display.draw_circle(x0, y0, r, color);
}

void ArduGame_TvOut::fillCircle(int8_t x0, int8_t y0, uint8_t r, uint8_t color = COLOR_WHITE) {
    display.draw_circle(x0, y0, r, color);
}

void ArduGame_TvOut::drawLine(int8_t x0, int8_t y0, int8_t x1, int8_t y1, uint8_t color = COLOR_WHITE) {
    display.draw_line(x0, y0, x1, y1, color);
}

void ArduGame_TvOut::drawBitmap(int8_t x, int8_t y, uint8_t* bitmap, uint8_t width = 0, uint8_t height = 0) {
    display.bitmap(x, y, bitmap, 0, width, height);
}

#pragma endregion
