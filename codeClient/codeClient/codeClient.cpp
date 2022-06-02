#include "pch.h"
#include "main.h"

int main(int argc, char** argv)
{

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(glutGet(GLUT_SCREEN_WIDTH) / 1.5,
					   glutGet(GLUT_SCREEN_HEIGHT) / 1.5); // ��������� ������ ����
	glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH) - glutGet(GLUT_SCREEN_WIDTH) / 1.5) / 2,
							(glutGet(GLUT_SCREEN_HEIGHT) - glutGet(GLUT_SCREEN_WIDTH) / 1.5) / 2 ); // ������� ����
	glutCreateWindow("Pick up berries or die!"); // ��� ����
	glutSetCursor(GLUT_CURSOR_NONE);

	initialize();

	mapInit();
	glutDisplayFunc(draw); // ����� ������� ���������
	glutReshapeFunc(resize); // ����� ������� ��������� ������� �����������
	glutTimerFunc(1000 / 60, idle, 0);
	glutMouseFunc(mouseButton);

	glutMainLoop();

	return 0;
}