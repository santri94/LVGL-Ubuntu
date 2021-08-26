#include "GUI.h"
#include "stdio.h"

GUI::GUI(lv_obj_t * parent)
    : mParent(parent)
{
}

void GUI::onButtonPress(lv_event_t * ev)
{
    auto * button = lv_event_get_target(ev);
    printf("Button Was Clicked!\n");
}

void GUI::draw()
{
    auto * obj = lv_obj_create(mParent);
    auto * label = lv_label_create(obj);
    lv_label_set_text(label, "Hi Santi");

    auto * btn = lv_btn_create(mParent);
    lv_obj_set_size(btn, 100, 50);
    lv_obj_center(btn);
    lv_obj_add_event_cb(btn, onButtonPress, LV_EVENT_CLICKED, NULL);

    auto * btnLabel = lv_label_create(btn);
    lv_label_set_text(btnLabel, "Click me!");
    lv_obj_center(btnLabel);
}