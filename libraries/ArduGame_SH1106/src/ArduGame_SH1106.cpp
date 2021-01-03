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
    width = 128;
    height = 64;
    fontWidth = 6;
    fontHeight = 8;
}

void ArduGame_SH1106::begin() {
    oledInit(&display, OLED_128x64, -1, 0, 0, 1, -1, -1, -1, 800000L);
    oledFill(&display, 0, 1);
    oledSetBackBuffer(&display, ucBackBuffer);
}

void ArduGame_SH1106::clear() {
    oledFill(&display, 0, 1);
}

void ArduGame_SH1106::setTextSize(uint8_t size) {
    switch (size) {
        case 4:
            fontWidth = 16;
            fontHeight = 32;
            break;
        case 3:
            fontWidth = 16;
            fontHeight = 16;
            break;
        case 2:
            fontWidth = 8;
            fontHeight = 8;
            break;
        default:
            fontWidth = 6;
            fontHeight = 8;

    }
}

void ArduGame_SH1106::drawText(char str[]) {
    if (fontWidth == 6 && fontHeight == 8) {
        oledWriteString(&display, 0, display.iCursorX, display.iCursorY, str, FONT_SMALL, 0, 1);
    } else if (fontWidth == 8 && fontHeight == 8) {
        oledWriteString(&display, 0, display.iCursorX, display.iCursorY, str, FONT_NORMAL, 0, 1);
    } else if (fontWidth == 16 && fontHeight == 16) {
        oledWriteString(&display, 0, display.iCursorX, display.iCursorY, str, FONT_STRETCHED, 0, 1);
    } else if (fontWidth == 16 && fontHeight == 32) {
        oledWriteString(&display, 0, display.iCursorX, display.iCursorY, str, FONT_LARGE, 0, 1);
    }
}

void ArduGame_SH1106::drawCenteredText(uint8_t y, char str[]) {
    int x = (width / 2) - ((strlen(str) * (int)fontWidth) / 2);
    oledSetCursor(&display, x, y);
    drawText(str);
}

void ArduGame_SH1106::setCursor(uint8_t x, uint8_t y) {
    oledSetCursor(&display, x, y);
}

void ArduGame_SH1106::fillScreen(uint8_t color) {
    if (color == COLOR_WHITE) {
        oledFill(&display, 1, 1);
    } else {
        oledFill(&display, 0, 1);
    }
}

void ArduGame_SH1106::shiftScreen(uint8_t distance, uint8_t direction) {
    // TODO not implemented, yet
}

void ArduGame_SH1106::drawPixel(int8_t x, int8_t y, uint8_t color = COLOR_WHITE) {
    if (color == COLOR_WHITE) {
        oledSetPixel(&display, x, y, 1, 1);
    } else {
        oledSetPixel(&display, x, y, 0, 1);
    }
}

void ArduGame_SH1106::drawRect(int8_t x, int8_t y, uint8_t width, uint8_t height, uint8_t color = COLOR_WHITE) {
    oledRectangle(&display, x, y, x +width -1, y +height -1, color, 0);
}

void ArduGame_SH1106::fillRect(int8_t x, int8_t y, uint8_t width, uint8_t height, uint8_t color = COLOR_WHITE) {
    oledRectangle(&display, x, y, x + width - 1, y + height - 1, color, 1);
}

void ArduGame_SH1106::drawBitmap(int8_t x, int8_t y, uint8_t* bitmap, uint8_t width = 0, uint8_t height = 0) {
    oledDrawSprite(&display, bitmap, width, height, 0, x, y, 1);
}

void ArduGame_SH1106::drawCircle(int8_t x0, int8_t y0, uint8_t r, uint8_t color = COLOR_WHITE) {
    oledEllipse(&display, x0, y0, r, r, color, 0);
}

void ArduGame_SH1106::fillCircle(int8_t x0, int8_t y0, uint8_t r, uint8_t color = COLOR_WHITE) {
    oledEllipse(&display, x0, y0, r, r, color, 1);
}

void ArduGame_SH1106::drawLine(int8_t x0, int8_t y0, int8_t x1, int8_t y1, uint8_t color = COLOR_WHITE) {
    oledDrawLine(&display, x0, y0, x1, y1, 1);
}

void ArduGame_SH1106::updateDisplay() {
    oledDumpBuffer(&display, NULL);
};
