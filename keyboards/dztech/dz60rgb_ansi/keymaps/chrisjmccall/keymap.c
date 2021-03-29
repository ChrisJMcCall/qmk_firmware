#include QMK_KEYBOARD_H
// #include "print.h"

rgb_config_t rgb_matrix_config;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_60_ansi(
        KC_GESC,        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        KC_TAB,         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        CTL_T(KC_CAPS), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
        KC_LSFT,                 KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,
        KC_LCTL,        KC_LALT, KC_LGUI,                            KC_SPC,                             KC_RGUI, KC_RALT, MO(2),   MO(1) 
    ),
    [1] = LAYOUT_60_ansi(
        KC_GESC, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
        _______, _______, KC_UP,   _______, _______, _______, _______, _______, KC_MPRV,  KC_MPLY, KC_MNXT, KC_VOLD, KC_VOLU, RESET,
        _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, _______, _______, _______, KC_MUTE,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______
    ),
    [2] = LAYOUT_60_ansi(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
        _______, RGB_TOG, _______, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, RGB_MOD, _______, _______, _______, RESET,
        _______, _______, _______, _______, _______, _______, _______, _______, RGB_SPI, RGB_SPD, _______, _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______
    ),

    [3] = LAYOUT_60_ansi(
        _______, _______,   _______, _______,   _______, _______,   _______, _______,   _______, _______,   _______, _______,  _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______
    )
};

const uint8_t PROGMEM layercolors[][2] = {
  [0] = {200,155},
  [1] = {100,155}
};

// The led matrix changes direction with every line, like this:
// --------->
// <---------
// --------->
const uint8_t PROGMEM ledcolors[][DRIVER_LED_TOTAL][3] = {
  [1] = {
        {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED},
        {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE}, {HSV_RED}, {HSV_WHITE}, {HSV_WHITE},
        {HSV_WHITE}, {HSV_RED}, {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_WHITE},
        {HSV_WHITE},          {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE},  {HSV_WHITE},          {HSV_WHITE},
        {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE},                            {HSV_WHITE},                            {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE}
  }
};

void matrix_init_user(void) {
  rgb_matrix_config.raw = eeprom_read_dword(EECONFIG_RGB_MATRIX);
}

void set_leds_color( int layer) {
  // print("start\n");
  // xprintf("%u\n", KC_GESC);
  // int ledIndexOffset = 0;
  // for (int k = 0; k < MATRIX_ROWS; k++) {
    // for (int l = 0; l < MATRIX_COLS; l++) {
      // uint16_t keycode = pgm_read_byte(&keymaps[layer][k][l]);
      // if (keycode == (uint16_t)0) {
        // xprintf("%u\n", ledIndexOffset);
        // ledIndexOffset++;
      // }
      // if (keycode > (uint16_t)1) {
        // int ledIndex = ((k*14)+l) - ledIndexOffset;
        // rgb_matrix_set_color(ledIndex, 255,255,255);
// 
      // }
    // }
    // print(KC_GESC);
    // if(keymaps[layer][i][0] == _______) {
      // print("yes");
    // } else {
      // print("no");
    // }
  // }
  // print("end\n");

  // for (int i = 0; i < MATRIX_ROWS; i++) {
    // if(keymaps[layer][i][0] == ){
      // print(yes);
    // }
  // }

  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    uint8_t val = pgm_read_byte(&ledcolors[layer][i][2]);
    // if the brightness of the led is set to 0 in the map,
    // the value is not overriden with global controls, allowing the led
    // to appear turned off
    HSV hsv = { .h = pgm_read_byte(&ledcolors[layer][i][0]), .s = pgm_read_byte(&ledcolors[layer][i][1]), .v = val == 0 ? 0 : rgb_matrix_config.hsv.v};
    RGB rgb = hsv_to_rgb( hsv );
    rgb_matrix_set_color( i, rgb.r, rgb.g, rgb.b );
  }
}

void set_layer_color( uint8_t layer ) {
  HSV hsv = { .h = pgm_read_byte(&layercolors[layer][0]), .s = pgm_read_byte(&layercolors[layer][1]), .v = rgb_matrix_config.hsv.v};
  RGB rgb = hsv_to_rgb( hsv );
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    rgb_matrix_set_color( i, rgb.r, rgb.g, rgb.b );
  }
}

void rgb_matrix_indicators_user(void) {
  // uint32_t mode = rgblight_get_mode();
  // assign colors if the matrix is on and the current mode
  // is SOLID COLORS => No animations running
  if(rgb_matrix_config.enable == 1) {
    uint8_t layer = biton32(layer_state);
    switch (layer) {
      case 1:
        set_leds_color(1);
        break;
    }
  }
}

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  // debug_enable=true;
  // debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}