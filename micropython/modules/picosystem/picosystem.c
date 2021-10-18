#include "picosystem.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
// PicosystemBuffer Class
////////////////////////////////////////////////////////////////////////////////////////////////////

/***** Methods *****/
MP_DEFINE_CONST_FUN_OBJ_1(PicosystemBuffer___del___obj, PicosystemBuffer___del__);

/***** Binding of Methods *****/
STATIC const mp_rom_map_elem_t PicosystemBuffer_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR___del__), MP_ROM_PTR(&PicosystemBuffer___del___obj) },
};

STATIC MP_DEFINE_CONST_DICT(PicosystemBuffer_locals_dict, PicosystemBuffer_locals_dict_table);

/***** Class Definition *****/
const mp_obj_type_t PicosystemBuffer_type = {
    { &mp_type_type },
    .name = MP_QSTR_Buffer,
    .print = PicosystemBuffer_print,
    .make_new = PicosystemBuffer_make_new,
    .buffer_p = { .get_buffer = PicosystemBuffer_get_buffer },
    .locals_dict = (mp_obj_dict_t*)&PicosystemBuffer_locals_dict,
};

////////////////////////////////////////////////////////////////////////////////////////////////////
// PicosystemVoice Class
////////////////////////////////////////////////////////////////////////////////////////////////////

/***** Methods *****/
MP_DEFINE_CONST_FUN_OBJ_1(PicosystemVoice___del___obj, PicosystemVoice___del__);
MP_DEFINE_CONST_FUN_OBJ_KW(PicosystemVoice_play_obj, 2, PicosystemVoice_play);
MP_DEFINE_CONST_FUN_OBJ_KW(PicosystemVoice_envelope_obj, 1, PicosystemVoice_envelope);
MP_DEFINE_CONST_FUN_OBJ_KW(PicosystemVoice_effects_obj, 1, PicosystemVoice_effects);
MP_DEFINE_CONST_FUN_OBJ_KW(PicosystemVoice_bend_obj, 1, PicosystemVoice_bend);

/***** Binding of Methods *****/
STATIC const mp_rom_map_elem_t PicosystemVoice_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR___del__), MP_ROM_PTR(&PicosystemVoice___del___obj) },
    { MP_ROM_QSTR(MP_QSTR_play), MP_ROM_PTR(&PicosystemVoice_play_obj) },
    { MP_ROM_QSTR(MP_QSTR_envelope), MP_ROM_PTR(&PicosystemVoice_envelope_obj) },
    { MP_ROM_QSTR(MP_QSTR_effects), MP_ROM_PTR(&PicosystemVoice_effects_obj) },
    { MP_ROM_QSTR(MP_QSTR_bend), MP_ROM_PTR(&PicosystemVoice_bend_obj) },
};

STATIC MP_DEFINE_CONST_DICT(PicosystemVoice_locals_dict, PicosystemVoice_locals_dict_table);

/***** Class Definition *****/
const mp_obj_type_t PicosystemVoice_type = {
    { &mp_type_type },
    .name = MP_QSTR_Voice,
    .print = PicosystemVoice_print,
    .make_new = PicosystemVoice_make_new,
    .locals_dict = (mp_obj_dict_t*)&PicosystemVoice_locals_dict,
    //.attr = PicosystemVoice_attr,
};

////////////////////////////////////////////////////////////////////////////////////////////////////
// picosystem Module
////////////////////////////////////////////////////////////////////////////////////////////////////

enum _sprites_ids {
    CHERRY, APPLE, BANANA, ORANGE, AUBERGINE, CARROT, POTATO, LEAF,
    PARSNIP, MEAT, BEAN, RADISH, STRAWBERRY, PUMPKIN, CUCUMBER, SALT,
    SWORD1, SWORD2, SWORD3, AXE, DAGGER, MACE, BOW, ARROW1,
    ARROW2, ARROW3, TRIDENT1, SPEAR, TRIDENT2, MACHINEGUN, PISTOL, SHOTGUN,
    GEM1, GEM2, GEM3, GEM4, GEM5, GEM6, AMULET, FOLDER,
    COIN, SKULL, TICK, CROSS, IDOL1, IDOL2, IDOL3, IDOL4,
    SWEETCORN, BROCCOLI, BISCUIT, BERRIES, SCEPTRE, FIRE, LASERGUN1, LASERGUN2,
    HELMET1, HELMET2, HELMET3, HELMET4,
    // TODO etc... can we name all 256 built in sprites?!
};

/***** Module Functions *****/
STATIC MP_DEFINE_CONST_FUN_OBJ_0(picosystem_init_obj, picosystem_init);
STATIC MP_DEFINE_CONST_FUN_OBJ_0(picosystem_reset_obj, picosystem_reset);
STATIC MP_DEFINE_CONST_FUN_OBJ_0(picosystem_tick_obj, picosystem_tick);

STATIC MP_DEFINE_CONST_FUN_OBJ_KW(picosystem_play_obj, 2, picosystem_audio_play);

STATIC MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(picosystem_pen_obj, 1, 4, picosystem_pen);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(picosystem_clip_obj, 4, 4, picosystem_clip);
STATIC MP_DEFINE_CONST_FUN_OBJ_1(picosystem_blend_obj, picosystem_blend);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(picosystem_target_obj, 0, 1, picosystem_target);
STATIC MP_DEFINE_CONST_FUN_OBJ_2(picosystem_camera_obj, picosystem_camera);
STATIC MP_DEFINE_CONST_FUN_OBJ_1(picosystem_spritesheet_obj, picosystem_spritesheet);

STATIC MP_DEFINE_CONST_FUN_OBJ_0(picosystem_clear_obj, picosystem_clear);
STATIC MP_DEFINE_CONST_FUN_OBJ_2(picosystem_pixel_obj, picosystem_pixel);
STATIC MP_DEFINE_CONST_FUN_OBJ_3(picosystem_hline_obj, picosystem_hline);
STATIC MP_DEFINE_CONST_FUN_OBJ_3(picosystem_vline_obj, picosystem_vline);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(picosystem_rect_obj, 4, 4, picosystem_rect);
STATIC MP_DEFINE_CONST_FUN_OBJ_3(picosystem_circle_obj, picosystem_circle);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR(picosystem_poly_obj, 1, picosystem_poly);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(picosystem_frect_obj, 4, 4, picosystem_frect);
STATIC MP_DEFINE_CONST_FUN_OBJ_3(picosystem_fcircle_obj, picosystem_fcircle);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR(picosystem_fpoly_obj, 1, picosystem_fpoly);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(picosystem_line_obj, 4, 4, picosystem_line);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(picosystem_blit_obj, 7, 7, picosystem_blit);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(picosystem_sprite_obj, 3, 7, picosystem_sprite);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(picosystem_text_obj, 1, 3, picosystem_text);
STATIC MP_DEFINE_CONST_FUN_OBJ_1(picosystem_text_width_obj, picosystem_text_width);

STATIC MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(picosystem_rgb_obj, 3, 4, picosystem_rgb);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(picosystem_hsv_obj, 3, 4, picosystem_hsv);

STATIC MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(picosystem_intersects_obj, 8, 8, picosystem_intersects);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(picosystem_intersection_obj, 8, 8, picosystem_intersection);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(picosystem_contains_obj, 6, 6, picosystem_contains);

STATIC MP_DEFINE_CONST_FUN_OBJ_1(picosystem_pressed_obj, picosystem_pressed);
STATIC MP_DEFINE_CONST_FUN_OBJ_1(picosystem_button_obj, picosystem_button);
STATIC MP_DEFINE_CONST_FUN_OBJ_0(picosystem_battery_obj, picosystem_battery);
STATIC MP_DEFINE_CONST_FUN_OBJ_3(picosystem_led_obj, picosystem_led);
STATIC MP_DEFINE_CONST_FUN_OBJ_1(picosystem_backlight_obj, picosystem_backlight);

/***** Globals Table *****/
STATIC const mp_map_elem_t picosystem_globals_table[] = {
    { MP_ROM_QSTR(MP_QSTR___name__), MP_ROM_QSTR(MP_QSTR_picosystem) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_Buffer), (mp_obj_t)&PicosystemBuffer_type },
    { MP_OBJ_NEW_QSTR(MP_QSTR_Voice), (mp_obj_t)&PicosystemVoice_type },

    { MP_ROM_QSTR(MP_QSTR_init), MP_ROM_PTR(&picosystem_init_obj) },
    { MP_ROM_QSTR(MP_QSTR_reset), MP_ROM_PTR(&picosystem_reset_obj) },
    { MP_ROM_QSTR(MP_QSTR_tick), MP_ROM_PTR(&picosystem_tick_obj) },

    { MP_ROM_QSTR(MP_QSTR_play), MP_ROM_PTR(&picosystem_play_obj) },

    { MP_ROM_QSTR(MP_QSTR_pen), MP_ROM_PTR(&picosystem_pen_obj) },
    { MP_ROM_QSTR(MP_QSTR_clip), MP_ROM_PTR(&picosystem_clip_obj) },
    { MP_ROM_QSTR(MP_QSTR_blend), MP_ROM_PTR(&picosystem_blend_obj) },
    { MP_ROM_QSTR(MP_QSTR_target), MP_ROM_PTR(&picosystem_target_obj) },
    { MP_ROM_QSTR(MP_QSTR_camera), MP_ROM_PTR(&picosystem_camera_obj) },
    { MP_ROM_QSTR(MP_QSTR_spritesheet), MP_ROM_PTR(&picosystem_spritesheet_obj) },

    { MP_ROM_QSTR(MP_QSTR_clear), MP_ROM_PTR(&picosystem_clear_obj) },
    { MP_ROM_QSTR(MP_QSTR_pixel), MP_ROM_PTR(&picosystem_pixel_obj) },
    { MP_ROM_QSTR(MP_QSTR_hline), MP_ROM_PTR(&picosystem_hline_obj) },
    { MP_ROM_QSTR(MP_QSTR_vline), MP_ROM_PTR(&picosystem_vline_obj) },
    { MP_ROM_QSTR(MP_QSTR_rect), MP_ROM_PTR(&picosystem_rect_obj) },
    { MP_ROM_QSTR(MP_QSTR_circle), MP_ROM_PTR(&picosystem_circle_obj) },
    { MP_ROM_QSTR(MP_QSTR_poly), MP_ROM_PTR(&picosystem_poly_obj) },
    { MP_ROM_QSTR(MP_QSTR_frect), MP_ROM_PTR(&picosystem_frect_obj) },
    { MP_ROM_QSTR(MP_QSTR_fcircle), MP_ROM_PTR(&picosystem_fcircle_obj) },
    { MP_ROM_QSTR(MP_QSTR_fpoly), MP_ROM_PTR(&picosystem_fpoly_obj) },
    { MP_ROM_QSTR(MP_QSTR_line), MP_ROM_PTR(&picosystem_line_obj) },
    { MP_ROM_QSTR(MP_QSTR_blit), MP_ROM_PTR(&picosystem_blit_obj) },
    { MP_ROM_QSTR(MP_QSTR_sprite), MP_ROM_PTR(&picosystem_sprite_obj) },
    { MP_ROM_QSTR(MP_QSTR_text), MP_ROM_PTR(&picosystem_text_obj) },
    { MP_ROM_QSTR(MP_QSTR_text_width), MP_ROM_PTR(&picosystem_text_width_obj) },

    { MP_ROM_QSTR(MP_QSTR_rgb), MP_ROM_PTR(&picosystem_rgb_obj) },
    { MP_ROM_QSTR(MP_QSTR_hsv), MP_ROM_PTR(&picosystem_hsv_obj) },

    { MP_ROM_QSTR(MP_QSTR_intersects), MP_ROM_PTR(&picosystem_intersects_obj) },
    { MP_ROM_QSTR(MP_QSTR_intersection), MP_ROM_PTR(&picosystem_intersection_obj) },
    { MP_ROM_QSTR(MP_QSTR_contains), MP_ROM_PTR(&picosystem_contains_obj) },

    { MP_ROM_QSTR(MP_QSTR_pressed), MP_ROM_PTR(&picosystem_pressed_obj) },
    { MP_ROM_QSTR(MP_QSTR_button), MP_ROM_PTR(&picosystem_button_obj) },
    { MP_ROM_QSTR(MP_QSTR_battery), MP_ROM_PTR(&picosystem_battery_obj) },
    { MP_ROM_QSTR(MP_QSTR_led), MP_ROM_PTR(&picosystem_led_obj) },
    { MP_ROM_QSTR(MP_QSTR_backlight), MP_ROM_PTR(&picosystem_backlight_obj) },

    { MP_ROM_QSTR(MP_QSTR_UP), MP_ROM_INT(UP) },
    { MP_ROM_QSTR(MP_QSTR_DOWN), MP_ROM_INT(DOWN) },
    { MP_ROM_QSTR(MP_QSTR_LEFT), MP_ROM_INT(LEFT) },
    { MP_ROM_QSTR(MP_QSTR_RIGHT), MP_ROM_INT(RIGHT) },
    { MP_ROM_QSTR(MP_QSTR_A), MP_ROM_INT(A) },
    { MP_ROM_QSTR(MP_QSTR_B), MP_ROM_INT(B) },
    { MP_ROM_QSTR(MP_QSTR_X), MP_ROM_INT(X) },
    { MP_ROM_QSTR(MP_QSTR_Y), MP_ROM_INT(Y) },
    { MP_ROM_QSTR(MP_QSTR_COPY), MP_ROM_INT(MODE_COPY) },
    { MP_ROM_QSTR(MP_QSTR_BLEND), MP_ROM_INT(MODE_BLEND) },
    { MP_ROM_QSTR(MP_QSTR_MASK), MP_ROM_INT(MODE_MASK) },

    { MP_ROM_QSTR(MP_QSTR_CHERRY), MP_ROM_INT(CHERRY) },
    { MP_ROM_QSTR(MP_QSTR_APPLE), MP_ROM_INT(APPLE) },
    { MP_ROM_QSTR(MP_QSTR_BANANA), MP_ROM_INT(BANANA) },
    { MP_ROM_QSTR(MP_QSTR_ORANGE), MP_ROM_INT(ORANGE) },
    { MP_ROM_QSTR(MP_QSTR_AUBERGINE), MP_ROM_INT(AUBERGINE) },
    { MP_ROM_QSTR(MP_QSTR_CARROT), MP_ROM_INT(CARROT) },
    { MP_ROM_QSTR(MP_QSTR_POTATO), MP_ROM_INT(POTATO) },
    { MP_ROM_QSTR(MP_QSTR_LEAF), MP_ROM_INT(LEAF) },
    { MP_ROM_QSTR(MP_QSTR_PARSNIP), MP_ROM_INT(PARSNIP) },
    { MP_ROM_QSTR(MP_QSTR_MEAT), MP_ROM_INT(MEAT) },
    { MP_ROM_QSTR(MP_QSTR_BEAN), MP_ROM_INT(BEAN) },
    { MP_ROM_QSTR(MP_QSTR_RADISH), MP_ROM_INT(RADISH) },
    { MP_ROM_QSTR(MP_QSTR_STRAWBERRY), MP_ROM_INT(STRAWBERRY) },
    { MP_ROM_QSTR(MP_QSTR_PUMPKIN), MP_ROM_INT(PUMPKIN) },
    { MP_ROM_QSTR(MP_QSTR_CUCUMBER), MP_ROM_INT(CUCUMBER) },
    { MP_ROM_QSTR(MP_QSTR_SALT), MP_ROM_INT(SALT) },
    { MP_ROM_QSTR(MP_QSTR_SWORD1), MP_ROM_INT(SWORD1) },
    { MP_ROM_QSTR(MP_QSTR_SWORD2), MP_ROM_INT(SWORD2) },
    { MP_ROM_QSTR(MP_QSTR_SWORD3), MP_ROM_INT(SWORD3) },
    { MP_ROM_QSTR(MP_QSTR_AXE), MP_ROM_INT(AXE) },
    { MP_ROM_QSTR(MP_QSTR_DAGGER), MP_ROM_INT(DAGGER) },
    { MP_ROM_QSTR(MP_QSTR_MACE), MP_ROM_INT(MACE) },
    { MP_ROM_QSTR(MP_QSTR_BOW), MP_ROM_INT(BOW) },
    { MP_ROM_QSTR(MP_QSTR_ARROW1), MP_ROM_INT(ARROW1) },
    { MP_ROM_QSTR(MP_QSTR_ARROW2), MP_ROM_INT(ARROW2) },
    { MP_ROM_QSTR(MP_QSTR_ARROW3), MP_ROM_INT(ARROW3) },
    { MP_ROM_QSTR(MP_QSTR_TRIDENT1), MP_ROM_INT(TRIDENT1) },
    { MP_ROM_QSTR(MP_QSTR_SPEAR), MP_ROM_INT(SPEAR) },
    { MP_ROM_QSTR(MP_QSTR_TRIDENT2), MP_ROM_INT(TRIDENT2) },
    { MP_ROM_QSTR(MP_QSTR_MACHINEGUN), MP_ROM_INT(MACHINEGUN) },
    { MP_ROM_QSTR(MP_QSTR_PISTOL), MP_ROM_INT(PISTOL) },
    { MP_ROM_QSTR(MP_QSTR_SHOTGUN), MP_ROM_INT(SHOTGUN) },
    { MP_ROM_QSTR(MP_QSTR_GEM1), MP_ROM_INT(GEM1) },
    { MP_ROM_QSTR(MP_QSTR_GEM2), MP_ROM_INT(GEM2) },
    { MP_ROM_QSTR(MP_QSTR_GEM3), MP_ROM_INT(GEM3) },
    { MP_ROM_QSTR(MP_QSTR_GEM4), MP_ROM_INT(GEM4) },
    { MP_ROM_QSTR(MP_QSTR_GEM5), MP_ROM_INT(GEM5) },
    { MP_ROM_QSTR(MP_QSTR_GEM6), MP_ROM_INT(GEM6) },
    { MP_ROM_QSTR(MP_QSTR_AMULET), MP_ROM_INT(AMULET) },
    { MP_ROM_QSTR(MP_QSTR_FOLDER), MP_ROM_INT(FOLDER) },
    { MP_ROM_QSTR(MP_QSTR_COIN), MP_ROM_INT(COIN) },
    { MP_ROM_QSTR(MP_QSTR_SKULL), MP_ROM_INT(SKULL) },
    { MP_ROM_QSTR(MP_QSTR_TICK), MP_ROM_INT(TICK) },
    { MP_ROM_QSTR(MP_QSTR_CROSS), MP_ROM_INT(CROSS) },
    { MP_ROM_QSTR(MP_QSTR_IDOL1), MP_ROM_INT(IDOL1) },
    { MP_ROM_QSTR(MP_QSTR_IDOL2), MP_ROM_INT(IDOL2) },
    { MP_ROM_QSTR(MP_QSTR_IDOL3), MP_ROM_INT(IDOL3) },
    { MP_ROM_QSTR(MP_QSTR_IDOL4), MP_ROM_INT(IDOL4) },
    { MP_ROM_QSTR(MP_QSTR_SWEETCORN), MP_ROM_INT(SWEETCORN) },
    { MP_ROM_QSTR(MP_QSTR_BROCCOLI), MP_ROM_INT(BROCCOLI) },
    { MP_ROM_QSTR(MP_QSTR_BISCUIT), MP_ROM_INT(BISCUIT) },
    { MP_ROM_QSTR(MP_QSTR_BERRIES), MP_ROM_INT(BERRIES) },
    { MP_ROM_QSTR(MP_QSTR_SCEPTRE), MP_ROM_INT(SCEPTRE) },
    { MP_ROM_QSTR(MP_QSTR_FIRE), MP_ROM_INT(FIRE) },
    { MP_ROM_QSTR(MP_QSTR_LASERGUN1), MP_ROM_INT(LASERGUN1) },
    { MP_ROM_QSTR(MP_QSTR_LASERGUN2), MP_ROM_INT(LASERGUN2) },
    { MP_ROM_QSTR(MP_QSTR_HELMET1), MP_ROM_INT(HELMET1) },
    { MP_ROM_QSTR(MP_QSTR_HELMET2), MP_ROM_INT(HELMET2) },
    { MP_ROM_QSTR(MP_QSTR_HELMET3), MP_ROM_INT(HELMET3) },
    { MP_ROM_QSTR(MP_QSTR_HELMET4), MP_ROM_INT(HELMET4) },
};
STATIC MP_DEFINE_CONST_DICT(mp_module_picosystem_globals, picosystem_globals_table);

/***** Module Definition *****/
const mp_obj_module_t picosystem_user_cmodule = {
    .base = { &mp_type_module },
    .globals = (mp_obj_dict_t*)&mp_module_picosystem_globals,
};

////////////////////////////////////////////////////////////////////////////////////////////////////
MP_REGISTER_MODULE(MP_QSTR_picosystem, picosystem_user_cmodule, MODULE_PICOSYSTEM_ENABLED);
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
