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

#include "ArduGame_U8G2.h"

ArduGame_U8G2::ArduGame_U8G2() {
}

void ArduGame_U8G2::begin() {
}

void ArduGame_U8G2::begin(U8G2* u8g2) {
    display = u8g2;
    display->begin();
    width = display->getWidth();
    height = display->getHeight();
    setTextSize(1);
}

void ArduGame_U8G2::clear() {
    display->clearBuffer();
}

void ArduGame_U8G2::setTextSize(uint8_t size) {
    #ifdef _ARDUGAME_EXTFONTS
    switch (size) {
        case 3:
            display->setFont(u8g2_font_profont22_mr);
            fontWidth = 12;
            fontHeight = 22;
            break;
        case 2:
            display->setFont(u8g2_font_profont15_mr);
            fontWidth = 7;
            fontHeight = 15;
            break;
        default:
            display->setFont(u8g2_font_profont12_mr);
            fontWidth = 6;
            fontHeight = 12;
    }
    #else
    display->setFont(u8g2_font_profont12_mr);
    fontWidth = 6;
    fontHeight = 12;
    #endif
}

void ArduGame_U8G2::drawText(char str[]) {
    display->print(str);
}

void ArduGame_U8G2::drawCenteredText(uint8_t y, char str[]) {
    int x = (width / 2) - ((strlen(str) * (int)fontWidth) / 2);
    display->setCursor(x, y);
    display->print(str);
}

void ArduGame_U8G2::setCursor(uint8_t x, uint8_t y) {
    display->setCursor(x, y);
}

void ArduGame_U8G2::fillScreen(uint8_t color) {
    // ...
}

void ArduGame_U8G2::shiftScreen(uint8_t distance, uint8_t direction) {
    // TODO not implemented, yet
}

void ArduGame_U8G2::drawPixel(int8_t x, int8_t y, uint8_t color = COLOR_WHITE) {
    //display->setDrawColor(color);
    display->drawPixel(x, y);
}

void ArduGame_U8G2::drawRect(int8_t x, int8_t y, uint8_t width, uint8_t height, uint8_t color = COLOR_WHITE) {
    //display->setDrawColor(color);
    display->drawFrame(x, y, width, height);
}

void ArduGame_U8G2::fillRect(int8_t x, int8_t y, uint8_t width, uint8_t height, uint8_t color = COLOR_WHITE) {
    //display->setDrawColor(color);
    display->drawBox(x, y, width, height);
}

void ArduGame_U8G2::drawBitmap(int8_t x, int8_t y, uint8_t* bitmap, uint8_t width = 0, uint8_t height = 0) {
    display->drawXBMP(x, y, width, height, bitmap);
}

void ArduGame_U8G2::drawCircle(int8_t x0, int8_t y0, uint8_t r, uint8_t color = COLOR_WHITE) {
    //display->setDrawColor(color);
    display->drawCircle(x0, y0, r);
}

void ArduGame_U8G2::fillCircle(int8_t x0, int8_t y0, uint8_t r, uint8_t color = COLOR_WHITE) {
    display->drawDisc(x0, y0, r);
}

void ArduGame_U8G2::drawLine(int8_t x0, int8_t y0, int8_t x1, int8_t y1, uint8_t color = COLOR_WHITE) {
    //display->setDrawColor(color);
    display->drawLine(x0, y0, x1, y1);
}

void ArduGame_U8G2::updateDisplay() {
    display->sendBuffer();
};
