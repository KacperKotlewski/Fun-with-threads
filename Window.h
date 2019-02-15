#include <iostream>

using namespace std;

class Window
{

///varible
private:
    short   WposX, WposY, WsizX, WsizY;
    short   NposX, NposY, NsizX, NsizY;
    bool    Wview=false;
    string  Wtitle, Winside;
public:



///methods
private:
    ///window
    void Clean();
    void Frame();
    void Fill();
    void Title();
    void Change();

    ///selsctors
    bool CFP(short position_X, short position_Y);
    bool CWP(short position_X, short position_Y);
    void iCFP(int position_X, int position_Y, char symbol);
    void iCWP(int position_X, int position_Y, char symbol);

    void ChangeColor(short bg_color);


public:
    Window(short positionX=0, short positionY=0, short sizeX=10, short sizeY=5, string title="");
    ///official
    void view();
    void changePosition(short positionX, short positionY);
    void changeSize(short sizeX, short sizeY);
};

void WindowSize(short window_width, short window_height);
