/* Copyright 2018 'mechmerlin'
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

#include "keymap_german_ch.h"

// Defines the keycodes used by our macros in process_record_user
enum layers {
    _BASE,
    _FUNC,
    _SHIFT,
	_ALTGR
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap (Base Layer) Default Layer
   * ,----------------------------------------------------------------.
   * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  '|  ^|Backsp |Del |
   * |----------------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Z|  U|  I|  O|  P|  ü|  ¨| Ret-|PgUp|
   * |------------------------------------------------------      ----|
   * |Caps   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ö|  ä| $|turn|PgDn|
   * |----------------------------------------------------------------|
   * |Shift| < | Z|  X|  C|  V|  B|  N|  M|  ,|  .|  -|Shift | Up|End |
   * |----------------------------------------------------------------|
   * |Ctrl|Win |Alt |        Space          |Alt| FN|Ctrl|Lef|Dow|Rig |
   * `----------------------------------------------------------------'
   */
[_BASE] = LAYOUT_65_iso(
  KC_ESC,  CH_1,    CH_2,   CH_3,   CH_4,   CH_5,   CH_6,   CH_7,   CH_8,    CH_9,    CH_0,    CH_QUOT, CH_CIRC,  KC_BSPC, KC_DEL, \
  KC_TAB,  CH_Q,    CH_W,   CH_E,   CH_R,   CH_T,   CH_Z,   CH_U,   CH_I,    CH_O,    CH_P,    CH_UDIA, CH_DIAE, KC_PGUP, \
  KC_CAPS, CH_A,    CH_S,   CH_D,   CH_F,   CH_G,   CH_H,   CH_J,   CH_K,    CH_L,    CH_ODIA, CH_ADIA, CH_DLR,  KC_ENT, KC_PGDN,  \
  KC_LSFT, CH_LABK, CH_Y,   CH_X,   CH_C,   CH_V,   CH_B,   CH_N,   CH_M,   CH_COMM, CH_DOT,  CH_MINS, KC_RSFT, KC_UP,   KC_END,           \
  KC_LCTL, KC_LGUI, KC_LALT,                KC_SPC,                          KC_RALT, MO(1),   KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT),

/* Keymap Fn Layer
     * ,----------------------------------------------------------------.
     * | ` | F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|       |Ins |
     * |----------------------------------------------------------------|
     * |     |TOG|M+ |H+ |S+ |V+ |Sp+|   |Prt|SLk|Pau|   |   |     |Home|
     * |------------------------------------------------------.    |----|
     * |      |VLK|M- |H- |S- |V+ |Sp-|   |   |   |   |   |   |    |End |
     * |----------------------------------------------------------------|
     * |       |BL |BL-|BL+|BRTG|   |   |   |   |   |   |      |PUp|    |
     * |----------------------------------------------------------------|
     * |Sleep|Reset|    |               |     |   |  |Hom|PDn|End |
     * `------------------------------------------------'  `------------'
     */
[_FUNC] = LAYOUT_65_iso(
    KC_GRV,  KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12, _______,KC_INS, \
    _______,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI,_______,KC_PSCR,KC_SLCK,KC_PAUS,_______,_______,      KC_HOME, \
    _______,     VLK_TOG, RGB_RMOD, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD,_______,_______,_______,_______,_______,_______,  _______,   KC_END, \
    _______,_______,BL_TOGG, BL_DEC, BL_INC, BL_BRTG,_______,_______,_______,_______,_______,_______,_______,        KC_PGUP,_______, \
    KC_SLEP,RESET  ,_______,_______,   _______,_______, _______,KC_HOME,KC_PGDN,KC_END),
       


/* Shifted symbols
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
 * │ ° │ + │ " │ * │ ç │ % │ & │ / │ ( │ ) │ = │ ? │ ` │       │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
 * │     │   │   │   │   │   │   │   │   │   │   │ è │ ! │     │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐    │
 * │      │   │   │   │   │   │   │   │   │   │ é │ à │ £ │    │
 * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴────┤
 * │    │ > │   │   │   │   │   │   │   │ ; │ : │ _ │          │
 * ├────┼───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤
 * │    │    │    │                        │    │    │    │    │
 * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘
 */
[_SHIFT] = LAYOUT_65_iso(
  CH_DEG,  CH_PLUS,    CH_DQUO,   CH_ASTR,   CH_CCED,   CH_PERC,   CH_AMPR,   CH_SLSH,   CH_LPRN,    CH_RPRN,    CH_EQL,    CH_QUES, CH_GRV,_______,_______, \
  _______,  _______,    _______,   _______,   _______,   _______,   _______,   _______,   _______,    _______,    _______,    CH_EGRV, CH_EXLM, _______, \
  _______,_______, _______,    _______,   _______,   _______,   _______,   _______,   _______,   _______,    CH_EACU,    CH_AGRV, CH_PND,_______, _______,  \
  _______, CH_RABK,    _______,   _______,   _______,   _______,   _______,   _______,   _______, CH_SCLN,  CH_COLN, CH_UNDS, _______,   _______,_______,           \
  _______, _______, _______,                _______,                          _______, _______,   _______, _______, _______, _______),



/* AltGr symbols
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
 * │   │ ¦ │ @ │ # │   │   │ ¬ │ | │ ¢ │   │   │ ´ │ ~ │       │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
 * │     │   │   │ € │   │   │   │   │   │   │   │ [ │ ] │     │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐    │
 * │      │   │   │   │   │   │   │   │   │   │   │ { │ } │    │
 * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴────┤
 * │    │ \ │   │   │   │   │   │   │   │   │   │   │          │
 * ├────┼───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤
 * │    │    │    │                        │    │    │    │    │
 * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘
 */
[_ALTGR] = LAYOUT_65_iso(
  _______,  CH_BRKP,    CH_AT,   CH_HASH,   _______,   _______,   CH_NOT,   CH_PIPE,   CH_CENT,    _______,    _______,    CH_ACUT, CH_TILD,_______,_______, \
  _______,  _______,    _______,   CH_EURO,   _______,   _______,   _______,   _______,   _______,    _______,    _______,    CH_LBRC, CH_RBRC, _______, \
  _______,_______, _______,    _______,   _______,   _______,   _______,   _______,   _______,   _______,    _______,    CH_LCBR, CH_RCBR,_______, _______,  \
  _______, CH_BSLS,    _______,   _______,   _______,   _______,   _______,   _______,   _______, _______,  _______, _______, _______,   _______,_______,           \
  _______, _______, _______,                _______,                          _______, _______,   _______, _______, _______, _______)

};

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
