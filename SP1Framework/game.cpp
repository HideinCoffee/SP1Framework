// This is the main file for the game logic and function
//

#include "game.h"
#include "Framework\console.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include "Rendermap.h"
#include "Rendercharacter.h"
#include "Renderenemy.h"
#include "RenderUI.h"
#include "Rendermainmenu.h"
#include "Mobs.h"
#include "player.h"
#include "Global.h"
#include "Map.h"

double  g_dElapsedTime;
double  g_dDeltaTime;
SKeyEvent g_skKeyEvent[int(EKEYS::K_COUNT)];
SMouseEvent g_mouseEvent;

// Game specific variables here
EGAMESTATES g_eGameState = EGAMESTATES::S_SPLASHSCREEN;
SGameChar   g_sChar;
SGameChar   trigger;
 // initial state
MOVEMENTDIRECTION movementdir;
BULLETDIRECTION bulletdir;
BULLETDIRECTION mobbulletdir;
// Console object
Console g_Console(160, 40, "SP1 Framework");

// map object
Map map;


//--------------------------------------------------------------
// Purpose  : Initialisation function
//            Initialize variables, allocate memory, load data from file, etc. 
//            This is called once before entering into your main loop
// Input    : void
// Output   : void
//--------------------------------------------------------------
void init(void)
{
    // Set precision for floating point output
    g_dElapsedTime = 0.0;    

    // sets the initial state for the game
    g_eGameState = EGAMESTATES::S_GAME;

    g_sChar.m_cLocation.X = g_Console.getConsoleSize().X / 2;
    g_sChar.m_cLocation.Y = g_Console.getConsoleSize().Y / 2;
    g_sChar.m_cLocation1.X = g_Console.getConsoleSize().X / 2;
    g_sChar.m_cLocation1.Y = g_Console.getConsoleSize().Y / 2 + 1;

    g_sChar.m_bActive = true;
    g_sChar.abletomove = true;
    // sets the width, height and the font name to use in the console
    g_Console.setConsoleFont(0, 16, L"Consolas");

    // remember to set your keyboard handler, so that your functions can be notified of input events
    g_Console.setKeyboardHandler(keyboardHandler);
    g_Console.setMouseHandler(mouseHandler);
    
    g_sChar.offset.X = 0;
    g_sChar.offset.Y = 0;

    // traps shooting to the right 0-49
    traparray[0] = new Trap(map, BULLETYPE::B_C, 57, 130); // first part of map
    //traparray[1] = new Trap(map, BULLETYPE::B_C, 57, 131);
    //traparray[2] = new Trap(map, BULLETYPE::B_C, 51, 119);
    //traparray[3] = new Trap(map, BULLETYPE::B_C, 51, 123);
    //traparray[4] = new Trap(map, BULLETYPE::B_C, 57, 146);
    //traparray[5] = new Trap(map, BULLETYPE::B_C, 78, 122);
    //traparray[6] = new Trap(map, BULLETYPE::B_C, 78, 118);
    //traparray[7] = new Trap(map, BULLETYPE::B_C, 93, 139);
    //traparray[8] = new Trap(map, BULLETYPE::B_C, 93, 141);

    //traparray[9] = new Trap(map, BULLETYPE::B_C, 140, 107); // second part of map
    //traparray[10] = new Trap(map, BULLETYPE::B_C, 118, 93);
    //traparray[11] = new Trap(map, BULLETYPE::B_C, 98, 91);
    //traparray[12] = new Trap(map, BULLETYPE::B_C, 92, 104);
    //traparray[13] = new Trap(map, BULLETYPE::B_C, 92, 86);
    //traparray[14] = new Trap(map, BULLETYPE::B_C, 92, 87);
    //traparray[15] = new Trap(map, BULLETYPE::B_C, 2, 77);
    //traparray[16] = new Trap(map, BULLETYPE::B_C, 2, 78);

    // traps shooting to the left 50-99
    traparray[50] = new Trap(map, BULLETYPE::B_C, 63, 134); // first part of map
    //traparray[51] = new Trap(map, BULLETYPE::B_C, 63, 135);
    //traparray[52] = new Trap(map, BULLETYPE::B_C, 82, 142);
    //traparray[53] = new Trap(map, BULLETYPE::B_C, 76, 121);
    //traparray[54] = new Trap(map, BULLETYPE::B_C, 76, 122);
    //traparray[55] = new Trap(map, BULLETYPE::B_C, 91, 125);
    //traparray[56] = new Trap(map, BULLETYPE::B_C, 96, 116);
    //traparray[57] = new Trap(map, BULLETYPE::B_C, 105, 115);

    //traparray[58] = new Trap(map, BULLETYPE::B_C, 141, 104); // second part of map
    //traparray[59] = new Trap(map, BULLETYPE::B_C, 140, 97);
    //traparray[60] = new Trap(map, BULLETYPE::B_C, 147, 88);
    //traparray[61] = new Trap(map, BULLETYPE::B_C, 147, 90);
    //traparray[62] = new Trap(map, BULLETYPE::B_C, 147, 78);
    //traparray[63] = new Trap(map, BULLETYPE::B_C, 124, 76);
    //traparray[64] = new Trap(map, BULLETYPE::B_C, 124, 78);

    //traps shooting to the top 100-149
    traparray[100] = new Trap(map, BULLETYPE::B_C, 55, 147); // first part of map
    ////traparray[101] = new Trap(map, BULLETYPE::B_C, 103, 120);
    ////traparray[102] = new Trap(map, BULLETYPE::B_C, 106, 120);
    //traparray[103] = new Trap(map, BULLETYPE::B_C, 126, 147);
    //traparray[104] = new Trap(map, BULLETYPE::B_C, 132, 147);

    //traparray[105] = new Trap(map, BULLETYPE::B_C, 135, 108); // second part of map
    //traparray[106] = new Trap(map, BULLETYPE::B_C, 128, 111);
    //traparray[107] = new Trap(map, BULLETYPE::B_C, 122, 105);
    //traparray[108] = new Trap(map, BULLETYPE::B_C, 109, 111);
    //traparray[109] = new Trap(map, BULLETYPE::B_C, 103, 111);
    //traparray[110] = new Trap(map, BULLETYPE::B_C, 115, 105);
    //traparray[111] = new Trap(map, BULLETYPE::B_C, 114, 105);
    //traparray[112] = new Trap(map, BULLETYPE::B_C, 104, 105);
    //traparray[113] = new Trap(map, BULLETYPE::B_C, 108, 79);
    //traparray[114] = new Trap(map, BULLETYPE::B_C, 74, 79);
    //traparray[115] = new Trap(map, BULLETYPE::B_C, 24, 82);
    //traparray[116] = new Trap(map, BULLETYPE::B_C, 25, 82);
    //traparray[117] = new Trap(map, BULLETYPE::B_C, 19, 82);
    //traparray[118] = new Trap(map, BULLETYPE::B_C, 20, 82);
    //traparray[119] = new Trap(map, BULLETYPE::B_C, 14, 82);
    //traparray[120] = new Trap(map, BULLETYPE::B_C, 15, 82);
    //traparray[121] = new Trap(map, BULLETYPE::B_C, 85, 108);
    //traparray[122] = new Trap(map, BULLETYPE::B_C, 90, 108);

    //traps shooting to the bottom 150-199
    traparray[150] = new Trap(map, BULLETYPE::B_C, 51, 125); // first part of map
    //traparray[151] = new Trap(map, BULLETYPE::B_C, 66, 115);
    //traparray[152] = new Trap(map, BULLETYPE::B_C, 70, 115);
    //traparray[153] = new Trap(map, BULLETYPE::B_C, 68, 122);
    //traparray[154] = new Trap(map, BULLETYPE::B_C, 111, 121);
    //traparray[155] = new Trap(map, BULLETYPE::B_C, 99, 129);
    //traparray[156] = new Trap(map, BULLETYPE::B_C, 103, 129);
    //traparray[157] = new Trap(map, BULLETYPE::B_C, 121, 133);
    //traparray[158] = new Trap(map, BULLETYPE::B_C, 122, 133);
    //traparray[159] = new Trap(map, BULLETYPE::B_C, 129, 115);

    //traparray[160] = new Trap(map, BULLETYPE::B_C, 142, 92); // second part of map
    //traparray[161] = new Trap(map, BULLETYPE::B_C, 110, 87);
    //traparray[162] = new Trap(map, BULLETYPE::B_C, 111, 87);
    //traparray[163] = new Trap(map, BULLETYPE::B_C, 106, 90);
    //traparray[164] = new Trap(map, BULLETYPE::B_C, 94, 94);
    //traparray[165] = new Trap(map, BULLETYPE::B_C, 142, 80);
    //traparray[166] = new Trap(map, BULLETYPE::B_C, 130, 76);
    //traparray[167] = new Trap(map, BULLETYPE::B_C, 107, 81);
    //traparray[168] = new Trap(map, BULLETYPE::B_C, 97, 75);
    //traparray[169] = new Trap(map, BULLETYPE::B_C, 53, 75);
    //traparray[170] = new Trap(map, BULLETYPE::B_C, 87, 80);
    //traparray[171] = new Trap(map, BULLETYPE::B_C, 88, 80);
    //traparray[172] = new Trap(map, BULLETYPE::B_C, 81, 85);
    //traparray[173] = new Trap(map, BULLETYPE::B_C, 80, 85);
    playerarray[0] = new Player(map,BULLETYPE::B_P,31,117,1);
    movementdir.LEFT = true;
    enemyarray[0] = new Mobs(30,115,6,'m',true,movementdir);
}

//--------------------------------------------------------------
// Purpose  : Reset before exiting the program
//            Do your clean up of memory here
//            This is called once just before the game exits
// Input    : Void
// Output   : void
//--------------------------------------------------------------
void shutdown( void )
{
    // Reset to white text on black background
    colour(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);

    g_Console.clearBuffer();
}

//--------------------------------------------------------------
// Purpose  : Get all the console input events
//            This function sets up the keyboard and mouse input from the console.
//            We will need to reset all the keyboard status, because no events will be sent if no keys are pressed.
//
//            Remember to set the handlers for keyboard and mouse events.
//            The function prototype of the handler is a function that takes in a const reference to the event struct
//            and returns nothing. 
//            void pfKeyboardHandler(const KEY_EVENT_RECORD&);
//            void pfMouseHandlerconst MOUSE_EVENT_RECORD&);
// Input    : Void
// Output   : void
//--------------------------------------------------------------
void getInput( void )
{
    // resets all the keyboard events
    //memset(g_skKeyEvent, 0, K_COUNT * sizeof(*g_skKeyEvent));
    // then call the console to detect input from user
    g_Console.readConsoleInput();    
}

//--------------------------------------------------------------
// Purpose  : This is the handler for the keyboard input. Whenever there is a keyboard event, this function will be called.
//            Ideally, you should pass the key event to a specific function to handle the event.
//            This is because in some states, some keys would be disabled. Hence, to reduce your code complexity, 
//            it would be wise to split your keyboard input handlers separately.
//            
//            The KEY_EVENT_RECORD struct has more attributes that you can use, if you are adventurous enough.
//
//            In this case, we are not handling any keyboard event in the Splashscreen state
//            
// Input    : const KEY_EVENT_RECORD& keyboardEvent - reference to a key event struct
// Output   : void
//--------------------------------------------------------------

void keyboardHandler(const KEY_EVENT_RECORD& keyboardEvent)
{    
    switch (g_eGameState)
    {
    case EGAMESTATES::S_SPLASHSCREEN: // don't handle anything for the splash screen
        break;
    case EGAMESTATES::S_GAME: gameplayKBHandler(keyboardEvent); // handle gameplay keyboard event 
        break;
    }
}

//--------------------------------------------------------------
// Purpose  : This is the handler for the mouse input. Whenever there is a mouse event, this function will be called.
//            Ideally, you should pass the key event to a specific function to handle the event.
//            This is because in some states, some keys would be disabled. Hence, to reduce your code complexity, 
//            it would be wise to split your keyboard input handlers separately.
//            
//            For the mouse event, if the mouse is not moved, no event will be sent, hence you should not reset the mouse status.
//            However, if the mouse goes out of the window, you would not be able to know either. 
//
//            The MOUSE_EVENT_RECORD struct has more attributes that you can use, if you are adventurous enough.
//
//            In this case, we are not handling any mouse event in the Splashscreen state
//            
// Input    : const MOUSE_EVENT_RECORD& mouseEvent - reference to a mouse event struct
// Output   : void
//--------------------------------------------------------------

void mouseHandler(const MOUSE_EVENT_RECORD& mouseEvent)
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

//--------------------------------------------------------------
// Purpose  : This is the keyboard handler in the game state. Whenever there is a keyboard event in the game state, this function will be called.
//            
//            Add more keys to the enum in game.h if you need to detect more keys
//            To get other VK key defines, right click on the VK define (e.g. VK_UP) and choose "Go To Definition" 
//            For Alphanumeric keys, the values are their ascii values (uppercase).
// Input    : const KEY_EVENT_RECORD& keyboardEvent
// Output   : void
//--------------------------------------------------------------
void gameplayKBHandler(const KEY_EVENT_RECORD& keyboardEvent)
{
    // here, we map the key to our enums
    EKEYS key = EKEYS::K_COUNT;
    switch (keyboardEvent.wVirtualKeyCode)
    {
    case 0x57: key = EKEYS::K_UP; break;
    case 0x53: key = EKEYS::K_DOWN; break;
    case 0x41: key = EKEYS::K_LEFT; break;
    case 0x44: key = EKEYS::K_RIGHT; break;
    case VK_UP: key = EKEYS::A_UP; break;
    case VK_DOWN: key = EKEYS::A_DOWN; break;
    case VK_LEFT: key = EKEYS::A_LEFT; break;
    case VK_RIGHT: key = EKEYS::A_RIGHT; break;
    case VK_SPACE: key = EKEYS::K_SPACE; break;
    case VK_ESCAPE: key = EKEYS::K_ESCAPE; break;
    }
    // a key pressed event would be one with bKeyDown == true
    // a key released event would be one with bKeyDown == false
    // if no key is pressed, no event would be fired.
    // so we are tracking if a key is either pressed, or released
    if (key != EKEYS::K_COUNT)
    {
        g_skKeyEvent[int(key)].keyDown = keyboardEvent.bKeyDown;
        g_skKeyEvent[int(key)].keyReleased = !keyboardEvent.bKeyDown;
    }    
}

//--------------------------------------------------------------
// Purpose  : This is the mouse handler in the game state. Whenever there is a mouse event in the game state, this function will be called.
//            
//            If mouse clicks are detected, the corresponding bit for that mouse button will be set.
//            mouse wheel, 
//            
// Input    : const KEY_EVENT_RECORD& keyboardEvent
// Output   : void
//--------------------------------------------------------------
void gameplayMouseHandler(const MOUSE_EVENT_RECORD& mouseEvent)
{
    if (mouseEvent.dwEventFlags & MOUSE_MOVED) // update the mouse position if there are no events
    {
        g_mouseEvent.mousePosition = mouseEvent.dwMousePosition;
    }
    g_mouseEvent.buttonState = mouseEvent.dwButtonState;
    g_mouseEvent.eventFlags = mouseEvent.dwEventFlags;
}

//--------------------------------------------------------------
// Purpose  : Update function
//            This is the update function
//            double dt - This is the amount of time in seconds since the previous call was made
//
//            Game logic should be done here.
//            Such as collision checks, determining the position of your game characters, status updates, etc
//            If there are any calls to write to the console here, then you are doing it wrong.
//
//            If your game has multiple states, you should determine the current state, and call the relevant function here.
//
// Input    : dt = deltatime
// Output   : void
//--------------------------------------------------------------
void update(double dt)
{
    // get the delta time
    g_dElapsedTime += dt;
    g_dDeltaTime = dt;

    switch (g_eGameState)
    {
         case EGAMESTATES::S_SPLASHSCREEN : splashScreenWait(); // game logic for the splash screen
            break;
        case EGAMESTATES::S_GAME: updateGame(); // gameplay logic when we are in the game
            break;
        case EGAMESTATES::S_MAINMENU:rendermainmenu(g_Console);
            break;
    }
}

void splashScreenWait()    // waits for time to pass in splash screen
{
    if (g_dElapsedTime > 3.0) // wait for 3 seconds to switch to game mode, else do nothing
        g_eGameState = EGAMESTATES::S_GAME;
}

void updateGame()       // gameplay logic
{
    processUserInput(); // checks if you should change states or do something else with the game, e.g. pause, exit
    moveCharacter();    // moves the character, collision detection, physics, etc
    shoottrap();
    shootcharacter();
    renderbullet();
    Trenderbullet();
  //  moveEnemy();        // sound can be played here too.
    
}

void moveEnemy() {
    ((Mobs*)(enemyarray[0]))->checkmove(playerarray[0]->returnPos());
    enemyarray[0]->move(movementdir,playerarray[0]->returnPos(),map);
}

void moveCharacter() {
    // Updating the location of the character based on the key release
    // providing a beep sound whenver we shift the character

    if (g_skKeyEvent[int(EKEYS::K_UP)].keyDown)
    {
   
        movementdir.UP = true;
        playerarray[0]->move(movementdir, playerarray[0]->returnPos(), map);
        //Beep(1440, 30);
    }
    
    if (g_skKeyEvent[int(EKEYS::K_LEFT)].keyDown)
    {
        movementdir.LEFT = true;
        playerarray[0]->move(movementdir, playerarray[0]->returnPos(), map);

        //Beep(1440, 30);
    }
    
    if (g_skKeyEvent[int(EKEYS::K_DOWN)].keyDown) 
    {
        movementdir.DOWN = true;
        playerarray[0]->move(movementdir, playerarray[0]->returnPos(), map);
        //Beep(1440, 30);
    }
    
    if (g_skKeyEvent[int(EKEYS::K_RIGHT)].keyDown)
    {
        movementdir.RIGHT = true;
        playerarray[0]->move(movementdir, playerarray[0]->returnPos(), map);
        //Beep(1440, 30);
    }
}


void processUserInput()
{
    // quits the game if player hits the escape key
    if (g_skKeyEvent[int(EKEYS::K_ESCAPE)].keyReleased)
        g_bQuitGame = true;
}

//--------------------------------------------------------------
// Purpose  : Render function is to update the console screen
//            At this point, you should know exactly what to draw onto the screen.
//            Just draw it!
//            To get an idea of the values for colours, look at console.h and the URL listed there
// Input    : void
// Output   : void
//--------------------------------------------------------------
void render()
{
    clearScreen();      // clears the current screen and draw from scratch 
    switch (g_eGameState)
    {
    case EGAMESTATES::S_SPLASHSCREEN: renderSplashScreen();
        break;
    case EGAMESTATES::S_GAME: renderGame();
        break;
    case EGAMESTATES::S_MAINMENU: rendermainmenu(g_Console);
    }
    renderFramerate();      // renders debug information, frame rate, elapsed time, etc
    renderInputEvents();    // renders status of input events
    renderToScreen();       // dump the contents of the buffer to the screen, one frame worth of game
}

void clearScreen()
{
    // Clears the buffer with this colour attribute
    g_Console.clearBuffer(0x0F);
}

void renderToScreen()
{
    // Writes the buffer to the console, hence you will see what you have written
    g_Console.flushBufferToConsole();
}

void renderSplashScreen()  // renders the splash screen
{
    COORD c = g_Console.getConsoleSize();
    c.Y /= 3;
    c.X = c.X / 2 - 9;
    g_Console.writeToBuffer(c, "A game in 3 seconds", 0x03);
    c.Y += 1;
    c.X = g_Console.getConsoleSize().X / 2 - 20;
    g_Console.writeToBuffer(c, "Press <Space> to change character colour", 0x09);
    c.Y += 1;
    c.X = g_Console.getConsoleSize().X / 2 - 9;
    g_Console.writeToBuffer(c, "Press 'Esc' to quit", 0x09);
}

void renderGame()
{
    rendertrap(map, traparray);
    rendermap(g_Console,map,g_sChar,playerarray);        // renders the map to the buffer first
    renderenemy(map, enemyarray);
    rendercharacter(g_Console,map,g_sChar,playerarray);  // renders the character into the buffer
    renderinterface(g_Console);
}


void renderCharacter()
{
    // Draw the location of the character
    WORD charColor = 0x23;
    if (g_sChar.m_bActive)
    {
        charColor = 0x0A;
    }
    g_Console.writeToBuffer((playerarray[0]->returnPos().X-g_sChar.offset.X)*2,playerarray[0]->returnPos().Y-g_sChar.offset.Y,"  ", 0x0f);
}

void renderFramerate()
{
    //COORD c;
    //// displays the framerate
    std::ostringstream ss;
    //ss << std::fixed << std::setprecision(3);
    //ss << 1.0 / g_dDeltaTime << "fps";
    //c.X = g_Console.getConsoleSize().X - 9;
    //c.Y = 0;
    //g_Console.writeToBuffer(c, ss.str());

    //// displays the elapsed time
    //ss.str("");
    //ss << g_dElapsedTime << "secs";
    //c.X = 0;
    //c.Y = 0;
    //g_Console.writeToBuffer(c, ss.str(), 0x59);
    //ss.str("");
    //ss <<"player position" << ' ' << playerarray[0]->getX()<< ' ' << playerarray[0]->getY();
    //g_Console.writeToBuffer(130, 0, ss.str(), 0x59);

    //// display offset
    //ss.str("");
    //ss << "offsetX:" << ' ' << g_sChar.offset.X << ' ' << "offsetY:" << ' ' << g_sChar.offset.Y;
    //g_Console.writeToBuffer(130, 5, ss.str(), 0x0f);
    //// display monster location // experiment
    ss.str("");
    ss << "monsterX:" << ' ' <<  enemyarray[0]->returnPos().X << ' ' << " monsterY:" << ' ' << enemyarray[0]->returnPos().Y;
    g_Console.writeToBuffer(130, 5, ss.str(), 0x0f);
}

// this is an example of how you would use the input events
void renderInputEvents()
{
    // keyboard events
    COORD startPos = {130,10};
    std::ostringstream ss;
    std::string key;
    for (int i = 0; i < int(EKEYS::K_COUNT); ++i)
    {
        ss.str("");
        switch (i)
        {
        case int(EKEYS::K_UP): key = "UP";
            break;
        case int(EKEYS::K_DOWN): key = "DOWN";
            break;
        case int(EKEYS::K_LEFT): key = "LEFT";
            break;
        case int(EKEYS::K_RIGHT): key = "RIGHT";
            break;
        case int(EKEYS::K_SPACE): key = "SPACE";
            break;
        case int(EKEYS::A_DOWN): key = "ALEFT";
            break;
        case int(EKEYS::A_UP): key = "AUP";
            break;
        case int(EKEYS::A_LEFT): key = "ALEFT";
            break;
        case int(EKEYS::A_RIGHT): key = "ARIGHT";
            break;
        default: continue;
        }
        if (g_skKeyEvent[i].keyDown)
            ss << key << " pressed";
        else if (g_skKeyEvent[i].keyReleased)
            ss << key << " released";
        else
        ss << key << " not pressed";

        COORD c = { startPos.X, startPos.Y + i };
      //  g_Console.writeToBuffer(c, ss.str(), 0x17);
    }

    // mouse events    
    ss.str("");
    ss << "Mouse position (" << g_mouseEvent.mousePosition.X << ", " << g_mouseEvent.mousePosition.Y << ")";
    g_Console.writeToBuffer(g_mouseEvent.mousePosition, ss.str(), 0x59);
    ss.str("");
    switch (g_mouseEvent.eventFlags)
    {
    case 0:
        if (g_mouseEvent.buttonState == FROM_LEFT_1ST_BUTTON_PRESSED)
        {
            ss.str("Left Button Pressed");
            g_Console.writeToBuffer(g_mouseEvent.mousePosition.X, g_mouseEvent.mousePosition.Y + 1, ss.str(), 0x59);
        }
        else if (g_mouseEvent.buttonState == RIGHTMOST_BUTTON_PRESSED)
        {
            ss.str("Right Button Pressed");
            g_Console.writeToBuffer(g_mouseEvent.mousePosition.X, g_mouseEvent.mousePosition.Y + 2, ss.str(), 0x59);
        }
        else
        {
            ss.str("Some Button Pressed");
            g_Console.writeToBuffer(g_mouseEvent.mousePosition.X, g_mouseEvent.mousePosition.Y + 3, ss.str(), 0x59);
        }
        break;
    case DOUBLE_CLICK:
        ss.str("Double Clicked");
        g_Console.writeToBuffer(g_mouseEvent.mousePosition.X, g_mouseEvent.mousePosition.Y + 4, ss.str(), 0x59);
        break;
    case MOUSE_WHEELED:
        if (g_mouseEvent.buttonState & 0xFF000000)
            ss.str("Mouse wheeled down");
        else
            ss.str("Mouse wheeled up");
        g_Console.writeToBuffer(g_mouseEvent.mousePosition.X, g_mouseEvent.mousePosition.Y + 5, ss.str(), 0x59);
        break;
    default:
        break;
    }

}

void rectangle(int x, int y, int width, int height, char ch, WORD bordercolor, WORD buttoncolor, std::string str, bool fill)
{
    COORD C;
    std::ostringstream ss;
    ss.str("");
    ss << str;
    int length = ss.str().length();
    length = length / 2;
    SHORT X = x;
    SHORT Y = y;
    for (int i = 0; i < height; i++)
    {
        for (int o = 0; o < width; o++)
        {
            if (((i == 0) || (i == height - 1)) && (o != 0) && (o != width - 1))
            {
                g_Console.writeToBuffer(X, Y, 32, bordercolor);
            }
            else if ((o != 0) && (o != width - 1) && (0 != height - 1) && (fill != false)) // middle of the rectangle
            {
                g_Console.writeToBuffer(X, Y, 33, buttoncolor);
            }
            else if (o == 0) // left side of rectangle
            {
                g_Console.writeToBuffer(X, Y, 32, bordercolor);
                g_Console.writeToBuffer(X - 1, Y, 32, bordercolor);
            }
            else if (o == width - 1) // right side of the rectangle
            {
                g_Console.writeToBuffer(X, Y, 32, bordercolor);
                g_Console.writeToBuffer(X + 1, Y, 32, bordercolor);
            }
            X += 1;
        }
        X = x;
        Y += 1;
    }

    // blitting of the string onto the rectangle

    C.X = (x + (width / 2));
    C.Y = (y + (height / 2));
    C.X -= length;
    g_Console.setConsoleFont(30, 30, L"Arial");
    g_Console.writeToBuffer(C, ss.str(), 0x0f);
}

void shootcharacter(){
    if (g_skKeyEvent[int(EKEYS::A_UP)].keyDown)
        playerarray[0]->shoot(BULLETDIRECTION::B_UP);
    else if (g_skKeyEvent[int(EKEYS::A_DOWN)].keyDown)
        playerarray[0]->shoot(BULLETDIRECTION::B_DOWN);
    else if (g_skKeyEvent[int(EKEYS::A_LEFT)].keyDown)
        playerarray[0]->shoot(BULLETDIRECTION::B_LEFT);
    else if (g_skKeyEvent[int(EKEYS::A_RIGHT)].keyDown)
        playerarray[0]->shoot(BULLETDIRECTION::B_RIGHT);
}

void renderbullet() { // make it so that instead of it dropping after a certain let it drop offscreen.
    for (int i = 0; i < 100; i++) {
        if (bulletarray[i] != nullptr) {
            if (bulletarray[i]->getstatus() == true){
                map.editmap(bulletarray[i]->returnPos().X, bulletarray[i]->returnPos().Y, ' ');
                delete bulletarray[i];
                bulletarray[i] = nullptr;
            }
            else {
                bulletarray[i]->movebullet(map);
                map.editmap(bulletarray[i]->returnPos().X, bulletarray[i]->returnPos().Y, 'B');
            }
        }
        else
            continue;
    }
}
// make a var that stores the previouschar so can restore later;

void shoottrap() {
    if (g_skKeyEvent[A_UP].keyDown) {

        traparray[100]->shoot(BULLETDIRECTION::B_UP); // first part of map
        //traparray[103]->shoot(BULLETDIRECTION::B_UP);
        //traparray[104]->shoot(BULLETDIRECTION::B_UP);

        //traparray[105]->shoot(BULLETDIRECTION::B_UP); // second part of map
        //traparray[106]->shoot(BULLETDIRECTION::B_UP);
        //traparray[107]->shoot(BULLETDIRECTION::B_UP);
        //traparray[108]->shoot(BULLETDIRECTION::B_UP);
        //traparray[109]->shoot(BULLETDIRECTION::B_UP);
        //traparray[110]->shoot(BULLETDIRECTION::B_UP);
        //traparray[111]->shoot(BULLETDIRECTION::B_UP);
        //traparray[112]->shoot(BULLETDIRECTION::B_UP);
        //traparray[113]->shoot(BULLETDIRECTION::B_UP);
        //traparray[114]->shoot(BULLETDIRECTION::B_UP);
        //traparray[115]->shoot(BULLETDIRECTION::B_UP);
        //traparray[116]->shoot(BULLETDIRECTION::B_UP);
        //traparray[117]->shoot(BULLETDIRECTION::B_UP);
        //traparray[118]->shoot(BULLETDIRECTION::B_UP);
        //traparray[119]->shoot(BULLETDIRECTION::B_UP);
        //traparray[120]->shoot(BULLETDIRECTION::B_UP);
        //traparray[121]->shoot(BULLETDIRECTION::B_UP);
        //traparray[122]->shoot(BULLETDIRECTION::B_UP);
    }
    else if (g_skKeyEvent[A_DOWN].keyDown) {

        traparray[150]->shoot(BULLETDIRECTION::B_DOWN); // first part of map
        //traparray[151]->shoot(BULLETDIRECTION::B_DOWN);
        //traparray[152]->shoot(BULLETDIRECTION::B_DOWN);
        //traparray[153]->shoot(BULLETDIRECTION::B_DOWN);
        //traparray[154]->shoot(BULLETDIRECTION::B_DOWN);
        //traparray[155]->shoot(BULLETDIRECTION::B_DOWN);
        //traparray[156]->shoot(BULLETDIRECTION::B_DOWN);
        //traparray[157]->shoot(BULLETDIRECTION::B_DOWN);
        //traparray[158]->shoot(BULLETDIRECTION::B_DOWN);
        //traparray[159]->shoot(BULLETDIRECTION::B_DOWN);

        //traparray[160]->shoot(BULLETDIRECTION::B_DOWN); // second part of map
        //traparray[161]->shoot(BULLETDIRECTION::B_DOWN);
        //traparray[162]->shoot(BULLETDIRECTION::B_DOWN);
        //traparray[163]->shoot(BULLETDIRECTION::B_DOWN);
        //traparray[164]->shoot(BULLETDIRECTION::B_DOWN);
        //traparray[165]->shoot(BULLETDIRECTION::B_DOWN);
        //traparray[166]->shoot(BULLETDIRECTION::B_DOWN);
        //traparray[167]->shoot(BULLETDIRECTION::B_DOWN);
        //traparray[168]->shoot(BULLETDIRECTION::B_DOWN);
        //traparray[169]->shoot(BULLETDIRECTION::B_DOWN);
        //traparray[170]->shoot(BULLETDIRECTION::B_DOWN);
        //traparray[171]->shoot(BULLETDIRECTION::B_DOWN);
        //traparray[172]->shoot(BULLETDIRECTION::B_DOWN);
        //traparray[173]->shoot(BULLETDIRECTION::B_DOWN);
    }
    else if (g_skKeyEvent[A_LEFT].keyDown) {

        traparray[50]->shoot(BULLETDIRECTION::B_LEFT); // first part of map
        //traparray[51]->shoot(BULLETDIRECTION::B_LEFT);
        //traparray[52]->shoot(BULLETDIRECTION::B_LEFT);
        //traparray[53]->shoot(BULLETDIRECTION::B_LEFT);
        //traparray[54]->shoot(BULLETDIRECTION::B_LEFT);
        //traparray[55]->shoot(BULLETDIRECTION::B_LEFT);
        //traparray[56]->shoot(BULLETDIRECTION::B_LEFT);
        //traparray[57]->shoot(BULLETDIRECTION::B_LEFT);

        //traparray[58]->shoot(BULLETDIRECTION::B_LEFT); // second part of map
        //traparray[59]->shoot(BULLETDIRECTION::B_LEFT);
        //traparray[60]->shoot(BULLETDIRECTION::B_LEFT);
        //traparray[61]->shoot(BULLETDIRECTION::B_LEFT);
        //traparray[62]->shoot(BULLETDIRECTION::B_LEFT);
        //traparray[63]->shoot(BULLETDIRECTION::B_LEFT);
        //traparray[64]->shoot(BULLETDIRECTION::B_LEFT);
    }
    else if (g_skKeyEvent[A_RIGHT].keyDown) {

        traparray[0]->shoot(BULLETDIRECTION::B_RIGHT); // first part of the map
        //traparray[1]->shoot(BULLETDIRECTION::B_RIGHT);
        //traparray[2]->shoot(BULLETDIRECTION::B_RIGHT);
        //traparray[3]->shoot(BULLETDIRECTION::B_RIGHT);
        //traparray[4]->shoot(BULLETDIRECTION::B_RIGHT);
        //traparray[5]->shoot(BULLETDIRECTION::B_RIGHT);
        //traparray[6]->shoot(BULLETDIRECTION::B_RIGHT);
        //traparray[7]->shoot(BULLETDIRECTION::B_RIGHT);
        //traparray[8]->shoot(BULLETDIRECTION::B_RIGHT);

        //traparray[9]->shoot(BULLETDIRECTION::B_RIGHT); // second part of map
        //traparray[10]->shoot(BULLETDIRECTION::B_RIGHT);
        //traparray[11]->shoot(BULLETDIRECTION::B_RIGHT);
        //traparray[12]->shoot(BULLETDIRECTION::B_RIGHT);
        //traparray[13]->shoot(BULLETDIRECTION::B_RIGHT);
        //traparray[14]->shoot(BULLETDIRECTION::B_RIGHT);
        //traparray[15]->shoot(BULLETDIRECTION::B_RIGHT);
        //traparray[16]->shoot(BULLETDIRECTION::B_RIGHT);
    }
}

void Trenderbullet() { // make it so that instead of it dropping after a certain let it drop offscreen.
    for (int i = 0; i < 20; i++) {
        if (bulletarray1[i] != nullptr) {
            if (bulletarray1[i]->getstatus() == true) {
                map.editmap(bulletarray1[i]->getx(), bulletarray1[i]->gety(), ' ');
                delete bulletarray1[i];
                bulletarray1[i] = nullptr;
            }
            else {
                bulletarray1[i]->movebullet(map);
                map.editmap(bulletarray1[i]->getx(), bulletarray1[i]->gety(), 'R');
            }
        }
        else
            continue;
    }
}