//GLEW�����O�̃R�[�h
/*
#include <cstdlib> //atexit���ق���
#include <iostream>
#include <GLFW/glfw3.h>


//int main()
{
	//(1)GLFW������������i���̃v���O������ OpenGL ���g�p���邽�߂̏����j
	//�������Ɏ��s�����ꍇ��glfwInit() �̖߂�l�� GL_FALSE�ɂȂ�
	if (glfwInit() == GL_FALSE)
	{
		//�G���[�p�̏o��cerr�ƁC�G���[�p�̖߂�l1
		std::cerr << "can't initialize GLFW" << std::endl;
		return 1;
	}

	//�v���O�����I�����̏�����o�^����
	atexit(glfwTerminate);

	//(2)�E�B���h�E���쐬����
	GLFWwindow* const window = glfwCreateWindow(640, 480, "window��", NULL, NULL);
	//const�ɂ�������Ă�̂Ōォ�� window �ɕʂ� GLFWwindow* �����������ꍇ�ɖ�肪�o��B
	if (window == NULL)
	{
		//window�̃|�C���^(��񂻂̂��́C�E�B���h�E�̍\���̂̐擪�|�C���^)���쐬�ł��Ȃ������悤����
		std::cerr << "can't create GLFW window...." << std::endl;
		//glfwTerminate(); //�擾�����������J��
		return 1;
	}

	//�쐬�����E�B���h�E���J�����g�iOpenGL�̏����Ώہj�ɂ���
	glfwMakeContextCurrent(window);

	//�w�i�F���w��
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);

	//(3) �E�B���h�E���J���Ă���ԏ������J��Ԃ�
	while (glfwWindowShouldClose(window) == GL_FALSE)
	{
		//�E�B���h�E�̕`����e�������i�㏑���j
		glClear(GL_COLOR_BUFFER_BIT); //�J���[�o�b�t�@�݂̂��w�肵glClearColor�ŏ㏑��

		//
		//�`�揈��
		//


		//�J���[�o�b�t�@�����ւ���
		glfwSwapBuffers(window); //���Ȃ��ƕ`�悾���ŕ\������Ȃ����


		//�C�x���g�̃`�F�b�N
		glfwWaitEvents(); //��~���Ȃ�(glfwPollEvents�̓C�x���g����܂Œ�~)
	}
}
*/