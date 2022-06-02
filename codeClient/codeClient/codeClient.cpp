#include "pch.h"
#include "main.h"

int main(int argc, char** argv)
{

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(glutGet(GLUT_SCREEN_WIDTH) / 1.5,
					   glutGet(GLUT_SCREEN_HEIGHT) / 1.5); // Указываем размер окна
	glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH) - glutGet(GLUT_SCREEN_WIDTH) / 1.5) / 2,
							(glutGet(GLUT_SCREEN_HEIGHT) - glutGet(GLUT_SCREEN_WIDTH) / 1.5) / 2 ); // Позиция окна
	glutCreateWindow("Pick up berries or die!"); // Имя окна
	glutSetCursor(GLUT_CURSOR_NONE);

	initialize();

	mapInit();
	glutDisplayFunc(draw); // Вызов функции отрисовки
	glutReshapeFunc(resize); // Вызов функции изменения размера изображения
	glutTimerFunc(1000 / 60, idle, 0);
	glutMouseFunc(mouseButton);

	glutMainLoop();

	return 0;
}