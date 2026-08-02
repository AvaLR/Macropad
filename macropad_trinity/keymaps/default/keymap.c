//Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

// Identify standard custom layers
enum custom_layers {
    _DAILY,
    _AVTF,
    _CODING
};

// Map hotkey macros to single internal words
enum custom_keycodes {
    MIN_ALL = SAFE_RANGE,
    OPEN_MUSIC,
    OPEN_NOTES,
    RIPPLE_DEL,
    AUTO_FIX_COLOR,
    SLICE_TOOL,
    SELECT_TOOL,
    NEW_TEXT,
    SPEED_DUR,
    LINK_UNLINK,
    RUN_TERM,
    AUTO_FORMAT,
    CLOSE_TERM,
    GIT_ADD,
    GIT_COMMIT,
    GIT_PUSH,
    OPEN_VSCODE,
    OPEN_COURSERA
};

// Simple 3x3 Grid Layout Arrays
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_DAILY] = LAYOUT_ortho_3x3(
        MIN_ALL,    OPEN_MUSIC, KC_MUTE,
        KC_MPRV,    KC_MPLY,    KC_MNXT,
        KC_PSCR,    OPEN_NOTES, TG(_AVTF)
    ),
    [_AVTF] = LAYOUT_ortho_3x3(
        RIPPLE_DEL, AUTO_FIX_COLOR, KC_MPLY,
        SLICE_TOOL, SELECT_TOOL,    NEW_TEXT,
        SPEED_DUR,  LINK_UNLINK,    TG(_CODING)
    ),
    [_CODING] = LAYOUT_ortho_3x3(
        RUN_TERM,    AUTO_FORMAT,  CLOSE_TERM,
        GIT_ADD,     GIT_COMMIT,   GIT_PUSH,
        OPEN_VSCODE, OPEN_COURSERA, TG(_AVTF)
    )
};

// Basic Vol Down / Vol Up mapping for turning the wheel left or right
#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_DAILY]  = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_AVTF]   = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_CODING] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) }
};
#endif

// Hotkey Macro Strings execution block
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case MIN_ALL:        SEND_STRING(SS_DOWN(X_LGUI) "d" SS_UP(X_LGUI)); return false;
            case OPEN_MUSIC:     SEND_STRING(SS_DOWN(X_LGUI) "1" SS_UP(X_LGUI)); return false;
            case OPEN_NOTES:     SEND_STRING(SS_TAP(X_LGUI) SS_DELAY(50) "notepad" SS_TAP(X_ENTER)); return false;
            case RIPPLE_DEL:     SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_BSPC) SS_UP(X_LALT)); return false;
            case AUTO_FIX_COLOR: SEND_STRING(SS_DOWN(X_LCTRL) SS_TAP(X_F) SS_UP(X_LCTRL)); return false;
            case SLICE_TOOL:     SEND_STRING("c"); return false;
            case SELECT_TOOL:    SEND_STRING("v"); return false;
            case NEW_TEXT:       SEND_STRING("t"); return false;
            case SPEED_DUR:      SEND_STRING(SS_DOWN(X_LCTRL) "r" SS_UP(X_LCTRL)); return false;
            case LINK_UNLINK:    SEND_STRING(SS_DOWN(X_LCTRL) "l" SS_UP(X_LCTRL)); return false;
            case RUN_TERM:       SEND_STRING(SS_DOWN(X_LCTRL) "`" SS_UP(X_LCTRL)); return false;
            case AUTO_FORMAT:    SEND_STRING(SS_DOWN(X_LALT) SS_DOWN(X_LSHIFT) "f" SS_UP(X_LSHIFT) SS_UP(X_LALT)); return false;
            case CLOSE_TERM:     SEND_STRING("exit" SS_TAP(X_ENTER)); return false;
            case GIT_ADD:        SEND_STRING("git add ." SS_TAP(X_ENTER)); return false;
            case GIT_COMMIT:     SEND_STRING("git commit -m \"\""); return false;
            case GIT_PUSH:       SEND_STRING("git push" SS_TAP(X_ENTER)); return false;
            case OPEN_VSCODE:    SEND_STRING(SS_TAP(X_LGUI) SS_DELAY(50) "code" SS_TAP(X_ENTER)); return false;
            case OPEN_COURSERA:  SEND_STRING(SS_TAP(X_LGUI) SS_DELAY(50) "browser" SS_DELAY(100) "coursera.org" SS_TAP(X_ENTER)); return false;
        }
    }
    return true;
}

// Simple OLED Screen Display Status Tracker
#ifdef OLED_ENABLE
bool oled_task_user(void) {
    switch (get_highest_layer(layer_state)) {
        case _DAILY:  oled_write_P(PSTR("LAYER: DAILY\n"), false); break;
        case _AVTF:   oled_write_P(PSTR("LAYER: AVTF EDIT\n"), false); break;
        case _CODING: oled_write_P(PSTR("LAYER: CODING\n"), false); break;
    }
    return false;
}
#endif

// Simple LED Layer Tracker Color Interceptor
#ifdef RGBLIGHT_ENABLE
layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _DAILY:  rgblight_setrgb(0, 225, 255); break; // Cyan
        case _AVTF:   rgblight_setrgb(255, 180, 200); break; // Pastel Pink
        case _CODING: rgblight_setrgb(211, 211, 255);  break; // Lavender
    } 
    return state;
}
void keyboard_post_init_user(void) {
    rgblight_enable();
    rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
    rgblight_setrgb(0, 180, 255);
}
#endif
        