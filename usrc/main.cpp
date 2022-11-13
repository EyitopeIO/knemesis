
/*
* Today: 5-Nov-2022
* Human: Eyitope Adelowo
*/


/* All C++ headers here */
#include "compositor.hpp"
#include <iostream>
#include <cstdlib>


/* All C headers here */
// #ifdef __cplusplus
// extern "C" {
// #endif



// #ifdef __cplusplus
// }
// #endif



/* GLOBAL */
Compositor compose = Compositor();


int main(int argc, char *argv[])
{
    // Connect to Ubus socket
    // Wait for connections

    if (compose.run()) {
        std::cout << "here: Failed to start compositor.\n" ;
        std::exit(EXIT_FAILURE);
    }
    else {
        std::cout << "here: Display-" << DISPLAY_HARDWARE << "loaded\n" ;
    }




    return 0;
}


