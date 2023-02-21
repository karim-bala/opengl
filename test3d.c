//////////////////////////////////////////////////////// 
// Abdelhak Mehadjbia  
// opengl house with c language 3d hadler
////////////////////////////////////////////////////////





// library opengl 
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415927

float _cameraAngle = -0.0f;
int isDebug = 0;
float _angle = 180.0f;
float _angle2 = 0.0f;
float _angle3 = 0.0f;
float _cameraAngle2=-1.5f;
float zoom=90.0;

// function to handle keyboard listners
void handleKeypress(unsigned char key, int x, int y) {
    switch (key) {
    case 27:
        exit(0);
    case 'a':

     _angle += 10.0f;
    if (_angle > 360) {
        _angle -= 360;
    }
    glutPostRedisplay();


    break;

    case 'b':

     _angle -= 10.0f;
    if (_angle > 360) {
        _angle -= 360;
    }
    glutPostRedisplay();


    break;
     case 'q':

     _angle2 -= 10.0f;
    if (_angle > 360) {
        _angle -= 360;
    }
    glutPostRedisplay();


    break;
     case 's':

     _angle2 += 10.0f;
    if (_angle > 360) {
        _angle -= 360;
    }
    glutPostRedisplay();


    break;
    case 'h':

     _angle3 -= 10.0f;
    if (_angle > 360) {
        _angle -= 360;
    }
    glutPostRedisplay();


    break;
     case 'j':

     _angle3 += 10.0f;
    if (_angle > 360) {
        _angle -= 360;
    }
    glutPostRedisplay();


    break;
    case 'c':

    _cameraAngle+=7; 
    
    glutPostRedisplay();


    break;

   case 'd':

    _cameraAngle-=7; 
    
    glutPostRedisplay();


    break;

    case 'e':

    _cameraAngle2+=0.2; 
    
    glutPostRedisplay();


    break;

    case 'f':

    _cameraAngle2-=0.2; 
    
    glutPostRedisplay();


    break;

    case 'z':glutFullScreen();  break;

            default: break;

     
    
    }

 
}

// function to init the world
void initRendering() {
    glEnable(GL_DEPTH_TEST);
}





 //function to init the size of shapes whenever the shapes size change

void handleResize(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(zoom, (double) w / (double) h, 1.0, 200.0);
}

// principale function which will draw all our designs

void drawScene() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
   glClearColor(0.60,0.40,0.12, 1.0); 
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRotatef(-_cameraAngle, 0.0f, 1.0f, 0.0f);
    glTranslatef(-1.0f, _cameraAngle2, -2.0f);
   
    glPushMatrix();
    glTranslatef(1.0f, 1.0f, 0.0f);
    glRotatef(_angle, 0.0f, 1.0f, 0.0f);
    glRotatef(_angle2, 0.1f, 0.0f, 0.0f);
    glRotatef(_angle3, 0.0f, 0.0f, 1.0f);
    glScalef(1.0f, 1.0f, 1.0f); 
    glLineWidth(10);


   
   
    
    

    /* main rec */
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (0.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex3f (0.2, 0.1, 0.0);
    glVertex3f (0.9, 0.1, 0.0);
    glVertex3f (0.9, 1.0, 0.0);
    glVertex3f (0.2, 1.0, 0.0);
    glEnd();

    /*back rec*/
    glColor3f (0.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex3f (0.2,0.1, 0.5);
    glVertex3f (0.9,0.1, 0.5);
    glVertex3f (0.9,1.0, 0.5);
    glVertex3f (0.2,1.0, 0.5);
    glEnd();

    /* left rec */
    glColor3f (0.0,1.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex3f (0.2, 0.1, 0.5);
    glVertex3f (0.2, 0.1, 0.0);
    glVertex3f (0.2, 1.0, 0.0);
    glVertex3f (0.2, 1.0, 0.5);
    glEnd();

    /* right rec */
    glColor3f (0.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex3f (0.9, 0.1, 0.5);
    glVertex3f (0.9, 0.1, 0.0);
    glVertex3f (0.9, 1.0, 0.0);
    glVertex3f (0.9,1.0, 0.5);
    glEnd();

    /* left tri */
    glColor3f (0.1, 0.1,0.1);
    glBegin(GL_TRIANGLES);
    glVertex3f (0.9, 0.8, 0.0);
    glVertex3f (0.9, 0.8, 0.5);
    glVertex3f (0.9, 1.3, 0.25);
glEnd();
    /* right tri */
    glColor3f (0.1, 0.1,0.1);
    glBegin(GL_TRIANGLES);
    glVertex3f (0.2, 0.8, 0.0);
    glVertex3f (0.2, 0.8, 0.5);
    glVertex3f (0.2, 1.3, 0.25);
    glEnd();

    /* roof */
    glColor3f (0.1, 0.1, 0.1);
    glBegin(GL_POLYGON);
    glVertex3f (0.2, 1.0, 0.0);
    glVertex3f (0.9, 1.0, 0.0);
    glVertex3f (0.9, 1.3, 0.25);
    glVertex3f (0.2, 1.3, 0.25);
    glEnd();

    /*back roof */
    glColor3f (0.1, 0.1, 0.1);
    glBegin(GL_POLYGON);
    glVertex3f (0.2, 1.0, 0.5);
    glVertex3f (0.9, 1.0, 0.5);
    glVertex3f (0.9, 1.3, 0.25);
    glVertex3f (0.2, 1.3, 0.25);
    glEnd();

    /* door */
    glColor3f (1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex3f (0.47, 0.105, 0.0);
    glVertex3f (0.65, 0.105, 0.0);
    glVertex3f (0.65, 0.46, 0.0);
    glVertex3f (0.47, 0.46, 0.0);
    glEnd();

    /* left window  */
    glColor3f (1.0, 1.0,1.0);
    glBegin(GL_POLYGON);
    glVertex3f (0.72, 0.6, 0.0);
    glVertex3f (0.83, 0.6, 0.0);
    glVertex3f (0.83, 0.8, 0.0);
    glVertex3f (0.72, 0.8, 0.0);
    glEnd();

    /*  right window  */
    glColor3f (1.0, 1.0,1.0);
    glBegin(GL_POLYGON);
    glVertex3f (0.27, 0.6, 0.0);
    glVertex3f (0.38, 0.6, 0.0);
    glVertex3f (0.38, 0.8, 0.0);
    glVertex3f (0.27, 0.8, 0.0);
    glEnd();

    // line of right window  
    
    glBegin(GL_LINES);
    glColor3f(0.0,0.0,0.0);
  glVertex3f(0.27, 0.7, 0.0);
  glVertex3f(0.38,0.7, 0.0);
glEnd(); 
  glBegin(GL_LINES);
    glColor3f(0.0,0.0,0.0);
  glVertex3f(0.32, 0.6, 0.0);
  glVertex3f(0.32,0.8, 0.0);
glEnd(); 

   
  glBegin(GL_LINES);
    glColor3f(0.0,0.0,0.0);
  glVertex3f(0.36, 0.6, 0.0);
  glVertex3f(0.36,0.8, 0.0);
glEnd(); 

 // line of left window

     glBegin(GL_LINES);
    glColor3f(0.0,0.0,0.0);
  glVertex3f(0.72, 0.7, 0.0);
  glVertex3f(0.83,0.7, 0.0);
glEnd(); 
  glBegin(GL_LINES);
    glColor3f(0.0,0.0,0.0);
  glVertex3f(0.78, 0.6, 0.0);
  glVertex3f(0.78,0.8, 0.0);
glEnd(); 

   
  glBegin(GL_LINES);
    glColor3f(0.0,0.0,0.0);
  glVertex3f(0.81, 0.6, 0.0);
  glVertex3f(0.81,0.8, 0.0);
glEnd(); 

// the ground



glColor3f (0.1, 0.1, 0.1);
    glBegin(GL_POLYGON);
    glVertex3f (-2, 0.1, -2.0);
    glVertex3f (2, 0.1, -2);
    glVertex3f (2, 0.1,2);
    glVertex3f (-2, 0.1, 2);
    glEnd();


    glFlush ();
    glPopMatrix();
    glutSwapBuffers();
}

//i don't use it her but you can use it to update every thing like adding sun which will raise and fall
void update(int value) {
    _angle += 1.0f;
    if (_angle > 360) {
        _angle -= 360;
    }
    glutPostRedisplay();
    glutTimerFunc(25, update, 0);
}

//our main function
int main(int argc, char * * argv) {
    glutInit( & argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1000, 800);
    glutCreateWindow("3D House Rotate");
    initRendering();
    glutDisplayFunc(drawScene);
    glutKeyboardFunc(handleKeypress);
    glutReshapeFunc(handleResize);
    glutMainLoop();
    return 0;
}