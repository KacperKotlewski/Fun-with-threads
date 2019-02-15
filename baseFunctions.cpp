#include <windows.h>
#include <iostream>
#include <conio.h>

#include "functions.h"
///#include "baseSettings.h"

using namespace std;


int getKey()
{
    bool fs=false;
	int x;
	for(;;)
	{
		x = getch();
		switch (x) {
		case 0:
		case 224:
			fs=true;
		break;
		default:
			if (fs==true) {
				x=300+x;
				return x;
			} else { return x; }
			fs=false;
		}
	}
}

void SCP(int position_X, int position_Y)
{
	//z pomoca mojego kumpla Adama Brzezowskiego
HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
COORD pos = { position_X, position_Y };
SetConsoleCursorPosition(output, pos);
}

void CLS(int startPosition_X, int startPosition_Y, int length_X, int length_Y)
{
    for(int y=0; y<length_Y; y++)
    {
        for(int x=0; x<length_X; x++)
        {
            SCP(startPosition_X+x, startPosition_Y+y);
            std::cout<<" ";
        }
    }
    SCP(startPosition_X, startPosition_Y);
}

void consColor(int color)
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console, color);
}









void windowSize(int windowWidth, int windowHight)
{
    int wW[]= { (((windowWidth%100000)/10000)+48), (((windowWidth%10000)/1000)+48), (((windowWidth%1000)/100)+48), (((windowWidth%100)/10)+48), ((windowWidth%10)+48) };
    int wH[]= { (((windowHight%100000)/10000)+48), (((windowHight%10000)/1000)+48), (((windowHight%1000)/100)+48), (((windowHight%100)/10)+48), ((windowHight%10)+48) };

    char wmode[]={'m','o','d','e',' ',(char)wW[0],(char)wW[1],(char)wW[2],(char)wW[3],(char)wW[4],',',' ',(char)wH[0],(char)wH[1],(char)wH[2],(char)wH[3],(char)wH[4]};

    bool tf=true, tf2=false;
    int x1=0, x2=0, x3=0;
    for(int i=5;i<17;i++)
    {
        if((tf==true)&&(wmode[i]=='0')) wmode[i]=' ';
        else { tf=false;  if(wmode[i]>=48 && wmode[i]<=58) {if(tf2==false) x1++; else x2++;} }
        if((tf==false)&&(wmode[i]==' ')) { tf=true; tf2=true; }
    }
    x2+=x1;
    x3=17-x2;
    char Wmode[x3];

    for(int i=0;i<x3;i++)
    {
        if(i>=5)
        {
            if(i>=12-x1) Wmode[i] = wmode[i+x2];
            else  Wmode[i] = wmode[i+x1];
        }
        else Wmode[i] = wmode[i];
    }


    try
    {
        system(Wmode);
    }
    catch (const exception& e)
    {
        SCP(1,1);
        cout<<"error: "<<e.what()<<endl;
        cout<<x1<<"/"<<x2<<"/"<<x3<<": ";
        for(int i=0;i<x3;i++) cout<<Wmode[i];
        system("pause>nul");
    }
}
