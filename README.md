# ArduGame

Simple framework for creating games on the arduino platform

## Supported setups

Currently there are two supported hardware setups:

1. Arduino with tv signal via RCA connectors as display
2. Arduino with OLED SSD1306 / SSD1309 (similar to Arduboy)
3. Arduino with OLED SH1106

Both setups can be run with one of three controller types:

1. Digital buttons; needs seven pins // TODO link to example board
2. Analog stick with one switch, needs three pins // TODO add link
3. Digital buttons on a single analog pin // TODO add link

## Supported Arduino controllers

The initial idea was to create simple games for the Arduino Nano (ATMega 328P), which *is* possible.
But the Nano has *very* little memory (both RAM and program memory), and a good part of RAM is needed for running the display, so I ran out of memory early.
So I decided to try out other setups; the Arduino Pro Micro / Leonardo with a 32U4 controller has a little bit more memory. The same controller is used in the ArduBoy, so if you want to develop minimalistic games *and* have a decent piece of hardware, it is probably better to get your own Arduboy.
Another option I tried is the ATMega 2560; there is an Mega 2560 Pro Mini, which can be soldered on your own board. It is quite big and not cheap -- I think most people will prefer to develop for more powerful microcontrollers (e. g. STM32 or ESP32) which are cheaper.

## Usage

Just install the libraries you need (or all provided) in your `libraries` folder and include the header file for the setup you want to use.
Initialize game and conroller implementations in you `setup` function and implement your game in the `loop` function.
