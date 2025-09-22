#include "lvgl.h"
#include "app_hal.h"

#ifdef ARDUINO
#include <Arduino.h>

void setup() {
  hal_setup();
}

void loop() {
  hal_loop();
}

#else

const char* my_svg_data = R"(S:<svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 24 24"><path d="M12,8L10.67,8.09C9.81,7.07 7.4,4.5 5,4.5C5,4.5 3.03,7.46 4.96,11.41C4.41,12.24 4.07,12.67 4,13.66L2.07,13.95L2.28,14.93L4.04,14.67L4.18,15.38L2.61,16.32L3.08,17.21L4.53,16.32C5.68,18.76 8.59,20 12,20C15.41,20 18.32,18.76 19.47,16.32L20.92,17.21L21.39,16.32L19.82,15.38L19.96,14.67L21.72,14.93L21.93,13.95L20,13.66C19.93,12.67 19.59,12.24 19.04,11.41C20.97,7.46 19,4.5 19,4.5C16.6,4.5 14.19,7.07 13.33,8.09L12,8M9,11A1,1 0 0,1 10,12A1,1 0 0,1 9,13A1,1 0 0,1 8,12A1,1 0 0,1 9,11M15,11A1,1 0 0,1 16,12A1,1 0 0,1 15,13A1,1 0 0,1 14,12A1,1 0 0,1 15,11M11,14H13L12.3,15.39C12.5,16.03 13.06,16.5 13.75,16.5A1.5,1.5 0 0,0 15.25,15H15.75A2,2 0 0,1 13.75,17C13,17 12.35,16.59 12,16V16H12C11.65,16.59 11,17 10.25,17A2,2 0 0,1 8.25,15H8.75A1.5,1.5 0 0,0 10.25,16.5C10.94,16.5 11.5,16.03 11.7,15.39L11,14Z" /></svg>)";

LV_FONT_DECLARE(Montserrat_20br);
LV_FONT_DECLARE(Montserrat_20r);
LV_FONT_DECLARE(Montserrat_14r);

void meal_row_display_create(lv_obj_t* parent, const char* name){

    lv_obj_t * cont = lv_obj_create(parent); 
    lv_obj_set_scroll_dir(cont, LV_DIR_NONE); 
    lv_obj_set_size(cont, 240, 60);
    lv_obj_set_scrollbar_mode(cont, LV_SCROLLBAR_MODE_OFF);
    lv_obj_set_style_pad_all(cont, 5, LV_PART_MAIN);
    lv_obj_set_style_border_width(cont, 2,LV_STYLE_STATE_CMP_SAME );
    lv_obj_set_style_border_color(cont, lv_color_hex(0xFFFFFF), LV_STYLE_STATE_CMP_SAME);
    lv_obj_set_style_bg_color(cont, lv_color_hex(0x000000), LV_PART_MAIN);

    lv_obj_t* mealNameLabel = lv_label_create(cont);
    lv_label_set_text(mealNameLabel, name);
    lv_obj_set_style_text_font(mealNameLabel, &Montserrat_20br, 0);
    lv_obj_align(mealNameLabel, LV_ALIGN_LEFT_MID, 0, 0);

    lv_obj_t* timeLabel = lv_label_create(cont);
    lv_label_set_text(timeLabel, "в 07:00");
    lv_obj_set_style_text_font(timeLabel, &Montserrat_14r, 0);
    lv_obj_align(timeLabel, LV_ALIGN_LEFT_MID, 108,0 );

    lv_obj_t * checkbox = lv_obj_create(cont); 
    lv_obj_set_size(checkbox, 50, 50);
    lv_obj_set_style_border_width(checkbox, 4,LV_STYLE_STATE_CMP_SAME );
    lv_obj_align(checkbox, LV_ALIGN_RIGHT_MID, 0, 0);
    lv_obj_set_style_border_color(checkbox, lv_color_hex(0xFFFFFF), LV_STYLE_STATE_CMP_SAME);
}

void statusbar_create(lv_obj_t* parent){
    lv_obj_t * cont = lv_obj_create(parent); 
    lv_obj_set_scroll_dir(cont, LV_DIR_NONE); 
    lv_obj_set_size(cont, 240, 30);
    lv_obj_set_style_border_side(cont, LV_BORDER_SIDE_BOTTOM, 0);
    lv_obj_set_style_border_width(cont, 2, LV_STYLE_STATE_CMP_SAME);
    lv_obj_set_style_radius(cont, 0,0);
    lv_obj_set_style_border_color(cont, lv_color_hex(0xFFFFFF), LV_STYLE_STATE_CMP_SAME);

    lv_obj_set_scrollbar_mode(cont, LV_SCROLLBAR_MODE_OFF);
    lv_obj_set_style_pad_all(cont, 0, LV_PART_MAIN);
    lv_obj_set_style_bg_color(cont, lv_color_hex(0x000000), LV_PART_MAIN);

    lv_obj_set_flex_flow(cont, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(cont, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_SPACE_AROUND, LV_FLEX_ALIGN_START);

    lv_obj_t* timeLabel = lv_label_create(cont);
    lv_label_set_text(timeLabel, "20:00");
    lv_obj_set_style_text_font(timeLabel, &Montserrat_20r, 0);

    lv_obj_t* batLabel = lv_label_create(cont);
    lv_label_set_text(batLabel, "100%");
    lv_obj_set_style_text_font(batLabel, &Montserrat_20r, 0);
}

void create_schedule_screen(lv_obj_t * parent) {
    // Create the background container for the screen
    lv_obj_t * cont = lv_obj_create(parent);  // Use lv_obj_create instead of lv_cont_create
    lv_obj_set_scroll_dir(cont, LV_DIR_NONE); 
    lv_obj_set_style_border_width(cont, 0,LV_STYLE_STATE_CMP_SAME );
    lv_obj_set_size(cont, 240, 320);
    lv_obj_align(cont, LV_ALIGN_CENTER, 0, 0);  // Align correctly using LV_ALIGN_CENTER

    // Set background color
    lv_obj_set_style_bg_color(cont, lv_color_hex(0x000000), LV_PART_MAIN);
    lv_obj_set_style_bg_opa(cont, 255, LV_PART_MAIN);

    // Настраиваем flex layout для вертикального расположения
    lv_obj_set_flex_flow(cont, LV_FLEX_FLOW_COLUMN);  // Вертикальное расположение
    lv_obj_set_flex_align(cont, LV_FLEX_ALIGN_SPACE_AROUND, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);

    // Убираем стандартные отступы и скролл
    lv_obj_set_style_pad_all(cont, 0, LV_PART_MAIN);
    // lv_obj_set_style_pad_row(cont, 15, LV_PART_MAIN);  // Отступ между строками
    lv_obj_set_scrollbar_mode(cont, LV_SCROLLBAR_MODE_OFF);


    statusbar_create(cont);

    meal_row_display_create(cont, "ЗАВТРАК");
    meal_row_display_create(cont, "ОБЕД");
    meal_row_display_create(cont, "УЖИН");
    meal_row_display_create(cont, "УЖИН 2");

    // Create time labels
    // time_label1 = lv_label_create(cont);
    // lv_label_set_text(time_label1, "07:00");
    // lv_obj_align(time_label1,LV_ALIGN_TOP_RIGHT, -10, 10);

    // // Create cat icons next to each label
    // lv_obj_t * cat_icon1 = lv_image_create(cont);
    // lv_image_set_src(cat_icon1, my_svg_data); // Use your cat icon image here
    // lv_obj_align(cat_icon1, LV_ALIGN_RIGHT_MID, 10, 0);

    // lv_obj_t * cat_icon2 = lv_image_create(cont);
    // lv_image_set_src(cat_icon2, my_svg_data); // Use your cat icon image here
    // lv_obj_align(cat_icon2, LV_ALIGN_RIGHT_MID, 10, 0);

    // lv_obj_t * cat_icon3 = lv_image_create(cont);
    // lv_image_set_src(cat_icon3, my_svg_data); // Use your cat icon image here
    // lv_obj_align(cat_icon3,  LV_ALIGN_RIGHT_MID, 10, 0);

    // lv_obj_t * cat_icon4 = lv_image_create(cont);
    // lv_image_set_src(cat_icon4, my_svg_data); // Use your cat icon image here
    // lv_obj_align(cat_icon4,  LV_ALIGN_RIGHT_MID, 10, 0);
}

int main(void)
{
	lv_init();
	hal_setup();

  lv_obj_t * scr = lv_scr_act();  // Active screen
  create_schedule_screen(scr);

  while(1){
    hal_loop();
  }

}

#endif /*ARDUINO*/