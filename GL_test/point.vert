#version 150 core //openGL3.2������GLSL�o�[�W����1.5, core profile�g�p

in vec4 position; //�O�̃p�C�v���C�����瑗��ꂽ�ϐ���in. 4�v�f����Ȃ�x�N�g��
                  //in�͓���attribute�ϐ��ƌĂ΂�C���_�������i�[���Ă���
void main(){      //�V�F�[�_�v���O������main����n�܂邪�������Ȃ�  
	gl_position = position; //GLSL���L�̕ϐ�(�g�ݍ��ݕϐ�)
	                        //�o�[�e�b�N�X�V�F�[�_�ł͕K�����̕ϐ��ɒl��������
}