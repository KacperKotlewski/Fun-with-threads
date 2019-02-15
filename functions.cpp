#include <iostream>
#include <string>

#include "functions.h"
//#include "baseSettings.h"

using namespace std;



void drawWindow(short positionX, short positionY, short sizeX, short sizeY, short colorIn, short colorOut, bool windowType, string title)
{
    sizeY--; sizeX--;
    consColor(colorIn);

    for(int i=1; i<=sizeY-1; i++)
    {
        for(int j=1; j<=sizeX-1; j++)
        {
            SCP(positionX+j,positionY+i);
            cout<<" ";
        }
    }


    for(int i=1; i<=sizeX-1; i++)
    {
        SCP(i+positionX,positionY+sizeY);
            if(windowType==1) cout<<(char)196; else cout<<(char)205;

        SCP(i+positionX,positionY);
            if(windowType==1) cout<<(char)196; else cout<<(char)205;
    }
    for(int i=1; i<=sizeY-1; i++)
    {
        SCP(positionX,i+positionY);
            if(windowType==1) cout<<(char)179; else cout<<(char)186;

        SCP(positionX+sizeX,i+positionY);
            if(windowType==1) cout<<(char)179; else cout<<(char)186;
    }


    SCP(positionX,      positionY);         if(windowType==1) cout<<(char)218; else cout<<(char)201;
    SCP(positionX+sizeX,positionY);         if(windowType==1) cout<<(char)191; else cout<<(char)187;
    SCP(positionX,      positionY+sizeY);   if(windowType==1) cout<<(char)192; else cout<<(char)200;
    SCP(positionX+sizeX,positionY+sizeY);   if(windowType==1) cout<<(char)217; else cout<<(char)188;

    if(title!="") { int position=(sizeX-title.length())/2; SCP(positionX+position,positionY);   cout<<"["<<title<<"]"; }

    consColor(colorOut);
    //int swW=windowWidth-1,swH=windowHight-1;

    try
    {
        SCP(90,20);
    }
    catch (const exception& e)
    {
        SCP(1,1);
        cout<<"error: "<<e.what()<<endl;
    }
}


void STP(short Xpos, short Ypos, short colorIn, short colorOut, string text) //Special Text Printer
{
    SCP(Xpos,Ypos);
    consColor(colorIn);
    cout<<text;
    consColor(colorOut);
}
