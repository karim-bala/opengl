#include <windows.h>
#include <iostream>
#include <stdlib.h>
#include <GL/glut.h>

using namespace std;

const float LIGHT_POS = 7.0f; //The length of each side of the cube
const float BOX_HEIGHT = LIGHT_POS ; //The height of the box off of the ground
const float FLOOR_SIZE = 20.0f; //The length of each side of the floor
float yAxe = -5;

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };



void DrawSphere(float x, float y, float z,float xColor, float yColor, float zColor)
{
    glColor4f(xColor,yColor,zColor, 0.5f);

    glPushMatrix();
    glTranslatef(x, y, z);
    glutSolidSphere(1.0f, 20, 16);
    glPopMatrix();
}


//Draws the floor
void drawFloor() {

    glColor4f(0.75f,0.75f,0.75f, 0.5f);

    glBegin(GL_QUADS);
    glNormal3f(0, 1, 0);
    glVertex3f(-FLOOR_SIZE / 2, 0, FLOOR_SIZE / 2);
    glVertex3f(-FLOOR_SIZE / 2, 0, -FLOOR_SIZE / 2);
    glVertex3f(FLOOR_SIZE / 2, 0, -FLOOR_SIZE / 2);
    glVertex3f(FLOOR_SIZE / 2, 0, FLOOR_SIZE / 2);

    glEnd();
}







void initRendering() {

    glClearColor(0.0,0.0,0.0,1.0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}




void handleResize(int w, int h) {

    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (float)w / (float)h, 1.0, 200.0);

}



void drawScene() {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(0.0f, 0.0f, -40.0f);
    glRotatef(30, 1, 0, 0);

    GLfloat ambientLight[] = {0.5f, 0.5f, 0.5f, 1.0f};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientLight);

    GLfloat lightColor[] = {0.5f, 0.5f, 0.5f, 1.0f};
    GLfloat light_specular[] = { 2.0f, 2.0f, 2.0f, 1.0f };
    GLfloat lightPos[] = {2 * LIGHT_POS , 4*LIGHT_POS , 2 * LIGHT_POS , 1.0f};

    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);



    glPushMatrix();
        glTranslatef(0, BOX_HEIGHT, 0);
        //draw red ball
        DrawSphere(-5, yAxe, 1,1,0,0);
        //draw green ball
        DrawSphere(0, yAxe, -3,0,1,0);
        //draw blue ball
        DrawSphere(5, yAxe, 0,0,0,1);
    glPopMatrix();

    glEnable(GL_STENCIL_TEST); //Enable using the stencil buffer
    glColorMask(0, 0, 0, 0); //Disable drawing colors to the screen
    glDisable(GL_DEPTH_TEST); //Disable depth testing
    glStencilFunc(GL_ALWAYS, 1, 1); //Make the stencil test always pass
    //Make pixels in the stencil buffer be set to 1 when the stencil test passes
    glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
    //Set all of the pixels covered by the floor to be 1 in the stencil


    drawFloor();

    glColorMask(1, 1, 1, 1); //Enable drawing colors to the screen
    glEnable(GL_DEPTH_TEST); //Enable depth testing
    //Make the stencil test pass only when the pixel is 1 in the stencil buffer
    glStencilFunc(GL_EQUAL, 1, 1);
    glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP); //Make the stencil buffer not change

    //Draw the cube, reflected vertically, at all pixels where the stencil
    //buffer is 1
    glPushMatrix();
        glScalef(1, -1, 1);
        glTranslatef(0, BOX_HEIGHT, 0);
        //draw reflex red ball
        DrawSphere(-5, yAxe, 1,1,0,0);
        //draw reflex green ball
        DrawSphere(0, yAxe, -3,0,1,0);
        //draw reflex blue ball
        DrawSphere(5, yAxe, 0,0,0,1);
    glPopMatrix();

    glDisable(GL_STENCIL_TEST); //Disable using the stencil buffer

    //Blend the floor onto the screen
    glEnable(GL_BLEND);
    glColor4f(0, 0, 0.5, 0.5f);
    drawFloor();
    glDisable(GL_BLEND);

    glutSwapBuffers();
}

int up = 1;
int down = 0;
void update(int value) {
    if ((yAxe < 7)&& (up == 1)){
        yAxe += 0.5f;
    }else{
        up = 0;
        down = 1;
    }


    if ((yAxe > -6)&& (down == 1)){
        yAxe = yAxe - 0.5f;
    }else{
        down = 0;
        up = 1;
    }
    glutPostRedisplay();
    glutTimerFunc(25, update, 0);
}



void handleKeypress(unsigned char key, int x, int y) {
switch (key) {
case 27: //Escape key
exit(0);
}
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH | GLUT_STENCIL);
    glutInitWindowSize(600, 600);

    glutCreateWindow("openGL project 'infographie informatique'");
    initRendering();

    glutDisplayFunc(drawScene);
    glutKeyboardFunc(handleKeypress);
    glutReshapeFunc(handleResize);
    glutTimerFunc(25, update, 0);

    glutMainLoop();
    return 0;
}
