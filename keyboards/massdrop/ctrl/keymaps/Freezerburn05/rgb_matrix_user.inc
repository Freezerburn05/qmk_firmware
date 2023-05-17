RGB_MATRIX_EFFECT(ACID)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

#if defined(RGB_MATRIX_FRAMEBUFFER_EFFECTS)

#define UNDERGLOW_LEDS 32
#define UNDERGLOW_OFFSET 87

static bool ACID(effect_params_t* params) {

    static uint8_t underglow_colors[UNDERGLOW_LEDS];

    if (params->init) {
        rgb_matrix_set_color_all(0, 0, 0);
        memset(g_rgb_frame_buffer, 0, sizeof(g_rgb_frame_buffer));
        memset(underglow_colors, 0, sizeof(underglow_colors));
    }

    bool flag = true;
    uint8_t speed = blend8(0, 10, rgb_matrix_config.speed);
    if (speed == 0) return false;

    uint8_t leds_processed = 0;

    for (uint8_t col = 0; col < MATRIX_COLS; col++) {
        for (uint8_t row = 0; row < MATRIX_ROWS; row++) {

            if (g_led_config.matrix_co[row][col] != 255) leds_processed++;

            //if (!HAS_ANY_FLAGS(g_led_config.flags[g_led_config.matrix_co[row][col]], params->flags)) continue;

            uint8_t val = g_rgb_frame_buffer[row][col];

            if (val == 0) val = 135;
            if (val > 250) val = 5;
            if (val < 5) val = 250;

            if (flag)
                val = qadd8(val, rand() % speed);
            else
                val = qsub8(val, rand() % speed);

            flag = !flag;

            g_rgb_frame_buffer[row][col] = val;

            HSV hsv = {val, rgb_matrix_config.hsv.s, rgb_matrix_config.hsv.v};
            RGB rgb = rgb_matrix_hsv_to_rgb(hsv);

            rgb_matrix_set_color(g_led_config.matrix_co[row][col], rgb.r, rgb.g, rgb.b);

        }
    }

    for (uint8_t i = 0; i < UNDERGLOW_LEDS; i++) {
        leds_processed++;

        //if (!HAS_ANY_FLAGS(g_led_config.flags[i + UNDERGLOW_OFFSET], params->flags)) continue;

        uint8_t val = underglow_colors[i];

        if (val == 0) val = 135;
        if (val > 250) val = 5;
        if (val < 5) val = 250;

        if (flag)
            val = qadd8(val, rand() % speed);
        else
            val = qsub8(val, rand() % speed);

        flag = !flag;

        underglow_colors[i] = val;

        HSV hsv = {val, rgb_matrix_config.hsv.s, rgb_matrix_config.hsv.v};
        RGB rgb = rgb_matrix_hsv_to_rgb(hsv);

        rgb_matrix_set_color(i + UNDERGLOW_OFFSET, rgb.r, rgb.g, rgb.b);
    }

    if (params->init) {
        printf("LEDs processed: %d\n", leds_processed);
        printf("Driver LEDs: %d\n", DRIVER_LED_TOTAL);
        for (uint8_t col = 0; col < MATRIX_COLS; col++) {
            for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
                printf("%d, ", g_led_config.matrix_co[row][col]);
            }
        }
    }

    return false;
}
#endif // RGB_MATRIX_FRAMEBUFFER_EFFECTS

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
