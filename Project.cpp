#include "iGraphics.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int m_x=0;
int m_y =0;
int page = 1;
int x = 659;
int y = 20;
int score=0;
char s[100];

/*
	function iDraw() is called again and again by the system.
*/

int main_x = 456;
int main_y = 30;
void background()
{
	iSetColor(90,90,90); // background
	iFilledRectangle(456,0,456,768);

	iSetColor(255,255,255);// 1st road coloumn
   iFilledRectangle(608,0,7,768);

   iSetColor(255,255,255);
   iFilledRectangle(608,350,7,150);

   iSetColor(255,255,255); // 2nd road coloumn
   iFilledRectangle(760,0,5,768);

   iSetColor(0,0,255);
   iFilledRectangle(x,y,50,60);

   iSetColor(0,64,0);
   iFilledRectangle(x+10,y,30,60);

   iSetColor(00,80,80) ;
	iFilledRectangle(x+5,y+60,40,16);

	iSetColor(00,80,80);
	iFilledRectangle(x, y+64,5,8);

		iSetColor(00,80,80);
	iFilledRectangle(x+45,y+64,5,8);


}
int car1 = 600;
void enemy_car1(){
	iSetColor(255,140,0);
	iFilledRectangle(659,car1,50,60);

	iSetColor(00,80,00);
	iFilledRectangle(664,car1-16,40,16);

}
int car2 = 600;
void enemy_car2(){
	iSetColor(80,00,00);
	iFilledRectangle(506,car2,50,60);

	iSetColor(165,42,42);
	iFilledRectangle(512,car2-16,40,16);
}

int car3 = 900;
void enemy_car3(){
	iSetColor(255,99,71);
	iFilledRectangle(810,car3 ,50,60);

	iSetColor(255,69,0);
	iFilledRectangle(815,car3-16,40,16);

}
int car4 = 800;

void enemy_car4(){
	iSetColor(165,42,42);
	iFilledRectangle(458,car4,50,60);

	iSetColor(19,19,70);
	iFilledRectangle(463,car4-16,40,16);
}
int car5 = 800;
void enemy_car5(){
	iSetColor(213, 77, 41);
	iFilledRectangle(810,car5,50,60);

	iSetColor(27, 115, 21);
	iFilledRectangle(815,car5-16,40,16);
}

int car6 = 1400;
void enemy_car6(){
	iSetColor(108, 9, 96);
	iFilledRectangle(865,car6, 50 ,60);
	iSetColor(47, 158, 25);
	iFilledRectangle(870 , car6-16 , 40,16);

}
void collision(){
	if(x+25>659 && x<708 && car1<25)exit(0);
	else if(car1<25)
	{
		score+=5;
	}
	if(x+25>506 && x<556 && car2<25)exit(0);
	else if(car1<25)
	{
		score+=5;
	}
	if(x+25>810 && x<860 && car3<25)exit(0);
	else if(car1<25)
	{
		score+=5;
	}
	if(x+25>458 && x<508 && car4<25)exit(0);
	else if(car1<25)
	{
		score+=5;
	}
	if(x+25>810 && x<860 && car5<25)exit(0);
	else if(car1<25)
	{
		score+=5;
	}
	if(x+25>1400 && x<1450 && car6<25) exit(0);
	else if(car1<25)
	{
		score+=5;
	}

}

double d = 0;

double delay = 0;

void iDraw()
{
	iClear();
	if(page==1){

		//iSetColor(219,112,2);
		//iFilledRectangle(0,0,1388,800);
		iSetColor(255,192,203);
		iRectangle(50,50,200,100);
		iText(65,65,"PLAY");
	}
	else if(page==2)
	{


	d+=0.015;
	delay+=0.05;
	if(d>1)d=0;
	background();
	enemy_car1();
	enemy_car2();
	enemy_car3();
	enemy_car4();
	enemy_car5();
	enemy_car6();
	//iDelay(1);

	if(delay>1){car1-=5*(1+d);
	delay=0;
	if(car1<0)
	{
		car1=1100;

	}

	car2-=5*(1+d);

	if(car2<0)
	{
		car2=1100;
	}

	car3-=5*(1+d);

	if(car3<0)
	{
		car3=1100;
	}

	car4-=5*(1+d);

	if(car4<0)
	{
		car4=1100;
	}

	//enemy_car5();
	//iDelayMS(35);
	car5-=5*(1+d);
	if(car5<0)
	{
		car5 = 1100;
	}
if(car6<0)
	{
		car6 = 1100;
	}
	collision();

	//enemy_car6();
	//iDelayMS(25 );
	car6-=5*(1+d);

	}



	//printf("%d\n" , score);
	sprintf(s, "Score: %d", score);
	iSetColor(15, 29, 134);
	iText(1146,384,s, GLUT_BITMAP_TIMES_ROMAN_24);

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
	printf("Button Number %d %d\n", button,state);
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if(mx>50 && mx<250 && my>50 && my<150 && page==1){//Click on Play in Main Menu
			page=2;
		}


	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
	}
}
/*
	function iPassiveMouseMove is called when user hovers the mouse pointer in the screen
	(mx,my) is the coordinate of mouse pointer
*/
void iPassiveMouseMove(int mx,int my){
	//printf("%d %d\n",mx,my);
	m_x = mx;
	m_y = my;
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
	if(key == 'q')
	{
		//do something with 'q'
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

	if(key == GLUT_KEY_END)
	{
		exit(0);
	}
	if((key == GLUT_KEY_DOWN)||(key == GLUT_KEY_PAGE_DOWN))
	{
	//	y-=12;
	}
	if((key == GLUT_KEY_UP)||(key == GLUT_KEY_PAGE_UP))
	{
		//y+=12;

	}
	if(key == GLUT_KEY_LEFT)
	{
		//main_x-=10;
		if(x>456)x-=10;
		if(x<456)x=456;
	}
	 if(key == GLUT_KEY_RIGHT)
	{

		if(x<862)x+=10;
		if(x>862)x=862;
	}
	//place your codes for other keys here
}

int main()
{
	iInitialize(1366, 768, "Race");
	return 0;
}
