/*
    Original Author: S. M. Shahriar Nirjon
    Last Modified by: Mohammad Saifur Rahman
    last modified: October 13, 2015
    Version: 2.0
*/
#include <iostream>
#include<string>
#pragma warning (disable : 4996)
#include<stdio.h>
#include <stdlib.h>
#include "iGraphics.h"
using namespace std;

double bg1[60]; // this array stores the co-ordinates of Level 1 Background images ( only on X AXIS )

char img[60][100] = { "screen//1.bmp", "screen//2.bmp", "screen//3.bmp", "screen//4.bmp", "screen//5.bmp", "screen//6.bmp", "screen//7.bmp", "screen//8.bmp", "screen//9.bmp", "screen//10.bmp", "screen//11.bmp", "screen//12.bmp", "screen//13.bmp", "screen//14.bmp", "screen//15.bmp", "screen//16.bmp", "screen//17.bmp", "screen//18.bmp", "screen//19.bmp", "screen//20.bmp", "screen//21.bmp", "screen//22.bmp", "screen//23.bmp", "screen//24.bmp", "screen//25.bmp", "screen//26.bmp", "screen//27.bmp", "screen//28.bmp", "screen//29.bmp", "screen//30.bmp",
"screen//31.bmp", "screen//32.bmp", "screen//33.bmp", "screen//34.bmp", "screen//35.bmp", "screen//36.bmp", "screen//37.bmp", "screen//38.bmp", "screen//39.bmp", "screen//40.bmp", "screen//41.bmp", "screen//42.bmp", "screen//43.bmp", "screen//44.bmp", "screen//45.bmp", "screen//46.bmp", "screen//47.bmp", "screen//48.bmp", "screen//49.bmp", "screen//50.bmp", "screen//51.bmp", "screen//52.bmp", "screen//53.bmp", "screen//54.bmp", "screen//55.bmp", "screen//56.bmp", "screen//57.bmp", "screen//58.bmp", "screen//59.bmp", "screen//60.bmp" };
//this string is for Level 1 Background rendering

char chr[8][30] = { "player//plane_0001.bmp", "player//plane_0002.bmp", "player//plane_0003.bmp", "player//plane_0004.bmp", "player//plane_0005.bmp", "player//plane_0006.bmp", "player//plane_0007.bmp", "player//plane_0008.bmp"};

int chx=500,chy=480,chr_index=0;

int mposx,  mposy;
/*
	function iDraw() is called again and again by the system.
*/
void iDraw()
{
	//place your drawing codes here
	iClear();
	for (int i = 9; i < 60; i++){
		iShowBMP(bg1[i], 0, img[i]); // this loop is for Level 1 Background rendering
	}
	iShowBMP2(chx, chy, chr[chr_index],0);
}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	//place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
	}
}
/*iPassiveMouseMove is called to detect and use
the mouse point without pressing any button */

void iPassiveMouseMove(int mx,int my)
{
	//place your code here

 mposx = mx;
 mposy = my;
 if(mx== 2){}        /*Something to do with mx*/
 else if(my== 2){}   /*Something to do with my*/

}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
	if(key == 'w')
	{
		chy += 10;
		if (chy >= 880) chy = 880;
	}
	if (key == 's')
	{
		chy -= 10;
		if (chy <= 0) chy = 0;
	}
	//place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_UP)
	{
		chy += 10;
		if (chy >= 880) chy = 880;
	}
	if (key == GLUT_KEY_DOWN)
	{
		chy -= 10;
		if (chy <= 0) chy = 0;
	}

	if (key == GLUT_KEY_END	)
	{
		exit(0);
	}
	//place your codes for other keys here
}
//

void setall(){
	for (int i = 9; i < 60; i++)
		bg1[i] = 32 * (i-9);  //this is a function that initializes the co-ordinates of Level 1 Background images
							  //on x axis for Level 1 Background rendering
}

void change(){								// this function updates the co-ordinates of Level 1 Background images
	for (int i = 9; i < 60; i++){			//on x axis for Level 1 Background rendering
		bg1[i] -= 8;
		if (bg1[i] <= 0) bg1[i] = 1600 ;//1616
	}		
	chr_index = (chr_index + 1)%7;

}


int main()
{
	setall();
	iSetTimer(25, change);
	//place your own initialization codes here.
	iInitialize(1600, 960, "demooo");
	return 0;
}
