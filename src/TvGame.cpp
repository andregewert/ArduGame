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

#include "TvGame.h"

TvGame::TvGame(uint8_t width, uint8_t height) {
    this->width = width;
    this->height = height;
}

TvGame::TvGame() : TvGame(128, 64) {
}

void TvGame::begin() {
    randomSeed(analogRead(0));
    display.begin(NTSC, width, height);
    setFont(font6x8);
    frameCounterTime = millis();
    lastFrameMillis = frameCounterTime;
    currentFps = fps;
}


#pragma region Basic flow control

void TvGame::delay(unsigned int ms) {
    display.delay(ms);
}

#pragma endregion


#pragma region Audio

void TvGame::tone(unsigned int frequency, unsigned long duration_ms) {
    display.tone(frequency, duration_ms);
}

void TvGame::noTone() {
    display.noTone();
}

#pragma endregion


#pragma region Graphics

void TvGame::clearScreen() {
    display.clear_screen();
}

void TvGame::setFont(const unsigned char* f) {
    fontWidth = (int)f[0];
    fontHeight = (int)f[1];
    display.select_font(f);
}

void TvGame::drawText(const char str[]) {
    display.print(str);
}

void TvGame::drawCenteredText(uint8_t y, const char str[]) {
    int x = (width / 2) - ((strlen(str) * (int)fontWidth) / 2);
    display.set_cursor(x, y);
    display.print(str);
}

void TvGame::setCursor(uint8_t x, uint8_t y) {
    display.set_cursor(x, y);
}

void TvGame::fillScreen(uint8_t color) {
    display.fill(color);
}

void TvGame::shiftScreen(uint8_t distance, uint8_t direction) {
    display.shift(distance, direction);
}

void TvGame::drawPixel(int8_t x, int8_t y, uint8_t color = WHITE) {
    display.set_pixel(x, y, color);
}

void TvGame::drawRect(int8_t x, int8_t y, uint8_t width, uint8_t height, uint8_t color = WHITE) {
    display.draw_rect(x, y, width - 1, height - 1, color);
}

void TvGame::fillRect(int8_t x, int8_t y, uint8_t width, uint8_t height, uint8_t color = WHITE, uint8_t fillColor = WHITE) {
    display.draw_rect(x, y, width - 1, height - 1, color, fillColor);
}

void TvGame::drawCircle(int8_t x0, int8_t y0, uint8_t r, uint8_t color = WHITE) {
    display.draw_circle(x0, y0, r, color);
}

void TvGame::fillCircle(int8_t x0, int8_t y0, uint8_t r, uint8_t color = WHITE, uint8_t fillColor = WHITE) {
    display.draw_circle(x0, y0, r, color, fillColor);
}

void TvGame::drawLine(int8_t x1, int8_t y1, int8_t x2, int8_t y2, uint8_t color = WHITE) {
    display.draw_line(x1, y1, x2, y2, WHITE);
}

void TvGame::drawBitmap(int8_t x, int8_t y, const uint8_t* bitmap, uint8_t width = 0, uint8_t height = 0) {
    display.bitmap(x, y, bitmap, 0, width, height);
}

#pragma endregion
