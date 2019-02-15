#include <iostream>
#include <windows.h>

#include "Window.h"

using namespace std;

int Wwidth=0, Wheight=0;

///constructors
Window::Window(short positionX, short positionY, short sizeX, short sizeY, string title)
:WposX(positionX), WposY(positionY), WsizX(sizeX), WsizY(sizeY), Wtitle(title)
{
    NposX=WposX;
    NposY=WposY;
    NsizX=WsizX;
    NsizY=WsizY;
}

///public

void Window::view()
{
    if(Wview==true)
    {
        Clean();
        Change();
    }
    CFP(0,0);
    cout<<WposX<<" "<<WposY<<" "<<WsizX<<" "<<WsizX;
    Frame();
    Fill();
    Title();
    Wview=false;
}
void Window::changePosition(short positionX, short positionY)
{
    NposX=positionX;
    NposY=positionY;
    Wview=true;
}
void Window::changeSize(short sizeX, short sizeY)
{
    NsizX=sizeX;
    NsizY=sizeY;
    Wview=true;
}



///private
    ///window build
void Window::Clean()  ///clean window
{
    for(int i=0; i<WsizX; i++)
    {
        for(int j=0; j<WsizY; j++)
        {
            iCFP(i+WposX,j+WposY, ' ');
        }
    }
    CFP(0,0);
}
void Window::Frame()  ///print frame of window
{
    for(int i=1; i<=WsizX-2; i++)
    {
        iCFP(i+WposX,WposY+WsizY-1, 196);
        iCFP(i+WposX,WposY, 196);
    }
    for(int i=1; i<=WsizY-2; i++)
    {
        iCFP(WposX,i+WposY, 179);
        iCFP(WposX+WsizX-1,i+WposY, 179);
    }

    iCFP(WposX,          WposY,         218);
    iCFP(WposX+WsizX-1,  WposY,         191);
    iCFP(WposX,          WposY+WsizY-1, 192);
    iCFP(WposX+WsizX-1,  WposY+WsizY-1, 217);


    CWP(0,0);
}
void Window::Fill()   ///fill window
{
    {
    for(int i=1; i<WsizX-1; i++)
    {
        for(int j=1; j<WsizY-1; j++)
        {
            iCFP(i+WposX,j+WposY, ' ');
        }
    }
    CFP(0,0);
}
}
void Window::Title()  ///draw title
{
    if(Wtitle!="")
    {
        CFP(0,0);
        int pos=(WsizX-2-Wtitle.length())/2;
        //if(pos%2==1) pos--;

        ///cout<<"["<<Wtitle<<"] "<<pos<<" "<<2+Wtitle.length()<<" "<<WsizX-(2+Wtitle.length()+pos)<<" "<<WsizX;

        iCFP(WposX+pos,WposY,'['); pos++;
        for(int i=0; i<Wtitle.length(); i++)
        {
            iCFP(WposX+pos,WposY,Wtitle.at(i));
            ///cout<<"["<<Wtitl<<"]";
            pos++;
        }
        iCFP(WposX+pos,WposY,']');
    }
}
void Window::Change() ///change window settings
{
    WposX=NposX;
    WposY=NposY;
    WsizX=NsizX;
    WsizY=NsizY;
}



    ///Sellectors
bool Window::CFP(short position_X, short position_Y) ///check frame position
{
    if(!((position_Y>=Wheight)||(position_Y<0)) && !((position_X>=Wwidth)||(position_X<0)))
    {
        HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD pos = { position_X, position_Y };
        SetConsoleCursorPosition(output, pos);
        return true;
    }
    else return false;
}
bool Window::CWP(short position_X, short position_Y) ///check in window position
{
    if(!((position_Y>=WposY+WsizY)&&(position_Y<WposY-1)) && !((position_X>=WposX+WsizX)&&(position_X<WposX-1)))
    {
        ///SCP(0,0); cout<<position_Y<<" : "<<position_X; system("pause>nul");
        if(!((position_Y>=Wheight)&&(position_Y<0)) && !((position_X>=Wwidth)&&(position_X<0)))
        {
            HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
            COORD pos = { position_X+WposX, position_Y+WposX };
            SetConsoleCursorPosition(output, pos);
            return true;
        }
        else return false;
    }
    else return false;
}
void Window::iCFP(int position_X, int position_Y, char symbol) ///CFP with draw char
{
    if(CFP(position_X,position_Y)==true) cout<<symbol;
}
void Window::iCWP(int position_X, int position_Y, char symbol) ///CWP with draw char
{
    if(CWP(position_X,position_Y)==true) cout<<symbol;
}








///dedicate

void WindowSize(short windowWidth, short windowHeight)
{
    windowWidth=windowWidth%10000;
    windowHeight=windowHeight%10000;
    Wwidth=windowWidth;
    Wheight=windowHeight;
    short wW[]= { (((windowWidth%10000)/1000)+48), (((windowWidth%1000)/100)+48), (((windowWidth%100)/10)+48), ((windowWidth%10)+48) };
    short wH[]= { (((windowHeight%10000)/1000)+48), (((windowHeight%1000)/100)+48), (((windowHeight%100)/10)+48), ((windowHeight%10)+48) };

    char wmode[]={'m','o','d','e',' ',(char)wW[0],(char)wW[1],(char)wW[2],(char)wW[3],',',' ',(char)wH[0],(char)wH[1],(char)wH[2],(char)wH[3]};

    bool tf=true, tf2=false;
    short x1=0, x2=0, x3=0;
    for(short i=5;i<15;i++)
    {
        if((tf==true)&&(wmode[i]=='0')) wmode[i]=' ';
        else { tf=false;  if(wmode[i]>=48 && wmode[i]<=58) {if(tf2==false) x1++; else x2++;} }
        if((tf==false)&&(wmode[i]==' ')) { tf=true; tf2=true; }
    }
    x2+=x1;
    x3=15-x2;
    char Wmode[x3];

    for(short i=0;i<x3;i++)
    {
        if(i>=5)
        {
            if(i>=11-x1) Wmode[i] = wmode[i+x2];
            else  Wmode[i] = wmode[i+x1];
        }
        else Wmode[i] = wmode[i];
    }

    /// scp(1,1); cout<<x1<<"/"<<x2<<"/"<<x3<<" ("<<windowWidth<<"/"<<windowHeight<<"): "; for(short i=0;i<x3;i++) cout<<Wmode[i]; cout<<" / "; for(short i=0;i<15;i++) cout<<wmode[i]; system("pause>nul");

    try
    {
        system(Wmode);
    }
    catch (const exception& e)
    {
        ///scp(1,1);
        cout<<"error: "<<e.what()<<endl;
        cout<<x1<<"/"<<x2<<"/"<<x3<<": ";
        for(short i=0;i<x3;i++) cout<<Wmode[i];
        system("pause>nul");
    }
}
