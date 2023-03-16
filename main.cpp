#include <GL/glut.h>
void display();
int main(int argc, char* argv[]) {
    glutInit(&argc, argv);

    glutInitWindowPosition(200, 200);
    glutInitWindowSize(600, 400);

    glutCreateWindow("Snake Conquer");
    glutDisplayFunc(display);

    glutMainLoop();
}
void display(){}
