#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"

#define BASE 0 // default layer
#define FUNK 1 // function and media layer
#define KODE 2 // coding layer

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   `    |   1  |   2  |   3  |   4  |   5  | ~L1  |           |      |   6  |   7  |   8  |   9  |   0  |   =    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  | Bksp |           |  \   |   Y  |   U  |   I  |   O  |   P  |   -    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LShift |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |~L2/; | RShift |
 * |--------+------+------+------+------+------| Meh  |           |  '   |------+------+------+------+------+--------|
 * | LCtrl  |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |  /   | RCtrl  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Hyper | Home | End  | LAlt | LGUI |                                      |GUI/Esc| Ralt |      |      |      |
 *   `----------------------------------'                                      `-----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        |Delete|      |       | Left | Right  |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | PgUp |       |  Up  |        |      |
 *                                 | Space| Esc  |------|       |------|  ~L1   |Enter |
 *                                 |      |      | PgDn |       | Down |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
        KC_GRV,  KC_1,    KC_2,   KC_3,   KC_4,   KC_5,   MO(FUNK),
        KC_TAB,  KC_Q,    KC_W,   KC_E,   KC_R,   KC_T,   KC_BSPC,
        KC_LSFT, KC_A,    KC_S,   KC_D,   KC_F,   KC_G,
        KC_LCTL, KC_Z,    KC_X,   KC_C,   KC_V,   KC_B,   KC_MEH,
        KC_HYPR, KC_HOME, KC_END, KC_LALT,KC_LGUI,
                                                  KC_DELT,KC_TRNS,
                                                          KC_PGUP,
                                          KC_SPC, KC_ESC, KC_PGDN,
        // right hand
             KC_TRNS,     KC_6,     KC_7,          KC_8,    KC_9,    KC_0,             KC_EQL,
             KC_BSLASH,   KC_Y,     KC_U,          KC_I,    KC_O,    KC_P,             KC_MINS,
                          KC_H,     KC_J,          KC_K,    KC_L,    LT(KODE,KC_SCLN), KC_RSFT,
             KC_QUOT,     KC_N,     KC_M,          KC_COMM, KC_DOT,  KC_SLSH,          KC_RCTL,
                                    GUI_T(KC_ESC), KC_RALT, KC_TRNS, KC_TRNS,          KC_TRNS,
             KC_LEFT,     KC_RGHT,
             KC_UP,
             KC_DOWN,     MO(FUNK), KC_ENT
    ),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        | F11  | F12  | F13  | F14  | F15  |      |           |      |  F16 | F17  | F18  | F19  | F20  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       | Prev |Pause | Next |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | Vol+ |       | Vol+ |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      | Vol- |       | Vol- |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[FUNK] = KEYMAP(
       // left hand
       KC_TRNS,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
       KC_TRNS,KC_F11, KC_F12, KC_F13, KC_F14, KC_F15, KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                               KC_TRNS,KC_TRNS,
                                                       KC_VOLU,
                                       KC_TRNS,KC_TRNS,KC_VOLD,
       // right hand
       KC_TRNS, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
       KC_TRNS, KC_F16,  KC_F17, KC_F18,  KC_F19,  KC_F20,  KC_TRNS,
                KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                         KC_MNXT,KC_MPLY, KC_MPRV, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_VOLU,
       KC_VOLD, KC_TRNS, KC_TRNS
),
/* Keymap 2: Code
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |   '  |  "   |      |------|           |------|      |   [  |  ]   |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |   {  |  }   |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// Coding symbols
[KODE] = KEYMAP(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_QUOT, S(KC_QUOT),KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                    KC_TRNS, KC_TRNS,
                                                             KC_TRNS,
                                           KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_LBRC, KC_RBRC, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_LCBR, KC_RCBR, KC_TRNS, KC_TRNS, KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(FUNK)                // FN1 - Momentary Layer 1
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          register_code(KC_RSFT);
        } else {
          unregister_code(KC_RSFT);
        }
        break;
      }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void * matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void * matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }

};
