#pragma once
#include "Framework/console.h"
struct SMouseEvent
{
    COORD mousePosition;
    DWORD buttonState;
    DWORD eventFlags;
};

void mouseHandler(const MOUSE_EVENT_RECORD& mouseEvent);

void gameplayMouseHandler(const MOUSE_EVENT_RECORD& mouseEvent);







