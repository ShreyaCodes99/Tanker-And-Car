/* Project Title: Tanker and Car travelling 
   By: Shreya Pathak (T.Y. BSc.(CS) )*/

/*Commands to execute the file: 

  Compilation: g++ TankerAndCar.c -o tnc -lglut -lGLU -lGL
  Execution: ./tnc

*/

#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>

const double PI = 3.141592654;

int frmno = 0; //frmno is the Number of frames initialized to 0.

/*
 * Drawing a 32-sided regular polygon(can be more) as an approximation for a circular disk.
 * (This is necessary since OpenGL has no commands for drawing ovals, circles,
 * or curves.)  
 * The disk is centered at (0,0) with a radius given by the 
 * parameter.
 */
void drawDisk(double radius) 
{
	int d;
	glBegin(GL_POLYGON); //for loop for generating 32 sides of the disk shaped polygon
	for (d = 0; d < 32; d++) 
	{
		double angle = 2*PI/32 * d; //Here, an angle of approximately 0.19 degree is set.
		glVertex2d( radius*cos(angle), radius*sin(angle)); //x=r cos(theta), y=r sin(theta)
	}
	glEnd();
}

/*
 * Draw a wheel, centered at (0,0) and with radius 1. The wheel has 15 spokes
 * that rotate in a clockwise direction as the animation proceeds.
 */
void drawWheel() {
    int i;
	glColor3f(0,0,0);
	drawDisk(1);
	glColor3f(0.75f, 0.75f, 0.75f); //Color of the wheel.
	drawDisk(0.8); //Radius is of the wheel is 0.8.
	glColor3f(0,0,0);
	drawDisk(0.2); 
	glRotatef(frmno*20,0,0,1); //Rotation of frames is set for the animation effect (rotation angle,x,y,z) according to rotation matrix.
	glBegin(GL_LINES);
	for (i = 0; i < 15; i++) //For loop for  spokes of the wheel
	{
		glVertex2f(0,0); //glVertex of type Float having 2 parameters
		glVertex2d(cos(i*2*PI/15), sin(i*2*PI/15)); //glVertex of type Double having 2 parameters
	}
	glEnd();
}

void drawTrees() 
{
	
	glColor3f(0.54510f, 0.27059f, 0.07451f); //Color of the bark of the trees
	glBegin(GL_POLYGON); //Co-rdinates of the polygon to build a vertical bark
	glVertex2f(-0.05f, 0);
	glVertex2f(0.05f, 0);
	glVertex2f(0.05f, 3);
	glVertex2f(-0.05f, 3);
	glEnd();
	glTranslatef(0, 3, 0); //Translating the Polygon (here, bark) to a farther point on the screen 
	    
	    glColor3f(0.16863f, 0.43137f, 0.23922f); //Color of the leaves of the tree
		glBegin(GL_POLYGON); //First layer of leaves
		glVertex2f(0,0);
		glVertex2f( -0.8, -0.8 );
		glVertex2f( 0, 0.9 );
		glVertex2f( 0.8, -0.8 );

		glVertex2f(0,2); //Second layer of leaves
		glVertex2f( -0.8, -0.8 );
		glVertex2f( 0, 0.9 );
		glVertex2f( 0.8, -0.8 );

  		glVertex2f(0,-2); //Third layer of leaves
		glVertex2f( -0.8, -0.8 );
		glVertex2f( 0, 0.9 );
		glVertex2f( 0.8, -0.8 );

		glEnd();
}


/*
 * Draw a car and tank consisting of a rectangular body and two wheels (three wheels for the tank).  The wheels
 * are drawn by the drawWheel() method; a different translation is applied to each
 * wheel to move them into position under the body.  The body of the car
 * is a light orange rectangle with corner at (0,-2.5), width 5(-2.5 to 2.5), and height 2 with the upper part having height 4.  The
 * center of the bottom of the rectangle is at (0,0).
 */
void drawTank() 
{
	glPushMatrix(); //Back wheel of the tank
	glTranslatef(-1.5f, -0.1f, 0); //x is the position of the wheel on the car
	glScalef(0.8f,0.8f,1);
	drawWheel();
	glPopMatrix();
	glPushMatrix(); //Middle wheel of the tank
	glTranslatef(-0.08f, -0.1f, 0);
	glScalef(0.8f,0.8f,1);
	drawWheel();
	glPopMatrix();
	glPushMatrix(); //Front Wheel of the tank
	glTranslatef(1.5f, -0.1f, 0);
	glScalef(0.8f,0.8f,1);
	drawWheel();
	glPopMatrix();


    glColor3f(0.29412f,0.32549f,0.12549f); //Color of the upper part of the tank (Army Green)
	glBegin(GL_POLYGON);
	glVertex2f(-5.5f,2);
	glVertex2f(4.5f,3);
	glVertex2f(4.5f,4);
	glVertex2f(-4.5f,4);

	glColor3f(0.29412f,0.32549f,0.12549f); //Color of the lower part of the tank (Army Green)
	glBegin(GL_POLYGON);
	glVertex2f(-2.5f,0);
	glVertex2f(2.5f,0);
	glVertex2f(2.5f,2.5);
	glVertex2f(-2.5f,2);
	glEnd();
}

void drawCar() {
	glPushMatrix(); //Back wheel of the car
	glTranslatef(-1.5f, -0.1f, 0);
	glScalef(0.8f,0.8f,1);
	drawWheel();
	glPopMatrix();
	glPushMatrix(); //Front wheel of the car
	glTranslatef(1.5f, -0.1f, 0);
	glScalef(0.8f,0.8f,1);
	drawWheel();
	glPopMatrix();
	glColor3f(1.0f,0.38824f,0.27843f); //Color of the car (Light Orange)
	glBegin(GL_POLYGON);
	
	glVertex2f(-1.25f,2);
	glVertex2f(1.25f,2);
	glVertex2f(1.25f,4);
	glVertex2f(-1.25f,4);


	glVertex2f(-2.5f,0);
	glVertex2f(2.5f,0);
	glVertex2f(2.5f,2);
	glVertex2f(-2.5f,2);
	glEnd();
}

/*
 * Draw a sun with radius 0.5 centered at (0,0).  There are also 13 rays which
 * extend outside from the sun for another 0.25 units.
 */

void drawSun() {
	int i;
	glColor3f(1,1,0); //Color of the Sun (Yellow)
	for (i = 0; i < 13; i++) { // Draw 13 rays, with different rotations.
		glRotatef( 360 / 13, 0, 0, 1 ); // Angle of rotation: 27.69230 degrees.
		glBegin(GL_LINES);
		glVertex2f(0, 0);
		glVertex2f(0.75f, 0);
		glEnd();
	}
	drawDisk(0.5); //Use disk with radius 0.5 for Sun (having 32 sides)
	glColor3f(0,0,0);
}

/*
 * This function is called when the image needs to be redrawn.
 * It is installed by main() as the GLUT display function.
 * It draws the current frame of the animation.
 */
void display() {

	glClear(GL_COLOR_BUFFER_BIT); // Fills the scene with faint blue.
	glLoadIdentity();

   /* Draw grass below the road*/
	glColor3f(0, 0.8f, 0.2f); //Color of the grass
	glBegin(GL_POLYGON);
	glVertex2f(-3,-1);
	glVertex2f(0,0.4f);
	glVertex2f(6,-1);
	glEnd();


	/* Draw a hill in the background */

	glColor3f(0, 0.8f, 0.2f); //Color of the hill
	glBegin(GL_POLYGON);
	glVertex2f(-5,-5);
	glVertex2f(6,1.6f); //Height of the hill
	glVertex2f(19,1);
	glEnd();

	/* Draw a gray rectangle to represent the road. */

	glColor3f(0.5f, 0.5f, 0.5f); //Color for the road
	glBegin(GL_POLYGON);
	glVertex2f(0,-0.4f);
	glVertex2f(7,-0.4f);
	glVertex2f(7,0.4f);
	glVertex2f(0,0.4f);
	glEnd();

	/* Draw a white line to represent the stripe down the middle
	 * of the road. */

	glLineWidth(6);  // Set the line width to be 6 pixels.
	glColor3f(1,1,1);
	glBegin(GL_LINES);
	glVertex2f(0,0);
	glVertex2f(7,0);
	glEnd();
	glLineWidth(1);  // Reset the line width to be 1 pixel.


    /* Draw a tree on the left */
    glPushMatrix();
	glTranslated(0.75,0.5,0);
	glScaled(0.6,0.6,1);
	drawTrees();
	glPopMatrix();

    /* Draw a tree on the right */
    glPushMatrix();
	glTranslated(3.3,0.6,0);
	glScaled(0.6,0.6,1);
	drawTrees();
	glPopMatrix();


	/* Draw the sun.  The drawSun method draws the sun centered at (0,0).  A 2D translation
	 * is applied to move the center of the sun to (5,3.3).   A rotation makes it rotate*/

	glPushMatrix();
	glTranslated(5.8,3,0);
	glRotated(-frmno*0.7,0,0,1);
	drawSun();
	glPopMatrix();

	/* Draw the car.  The drawCar method draws the car with the center of its base at
	 * (0,0).  The body of the car is 5 units long and 2 units high.  A scale is first
	 * applied to the car to make its size more reasonable for the picture.  Then a
	 * translation is applied to move the car horizontally.  The amount of the translation
	 * depends on the frame number, which makes the car move from left to right across
	 * the screen as the animation progresses.  The car animation repeats every 300 
	 * frames.  At the beginning of the animation, the car is off the left edge of the
	 * screen. */

	glPushMatrix();
	glTranslated(-3 + 13*(frmno % 300) / 300.0, 0, 0);
	glScaled(0.3,0.3,1);
	drawTank();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-3 + 12*(frmno % 200) / 200.0, 0, 0);
	glScaled(0.3,0.3,1);
	drawCar();
	glPopMatrix();

	glutSwapBuffers();

}  // end display

/*
 * This function is set as the glutTimerFunc to drive the animation
 */
void doFrame(int v) {
    frmno++;
    glutPostRedisplay();
    glutTimerFunc(30,doFrame,0);
}

/*
 * This method is called from main() to initialize OpenGL.
 */
void init() {
	glClearColor(0.74902f, 0.847059f, 1, 1); //Background color LightBlue = color red 0.74902 green 0.847059 blue 0.847059
		// The next three lines set up the coordinates system.
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 7, -1, 4, -1, 1);
	glMatrixMode(GL_MODELVIEW);
}


int main(int argc, char** argv) {
    glutInit(&argc, argv); 
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(1100,700);
    glutInitWindowPosition(100,100);  
    glutCreateWindow("Tanker and Car travelling"); 

    init();

    glutDisplayFunc(display);   
    glutTimerFunc(200,doFrame,0); 

    glutMainLoop(); 
    return 0;
}    

math.hws.edu
https://encycolorpedia.com/
http://easyrgb.com/en/convert.php#inputFORM
https://www.opengl.org/archives/resources/code/samples/glut_examples/progs.html
