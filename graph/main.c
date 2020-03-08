
// C program to demonstrate 
// drawing a circle using 
// OpenGL 
#include<stdio.h> 
#include<GL/glut.h> 
#include<math.h> 
#define pi 3.142857 

const int WIDTH = 1920;
const int HEIGHT = 1080;
const float ASPECT = (float) WIDTH / HEIGHT;   // desired aspect ratio
  
// function to initialize 
void myInit (void) 
{ 
    // making background color black as first  
    // 3 arguments all are 0.0 
    glClearColor(1.0, 1.0, 1.0, 1.0); 
      
    // making picture color green (in RGB mode), as middle argument is 1.0 
    glColor3f(1.0, 0.0, 0.0); 
      
    // breadth of picture boundary is 1 pixel 
    glPointSize(4.0); 
    glMatrixMode(GL_PROJECTION);  
    glLoadIdentity(); 
       
} 
  
void display (void)  
{ 
    glClear(GL_COLOR_BUFFER_BIT); 
    glBegin(GL_POINTS); 
    float x, y, i; 
      
    // iterate y up to 2*pi, i.e., 360 degree 
    // with small increment in angle as 
    // glVertex2i just draws a point on specified co-ordinate 
    for ( i = 0; i < (2 * pi); i += 0.0001) 
    { 
        // let 200 is radius of circle and as, 
        // circle is defined as x=r*cos(i) and y=r*sin(i) 
        x = 200 * cos(i); 
        y = 200 * sin(i); 
          
        glVertex2i(x + WIDTH / 2, y + HEIGHT / 2); 
    } 
    glEnd(); 
    glFlush(); 
} 

void reshapeScene(GLint width, GLint height)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    int w = height * ASPECT;           // w is width adjusted for aspect ratio
    int left = (width - w) / 2;
    glViewport(left, 0, w, height);       // fix up the viewport to maintain aspect ratio
    gluOrtho2D(0, WIDTH, HEIGHT, 0);   // only the window is changing, not the camera
    glMatrixMode(GL_MODELVIEW);

    glutPostRedisplay();
}
int main (int argc, char** argv) 
{ 
    glutInit(&argc, argv); 
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
      
    // giving window size in X- and Y- direction 
    glutInitWindowSize(WIDTH, HEIGHT); 
    glutInitWindowPosition(0, 0); 
      
    // Giving name to window 
    glutCreateWindow("Circle Drawing"); 
    myInit(); 
      
    glutDisplayFunc(display); 
    glutReshapeFunc(reshapeScene);
    glutMainLoop(); 
} 
