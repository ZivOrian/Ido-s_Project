#include <stdlib.h>
#include <stdio.h>
#include <glut.h>
#include <ctype.h>
#include <cmath> 


float xAngle = 20.;
float deshe_x = 0;
float yAngle = 0;

struct Point {
    float x;
    float y;
    float z;
};

struct PlaneCollider {
    float a;//  >
    float b;//   >The plane's normal
    float c;//  >
    float d;// the plane's d ( ax+by+cz+d=0 )
    float height;
    float width;
};



float distance(Point p1, Point p2) {
    return sqrt(powf(p1.x - p2.x, 2)+powf(p1.y - p2.y, 2)+powf(p1.z - p2.z, 2));
}


void display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);// מנקה את הרקע 
    glLoadIdentity();
 
    glPushMatrix();
    for (int i = 0; i < 6; i++) {
        glPushMatrix();
        glRotatef(yAngle,1,0,0);
        glRotatef(xAngle,0,1,0);
        glTranslatef(deshe_x+i*2.1,2,2);
        glScalef(0.3,0.02/1.5,2);
        glColor3ub(0,150 + 105 * (i%2),0);
        glutSolidCube(7);
        glPopMatrix();
    }
    glRotatef(yAngle, 1, 0, 0);
    glRotatef(xAngle, 0, 1, 0);
    glTranslatef(deshe_x + 5.3 , 2, 2);
    glScalef(0.3001*6, 0.02001, 2.001);
    glColor3f(0,0,0);
    glutWireCube(7);
    glColor3f(1, 0, 0);
    glBegin(GL_LINES);
    glVertex3f(0,3.5,0);
    glVertex3f(0,50,0);
    glEnd();
    glPopMatrix();

    glutPostRedisplay();
    glutSwapBuffers();
    glFlush();
}

//void idle() {
//    angle--;
//    glutPostRedisplay();
//}

void myinit(void) {
    glClearColor(0.0, 0.7, 0.7, 0.);// יצוייר עליו ירוק ראשי חלון הצבעים מחליף הריבוע 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-2., 15., -1., 6., -40., 40);
    glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y) {
    if (tolower(key) == 'e')
        xAngle++;
    if (tolower(key) == 'q')
        xAngle--;
    printf("%f\n", yAngle);
    if (tolower(key) == 'a')
        deshe_x--;
    if (tolower(key) == 'd')
        deshe_x++;
    if (tolower(key) == 'w' && yAngle < 7.5)
        yAngle++;
    if (tolower(key) == 's' && yAngle > -7.5)
        yAngle--;
}

void main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1000, 1000);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Triangle and square without hiddensurface-removal");
    glutDisplayFunc(display);
    //glutIdleFunc(idle);
    myinit();
    glutKeyboardFunc(keyboard);
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
}
