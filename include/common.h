/*
* Today: 6-Nov-2022
* Human: Eyitope Adelowo
*/

#ifndef COMMON_H
#define COMMON_H

enum StaticCoordinates {
    TOP_LEFT,
    TOP_RIGHT,
    BOTTOM_LEFT,
    BOTTOM_RIGHT
};

struct ui_extras {
    int (*init)();
    void (*enit)();
    void (*restart)();
    void (*backlight_control)(unsigned char percentage);
    void (*show_from_coordinate)(enum StaticCoordinates coord);
};

#endif