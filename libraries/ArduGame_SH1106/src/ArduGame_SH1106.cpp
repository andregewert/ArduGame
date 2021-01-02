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

#include "ArduGame_SH1106.h"

ArduGame_SH1106::ArduGame_SH1106() {
    display = new DisplaySH1106_128x64_I2C(-1);
    width = 128;
    height = 128;
    fontWidth = 6;
    fontHeight = 8;
}

void ArduGame_SH1106::begin() {
    display->begin();
    display->setFixedFont(ssd1306xled_font6x8);
}

void ArduGame_SH1106::clearScreen() {
    display->clear();
}

void ArduGame_SH1106::setFont(const unsigned char* f) {
    // different type ...
}

void ArduGame_SH1106::drawText(const char str[]) {
    // TODO not implemented yet
}

void ArduGame_SH1106::drawCenteredText(uint8_t y, const char str[]) {
    int x = (width / 2) - ((strlen(str) * (int)fontWidth) / 2);
    display->setTextCursor(x, y);
    // TODO not implemented yet
}

void ArduGame_SH1106::setCursor(uint8_t x, uint8_t y) {
    display->setTextCursor(x, y);
}

void ArduGame_SH1106::fillScreen(uint8_t color) {
    display->fill(color);
}

void ArduGame_SH1106::shiftScreen(uint8_t distance, uint8_t direction) {
    // TODO not implemented, yet
}

void ArduGame_SH1106::drawPixel(int8_t x, int8_t y, uint8_t color = COLOR_WHITE) {
    display->drawRect(x, y, x, y);
}

void ArduGame_SH1106::drawRect(int8_t x, int8_t y, uint8_t width, uint8_t height, uint8_t color = COLOR_WHITE) {
    display->drawRect(x, y, x + width - 1, y + height - 1);
}

void ArduGame_SH1106::fillRect(int8_t x, int8_t y, uint8_t width, uint8_t height, uint8_t color = COLOR_WHITE) {
    display->fillRect(x, y, x + width - 1, y + height - 1);
}

void ArduGame_SH1106::drawBitmap(int8_t x, int8_t y, const uint8_t* bitmap, uint8_t width = 0, uint8_t height = 0) {
    display->drawBitmap1(x, y, width, height, bitmap);
}

void ArduGame_SH1106::drawCircle(int8_t x0, int8_t y0, uint8_t r, uint8_t color = COLOR_WHITE) {
    display->drawCircle(x0, y0, r);
}

void ArduGame_SH1106::fillCircle(int8_t x0, int8_t y0, uint8_t r, uint8_t color = COLOR_WHITE) {
    //display.fillCircle(x0, y0, r);
}

void ArduGame_SH1106::drawLine(int8_t x0, int8_t y0, int8_t x1, int8_t y1, uint8_t color = COLOR_WHITE) {
    display->drawLine(x0, y0, x1, y1);
}
