#ifndef DISPLAYPARAMS_H_
#define DISPLAYPARAMS_H_

#include <cstddef>

// small struct to hold display parameters for easier passing
struct DisplayParams{
    std::size_t screen_width;
    std::size_t screen_height;
    std::size_t grid_width;
    std::size_t grid_height;
};

#endif