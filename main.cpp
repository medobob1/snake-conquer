#include <GL/glut.h>
#include <iostream>
#include <chrono>
#include <thread>

void delay(int milliseconds) {
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}

void display() {
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 0, 0);
    std::cout<<"Enter x1, y1, x2, y2:"<< "\n";
    float x1;
    std::cin>>x1;
    float y1;
    std::cin>>y1;
    float x2;
    std::cin>>x2;
    float y2;
    std::cin>>y2;
    float dx = x2 - x1;
    float dy = y2 - y1;
    float steps = dx > dy ? dx : dy;
    float xInc = dx / steps;
    float yInc = dy / steps;
    glPointSize(5);
    float x = x1;
    float y = y1;
    for (int i = 0; i <= steps; i++) {
        glBegin(GL_POINTS);
        glVertex2f(x, y);
        glEnd();
        glFlush();
        std::this_thread::sleep_for(std::chrono::milliseconds(20)); // Increase delay time
        x += xInc;
        y += yInc;
        if (i == steps) {
            std::cout << "Done" << "\n";
            std::cout << "If you want to draw a new line enter 1 else enter 0" << "\n";
            int choice;
            std::cin >> choice;
            if (choice == 1) {
                display();
            }
            else if (choice != 0 && choice != 1) {
                std::cout << "Invalid choice" << "\n";
                display();
            }
             else if (choice == 0) {
                exit(0);
            }   
        }
    }
    glFlush();
}



int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Hello World");
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 500, 0, 500);
    glutDisplayFunc(display);
    glutMainLoop();
}