#include "Circle.h"
using namespace std;

Circle a = Circle();

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glLineWidth(10);
    a.paintLine();
    glutSwapBuffers();
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);  //параметры окна(двойная буферизация и всё такое)
    glutInitWindowSize(1200, 800);  //это размеры окна
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Physics");  //это название создающегося окна
    glClearColor(1, 1, 1, 0);   //цвет фона
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glutDisplayFunc(display);
    //glutIdleFunc(display);
    //glutKeyboardFunc(keyboard);
    //glutSpecialFunc(special);
    glutMainLoop();
    return 1;
}
