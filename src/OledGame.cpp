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

#include "OledGame.h"

OledGame::OledGame() {
    width = 128;
    height = 64;
}

void OledGame::begin() {
    display = Adafruit_SSD1306(
        128, 64, &SPI, ARDUGAME_PIN_SPI_DC, ARDUGAME_PIN_SPI_RST, ARDUGAME_PIN_SPI_CS
    );
    display.begin(SSD1306_SWITCHCAPVCC);
}

// Graphics
void OledGame::clearScreen() {
    display.clearDisplay();
}

void OledGame::setFont(const unsigned char* f) {

}

void OledGame::drawText(const char str[]) {
    
}

void OledGame::drawCenteredText(uint8_t y, const char str[]) {

}

void OledGame::setCursor(uint8_t x, uint8_t y) {

}

void OledGame::fillScreen(uint8_t color) {

}

void OledGame::shiftScreen(uint8_t distance, uint8_t direction) {

}

void OledGame::drawPixel(int8_t x, int8_t y, uint8_t color = COLOR_WHITE) {

}

void OledGame::drawRect(int8_t x, int8_t y, uint8_t width, uint8_t height, uint8_t color = COLOR_WHITE) {

}

void OledGame::fillRect(int8_t x, int8_t y, uint8_t width, uint8_t height, uint8_t color = COLOR_WHITE, uint8_t fillColor = COLOR_WHITE) {
    display.fillRect(x, y, width, height, color);
}

void OledGame::drawBitmap(int8_t x, int8_t y, const uint8_t* bitmap, uint8_t with = 0, uint8_t height = 0) {

}

void OledGame::drawCircle(int8_t x0, int8_t y0, uint8_t r, uint8_t color = COLOR_WHITE) {

}

void OledGame::fillCircle(int8_t x0, int8_t y0, uint8_t r, uint8_t color = COLOR_WHITE, uint8_t fillColor = COLOR_WHITE) {

}

void OledGame::drawLine(int8_t x1, int8_t y1, int8_t x2, int8_t y2, uint8_t color = COLOR_WHITE) {

}

void OledGame::update() {
    display.display();
}
