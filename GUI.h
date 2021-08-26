#pragma once

#include "lvgl.h"

class GUI
{
    private:
        lv_obj_t * mParent = nullptr;

    private:
        static void onButtonPress(lv_event_t * ev);

    public:
        GUI(lv_obj_t * parent);

        void draw();
};
