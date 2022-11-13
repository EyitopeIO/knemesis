/*
* Today: 5-Nov-2022
* Human: Eyitope Adelowo
*/

#ifndef COMPOSITOR_HPP
#define COMPOSITOR_HPP

#include "custom.h"
#include "common.h"
#include <cstddef>
#include <list>



// TODO: Define other message orders
#ifdef POP_ORDER_TYPE_LINEAR 
#define get_next_message    get_next_message_linear_order
#elif POP_ORDER_TYPE_GRACIOUS
#define get_next_message    get_next_message_gracious_order
#endif

#ifdef DISPLAY_TYPE_NEXTION
#define DISPLAY_HARDWARE "nextion"
#elif DISPLAY_TYPE_16BY2_LCD 
#define DISPLAY_HARDWARE "lcd"
#endif



/*
* DO_SOMETHING_NOW:             User needs to take action as soon as possible.
* UPDATES:                      Results of a previous action or an event.
* NOT_THAT_IMPORTANT:           Not critical. Compositor might as well ignore.
*/
enum class AlertLevel { 
    DO_SOMETHING_NOW,
    UPDATES,
    JUST_IN_CASE_YOURE_THERE
};


// TODO: The list a message is put in already identifies its level. Remove redundant info.
/*
 *  datestamp:                  A 32-bit integer at least
 *  alias:                      Short form of the sender's name
 *  text:                       The actual text that the sender wants to show              
*/
struct Message {
    AlertLevel level;
    unsigned long datestamp;    
    char *alias;
    char *text;
};


class Compositor {
    public:
        Compositor();
        ~Compositor();
        int run();
    private:
        struct ui_extras ui;
};

#endif