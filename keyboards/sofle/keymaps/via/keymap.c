// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _QWERTY,
    _Nav,
    _Func,
    _Syntax
};

enum custom_keycodes {
    KC_PRVWD = QK_USER,
    KC_NXTWD,
    KC_LSTRT,
    KC_LEND,
    KC_WDESK_L,  // Win+Ctrl+Left (switch virtual desktop left)
    KC_WDESK_R,  // Win+Ctrl+Right (switch virtual desktop right)
    KC_WTAB,     // Win+Tab (task view)
    KC_WNEWDESK,  // Win+Ctrl+D (create new virtual desktop)
    KC_WDELDESK, // Win+Ctrl+F4 (delete current virtual desktop)
    KC_DELLINE,
};

enum {
    TD_ESC_CAPS,
};

// Tap Dance definitions
// tap_dance_action_t tap_dance_actions[] = {
//     // Tap once for Escape, twice for Caps Lock
//     [TD_ESC_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS),
// };
const uint16_t PROGMEM esc[] = {KC_GRV, KC_1, COMBO_END};
const uint16_t PROGMEM func[] = {KC_LGUI, KC_LALT, KC_LCTL, COMBO_END};
const uint16_t PROGMEM equal[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM left_brace[] = {KC_C, KC_V, COMBO_END};
// const uint16_t PROGMEM right_brace[] = {KC_V, KC_B, COMBO_END};
const uint16_t PROGMEM right_brace[] = {C(KC_C), C(KC_V), COMBO_END};
const uint16_t PROGMEM left_bracket[] =  {KC_D, KC_F, COMBO_END};
// const uint16_t PROGMEM right_bracket[] =  {KC_F, KC_G, COMBO_END};
const uint16_t PROGMEM right_bracket[] = {QK_MOUSE_CURSOR_DOWN,  QK_MOUSE_CURSOR_RIGHT, COMBO_END};
const uint16_t PROGMEM backslash[] = {KC_M, KC_COMM, COMBO_END};

combo_t key_combos[] = {
    COMBO(esc, KC_ESC),
    COMBO(func, TG(_Func)),
    COMBO(equal, KC_EQL),
    COMBO(left_brace, KC_LCBR),
    COMBO(right_brace, KC_RCBR),
    COMBO(left_bracket, KC_LBRC),
    COMBO(right_bracket, KC_RBRC),
    COMBO(backslash, KC_BSLS)
};

#define KC_QWERTY PDF(_QWERTY)
#define KC_COLEMAK PDF(_COLEMAK)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Caps |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |Space | /  _Nav /       \ _Nav \  |Enter | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_QWERTY] = LAYOUT(
  KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_MINS,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_BSPC,
  LT(_Syntax, KC_CAPS),  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  LT(_Syntax, KC_QUOT),
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_MUTE,     KC_PSCR,KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT,
            KC_LGUI,KC_LALT,KC_LCTL, KC_SPC, MO(_Nav),      MO(_Nav),  KC_ENT, KC_RCTL, KC_RALT, KC_RGUI
),
/* Nav
 * ,----------------------------------------.                     ,--------------------------------------------.
 * |      |      |      |      |      |      |                    |         |      |      |      |       |     |
 * |------+------+------+------+------+------|                    |---------+------+------+------+------+------|
 * | Esc  | Ins  | Pscr | Menu |      |      |                    |Page up  | PWrd |  Up  | NWrd | DLine| Bspc |
 * |------+------+------+------+------+------|                    |---------+------+------+------+------+------|
 * | Tab  | LAt  | LCtl |LShift|      | Caps |-------.     ,-------|Page down| Left | Down | Rigth|  Del | Bspc |
 * |------+------+------+------+------+------|  MUTE  |   |      |---------+------+------+------+------+------|
 * | Redo | Undo |  Cut | Copy | Paste|      |-------|    |-------|         | LStr |      | LEnd |      | Shift|
 * `-----------------------------------------/       /     \      \--------------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_Nav] = LAYOUT(
  _______, KC_WDELDESK , KC_WDESK_L, KC_WTAB,  KC_WDESK_R , KC_WNEWDESK,                                                     KC_WNEWDESK,KC_WDESK_L, KC_WTAB,  KC_WDESK_R,  KC_WDELDESK ,A(KC_F4),
  _______,  KC_INS,  QK_MOUSE_BUTTON_1,   QK_MOUSE_CURSOR_UP,  QK_MOUSE_BUTTON_2, MS_WHLU,                            KC_PGUP, KC_PRVWD,   KC_UP, KC_NXTWD,C(KC_BSPC), KC_BSPC,
  C(KC_Y), C(KC_A),  QK_MOUSE_CURSOR_LEFT,  QK_MOUSE_CURSOR_DOWN,  QK_MOUSE_CURSOR_RIGHT, MS_WHLD,                  KC_PGDN,  KC_LEFT, KC_DOWN, KC_RGHT,  KC_DEL, KC_DELLINE,
  _______, C(KC_Z), C(KC_X), C(KC_C), C(KC_V), C(S(KC_DOT)),  _______,                                          _______,  XXXXXXX, KC_LSTRT, XXXXXXX, KC_LEND,   XXXXXXX, _______,
                         _______, _______, _______, _______, _______,                                    _______, _______, _______, _______, _______
),
/* Func
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |    |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |     |   7  |   8  |   9  |   0  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|     |   &  |   *  |   (  |   )  |   |  |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * | Shift|  =   |  -   |  +   |   {  |   }  |-------|    |-------|     |   ]  |   ;  |   :  |   \  | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */


[_Func] = LAYOUT(KC_NO, KC_NUM, KC_P7, KC_P8, KC_P9, KC_PSLS, KC_NUM, KC_NO, KC_NO, KC_PSLS, KC_NO, KC_NO, KC_NO, KC_BSPC, KC_P4, KC_P5, KC_P6, KC_PAST, KC_P7, KC_P8, KC_P9, KC_PAST, KC_NO, KC_TRNS, KC_NO, KC_DEL, KC_P1, KC_P2, KC_P3, KC_PMNS, KC_P4, KC_P5, KC_P6, KC_PMNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_P0, KC_PDOT, KC_PENT, KC_PPLS, KC_NO, KC_NO, KC_P1, KC_P2, KC_P3, KC_PPLS, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_PENT, KC_NO, KC_NO, KC_P0, KC_PDOT, KC_PENT, KC_NO),
[_Syntax] = LAYOUT(KC_NO, KC_F11, KC_F12, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_MPRV, KC_MPLY, KC_MNXT, MS_WHLL, MS_WHLU, MS_WHLR, KC_NO, KC_NO, KC_TRNS, KC_LSFT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, UG_TOGG, UG_TOGG, KC_NO, MS_WHLD, KC_NO, KC_NO, KC_NO, KC_RSFT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_PRVWD:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_LEFT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                }
            }
            break;
        case KC_NXTWD:
             if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_RIGHT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                }
            }
            break;
        case KC_LSTRT:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                     //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                } else {
                    register_code(KC_HOME);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_code(KC_HOME);
                }
            }
            break;
        case KC_LEND:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                } else {
                    register_code(KC_END);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_code(KC_END);
                }
            }
            break;
        case KC_WDESK_L:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LGUI | MOD_LCTL));
                register_code(KC_LEFT);
            } else {
                unregister_mods(mod_config(MOD_LGUI | MOD_LCTL));
                unregister_code(KC_LEFT);
            }
            break;
        case KC_WDESK_R:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LGUI | MOD_LCTL));
                register_code(KC_RIGHT);
            } else {
                unregister_mods(mod_config(MOD_LGUI | MOD_LCTL));
                unregister_code(KC_RIGHT);
            }
            break;
        case KC_WTAB:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LGUI));
                register_code(KC_TAB);
            } else {
                unregister_mods(mod_config(MOD_LGUI));
                unregister_code(KC_TAB);
            }
            break;
        case KC_WNEWDESK:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LGUI | MOD_LCTL));
                register_code(KC_D);
            } else {
                unregister_mods(mod_config(MOD_LGUI | MOD_LCTL));
                unregister_code(KC_D);
            }
            break;
        case KC_WDELDESK:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LGUI | MOD_LCTL));
                register_code(KC_F4);
            } else {
                unregister_mods(mod_config(MOD_LGUI | MOD_LCTL));
                unregister_code(KC_F4);
            }
            break;
        case KC_DELLINE:
            if (record->event.pressed) {
                tap_code(KC_HOME);
                register_code(KC_LSFT);
                tap_code(KC_END);
                unregister_code(KC_LSFT);
                tap_code(KC_DEL);
            }
            return false;
            break;
    }
    return true;
}
