RGB_MATRIX_EFFECT(ACID)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

#if defined(RGB_MATRIX_FRAMEBUFFER_EFFECTS)
static bool ACID(effect_params_t* params) {

  //const uint8_t update_ticks = 14;
  static uint8_t update      = 0;

  if (params->init) {
    rgb_matrix_set_color_all(0, 0, 0);
    memset(g_rgb_frame_buffer, 0, sizeof(g_rgb_frame_buffer));
  }

  if (++update < rgb_matrix_config.speed) {
    return false;
  }

  update = 0;

  for (uint8_t col = 0; col < MATRIX_COLS; col++) {
    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {

      // set the pixel colour
      uint8_t led[LED_HITS_TO_REMEMBER];
      uint8_t led_count = rgb_matrix_map_row_column_to_led(row, col, led);

      if (led_count > 0) {
        if (!HAS_ANY_FLAGS(g_led_config.flags[g_led_config.matrix_co[row][col]], params->flags)) continue;

        uint8_t val = g_rgb_frame_buffer[row][col];

        if (val == 0) val = 135;
        if (val > 250) val = 5;
        if (val < 5) val = 250;
        if (rand() < RAND_MAX / 12) {
          val = qadd8(val, rand() % 3);
        } else {
          val = qsub8(val, rand() % 3);
        }

        g_rgb_frame_buffer[row][col] = val;

        HSV hsv = {val, rgb_matrix_config.hsv.s, rgb_matrix_config.hsv.v};
        RGB rgb = rgb_matrix_hsv_to_rgb(hsv);

        rgb_matrix_set_color(g_led_config.matrix_co[row][col], rgb.r, rgb.g, rgb.b);
      }

    }
  }


  return false;
}
#endif // RGB_MATRIX_FRAMEBUFFER_EFFECTS

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
