//////////////////////////////////////////////////////// 
// Abdelhak Mehadjbia  
// opengl house with c language 2d hadler
////////////////////////////////////////////////////////



// library opengl 
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define M_PI    3.14159265358979323846

float ballX = -0.8f;
float ballY = -0.0f;
float ballZ = -1.2f;
int night=0;
static int flag=1;


// function for initialise the world
double size=150; 
void initDay (void) 
{   
glClearColor(0.60,0.40,0.12, 1.0); 
glViewport(0,0,500,500);
glMatrixMode(GL_PROJECTION); 
glLoadIdentity(); 
gluOrtho2D(0.0, size, 0.0, size); 
}


// function for drawing a square
void draw_square() {
    glBegin(GL_QUADS);
    glVertex2f(-0.5f, -0.5f);
    glVertex2f( 0.5f, -0.5f);
    glVertex2f( 0.5f,  0.5f);
    glVertex2f(-0.5f,  0.5f);
    glEnd();
  }  
// drawing the ball 
void drawBall(void) {

        glColor3ub(255,255,0); //set ball colour
        glTranslatef(ballX,ballY,ballZ); //moving it toward the screen a bit on creation
        glutSolidSphere (0.25, 30, 30); //create ball.

}

// drawing triangle
void draw_triangle() {
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(+0.5f, -0.5f);
    glVertex2f( 0.0f,  0.5f);
    glEnd();
  } 

// the main function of our design
void display(void)
{
  // if we press n in keyboard will display this
if (night==1)

{

     glClear(GL_COLOR_BUFFER_BIT); 
     glClearColor(0.0,0.0,1.0,0.0);
    glLineWidth(1);
    glPushMatrix();
    glutWireCube (1.0);




   // the stars
   // star 1
   
   glPushMatrix();
   glColor3f(0.0f, 0.0f, 0.0f);
   glTranslatef(100.5, 142.5, 1.0);
   glRotatef(-150, 0.0, 0.0, 1.0);
   glScalef(15, 6, 0.0);
   draw_triangle();
   glPopMatrix();

  glPushMatrix();
  glColor3f(0.0f, 0.0f, 0.0f);
  glTranslatef(100.5, 142.5, 1.0);
  glRotatef(150, 0.0, 0.0, 1.0);
  glScalef(15, 6, 0.0);
  draw_triangle();
  glPopMatrix();

     glPushMatrix();
  glColor3f(0.0f, 0.0f, 0.0f);
   glTranslatef(100.5, 142.5, 1.0);
   glRotatef(-290, 0.0, 0.0, 1.0);
   glScalef(14, 6, 0.0);
   draw_triangle();
     glPopMatrix();


   // star 2
 
    glPushMatrix();
   glColor3f(0.0f, 0.0f, 0.0f);
   glTranslatef(60.5, 142.5, 1.0);
   glRotatef(-150, 0.0, 0.0, 1.0);
   glScalef(15, 6, 0.0);
   draw_triangle();
   glPopMatrix();

  glPushMatrix();
  glColor3f(0.0f, 0.0f, 0.0f);
  glTranslatef(60.5, 142.5, 1.0);
  glRotatef(150, 0.0, 0.0, 1.0);
  glScalef(15, 6, 0.0);
  draw_triangle();
  glPopMatrix();

     glPushMatrix();
  glColor3f(0.0f, 0.0f, 0.0f);
   glTranslatef(60.5, 142.5, 1.0);
   glRotatef(-290, 0.0, 0.0, 1.0);
   glScalef(14, 6, 0.0);
   draw_triangle();
     glPopMatrix();

   // star  3
 
    glPushMatrix();
   glColor3f(0.0f, 0.0f, 0.0f);
   glTranslatef(50.5, 127.5, 1.0);
   glRotatef(-150, 0.0, 0.0, 1.0);
   glScalef(15, 6, 0.0);
   draw_triangle();
   glPopMatrix();

  glPushMatrix();
  glColor3f(0.0f, 0.0f, 0.0f);
  glTranslatef(50.5, 127.5, 1.0);
  glRotatef(150, 0.0, 0.0, 1.0);
  glScalef(15, 6, 0.0);
  draw_triangle();
  glPopMatrix();

     glPushMatrix();
  glColor3f(0.0f, 0.0f, 0.0f);
   glTranslatef(50.5, 127.5, 1.0);
   glRotatef(-290, 0.0, 0.0, 1.0);
   glScalef(14, 6, 0.0);
   draw_triangle();
     glPopMatrix();

// star 4
   
   glPushMatrix();
   glColor3f(0.0f, 0.0f, 0.0f);
   glTranslatef(130.5, 142.5, 1.0);
   glRotatef(-150, 0.0, 0.0, 1.0);
   glScalef(15, 6, 0.0);
   draw_triangle();
   glPopMatrix();

  glPushMatrix();
  glColor3f(0.0f, 0.0f, 0.0f);
  glTranslatef(130.5, 142.5, 1.0);
  glRotatef(150, 0.0, 0.0, 1.0);
  glScalef(15, 6, 0.0);
  draw_triangle();
  glPopMatrix();

     glPushMatrix();
  glColor3f(0.0f, 0.0f, 0.0f);
   glTranslatef(130.5, 142.5, 1.0);
   glRotatef(-290, 0.0, 0.0, 1.0);
   glScalef(14, 6, 0.0);
   draw_triangle();
     glPopMatrix();


   // star 5
 
    glPushMatrix();
   glColor3f(0.0f, 0.0f, 0.0f);
   glTranslatef(136.5, 120.5, 1.0);
   glRotatef(-150, 0.0, 0.0, 1.0);
   glScalef(15, 6, 0.0);
   draw_triangle();
   glPopMatrix();

  glPushMatrix();
  glColor3f(0.0f, 0.0f, 0.0f);
  glTranslatef(136.5, 120.5, 1.0);
  glRotatef(150, 0.0, 0.0, 1.0);
  glScalef(15, 6, 0.0);
  draw_triangle();
  glPopMatrix();

     glPushMatrix();
  glColor3f(0.0f, 0.0f, 0.0f);
   glTranslatef(136.5, 120.5, 1.0);
   glRotatef(-290, 0.0, 0.0, 1.0);
   glScalef(14, 6, 0.0);
   draw_triangle();
     glPopMatrix();

   // star  6
 
    glPushMatrix();
   glColor3f(0.0f, 0.0f, 0.0f);
   glTranslatef(115.5, 115.5, 1.0);
   glRotatef(-150, 0.0, 0.0, 1.0);
   glScalef(15, 6, 0.0);
   draw_triangle();
   glPopMatrix();

  glPushMatrix();
  glColor3f(0.0f, 0.0f, 0.0f);
  glTranslatef(115.5, 115.5, 1.0);
  glRotatef(150, 0.0, 0.0, 1.0);
  glScalef(15, 6, 0.0);
  draw_triangle();
  glPopMatrix();

     glPushMatrix();
  glColor3f(0.0f, 0.0f, 0.0f);
   glTranslatef(115.5, 115.5, 1.0);
   glRotatef(-290, 0.0, 0.0, 1.0);
   glScalef(14, 6, 0.0);
   draw_triangle();
     glPopMatrix();







// the rest of design
// the home
    glPushMatrix();
    glColor3f(0.0,1.0,0.0);
    glTranslatef(40,35.5,1);
    glScalef(40, 63, 1);
    draw_square();
    glPopMatrix();

//roof of the house
    glPushMatrix();
    glColor3f(0.0,0.9,1.0);
    glTranslatef(40,82,1);
    glScalef(40, 30, 1);
    draw_triangle();
    glPopMatrix();



// the house door
    glPushMatrix();
    glColor3f(1.0,0.0,0.0);
    glTranslatef(40,15.5,1);
    glScalef(10, 22, 1);
    draw_square();
    glPopMatrix();
//


//

// the left house window
    glPushMatrix();
    glColor3f(1.0,1.0,1.0);  
    glTranslatef(30,46,1);
    glScalef(10, 10, 1);
    draw_square();
    glPopMatrix();
//



// left window's bar
      
    glPushMatrix();
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0,0.0,0.0);
    glVertex2f(25, 46);
    glVertex2f(35, 46);
    glEnd(); 
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0,0.0,0.0);
    glVertex2f(30, 51);
    glVertex2f(30, 41);
    glEnd(); 
    glPopMatrix();
//

// right house's window
    glPushMatrix();
    glColor3f(1.0,1.0,1.0);  
    glTranslatef(50,46,1);
    glScalef(10, 10, 1);
    draw_square();
    glPopMatrix(); 
//

//right window's bar

    glBegin(GL_LINE_STRIP);
    glColor3f(0.0,0.0,0.0);
    glVertex2f(45, 46);
    glVertex2f(55, 46);
    glEnd(); 


    glPushMatrix();
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0,0.0,0.0);
    glVertex2f(50, 51);
    glVertex2f(50, 41);
    glEnd(); 
    glPopMatrix();
//

//the tree

     glPushMatrix();
   glColor3f(0.0, 1.0, 0.0);
   glTranslatef(125, 19.0, 1.0);
   glScalef(5, 31.3, 0.0);
   draw_square();
     glPopMatrix();

// the leaves of the tree
    glPushMatrix();
   glColor3f(0.0, 1.0, 0.0);
   glTranslatef(125.5, 37.5, 1.0);
   glRotatef(-150, 0.0, 0.0, 1.0);
   glScalef(25, 7, 0.0);
   draw_triangle();
   glPopMatrix();

     glPushMatrix();
   glColor3f(0.0, 1.0, 0.0);
   glTranslatef(124.1, 37.5, 1.0);
   glRotatef(150, 0.0, 0.0, 1.0);
   glScalef(25, 7, 0.0);
   draw_triangle();
     glPopMatrix();


//
     
  // the ground
    glLineWidth(10);
    glPushMatrix();
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0,0.0,0.0);
    glVertex2f(0.0, 4);
    glVertex2f(130, 4);
    glEnd();
glPopMatrix();
//
glPopMatrix();
    glFlush();        
 
}
 else {  

    glClear(GL_COLOR_BUFFER_BIT); 
    glClearColor(0.60,0.40,0.12, 1.0); 
    glLineWidth(1);
    glPushMatrix();
    glutWireCube (1.0);


    //the  ball 
    glPushMatrix();
    glTranslatef(30,80,1);
    glScalef(40, 63, 1);
    drawBall();
    glPopMatrix();

    // the home
    glPushMatrix();
    glColor3f(0.0,1.0,0.0);
    glTranslatef(40,35.5,1);
    glScalef(40, 63, 1);
    draw_square();
    glPopMatrix();

    


    

//roof of the house
    glPushMatrix();
    glColor3f(0.0,0.9,1.0);
    glTranslatef(40,82,1);
    glScalef(40, 30, 1);
    draw_triangle();
    glPopMatrix();



// the house door
    glPushMatrix();
    glColor3f(1.0,0.0,0.0);
    glTranslatef(40,15.5,1);
    glScalef(10, 22, 1);
    draw_square();
    glPopMatrix();
//


//

// the left house window
    glPushMatrix();
    glColor3f(1.0,1.0,1.0);  
    glTranslatef(30,46,1);
    glScalef(10, 10, 1);
    draw_square();
    glPopMatrix();
//



// left window's bar
      
    glPushMatrix();
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0,0.0,0.0);
    glVertex2f(25, 46);
    glVertex2f(35, 46);
    glEnd(); 
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0,0.0,0.0);
    glVertex2f(30, 51);
    glVertex2f(30, 41);
    glEnd(); 
    glPopMatrix();
//

// right house's window
    glPushMatrix();
    glColor3f(1.0,1.0,1.0);  
    glTranslatef(50,46,1);
    glScalef(10, 10, 1);
    draw_square();
    glPopMatrix(); 
//

//right window's bar

    glBegin(GL_LINE_STRIP);
    glColor3f(0.0,0.0,0.0);
    glVertex2f(45, 46);
    glVertex2f(55, 46);
    glEnd(); 


    glPushMatrix();
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0,0.0,0.0);
    glVertex2f(50, 51);
    glVertex2f(50, 41);
    glEnd(); 
    glPopMatrix();
//

//the tree

     glPushMatrix();
   glColor3f(0.0, 1.0, 0.0);
   glTranslatef(125, 19.0, 1.0);
   glScalef(5, 31.3, 0.0);
   draw_square();
     glPopMatrix();

// the leaves of the tree
    glPushMatrix();
   glColor3f(0.0, 1.0, 0.0);
   glTranslatef(125.5, 37.5, 1.0);
   glRotatef(-150, 0.0, 0.0, 1.0);
   glScalef(25, 7, 0.0);
   draw_triangle();
   glPopMatrix();

     glPushMatrix();
   glColor3f(0.0, 1.0, 0.0);
   glTranslatef(124.1, 37.5, 1.0);
   glRotatef(150, 0.0, 0.0, 1.0);
   glScalef(25, 7, 0.0);
   draw_triangle();
     glPopMatrix();


//
     
  // the ground
    glLineWidth(10);
    glPushMatrix();
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(0.0, 4,-1);
    glVertex3f(130, 4,-1);
    glEnd();
glPopMatrix();
//
glPopMatrix();
    glFlush();    
                        
}}

void displayall(){
glClear(GL_COLOR_BUFFER_BIT);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluPerspective( 90.0,0.8,-1.0,1.0); 
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
gluLookAt(150,150,150,0,0,0,0,1,0);
display();


}


// function to recalculate the scene
static void idle(void)
{
    glutPostRedisplay();
}

// reshape function to resize the viewport
void reshape (int w,int h)
{ 
if(w >=h) glViewport(0,0,(GLsizei)h, (GLsizei)h);
else glViewport(0,0,(GLsizei)w, (GLsizei)w);

}
void keyPress(int key,int x, int y)
{
    switch (key)
    {
        
        case GLUT_KEY_RIGHT:glutFullScreen();   
        case GLUT_KEY_DOWN: size++; 
glLoadIdentity(); gluOrtho2D(0.0, size, 0.0, size);  break;
        case GLUT_KEY_UP: size--; 
glLoadIdentity(); gluOrtho2D(0.0, size, 0.0, size);  break; 
            default: break;
    }

    glutPostRedisplay();
}
void keyPress2(unsigned char key,int x, int y)
{
    switch (key)
    {

        case 'n': if (night==0)
                  {
                     night=1;
                  }else night=0; 
                  break;
        case 27 : exit(0); 
            default: break;
    }

    glutPostRedisplay();
}


//float _angle = 30.0f;
void update(int value) {
   
    if(ballX>0.9f)
    {
        ballX = -0.8f;
        ballY = -0.0f;
        flag=1;

    }
   
    if(flag)
    {
    ballX += 0.008f;
    ballY +=0.001f;


       if(ballX>0.01)
       {
           flag=0;

       }
    }
    if (!flag)
    {
        ballX += 0.006f;
        ballY -=0.0009f;

        if(ballX<-0.7)
       {
           flag=1;

       }
    }
   
    glutPostRedisplay(); //Tell GLUT that the display has changed
   
    //Tell GLUT to call update again in 25 milliseconds
    glutTimerFunc(15, update, 0);
}

int
main(int argc, char **argv)
{


glutInit(&argc,argv); 
int mode = GLUT_RGB|GLUT_SINGLE; 
glutInitDisplayMode(mode); 
glutInitWindowSize(500,500); 
glutCreateWindow("Lab 2"); 
glutReshapeFunc(reshape); 
glutDisplayFunc(display); 

/*glutFullScreen();*/
 glutSpecialFunc(keyPress);
 glutKeyboardFunc(keyPress2);
initDay();
glutTimerFunc(50, update, 0);
  glutMainLoop();
  return 0; 
}