
#include "DxLib.h"


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

#define GAME_FPS			60	//FPS�̐��l	

//�摜�̃p�X�ݒ�
#define TITLE_BACK_PATH TEXT(".\\IMAGE\\�_�E�����[�h (2).png") //�^�C�g���̉摜
#define IMAGE_SETUMEI_PATH		TEXT(".\\IMAGE\\�������2.png") //������ʂ̉摜
#define GAME_MAP_PATH TEXT(".\\IMAGE\\ST-Town-I01.png")

//�G���[���b�Z�[�W
#define IMAGE_LOAD_ERR_TITLE	TEXT("�摜�ǂݍ��݃G���[")

//�p�X�̒���
#define PATH_MAX			255	//255�����܂�
#define NAME_MAX			255	//255�����܂�

//�L�[�{�[�h�̎��
#define KEY_CODE_KIND		256	//256���

//����{�^�����������Ƃ�
#define MSG_CLOSE_TITLE			TEXT("�I�����b�Z�[�W")
#define MSG_CLOSE_CAPTION		TEXT("�Q�[�����I�����܂����H")

enum GAME_SCENE {
	GAME_SCENE_START,
	GAME_SCENE_SETUMEI,
	GAME_SCENE_PLAY,
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
	e = 350, //�J�[�y�b�g��
	f = 351 //�J�[�y�b�g�^��
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
	d,d,d,d,n,n,n,n,n,n,n,n,d,d,d,n,n,n,n,n,n,n,n,n,n,
	n,n,n,n,n,n,n,n,n,n,n,n,n,n,d,n,n,n,n,d,d,n,n,n,n,
	d,d,d,d,n,n,n,n,n,n,n,n,n,n,d,n,n,d,n,n,n,d,n,n,n,
	n,n,n,n,n,n,d,d,d,d,n,n,n,n,n,n,n,n,n,n,n,d,n,n,n,
	d,d,d,d,n,n,n,n,n,d,d,n,n,n,n,n,n,n,n,n,d,d,n,n,n,
	n,n,n,n,n,n,n,n,n,n,n,n,n,n,d,n,d,d,n,n,d,n,n,n,n,
	d,d,d,d,n,n,n,n,n,n,n,n,n,d,d,n,n,d,n,d,d,n,n,n,n,
	n,n,n,n,n,n,n,n,d,d,n,d,d,d,n,n,n,d,d,d,n,n,n,n,n,
	d,d,d,d,n,n,n,n,n,d,d,d,n,n,n,n,n,n,n,n,n,n,n,n,n,
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
	
};

int mapDataInit[MAP_HEIGHT_MAX][MAP_WIDTH_MAX];
int mapDataInit_Nowalk[MAP_HEIGHT_MAX][MAP_WIDTH_MAX];
int mapDataInit_Object[MAP_HEIGHT_MAX][MAP_WIDTH_MAX];

//�}�b�v�`�b�v�̉摜���Ǘ�
MAPCHIP mapChip;
MAPCHIP mapChip_Nowalk;
MAPCHIP mapChip_Object;

//�}�b�v�̏ꏊ���Ǘ�
MAP map[MAP_HEIGHT_MAX][MAP_WIDTH_MAX];
MAP map2[MAP_HEIGHT_MAX][MAP_WIDTH_MAX];
MAP map3[MAP_HEIGHT_MAX][MAP_WIDTH_MAX];
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

VOID MY_END(VOID);			//�G���h���
VOID MY_END_PROC(VOID);		//�G���h��ʂ̏���
VOID MY_END_DRAW(VOID);		//�G���h��ʂ̕`��


//�C���[�W�\���̂̕���
IMAGE imageBACK; //�^�C�g���w�i
IMAGE ImageSetumei; //������ʂ̉摜

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
	//�X�y�[�X�L�[����������A�G���h�V�[���ֈړ�����
	if (MY_KEY_DOWN(KEY_INPUT_SPACE) == TRUE)
	{
		//�Q�[���̃V�[�����G���h��ʂɂ���
		GameScene = GAME_SCENE_END;

		return;
	}

	
	

	return;
}

//�v���C��ʂ̕`��
VOID MY_PLAY_DRAW(VOID)
{

	
	for (int tate = 0; tate < MAP_HEIGHT_MAX; tate++)
	{
		for (int yoko = 0; yoko < MAP_WIDTH_MAX; yoko++)
		{
			//�}�b�v��`��
			DrawGraph(
				map[tate][yoko].x,
				map[tate][yoko].y,
				mapChip.handle[map[tate][yoko].kind],
				TRUE);
		}
	}

	



	for (int tate = 0; tate < MAP_HEIGHT_MAX; tate++)
	{
		for (int yoko = 0; yoko < MAP_WIDTH_MAX; yoko++)
		{
			//�}�b�v��`��
			DrawGraph(
				map2[tate][yoko].x,
				map2[tate][yoko].y,
				mapChip_Nowalk.handle[map2[tate][yoko].kind],
				TRUE);
		}
	}

	for (int tate = 0; tate < MAP_HEIGHT_MAX; tate++)
	{
		for (int yoko = 0; yoko < MAP_WIDTH_MAX; yoko++)
		{
			//�}�b�v��`��
			DrawGraph(
				map3[tate][yoko].x,
				map3[tate][yoko].y,
				mapChip_Object.handle[map3[tate][yoko].kind],
				TRUE);
		}
	}


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

	return TRUE;
}

//�摜���܂Ƃ߂č폜����֐�
VOID DELETE_IMAGE(VOID)
{
	DeleteGraph(imageBACK.handle);
	DeleteGraph(ImageSetumei.handle);
	for (int i_num = 0; i_num < MAP_DIV_NUM; i_num++) { DeleteGraph(mapChip.handle[i_num]); }
	for (int i_num = 0; i_num < MAP_DIV_NUM; i_num++) { DeleteGraph(mapChip_Nowalk.handle[i_num]); }
	for (int i_num = 0; i_num < MAP_DIV_NUM; i_num++) { DeleteGraph(mapChip_Object.handle[i_num]); }
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