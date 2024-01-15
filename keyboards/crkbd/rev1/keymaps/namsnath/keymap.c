/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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
#include <stdio.h>

enum layer_names {
    _BASE = 0,
    _NAV,
    _MOUSE,
    _MEDIA,
    _NUM,
    _SYM,
    _FUN
};

// Left-hand home row mods
#define GUI_A LGUI_T(KC_A)
#define ALT_S LALT_T(KC_S)
#define CTL_D LCTL_T(KC_D)
#define SFT_F LSFT_T(KC_F)

// Right-hand home row mods
#define SFT_J RSFT_T(KC_J)
#define CTL_K RCTL_T(KC_K)
#define ALT_L LALT_T(KC_L)
#define GUI_SCLN RGUI_T(KC_SCLN)

// Layer switching
#define LS_MOUSE LT(_MOUSE, KC_TAB)
#define LS_NAV LT(_NAV, KC_BSPC)
#define LS_MEDIA LT(_MEDIA, KC_ESC)
#define LS_NUM LT(_NUM, KC_ENT)
#define LS_SYM LT(_SYM, KC_SPC)
#define LS_FUN LT(_FUN, KC_DEL)

#define REDO LCTL(KC_Y)
#define UNDO LCTL(KC_Z)
#define CUT LCTL(KC_X)
#define COPY LCTL(KC_C)
#define PASTE LCTL(KC_V)


// TODO: Consider switching Del and Escape
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x6_3(
         XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    XXXXXXX,
         XXXXXXX, GUI_A,   ALT_S,   CTL_D,   SFT_F,   KC_G,                               KC_H,    SFT_J,   CTL_K,   ALT_L,   GUI_SCLN,XXXXXXX,
         XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                               KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, XXXXXXX,
                                             LS_MEDIA,LS_NAV,  LS_MOUSE,         LS_NUM,  LS_SYM,  LS_FUN
    ),

    [_NAV] = LAYOUT_split_3x6_3(
         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            KC_INS,  KC_HOME, KC_UP,   KC_END,  KC_PGUP, XXXXXXX,
         XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                            KC_CAPS, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, XXXXXXX,
         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            REDO,    PASTE,   COPY,    CUT,     UNDO,    XXXXXXX,
                                             XXXXXXX, _______, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [_MOUSE] = LAYOUT_split_3x6_3(
         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            REDO,    PASTE,   COPY,    CUT,     UNDO,    XXXXXXX,
         XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                            XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, XXXXXXX,
         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, XXXXXXX,
                                             XXXXXXX, XXXXXXX, _______,          KC_BTN1, KC_BTN2, KC_BTN3
    ),

    [_MEDIA] = LAYOUT_split_3x6_3(
         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            KC_MPLY, KC_MPRV, KC_MNXT, XXXXXXX, XXXXXXX, XXXXXXX,
         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX, XXXXXXX, XXXXXXX,
         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, KC_BRID, KC_BRIU, XXXXXXX, XXXXXXX, XXXXXXX,
                                             _______, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [_NUM] = LAYOUT_split_3x6_3(
         XXXXXXX, XXXXXXX, KC_7,    KC_8,    KC_9,    XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
         XXXXXXX, XXXXXXX, KC_4,    KC_5,    KC_6,    XXXXXXX,                            XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,
         XXXXXXX, XXXXXXX, KC_1,    KC_2,    KC_3,    XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                             KC_DOT,  KC_0,    XXXXXXX,          _______, XXXXXXX, XXXXXXX
    ),

    [_SYM] = LAYOUT_split_3x6_3(
         XXXXXXX, KC_GRV,  KC_TILD, KC_LBRC, KC_RBRC, KC_PLUS,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
         XXXXXXX, KC_QUOT, KC_DQUO, KC_LPRN, KC_RPRN, KC_MINS,                            XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,
         XXXXXXX, KC_BSLS, KC_PIPE, KC_LCBR, KC_RCBR, KC_EQL,                             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                             KC_EXLM, KC_UNDS, KC_DLR,           XXXXXXX, _______, XXXXXXX
    ),

    [_FUN] = LAYOUT_split_3x6_3(
         XXXXXXX, KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_SYRQ,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
         XXXXXXX, KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_SCRL,                            XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,
         XXXXXXX, KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_PAUS,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                             KC_APP,  XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, _______
    )
};

//     /**
//      *  ┏━━━━━━━━━━┯━━━━━━━━━━┯━━━━━━━━━━┯━━━━━━━━━━┯━━━━━━━━━━┯━━━━━━━━━━┓                        ┏━━━━━━━━━━┯━━━━━━━━━━┯━━━━━━━━━━┯━━━━━━━━━━┯━━━━━━━━━━┯━━━━━━━━━━┓
//      *  ┃   Tab    │    Q     │    W     │    E     │    R     │    T     ┃                        ┃    Y     │    U     │    I     │    O     │    P     │  Delete  ┃
//      *  ┠──────────┼──────────┼──────────┼──────────┼──────────┼──────────┨                        ┠──────────┼──────────┼──────────┼──────────┼──────────┼──────────┨
//      *  ┃   Esc    │ GUI   A  │ ALT    S │ CTRL   D │ SHFT   F │    G     ┃                        ┃    H     │ SHFT   J │ CTRL   K │ ALT    L │ GUI ; :  │  Enter   ┃
//      *  ┠──────────┼──────────┼──────────┼──────────┼──────────┼──────────┨                        ┠──────────┼──────────┼──────────┼──────────┼──────────┼──────────┨
//      *  ┃          │    Z     │    X     │    C     │    V     │    B     ┃                        ┃    N     │    M     │   ,  <   │   .  >   │   /  ?   │          ┃
//      *  ┗━━━━━━━━━━┷━━━━━━━━━━┷━━━━━━━━━━┷━━━━━━━━━━╅──────────┼──────────╄━━━━━━━━━━┓  ┏━━━━━━━━━━╃──────────┼──────────╆━━━━━━━━━━━━━━━━━━━━━┷━━━━━━━━━━┷━━━━━━━━━━┛
//      *                                              ┃          │  LOWER   │   Bksp   ┃  ┃  Space   │  RAISE   │          ┃
//      *                                              ┗━━━━━━━━━━┷━━━━━━━━━━┷━━━━━━━━━━┛  ┗━━━━━━━━━━┷━━━━━━━━━━┷━━━━━━━━━━┛
//      */
//     /**
//      *  ┏━━━━━━━━━━┯━━━━━━━━━━┯━━━━━━━━━━┯━━━━━━━━━━┯━━━━━━━━━━┯━━━━━━━━━━┓                        ┏━━━━━━━━━━┯━━━━━━━━━━┯━━━━━━━━━━┯━━━━━━━━━━┯━━━━━━━━━━┯━━━━━━━━━━┓
//      *  ┃   Tab    │    Q     │    W     │    E     │    R     │    T     ┃                        ┃          │          │   Up     │          │          │  Delete  ┃
//      *  ┠──────────┼──────────┼──────────┼──────────┼──────────┼──────────┨                        ┠──────────┼──────────┼──────────┼──────────┼──────────┼──────────┨
//      *  ┃   Esc    │ GUI   A  │ ALT    S │ CTRL   D │ SHFT   D │    G     ┃                        ┃          │   Left   │   Down   │   Right  │          │  Enter   ┃
//      *  ┠──────────┼──────────┼──────────┼──────────┼──────────┼──────────┨                        ┠──────────┼──────────┼──────────┼──────────┼──────────┼──────────┨
//      *  ┃          │    Z     │    X     │    C     │    V     │    B     ┃                        ┃          │          │          │          │          │          ┃
//      *  ┗━━━━━━━━━━┷━━━━━━━━━━┷━━━━━━━━━━┷━━━━━━━━━━╅──────────┼──────────╄━━━━━━━━━━┓  ┏━━━━━━━━━━╃──────────┼──────────╆━━━━━━━━━━━━━━━━━━━━━┷━━━━━━━━━━┷━━━━━━━━━━┛
//      *                                              ┃          │  LOWER   │   Bksp   ┃  ┃  Space   │  RAISE   │          ┃
//      *                                              ┗━━━━━━━━━━┷━━━━━━━━━━┷━━━━━━━━━━┛  ┗━━━━━━━━━━┷━━━━━━━━━━┷━━━━━━━━━━┛
//      */

// OLED Stuff
#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write_ln_P(PSTR("Default"), false);
            break;
        case _NAV:
            oled_write_ln_P(PSTR("Navigation"), false);
            break;
        case _MOUSE:
            oled_write_ln_P(PSTR("Mouse"), false);
            break;
        case _MEDIA:
            oled_write_ln_P(PSTR("Media"), false);
            break;
        case _NUM:
            oled_write_ln_P(PSTR("Number"), false);
            break;
        case _SYM:
            oled_write_ln_P(PSTR("Symbol"), false);
            break;
        case _FUN:
            oled_write_ln_P(PSTR("Function"), false);
            break;
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
    } else {
        oled_render_logo();
    }
    return false;
}

#endif // OLED_ENABLE