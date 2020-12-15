#include "DxLib.h"
#include "stdlib.h"
#include "string.h"
#include "prototype_mapp.h"

#define _CRT_SECURE_NO_WARNINGS
#define MAP_NUM         3           // �}�b�v�̐�
#define GAME_WIDTH			800	//��ʂ̉��̑傫��
#define GAME_HEIGHT			640	//��ʂ̏c�̑傫��
#define GAME_COLOR			32	//��ʂ̃J���[�r�b�g

#define MAP_SIZE        32          // �}�b�v�`�b�v��̃h�b�g�T�C�Y

#define MAP_WIDTH_MAX   25          // �}�b�v�̍ő啝
#define MAP_HEIGHT_MAX  20          // �}�b�v�̍ő�c����

#define MAP_DIV_WIDTH		32	//�摜�𕪊����镝�T�C�Y
#define MAP_DIV_HEIGHT		32	//�摜�𕪊����鍂���T�C�Y
#define MAP_DIV_TATE		8	//�摜���c�ɕ������鐔8
#define MAP_DIV_YOKO		50	//�摜�����ɕ������鐔50
#define MAP_DIV_NUM	MAP_DIV_TATE * MAP_DIV_YOKO	//�摜�𕪊����鑍�� 400

#define PLAYER_DIV_WIDTH 32 //�v���C���[�̉���32�r�b�g
#define PLAYER_DIV_HEIGHT 48 //�v���C���[����48�r�b�g
#define PLAYER_DIV_TATE 4 //�^�e������4
#define PLAYER_DIV_YOKO 4 //���R������4
#define PLAYER_DIV_NUM PLAYER_DIV_TATE * PLAYER_DIV_YOKO //16

#define GAME_FPS			60	//FPS�̐��l	

//�摜�̃p�X�ݒ�
#define TITLE_BACK_PATH TEXT(".\\IMAGE\\�_�E�����[�h (2).png") //�^�C�g���̉摜
#define IMAGE_SETUMEI_PATH		TEXT(".\\IMAGE\\�������2.png") //������ʂ̉摜
#define GAME_MAP_PATH TEXT(".\\IMAGE\\ST-Town-I01.png")
#define GAME_PLAYER_PATH TEXT(".\\IMAGE\\joshi03.png")

//�G���[���b�Z�[�W
#define IMAGE_LOAD_ERR_TITLE	TEXT("�摜�ǂݍ��݃G���[")

//�p�X�̒���
#define PATH_MAX			255	//255�����܂�
#define NAME_MAX			255	//255�����܂�

//�L�[�{�[�h�̎��
#define KEY_CODE_KIND		256	//256���

//�X�^�[�g�G���[
#define START_ERR_TITLE		TEXT("�X�^�[�g�ʒu�G���[")
#define START_ERR_CAPTION	TEXT("�X�^�[�g�ʒu�����܂��Ă��܂���")
//�S�[���G���[
#define GOAL_ERR_TITLE		TEXT("�S�[���ʒu�G���[")
#define GOAL_ERR_CAPTION	TEXT("�S�[���ʒu�����܂��Ă��܂���")
//����{�^�����������Ƃ�
#define MSG_CLOSE_TITLE			TEXT("�I�����b�Z�[�W")
#define MSG_CLOSE_CAPTION		TEXT("�Q�[�����I�����܂����H")
//�I���_�C�A���O�p
#define MOUSE_R_CLICK_TITLE		TEXT("�Q�[�����f")
#define MOUSE_R_CLICK_CAPTION	TEXT("�Q�[���𒆒f���A�^�C�g����ʂɖ߂�܂����H")

enum GAME_SCENE {
	GAME_SCENE_START,
	GAME_SCENE_SETUMEI,
	GAME_SCENE_PLAY,
	GAME_SCENE_PLAY2,
	GAME_SCENE_END,
};	//�Q�[���̃V�[��

enum GAME_MAP_KIND
{
	/*n = -1,*/	//(NONE)����
	k = 10,	//��
	t = 17,	//���
	s = 25,	//����
	g = 33,	//����
	n = 196, // ����
	d = 150, // �_���{�[��
	a = 66, //������
	b = 67, // �E����
	c = 74, //������
	h = 75, // �E����
	u = 349, //���J�[�y�b�g
	e = 350, //�J�[�y�b�g��
	f = 351, //�J�[�y�b�g�^��
	r = 2, //����
	S = 198, //start
	G = 197, //goal
	M = 195, //��O�̏ꏊ�ɖ߂锻��

};	//�}�b�v�̎��

enum GAME_END {
	GAME_END_COMP,	//�R���v���[�g
	GAME_END_FAIL	//�t�H�[���g
};	//�Q�[���̏I�����




typedef struct STRUCT_IMAGE
{
	char path[PATH_MAX];		//�p�X
	int handle;					//�n���h��
	int x;						//X�ʒu
	int y;						//Y�ʒu
	int width;					//��
	int height;					//����

}IMAGE;	//�摜�\����

typedef struct STRUCT_MAP_IMAGE
{
	char path[PATH_MAX];				//�p�X
	int handle[MAP_DIV_NUM];			//���������̒e�̉摜�n���h�����擾
	int kind[MAP_DIV_NUM];				//�}�b�v�̎��
	int width;							//��
	int height;							//����
}MAPCHIP;	//MAP_IMAGE�\����

typedef struct STRUCT_MAP
{
	GAME_MAP_KIND kind;			//�}�b�v�̎��
	int x;						//X�ʒu
	int y;						//Y�ʒu
	int width;					//��
	int height;					//����
}MAP;	//MAP�\����

typedef struct STRUCT_I_POINT
{
	int x = -1;
	int y = -1;

}iPOINT;

typedef struct STRUCT_CHARA
{
	char path[PATH_MAX];
	IMAGE image;
	int speed;
	int CenterX;
	int CenterY;
	int handle[PLAYER_DIV_NUM];
	int Part;
	double Muki;		//0�F�O�@+1�F�E�@-1�F��
	 
	RECT coll; //�����蔻��
	iPOINT collBeforePt; //������O�̔���
}CHARA;



//�}�b�v
GAME_MAP_KIND MapData[MAP_HEIGHT_MAX][MAP_WIDTH_MAX] =
{
	/*0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
	3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
	3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
	3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
	3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
	3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
	3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
	3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
	3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
	3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
	3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
	3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
	3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
	3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
	3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
	3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
	3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3*/

	n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,
	n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,
	n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,
	k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,
	k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,
	k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,
	k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,
	k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,
	k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,
	k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,
	k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,
	k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,
	k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,
	k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,
	k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,
	k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,
	k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,
	k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,
	k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,
	k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k
};

GAME_MAP_KIND MapData_Object[MAP_HEIGHT_MAX][MAP_WIDTH_MAX] =
{	
	/*0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,67,68,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,75,76,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	151,151,151,151,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,350,351,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	151,151,151,151,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,151,151,151,151,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	151,151,151,151,0,0,0,0,0,0,0,0,0,151,151,151,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,151,151,151,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	151,151,151,151,0,0,0,0,0,0,0,0,151,151,151,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,151,0,0,0,0,151,151,0,0,0,0,
	151,151,151,151,0,0,0,0,0,0,0,0,0,0,151,0,0,151,0,0,0,151,0,0,0,
	0,0,0,0,0,0,151,151,151,151,0,0,0,0,0,0,0,0,0,0,0,151,0,0,0,
	151,151,151,151,0,0,0,0,0,151,151,0,0,0,0,0,0,0,0,0,151,151,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,151,0,151,151,0,0,151,0,0,0,0,
	151,151,151,151,0,0,0,0,0,0,0,0,0,151,151,0,0,151,0,151,151,0,0,0,0,
	0,0,0,0,0,0,0,0,151,151,0,151,151,151,0,0,0,151,151,151,0,0,0,0,0,
	151,151,151,151,0,0,0,0,0,151,151,151,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,151,151,151,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,151,0*/

	n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,
	n,n,n,a,b,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,
	n,n,n,c,h,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,
	d,d,d,d,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,e,f,
	n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,
	d,d,d,d,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,
	n,n,n,n,n,d,d,d,d,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,
	d,d,d,d,n,n,n,n,n,n,n,n,n,d,d,d,n,n,n,n,n,n,n,n,n,
	n,n,n,n,n,n,n,d,d,d,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,
	n,n,n,n,n,n,n,n,n,n,n,n,d,d,d,n,n,n,n,n,n,n,n,n,n,
	n,n,n,n,n,n,n,n,n,n,n,n,n,n,d,n,n,n,n,d,d,n,n,n,n,
	n,n,n,n,n,n,n,n,n,n,n,n,n,n,d,n,n,d,n,n,n,d,n,n,n,
	n,n,n,n,n,n,d,d,d,d,n,n,n,n,n,n,n,n,n,n,n,d,n,n,n,
	d,d,d,d,n,n,n,n,n,d,d,n,n,n,n,n,n,n,n,n,d,d,n,n,n,
	n,n,n,n,n,n,n,n,n,n,n,n,n,n,d,n,d,d,n,n,d,n,n,n,n,
	d,d,d,d,n,n,n,n,n,n,n,n,n,d,d,n,n,d,n,d,d,n,n,n,n,
	n,n,n,n,n,n,n,n,d,d,n,d,d,d,n,n,n,d,d,d,n,n,n,n,n,
	d,d,d,d,n,n,n,n,n,d,d,d,S,n,n,n,n,n,n,n,n,n,n,n,n,
	n,n,n,n,n,n,n,n,n,n,n,n,n,n,d,d,d,n,n,n,n,n,n,n,n,
	n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,d,n
};

GAME_MAP_KIND MapData_NoWalk[MAP_HEIGHT_MAX][MAP_WIDTH_MAX] =
{
	/*17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,
	25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,
	33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0*/

	t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,
	s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,
	g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,
	n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,G,
	n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,
	n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,
	n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,
	n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,
	n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,
	n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,
	n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,
	n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,
	n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,
	n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,
	n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,
	n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,
	n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,
	n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,
	n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,
	n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n
	
};

GAME_MAP_KIND MapData_Roka[MAP_HEIGHT_MAX][MAP_WIDTH_MAX] =
{
	
	n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,
	n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,
	n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,
	n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,
	n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,
	n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,
	r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,
	r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,
	r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,
	r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,
	r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,
	r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,
	n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,
	n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,
	n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,
	n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,
	n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,
	n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,
	n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,
	n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n
	

};

GAME_MAP_KIND MapData_RokaNoWalk[MAP_HEIGHT_MAX][MAP_WIDTH_MAX] =
{

	n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,
	n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,
	n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,
	t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,
	s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,
	g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,
	n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,
	n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,
	n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,
	n,n,S,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,
	n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,G,
	n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,
	g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,
	n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,
	n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,
	n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,
	n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,
	n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,
	n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,
	n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n


};

int mapDataInit[MAP_HEIGHT_MAX][MAP_WIDTH_MAX];
int mapDataInit_Nowalk[MAP_HEIGHT_MAX][MAP_WIDTH_MAX];
int mapDataInit_Object[MAP_HEIGHT_MAX][MAP_WIDTH_MAX];
int mapDataInit_Roka[MAP_HEIGHT_MAX][MAP_WIDTH_MAX];
int mapDataInit_RokaNoWalk[MAP_HEIGHT_MAX][MAP_WIDTH_MAX];

int mapdata[MAP_HEIGHT_MAX][MAP_WIDTH_MAX];
int mapdata2[MAP_HEIGHT_MAX][MAP_WIDTH_MAX];
int mapdata3[MAP_HEIGHT_MAX][MAP_WIDTH_MAX];
int mapdata4[MAP_HEIGHT_MAX][MAP_WIDTH_MAX];
int mapdata5[MAP_HEIGHT_MAX][MAP_WIDTH_MAX];
int mapdata6[MAP_HEIGHT_MAX][MAP_WIDTH_MAX];


int MapDataMode[MAP_HEIGHT_MAX][MAP_WIDTH_MAX];

//�}�b�v�`�b�v�̉摜���Ǘ�
MAPCHIP mapChip;
MAPCHIP mapChip_Nowalk;
MAPCHIP mapChip_Object;
MAPCHIP mapChip_Roka;
MAPCHIP mapChip_RokaNowalk;
CHARA player;

//�}�b�v�̏ꏊ���Ǘ�
MAP map[MAP_HEIGHT_MAX][MAP_WIDTH_MAX];
MAP map2[MAP_HEIGHT_MAX][MAP_WIDTH_MAX];
MAP map3[MAP_HEIGHT_MAX][MAP_WIDTH_MAX];
MAP map4[MAP_HEIGHT_MAX][MAP_WIDTH_MAX];
MAP map5[MAP_HEIGHT_MAX][MAP_WIDTH_MAX];


RECT mapColl[MAP_HEIGHT_MAX][MAP_WIDTH_MAX]; //�}�b�v�̓����蔻��

//�C���[�W�\���̂̕���
IMAGE imageBACK; //�^�C�g���w�i
IMAGE ImageSetumei; //������ʂ̉摜
iPOINT startPt{ -1, -1 };
iPOINT startPt2{ -1 , -1 };
RECT GoalRect = { -1,-1, -1, -1 };	//�S�[���̓����蔻��
RECT GoalRect2 = { -1, -1 , -1, -1 };
RECT Modoru = { -1, -1, -1,-1 }; //��O�̕����ɖ߂锻��
iPOINT ModoruPt{ -1,-1 };

int GameScene;		//�Q�[���V�[�����Ǘ�
//�L�[�{�[�h�̓��͂��擾
char AllKeyState[KEY_CODE_KIND] = { '\0' };		//���ׂẴL�[�̏�Ԃ�����
char OldAllKeyState[KEY_CODE_KIND] = { '\0' };	//���ׂẴL�[�̏��(���O)������

//FPS�֘A
int StartTimeFps;				//����J�n����
int CountFps;					//�J�E���^
float CalcFps;					//�v�Z����
int SampleNumFps = GAME_FPS;	//���ς����T���v����
char key[256];
int playerhandle[16];

int count;

int x;
int y;
int result = 0;			//�t�@�C���̍Ōォ�`�F�b�N
int tateCnt = 0;		//�c�J�E���g�p
int yokoCnt = 0;		//���J�E���g�p

FILE* fp = NULL;




VOID MY_FPS_UPDATE(VOID);			//FPS�l���v���A�X�V����
BOOL LOAD_IMAGE(VOID);		//�摜���܂Ƃ߂ēǂݍ��ފ֐�
VOID DELETE_IMAGE(VOID);		//�摜���܂Ƃ߂č폜����֐�

VOID MY_FPS_WAIT(VOID);				//FPS�l���v�����A�҂�

BOOL LOAD_MUSIC(VOID);		//���y���܂Ƃ߂ēǂݍ��ފ֐�
VOID DELETE_MUSIC(VOID);		//���y���܂Ƃ߂č폜����֐�
VOID MY_ALL_KEYDOWN_UPDATE(VOID);	//�L�[�̓��͏�Ԃ��X�V����
BOOL MY_KEY_DOWN(int);				//�L�[�������Ă��邩�A�L�[�R�[�h�Ŕ��f����
BOOL MY_KEY_UP(int);				//�L�[�������グ�����A�L�[�R�[�h�Ŕ��f����
BOOL MY_KEYDOWN_KEEP(int, int);		//�L�[�����������Ă��邩�A�L�[�R�[�h�Ŕ��f����


VOID MY_START(VOID);		//�X�^�[�g���
VOID MY_START_PROC(VOID);	//�X�^�[�g��ʂ̏���
VOID MY_START_DRAW(VOID);	//�X�^�[�g��ʂ̕`��

VOID MY_SETUMEI(VOID); //�������
VOID MY_START_SETUMEI_DRAW(VOID); //������ʂ̕`��

VOID MY_PLAY_INIT(VOID);	//�v���C��ʏ�����
VOID MY_PLAY(VOID);			//�v���C���
VOID MY_PLAY_PROC(VOID);	//�v���C��ʂ̏���
VOID MY_PLAY_DRAW(VOID);	//�v���C��ʂ̕`��
VOID MY_PLAY2(VOID);		//�L�����
VOID MY_PLAY_PROC2(VOID);   //�L���̏���
VOID MY_PLAY_DRAW2(VOID);	//�L���̃X�e�[�W�`��

VOID MY_END(VOID);			//�G���h���
VOID MY_END_PROC(VOID);		//�G���h��ʂ̏���
VOID MY_END_DRAW(VOID);		//�G���h��ʂ̕`��

BOOL MY_CHECK_MAP1_PLAYER_COLL(RECT);	//�}�b�v�ƃv���C���[�̓����蔻�������֐�
BOOL MY_CHECK_RECT_COLL(RECT, RECT);	//�̈�̓����蔻�������֐�
BOOL MY_CHECK_MAP2_PLAYER_COLL(RECT);
BOOL MY_CHECK_RECT2_COLL(RECT, RECT);




//########## �v���O�����ōŏ��Ɏ��s�����֐� ##########
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetOutApplicationLogValidFlag(FALSE);				//Log.txt���o�͂��Ȃ�
	ChangeWindowMode(TRUE);								//�E�B���h�E���[�h�ɐݒ�
	SetGraphMode(GAME_WIDTH, GAME_HEIGHT, GAME_COLOR);	//�w��̐��l�ŃE�B���h�E��\������
	SetWindowStyleMode(0);				//�^�C�g���o�[�̓f�t�H���g�ɂ���
	SetAlwaysRunFlag(TRUE);								//��A�N�e�B�u�ł����s����
	
	SetWindowUserCloseEnableFlag(FALSE);				//����{�^���ŁA����ɃE�B���h�E�����Ȃ��悤�ɂ���

	if (DxLib_Init() == -1) { return -1; }	//�c�w���C�u��������������

	if (LOAD_IMAGE() == FALSE) { return -1; }

	//���y��ǂݍ���
	if (LOAD_MUSIC() == FALSE) { return -1; }

	GameScene = GAME_SCENE_START;	//�Q�[���V�[���̓X�^�[�g��ʂ���
	SetDrawScreen(DX_SCREEN_BACK);	//Draw�n�֐��͗���ʂɕ`��

	fp = fopen(".\\sakuhin_remake.txt", "r");


	if (fp == NULL) { exit(EXIT_FAILURE); }	//�v���O�������G���[�Ƃ��ċ����I��}
	int result = 0;			//�t�@�C���̍Ōォ�`�F�b�N
	int tateCnt = 0;		//�c�J�E���g�p
	int yokoCnt = 0;		//���J�E���g�p
	while (result != EOF)	//End Of File�i�t�@�C���̍Ō�j�ł͂Ȃ��Ƃ��J��Ԃ�
	{
		char mapData[MAP_WIDTH_MAX * 3 + 1];
		//�t�@�C�����琔�l����ǂݍ���(%d,)�A�z��Ɋi�[����
		result = fscanf(fp, "%s,", mapData);
		for (int i = 0; i < strlen(mapData); i++)
		{
			switch (mapData[i])
			{
			case 'n':
				//�ʘH�̂Ƃ�
				mapdata[tateCnt][yokoCnt] = n;
				yokoCnt++;
				break;
			case 'k':
				//�ǂ̂Ƃ�
				mapdata[tateCnt][yokoCnt] = k;
				yokoCnt++;
				break;

			case 't':
				mapdata[tateCnt][yokoCnt] = t;
				yokoCnt++;
				break;
			case 's':
				mapdata[tateCnt][yokoCnt] = s;
				yokoCnt++;
				break;
			case 'g':
				mapdata[tateCnt][yokoCnt] = g;
				yokoCnt++;
				break;
			case 'S':
				//�X�^�[�g�̂Ƃ�
				mapdata[tateCnt][yokoCnt] = S;
				yokoCnt++;
				break;
			case 'G':
				//�S�[���̂Ƃ�
				mapdata[tateCnt][yokoCnt] = G;
				yokoCnt++;
				break;
			default:
				break;
			}
		}



		//���̃f�[�^���P�s�ǂ߂���
		if (yokoCnt >= MAP_WIDTH_MAX)
		{
			tateCnt++;		//�c�̃J�E���g�A�b�v
			yokoCnt = 0;	//���̃J�E���^������
		}
	}

	//�J������A�K�����邱�ƁI
	fclose(fp);	//�t�@�C�������

	result = 0;
	tateCnt = 0;
	yokoCnt = 0;

	fp = fopen(".\\sakuhin_remake_nowalk.txt", "r");

	while (result != EOF)	//End Of File�i�t�@�C���̍Ō�j�ł͂Ȃ��Ƃ��J��Ԃ�
	{
		char mapData[MAP_WIDTH_MAX * 3 + 1];
		//�t�@�C�����琔�l����ǂݍ���(%d,)�A�z��Ɋi�[����
		result = fscanf(fp, "%s,", mapData);
		for (int i = 0; i < strlen(mapData); i++)
		{
			switch (mapData[i])
			{
			case 'n':
				//�ʘH�̂Ƃ�
				mapdata2[tateCnt][yokoCnt] = n;
				yokoCnt++;
				break;
			case 'k':
				//�ǂ̂Ƃ�
				mapdata2[tateCnt][yokoCnt] = k;
				yokoCnt++;
				break;

			case 't':
				mapdata2[tateCnt][yokoCnt] = t;
				yokoCnt++;
				break;
			case 's':
				mapdata2[tateCnt][yokoCnt] = s;
				yokoCnt++;
				break;
			case 'g':
				mapdata2[tateCnt][yokoCnt] = g;
				yokoCnt++;
				break;
			case 'S':
				//�X�^�[�g�̂Ƃ�
				mapdata2[tateCnt][yokoCnt] = S;
				yokoCnt++;

				//�X�^�[�g�ʒu���v�Z
				startPt.x = mapChip.width * yokoCnt + mapChip.width / 2;	//���SX���W���擾
				startPt.y = mapChip.height * tateCnt + mapChip.height / 2;	//���SY���W���擾
				break;
			case 'G':
				//�S�[���̂Ƃ�
				mapdata2[tateCnt][yokoCnt] = G;
				yokoCnt++;

				GoalRect.left = mapChip.width * yokoCnt;
				GoalRect.top = mapChip.height * tateCnt;
				GoalRect.right = mapChip.width * (yokoCnt + 1);
				GoalRect.bottom = mapChip.height * (tateCnt + 1);

			case 'M':
				mapdata2[tateCnt][yokoCnt] = M;
				yokoCnt++;

				ModoruPt.x = mapChip.width * yokoCnt + mapChip.width -125;	//���SX���W���擾
				ModoruPt.y = mapChip.height * tateCnt + mapChip.height -40;	//���SY���W���擾
				
				break;
			default:
				break;
			}
		}



		//���̃f�[�^���P�s�ǂ߂���
		if (yokoCnt >= MAP_WIDTH_MAX)
		{
			tateCnt++;		//�c�̃J�E���g�A�b�v
			yokoCnt = 0;	//���̃J�E���^������
		}
	}

	//�J������A�K�����邱�ƁI
	fclose(fp);	//�t�@�C�������
	result = 0;
	tateCnt = 0;
	yokoCnt = 0;

	fp = fopen(".\\sakuhin_remake_object.txt", "r");

	while (result != EOF)	//End Of File�i�t�@�C���̍Ō�j�ł͂Ȃ��Ƃ��J��Ԃ�
	{
		char mapData[MAP_WIDTH_MAX * 3 + 1];
		//�t�@�C�����琔�l����ǂݍ���(%d,)�A�z��Ɋi�[����
		result = fscanf(fp, "%s,", mapData);
		for (int i = 0; i < strlen(mapData); i++)
		{
			switch (mapData[i])
			{
			case 'a':
				//�ʘH�̂Ƃ�
				mapdata3[tateCnt][yokoCnt] = a;
				yokoCnt++;
				break;
			case 'b':
				//�ǂ̂Ƃ�
				mapdata3[tateCnt][yokoCnt] = b;
				yokoCnt++;
				break;

			case 'c':
				mapdata3[tateCnt][yokoCnt] = c;
				yokoCnt++;
				break;
			case 'h':
				mapdata3[tateCnt][yokoCnt] = h;
				yokoCnt++;
				break;
			case 'e':
				mapdata3[tateCnt][yokoCnt] = e;
				yokoCnt++;
				break;
			case 'f':
				//�X�^�[�g�̂Ƃ�
				mapdata3[tateCnt][yokoCnt] = f;
				yokoCnt++;
				break;
			case 'd':
				//�X�^�[�g�̂Ƃ�
				mapdata3[tateCnt][yokoCnt] = d;
				yokoCnt++;
				break;
			case 'n':
				//�X�^�[�g�̂Ƃ�
				mapdata3[tateCnt][yokoCnt] = n;
				yokoCnt++;
				break;
			default:
				break;
			}
		}



		//���̃f�[�^���P�s�ǂ߂���
		if (yokoCnt >= MAP_WIDTH_MAX)
		{
			tateCnt++;		//�c�̃J�E���g�A�b�v
			yokoCnt = 0;	//���̃J�E���^������
		}
	}

	fclose(fp);	//�t�@�C�������


	//-----------------------�L��csv-----------------------
	result = 0;
	tateCnt = 0;
	yokoCnt = 0;

	fp = fopen(".\\sakuhin_roka.txt", "r");

	while (result != EOF)	//End Of File�i�t�@�C���̍Ō�j�ł͂Ȃ��Ƃ��J��Ԃ�
	{
		char mapData[MAP_WIDTH_MAX * 3 + 1];
		//�t�@�C�����琔�l����ǂݍ���(%d,)�A�z��Ɋi�[����
		result = fscanf(fp, "%s,", mapData);
		for (int i = 0; i < strlen(mapData); i++)
		{
			switch (mapData[i])
			{
			case 'n':
				//�ʘH�̂Ƃ�
				mapdata4[tateCnt][yokoCnt] = n;
				yokoCnt++;
				break;
			case 'r':
				//�ǂ̂Ƃ�
				mapdata4[tateCnt][yokoCnt] = r;
				yokoCnt++;
				break;

			default:
				break;
			}
		}



		//���̃f�[�^���P�s�ǂ߂���
		if (yokoCnt >= MAP_WIDTH_MAX)
		{
			tateCnt++;		//�c�̃J�E���g�A�b�v
			yokoCnt = 0;	//���̃J�E���^������
		}
	}

	//�J������A�K�����邱�ƁI
	fclose(fp);	//�t�@�C�������

	result = 0;
	tateCnt = 0;
	yokoCnt = 0;

	fp = fopen(".\\sakuhin_roka_nowalk.txt", "r");

	while (result != EOF)	//End Of File�i�t�@�C���̍Ō�j�ł͂Ȃ��Ƃ��J��Ԃ�
	{
		char mapData[MAP_WIDTH_MAX * 3 + 1];
		//�t�@�C�����琔�l����ǂݍ���(%d,)�A�z��Ɋi�[����
		result = fscanf(fp, "%s,", mapData);
		for (int i = 0; i < strlen(mapData); i++)
		{
			switch (mapData[i])
			{
			case 't':
				//�ʘH�̂Ƃ�
				mapdata5[tateCnt][yokoCnt] = t;
				yokoCnt++;
				break;
			case 's':
				//�ǂ̂Ƃ�
				mapdata5[tateCnt][yokoCnt] = s;
				yokoCnt++;
				break;
			case 'g':
				//�ǂ̂Ƃ�
				mapdata5[tateCnt][yokoCnt] = g;
				yokoCnt++;
				break;
			case 'n':
				//�ǂ̂Ƃ�
				mapdata5[tateCnt][yokoCnt] = n;
				yokoCnt++;
				break;

			case 'S':
				//�ǂ̂Ƃ�
				mapdata5[tateCnt][yokoCnt] = S;
				yokoCnt++;
				//�X�^�[�g�ʒu���v�Z
				startPt2.x = mapChip.width * yokoCnt + mapChip.width / 2;	//���SX���W���擾
				startPt2.y = mapChip.height * tateCnt + mapChip.height / 2;	//���SY���W���擾
				break;
			case 'G':
				//�ǂ̂Ƃ�
				mapdata5[tateCnt][yokoCnt] = G;
				yokoCnt++;
				//�S�[�����v�Z
				GoalRect2.left = mapChip.width * yokoCnt;
				GoalRect2.top = mapChip.height * tateCnt;
				GoalRect2.right = mapChip.width * (yokoCnt + 1);
				GoalRect2.bottom = mapChip.height * (tateCnt + 1);

			case 'u':
				//�ǂ̂Ƃ�
				mapdata5[tateCnt][yokoCnt] = u;
				yokoCnt++;
				break;

				break;
			default:
				break;
			}
		}



		//���̃f�[�^���P�s�ǂ߂���
		if (yokoCnt >= MAP_WIDTH_MAX)
		{
			tateCnt++;		//�c�̃J�E���g�A�b�v
			yokoCnt = 0;	//���̃J�E���^������
		}
	}

	//�J������A�K�����邱�ƁI
	fclose(fp);	//�t�@�C�������

	result = 0;
	tateCnt = 0;
	yokoCnt = 0;

	fp = fopen(".\\sakuhin_roka_maenimodoru.txt", "r");

	while (result != EOF)	//End Of File�i�t�@�C���̍Ō�j�ł͂Ȃ��Ƃ��J��Ԃ�
	{
		char mapData[MAP_WIDTH_MAX * 3 + 1];
		//�t�@�C�����琔�l����ǂݍ���(%d,)�A�z��Ɋi�[����
		result = fscanf(fp, "%s,", mapData);
		for (int i = 0; i < strlen(mapData); i++)
		{
			switch (mapData[i])
			{
			case 'n':
				//�ʘH�̂Ƃ�
				mapdata6[tateCnt][yokoCnt] = n;
				yokoCnt++;
				break;
			case 'M':
				//�ǂ̂Ƃ�
				mapdata6[tateCnt][yokoCnt] = M;
				yokoCnt++;
				Modoru.left = mapChip.width * yokoCnt;
				Modoru.top = mapChip.height * tateCnt;
				Modoru.right = mapChip.width;
				Modoru.bottom = mapChip.height * (tateCnt + 1);
				break;
			default:
				break;
			}
		}



		//���̃f�[�^���P�s�ǂ߂���
		if (yokoCnt >= MAP_WIDTH_MAX)
		{
			tateCnt++;		//�c�̃J�E���g�A�b�v
			yokoCnt = 0;	//���̃J�E���^������
		}
	}

	fclose(fp);	//�t�@�C�������
	
				
		
	//�������[�v
	while (TRUE)
	{
		if (ProcessMessage() != 0) { break; }	//���b�Z�[�W�����̌��ʂ��G���[�̂Ƃ��A�����I��
		if (ClearDrawScreen() != 0) { break; }	//��ʂ������ł��Ȃ������Ƃ��A�����I��

		//��ʂ̕���{�^���������ꂽ�Ƃ�
		if (GetWindowUserCloseFlag(TRUE))
		{
			//�I���_�C�A���O��\��
			int Ret = MessageBox(GetMainWindowHandle(), MSG_CLOSE_CAPTION, MSG_CLOSE_TITLE, MB_YESNO | MB_ICONASTERISK);
			if (Ret == IDYES) { break; }	//YES�Ȃ�A�Q�[���𒆒f����
		}

		MY_ALL_KEYDOWN_UPDATE();				//�����Ă���L�[��Ԃ��擾

		

		

		MY_FPS_UPDATE();	//FPS�̏���[�X�V]


		//�V�[�����Ƃɏ������s��
		switch (GameScene)
		{
		case GAME_SCENE_START:
			MY_START();	//�X�^�[�g���
			break;

		case GAME_SCENE_SETUMEI:
			MY_SETUMEI(); //�������
			break; 

		case GAME_SCENE_PLAY:
			MY_PLAY();	//�v���C���
			break;
		case GAME_SCENE_PLAY2:
			MY_PLAY2(); //�L�����
			break;
		case GAME_SCENE_END:
			MY_END();	//�G���h���
			break;
		}

		

		ScreenFlip();		//���j�^�̃��t���b�V�����[�g�̑����ŗ���ʂ��ĕ`��

		MY_FPS_WAIT();		//FPS�̏���[�҂�]
	}


	//�摜�n���h����j��
	DELETE_IMAGE();

	//���y�n���h����j��
	DELETE_MUSIC();

	DxLib_End();	//�c�w���C�u�����g�p�̏I������

	return 0;
}


//########## FPS�l���v���A�X�V����֐� ##########
VOID MY_FPS_UPDATE(VOID)
{
	if (CountFps == 0) //1�t���[���ڂȂ玞�����L��
	{
		StartTimeFps = GetNowCount();
	}

	if (CountFps == SampleNumFps) //60�t���[���ڂȂ畽�ς��v�Z
	{
		int now = GetNowCount();
		//���݂̎��Ԃ���A0�t���[���ڂ̎��Ԃ������AFPS�̐��l�Ŋ��遁1FPS�ӂ�̕��ώ��Ԃ��v�Z�����
		CalcFps = 1000.f / ((now - StartTimeFps) / (float)SampleNumFps);
		CountFps = 0;
		StartTimeFps = now;
	}
	CountFps++;
	return;
}

//########## FPS�l���v�����A�҂֐� ##########
VOID MY_FPS_WAIT(VOID)
{
	int resultTime = GetNowCount() - StartTimeFps;					//������������
	int waitTime = CountFps * 1000 / GAME_FPS - resultTime;	//�҂ׂ�����

	if (waitTime > 0)		//�w���FPS�l���������ꍇ
	{
		WaitTimer(waitTime);	//�҂�
	}
	return;
}

//########## �L�[�̓��͏�Ԃ��X�V����֐� ##########
VOID MY_ALL_KEYDOWN_UPDATE(VOID)
{

	//�ꎞ�I�ɁA���݂̃L�[�̓��͏�Ԃ��i�[����
	char TempKey[KEY_CODE_KIND];

	//���O�̃L�[���͂��Ƃ��Ă���
	for (int i = 0; i < KEY_CODE_KIND; i++)
	{
		OldAllKeyState[i] = AllKeyState[i];
	}

	GetHitKeyStateAll(TempKey); // �S�ẴL�[�̓��͏�Ԃ𓾂�

	for (int i = 0; i < KEY_CODE_KIND; i++)
	{
		if (TempKey[i] != 0)	//������Ă���L�[�̃L�[�R�[�h�������Ă���Ƃ�
		{
			AllKeyState[i]++;	//������Ă���
		}
		else
		{
			AllKeyState[i] = 0;	//������Ă��Ȃ�
		}
	}
	return;
}

//�L�[�������Ă��邩�A�L�[�R�[�h�Ŕ��f����
//���@���Fint�F�L�[�R�[�h�FKEY_INPUT_???
BOOL MY_KEY_DOWN(int KEY_INPUT_)
{
	//�L�[�R�[�h�̃L�[�������Ă��鎞
	if (AllKeyState[KEY_INPUT_] != 0)
	{
		return TRUE;	//�L�[�������Ă���
	}
	else
	{
		return FALSE;	//�L�[�������Ă��Ȃ�
	}
}

//�X�^�[�g���
VOID MY_START(VOID)
{
	MY_START_PROC();	//�X�^�[�g��ʂ̏���
	MY_START_DRAW();	//�X�^�[�g��ʂ̕`��
	

	
	DrawString(0, 0, "�X�^�[�g���(�G���^�[�L�[�������ĉ�����)", GetColor(255, 255, 255));
	return;
}

//�X�^�[�g��ʂ̏���
VOID MY_START_PROC(VOID)
{
	
	//�G���^�[�L�[����������A�v���C�V�[���ֈړ�����
	if (MY_KEY_DOWN(KEY_INPUT_RETURN) == TRUE)
	{

		//�Q�[���̃V�[�����v���C��ʂɂ���
		GameScene = GAME_SCENE_SETUMEI;

		return;
	}

	return;
}

//�X�^�[�g��ʂ̕`��
VOID MY_START_DRAW(VOID)
{
	DrawGraph(imageBACK.x, imageBACK.y, imageBACK.handle, TRUE);
	/*DrawExtendGraph(imageBACK.x, imageBACK.y, 1136, 640, imageBACK.handle, TRUE);*/
	return;
}

VOID MY_SETUMEI(VOID)
{
	MY_START_SETUMEI_DRAW();//������ʂ̕`��
}
//������ʂ̕`��
VOID MY_START_SETUMEI_DRAW(VOID)
{
	DrawGraph(ImageSetumei.x, ImageSetumei.y, ImageSetumei.handle, TRUE);
	DrawString(0, 0, "�X�^�[�g���(H�L�[�������ĉ�����)", GetColor(255, 255, 255));

	if (MY_KEY_DOWN(KEY_INPUT_H) == TRUE)
	{
		GameScene = GAME_SCENE_PLAY;

		SetMouseDispFlag(FALSE);

		player.CenterX = startPt.x;
		player.CenterY = startPt.y;
	

		player.image.x = player.CenterX;
		player.image.y = player.CenterY;

		
	}

	return;
}

//�v���C���
VOID MY_PLAY(VOID)
{
	MY_PLAY_PROC();	//�v���C��ʂ̏���
	MY_PLAY_DRAW();	//�v���C��ʂ̕`��

	DrawString(0, 0, "�v���C���(�X�y�[�X�L�[�������ĉ�����)", GetColor(255, 255, 255));
	return;
}

//�v���C��ʂ̏���
VOID MY_PLAY_PROC(VOID)
{

	
	count++;
	//�X�y�[�X�L�[����������A�G���h�V�[���ֈړ�����
	if (MY_KEY_DOWN(KEY_INPUT_SPACE) == TRUE)
	{
		//�Q�[���̃V�[�����G���h��ʂɂ���
		GameScene = GAME_SCENE_END;

		return;
	}

	//�}�E�X���E�N���b�N����ƁA�^�C�g����ʂɖ߂�
	if (MY_KEY_DOWN(KEY_INPUT_L) == TRUE)
	{
		

		//�}�E�X��\��
		SetMouseDispFlag(TRUE);

		//�I���_�C�A���O��\��
		int Ret = MessageBox(GetMainWindowHandle(), MOUSE_R_CLICK_CAPTION, MOUSE_R_CLICK_TITLE, MB_YESNO);

		if (Ret == IDYES)		//YES�Ȃ�A�Q�[���𒆒f����
		{
			//�����I�Ƀ^�C�g����ʂɔ��
			GameScene = GAME_SCENE_START;
			return;

		}
		else if (Ret == IDNO)	//NO�Ȃ�A�Q�[���𑱍s����
		{

			//�}�E�X���\���ɂ���B
			SetMouseDispFlag(FALSE);
		}
	}
	int old_x = player.image.x;
	int old_y = player.image.y;
	BOOL IsMove = TRUE;

	/*if (count > 30)
	{*/
		if (MY_KEY_DOWN(KEY_INPUT_W) == TRUE)
		{
			player.image.y -= 1.5; //30


		}
		if (MY_KEY_DOWN(KEY_INPUT_S) == TRUE)
		{
			player.image.y += 1.5;//30


		}
		if (MY_KEY_DOWN(KEY_INPUT_A) == TRUE)
		{
			player.image.x -= 1.5;//30



		}
		if (MY_KEY_DOWN(KEY_INPUT_D) == TRUE)
		{
			player.image.x += 2;//30


		}
		/*count = 0;
	}*/

	//��ʓ��Ƀ}�E�X�������
		if (player.image.x >= 0 && player.image.x <= GAME_WIDTH
			&& player.image.y >= 0 && player.image.y <= GAME_HEIGHT)
		{
			//�v���C���[�̒��S�ʒu��ݒ肷��
			player.CenterX = player.image.x;
			player.CenterY = player.image.y;
		}

		//�v���C���[�̓����蔻��̐ݒ�
		player.coll.left = player.CenterX - 40 / 20 + 5;
		player.coll.top = player.CenterY + 200 / 20 + 5;
		player.coll.right = player.CenterX + 650 / 20 - 5;
		player.coll.bottom = player.CenterY + 1000 / 20 - 5;

		RECT PlayerRect;
		PlayerRect.left = player.CenterX - 40 / 20 + 5;
		PlayerRect.top = player.CenterY + 200 / 20 + 5;
		PlayerRect.right = player.CenterX + 650 / 20 - 5;
		PlayerRect.bottom = player.CenterY + 1000 / 20 - 5;
		//�S�[���ɐG��Ă��邩�`�F�b�N
		if (MY_CHECK_RECT_COLL(PlayerRect, GoalRect) == TRUE)
		{
			

			player.CenterX = startPt2.x;
			player.CenterY = startPt2.y;


			player.image.x = player.CenterX;
			player.image.y = player.CenterY;

			GameScene = GAME_SCENE_PLAY2;
		

			return;	//�����I�ɃG���h��ʂɔ��
		}

		//�v���C���[����ʊO�ɏo����
		/*if (player.image.x > GAME_WIDTH || player.image.y > GAME_HEIGHT
			|| player.image.x + player.image.width < 0 || player.image.y + player.image.height < 0)
		{
			
			IsMove = false;
			
		}*/

	

		

		//�v���C���[�ƃ}�b�v���������Ă�����
		if (MY_CHECK_MAP1_PLAYER_COLL(player.coll) == TRUE)
		{
			SetMousePoint(player.collBeforePt.x, player.collBeforePt.y);
			IsMove = false;
			

		}

		if (IsMove == false)
		{
			player.image.x = old_x;
			player.image.y = old_y;
		}
		
		
		if (IsMove == TRUE) 
		{
		
			{
				////�v���C���[�̈ʒu�ɒu��������
				//player.image.x = player.CenterX - player.image.width / 2;
				//player.image.y = player.CenterY - player.image.height / 2;

				//�������Ă��Ȃ��Ƃ��̍��W���擾
				player.collBeforePt.x = player.CenterX;
				player.collBeforePt.y = player.CenterY;
			}
		}

		////��ʊO�Ƀv���C���[���s���Ȃ��悤�ɂ���
		//if (player.coll.top < 0) { player.image.x = 0; }
		//if (player.coll.top + player.coll.right > GAME_WIDTH) { player.image.x = GAME_WIDTH - player.image.width; }
		//if (player.coll.bottom < 0) { player.image.y = 0; }
		//if (player.coll.bottom + player.coll.left > GAME_HEIGHT) { player.image.y = GAME_HEIGHT - player.image.height; }
	
	

	return;
}

//�v���C��ʂ̕`��
VOID MY_PLAY_DRAW(VOID)
{

	for (int tate = 0; tate < MAP_HEIGHT_MAX; tate++)
	{
		for (int yoko = 0; yoko < MAP_WIDTH_MAX; yoko++)
		{
			
				
				DrawGraph(yoko * mapChip.width,
					tate * mapChip.height,
					mapChip.handle[mapdata[tate][yoko]],
					TRUE);
			
			
		}

	}

	for (int tate = 0; tate < MAP_HEIGHT_MAX; tate++)
	{
		for (int yoko = 0; yoko < MAP_WIDTH_MAX; yoko++)
		{

			
			DrawGraph(yoko * mapChip.width,
				tate * mapChip.height,
				mapChip.handle[mapdata2[tate][yoko]],
				TRUE);


		}

	}


	for (int tate = 0; tate < MAP_HEIGHT_MAX; tate++)
	{
		for (int yoko = 0; yoko < MAP_WIDTH_MAX; yoko++)
		{

			//�����̂Ƃ�
			DrawGraph(yoko * mapChip.width,
				tate * mapChip.height,
				mapChip.handle[mapdata3[tate][yoko]],
				TRUE);


		}

	}
	
	
	
	DrawGraph(player.image.x, player.image.y, playerhandle[13], TRUE);

	//�����蔻��̕`��i�f�o�b�O�p�j
	for (int tate = 0; tate < MAP_HEIGHT_MAX; tate++)
	{
		for (int yoko = 0; yoko < MAP_WIDTH_MAX; yoko++)
		{
			//�_���{�[���Ȃ��
			if (mapdata3[tate][yoko] == d)
			{
				DrawBox(mapColl[tate][yoko].left, mapColl[tate][yoko].top, mapColl[tate][yoko].right, mapColl[tate][yoko].bottom, GetColor(255, 0, 0), FALSE);
			}

		}
	}
	//�S�[�������蔻��p
	DrawBox(GoalRect.left, GoalRect.top, GoalRect.right, GoalRect.bottom, GetColor(255, 255, 0), TRUE);
	//�v���C���[�̓����蔻��p
	DrawBox(player.coll.left, player.coll.top, player.coll.right, player.coll.bottom, GetColor(255, 0, 0), FALSE);



	return;
}

VOID MY_PLAY2(VOID)
{

	MY_PLAY_PROC2();
	MY_PLAY_DRAW2();
	return;
}

VOID MY_PLAY_PROC2(VOID)
{
	
	//�}�E�X���E�N���b�N����ƁA�^�C�g����ʂɖ߂�
	if (MY_KEY_DOWN(KEY_INPUT_L) == TRUE)
	{


		//�}�E�X��\��
		SetMouseDispFlag(TRUE);

		//�I���_�C�A���O��\��
		int Ret = MessageBox(GetMainWindowHandle(), MOUSE_R_CLICK_CAPTION, MOUSE_R_CLICK_TITLE, MB_YESNO);

		if (Ret == IDYES)		//YES�Ȃ�A�Q�[���𒆒f����
		{
			//�����I�Ƀ^�C�g����ʂɔ��
			GameScene = GAME_SCENE_START;
			return;

		}
		else if (Ret == IDNO)	//NO�Ȃ�A�Q�[���𑱍s����
		{

			//�}�E�X���\���ɂ���B
			SetMouseDispFlag(FALSE);
		}
	}

	int old_x = player.image.x;
	int old_y = player.image.y;
	BOOL IsMove = TRUE;

	/*if (count > 30)
	{*/
	if (MY_KEY_DOWN(KEY_INPUT_W) == TRUE)
	{
		player.image.y -= 1.5; //30


	}
	if (MY_KEY_DOWN(KEY_INPUT_S) == TRUE)
	{
		player.image.y += 1.5;//30


	}
	if (MY_KEY_DOWN(KEY_INPUT_A) == TRUE)
	{
		player.image.x -= 1.5;//30



	}
	if (MY_KEY_DOWN(KEY_INPUT_D) == TRUE)
	{
		player.image.x += 2;//30


	}
	/*count = 0;*/


//��ʓ��ɃL�����������
	if (player.image.x >= 0 && player.image.x <= GAME_WIDTH
		&& player.image.y >= 0 && player.image.y <= GAME_HEIGHT)
	{
		//�v���C���[�̒��S�ʒu��ݒ肷��
		player.CenterX = player.image.x;
		player.CenterY = player.image.y;
	}

	//�v���C���[�̓����蔻��̐ݒ�
	player.coll.left = player.CenterX - 40 / 20 + 5;
	player.coll.top = player.CenterY + 200 / 20 + 5;
	player.coll.right = player.CenterX + 650 / 20 - 5;
	player.coll.bottom = player.CenterY + 1000 / 20 - 5;

	RECT PlayerRect;
	PlayerRect.left = player.CenterX - 40 / 20 + 5;
	PlayerRect.top = player.CenterY + 200 / 20 + 5;
	PlayerRect.right = player.CenterX + 650 / 20 - 5;
	PlayerRect.bottom = player.CenterY + 1000 / 20 - 5;
	//�S�[���ɐG��Ă��邩�`�F�b�N
	if (MY_CHECK_RECT_COLL(PlayerRect, GoalRect2) == TRUE)
	{




		/*GameScene = GAME_SCENE_PLAY2;*/
		

		return;	//�����I�ɃG���h��ʂɔ��
	}

	if (MY_CHECK_RECT_COLL(PlayerRect, Modoru) == TRUE)
	{



		player.CenterX = ModoruPt.x;
		player.CenterY = ModoruPt.y;


		player.image.x = player.CenterX;
		player.image.y = player.CenterY;

		GameScene = GAME_SCENE_PLAY;


		return;	//�����I�ɃG���h��ʂɔ��
	}


	//�v���C���[����ʊO�ɏo����
	/*if (player.image.x > GAME_WIDTH || player.image.y > GAME_HEIGHT
		|| player.image.x + player.image.width < 0 || player.image.y + player.image.height < 0)
	{

		IsMove = false;

	}*/





	//�v���C���[�ƃ}�b�v���������Ă�����
	if (MY_CHECK_MAP2_PLAYER_COLL(player.coll) == TRUE)
	{
		
		IsMove = false;


	}

	if (IsMove == false)
	{
		player.image.x = old_x;
		player.image.y = old_y;
	}


	if (IsMove == TRUE)
	{

		{
			////�v���C���[�̈ʒu�ɒu��������
			//player.image.x = player.CenterX - player.image.width / 2;
			//player.image.y = player.CenterY - player.image.height / 2;

			//�������Ă��Ȃ��Ƃ��̍��W���擾
			player.collBeforePt.x = player.CenterX;
			player.collBeforePt.y = player.CenterY;
		}
	}

	return;
}

VOID MY_PLAY_DRAW2(VOID)
{
	for (int tate = 0; tate < MAP_HEIGHT_MAX; tate++)
	{
		for (int yoko = 0; yoko < MAP_WIDTH_MAX; yoko++)
		{


			DrawGraph(yoko * mapChip.width,
				tate * mapChip.height,
				mapChip.handle[mapdata4[tate][yoko]],
				TRUE);


		}

	}

	for (int tate = 0; tate < MAP_HEIGHT_MAX; tate++)
	{
		for (int yoko = 0; yoko < MAP_WIDTH_MAX; yoko++)
		{


			DrawGraph(yoko * mapChip.width,
				tate * mapChip.height,
				mapChip.handle[mapdata5[tate][yoko]],
				TRUE);


		}

	}

	for (int tate = 0; tate < MAP_HEIGHT_MAX; tate++)
	{
		for (int yoko = 0; yoko < MAP_WIDTH_MAX; yoko++)
		{


			DrawGraph(yoko * mapChip.width,
				tate * mapChip.height,
				mapChip.handle[mapdata6[tate][yoko]],
				TRUE);


		}

	}

	DrawGraph(player.image.x, player.image.y, playerhandle[13], TRUE);

	//�����蔻��̕`��i�f�o�b�O�p�j
	for (int tate = 0; tate < MAP_HEIGHT_MAX; tate++)
	{
		for (int yoko = 0; yoko < MAP_WIDTH_MAX; yoko++)
		{
			//���Ȃ��
			//if (MapData_RokaNoWalk[tate][yoko] == s)
			//{
			//	DrawBox(mapColl[tate][yoko].left, mapColl[tate][yoko].top, mapColl[tate][yoko].right, mapColl[tate][yoko].bottom, GetColor(0, 0, 255), FALSE);
			//}

			////�_���{�[���Ȃ��
			//if (MapData_Object[tate][yoko] == d)
			//{
			//	DrawBox(mapColl[tate][yoko].left, mapColl[tate][yoko].top, mapColl[tate][yoko].right, mapColl[tate][yoko].bottom, GetColor(255, 0, 0), FALSE);
			//}
			////��ǂȂ��
			//if (MapData_RokaNoWalk[tate][yoko] == t)
			//{
			//	DrawBox(mapColl[tate][yoko].left, mapColl[tate][yoko].top, mapColl[tate][yoko].right, mapColl[tate][yoko].bottom, GetColor(255, 0, 0), FALSE);
			//}
			////����
			//if (MapData_RokaNoWalk[tate][yoko] == g)
			//{
			//	DrawBox(mapColl[tate][yoko].left, mapColl[tate][yoko].top, mapColl[tate][yoko].right, mapColl[tate][yoko].bottom, GetColor(255, 0, 0), FALSE);
			//}

			////���Ȃ��
			//if (MapData_NoWalk[tate][yoko] == s)
			//{
			//	DrawBox(mapColl[tate][yoko].left, mapColl[tate][yoko].top, mapColl[tate][yoko].right, mapColl[tate][yoko].bottom, GetColor(0, 0, 255), FALSE);
			//}

			////�_���{�[���Ȃ��
			//if (MapData_Object[tate][yoko] == d)
			//{
			//	DrawBox(mapColl[tate][yoko].left, mapColl[tate][yoko].top, mapColl[tate][yoko].right, mapColl[tate][yoko].bottom, GetColor(255, 0, 0), FALSE);
			//}
			////��ǂȂ��
			//if (MapData_NoWalk[tate][yoko] == t)
			//{
			//	DrawBox(mapColl[tate][yoko].left, mapColl[tate][yoko].top, mapColl[tate][yoko].right, mapColl[tate][yoko].bottom, GetColor(255, 0, 0), FALSE);
			//}
			////����
			if (mapdata6[tate][yoko] == M)
			{
				DrawBox(mapColl[tate][yoko].left, mapColl[tate][yoko].top, mapColl[tate][yoko].right, mapColl[tate][yoko].bottom, GetColor(255, 0, 0), FALSE);
			}

		}
	}
	//�S�[�������蔻��p
	DrawBox(GoalRect2.left, GoalRect2.top, GoalRect2.right, GoalRect2.bottom, GetColor(255, 255, 0), TRUE);
	//�v���C���[�̓����蔻��p
	DrawBox(player.coll.left, player.coll.top, player.coll.right, player.coll.bottom, GetColor(255, 0, 0), FALSE);
	return;
}

//�G���h���
VOID MY_END(VOID)
{
	MY_END_PROC();	//�G���h��ʂ̏���
	MY_END_DRAW();	//�G���h��ʂ̕`��


	return;
}

//�G���h��ʂ̏���
VOID MY_END_PROC(VOID)
{
	//�G�X�P�[�v�L�[����������A�X�^�[�g�V�[���ֈړ�����
	if (MY_KEY_DOWN(KEY_INPUT_ESCAPE) == TRUE)
	{
		GameScene = GAME_SCENE_START;
	}

	DrawString(0, 0, "�G���h���(�G�X�P�[�v�L�[�������ĉ�����)", GetColor(255, 255, 255));
	return;
}

//�G���h��ʂ̕`��
VOID MY_END_DRAW(VOID)
{

	return;
}


//�摜���܂Ƃ߂ēǂݍ��ފ֐�
BOOL LOAD_IMAGE(VOID)
{
	strcpy_s(imageBACK.path, TITLE_BACK_PATH);	//�^�C�g���w�i�摜�Ǎ�
	imageBACK.handle = LoadGraph(imageBACK.path);			//�ǂݍ���
	if (imageBACK.handle == -1)
	{
		//�G���[���b�Z�[�W�\��
		MessageBox(GetMainWindowHandle(), TITLE_BACK_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(imageBACK.handle, &imageBACK.width, &imageBACK.height);	//�摜�̕��ƍ������擾
	imageBACK.x = GAME_WIDTH / 2 - imageBACK.width / 2;		//���E��������
	imageBACK.y = GAME_HEIGHT / 2 - imageBACK.height / 2;		//�㉺��������

	strcpy_s(ImageSetumei.path, IMAGE_SETUMEI_PATH);	//������ʔw�i�摜�Ǎ�
	ImageSetumei.handle = LoadGraph(ImageSetumei.path);			//�ǂݍ���
	if (ImageSetumei.handle == -1)
	{
		//�G���[���b�Z�[�W�\��
		MessageBox(GetMainWindowHandle(), IMAGE_SETUMEI_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(ImageSetumei.handle, &ImageSetumei.width, &ImageSetumei.height);	//�摜�̕��ƍ������擾
	ImageSetumei.x = GAME_WIDTH / 2 - ImageSetumei.width / 2;		//���E��������
	ImageSetumei.y = GAME_HEIGHT / 2 - ImageSetumei.height / 2;		//�㉺��������

	int mapRes = LoadDivGraph(
		GAME_MAP_PATH,										//�Ԓe�̃p�X
		MAP_DIV_NUM, MAP_DIV_TATE, MAP_DIV_YOKO,			//�Ԓe�𕪊����鐔
		MAP_DIV_WIDTH, MAP_DIV_HEIGHT,						//�摜�𕪊�����̕��ƍ���
		&mapChip.handle[0]);								//���������摜������n���h��

	if (mapRes == -1)
	{
		//�G���[���b�Z�[�W�\��
		MessageBox(GetMainWindowHandle(), GAME_MAP_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	//���ƍ������擾
	GetGraphSize(mapChip.handle[0], &mapChip.width, &mapChip.height);

	for (int tate = 0; tate < MAP_HEIGHT_MAX; tate++)
	{
		for (int yoko = 0; yoko < MAP_WIDTH_MAX; yoko++)
		{
			//�}�b�v�f�[�^�������p�ɏ����R�s�[
			mapDataInit[tate][yoko] = MapData[tate][yoko];

			//�}�b�v�̎�ނ��R�s�[
			map[tate][yoko].kind = MapData[tate][yoko];

			//�}�b�v�̕��ƍ������R�s�[
			map[tate][yoko].width = mapChip.width;
			map[tate][yoko].height = mapChip.height;

			//�}�b�v�̍��W��ݒ�
			map[tate][yoko].x = yoko * map[tate][yoko].width;
			map[tate][yoko].y = tate * map[tate][yoko].height;
		}
	}

	int mapRes2 =LoadDivGraph(
		GAME_MAP_PATH,										//�Ԓe�̃p�X
		MAP_DIV_NUM, MAP_DIV_TATE, MAP_DIV_YOKO,			//�Ԓe�𕪊����鐔
		MAP_DIV_WIDTH, MAP_DIV_HEIGHT,						//�摜�𕪊�����̕��ƍ���
		&mapChip_Nowalk.handle[0]);								//���������摜������n���h��

	if (mapRes2 == -1)
	{
		//�G���[���b�Z�[�W�\��
		MessageBox(GetMainWindowHandle(), GAME_MAP_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	GetGraphSize(mapChip_Nowalk.handle[0], &mapChip_Nowalk.width, &mapChip_Nowalk.height);
	for (int tate = 0; tate < MAP_HEIGHT_MAX; tate++)
	{
		for (int yoko = 0; yoko < MAP_WIDTH_MAX; yoko++)
		{
			//�}�b�v�f�[�^�������p�ɏ����R�s�[
			mapDataInit_Nowalk[tate][yoko] = MapData_NoWalk[tate][yoko];

			//�}�b�v�̎�ނ��R�s�[
			map2[tate][yoko].kind = MapData_NoWalk[tate][yoko];

			//�}�b�v�̕��ƍ������R�s�[
			map2[tate][yoko].width = mapChip.width;
			map2[tate][yoko].height = mapChip.height;

			//�}�b�v�̍��W��ݒ�
			map2[tate][yoko].x = yoko * map2[tate][yoko].width;
			map2[tate][yoko].y = tate * map2[tate][yoko].height;
		}
	}


	


	int mapRes3 = LoadDivGraph(
		GAME_MAP_PATH,										//�Ԓe�̃p�X
		MAP_DIV_NUM, MAP_DIV_TATE, MAP_DIV_YOKO,			//�Ԓe�𕪊����鐔
		MAP_DIV_WIDTH, MAP_DIV_HEIGHT,						//�摜�𕪊�����̕��ƍ���
		&mapChip_Object.handle[0]);								//���������摜������n���h��

	if (mapRes3 == -1)
	{
		//�G���[���b�Z�[�W�\��
		MessageBox(GetMainWindowHandle(), GAME_MAP_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	GetGraphSize(mapChip_Object.handle[0], &mapChip_Object.width, &mapChip_Object.height);
	for (int tate = 0; tate < MAP_HEIGHT_MAX; tate++)
	{
		for (int yoko = 0; yoko < MAP_WIDTH_MAX; yoko++)
		{
			//�}�b�v�f�[�^�������p�ɏ����R�s�[
			mapDataInit_Object[tate][yoko] = MapData_Object[tate][yoko];

			//�}�b�v�̎�ނ��R�s�[
			map3[tate][yoko].kind = MapData_Object[tate][yoko];

			//�}�b�v�̕��ƍ������R�s�[
			map3[tate][yoko].width = mapChip.width;
			map3[tate][yoko].height = mapChip.height;

			//�}�b�v�̍��W��ݒ�
			map3[tate][yoko].x = yoko * map3[tate][yoko].width;
			map3[tate][yoko].y = tate * map3[tate][yoko].height;
		}
	}

	LoadDivGraph(
		GAME_PLAYER_PATH,										//�v���C���[�̃p�X
		PLAYER_DIV_NUM, PLAYER_DIV_TATE, PLAYER_DIV_YOKO,			//�Ԓe�𕪊����鐔
		PLAYER_DIV_WIDTH, PLAYER_DIV_HEIGHT,						//�摜�𕪊�����̕��ƍ���
		&playerhandle[0]);								//���������摜������n���h��

	strcpy_s(player.image.path, GAME_PLAYER_PATH);
	player.image.handle = LoadGraph(player.image.path);
	if (player.image.handle == -1)
	{
		MessageBox(GetMainWindowHandle(), GAME_PLAYER_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return(FALSE);
	}
	GetGraphSize(player.image.handle, &player.image.width, &player.image.height);
	player.image.x = GAME_WIDTH / 2 - player.image.width / 2;
	player.image.y = GAME_HEIGHT / 2 - player.image.height / 2;
	player.CenterX = player.image.x + player.image.width / 2;
	player.CenterY = player.image.y + player.image.height / 2;


	//�}�b�v�̓����蔻���ݒ肷��
	for (int tate = 0; tate < MAP_HEIGHT_MAX; tate++)
	{
		for (int yoko = 0; yoko < MAP_WIDTH_MAX; yoko++)
		{
			//�}�b�v�̓����蔻���ݒ�
			mapColl[tate][yoko].left = (yoko + 0) * mapChip.width + 1;
			mapColl[tate][yoko].top = (tate + 0) * mapChip.height + 1;
			mapColl[tate][yoko].right = (yoko + 1) * mapChip.width - 1;
			mapColl[tate][yoko].bottom = (tate + 1) * mapChip.height - 1;
		}
	}

	LoadDivGraph(
		GAME_MAP_PATH,										//�L���̃p�X
		MAP_DIV_NUM, MAP_DIV_TATE, MAP_DIV_YOKO,			//�}�b�v�`�b�v�𕪊����鐔
		MAP_DIV_WIDTH, MAP_DIV_HEIGHT,						//�摜�𕪊�����̕��ƍ���
		&mapChip_Roka.handle[0]);								//���������摜������n���h��

	GetGraphSize(mapChip_Roka.handle[0], &mapChip_Roka.width, &mapChip_Roka.height);
	for (int tate = 0; tate < MAP_HEIGHT_MAX; tate++)
	{
		for (int yoko = 0; yoko < MAP_WIDTH_MAX; yoko++)
		{
			//�}�b�v�f�[�^�������p�ɏ����R�s�[
			mapDataInit_Roka[tate][yoko] = MapData_Roka[tate][yoko];

			//�}�b�v�̎�ނ��R�s�[
			map4[tate][yoko].kind = MapData_Roka[tate][yoko];

			//�}�b�v�̕��ƍ������R�s�[
			map4[tate][yoko].width = mapChip.width;
			map4[tate][yoko].height = mapChip.height;

			//�}�b�v�̍��W��ݒ�
			map4[tate][yoko].x = yoko * map4[tate][yoko].width;
			map4[tate][yoko].y = tate * map4[tate][yoko].height;
		}
	}

	LoadDivGraph(
		GAME_MAP_PATH,										//�Ԓe�̃p�X
		MAP_DIV_NUM, MAP_DIV_TATE, MAP_DIV_YOKO,			//�Ԓe�𕪊����鐔
		MAP_DIV_WIDTH, MAP_DIV_HEIGHT,						//�摜�𕪊�����̕��ƍ���
		&mapChip_RokaNowalk.handle[0]);								//���������摜������n���h��

	GetGraphSize(mapChip_RokaNowalk.handle[0], &mapChip_RokaNowalk.width, &mapChip_RokaNowalk.height);
	for (int tate = 0; tate < MAP_HEIGHT_MAX; tate++)
	{
		for (int yoko = 0; yoko < MAP_WIDTH_MAX; yoko++)
		{
			//�}�b�v�f�[�^�������p�ɏ����R�s�[
			mapDataInit_RokaNoWalk[tate][yoko] = MapData_RokaNoWalk[tate][yoko];

			//�}�b�v�̎�ނ��R�s�[
			map5[tate][yoko].kind = MapData_RokaNoWalk[tate][yoko];

			//�}�b�v�̕��ƍ������R�s�[
			map5[tate][yoko].width = mapChip.width;
			map5[tate][yoko].height = mapChip.height;

			//�}�b�v�̍��W��ݒ�
			map5[tate][yoko].x = yoko * map5[tate][yoko].width;
			map5[tate][yoko].y = tate * map5[tate][yoko].height;
		}
	}
	return TRUE;
}

//�摜���܂Ƃ߂č폜����֐�
VOID DELETE_IMAGE(VOID)
{
	DeleteGraph(imageBACK.handle);
	DeleteGraph(ImageSetumei.handle);
	DeleteGraph(player.image.handle);
	for (int i_num = 0; i_num < MAP_DIV_NUM; i_num++) { DeleteGraph(mapChip.handle[i_num]); }
	for (int i_num = 0; i_num < MAP_DIV_NUM; i_num++) { DeleteGraph(mapChip_Nowalk.handle[i_num]); }
	for (int i_num = 0; i_num < MAP_DIV_NUM; i_num++) { DeleteGraph(mapChip_Object.handle[i_num]); }
	for (int i_num = 0; i_num < MAP_DIV_NUM; i_num++) { DeleteGraph(mapChip_Roka.handle[i_num]); }
	for (int i_num = 0; i_num < MAP_DIV_NUM; i_num++) { DeleteGraph(mapChip_RokaNowalk.handle[i_num]); }
	return;
}

//���y���܂Ƃ߂ēǂݍ��ފ֐�
BOOL LOAD_MUSIC(VOID)
{

	return TRUE;
}

//���y���܂Ƃ߂č폜����֐�
VOID DELETE_MUSIC(VOID)
{

	return;
}

//�}�b�v�ƃv���C���[�̓����蔻�������֐�
BOOL MY_CHECK_MAP1_PLAYER_COLL(RECT player)
{
	//�}�b�v�̓����蔻���ݒ肷��
	for (int tate = 0; tate < MAP_HEIGHT_MAX; tate++)
	{
		for (int yoko = 0; yoko < MAP_WIDTH_MAX; yoko++)
		{
			//�v���C���[�ƃ}�b�v���������Ă���Ƃ�
			if (MY_CHECK_RECT_COLL(player, mapColl[tate][yoko]) == TRUE)
			{
				/*if (GAME_SCENE_PLAY2 == TRUE)
				{
					return false;
				}*/
	
				//�ǂ̂Ƃ��́A�v���C���[�ƃ}�b�v���������Ă���
				if (mapdata3[tate][yoko] == d) { return TRUE; }
				if (mapdata2[tate][yoko] == t) { return TRUE; }
				if (mapdata2[tate][yoko] == s) { return TRUE; }
				if (mapdata2[tate][yoko] == g) { return TRUE; }
			
			}
		}
	}
	
	return FALSE;
}

//�̈�̓����蔻�������֐�
BOOL MY_CHECK_RECT_COLL(RECT a, RECT b)
{
	if (a.left < b.right &&
		a.top < b.bottom &&
		a.right > b.left &&
		a.bottom > b.top
		)
	{
		return TRUE;	//�������Ă���
	}

	return FALSE;		//�������Ă��Ȃ�
}

BOOL MY_CHECK_MAP2_PLAYER_COLL(RECT player)
{
	//�}�b�v�̓����蔻���ݒ肷��
	for (int tate = 0; tate < MAP_HEIGHT_MAX; tate++)
	{
		for (int yoko = 0; yoko < MAP_WIDTH_MAX; yoko++)
		{
			//�v���C���[�ƃ}�b�v���������Ă���Ƃ�
			if (MY_CHECK_RECT_COLL(player, mapColl[tate][yoko]) == TRUE)
			{
				
				//�ǂ̂Ƃ��́A�v���C���[�ƃ}�b�v���������Ă���
				if (mapdata5[tate][yoko] == t) { return TRUE; }
				
				if (mapdata5[tate][yoko] == s) { return TRUE; }
				if (mapdata5[tate][yoko] == g) { return TRUE; }
			}
		}
	}

	return FALSE;
}

//�̈�̓����蔻�������֐�
//BOOL MY_CHECK_RECT2_COLL(RECT a, RECT b)
//{
//	if (a.left < b.right &&
//		a.top < b.bottom &&
//		a.right > b.left &&
//		a.bottom > b.top
//		)
//	{
//		return TRUE;	//�������Ă���
//	}
//
//	return FALSE;		//�������Ă��Ȃ�
//}

