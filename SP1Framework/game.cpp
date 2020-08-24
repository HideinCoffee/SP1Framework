// This is the main file for the game logic and function
//
//blah blah blooop blahh
#include "game.h"
#include "Framework\console.h"
#include "Mobs.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include "Map.h"
#include "Entity.h"

double  g_dElapsedTime;
double  g_dDeltaTime;
SKeyEvent g_skKeyEvent[K_COUNT];
SMouseEvent g_mouseEvent;

// Game specific variables here
SGameChar   g_sChar;
SGameChar   trigger;
EGAMESTATES g_eGameState = S_SPLASHSCREEN; // initial state
MOVEMENTDIRECTION movementdir;
BULLETDIRECTION bulletdir;
// Console object
Console g_Console(160, 40, "SP1 Framework");

// map object
Map map;

// player object
//Player player(2, 151); //Original spawn is 2, 151



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
    g_eGameState = S_SPLASHSCREEN;

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
    entityarray[0] = new Player(2,151);
    entityarray[1] = new Mobs(4,151);
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
    case S_SPLASHSCREEN: // don't handle anything for the splash screen
        break;
    case S_GAME: gameplayKBHandler(keyboardEvent); // handle gameplay keyboard event 
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
    case S_SPLASHSCREEN: // don't handle anything for the splash screen
        break;
    case S_GAME: gameplayMouseHandler(mouseEvent); // handle gameplay mouse event
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
    EKEYS key = K_COUNT;
    switch (keyboardEvent.wVirtualKeyCode)
    {
    case 0x57: key = K_UP; break;
    case 0x53: key = K_DOWN; break;
    case 0x41: key = K_LEFT; break;
    case 0x44: key = K_RIGHT; break;
    case VK_UP: key = A_UP; break;
    case VK_DOWN: key = A_DOWN; break;
    case VK_LEFT: key = A_LEFT; break; 
    case VK_RIGHT: key = A_RIGHT; break; 
    case VK_SPACE: key = K_SPACE; break;
    case VK_ESCAPE: key = K_ESCAPE; break; 
    }
    // a key pressed event would be one with bKeyDown == true
    // a key released event would be one with bKeyDown == false
    // if no key is pressed, no event would be fired.
    // so we are tracking if a key is either pressed, or released
    if (key != K_COUNT)
    {
        g_skKeyEvent[key].keyDown = keyboardEvent.bKeyDown;
        g_skKeyEvent[key].keyReleased = !keyboardEvent.bKeyDown;
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
        case S_SPLASHSCREEN : splashScreenWait(); // game logic for the splash screen
            break;
        case S_GAME: updateGame(); // gameplay logic when we are in the game
            break;
    }
}


void splashScreenWait()    // waits for time to pass in splash screen
{
    if (g_dElapsedTime > 3.0) // wait for 3 seconds to switch to game mode, else do nothing
        g_eGameState = S_GAME;
}

void updateGame()       // gameplay logic
{
    processUserInput(); // checks if you should change states or do something else with the game, e.g. pause, exit
    moveCharacter();    // moves the character, collision detection, physics, etc
    shootcharacter();
    renderbullet();
    moveEnemy();        // sound can be played here too.
    
}
void moveEnemy() {
    ((Mobs*)(entityarray[1]))->checkmove(entityarray[0]->returnPos());
    entityarray[1]->move(movementdir,entityarray[0]->returnPos(),map);
}
void moveCharacter() {
    // Updating the location of the character based on the key release
    // providing a beep sound whenver we shift the character

    if ((g_skKeyEvent[K_UP].keyDown) && (map.isoccupied(entityarray[0]->getX(), entityarray[0]->getY() - 1) == false))
    {
        entityarray[0]->setpos(map.movecamera(1,entityarray[0]->returnPos()));
        //Beep(1440, 30);
    }
    
    if ((g_skKeyEvent[K_LEFT].keyDown) && (map.isoccupied(entityarray[0]->getX() - 1, entityarray[0]->getY()) == false))
    {
       entityarray[0]->setpos(map.movecamera(3,entityarray[0]->returnPos()));
        //Beep(1440, 30);
    }
    
    if ((g_skKeyEvent[K_DOWN].keyDown) && (map.isoccupied(entityarray[0]->getX(), entityarray[0]->getY() + 1) == false))
    {
        entityarray[0]->setpos(map.movecamera(2,entityarray[0]->returnPos()));
        //Beep(1440, 30);
    }
    
    if ((g_skKeyEvent[K_RIGHT].keyDown) && (map.isoccupied(entityarray[0]->getX() + 1, entityarray[0]->getY()) == false))
    {
        entityarray[0]->setpos(map.movecamera(4,entityarray[0]->returnPos()));
        //Beep(1440, 30);
    }
}


void processUserInput()
{
    // quits the game if player hits the escape key
    if (g_skKeyEvent[K_ESCAPE].keyReleased)
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
    case S_SPLASHSCREEN: renderSplashScreen();
        break;
    case S_GAME: renderGame();
        break;
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
    renderMap();        // renders the map to the buffer first
    renderEnemies();
    renderCharacter();  // renders the character into the buffer
}

void renderMap() {
    if (map.checkread() == false) {
        if (map.slotmap("map.txt", g_Console) == true) {
            map.changeread(true);
        }
    }

    if ((entityarray[0]->getX() > 80) && (entityarray[0]->getX() < 200 - 80)) { // offset x
        g_sChar.offset.X = entityarray[0]->getX() - 80;
    }

    if ((entityarray[0]->getY() > 20) && (entityarray[0]->getY() < 200 - 20)) { // offset y
        g_sChar.offset.Y = entityarray[0]->getY() - 20;
    }

    for (int row = 0; row < 40; row++) {
        for (int col = 0; col < 160; col++) {
            if (map.maparray[row + g_sChar.offset.Y][col + (g_sChar.offset.X)] == '#') {
                g_Console.writeToBuffer(col, row, "  ", 0x00);
            }
            else if (map.maparray[row + g_sChar.offset.Y][col + g_sChar.offset.X] == '$') {
                g_Console.writeToBuffer(col, row, "  ", 0x66); //Colour of "coin" pixels
            }
            else if (map.maparray[row + g_sChar.offset.Y][col + (g_sChar.offset.X)] == '!') {
                g_Console.writeToBuffer(col, row, "  ", 0x22); //NPC colours? There's only 2 of the green pixels, they're next to the exit of the maze
            }
            else if (map.maparray[row + g_sChar.offset.Y][col + (g_sChar.offset.X)] == 'x') {
                g_Console.writeToBuffer(col, row, "  ", 0x44); //enemy
            }
            else if (map.maparray[row + g_sChar.offset.Y][col + (g_sChar.offset.X)] == 'm') {
                g_Console.writeToBuffer(col, row, "  ", 0x44);
            }
            else if (map.maparray[row + g_sChar.offset.Y][col + (g_sChar.offset.X)] == 'B') {
                g_Console.writeToBuffer(col, row, "  ", 0x66);
            }
            else{
                g_Console.writeToBuffer(col,row,"  ", 0xff); 
            }
        }
    }
}


void renderCharacter()
{
    // Draw the location of the character
    WORD charColor = 0x0C;
    if (g_sChar.m_bActive)
    {
        charColor = 0x0A;
    }
    g_Console.writeToBuffer(entityarray[0]->getX()-g_sChar.offset.X,entityarray[0]->getY()-g_sChar.offset.Y,char(1), charColor);    
}

void renderFramerate()
{
    COORD c;
    // displays the framerate
    std::ostringstream ss;
    ss << std::fixed << std::setprecision(3);
    ss << 1.0 / g_dDeltaTime << "fps";
    c.X = g_Console.getConsoleSize().X - 9;
    c.Y = 0;
    g_Console.writeToBuffer(c, ss.str());

    // displays the elapsed time
    ss.str("");
    ss << g_dElapsedTime << "secs";
    c.X = 0;
    c.Y = 0;
    g_Console.writeToBuffer(c, ss.str(), 0x59);
    ss.str("");
    ss <<"player position" << ' ' << entityarray[0]->getX()<< ' ' << entityarray[0]->getY();
    g_Console.writeToBuffer(120, 0, ss.str(), 0x59);
}

// this is an example of how you would use the input events
void renderInputEvents()
{
    // keyboard events
    COORD startPos = {130, 30};
    std::ostringstream ss;
    std::string key;
    for (int i = 0; i < K_COUNT; ++i)
    {
        ss.str("");
        switch (i)
        {
        case K_UP: key = "UP";
            break;
        case K_DOWN: key = "DOWN";
            break;
        case K_LEFT: key = "LEFT";
            break;
        case K_RIGHT: key = "RIGHT";
            break;
        case K_SPACE: key = "SPACE";
            break;
        case A_DOWN: key = "ALEFT";
            break;
        case A_UP: key = "AUP";
            break;
        case A_LEFT: key = "ALEFT";
            break;
        case A_RIGHT: key = "ARIGHT";
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
        g_Console.writeToBuffer(c, ss.str(), 0x17);
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
void renderEnemies()
{
    //int Time = g_dElapsedTime;
    map.editmap(entityarray[1]->getX(),entityarray[1]->getY(),'m');
}


void shootcharacter(){
    if (g_skKeyEvent[A_UP].keyDown)
        entityarray[0]->shoot(BULLETDIRECTION::B_UP);
    if (g_skKeyEvent[A_DOWN].keyDown)
        entityarray[0]->shoot(BULLETDIRECTION::B_DOWN);
    if (g_skKeyEvent[A_LEFT].keyDown)
        entityarray[0]->shoot(BULLETDIRECTION::B_LEFT);
    if (g_skKeyEvent[A_RIGHT].keyDown)
        entityarray[0]->shoot(BULLETDIRECTION::B_RIGHT);
}

void renderbullet() {
    for (int i = 0; i < 20; i++) {
        if (bulletarray[i] != nullptr) {
            if (bulletarray[i]->getstatus() == true){
                map.editmap(bulletarray[i]->getx(), bulletarray[i]->gety(), '@');
                delete bulletarray[i];
                bulletarray[i] = nullptr;
            }
            else {
                bulletarray[i]->movebullet(map);
                map.editmap(bulletarray[i]->getx(), bulletarray[i]->gety(), 'B');
            }
        }
        else
            continue;
    }
}
// make a var that stores the previouschar so can restore later;