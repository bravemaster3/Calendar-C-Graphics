// C Program To Implement a Calendar using Graphics.h

// Header Files
#include<stdio.h>
#include<graphics.h>
#include<process.h>
#include<conio.h>

// Function to Set the Screen
void draw_bg()
{
	cleardevice();
	setbkcolor(BLUE);
}

// Driver's Code
int main()
{
	// Variable Declaration
	int m, y, col, row, s, firstday,leap, ch, ch1, d,i;
	long int normaldays,totaldays;
	int days[]={31,0,31,30,31,30,31,31,30,31,30,31};
	char *month[]={ "January", "Febraury", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	
	// Initializing Graphics Library 
	int gd=DETECT, gm;
	initgraph(&gd, &gm, "<Graphics - Driver - Path>");
	draw_bg();
	gotoxy(20,10);
	printf("Enter Month & Year : ");
	scanf("%d %d",&m, &y);

	while(1)
	{
		draw_bg();

		normaldays = (y-1)*365l;
		leap = (y-1)/4-(y-1)/100+(y-1)/400;
		totaldays = normaldays + leap;

		// Checking For Leap Year
		if( (y%4==0) || (y%100!=0 && y%4==0) )
		   days[1]=29;
		else
		   days[1]=28;

		s=0;
		for(i=0;i<=m-2;i++)
		    s = s + days[i];
		totaldays += s;
		firstday = totaldays%7;
		col = 20 + firstday*6;
		gotoxy(32,8);
		printf("%s  %d",month[m-1],y);
		gotoxy(20,10);
		printf("Mon   Tue   Wed   Thu  Fri   Sat   Sun");
		row=12;
		for(d=1;d<=days[m-1];d++)
		{
			if(m==9&&y==1757&&d==4)
				d=d+13;
			gotoxy(col,row);
			printf("%d", d);
			col=col+6;
			if(col>56)
			{
				row++;
				col=20;
			}
		}

		// User Controls Description
		gotoxy(20,20);
		printf("Right for Next Month");
		gotoxy(20,21);
		printf("Left for Previous Month");
		gotoxy(20,22);
		printf("Down Arrow for Next Year");
		gotoxy(20,23);
		printf("Up Arrow for Previous Year");
		gotoxy(20,24);
		printf("Press Delete for Exit");
		gotoxy(30,25);

		// Input
		ch=getch();
		if(ch==0)
			ch1=getch();

		// Conditional Rendering
		switch(ch1)
		{
			case 77:
				m++;
				if(m>12)
				{
					m=1;
					y++;
				}
				break;
			case 75:
				m--;
				if(m<1)
				{
					m=12;
					y--;
				}
				break;
			case 80:
				y++;
				break;
			case 72:
				y--;
				break;
			case 83:
				exit(0);
		}
	}
}// End of Main