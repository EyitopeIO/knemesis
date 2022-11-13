/*
* Today: 6-Nov-2022
* Human: Eyitope Adelowo


    This file uses the Nextion driver to carry out compositor operations.

    Some functions link to the Linux kernel. They are few and neccessarily have an `extern`.

*/

#include "nextion.h"
#include "common.h"
#include <stdio.h>
#include <stdlib.h>


// TODO: Define an enum for error types.


static int nextion_init(void);
static void nextion_enit(void);
static void nextion_enit(void);
static void nextion_restart(void);
static void nextion_backlight_control(unsigned char percentage);


static FILE* file_descriptor;


struct ui_extras display_ui_extras = {
    nextion_init,
    nextion_enit,
    nextion_restart,
    nextion_backlight_control,
    NULL
};


static int nextion_init(void)
{
    file_descriptor = fopen(DEVICE, "r+");
    if (file_descriptor == NULL) {
        return 1;
    }
    else {
        return 0;
    }
}


static void nextion_enit(void) {
    if (file_descriptor != NULL)
        fclose(file_descriptor);
}

static void nextion_restart(void)
{
    return;
}

static void nextion_backlight_control(unsigned char percentage)
{
    return;
}


