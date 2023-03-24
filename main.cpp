#include <GL/glut.h>

void display();
void init();

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);

    glutInitWindowPosition(200, 200);
    glutInitWindowSize(600, 400);

    glutCreateWindow("Snake Conquer");
    init();
    glutDisplayFunc(display);

    glutMainLoop();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex3f(0.25, 0.25, 0.0);
    glVertex3f(0.75, 0.25, 0.0);
    glVertex3f(0.75, 0.75, 0.0);
    glVertex3f(0.25, 0.75, 0.0);
    glEnd();
    glFlush();
}
void init()
{
    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}