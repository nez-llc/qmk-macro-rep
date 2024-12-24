/*
Copyright 2012,2013 gezhaoyou <gezhaoyou@126.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include QMK_KEYBOARD_H

//#include "./libs/mouse.h"
//#include "./libs/delay.h"

#define SCREEN_WIDTH  2560  // 가로 해상도
#define SCREEN_HEIGHT 1440  // 세로 해상도

#define DELAY_MIN 500
#define DELAY_MAX 800

void move_to_absolute(uint16_t x, uint16_t y) {
    digitizer_in_range_on();
    digitizer_set_position(x * 1.0 / SCREEN_WIDTH, y * 1.0 / SCREEN_HEIGHT);
    digitizer_in_range_off();
}

void random_delay(void) {
    uint16_t delay = (rand() % (DELAY_MAX - DELAY_MIN)) + DELAY_MIN;
    wait_ms(delay);
}

void random_pause(void) {
    if (rand() % 10 == 0) {
        wait_ms(2000 + (rand() % 1000));
    }
}

enum custom_keycodes {
    KC_CUSTOM_1 = SAFE_RANGE,  // 0x7E40
    KC_CUSTOM_10,
    KC_CUSTOM_20,
    KC_CUSTOM_30,
    KC_CUSTOM_50,
    KC_CUSTOM_100,
    MM_ZERO,
};

void run(void) {
    random_delay();
    tap_code(KC_P0);
    random_delay();
    tap_code(KC_P1);
    random_delay();
    tap_code(KC_P2);
    random_delay();
    tap_code(KC_P3);
    random_delay();
    tap_code(KC_P4);
    random_delay();
    tap_code(KC_P5);
    random_delay();
    tap_code(KC_P6);
    random_delay();
    tap_code(KC_P7);
    random_delay();
    tap_code(KC_P8);
    random_delay();
    tap_code(KC_P9);

    random_pause();
}

void off_leds(void) {
    rgb_matrix_enable_noeeprom();
}

void on_leds(void) {
    rgb_matrix_disable_noeeprom();
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
//        case KC_CUSTOM_1:
//            rgb_matrix_toggle();
        case KC_CUSTOM_10:
            off_leds();
            if (record->event.pressed) {
                for (int i = 0; i < 10; i++) { run();}
                return false;
            }
            on_leds();
        case KC_CUSTOM_20:
            off_leds();
            if (record->event.pressed) {
                for (int i = 0; i < 20; i++) { run();}
                return false;
            }
            on_leds();
        case KC_CUSTOM_30:
            off_leds();
            if (record->event.pressed) {
                for (int i = 0; i < 30; i++) { run();}
                return false;
            }
            on_leds();
        case KC_CUSTOM_50:
            off_leds();
            if (record->event.pressed) {
                for (int i = 0; i < 50; i++) { run();}
                return false;
            }
            on_leds();
        case KC_CUSTOM_100:
            off_leds();
            if (record->event.pressed) {
                for (int i = 0; i < 100; i++) { run();}
                return false;
            }
            on_leds();
    }
    return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_numpad_5x4(
        QK_BOOTLOADER,          KC_PSLS,       KC_PAST,             LT(1, KC_CUSTOM_100),
        KC_P7,                  KC_P8,         KC_P9,
        KC_P4,                  KC_P5,         KC_P6,               KC_CUSTOM_50,
        KC_P1,                  KC_P2,         KC_P3,
                                KC_CUSTOM_10,  KC_CUSTOM_20,        KC_CUSTOM_30),
  [1] = LAYOUT_numpad_5x4(
        KC_TRNS,                KC_CALCULATOR,          KC_BSPC,    KC_TRNS,
        RM_NEXT,                RM_VALU,                RM_HUEU,
        RM_SPDD,                RM_TOGG,                RM_SPDU,    QK_BOOTLOADER,
        RM_PREV,                RM_VALD,                RM_HUED,
                                KC_TRNS,                KC_TRNS,    QK_CLEAR_EEPROM),
};
