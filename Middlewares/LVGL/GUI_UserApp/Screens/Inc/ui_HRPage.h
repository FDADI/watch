#ifndef _UI_HRPAGE_H
#define _UI_HRPAGE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl/lvgl.h"

extern lv_obj_t * ui_HRPage;
extern lv_obj_t * ui_HRPageNumLabel;
extern lv_obj_t * ui_HRPageUnitLabel;
extern lv_obj_t * ui_HRPaggiconLabel;
extern lv_obj_t * ui_HRPageNoticeLabel;

extern uint8_t ui_HRValue;

void ui_HRPage_screen_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
