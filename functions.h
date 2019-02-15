#include <iostream>

///base functions
void SCP(int position_X, int position_Y);
void CLS(int startPosition_X, int startPosition_Y, int length_X, int length_Y);
void consColor(int color);
int getKey();
///void windowSize(int windowWidth, int windowHight);




///other functions
void drawWindow(short positionX, short positionY, short sizeX, short sizeY, short colorIn, short colorOut, bool windowType, std::string title);
void STP(short Xpos, short Ypos, short colorIn, short colorOut, std::string text);
