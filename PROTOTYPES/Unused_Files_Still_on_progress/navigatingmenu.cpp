#include<stdio.h>

#include<conio.h>

#include<graphics.h>

void test(int);

void main()

{

int gd=DETECT,gm=0;

int y=127;

int key=0;
    
initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

setcolor(4);

while(1)

{

cleardevice();

setbkcolor(BLUE);

setcolor(2);

settextstyle(0,0,2);

outtextxy(200,20,"Code In Nepal");

settextstyle(0,0,1);

setcolor(15);

outtextxy(20,130,"Like");

outtextxy(20,150,"Share");

outtextxy(20,170,"Subscribe");

rectangle(15,y,180,y+15);

key=getch();

if(key==27)

exit(0);

if(key==13)

{

test(y);

break;

}

if(key==80&&y<167)

{

y=y+20;

}

else if(key==72&&y>=142)

{

y=y-20;

}

else

y=y;

}

closegraph();



}



void test(int y)

{

if(y==127)

{

cleardevice();

outtextxy(50,50,"YOU CLICKED LIKE OPTION");

getch();

}

else if(y==147)

{

cleardevice();

outtextxy(50,50,"YOU CLICKED SHARE OPTION");

getch();

}

else if(y==167)

{

cleardevice();

outtextxy(50,50,"YOU CLICKED SUBSCRIBE OPTION");

getch();

}


}

