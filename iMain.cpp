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

//difficulty section
int obs_gap = 220;
int obs_hi = 750;
int obs_lo = 500;
// int bg_speed = 16;
//int obs_speed = 8;


int chx = 700; //this variable stores the x co-ordinate of character images
int chy = 480; //this variable stores the y co-ordinate of character images
int chr_index = 0; //this variable stores the index of character images
int chr_speed = 8;	 //this variable stores the speed of character rendering

int bg_speed = 8;  //this variable stores the speed of background rendering
int bg_width = 1600; //this variable stores the width of whole background

int	slice = 60; //this variable stores the num of slice of background
int slice_width = 32; //this variable stores the width of each slice of background

int scr_index = 0; // this variable changes and makes it scoreboard rendering

int bg1[60]; // this array stores the co-ordinates of Level 1 Background images ( only on X AXIS )

int obs1x = 533;//100*183
int obs1y = 580; // highest
int obs3x = 916;//120*134
int obs3y = 300; // lowest
int obs2x = 1300;//130*60  
int obs2y = 415; // mid 
int obs_speed = 10;

int GameState = -1; // this variable stores the homepage index

int play_x = 37;
int play_y = 407;
int ins_x = 37;
int ins_y = 305;
int abt_x = 37;
int abt_y = 198;
int exit_x = 37;
int exit_y = 87;



char img[60][100] = { "screen//1.bmp", "screen//2.bmp", "screen//3.bmp", "screen//4.bmp", "screen//5.bmp", "screen//6.bmp", "screen//7.bmp", "screen//8.bmp", "screen//9.bmp", "screen//10.bmp", "screen//11.bmp", "screen//12.bmp", "screen//13.bmp", "screen//14.bmp", "screen//15.bmp", "screen//16.bmp", "screen//17.bmp", "screen//18.bmp", "screen//19.bmp", "screen//20.bmp", "screen//21.bmp", "screen//22.bmp", "screen//23.bmp", "screen//24.bmp", "screen//25.bmp", "screen//26.bmp", "screen//27.bmp", "screen//28.bmp", "screen//29.bmp", "screen//30.bmp",
"screen//31.bmp", "screen//32.bmp", "screen//33.bmp", "screen//34.bmp", "screen//35.bmp", "screen//36.bmp", "screen//37.bmp", "screen//38.bmp", "screen//39.bmp", "screen//40.bmp", "screen//41.bmp", "screen//42.bmp", "screen//43.bmp", "screen//44.bmp", "screen//45.bmp", "screen//46.bmp", "screen//47.bmp", "screen//48.bmp", "screen//49.bmp", "screen//50.bmp", "screen//51.bmp", "screen//52.bmp", "screen//53.bmp", "screen//54.bmp", "screen//55.bmp", "screen//56.bmp", "screen//57.bmp", "screen//58.bmp", "screen//59.bmp", "screen//60.bmp" };
//this string is for Level 1 Background rendering

char chr[8][30] = { "player//plane_0001.bmp", "player//plane_0002.bmp", "player//plane_0003.bmp", "player//plane_0004.bmp", "player//plane_0005.bmp", "player//plane_0006.bmp", "player//plane_0007.bmp", "player//plane_0008.bmp" };
//this string is for the character images

char score_board[30][35] = { "scoreboard//Slide1.bmp", "scoreboard//Slide2.bmp", "scoreboard//Slide3.bmp", "scoreboard//Slide4.bmp", "scoreboard//Slide5.bmp", "scoreboard//Slide6.bmp", "scoreboard//Slide7.bmp", "scoreboard//Slide8.bmp", "scoreboard//Slide9.bmp", "scoreboard//Slide10.bmp",
"scoreboard//Slide11.bmp", "scoreboard//Slide12.bmp", "scoreboard//Slide13.bmp", "scoreboard//Slide14.bmp", "scoreboard//Slide15.bmp", "scoreboard//Slide16.bmp", "scoreboard//Slide17.bmp", "scoreboard//Slide18.bmp", "scoreboard//Slide19.bmp", "scoreboard//Slide20.bmp",
"scoreboard//Slide21.bmp", "scoreboard//Slide22.bmp", "scoreboard//Slide23.bmp", "scoreboard//Slide24.bmp", "scoreboard//Slide25.bmp", "scoreboard//Slide26.bmp", "scoreboard//Slide27.bmp", "scoreboard//Slide28.bmp", "scoreboard//Slide29.bmp", "scoreboard//Slide30.bmp" };
//this string is for the scoreboard

//char obs[30][35]


int mposx, mposy;
/*
function iDraw() is called again and again by the system.
*/
void iDraw()
{
	//place your drawing codes here
	iClear();
	if (GameState == -1){					// if the GameState is -1 that means the game is now paused
		iShowBMP(0, 0, "menu//bg.bmp");// render the homepage 
		iShowBMP2(play_x, play_y, "menu//1.bmp", 0);
		iShowBMP2(ins_x, ins_y, "menu//2.bmp", 0);
		iShowBMP2(abt_x, abt_y, "menu//3.bmp", 0);
		iShowBMP2(exit_x, exit_y, "menu//4.bmp", 0);
	}
	else if (GameState == 0){
		for (int i = 9; i < slice; i++){
			iShowBMP(bg1[i], 0, img[i]); // this loop is for Level 1 Background rendering
		}

		iShowBMP2(obs1x, obs1y, "obstrcle1//1.bmp", 0);   //this four lines are rendering the obstrcle
		iShowBMP2(obs1x, obs1y - obs_gap, "obstrcle1//2.bmp", 0);
		iShowBMP2(obs2x, obs2y, "obstrcle1//3.bmp", 0);
		iShowBMP2(obs2x, obs2y - obs_gap, "obstrcle1//4.bmp", 0);
		iShowBMP2(obs3x, obs3y, "obstrcle1//5.bmp", 0);
		iShowBMP2(obs3x, obs3y - obs_gap + 100, "obstrcle1//6.bmp", 0);

		iShowBMP(0, 0, score_board[scr_index]); // this function is rendering the scoreboard
		iShowBMP2(chx, chy, chr[chr_index], 0); //rendering the character images



	}

	if (GameState == 1){
		//place your drawing codes here
		iShowBMP(0, 0, "menu//instruction.bmp");
	}

	if (GameState == 2){
		//place your drawing codes here
		iShowBMP(0, 0, "menu//about.bmp");
	}
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
	if (GameState == -1)
	{

		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			if (mx >= play_x && mx <= play_x + 386 && my >= play_y && my <= play_y + 76)		// the condition for the option "PLAY GAME" in the homepage
				GameState = 0;
			//place your codes here
			if (mx >= ins_x && mx <= ins_x + 386 && my >= ins_y && my <= ins_y + 76)
				GameState = 1;
			if (mx >= abt_x && mx <= abt_x + 386 && my >= abt_y && my <= abt_y + 76)
				GameState = 2;
			if (mx >= exit_x && mx <= exit_x + 386 && my >= exit_y && my <= exit_y + 76)
				exit(0);

		}
		if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
		{
			//place your codes here
		}
	}
}
/*iPassiveMouseMove is called to detect and use
the mouse point without pressing any button */

void iPassiveMouseMove(int mx, int my)
{
	//place your code here

	mposx = mx;
	mposy = my;
	if (mx == 2){}        /*Something to do with mx*/
	else if (my == 2){}   /*Something to do with my*/

}

/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
	if (key == 'w')
	{
		chy += 10;
		if (chy >= 880) chy = 880; // for pressing "w" key each time 
	}							   // the co-ordinates on Y axis increases 10 pixels
	if (key == 's')
	{
		chy -= 10;				// for pressing "s" key each time 
		if (chy <= 0) chy = 0;  //// the co-ordinates on Y axis decreases 10 pixels
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

	if (key == GLUT_KEY_UP)
	{
		chy += 10;						// for pressing "GLUT_KEY_UP" key each time 
		if (chy >= 880) chy = 880;		// the co-ordinates on Y axis increases 10 pixels
	}
	if (key == GLUT_KEY_DOWN)
	{
		chy -= 10;				// for pressing "GLUT_KEY_DOWN" key each time 
		if (chy <= 0) chy = 0;	//// the co-ordinates on Y axis decreases 10 pixels
	}

	if (key == GLUT_KEY_END)
	{
		exit(0); // for pressing "GLUT_KEY_END" key the game ends
	}
	if (key == GLUT_KEY_HOME){
		GameState = -1; //you can go to the home and pause the game by clicking the "GLUT_KEY_HOME" button
	}
	//place your codes for other keys here
}
//

void setall(){
	for (int i = 9; i < slice; i++)
		bg1[i] = slice_width * (i - 9);  //this is a function that initializes the co-ordinates of Level 1 Background images
	//on x axis for Level 1 Background rendering
}

void change(){								// this function updates the co-ordinates of Level 1 Background images
	if (GameState == 0){  					// when the game is running
		for (int i = 9; i < slice; i++){			//on x axis for Level 1 Background rendering
			bg1[i] -= bg_speed;
			if (bg1[i] <= 0) bg1[i] = bg_width;//1616
		}
		chr_index = (chr_index + 1) % 7; // this line updates the character rendering index
		
		obs1x = obs1x - obs_speed;
		if (obs1x <= 150) obs1x = 1280;
		obs2x = obs2x - obs_speed;
		if (obs2x <= 150) obs2x = 1280;
		obs3x = obs3x - obs_speed;
		if (obs3x <= 150) obs3x = 1280;


	}
}

void collisioncheck(){

}

int main()
{
	setall();
	iSetTimer(25, change);
	iSetTimer(5, collisioncheck);
	//place your own initialization codes here.
	iInitialize(1280, 720, "Bumbble Jet");
	return 0;
}