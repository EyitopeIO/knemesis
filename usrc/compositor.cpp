/*
* Today: 6-Nov-2022
* Human: Eyitope Adelowo
*/

#include "compositor.hpp"


// Defined the the display module
extern "C" struct ui_extras display_ui_extras;


/* 
 *  TODO: Auto-generate the vectors in WaitingRoom based on AlertLevel

 *  Each vector corresponds to AlertLevels stored in order of arrival  
*/
std::list<Message> do_something_now_list;
std::list<Message> updates_list;
std::list<Message> just_in_case_youre_there_list;


int add_messages_to_wait_list(struct Message msg); 
Message* get_next_message_linear_order(void);



int add_messages_to_wait_list(struct Message msg) 
{
    if (msg.level == AlertLevel::DO_SOMETHING_NOW)
        do_something_now_list.push_back(msg);
    else if (msg.level == AlertLevel::UPDATES)
        updates_list.push_back(msg);
    else if (msg.level == AlertLevel::JUST_IN_CASE_YOURE_THERE)
        just_in_case_youre_there_list.push_back(msg);
    else
        return 0;
    return 1; 
}

Message* get_next_message_linear_order(void)
{
    static struct Message tmp_do_something_now;
    static struct Message tmp_updates;
    static struct Message tmp_just_in_case_youre_there;

    if (!do_something_now_list.empty()) {
        tmp_do_something_now = do_something_now_list.front();
        do_something_now_list.pop_front();
        return &tmp_do_something_now;
    }
    else if (!updates_list.empty()) {
        tmp_updates = updates_list.front();
        updates_list.pop_front();
        return &tmp_updates;
    }
    else if (!just_in_case_youre_there_list.empty()) {
        tmp_just_in_case_youre_there = just_in_case_youre_there_list.front();
        just_in_case_youre_there_list.pop_front();
        return &tmp_just_in_case_youre_there;
    }
    else {
        return nullptr;
    }
}



Compositor::Compositor() 
{
    this->ui = display_ui_extras;
}

Compositor::~Compositor()
{
    this->ui.enit();
}

int Compositor::run()
{
    return this->ui.init();
}