#include <cstdlib> //atexit
#include <iostream>
#include <GL/glew.h> //glfw���O��
#include <GLFW/glfw3.h>
//-------------------------------------
//�v���O�����I�u�W�F�N�g���쐬
//vsrc : �o�[�e�b�N�X�V�F�[�_�̃\�[�X������
//fsrc : �t���O�����g�V�F�[�_�̃\�[�X������

//-------------------------------------
GLint createProgram(const char* vsrc, const char* fsrc) //��A�̏���������֐�
{
	//��̃v���O�����I�u�W�F�N�g���쐬
	const GLint program = glCreateProgram();

	if (vsrc != NULL) {
		//�o�[�e�b�N�X�V�F�[�_�̃V�F�[�_�I�u�W�F�N�g����낤�ivsrc����Ȃ�j
		const GLint vobj = glCreateShader(GL_VERTEX_SHADER); //������
		
		glShaderSource(vobj, 1, &vsrc, NULL); //������Ƃ��ă\�[�X�����т���
		glCompileShader(vobj); //���т����V�F�[�_�I�u�W�F�N�g(�̃\�[�X)���R���p�C��

		//�v���O�����I�u�W�F�N�g��V�V�F�[�_�I�u�W�F�N�g��g�ݍ���
		glAttachShader(program, vobj);
		glDeleteShader(vobj); //Detach���ꂽ��V�F�[�_�I�u�W�F�N�g�͍폜�����悤��
	}

	//�v���O�����I�u�W�F�N�g�������N���悤
	//�X�̃V�F�[�_�̓R���p�C������Ă��邪�C����������s�\�ȏ�Ԃɂ͂܂��Ȃ��ĂȂ�
	
	//GPU��ver�V�F�[�_�̓��͂��󂯎��ꏊ�Cfrag�V�F�[�_�̏o�͂������̂�n���ꏊ���w��
	glBindAttribLocation(program, 0, "position"); //�X���b�g�O�C�ϐ�����potision
	glBindFragDataLocation(program, 0, "fragment");

	glLinkProgram(program); //�����N���ĕ����̃V�F�[�_�I�u�W�F�N�g��1�̃v���O������

	//�쐬�����v���O�����I�u�W�F�N�g��Ԃ�
	return program;
}

//-------------------------------------
// GLFW main����
int main()
{
	//(1)GLFW������������i���̃v���O������ OpenGL ���g�p���邽�߂̏����j
	//�������Ɏ��s�����ꍇ��glfwInit() �̖߂�l�� GL_FALSE�ɂȂ�
	if (glfwInit() == GL_FALSE)
	{
		//�G���[�p�̏o��cerr�ƁC�G���[�p�̖߂�l1
		std::cerr << "can't initialize GLFW" << std::endl;
		return 1;
	}

	//�v���O��������I�����̏�����o�^
	atexit(glfwTerminate);

//---------------
	//�E�B���h�E�̓����i�q���g�j��ݒ�
	//�o�[�W�����w��i3.2�j
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);

	//mac�ł̂ݕK�v
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); 
	//�v���t�@�C���w��iCore Profile�j
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

//---------------
	//(2)�E�B���h�E���쐬����
	GLFWwindow *const window = glfwCreateWindow(640, 480, "window_name", NULL, NULL);
	//const�ɂ��Ă�̂Ōォ�� window �ɕʂ� GLFWwindow* �����������ꍇ�ɖ�肪�o��
	if (window == NULL)
	{
		//window�̃|�C���^(��񂻂̂��́C�E�B���h�E�̍\���̂̐擪�|�C���^)�쐬�Ɏ��s�����ꍇ
		std::cerr << "can't create GLFW window...." << std::endl;
		//glfwTerminate(); //�擾�����������J��
		return 1;
	}

	//�쐬�����E�B���h�E���J�����g�iOpenGL�̏����Ώہj�ɂ���
	glfwMakeContextCurrent(window);
	//---------------
	//GLEW(�h���C�o�Ɋ֐��|�C���^�̎擾�葱�������Ă����)�̓R���e�L�X�g�Ɉˑ�
	//�L���ȃR���e�L�X�g�����߂����߂����ŏ�����
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		//GLEW�̏������Ɏ��s
		std::cerr << "can't initialize GLEW" << std::endl;
		return 1;
	}
	//---------------
	//�w�i�F���w��
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);

	//�E�B���h�E�쐬���V-sync�ݒ�(�E�B���h�E��fps�ɍ��킹��)
	glfwSwapInterval(1);

//---------------
	//(3) �E�B���h�E���J���Ă���ԏ������J��Ԃ�
	while (glfwWindowShouldClose(window) == GL_FALSE)
	{
		//�E�B���h�E�̕`����e�������i�㏑���j
		glClear(GL_COLOR_BUFFER_BIT); //�J���[�o�b�t�@�݂̂��w�肵glClearColor�ŏ㏑��

		//
		//�`�揈��
		//


		//GLFW�͕W���Ń_�u���o�b�t�@�Ȃ̂ŃJ���[�o�b�t�@�����ւ���(��ʕ\��)
		glfwSwapBuffers(window); //���Ȃ��ƕ`�悾���ŕ\������Ȃ��i���ɂ���܂܁j
		

		//�C�x���g�̃`�F�b�N
		glfwWaitEvents(); //OS����C�x���g���b�Z�[�W����܂ŕ`���~(����->�Ή�����R�[���o�b�N�𔭉�->while�`��擪��)
	}
}
//-------------------------------------