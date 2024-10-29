#define GL_SILENCE_DEPRECATION // Remove Deprecation Messages
#include <GLUT/glut.h> // GLUT, include glu.h and gl.h

#include <math.h>

#include<cstring>

#include <string>
#include <cstdlib>

#include <ctime>

void drawText(float x, float y, const std::string& text, float r, float g, float b) {
glColor3f(r, g, b);
glRasterPos2f(x, y);
for (char c : text) {
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
}
}


bool ismoon = true;
bool israin = true;

void keyboard(unsigned char key, int x, int y) {


if (key == 'D' || key == 'd' || key == '1') {
    israin = false;
    ismoon = true;

} else if (key == 'R' || key == 'r' || key == '3' ) {
    israin = true;
    ismoon = false;

}



glutPostRedisplay();
}

float boatX = 0.0f;

float boatY = 0.0f;

float boatX1 = 0.0f;

float boatY1 = 0.0f;

float objectX = 0.0f;

float objectY = 0.0f;
float move1 = 0.0f;
float move2 = 0.0f;
float scaleValue = 0.0f;
float carX = 0.0f;
float carY = -10.0f;

float carX1 = 0.0f;
float carY1 = -10.0f;

int currentScene = 1;

int elapsedTime = 1;

bool isSnowing = false;

char text[] = "BOAT GHAT";



void initGL() {

    glClearColor(0.4f, 0.4f, 0.4f, 1.0f);

    }

void circle(float radius, float cX, float cY)

{

    for(int i=0;i<200;i++)

        {

            float pi=3.1416;

            float A=(i*2*pi)/200;

            float r=radius;

            float x = r * cos(A);

            float y = r * sin(A);

            glVertex2f(x+cX,y+cY);

        }

}


void Sprint( float x, float y, char *st)

{

    int l,i;


    l=strlen( st ); // see how many characters are in text string.

    glColor3ub(255,255,255);

    //glDisable(GL_LIGHTING);

    glRasterPos2f( x, y); // location to start printing text

    for( i=0; i < l; i++) // loop until i is greater then l

    {

       glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, st[i]);

    }

}


void scene1() {

glClear(GL_COLOR_BUFFER_BIT);

glBegin(GL_POLYGON); //right arc1

glColor3ub(144, 109, 28 );

circle(25.0,27.0,-23.0);

glEnd();

glBegin(GL_LINES); //right arc1 border

glColor3ub(255,255,255 );

circle(25.0,26.5,-23.0);

glEnd();

glBegin(GL_POLYGON);   //right arc2

glColor3ub(56, 135, 186   );

circle(25.0,29.0,-23.0);

glEnd();


glBegin(GL_POLYGON);     //left arc1

glColor3ub(194, 169, 69 );

circle(25.0,-27.0,-23.0);

glEnd();

glBegin(GL_LINES);     //left arc1 border

glColor3ub(255,255,255);

circle(25.0,-26.5,-23.0);

glEnd();


glBegin(GL_POLYGON);    //left arc2

glColor3ub(56, 135, 186);

circle(25.0,-29.0,-23.0);

glEnd();


glBegin(GL_POLYGON); //upper arc

glColor3ub(51, 127, 177 );

circle(120.0,0.0,120.0);

glEnd();

/*glBegin(GL_LINE_LOOP); //upper arc road border

glColor3ub(255, 255, 255 );

circle(120.0,0.0,120.0);

glEnd();*/

glBegin(GL_POLYGON);//sky

glColor3ub(142, 242, 242 );

glVertex2f(-25.0f, 15.0f);

glVertex2f(-25.0f, 7.5f);

glVertex2f(25.0f, 7.5f);

glVertex2f(25.0f, 15.0f);

glEnd();


glBegin(GL_POLYGON); //upper arc

glColor3ub(255, 251, 14);//sun

circle(3.0,0.0,11.0);

glEnd();


glPushMatrix();

glTranslatef(move1,0.0f,0.0);

glBegin(GL_POLYGON);//cloud left

glColor3ub(255, 255,255);

circle(2.0,-10.0,11.0);

glEnd();

glBegin(GL_POLYGON);

glColor3ub(255, 255,255);

circle(1.5,-12.0,11.0);

glEnd();

glBegin(GL_POLYGON);

glColor3ub(255, 255,255);

circle(1.5,-8.0,11.0);

glEnd();

glPopMatrix();


glPushMatrix();

glTranslatef(move1,0.0f,0.0);

glBegin(GL_POLYGON);//cloud right

glColor3ub(255, 255,255);

circle(2.0,10.0,11.0);

glEnd();

glBegin(GL_POLYGON);

glColor3ub(255, 255,255);

circle(1.5,12.0,11.0);

glEnd();

glBegin(GL_POLYGON);

glColor3ub(255, 255,255);

circle(1.5,8.0,11.0);

glEnd();

glPopMatrix();


glPushMatrix();

glScalef(1.5f, 1.5f, 0.0f);

glBegin(GL_TRIANGLES); //hills

glColor3ub(150,150,150);

glVertex2f(15.0f, 5.0f);

glVertex2f(17.0f, 7.0f);

glVertex2f(19.0f, 5.0f);


glColor3ub( 183, 183, 183);

glVertex2f(13.0f, 5.0f);

glVertex2f(15.0f, 8.0f);

glVertex2f(17.0f, 5.0f);


glColor3ub(150,150,150); // hill

glVertex2f(11.0f, 5.0f);

glVertex2f(13.0f, 7.0f);

glVertex2f(15.0f, 5.0f);


glColor3ub( 183, 183, 183); // hill

glVertex2f(9.0f, 5.0f);

glVertex2f(11.0f, 8.0f);

glVertex2f(13.0f, 5.0f);


glColor3ub(150,150,150); // hill

glVertex2f(7.0f, 5.0f);

glVertex2f(9.0f, 7.0f);

glVertex2f(11.0f, 5.0f);

glColor3ub( 183, 183, 183); // hill

glVertex2f(5.0f, 5.0f);

glVertex2f(7.0f, 8.0f);

glVertex2f(9.0f, 5.0f);

glColor3ub(150,150,150); // hill

glVertex2f(3.0f, 5.0f);

glVertex2f(5.0f, 7.0f);

glVertex2f(7.0f, 5.0f);

glColor3ub( 183, 183, 183); // hill

glVertex2f(1.0f, 5.0f);

glVertex2f(3.0f, 8.0f);

glVertex2f(5.0f, 5.0f);


glColor3ub(150,150,150); // hill

glVertex2f(-1.0f, 5.0f);

glVertex2f(1.0f, 7.0f);

glVertex2f(3.0f, 5.0f);

glColor3ub( 183, 183, 183); // hill

glVertex2f(-3.0f, 5.0f);

glVertex2f(-1.0f, 8.0f);

glVertex2f(1.0f, 5.0f);

glColor3ub(150,150,150); // hill

glVertex2f(-5.0f, 5.0f);

glVertex2f(-3.0f, 7.0f);

glVertex2f(-1.0f, 5.0f);

glColor3ub( 183, 183, 183); // hill

glVertex2f(-7.0f, 5.0f);

glVertex2f(-5.0f, 8.0f);

glVertex2f(-3.0f, 5.0f);

glColor3ub(150,150,150); // hill

glVertex2f(-9.0f, 5.0f);

glVertex2f(-7.0f, 7.0f);

glVertex2f(-5.0f, 5.0f);


glColor3ub( 183, 183, 183); // hill

glVertex2f(-11.0f, 5.0f);

glVertex2f(-9.0f, 8.0f);

glVertex2f(-7.0f, 5.0f);


glColor3ub(150,150,150); // hill

glVertex2f(-13.0f, 5.0f);

glVertex2f(-11.0f, 7.0f);

glVertex2f(-9.0f, 5.0f);


glColor3ub( 183, 183, 183); // hill

glVertex2f(-15.0f, 5.0f);

glVertex2f(-13.0f, 8.0f);

glVertex2f(-11.0f, 5.0f);


glColor3ub(150,150,150); // hill

glVertex2f(-17.0f, 5.0f);

glVertex2f(-15.0f, 7.0f);

glVertex2f(-13.0f, 5.0f);


glColor3ub( 183, 183, 183); // hill

glVertex2f(-19.0f, 5.0f);

glVertex2f(-17.0f, 8.0f);

glVertex2f(-15.0f, 5.0f);

glEnd();

glPopMatrix();

glEnd();


glLineWidth(5.0f);

glBegin(GL_LINES);

glColor3ub( 255,255,255); // road line

glVertex2f(0.0f, -15.0f);

glVertex2f(0.0f, -12.0f);

glEnd();

glBegin(GL_LINES);

glColor3ub( 255,255,255); // road line

glVertex2f(0.0f, -11.0f);

glVertex2f(0.0f, -8.5f);

glEnd();

glBegin(GL_LINES);

glColor3ub( 255,255,255); // road line

glVertex2f(0.0f, -7.5f);

glVertex2f(0.0f, -5.5f);

glEnd();

glBegin(GL_TRIANGLES);

glColor3ub( 255,255,255); //road triangle

glVertex2f(0.0f, -6.0+0.4f);

glVertex2f(-1.5f, -3.0+0.4f);

glVertex2f(1.5f, -3.0+0.4f);


glEnd();



}


void stars() {

    glPointSize(2.0f);

    glBegin(GL_POINTS);

    glColor3ub(255, 255, 255); // White color for stars

    // Fixed set of stars

    glVertex2f(-10.0f, 13.0f);

    glVertex2f(5.0f, 11.0f);

    glVertex2f(-15.0f, 10.0f);

    glVertex2f(10.0f, 14.0f);

    glVertex2f(-5.0f, 12.0f);

    glVertex2f(0.0f, 13.5f);

    glVertex2f(15.0f, 11.0f);

    glVertex2f(20.0f, 12.0f);

    glVertex2f(-20.0f, 13.0f);

    glVertex2f(25.0f, 13.5f);

    glEnd();

}


void scene2(){

glClear(GL_COLOR_BUFFER_BIT);


glBegin(GL_POLYGON); //right arc1

glColor3ub(144, 109, 28 );

circle(25.0,27.0,-23.0);

glEnd();

glBegin(GL_LINES); //right arc1 border

glColor3ub(255,255,255 );

circle(25.0,26.5,-23.0);

glEnd();

glBegin(GL_POLYGON);   //right arc2

glColor3ub(26, 82, 118   );

circle(25.0,29.0,-23.0);

glEnd();


glBegin(GL_POLYGON);     //left arc1

glColor3ub(194, 169, 69 );

circle(25.0,-27.0,-23.0);

glEnd();

glBegin(GL_LINES);     //left arc1 border

glColor3ub(255,255,255);

circle(25.0,-26.5,-23.0);

glEnd();


glBegin(GL_POLYGON);    //left arc2

glColor3ub(26, 82, 118);

circle(25.0,-29.0,-23.0);

glEnd();


glBegin(GL_POLYGON); //upper arc

glColor3ub(26, 82, 118 );

circle(120.0,0.0,120.0);

glEnd();

/*glBegin(GL_LINE_LOOP); //upper arc road border

glColor3ub(255, 255, 255 );

circle(120.0,0.0,120.0);

glEnd();*/

glBegin(GL_POLYGON);//sky

glColor3ub(44, 62, 80 );

glVertex2f(-25.0f, 15.0f);

glVertex2f(-25.0f, 7.5f);

glVertex2f(25.0f, 7.5f);

glVertex2f(25.0f, 15.0f);

glEnd();


stars();


glBegin(GL_POLYGON); //upper arc

glColor3ub(255, 255, 255);//sun

circle(2.0,0.0,12.0);

glEnd();


glPushMatrix();

glTranslatef(move1,0.0f,0.0);

glBegin(GL_POLYGON);//cloud left

glColor3ub(86, 101, 115);

circle(2.0,-10.0,11.0);

glEnd();

glBegin(GL_POLYGON);

glColor3ub(86, 101, 115);

circle(1.5,-12.0,11.0);

glEnd();

glBegin(GL_POLYGON);

glColor3ub(86, 101, 115);

circle(1.5,-8.0,11.0);

glEnd();

glPopMatrix();


glPushMatrix();

glTranslatef(move1,0.0f,0.0);

glBegin(GL_POLYGON);//cloud right

glColor3ub(86, 101, 115);

circle(2.0,10.0,11.0);

glEnd();

glBegin(GL_POLYGON);

glColor3ub(86, 101, 115);

circle(1.5,12.0,11.0);

glEnd();

glBegin(GL_POLYGON);

glColor3ub(86, 101, 115);

circle(1.5,8.0,11.0);

glEnd();

glPopMatrix();

glPushMatrix();

glScalef(1.5f, 1.5f, 0.0f);

glBegin(GL_TRIANGLES); //hills

glColor3ub(150,150,150);

glVertex2f(15.0f, 5.0f);

glVertex2f(17.0f, 7.0f);

glVertex2f(19.0f, 5.0f);


glColor3ub( 183, 183, 183);

glVertex2f(13.0f, 5.0f);

glVertex2f(15.0f, 8.0f);

glVertex2f(17.0f, 5.0f);


glColor3ub(150,150,150); // Yellow

glVertex2f(11.0f, 5.0f);

glVertex2f(13.0f, 7.0f);

glVertex2f(15.0f, 5.0f);


glColor3ub( 183, 183, 183); // Yellow

glVertex2f(9.0f, 5.0f);

glVertex2f(11.0f, 8.0f);

glVertex2f(13.0f, 5.0f);


glColor3ub(150,150,150); // Yellow

glVertex2f(7.0f, 5.0f);

glVertex2f(9.0f, 7.0f);

glVertex2f(11.0f, 5.0f);

glColor3ub( 183, 183, 183); // Yellow

glVertex2f(5.0f, 5.0f);

glVertex2f(7.0f, 8.0f);

glVertex2f(9.0f, 5.0f);

glColor3ub(150,150,150); // Yellow

glVertex2f(3.0f, 5.0f);

glVertex2f(5.0f, 7.0f);

glVertex2f(7.0f, 5.0f);

glColor3ub( 183, 183, 183); // Yellow

glVertex2f(1.0f, 5.0f);

glVertex2f(3.0f, 8.0f);

glVertex2f(5.0f, 5.0f);


glColor3ub(150,150,150); // Yellow

glVertex2f(-1.0f, 5.0f);

glVertex2f(1.0f, 7.0f);

glVertex2f(3.0f, 5.0f);

glColor3ub( 183, 183, 183); // Yellow

glVertex2f(-3.0f, 5.0f);

glVertex2f(-1.0f, 8.0f);

glVertex2f(1.0f, 5.0f);

glColor3ub(150,150,150); // Yellow

glVertex2f(-5.0f, 5.0f);

glVertex2f(-3.0f, 7.0f);

glVertex2f(-1.0f, 5.0f);

glColor3ub( 183, 183, 183); // Yellow

glVertex2f(-7.0f, 5.0f);

glVertex2f(-5.0f, 8.0f);

glVertex2f(-3.0f, 5.0f);

glColor3ub(150,150,150); // Yellow

glVertex2f(-9.0f, 5.0f);

glVertex2f(-7.0f, 7.0f);

glVertex2f(-5.0f, 5.0f);


glColor3ub( 183, 183, 183); // Yellow

glVertex2f(-11.0f, 5.0f);

glVertex2f(-9.0f, 8.0f);

glVertex2f(-7.0f, 5.0f);


glColor3ub(150,150,150); // Yellow

glVertex2f(-13.0f, 5.0f);

glVertex2f(-11.0f, 7.0f);

glVertex2f(-9.0f, 5.0f);


glColor3ub( 183, 183, 183); // Yellow

glVertex2f(-15.0f, 5.0f);

glVertex2f(-13.0f, 8.0f);

glVertex2f(-11.0f, 5.0f);


glColor3ub(150,150,150); // Yellow

glVertex2f(-17.0f, 5.0f);

glVertex2f(-15.0f, 7.0f);

glVertex2f(-13.0f, 5.0f);


glColor3ub( 183, 183, 183); // Yellow

glVertex2f(-19.0f, 5.0f);

glVertex2f(-17.0f, 8.0f);

glVertex2f(-15.0f, 5.0f);

glEnd();

glPopMatrix();

glEnd();


glLineWidth(5.0f);

glBegin(GL_LINES);

glColor3ub( 255,255,255); // Yellow

glVertex2f(0.0f, -15.0f);

glVertex2f(0.0f, -12.0f);

glEnd();

glBegin(GL_LINES);

glColor3ub( 255,255,255); // road line

glVertex2f(0.0f, -11.0f);

glVertex2f(0.0f, -8.5f);

glEnd();

glBegin(GL_LINES);

glColor3ub( 255,255,255); // road line

glVertex2f(0.0f, -7.5f);

glVertex2f(0.0f, -5.5f);

glEnd();

glBegin(GL_TRIANGLES);

glColor3ub( 255,255,255); //road triangle

glVertex2f(0.0f, -6.0+0.4f);

glVertex2f(-1.5f, -3.0+0.4f);

glVertex2f(1.5f, -3.0+0.4f);


glEnd();




glutSwapBuffers();


}


void Boat() {

  glPushMatrix();

glTranslatef(0.0, 0.0, 0.0f);


glPushMatrix();

glTranslatef(boatX, boatY, 0.0f);

glBegin(GL_POLYGON);//boat 1

glColor3ub(109, 97, 10  );

glVertex2f(-20.0f, -10.0f);

glVertex2f(-18.8f, -11.0f);

glVertex2f(-16.3f, -11.0f);

glVertex2f(-15.0f, -10.0f);

glEnd();

glPopMatrix();

glPushMatrix();

glTranslatef(boatX, boatY, 0.0f);

glBegin(GL_TRIANGLES);

glColor3ub( 220, 177, 18   ) ; // Yellow

glVertex2f(-18.5f, -10.0f);

glVertex2f(-16.5f, -10.0f);

glVertex2f(-17.5f, -9.0f);

glEnd();

glPopMatrix();


glPushMatrix();

glTranslatef(boatX, boatY, 0.0f);

glBegin(GL_POLYGON);//boat 2

glColor3ub(64, 53, 9 );

glVertex2f(20.0f, -10.0f);

glVertex2f(18.8f, -11.0f);

glVertex2f(16.3f, -11.0f);

glVertex2f(15.0f, -10.0f);

glEnd();

glPopMatrix();


glPushMatrix();

glTranslatef(boatX, boatY, 0.0f);

glBegin(GL_TRIANGLES);

glColor3ub( 126, 105, 30 ); // Yellow

glVertex2f(18.5f, -10.0f);

glVertex2f(16.5f, -10.0f);

glVertex2f(17.5f, -9.0f);

glEnd();

glPopMatrix();


}

///Moon update

//    void update(int value) {
//
//        boatY -= 8.0f; // Move the boat to the right
//
//        if (boatY < -1.0f)
//
//            {
//
//            boatY > 1.0f; // Wrap around to the left when reaching the right edge
//
//            }
//
//        boatY = sin(glutGet(GLUT_ELAPSED_TIME) * 0.001) * 0.8;
//
//
//        boatX1 -= 8.0f; // Move the boat to the right
//
//        if (boatX1 < -25.0f)
//
//            {
//
//            boatX1 > 25.0f; // Wrap around to the left when reaching the right edge
//
//            }
//
//        boatX1 = sin(glutGet(GLUT_ELAPSED_TIME) * 0.0001) * 25.0;
//
//
//        move1 -= 5.0f; // Move the boat to the right
//
//        if (move1 < -1.0f)
//
//            {
//
//            move1 > 1.0f; // Wrap around to the left when reaching the right edge
//
//            }
//
//            move1 = sin(glutGet(GLUT_ELAPSED_TIME) * 0.0001) * 5.0;
//
//            elapsedTime += 25; // Time in milliseconds
//
//        if (elapsedTime >= 5000) {
//
//            currentScene = (currentScene == 1) ? 2 : 1; // Toggle between scene1 and scene2
//
//            elapsedTime = 0;
//
//        }
//
//        glutPostRedisplay();
//
//        glutTimerFunc(22, update, 0); // 60 frames per second
//
//    }

void tree1(){

    glPushMatrix();

    glTranslatef(0.0,-2.3,0.0);

    glScalef(15.0,15.0,1.0);


    glBegin(GL_QUADS);

    glColor3f(0.314, 0.184, 0.149);

    glVertex2f(0.73f, 0.19f);

    glVertex2f(0.744f, 0.472f);

    glVertex2f(0.754f, 0.472f);

    glVertex2f(0.764f, 0.19f);

    glVertex2f(0.738f, 0.255f);

    glVertex2f(0.736f, 0.274f);

    glVertex2f(0.684f, 0.303f);

    glVertex2f(0.680f, 0.298f);

    glVertex2f(0.759f, 0.303f);

    glVertex2f(0.759f, 0.319f);

    glVertex2f(0.815f, 0.350f);

    glVertex2f(0.824f, 0.347f);

    glEnd();

    glBegin(GL_TRIANGLES);

    glColor3f(0.314, 0.184, 0.149);

    glVertex2f(0.744f, 0.408f);

    glVertex2f(0.687f, 0.460f);

    glVertex2f(0.744f, 0.424f);

    glVertex2f(0.755f, 0.421f);

    glVertex2f(0.815f, 0.493f);

    glVertex2f(0.755f, 0.439f);

    glEnd();

///---------------Tree Leaf 1 -----------------


    glPushMatrix();

    glTranslatef(0.7,0.5,0.0);

    glScalef(0.15,0.15,1.0);

    glBegin(GL_POLYGON);

    glColor3f(0.549, 0.639, 0.153);

    circle(0.644,0.532,0.06);

    glColor3f(0.549, 0.639, 0.153);

    circle(0.644,0.477,0.05);

    glColor3f(0.647, 0.745, 0.184);

    circle(0.691,0.568,0.07);

    glColor3f(0.647, 0.745, 0.184);

    circle(0.771,0.563,0.06);

    glColor3f(0.694, 0.78, 0.294);

    circle(0.814,0.562,0.045);

    glColor3f(0.694, 0.78, 0.294);

    circle(0.835,0.543,0.05);

    glColor3f(0.694, 0.78, 0.294);

    circle(0.839,0.508,0.05);

    glColor3f(0.647, 0.745, 0.184);

    circle(0.749,0.457,0.06);

    glColor3f(0.694, 0.78, 0.294);

    circle(0.796,0.485,0.05);

    glColor3f(0.647, 0.745, 0.184);

    circle(0.709,0.442,0.05);

    glColor3f(0.647, 0.745, 0.184);

    circle(0.695,0.457,0.055);

    ///--------------- Tree leaf 2  ----------------

    glColor3f(0.549, 0.639, 0.153);

    circle(0.865,0.376,0.035);

    glColor3f(0.647, 0.745, 0.184);

    circle(0.896,0.390,0.025);

    glColor3f(0.694, 0.78, 0.294);

    circle(0.835,0.406,0.03);

    glColor3f(0.694, 0.78, 0.294);

    circle(0.802,0.384,0.03);

    glColor3f(0.549, 0.639, 0.153);

    circle(0.836,0.366,0.035);

    glColor3f(0.647, 0.745, 0.184);

    circle(0.881,0.408,0.03);


    ///------------------ Tree Leaf 3----------------------


    glTranslated(-0.18f,-0.055f,0.0f);

    glColor3f(0.549, 0.639, 0.153);

    circle(0.865,0.376,0.035);

    glColor3f(0.647, 0.745, 0.184);

    circle(0.896,0.390,0.025);

    glColor3f(0.694, 0.78, 0.294);

    circle(0.835,0.406,0.03);

    glColor3f(0.694, 0.78, 0.294);

    circle(0.802,0.384,0.03);

    glColor3f(0.549, 0.639, 0.153);

    circle(0.836,0.366,0.035);

    glColor3f(0.647, 0.745, 0.184);

    circle(0.881,0.408,0.03);

    glEnd();

    glPopMatrix();

    glPopMatrix();

    }


void tree2(){

    glPushMatrix();

    glTranslatef(-23.0,-2.2,0.0);

    glScalef(15.0,15.0,1.0);


    glBegin(GL_QUADS);

    glColor3f(0.314, 0.184, 0.149);

    glVertex2f(0.73f, 0.19f);

    glVertex2f(0.744f, 0.472f);

    glVertex2f(0.754f, 0.472f);

    glVertex2f(0.764f, 0.19f);

    glVertex2f(0.738f, 0.255f);

    glVertex2f(0.736f, 0.274f);

    glVertex2f(0.684f, 0.303f);

    glVertex2f(0.680f, 0.298f);

    glVertex2f(0.759f, 0.303f);

    glVertex2f(0.759f, 0.319f);

    glVertex2f(0.815f, 0.350f);

    glVertex2f(0.824f, 0.347f);

    glEnd();

    glBegin(GL_TRIANGLES);

    glColor3f(0.314, 0.184, 0.149);

    glVertex2f(0.744f, 0.408f);

    glVertex2f(0.687f, 0.460f);

    glVertex2f(0.744f, 0.424f);

    glVertex2f(0.755f, 0.421f);

    glVertex2f(0.815f, 0.493f);

    glVertex2f(0.755f, 0.439f);

    glEnd();

///---------------Tree Leaf 1 -----------------


    glPushMatrix();

    glTranslatef(0.7,0.5,0.0);

    glScalef(0.15,0.15,1.0);

    glBegin(GL_POLYGON);

    glColor3f(0.549, 0.639, 0.153);

    circle(0.644,0.532,0.06);

    glColor3f(0.549, 0.639, 0.153);

    circle(0.644,0.477,0.05);

    glColor3f(0.647, 0.745, 0.184);

    circle(0.691,0.568,0.07);

    glColor3f(0.647, 0.745, 0.184);

    circle(0.771,0.563,0.06);

    glColor3f(0.694, 0.78, 0.294);

    circle(0.814,0.562,0.045);

    glColor3f(0.694, 0.78, 0.294);

    circle(0.835,0.543,0.05);

    glColor3f(0.694, 0.78, 0.294);

    circle(0.839,0.508,0.05);

    glColor3f(0.647, 0.745, 0.184);

    circle(0.749,0.457,0.06);

    glColor3f(0.694, 0.78, 0.294);

    circle(0.796,0.485,0.05);

    glColor3f(0.647, 0.745, 0.184);

    circle(0.709,0.442,0.05);

    glColor3f(0.647, 0.745, 0.184);

    circle(0.695,0.457,0.055);

    ///--------------- Tree leaf 2  ----------------

    glColor3f(0.549, 0.639, 0.153);

    circle(0.865,0.376,0.035);

    glColor3f(0.647, 0.745, 0.184);

    circle(0.896,0.390,0.025);

    glColor3f(0.694, 0.78, 0.294);

    circle(0.835,0.406,0.03);

    glColor3f(0.694, 0.78, 0.294);

    circle(0.802,0.384,0.03);

    glColor3f(0.549, 0.639, 0.153);

    circle(0.836,0.366,0.035);

    glColor3f(0.647, 0.745, 0.184);

    circle(0.881,0.408,0.03);


    ///------------------ Tree Leaf 3----------------------


    glTranslated(-0.18f,-0.055f,0.0f);

    glColor3f(0.549, 0.639, 0.153);

    circle(0.865,0.376,0.035);

    glColor3f(0.647, 0.745, 0.184);

    circle(0.896,0.390,0.025);

    glColor3f(0.694, 0.78, 0.294);

    circle(0.835,0.406,0.03);

    glColor3f(0.694, 0.78, 0.294);

    circle(0.802,0.384,0.03);

    glColor3f(0.549, 0.639, 0.153);

    circle(0.836,0.366,0.035);

    glColor3f(0.647, 0.745, 0.184);

    circle(0.881,0.408,0.03);

    glEnd();

    glPopMatrix();

    glPopMatrix();

    }

void boatGhat(){

glPushMatrix();

glScalef(0.7f,0.7f,1.0f);

glTranslatef(12.0f, 12.0f, 0.0f);


glBegin(GL_POLYGON);//stand boat 1

glColor3ub(114, 55, 5  );

glVertex2f(-20.0f, -10.0f);

glVertex2f(-18.8f, -11.0f);

glVertex2f(-16.3f, -11.0f);

glVertex2f(-15.0f, -10.0f);

glEnd();

glBegin(GL_TRIANGLES);

glColor3ub( 165, 129, 99 ); // Yellow

glVertex2f(-18.5f, -10.0f);

glVertex2f(-16.5f, -10.0f);

glVertex2f(-17.5f, -9.0f);

glEnd();

glPopMatrix();


glPushMatrix();

glScalef(0.7f,0.7f,1.0f);

glTranslatef(18.0f, 12.0f, 0.0f);


glBegin(GL_POLYGON);//stand boat 2

glColor3ub(109, 96, 47  );

glVertex2f(-20.0f, -10.0f);

glVertex2f(-18.8f, -11.0f);

glVertex2f(-16.3f, -11.0f);

glVertex2f(-15.0f, -10.0f);

glEnd();

glBegin(GL_TRIANGLES);

glColor3ub( 183, 183, 183); // Yellow

glVertex2f(-18.5f, -10.0f);

glVertex2f(-16.5f, -10.0f);

glVertex2f(-17.5f, -9.0f);

glEnd();

glPopMatrix();


glPushMatrix();

glScalef(0.7f,0.7f,1.0f);

glTranslatef(24.0f, 12.0f, 0.0f);

glBegin(GL_POLYGON);//stand boat 3

glColor3ub(114, 55, 5);

glVertex2f(-20.0f, -10.0f);

glVertex2f(-18.8f, -11.0f);

glVertex2f(-16.3f, -11.0f);

glVertex2f(-15.0f, -10.0f);

glEnd();

glBegin(GL_TRIANGLES);

glColor3ub( 165, 129, 99); // Yellow

glVertex2f(-18.5f, -10.0f);

glVertex2f(-16.5f, -10.0f);

glVertex2f(-17.5f, -9.0f);

glEnd();

glPopMatrix();


glLineWidth(2.0f);

glBegin(GL_LINES);//boat stand1

glColor3ub(0,0,0);

glVertex2f(2.5f, 0.0f);

glVertex2f(2.5f, 3.5f);

glEnd();

glLineWidth(2.0f);

glBegin(GL_LINES);//boat stand2

glColor3ub(0,0,0);

glVertex2f(-1.5f, 0.0f);

glVertex2f(-1.5f, 3.5f);

glEnd();


glLineWidth(2.0f);

glBegin(GL_LINES);//boat stand3

glColor3ub(0,0,0);

glVertex2f(-6.0f, 0.0f);

glVertex2f(-6.0f, 3.5f);

glEnd();


glLineWidth(5.0f);

glBegin(GL_LINES);//stand1

glColor3ub(0,0,0);

glVertex2f(-8.0f, 0.2f);

glVertex2f(-8.0f, 6.5f);

glEnd();


glLineWidth(5.0f);

glBegin(GL_LINES);//stand2

glColor3ub(0,0,0);

glVertex2f(8.0f, 0.2f);

glVertex2f(8.0f, 6.5f);

glEnd();


glBegin(GL_POLYGON);//banner

glColor3ub(111, 79, 6);

glVertex2f(-8.0f, 6.5f);

glVertex2f(-8.0f, 4.5f);

glVertex2f(8.0f, 4.5f);

glVertex2f(8.0f, 6.5f);

Sprint(0.0,0,text);

glEnd();


}

void ship(){

//upper boat

glPushMatrix();

glTranslatef(boatX1, boatY1, 0.0f);

glBegin(GL_POLYGON);//base

glColor3ub(44, 62, 80);

glVertex2f(-2.5f, 6.0f);

glVertex2f(-1.2f, 5.0f);

glVertex2f(1.2f, 5.0f);

glVertex2f(2.5f, 6.0f);

glEnd();

glBegin(GL_POLYGON);//middle

glColor3ub(69, 179, 157);

glVertex2f(-1.5f, 6.5f);

glVertex2f(-1.5f, 6.0f);

glVertex2f(1.5f, 6.0f);

glVertex2f(1.5f, 6.5f);

glEnd();

glBegin(GL_POLYGON);//up

glColor3ub(93, 173, 226);

glVertex2f(-1.2f, 7.0f);

glVertex2f(-1.2f, 6.5f);

glVertex2f(1.2f, 6.5f);

glVertex2f(1.2f, 7.0f);

glEnd();


glLineWidth(2.0f);

glBegin(GL_LINES);//flag stand

glColor3ub(0,0,0);

glVertex2f(1.0f, 7.0f);

glVertex2f(1.0f, 8.5f);

glEnd();


glBegin(GL_POLYGON);//flag

glColor3ub(25, 111, 61);

glVertex2f(-0.5f, 8.5f);

glVertex2f(-0.5f, 7.8f);

glVertex2f(1.0f, 7.8f);

glVertex2f(1.0f, 8.5f);

glEnd();

glBegin(GL_POLYGON); //flag circle

glColor3ub(251, 32, 32 );

circle(0.2,0.3,8.1);

glEnd();


glPopMatrix();



}


void snow() {

    if (isSnowing) {

        glPointSize(5.0f);

    glBegin(GL_POINTS);

    glColor3ub(255, 255, 255);


    for (int i = 0; i < 100; i++) {

        float x = static_cast<float>(rand() % 50 - 25);

        float y = static_cast<float>(rand() % 50 - 25);

        glVertex2f(x, y);

    }

    glEnd();

//    Sleep(100);

}

}


void keyPressed(unsigned char key, int x, int y) {

    if (key == 's' || key == 'S') {

        isSnowing = !isSnowing;

    }

}

////moon dsplay

//    void display() {
//
//       glClear(GL_COLOR_BUFFER_BIT);
//
//        scene1();
//
//        scene2();
//
//        if (currentScene == 1) {
//
//          scene1();
//
//       } else if (currentScene == 2) {
//
//          scene2();
//
//       }
//
//        ship();
//
//        boatGhat();
//
//        Boat();
//
//        tree1();
//
//        tree2();
//
//        snow();
//
//
//        glFlush();
//
//        glutSwapBuffers();
//
//    }

/////--------RIAD---------/////////


//Circle
void circle(float radius, float xc, float yc, float r, float g, float b)
{
glBegin(GL_POLYGON);
for(int i=0;i<200;i++)
    {
        glColor3f(r,g,b);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=radius;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+xc,y+yc);
    }
glEnd();
}



//For Cresent moon
void drawCircle(float radius, float x, float y, int segments) {
glBegin(GL_TRIANGLE_FAN);
glColor3ub(171,171,171);
glVertex2f(x, y); // Center of the circle
for (int i = 0; i <= segments; ++i) {
    float theta = 2.0f * M_PI * static_cast<float>(i) / static_cast<float>(segments);
    float dx = radius * cos(theta);
    float dy = radius * sin(theta);
    glVertex2f(x + dx, y + dy);
}
glEnd();
}



//**Road

///Draw Road Area-- RA
void drawRoad() {
glColor3f(0.29f, 0.31f, 0.35f);  // Gray road color
glBegin(GL_QUADS);
glVertex2f(-4.0f, -10.0f);
glVertex2f(4.0f, -10.0f);

glVertex2f(4.0f, -10.0f);
glVertex2f(1.0f, 8.0f);


glVertex2f(1.0f, 8.0f);
glVertex2f(-1.0f, 8.0f);

glVertex2f(-1.0f, 8.0f);
glVertex2f(-4.0f, -10.20f);


glEnd();
}



//Road Line -- RL
void drawRoadLine()
{
glColor3f(1.0f, 1.0f, 1.0f);
glLineWidth(5.0);
glBegin(GL_LINES);

//Right Side
glVertex2f(3.7f, -10.0f);
glVertex2f(0.7f,8.0f);

//Left Side
glVertex2f(-3.7f, -10.0f);
glVertex2f(-0.7f,8.0f);

//Middle
glVertex2f(0.0f, -10.0f);
glVertex2f(0.0f,-9.0f);

glVertex2f(0.0f, -8.5f);
glVertex2f(0.0f,-7.5f);

glVertex2f(0.0f, -7.0f);
glVertex2f(0.0f,-6.0f);

glVertex2f(0.0f, -5.5f);
glVertex2f(0.0f,-4.5f);

glVertex2f(0.0f, -4.0f);
glVertex2f(0.0f,-3.0f);

glVertex2f(0.0f, -2.5f);
glVertex2f(0.0f,-1.5f);

glVertex2f(0.0f, -1.0f);
glVertex2f(0.0f,0.0f);

glVertex2f(0.0f, 0.5f);
glVertex2f(0.0f,1.5f);

glVertex2f(0.0f, 2.0f);
glVertex2f(0.0f,3.0f);


glVertex2f(0.0f,3.5f);
glVertex2f(0.0f, 4.0f);

glVertex2f(0.0f,4.5f);
glVertex2f(0.0f, 5.5f);

glVertex2f(0.0f,6.0f);
glVertex2f(0.0f, 7.0f);

glVertex2f(0.0f,7.5f);
glVertex2f(0.0f, 8.0f);

glEnd();




}

////Lamp post for road side--For Day

void Lamp_post_day()
{
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glLineWidth(5.0);
glVertex2f(-4.0f, -10.0f);
glVertex2f(-4.5f, -10.0f);
glEnd();

}

void drawTransparentSquare() {
// Enable blending for transparency
glEnable(GL_BLEND);
glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

// Draw a transparent square
glColor4f(109/255,109/255,109/255,0.25);  // Red color with 50% transparency
glBegin(GL_QUADS);
glVertex2f(-1.39f, 5.67f);
glVertex2f(1.41f, 5.62f);
glVertex2f(1.19f, 7.0f);
glVertex2f(-1.19, 7.0f);
glEnd();

// Disable blending after drawing
glDisable(GL_BLEND);
}





//void TRIANGLES () {
//    glColor3f(0.0f, 0.8f, 0.0f);  // Green hills color
//    glBegin(GL_TRIANGLES);
//    glVertex2f(-1.0f, -0.2f);
//    glVertex2f(0.0f, 0.8f);
//    glVertex2f(1.0f, -0.2f);
//    glEnd();
//}



//Big Boat - BB1

void Boatt()
{
glPushMatrix();
glTranslatef(0.0, 0.0, 0.0f);
glPushMatrix();

glTranslatef(boatX, boatY, 0.0f);

glBegin(GL_POLYGON);//boat 1
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(4.38f,-3.55f);
glVertex2f(4.95f,-4.01f);
glVertex2f(7.45f,-4.0f);
glVertex2f(8.0f,-3.3f);
glVertex2f(4.38f,-3.55f);
glEnd();

glPopMatrix();
glPushMatrix();
glTranslatef(boatX, boatY, 0.0f);

glBegin(GL_LINES);
glColor3f(1.0f, 0.0f, 0.0f);
glVertex2f(6.70f,-3.45);
glVertex2f(6.70f,-1.69f);
glEnd();
glPopMatrix();


glPushMatrix();
glTranslatef(boatX, boatY, 0.0f);
glBegin(GL_POLYGON);
glColor3f(1.0f, 0.0f, 0.0f);
glVertex2f(4.77f,-3.28f);
glVertex2f(6.70f,-3.45);
glVertex2f(6.70f,-1.69f);
glEnd();
glPopMatrix();


glPushMatrix();
glTranslatef(boatX, boatY, 0.0f);
glBegin(GL_POLYGON);
glColor3f(0.0f, 1.0f, 0.0f);
glVertex2f(6.70f,-3.45f);
glVertex2f(7.84f,-3.4f);
glVertex2f(6.70f,-2.06f);
glVertex2f(7.18f,-3.10f);
glVertex2f(6.70f,-3.45f);
glEnd();
glPopMatrix();

//Boat Ghat
glBegin(GL_QUADS);

glColor3f(0.66f, 0.65f, 0.59f);
glVertex2f(2.65f,-1.90f);
glVertex2f(3.13f,-4.63f);
glVertex2f(3.53f,-4.59f);
glVertex2f(2.87f,-1.78f);
glVertex2f(2.65f,-1.90f);

glEnd();

drawText(3.20f,-5.00f,"Boat Ghat",0.0f,0.0f,0.0f);

//Boat Ghat Lamp post

glBegin(GL_LINES);
glColor3f(1.0f, 0.27f, 0.0f);
glLineWidth(5);
glVertex2f(3.5f, -6.30f);
glVertex2f(4.03f, -8.99f);
glEnd();

//Light Box
//    glBegin(GL_POLYGON);
//    glColor3f(1.0f, 1.0f, 1.0f);
//
//    glVertex2f(3.52f, -6.82f);
//    glVertex2f(3.74f, -6.70f);
//    glVertex2f(3.71f, -6.12f);
//    glVertex2f(3.36f, -6.27f);

glEnd();


}

void miniBoat()
{

//left runing mini boat
glPushMatrix();
glTranslatef(0.0, 0.0, 0.0f);
glPushMatrix();
glTranslatef(boatX1, boatY1, 0.0f);

glBegin(GL_POLYGON);//lb 1
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(1.23f,6.50f);
glVertex2f(1.80f,5.80f);
glVertex2f(3.15f,5.80f);
glVertex2f(3.80f,6.50f);
glEnd();
glPopMatrix();


glPushMatrix();

glTranslatef(boatX1, boatY1, 0.0f);

glBegin(GL_POLYGON);//lb 1
glColor3f(1.0f, 1.0f, 1.0f);

glVertex2f(2.12f,6.15f);
glVertex2f(3.04f,6.15f);
glVertex2f(3.04f,6.75f);
glVertex2f(2.12f,6.75f);
glEnd();
glPopMatrix();




//left down mini boat
//    glPushMatrix();
//    glTranslatef(boatX1, boatY1, 0.0f);
//
//    glBegin(GL_LINES);
//    glColor3f(1.0f, 0.0f, 0.0f);
//    glVertex2f(6.70f,-3.45);
//    glVertex2f(6.70f,-1.69f);
//    glEnd();
//    glPopMatrix();

glEnd();
}


//Hills

void Hill()

{
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(10);
    glVertex2f(-10.0f, 7.0f);
    glVertex2f(10.0f, 7.0f);
    
    glEnd();
    
    //Hill -1
    glBegin(GL_TRIANGLES);
    glColor3ub(37,89,31); //Dark Green
    glVertex2f(-10.0f, 7.0f);
    glVertex2f(-8.0f, 7.0f);
    glVertex2f(-9.5f, 8.5f);
    glEnd();
    
    //Hill-2
    glBegin(GL_TRIANGLES);
    glColor3ub(129,140,60); //Light Yellow
    glVertex2f(-8.5f, 7.0f);
    glVertex2f(-6.5f, 7.0f);
    glVertex2f(-7.2f, 9.5f);
    glEnd();
    
    //Hill-3
    glBegin(GL_TRIANGLES);
    glColor3ub(37,89,31); //Dark Green
    glVertex2f(-7.0f, 7.0f);
    glVertex2f(-6.0f, 7.0f);
    glVertex2f(-6.5f, 8.5f);
    glEnd();
    
    
    //Hill-4
    glBegin(GL_TRIANGLES);
    glColor3ub(0,153,31); //Natural Green
    glVertex2f(-6.5f, 7.0f);
    glVertex2f(-5.5f, 7.0f);
    glVertex2f(-6.1f, 8.5f);
    glEnd();
    
    
    //Hill-5
    glBegin(GL_TRIANGLES);
    glColor3ub(37,89,31); //Dark Green
    glVertex2f(-5.5f, 7.0f);
    glVertex2f(-4.0f, 7.0f);
    glVertex2f(-5.0f, 8.5f);
    glEnd();
    
    //Hill-6
    glBegin(GL_TRIANGLES);
    glColor3ub(129,140,60); //Light Yellow
    glVertex2f(-4.5f, 7.0f);
    glVertex2f(-2.0f, 7.0f);
    glVertex2f(-3.0f, 8.5f);
    glEnd();
    
    //Hill-7
    glBegin(GL_TRIANGLES);
    glColor3ub(214,222,167); // Gray
    glVertex2f(-3.0f, 7.0f);
    glVertex2f(-1.0f, 7.0f);
    glVertex2f(-2.2f, 8.5f);
    glEnd();
    
    
    //Hill-8
    glBegin(GL_TRIANGLES);
    glColor3ub(37,89,31); //Dark Green
    glVertex2f(-2.0f, 7.0f);
    glVertex2f(1.0f, 7.0f);
    glVertex2f(-0.7f, 9.5f);
    glEnd();
    
    
    //Hill-9
    glBegin(GL_TRIANGLES);
    glColor3ub(214,222,167); // Gray
    glVertex2f(-1.5f, 7.0f);
    glVertex2f(3.0f, 7.0f);
    glVertex2f(1.0f, 9.0f);
    glEnd();
    
    
    //Hill-10
    glBegin(GL_TRIANGLES);
    glColor3ub(129,140,60); //Light Yellow
    glVertex2f(2.5f, 7.0f);
    glVertex2f(4.0f, 7.0f);
    glVertex2f(3.0f, 9.0f);
    glEnd();
    
    //Hill-10
    glBegin(GL_TRIANGLES);
    glColor3ub(0,153,31); //Natural Green
    glVertex2f(3.8f, 7.0f);
    glVertex2f(5.0f, 7.0f);
    glVertex2f(4.5f, 9.0f);
    glEnd();
    
    //Hill-11
    glBegin(GL_TRIANGLES);
    glColor3ub(37,89,31); //Dark Green
    glVertex2f(4.8f, 7.0f);
    glVertex2f(6.0f, 7.0f);
    glVertex2f(5.5f, 9.0f);
    glEnd();
    
    //Hill-12
    glBegin(GL_TRIANGLES);
    glColor3ub(129,140,60); //Light Yellow
    glVertex2f(5.5f, 7.0f);
    glVertex2f(7.0f, 7.0f);
    glVertex2f(6.5f, 9.0f);
    glEnd();
    
    //Hill-13
    glBegin(GL_TRIANGLES);
    glColor3ub(37,89,31); //Dark Green
    glVertex2f(6.5f, 7.0f);
    glVertex2f(8.5f, 7.0f);
    glVertex2f(8.0f, 9.0f);
    glEnd();
    
    //Hill-14
    glBegin(GL_TRIANGLES);
    glColor3ub(214,222,167); // Gray
    glVertex2f(7.8f, 7.0f);
    glVertex2f(10.0f, 7.0f);
    glVertex2f(8.5f, 9.0f);
    glEnd();
    
    
}


//For night Cresent moon

void CresentMOON()
{
    drawCircle(0.2, -6.0, 8.8, 50);

    drawCircle(0.5, -5.8, 8.8, 50);
}

//For Night
void sunN()
{
glBegin(GL_POLYGON);

glColor3ub(255, 255, 0);//sun

circle(0.5,-4.0,8.8);

glEnd();
}

//For Day+Sunny
void sunS()
{
glBegin(GL_POLYGON);

glColor3ub(255, 255, 0);//sun

circle(0.5,-4.0,8.8,255/255, 255/255, 0/255);

glEnd();
}

//cloud for rainy
void cloudr(){
glPushMatrix();

glTranslatef(move2,0.0f,0.0);

glBegin(GL_POLYGON);//cloud right

glColor3ub(171,171,171);

circle(2.0,10.0,11.0,171/255,171/255,171/255);

glEnd();

glBegin(GL_POLYGON);

glColor3ub(171,171,171);

circle(1.5,12.0,11.0,171/255,171/255,171/255);

glEnd();

glBegin(GL_POLYGON);

glColor3ub(171,171,171);
circle(1.5,8.0,11.0,171/255,171/255,171/255);

glEnd();

glPopMatrix();
}



//cloud For sunny
void clouds(){
glPushMatrix();

glTranslatef(move1,0.0f,0.0);

glBegin(GL_POLYGON);//cloud right

glColor3ub(255, 255,255);

circle(2.0,10.0,11.0);

glEnd();

glBegin(GL_POLYGON);

glColor3ub(255, 255,255);

circle(1.5,12.0,11.0);

glEnd();

glBegin(GL_POLYGON);

glColor3ub(255, 255,255);

circle(1.5,8.0,11.0);

glEnd();

glPopMatrix();
}


//void rain()
//{
//    if (isRaining) {
//
//
//    }
//}

//Rain drops

//void mouseClick(int button, int state, int x, int y) {
//    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
//        isRaining = !isRaining; // Toggle rain on left mouse click
//    }
//}




void car() {
glPushMatrix();
float perspectiveScale = 1.0f - 0.08f * carY;

glTranslatef(carX, carY, 0.0f);
glScalef(perspectiveScale, perspectiveScale, 1.0f);

//  car
glPushMatrix();
glScalef(0.8, 0.5, 0.0f);

glBegin(GL_POLYGON);
glColor3ub(255, 120, 0); // Red color for the car
circle(0.5,0.0,0.0);
glEnd();




glBegin(GL_POLYGON);
glColor3ub(0, 0, 0); // Red color for the car
glVertex2f(-1.1f, -0.0f);
glVertex2f(-1.1f, -2.0f);
glVertex2f(1.1f, -2.0f);
glVertex2f(1.1f, -0.0f);
glEnd();


//wheel

 glBegin(GL_POLYGON);
glColor3f(1.0f, 0.0f, 0.0f);
glVertex2f(-0.80f, -2.5f);
glVertex2f(-0.60f, -2.5f);
glVertex2f(-0.60f, -2.0f);
glVertex2f(-0.80f, -2.0f);
glEnd();

glBegin(GL_POLYGON);
glColor3f(1.0f, 0.0f, 0.0f);
glVertex2f(0.80f, -2.5f);
glVertex2f(0.60f, -2.5f);
glVertex2f(0.60f, -2.0f);
glVertex2f(0.80f, -2.0f);
glEnd();


glPopMatrix();

glPopMatrix();


glPopMatrix();

glFlush();
}

void updateCar() {
carY += 0.05f; // Move the car to the right

if (carY > 8.0f) {
    carY = -20.0f; // Wrap around to the left when reaching the right edge
}


}


//Car going on Rainy day
void carR() {
glPushMatrix();
float perspectiveScale = 1.0f - 0.08f * carY1;

glTranslatef(carX1, carY1, 0.0f);
glScalef(perspectiveScale, perspectiveScale, 1.0f);

//  car
glPushMatrix();
glScalef(0.8, 0.5, 0.0f);

glBegin(GL_POLYGON);
glColor3ub(255, 120, 0); // Red color for the car
circle(0.5,0.0,0.0);
glEnd();




glBegin(GL_POLYGON);
glColor3ub(0, 0, 0); // Red color for the car
glVertex2f(-1.1f, -0.0f);
glVertex2f(-1.1f, -2.0f);
glVertex2f(1.1f, -2.0f);
glVertex2f(1.1f, -0.0f);
glEnd();


//wheel

 glBegin(GL_POLYGON);
glColor3f(1.0f, 0.0f, 0.0f);
glVertex2f(-0.80f, -2.5f);
glVertex2f(-0.60f, -2.5f);
glVertex2f(-0.60f, -2.0f);
glVertex2f(-0.80f, -2.0f);
glEnd();

glBegin(GL_POLYGON);
glColor3f(1.0f, 0.0f, 0.0f);
glVertex2f(0.80f, -2.5f);
glVertex2f(0.60f, -2.5f);
glVertex2f(0.60f, -2.0f);
glVertex2f(0.80f, -2.0f);
glEnd();


glPopMatrix();

glPopMatrix();


glPopMatrix();

glFlush();
}


//For rainy day
void updateCarR() {
carY1 += 0.05f; // Move the car to the right

if (carY1 > 5.62f) {
    carY1 = -20.0f; // Wrap around to the left when reaching the right edge
}


}




void update(int value) {


//moon update-1

boatY -= 8.0f; // Move the boat to the right

if (boatY < -1.0f)

    {

    boatY > 1.0f; // Wrap around to the left when reaching the right edge

    }

boatY = sin(glutGet(GLUT_ELAPSED_TIME) * 0.001) * 0.8;


boatX1 -= 8.0f; // Move the boat to the right

if (boatX1 < -25.0f)

    {

    boatX1 > 25.0f; // Wrap around to the left when reaching the right edge

    }

boatX1 = sin(glutGet(GLUT_ELAPSED_TIME) * 0.0001) * 25.0;


move1 -= 5.0f; // Move the boat to the right

if (move1 < -1.0f)

    {

    move1 > 1.0f; // Wrap around to the left when reaching the right edge

    }

    move1 = sin(glutGet(GLUT_ELAPSED_TIME) * 0.0001) * 5.0;

    elapsedTime += 25; // Time in milliseconds

if (elapsedTime >= 5000) {

    currentScene = (currentScene == 1) ? 2 : 1; // Toggle between scene1 and scene2

    elapsedTime = 0;

}

glutPostRedisplay();

glutTimerFunc(22, update, 0); // 60 frames per second



boatX -= 0.0f; // Move the boat to the right

if (boatX < -8.0f)

    {

    boatX > 10.0f; // Wrap around to the left when reaching the right edge

    }

boatX = sin(glutGet(GLUT_ELAPSED_TIME) * 0.001) * 0.5f;

/////mini boat
boatX1 -= 0.0f; // Move the boat to the right

if (boatX1 < -8.0f)

    {

    boatX1 > 10.0f; // Wrap around to the left when reaching the right edge

    }

boatX1 = sin(glutGet(GLUT_ELAPSED_TIME) * 0.0001) * 0.0f;

///
    elapsedTime += 35; // Time in milliseconds

if (elapsedTime >= 5000) {

    currentScene = (currentScene == 1) ? 2 : 1; // Toggle between scene1 and scene2

    elapsedTime = 0;

}

//Sunny
if (move1 < 10.0f)

    {

    move1 > 10.0f; // Wrap around to the left when reaching the right edge

    }

    move1 = sin(glutGet(GLUT_ELAPSED_TIME) * 0.0001) * -10.0;

//Rainy

if (move2 < 15.0f)

    {

    move2 > 20.0f; // Wrap around to the left when reaching the right edge

    }

    move2 = sin(glutGet(GLUT_ELAPSED_TIME) * 0.0001) *-25.0;


//mini boat
if (boatX1 < 15.0f)

    {

    boatX1> 20.0f; // Wrap around to the left when reaching the right edge

    }

boatX1 = sin(glutGet(GLUT_ELAPSED_TIME) * 0.001) *10.0;

updateCar();
updateCarR();


glutPostRedisplay();

glutTimerFunc(22, update, 0); // 60 frames per second

}




void display() {
glClear(GL_COLOR_BUFFER_BIT);



if(ismoon)
{
    
    ///moon display
    ///
    
    scene1();
    
    scene2();
    
    if (currentScene == 1) {
        
        scene1();
        
    } else if (currentScene == 2) {
        
        scene2();
        
    }
    
    ship();
    
    boatGhat();
    
    Boat();
    
    tree1();
    
    tree2();
    
    snow();
    glutSwapBuffers();
    
}
else{
    
    if(israin)
    {
        //Window color for rainy day
        
        glBegin(GL_QUADS);
        glColor3ub(109,109,109);
        glVertex2f(-10.0f, -10.0f);
        glVertex2f(10.0f,-10.0f);
        glVertex2f(10.0f, 10.0f);
        glVertex2f(-10.0f,10.0f);
        glEnd();
        
        //Rain drops
        glLineWidth(1.0f);
        glBegin(GL_LINES);
        glColor3ub(173, 216, 230); // light blue color for raindrops
        for (int i = 0; i < 500; ++i) {
            float x = static_cast<float>(rand() % 50 - 25);
            float y = static_cast<float>(rand() % 50 - 25);
            glVertex2f(x, y);
            glVertex2f(x, y - 0.2f); // Draw ra short line as a raindrop
            
        }
        
        glEnd();
        
        cloudr();
        CresentMOON();
        miniBoat();
        Boat();
        drawTransparentSquare();
        drawRoad();
        drawRoadLine();
        
        glutSwapBuffers();

    }
    else
    {
        
        sunS();
        clouds();
        car();
        //window
        glBegin(GL_QUADS);
        glColor3ub(0,255,0);
        glVertex2f(-10.0f, -10.0f);
        glVertex2f(10.0f,-10.0f);
        glVertex2f(10.0f, 7.0f);
        glVertex2f(-10.0f,7.0f);
        glEnd();
        
        //Green Field
        
        //Left--1
        glBegin(GL_QUADS);
        glColor3ub(65,147,94);
        glVertex2f(-10.0f, -10.0f);
        glVertex2f(-4.5f,-10.0f);
        glVertex2f(-3.65f, -4.97f);
        glVertex2f(-10.0f,-4.97f);
        glEnd();
        
        //Left--2
        glBegin(GL_QUADS);
        glColor3ub(65,147,94);
        glVertex2f(-10.0f, -4.5f);
        glVertex2f(-3.65f,-4.5f);
        glVertex2f(-2.80f, -0.5f);
        glVertex2f(-10.0f,-0.5f);
        glEnd();
        
        //Left--3
        glBegin(GL_QUADS);
        glColor3ub(65,147,94);
        glVertex2f(-10.0f, -0.0f);
        glVertex2f(-2.7f,0.0f);
        glVertex2f(-1.5f, 7.0f);
        glVertex2f(-10.0f,7.0f);
        glEnd();
        
        //Right Field-1
        glBegin(GL_QUADS);
        glColor3ub(65,147,94);
        glVertex2f(4.3f, -10.0f);
        glVertex2f(10.0f,-10.0f);
        glVertex2f(10.0f, -5.0f);
        glVertex2f(3.5f,-5.0f);
        glEnd();
        
        //Right Field-2
        glBegin(GL_QUADS);
        glColor3ub(65,147,94);
        glVertex2f(3.4f, -4.4f);
        glVertex2f(10.0f,-4.8f);
        glVertex2f(10.0f, 2.2f);
        glVertex2f(2.7f, -0.6f);
        glEnd();
        
        //Right Field-3
        glBegin(GL_QUADS);
        glColor3ub(65,147,94);
        glVertex2f(2.7f, -0.2f);
        glVertex2f(10.0f,3.0f);
        glVertex2f(10.0f, 7.0f);
        glVertex2f(1.39f, 7.0f);
        glEnd();
        
        drawRoad();
        drawRoadLine();
        // drawTransparentSquare();
    }
    
    
    
    
    
    Hill();
    //  drawTransparentSquare();
    carR();
    
    
    
    
    // Lamp_post_day();
    //    sun();
    //    cloud();
    glutSwapBuffers();

}
glutSwapBuffers();

}

int main(int argc, char** argv) {

glutInit(&argc, argv); // Initialize GLUT

glutInitWindowSize(1200,1000); // Set the window's initial width & height

glutCreateWindow("Computer Graphic "); // Create window with the given title

glutInitWindowPosition(50, 50); // Position the window's initial top-left corner

glutKeyboardFunc(keyPressed);

glutDisplayFunc(display); // Register callback handler for window re-paint event

gluOrtho2D(-25,25,-15,15);

initGL(); // Our own OpenGL initialization

glutTimerFunc(25, update, 0); // Set up the timer for animation

glutMainLoop(); // Enter the event-processing loop
    glutKeyboardFunc(keyboard);

return 0;

}
