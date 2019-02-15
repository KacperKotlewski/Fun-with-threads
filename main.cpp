#include <windows.h>
#include <iostream>
#include <thread>
#include <string>

#include "functions.h"
#include "baseSettings.h"
#include "Window.h"

///setlocale(LC_ALL,"Polish");


using namespace std;

bool window=true;
long long int soundLevel=0;
int input=0, lInp=-1;
string prompt="";
bool promptChange=true, eventChange=true, inpEvCh=true, btest=true;

void main2(), drawThread(), inputThread(), frequencyThread(),soundThread() , specialDraw(), boolChange(bool input);



int main() {
    WindowSize(windowWidth, windowHeight);


    main2();

    ///getKey();

	return 0;
}

void main2()
{
    // Constructs the new thread and runs it. Does not block execution.
    thread t1(drawThread);
    thread t2(inputThread);
    thread t3(frequencyThread);
    thread t4(soundThread);

    // Makes the main thread wait for the new thread to finish execution, therefore blocks its own execution.
    t1.join();
    t2.join();
    t3.join();
    t4.join();
}


// The function we want to execute on the new thread.
void drawThread()
{
    Window test(2,2,20,5,""); 
    Window test1(3,3,20,5,"");
    Window test2(4,4,20,5,"");
    Window test3(5,5,20,5,"");

    while(runApp==true)
    {
        if(window==true)
        {
            drawWindow(0,0,60,20,15,15,0,"");
            drawWindow(60,0,30,20,15,15,1,"dev info");
            SCP(0,17);cout<<(char)199;
            SCP(59,17);cout<<(char)182;
            for(int i=1; i<59;i++) {SCP(i,17); cout<<(char)196;}

            window=false;
            boolChange(true);
            ///pauseT1=false;
        }

        if(btest==true)
        {
            test.view();
            test.changePosition(20,4);
            /*
            test1.view();
            test1.changePosition(21,5);
            test2.view();
            test2.changePosition(22,6);
            test3.view();
            test3.changePosition(23,7);
            */
            btest=false;
        }


        specialDraw();

        if(eventChange==true)
        {
            SCP(61,1);
            cout<<"sound Hz: "<<soundLevel;
            if(inpEvCh==true)
            {
                SCP(61,2);
                cout<<"last input: "<<lInp<<" ";
                SCP(61,3);
                cout<<"action input: "<<input<<" ";
                inpEvCh=false;
            }
        }
        if(promptChange==true)
        {
            SCP(1,18);
            cout<<"> "<<prompt<<" ";
            promptChange=false;
        }


        SCP(windowWidth-1, windowHeight-1);
    }
}

void inputThread()
{
    while(runApp==true)
    {
        lInp=getKey();
        int inp=lInp;
        eventChange=true; inpEvCh=true;
        if(inp=='p')
        {
            btest=true;
        }
        if(inp==27)
        {
            input=1;
            inp=getKey();
            if((inp=='y')||(inp=='Y')) runApp=false;
            else  window=true;
        }
        if(inp>=32&&inp<=127)
        {
            prompt+=(char)inp;
            promptChange=true;
        }
        if((inp==8)&&(prompt!=""))
        {
            string buff="";

            for(int i = 0;i<prompt.length()-1;i++)
            {
                buff+=prompt.at(i);
            }
            prompt=buff;
            promptChange=true;
        }
    }
}

void frequencyThread()
{
    while(runApp==true)
    {
        soundLevel++;
        Sleep(100);
        eventChange=true;
    }
}

void soundThread()
{
    while(runApp==true)
    {
        Beep(soundLevel,1000);
    }
}

void specialDraw()
{
    switch(input)
    {
    case 1:
        drawWindow(33,8,24,4,192,15,0,"EXIT STATUS");
        STP(35,9,192,15,"do you want to exit?");
        STP(35,10,192,15,"push Y -yes or N -no");
        break;
    }
    input=0;
}

void boolChange(bool input)
{
    promptChange=input; eventChange=input; inpEvCh=input;
}
