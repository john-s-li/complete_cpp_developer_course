#ifndef WARP_DRIVE_OVERHEATING_H
#define WARP_DRIVE_OVERHEATING_H

#include <stdexcept>

using namespace std;

class warpDriveOverheating : public overflow_error
{
    public:
        warpDriveOverheating() : overflow_error("Warp drive has exceeded safe temperature tolerance.")
        {
        };
};

#endif