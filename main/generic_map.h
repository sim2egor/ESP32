/*
Driver code for ESP32

Part of grblHAL

Copyright (c) 2020-2023 Terje Io

Grbl is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Grbl is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Grbl. If not, see http://www.gnu.org/licenses/.
*/

#if VFD_SPINDLE
#error "Board RDS does not have support for VFD spindle."
#endif

#define BOARD_NAME "RDS"
#if VFD_SPINDLE
#error "Generic map does not have support for VFD spindle."
#endif

#define USE_I2S_OUT
#define I2S_OUT_BCK GPIO_NUM_13
#define I2S_OUT_WS GPIO_NUM_12
#define I2S_OUT_DATA GPIO_NUM_14

// timer definitions
#define STEP_TIMER_GROUP TIMER_GROUP_0
#define STEP_TIMER_INDEX TIMER_0

// Define step pulse output pin27
#define X_STEP_PIN I2SO(1)
#define Y_STEP_PIN I2SO(3)
#define Z_STEP_PIN I2SO(5)

// Define step direction output pins. NOTE: All direction pins must be on the same port.
#define X_DIRECTION_PIN I2SO(2)
#define Y_DIRECTION_PIN I2SO(4)
#define Z_DIRECTION_PIN I2SO(6)

// Define stepper driver enable/disable output pin(s).
#define STEPPERS_ENABLE_PIN GPIO_NUM_27

// Define homing/hard limit switch input pins and limit interrupt vectors.
#define X_LIMIT_PIN GPIO_NUM_33
#define Y_LIMIT_PIN GPIO_NUM_32
#define Z_LIMIT_PIN GPIO_NUM_35

#if N_ABC_MOTORS >= 1
#define M3_AVAILABLE
#define M3_STEP_PIN I2SO(7)
#define M3_DIRECTION_PIN I2SO(0)
#define M3_LIMIT_PIN GPIO_NUM_34
#endif

#if DRIVER_SPINDLE_ENABLE
// Define spindle enable and spindle direction output pins.
#define SPINDLE_ENABLE_PIN GPIO_NUM_4
#define SPINDLEPWMPIN GPIO_NUM_2
#endif

// Define flood and mist coolant enable output pins.
#define COOLANT_FLOOD_PIN GPIO_NUM_15
#define COOLANT_MIST_PIN I2SO(11)

// Define user-control CONTROLs (cycle start, reset, feed hold) input pins.
//#define RESET_PIN GPIO_NUM_34
//#define FEED_HOLD_PIN GPIO_NUM_36
//#define CYCLE_START_PIN GPIO_NUM_39
#if SAFETY_DOOR_ENABLE
#define SAFETY_DOOR_PIN GPIO_NUM_25
#endif

// Define probe switch input pin.
#if PROBE_ENABLE
#define PROBE_PIN GPIO_NUM_26
#endif

#if KEYPAD_ENABLE
#error No free pins for keypad!
#endif

#if SDCARD_ENABLE
// Pin mapping when using SPI mode.
// With this mapping, SD card can be used both in SPI and 1-line SD mode.
// Note that a pull-up on CS line is required in SD mode.
#define PIN_NUM_MISO GPIO_NUM_19
#define PIN_NUM_MOSI GPIO_NUM_23
#define PIN_NUM_CLK GPIO_NUM_18
#define PIN_NUM_CS GPIO_NUM_5
#endif

