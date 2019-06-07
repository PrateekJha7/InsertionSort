#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<GL/glut.h>
//#include<graphics.h>
void *currentfont=GLUT_BITMAP_TIMES_ROMAN_24;
#define SORT_NO 1	// Number of sorting algorithms
#define MAX 25		// Number of values in the array
#define SPEED 700	// Speed of sorting, must be greater than MAX always
int a[MAX];		// Array
int swapflag=0;		// Flag to check if swapping has occured
int i=0,j=0;		// To iterate through the array
int flag=0;		// For Insertion Sort
int dirflag=0;		// For Ripple Sort, to change direction at the ends
int count=1;		// For Ripple Sort, to keep count of how many are sorted at the end
int count1=0;
int k=0;		// To Switch from Welcome screen to Main Screen
int sorting=0;		// 1 if Sorted
char *sort_string[]={"Insertion Sort"};
int sort_count=0;	// To cycle through the string

// Function to display text on screen char by char
void bitmap_output(int x, int y, char *string, void *font)
{
	int len, i;

	glRasterPos2f(x, y);
	len = (int) strlen(string);
	for (i = 0; i < len; i++) {
		glutBitmapCharacter(font, string[i]);
	}
}

void int_str(int rad,char r[])
{
	itoa(rad,r,10);
}

void display_text()
{
	glColor3f(0,0,1);
	bitmap_output(150, 665, "Insertion Sort Algorithm",GLUT_BITMAP_TIMES_ROMAN_24);
	glBegin(GL_LINE_LOOP);
		//glVertex2f(145, 660);
		//glVertex2f(520, 660);
	glEnd();

	// other text small font
	bitmap_output(10, 625, "This program sorts a random set of numbers in ascending order displaying them graphically as ",GLUT_BITMAP_9_BY_15);
	bitmap_output(10, 605, "bars with varying height",GLUT_BITMAP_9_BY_15);


	if (sorting == 0)	// if not sorting display menu
	{
		bitmap_output(10, 575, "MENU",GLUT_BITMAP_9_BY_15);
		bitmap_output(10, 555, "Press s to SORT",GLUT_BITMAP_9_BY_15);
		//bitmap_output(10, 535, "Press c to SELECT the sort algorithm",GLUT_BITMAP_9_BY_15);
		bitmap_output(10, 515, "Press r to RANDOMISE",GLUT_BITMAP_9_BY_15);
		bitmap_output(10, 495, "Press q to QUIT",GLUT_BITMAP_9_BY_15);
		bitmap_output(10, 475, "Selected sort: ",GLUT_BITMAP_9_BY_15);
		bitmap_output(150, 475, *(sort_string+sort_count),GLUT_BITMAP_9_BY_15);
	}
	else if (sorting == 1)	// while sorting
	{
		glColor3f(0.5,0.5,0.5);
		bitmap_output(10, 555, "Sorting in progress...",GLUT_BITMAP_9_BY_15);
		bitmap_output(10, 535, "Press p to PAUSE",GLUT_BITMAP_9_BY_15);
		glColor3f(0.0,0.0,0.0);
	}
}
void drawstring(float x,float y,float z,char *string)
{
 char *c;
glRasterPos3f(x,y,z);
 for(c=string;*c!='\0';c++)
 {glColor3f(0.0,0.0,0.0);
  glutBitmapCharacter(currentfont,*c);//display string
 }
}
void frontscreen()
{
 glClear(GL_COLOR_BUFFER_BIT);/*
glBegin(GL_POLYGON);
			//glColor3f(1.8,1.8,1.8);
		    glColor3f(0.502,0.0,0.502);
			glVertex2f(0,0);
			//glColor3f(0.184,0.310,0.310);
			glColor3f(0.618,0,0.184);
			glVertex2f(0,640);
			//glColor3f(0.8,0.8,0.8);
			glColor3f(1,0.549,0);
			glVertex2f(640,640);
//			glColor3f(0.184,0.310,0.310);
	glColor3f(0.255,0.412,0.882);
			glVertex2f(640,0);
			glEnd();*/
glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);//background color
	glColor3f(0,1,1);
	glVertex2f(0,0);
//	glColor3f(0.6,1.0,0.9);
glColor3f(0.6,0.6,0.6);
	glVertex2f(0,1000);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(1000,1000);
//glColor3f(0.6,1,0.9);
glColor3f(0.6,0.6,0.6);	glVertex2f(1000,0);
	glEnd();
 glColor3f(0,0,1);//string color
 drawstring(165.0,450.0,0.0,"SDM INSTITUTE OF TECHNOLOGY");//position and string
 glColor3f(0.7,0,1);
 drawstring(110,400,0.0,"DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING");
 glColor3f(1,0.5,0);
 drawstring(196,350,0.0,"MINI PROJECT ON");
 glColor3f(0.9,0.1,0.3);
 drawstring(118,300,0.0,"**********SIMULATION INSERTION SORT**********");
 glColor3f(0.7,0,0.5);
 drawstring(50,250,0.0,"SUBMITTED BY:");
 glColor3f(0.0,0,1);
 drawstring(50,150,0.0,"PRATEEK KUMAR JHA (4SU15CS082)");
 glColor3f(0.0,0,1);
 drawstring(50,100,0.0,"RAGHOOTTAM KATTI (4SU15CS085)");
 glColor3f(0.7,0,0.5);
 drawstring(350,250,0.0,"GUIDED BY:");
 glColor3f(0.0,0,1);
 drawstring(350,200,0.0,"PROF.ARJUN K");
 glColor3f(0.0,0,1);
 drawstring(350,100,0.0,"PROF.GURUPRASAD MS");
 glColor3f(0.0,0,1);
 drawstring(350,150,0.0,"PROF.H MANOJ T GADIYAR");
 glColor3f(0.3,0.4,0.2);
 drawstring(196,50,0.0,"[PRESS ENTER TO START]");
 glFlush();
}

void Initialize() {
	int temp1;

	// Reset the array
	for(temp1=0;temp1<MAX;temp1++){
		a[temp1]=rand()%100+1;
		printf("%d ",a[temp1]);
	}

	// Reset all values
	i=j=0;
	dirflag=0;
	count=1;
	flag=0;

	glClearColor(1,1,1,1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 699,0,799);
}


// Return 1 if not sorted
int notsorted(){
	int q;
	for(q=0;q<MAX-1;q++)
	{
		if(a[q]>a[q+1])
			return 1;
	}
	return 0;
}

// Main function for display
void display()
{
	int ix,temp;
	glClear(GL_COLOR_BUFFER_BIT);

	if(k==0)
		frontscreen();
	else{
		display_text();
		char text[10];

		for(ix=0;ix<MAX;ix++)
		{
			glColor3f(1,0.2,0);
			glLineWidth(50);
			glBegin(GL_LINE_LOOP);
            //glColor3f(1,0,0);

				//glVertex2f(10+(700/(MAX+1))*ix,50);
				glVertex2f(10+(700/(MAX+1))*(ix+1),50);
				glVertex2f(10+(700/(MAX+1))*(ix+1),50+a[ix]*4);
				//glVertex2f(10+(700/(MAX+1))*ix,50+a[ix]*4);

			glEnd();

			int_str(a[ix],text);
			printf("\n%s",text);
			glColor3f(0,0,0);
			bitmap_output(29+(700/(MAX+1))*ix, 35, text,GLUT_BITMAP_TIMES_ROMAN_10);
		}

		if(swapflag || sorting==0)
		{
			glColor3f(0,0,0);
			glLineWidth(50);
			glBegin(GL_LINE_LOOP);
				glColor3f(0,0,1);
				//glVertex2f(10+(700/(MAX+1))*j,50);
				glVertex2f(10+(700/(MAX+1))*(j+1),50);
                glVertex2f(10+(700/(MAX+1))*(j+1),50+a[j]*4);
				//glVertex2f(10+(700/(MAX+1))*j,50+a[j]*4);

			glEnd();

			swapflag=0;
		}
	}
	glFlush();
}

// Insertion Sort
void insertionsort()
{
	int temp;

	while(i<MAX)
	{
		if(flag==0){j=i; flag=1;}
		while(j<MAX-1)
		{
			if(a[j]>a[j+1])
			{
				swapflag=1;
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				//count1++;
				//printf("Total count %d",count1);
				goto A;
			}
			j++;
			if(j==MAX-1)
			{
			flag=0;
			}
			printf("swap %d and %d\n",a[j],a[j+1]);
		}
		i++;
		//printf("Total count %d",i);
	}
	sorting=0;
	A:
	i=j=0;
	count1++;
	printf("Total number of swaps: %d\n",count1);
}


// Timer Function, takes care of sort selection
void makedelay(int)
{
	if(sorting)
	{
		switch(sort_count)
		{
			case 0:	insertionsort();	break;
			case 1:	exit(0);

		}
	}
	glutPostRedisplay();
	glutTimerFunc(SPEED/MAX,makedelay,1);
}

// Keyboard Function
void keyboard (unsigned char key, int x, int y)
{
	if(key==13)
		k=1;
	if (k==1 && sorting!=1)
	{
		switch (key)
		{
			case 113 :	exit (0); // 27 is the ascii code for the ESC key
			case 's' :	sorting = 1; break;
			case 'r' :	Initialize(); break;
			case 'c' :	sort_count=(sort_count+1)%SORT_NO;	break;
		}
	}
	if(k==1 && sorting==1)
		if(key=='p')	sorting=0;
}

// Main Function

int main(int argc,char **argv)
{

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(1000,600);
	glutInitWindowPosition(0,0);
	glutCreateWindow("SIMULATION OF INSERTION SORT");
	Initialize();
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
//	glutMouseFunc(mouse);
	glutTimerFunc(1000,makedelay,1);
	glutMainLoop();
	return 0;
}
