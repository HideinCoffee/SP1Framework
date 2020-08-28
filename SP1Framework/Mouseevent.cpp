#include "Mouseevent.h"
SMouseEvent g_mouseEvent;
void mouseHandler(const MOUSE_EVENT_RECORD& mouseEvent,EGAMESTATES &g_GameState)
{
    switch (g_eGameState)
    {
    case EGAMESTATES::S_SPLASHSCREEN: // don't handle anything for the splash screen
        break;
    case EGAMESTATES::S_GAME: gameplayMouseHandler(mouseEvent); // handle gameplay mouse event
        break;
    case EGAMESTATES::S_MAINMENU: gameplayMouseHandler(mouseEvent); // handle main menu mousevent
        break;
    }
}

void gameplayMouseHandler(const MOUSE_EVENT_RECORD& mouseEvent)
{
    if (mouseEvent.dwEventFlags & MOUSE_MOVED) // update the mouse position if there are no events
    {
        g_mouseEvent.mousePosition = mouseEvent.dwMousePosition;
    }
    g_mouseEvent.buttonState = mouseEvent.dwButtonState;
    g_mouseEvent.eventFlags = mouseEvent.dwEventFlags;
}





