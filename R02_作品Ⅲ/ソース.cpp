#include "DxLib.h"
#include "stdlib.h"
#include "string.h"


#define _CRT_SECURE_NO_WARNINGS
#define MAP_NUM         3           // �}�b�v�̐�
#define GAME_WIDTH			800	//��ʂ̉��̑傫��
#define GAME_HEIGHT			640	//��ʂ̏c�̑傫��
#define GAME_COLOR			32	//��ʂ̃J���[�r�b�g
#define TEXT_WIDTH_POSITION	100
#define TEXT_HEIGHT_POSITION 500

#define MAP_SIZE        32          // �}�b�v�`�b�v��̃h�b�g�T�C�Y

#define MAP_WIDTH_MAX   25          // �}�b�v�̍ő啝
#define MAP_HEIGHT_MAX  20          // �}�b�v�̍ő�c����
#define MAP_DIV_WIDTH		32	//�摜�𕪊����镝�T�C�Y
#define MAP_DIV_HEIGHT		32	//�摜�𕪊����鍂���T�C�Y
#define MAP_DIV_TATE		8	//�摜���c�ɕ������鐔8
#define MAP_DIV_YOKO		50	//�摜�����ɕ������鐔50 
#define MAP_DIV_NUM	MAP_DIV_TATE * MAP_DIV_YOKO	//�摜�𕪊����鑍�� 400

#define MAP_TATE		41	//�摜���c�ɕ������鐔41
#define MAP_YOKO		32	//�摜�����ɕ������鐔32
#define MAP_NUM	MAP_TATE * MAP_YOKO	//�摜�𕪊����鑍�� 1312


#define PLAYER_DIV_WIDTH 32 //�v���C���[�̉���32�r�b�g 
#define PLAYER_DIV_HEIGHT 48 //�v���C���[����48�r�b�g
#define PLAYER_DIV_TATE 4 //�^�e������4
#define PLAYER_DIV_YOKO 4 //���R������4
#define PLAYER_DIV_NUM PLAYER_DIV_TATE * PLAYER_DIV_YOKO //16
#define PLAYER_IMG_CHANGE_MAX 16

#define GAME_FPS			60	//FPS�̐��l	

//�摜�̃p�X�ݒ�
#define TITLE_BACK_PATH TEXT(".\\IMAGE\\�Q�[���^�C�g��.png") //�^�C�g���̉摜
#define IMAGE_SETUMEI_PATH		TEXT(".\\IMAGE\\�������3.png") //������ʂ̉摜
#define GAME_MAP_PATH TEXT(".\\IMAGE\\ST-Town-I01.png") //�}�b�v�`�b�v
#define GAME_MAP_PATH2 TEXT(".\\IMAGE\\mapchip1.png") //�}�b�v�`�b�v2
#define GAME_PLAYER_PATH TEXT(".\\IMAGE\\joshi03.png") //�v���C���[�̉摜
#define TEXT_BOX (".\\IMAGE\\TextBox_start.png")  //���݂͖v�ł���
#define TEXT_BOX_1 (".\\IMAGE\\TextBox1.png") //�A�C�e��������̃e�L�X�g�{�b�N�X
#define TEXT_BOX_2 (".\\IMAGE\\TextBox������.png") //�A�C�e��������Ă��Ȃ��Ƃ�
#define TEXT_BOX_3 (".\\IMAGE\\TextBox���֌�����.png")//�����擾��
#define TEXT_BOX_4 (".\\IMAGE\\TextBox���֌�����.png")//���������Ă��Ȃ�

//BGM�̃p�X��ݒ�
#define TITLE_BGM_PATH TEXT(".\\MUSIC\\�~�̏�i�ɂ�.mp3") //�^�C�g��BGM
#define ROKA_BGM_PATH TEXT(".\\MUSIC\\����̊�.mp3") //�L���̂�����ƕ|��BGM
#define FLAG_BGM_PATH TEXT(".\\MUSIC\\se_maoudamashii_onepoint07.mp3")//�A�C�e���擾���̌��ʉ�

//�G���[���b�Z�[�W
#define IMAGE_LOAD_ERR_TITLE	TEXT("�摜�ǂݍ��݃G���[")
#define MUSIC_LOAD_ERR_TITLE	TEXT("���y�ǂݍ��݃G���[")

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
	GAME_SCENE_SCENARIO,
	GAME_SCENE_PLAY,
	GAME_SCENE_PLAY2,
	GAME_SCENE_PLAY3,
	GAME_SCENE_PLAY4,
	GAME_SCENE_END,
};	//�Q�[���̃V�[��

enum GAME_MAP_KIND
{
	/*n = -1,*/	//(NONE)����
	GL = 0, //�O�̒n��
	k = 10,	//��
	t = 17,	//���
	s = 25,	//����
	g = 33,	//����
	n = 196, // ����
	d = 150, // �_���{�[��
	m = 64, //����h�A
	l = 65, //�E��h�A
	a = 66, //������
	b = 67, // �E����
	j = 72, //�����h�A
	o = 73, //�E���h�A
	c = 74, //������
	h = 75, // �E����
	p = 90, //�\�t�@
	q = 91, //�\�t�@
	R = 92, //�\�t�@
	v = 98, //�\�t�@
	w = 99, //�\�t�@
	z = 100, //�\�t�@
	P = 106, //��
	N = 107, //��
	O = 108, //��
	A = 149, //�S�~��
	B = 156, //�u��
	NU = 190, //����
	START = 189, //�O�X�^�[�g
	GOAL = 221,//�S�[��
	Z = 319, //�A�C�e���t���O
	SB = 340,
	C = 344, //�K�i
	D = 345, //�K�i
	E = 346, //�K�i
	F = 352, //�K�i
	H = 353, //�K�i
	I = 354, //�K�i
	u = 349, //���J�[�y�b�g
	e = 350, //�J�[�y�b�g��
	f = 351, //�J�[�y�b�g�^��
	J = 360, //�K�i
	K = 361, //�K�i
	L = 362, //�K�i
	r = 2, //����
	S = 198, //start
	G = 197, //goal
	M = 195, //��O�̏ꏊ�ɖ߂锻��
	FL = 1188,
	FL2 = 1189,
	FL3 = 1190,
	FL4 = 1191,
	FE = 1192,
	FE2 = 1224,

};	//�}�b�v�̎��


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
	int handle[MAP_NUM];			//���������̒e�̉摜�n���h�����擾
	int kind[MAP_NUM];				//�}�b�v�̎��
	int width;							//��
	int height;							//����
}MAPCHIP;	//MAP_IMAGE�\����




typedef struct STRUCT_MUSIC
{
	char path[PATH_MAX];		//�p�X
	int handle;					//�n���h��
}MUSIC;	//���y�\����

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

	int kind1;			//�摜�̎�ނP
	int kind2;			//�摜�̎�ނQ
	char path[PATH_MAX];
	IMAGE image;
	int speed;
	int CenterX;
	int CenterY;
	int handle[PLAYER_DIV_NUM];
	int Part;

	int imgChangeCnt;	//�摜�X�V�J�E���^
	int imgChangeCntMAX;//�摜�X�V�J�E���^MAX�l
	BOOL IsMoveNaname;	//�΂߈ړ������Ă��邩
	 
	RECT coll; //�����蔻��
	iPOINT collBeforePt; //������O�̔���
}CHARA;

typedef struct STRUCT_PLAYERCHIP
{
	char path[PATH_MAX];				//�p�X
	int handle[PLAYER_DIV_NUM];			//���������摜�n���h�����擾
	int width;							//��
	int height;							//����
}PLAYERCHIP;

enum PLAYER_KIND_1 {
	D_1, D_2, D_3,D_4,
	L_1, L_2, L_3,L_4,
	R_1, R_2, R_3,R_4,
	U_1, U_2, U_3,U_4
};//(U��/D��/R�E/L��)





//�}�b�v�̕��ƍ������i�[����
int mapdata[MAP_HEIGHT_MAX][MAP_WIDTH_MAX];
int mapdata2[MAP_HEIGHT_MAX][MAP_WIDTH_MAX];
int mapdata3[MAP_HEIGHT_MAX][MAP_WIDTH_MAX];
int mapdata4[MAP_HEIGHT_MAX][MAP_WIDTH_MAX];
int mapdata5[MAP_HEIGHT_MAX][MAP_WIDTH_MAX];
int mapdata6[MAP_HEIGHT_MAX][MAP_WIDTH_MAX];
int mapdata7[MAP_HEIGHT_MAX][MAP_WIDTH_MAX];
int mapdata8[MAP_HEIGHT_MAX][MAP_WIDTH_MAX];
int mapdata9[MAP_HEIGHT_MAX][MAP_WIDTH_MAX];
int mapdata10[MAP_HEIGHT_MAX][MAP_WIDTH_MAX];
int mapdata11[MAP_HEIGHT_MAX][MAP_WIDTH_MAX];
int mapdata12[MAP_HEIGHT_MAX][MAP_WIDTH_MAX];
int mapdata13[MAP_HEIGHT_MAX][MAP_WIDTH_MAX];


int MapDataMode[MAP_HEIGHT_MAX][MAP_WIDTH_MAX];

//�}�b�v�`�b�v�̉摜���Ǘ�
MAPCHIP mapChip;
MAPCHIP mapChip2;
MAPCHIP mapChip_Nowalk;
MAPCHIP mapChip_Object;
MAPCHIP mapChip_Roka;
MAPCHIP mapChip_RokaNowalk;
CHARA player;
PLAYERCHIP playerChip1;



RECT mapColl[MAP_HEIGHT_MAX][MAP_WIDTH_MAX]; //�}�b�v�̓����蔻��

//�C���[�W�\���̂̕���
IMAGE imageBACK; //�^�C�g���w�i
IMAGE ImageSetumei; //������ʂ̉摜
IMAGE TextBox_start;
IMAGE TextBox_flag; //�A�C�e��������̃e�L�X�g�{�b�N�X
IMAGE TextBox_Null; //�A�C�e��������Ă��Ȃ��Ƃ�
IMAGE TextBox_GenkanKagi;
IMAGE TextBox_GenkanKagiNasi;

iPOINT startPt{ -1, -1 }; //�ŏ��̃X�^�[�g�|�C���g
iPOINT startPt2{ -1 , -1 };//�L���̃X�^�[�g�|�C���g
iPOINT startPt3{ -1 , -1 }; //���ւ����镔���̃X�^�[�g�|�C���g
iPOINT startPt4{ -1,-1 }; //�O�̃X�^�[�g�|�C���g
RECT GoalRect = { -1,-1, -1, -1 };	//�ŏ��̏o���|�C���g
RECT GoalRect2 = { -1, -1 , -1, -1 };//�L���̏o���|�C���g
RECT GoalRect3 = { -1, -1, -1, -1 };//���ւ�����o���|�C���g
RECT GoalRect4 = { -1,-1,-1,-1 };//�O�̏o���|�C���g

RECT Modoru = { -1, -1, -1,-1 }; //��O�̕����ɖ߂锻��
RECT Modoru2 = { -1,-1,-1,-1 };//�L���ɖ߂锻��
RECT Itemflag = { -1,-1,-1,-1 }; //�A�C�e���t���O�̓����蔻��
RECT Itemflag2 = { -1,-1,-1,-1 };//�ŏ��̕����̃t���O����
iPOINT ModoruPt{ -1,-1 };
iPOINT Modoru2Pt{ -1,-1, };

//BGM
MUSIC BGM; //�^�C�g��BGM
MUSIC ROKA;//�L����BGM
MUSIC FLAG; //�A�C�e���擾���̌��ʉ������݂͖v

int GameScene;		//�Q�[���V�[�����Ǘ�

//�L�[�{�[�h�̓��͂��擾
char AllKeyState[KEY_CODE_KIND] = { '\0' };		//���ׂẴL�[�̏�Ԃ�����
char OldAllKeyState[KEY_CODE_KIND] = { '\0' };	//���ׂẴL�[�̏��(���O)������

//FPS�֘A
int StartTimeFps;				//����J�n����
int CountFps;					//�J�E���^
float CalcFps;					//�v�Z����
int SampleNumFps = GAME_FPS;	//���ς����T���v����
char key[256];					//�L�[���󂯎��
int playerhandle[16];			//�L�����N�^�[�̃`�b�v������

int count;	//�t���[�����擾���ăJ�E���g����

int x;
int y;
int result = 0;			//�t�@�C���̍Ōォ�`�F�b�N
int tateCnt = 0;		//�c�J�E���g�p
int yokoCnt = 0;		//���J�E���g�p

FILE* fp = NULL; //�t�@�C���|�C���^

int flag = 0;  //�A�C�e���t���O
int flag2 = 0; //�A�C�e���t���O




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

VOID MY_SCENARIO(VOID); //�V�i���I����

VOID MY_PLAY_INIT(VOID);	//�v���C��ʏ�����
VOID MY_PLAY(VOID);			//�v���C���
VOID MY_PLAY_PROC(VOID);	//�v���C��ʂ̏���
VOID MY_PLAY_DRAW(VOID);	//�v���C��ʂ̕`��
VOID MY_PLAY2(VOID);		//�L�����
VOID MY_PLAY_PROC2(VOID);   //�L���̏���
VOID MY_PLAY_DRAW2(VOID);	//�L���̃X�e�[�W�`��
VOID MY_PLAY3(VOID);		//�Ō�̕���
VOID MY_PLAY_PROC3(VOID);	//�Ō�̕����̏���
VOID MY_PLAY_DRAW3(VOID);	//�Ō�̕����̕`��
VOID MY_PLAY4(VOID);		//�O
VOID MY_PLAY_PROC4(VOID);	//�O�̏���
VOID MY_PLAY_DRAW4(VOID);	//�O�̕`��

VOID MY_END(VOID);			//�G���h���
VOID MY_END_PROC(VOID);		//�G���h��ʂ̏���
VOID MY_END_DRAW(VOID);		//�G���h��ʂ̕`��

BOOL MY_CHECK_MAP1_PLAYER_COLL(RECT);	//�}�b�v�ƃv���C���[�̓����蔻�������֐�
BOOL MY_CHECK_RECT_COLL(RECT, RECT);	//�̈�̓����蔻�������֐�
BOOL MY_CHECK_MAP2_PLAYER_COLL(RECT);   //�L���̓����蔻���ݒ肷��֐�
BOOL MY_CHECK_MAP3_PLAYER_COLL(RECT);   //���ւ̕����̓����蔻���ݒ肷��֐�
BOOL MY_CHECK_MAP4_PLAYER_COLL(RECT);  //�O�̓����蔻���ݒ肷��֐�


BOOL MY_LOAD_PLAYER(const char* path, PLAYERCHIP* player); //�v���C���[�̃`�b�v�𕪊����X����



int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetOutApplicationLogValidFlag(FALSE);				//Log.txt���o�͂��Ȃ�
	ChangeWindowMode(TRUE);								//�E�B���h�E���[�h�ɐݒ�
	SetGraphMode(GAME_WIDTH, GAME_HEIGHT, GAME_COLOR);	//�w��̐��l�ŃE�B���h�E��\������
	SetWindowStyleMode(0);				//�^�C�g���o�[�̓f�t�H���g�ɂ���
	SetAlwaysRunFlag(TRUE);								//��A�N�e�B�u�ł����s����
	
	SetWindowUserCloseEnableFlag(FALSE);				//����{�^���ŁA����ɃE�B���h�E�����Ȃ��悤�ɂ���




	if (DxLib_Init() == -1) { return -1; }	//�c�w���C�u��������������

	if (LOAD_IMAGE() == FALSE) { return -1; } //�C���[�W�̐錾������֐����Ă�
	if (MY_LOAD_PLAYER(GAME_PLAYER_PATH, &playerChip1) == FALSE) { return -1; } //�v���C���[�̕���������֐����Ă�
	
	

	//���y��ǂݍ���
	if (LOAD_MUSIC() == FALSE) { return -1; }

	GameScene = GAME_SCENE_START;	//�Q�[���V�[���̓X�^�[�g��ʂ���
	SetDrawScreen(DX_SCREEN_BACK);	//Draw�n�֐��͗���ʂɕ`��



	//###################################��������e�L�X�g�t�@�C���Ǎ�##########################################

	fp = fopen(".\\TXT\\sakuhin_remake.txt", "r");


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
	fclose(fp);	//�t�@�C�������

	result = 0;
	tateCnt = 0;
	yokoCnt = 0;

	fp = fopen(".\\TXT\\sakuhin_remake_nowalk.txt", "r");

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

			case'Z':
				mapdata2[tateCnt][yokoCnt] = Z;
				yokoCnt++;
				Itemflag2.left = mapChip.width * yokoCnt;
				Itemflag2.top = mapChip.height * tateCnt;
				Itemflag2.right = mapChip.width * (yokoCnt + 1);
				Itemflag2.bottom = mapChip.height * (tateCnt + 1);

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
	result = 0;
	tateCnt = 0;
	yokoCnt = 0;

	fp = fopen(".\\TXT\\sakuhin_remake_object.txt", "r");

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
			case'B':
				mapdata3[tateCnt][yokoCnt] = B;
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



	//-----------------------�L��txt-----------------------
	result = 0;
	tateCnt = 0;
	yokoCnt = 0;

	fp = fopen(".\\TXT\\sakuhin_roka.txt", "r");

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


	fclose(fp);	//�t�@�C�������

	result = 0;
	tateCnt = 0;
	yokoCnt = 0;

	fp = fopen(".\\TXT\\sakuhin_roka_nowalk.txt", "r");

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
				startPt2.x = mapChip.width * yokoCnt - 30 ;	//���SX���W���擾
				startPt2.y = mapChip.height * tateCnt -20 ;	//���SY���W���擾
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

			case 'M':
				mapdata5[tateCnt][yokoCnt] = M;
				yokoCnt++;

				Modoru2Pt.x = mapChip.width * yokoCnt + mapChip.width - 125;	//���SX���W���擾
				Modoru2Pt.y = mapChip.height * tateCnt + mapChip.height - 40;	//���SY���W���擾


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

	result = 0;
	tateCnt = 0;
	yokoCnt = 0;

	fp = fopen(".\\TXT\\sakuhin_roka_maenimodoru.txt", "r");

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

	//########################����2#######################

	result = 0;
	tateCnt = 0;
	yokoCnt = 0;

	fp = fopen(".\\TXT\\sakuhin_heya2.txt", "r");

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
				mapdata7[tateCnt][yokoCnt] = n;
				yokoCnt++;
				break;
			case 'k':
				//�ǂ̂Ƃ�
				mapdata7[tateCnt][yokoCnt] = k;
				yokoCnt++;
				break;

			case 'G':
				mapdata7[tateCnt][yokoCnt] = G;
				yokoCnt++;

				GoalRect3.left = mapChip.width * yokoCnt;
				GoalRect3.top = mapChip.height * tateCnt;
				GoalRect3.right = mapChip.width * (yokoCnt + 1);
				GoalRect3.bottom = mapChip.height * (tateCnt + 1);
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

	fp = fopen(".\\TXT\\sakuhin_heya2_nowalk.txt", "r");

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
				mapdata8[tateCnt][yokoCnt] = n;
				yokoCnt++;
				break;
			case 's':
				//�ǂ̂Ƃ�
				mapdata8[tateCnt][yokoCnt] = s;
				yokoCnt++;
				break;

			case 't':
				
				mapdata8[tateCnt][yokoCnt] = t;
				yokoCnt++;
				break;

			case 'g':

				mapdata8[tateCnt][yokoCnt] = g;
				yokoCnt++;
				break;
			case 'P':

				mapdata8[tateCnt][yokoCnt] = P;
				yokoCnt++;
				break;

			case 'N':

				mapdata8[tateCnt][yokoCnt] = N;
				yokoCnt++;
				break;

			case 'O':

				mapdata8[tateCnt][yokoCnt] = O;
				yokoCnt++;
				break;

			case 'S':

				mapdata8[tateCnt][yokoCnt] = S;
				yokoCnt++;

				//�X�^�[�g�ʒu���Z�b�g
				startPt3.x = mapChip.width * yokoCnt - 30;	//���SX���W���擾
				startPt3.y = mapChip.height * tateCnt - 20;	//���SY���W���擾
				break;

			case 'Z':
				mapdata8[tateCnt][yokoCnt] = Z;
				yokoCnt++;
				Itemflag.left = mapChip.width * yokoCnt;
				Itemflag.top = mapChip.height * tateCnt;
				Itemflag.right = mapChip.width * (yokoCnt + 1);
				Itemflag.bottom = mapChip.height * (tateCnt + 1);

				break;
			case 'M':
				//�ǂ̂Ƃ�
				mapdata8[tateCnt][yokoCnt] = M;
				yokoCnt++;
				Modoru2.left = mapChip.width * yokoCnt ;
				Modoru2.top = mapChip.height * tateCnt ;
				Modoru2.right = mapChip.width; //* (yokoCnt + 1);
				Modoru2.bottom = mapChip.height * (tateCnt + 1);

				

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

	result = 0;
	tateCnt = 0;
	yokoCnt = 0;

	fp = fopen(".\\TXT\\sakuhin_heya2_Object.txt", "r");

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
				mapdata9[tateCnt][yokoCnt] = n;
				yokoCnt++;
				break;
			case 'm':
				//�ǂ̂Ƃ�
				mapdata9[tateCnt][yokoCnt] = m;
				yokoCnt++;
				break;

			case 'l':

				mapdata9[tateCnt][yokoCnt] = l;
				yokoCnt++;
				break;

			case 'j':

				mapdata9[tateCnt][yokoCnt] = j;
				yokoCnt++;
				break;
			case 'o':

				mapdata9[tateCnt][yokoCnt] = o;
				yokoCnt++;
				break;

			case 'd':

				mapdata9[tateCnt][yokoCnt] = d;
				yokoCnt++;
				break;

			case 'p':

				mapdata9[tateCnt][yokoCnt] = p;
				yokoCnt++;
				break;

			case 'q':

				mapdata9[tateCnt][yokoCnt] = q;
				yokoCnt++;
				break;

			case 'R':

				mapdata9[tateCnt][yokoCnt] = R;
				yokoCnt++;
				break;

			case 'v':

				mapdata9[tateCnt][yokoCnt] = v;
				yokoCnt++;
				break;

			case 'w':

				mapdata9[tateCnt][yokoCnt] = w;
				yokoCnt++;
				break;

			case 'z':

				mapdata9[tateCnt][yokoCnt] = z;
				yokoCnt++;
				break;

			case 'f':

				mapdata9[tateCnt][yokoCnt] = f;
				yokoCnt++;
				break;

			case 'A':

				mapdata9[tateCnt][yokoCnt] = A;
				yokoCnt++;
				break;

			case 'B':

				mapdata9[tateCnt][yokoCnt] = B;
				yokoCnt++;
				break;

			case 'C':

				mapdata9[tateCnt][yokoCnt] = C;
				yokoCnt++;
				break;
			case 'D':

				mapdata9[tateCnt][yokoCnt] = D;
				yokoCnt++;
				break;
			case 'E':

				mapdata9[tateCnt][yokoCnt] = E;
				yokoCnt++;
				break;

			case 'F':

				mapdata9[tateCnt][yokoCnt] = F;
				yokoCnt++;
				break;

			case 'H':
				mapdata9[tateCnt][yokoCnt] = H;
				yokoCnt++;
				break;

			case 'I':

				mapdata9[tateCnt][yokoCnt] = I;
				yokoCnt++;
				break;

			case 'J':

				mapdata9[tateCnt][yokoCnt] = J;
				yokoCnt++;
				break;

			case 'K':

				mapdata9[tateCnt][yokoCnt] = K;
				yokoCnt++;
				break;

			case 'L':

				mapdata9[tateCnt][yokoCnt] = L;
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

	fp = fopen(".\\TXT\\a.txt", "r");

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
				//�ǂ̂Ƃ�
				mapdata10[tateCnt][yokoCnt] = n;
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

	result = 0;
	tateCnt = 0;
	yokoCnt = 0;

		//################################�O######################################

	fp = fopen(".\\TXT\\soto.txt", "r");

	while (result != EOF)	//End Of File�i�t�@�C���̍Ō�j�ł͂Ȃ��Ƃ��J��Ԃ�
	{
		char mapData[MAP_WIDTH_MAX * 3 + 1];
		//�t�@�C�����琔�l����ǂݍ���(%d,)�A�z��Ɋi�[����
		result = fscanf(fp, "%s,", mapData);
		for (int i = 0; i < strlen(mapData); i++)
		{
			switch (mapData[i])
			{

			case 'G':
				//�ǂ̂Ƃ�
				mapdata11[tateCnt][yokoCnt] = GL;
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

	fp = fopen(".\\TXT\\soto_nowalk.txt", "r");

	while (result != EOF)	//End Of File�i�t�@�C���̍Ō�j�ł͂Ȃ��Ƃ��J��Ԃ�
	{
		char mapData[MAP_WIDTH_MAX * 3 + 1];
		//�t�@�C�����琔�l����ǂݍ���(%d,)�A�z��Ɋi�[����
		result = fscanf(fp, "%s,", mapData);
		for (int i = 0; i < strlen(mapData); i++)
		{
			switch (mapData[i])
			{

			case 'N':
				//�ǂ̂Ƃ�
				mapdata12[tateCnt][yokoCnt] = NU;
				yokoCnt++;
				break;
			case 'S':
				//�ǂ̂Ƃ�
				mapdata12[tateCnt][yokoCnt] = START;
				yokoCnt++;
			
				//�X�^�[�g�ʒu���Z�b�g
				startPt4.x = mapChip2.width * yokoCnt - 30;	//���SX���W���擾
				startPt4.y = mapChip2.height * tateCnt - 20;	//���SY���W���擾

				break;

			case'G':
				//�S�[���̎�
				mapdata12[tateCnt][yokoCnt] = GOAL;
				yokoCnt++;
				//�S�[���̔����ݒ�
				GoalRect4.left = mapChip2.width * yokoCnt;
				GoalRect4.top = mapChip2.height * tateCnt;
				GoalRect4.right = mapChip2.width * (yokoCnt + 1);
				GoalRect4.bottom = mapChip2.height * (tateCnt + 1);

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

	fp = fopen(".\\TXT\\soto_object.txt", "r");

	while (result != EOF)	//End Of File�i�t�@�C���̍Ō�j�ł͂Ȃ��Ƃ��J��Ԃ�
	{
		char mapData[MAP_WIDTH_MAX * 3 + 1];
		//�t�@�C�����琔�l����ǂݍ���(%d,)�A�z��Ɋi�[����
		result = fscanf(fp, "%s,", mapData);
		for (int i = 0; i < strlen(mapData); i++)
		{
			switch (mapData[i])
			{

			case 'N':
				//�ǂ̂Ƃ�
				mapdata13[tateCnt][yokoCnt] = NU;
				yokoCnt++;
				break;

			case 'F':
				//�ǂ̂Ƃ�
				mapdata13[tateCnt][yokoCnt] = FE2;
				yokoCnt++;
				break;
			case 'E':
				//�ǂ̂Ƃ�
				mapdata13[tateCnt][yokoCnt] = FE;
				yokoCnt++;
				break;
			case 'R':
				//�ǂ̂Ƃ�
				mapdata13[tateCnt][yokoCnt] = FL;
				yokoCnt++;
				break;
			case 'L':
				//�ǂ̂Ƃ�
				mapdata13[tateCnt][yokoCnt] = FL2;
				yokoCnt++;
				break;
			case 'O':
				//�ǂ̂Ƃ�
				mapdata13[tateCnt][yokoCnt] = FL3;
				yokoCnt++;
				break;
			case 'W':
				//�ǂ̂Ƃ�
				mapdata13[tateCnt][yokoCnt] = FL4;
				yokoCnt++;
				break;
			case 'S':
				//�ǂ̂Ƃ�
				mapdata13[tateCnt][yokoCnt] = SB;
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


	//#########################�����܂ł�txt�t�@�C���̓ǂݍ���################################
				
		
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

		

		ChangeFontType(DX_FONTTYPE_ANTIALIASING_8X8); //�A���`�G�C���A�X

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

		case GAME_SCENE_SCENARIO:
			MY_SCENARIO(); //�V�i���I���
			break;

		case GAME_SCENE_PLAY:
			MY_PLAY();	//�v���C���
			break;
		case GAME_SCENE_PLAY2:
			MY_PLAY2(); //�L�����
			break;

		case GAME_SCENE_PLAY3:
			MY_PLAY3(); //���ւ̕���
			break;
		case GAME_SCENE_PLAY4:
			MY_PLAY4(); //�O
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
	if (CheckSoundMem(BGM.handle) == 0)
	{
		//BGM�̉��ʂ�������
		ChangeVolumeSoundMem(255 * 50 / 100, BGM.handle);	//50%�̉��ʂɂ���

		PlaySoundMem(BGM.handle, DX_PLAYTYPE_LOOP);
	}
	
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
	DrawGraph(imageBACK.x, imageBACK.y, imageBACK.handle, TRUE); //�^�C�g���̃o�b�N�C���[�W

	return;
}

VOID MY_SETUMEI(VOID)
{
	MY_START_SETUMEI_DRAW();//������ʂ̕`��
}
//������ʂ̕`��
VOID MY_START_SETUMEI_DRAW(VOID)
{
	DrawGraph(ImageSetumei.x, ImageSetumei.y, ImageSetumei.handle, TRUE); //�����摜
	DrawString(0, 0, "�X�^�[�g���(�[��(0)�L�[�������ĉ�����)", GetColor(255, 255, 255));

	if (MY_KEY_DOWN(KEY_INPUT_0) == TRUE) //�V�i���I�V�[���֑J��
	{
		
		
		GameScene = GAME_SCENE_SCENARIO;
	}
	
	


	return;
}

VOID MY_SCENARIO(VOID)
{

	DrawString(300, 200, "������̂��ƁA�ڂ��o�߂���l���͌��m��ʏꏊ�ɂ����B", GetColor(255, 255, 255));
	DrawString(300, 220, "�q�ɂƂ��Ďg���Ă���̂��킩��Ȃ���", GetColor(255, 255, 255));
	DrawString(300, 240, "����ɂ͑����̃_���{�[�����ςݏd�Ȃ��Ă����B", GetColor(255, 255, 255));
	DrawString(300, 260, "��l���͂��̓�̉Ƃ���o�邽�߂ɁA�T�������邱�Ƃɂ����B", GetColor(255, 255, 255));

	DrawString(0, 0, "�G���^�[�L�[�������Ă�������", GetColor(255, 255, 255));

	if (MY_KEY_DOWN(KEY_INPUT_RETURN) == TRUE) //�v���C��ʂ֑J��
	{
		if (CheckSoundMem(BGM.handle) != 0)
		{
			StopSoundMem(BGM.handle);	//BGM���~�߂�
		}
		GameScene = GAME_SCENE_PLAY;

		SetMouseDispFlag(FALSE);

		//�v���C���[�̈ʒu��ݒ�
		player.CenterX = startPt.x;
		player.CenterY = startPt.y;


		player.image.x = player.CenterX;
		player.image.y = player.CenterY;


	}
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

	player.kind1 = D_1; //���������Ă��Ȃ��Ƃ��̃v���C���[�̌���
	int old_x = player.image.x; //�����蔻�莞�A�O�ɋ����ʒu�֖߂�
	int old_y = player.image.y;
	BOOL IsMove = TRUE; //�ړ��\


	//��Ɉړ�����Ƃ�
	if (MY_KEY_DOWN(KEY_INPUT_W) == TRUE
		&& MY_KEY_DOWN(KEY_INPUT_D) == FALSE
		&& MY_KEY_DOWN(KEY_INPUT_S) == FALSE
		&& MY_KEY_DOWN(KEY_INPUT_A) == FALSE)
	{
		player.IsMoveNaname = FALSE;	//�΂߈ړ����Ă��Ȃ�

		if (player.kind1 >= U_1 && player.kind1 < U_4)
		{
			//�摜�ύX�J�E���^
			if (player.imgChangeCnt < player.imgChangeCntMAX)
			{
				player.imgChangeCnt++;
			}
			else //�摜��ς���^�C�~���O�ɂȂ�����
			{
				player.kind1++;			//���̉摜�ɂ���
				player.imgChangeCnt = 0;	//�ύX�J�E���^������
			}
		}
		else
		{
			player.kind1 = U_1;	//�ŏ��̉摜�ɂ���
		}

		player.image.y -= 1.5;	//�ړ�
	}

	//�E�Ɉړ�����Ƃ�
	if (MY_KEY_DOWN(KEY_INPUT_W) == FALSE
		&& MY_KEY_DOWN(KEY_INPUT_D) == TRUE
		&& MY_KEY_DOWN(KEY_INPUT_S) == FALSE
		&& MY_KEY_DOWN(KEY_INPUT_A) == FALSE)
	{
		player.IsMoveNaname = FALSE;	//�΂߈ړ����Ă��Ȃ�

		if (player.kind1 >= R_1 && player.kind1 < R_4)
		{
			//�摜�ύX�J�E���^
			if (player.imgChangeCnt < player.imgChangeCntMAX)
			{
				player.imgChangeCnt++;
			}
			else //�摜��ς���^�C�~���O�ɂȂ�����
			{
				player.kind1++;			//���̉摜�ɂ���
				player.imgChangeCnt = 0;	//�ύX�J�E���^������
			}
		}
		else
		{
			player.kind1 = R_1;	//�ŏ��̉摜�ɂ���
		}
		player.image.x += 2;	//�ړ�
	}

	//���Ɉړ�����Ƃ�
	if (MY_KEY_DOWN(KEY_INPUT_W) == FALSE
		&& MY_KEY_DOWN(KEY_INPUT_D) == FALSE
		&& MY_KEY_DOWN(KEY_INPUT_S) == FALSE
		&& MY_KEY_DOWN(KEY_INPUT_A) == TRUE)
	{
		player.IsMoveNaname = FALSE;	//�΂߈ړ����Ă��Ȃ�

		if (player.kind1 >= L_1 && player.kind1 < L_4)
		{
			//�摜�ύX�J�E���^
			if (player.imgChangeCnt < player.imgChangeCntMAX)
			{
				player.imgChangeCnt++;
			}
			else //�摜��ς���^�C�~���O�ɂȂ�����
			{
				player.kind1++;			//���̉摜�ɂ���
				player.imgChangeCnt = 0;	//�ύX�J�E���^������
			}
		}
		else
		{
			player.kind1 = L_1;	//�ŏ��̉摜�ɂ���
		}
		player.image.x -= 1.5;	//�ړ�
	}

	//���Ɉړ�����Ƃ�
	if (MY_KEY_DOWN(KEY_INPUT_W) == FALSE
		&& MY_KEY_DOWN(KEY_INPUT_D) == FALSE
		&& MY_KEY_DOWN(KEY_INPUT_S) == TRUE
		&& MY_KEY_DOWN(KEY_INPUT_A) == FALSE)
	{
		player.IsMoveNaname = FALSE;	//�΂߈ړ����Ă��Ȃ�

		if (player.kind1 >= D_1 && player.kind1 < D_4)
		{
			//�摜�ύX�J�E���^
			if (player.imgChangeCnt < player.imgChangeCntMAX)
			{
				player.imgChangeCnt++;
			}
			else //�摜��ς���^�C�~���O�ɂȂ�����
			{
				player.kind1++;			//���̉摜�ɂ���
				player.imgChangeCnt = 0;	//�ύX�J�E���^������
			}
		}
		else
		{
			player.kind1 = D_1;	//�ŏ��̉摜�ɂ���
		}
		player.image.y += 2;	//�ړ�
	}

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

			
			
			//�L���̃X�^�[�g�|�C���g�ɐݒ肵�J��
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

		
	
	

	return;
}

//�v���C��ʂ̕`��
VOID MY_PLAY_DRAW(VOID)
{

	//�}�b�v�̕`��
	

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


	//�����蔻��̕`��i�f�o�b�O�p�j
	for (int tate = 0; tate < MAP_HEIGHT_MAX; tate++)
	{
		for (int yoko = 0; yoko < MAP_WIDTH_MAX; yoko++)
		{
			//�_���{�[���Ȃ��
			/*if (mapdata3[tate][yoko] == d)
			{
				DrawBox(mapColl[tate][yoko].left, mapColl[tate][yoko].top, mapColl[tate][yoko].right, mapColl[tate][yoko].bottom, GetColor(255, 0, 0), FALSE);
			}
			//�o���Ȃ��
			if (mapdata2[tate][yoko] == Z)
			{
				DrawBox(mapColl[tate][yoko].left, mapColl[tate][yoko].top, mapColl[tate][yoko].right, mapColl[tate][yoko].bottom, GetColor(255, 0, 0), FALSE);
			}*/

		}
	}

	//�S�[�������蔻��p
	DrawBox(GoalRect.left, GoalRect.top, GoalRect.right, GoalRect.bottom, GetColor(255, 255, 0), TRUE);
	//�v���C���[�̓����蔻��p
	DrawBox(player.coll.left, player.coll.top, player.coll.right, player.coll.bottom, GetColor(255, 0, 0), FALSE);

	//���݂͖v�̗\��
	//DrawGraph(TEXT_WIDTH_POSITION, TEXT_HEIGHT_POSITION, TextBox_start.handle, TRUE);
	//if (MY_KEY_DOWN(KEY_INPUT_RETURN) == TRUE)
	//{
	//	DeleteGraph(TextBox_start.handle);
	//}
	
	//�v���C���[�̕`��
		DrawGraph(player.image.x, player.image.y, playerChip1.handle[player.kind1], TRUE);

		RECT PlayerRect;
		PlayerRect.left = player.CenterX - 40 / 20 + 5;
		PlayerRect.top = player.CenterY + 200 / 20 + 5;
		PlayerRect.right = player.CenterX + 650 / 20 - 5;
		PlayerRect.bottom = player.CenterY + 1000 / 20 - 5;

		
		//�t���O��������Ă��邩�ǂ����̃C�x���g
		if (MY_CHECK_RECT_COLL(PlayerRect, Itemflag2) == TRUE && flag == 1)
		{
			flag2 = 1;

			//if (CheckSoundMem(FLAG.handle) == 0)
			//{
			//	//BGM�̉��ʂ�������
			//	ChangeVolumeSoundMem(255 * 50 / 100, FLAG.handle);	//50%�̉��ʂɂ���

			//	PlaySoundMem(FLAG.handle, DX_PLAYTYPE_NORMAL);
			//}

			DrawGraph(TEXT_WIDTH_POSITION, TEXT_HEIGHT_POSITION, TextBox_GenkanKagi.handle, TRUE);

			if (MY_KEY_DOWN(KEY_INPUT_RETURN) == TRUE)
			{
				DeleteGraph(TextBox_GenkanKagi.handle);
			}
		}

		
		//�����擾���Ă��Ȃ��Ƃ�
		if (MY_CHECK_RECT_COLL(PlayerRect, Itemflag2) == TRUE && flag == 0 )
		{
			

				DrawGraph(TEXT_WIDTH_POSITION, TEXT_HEIGHT_POSITION, TextBox_GenkanKagiNasi.handle, TRUE);

			

			if (MY_KEY_DOWN(KEY_INPUT_RETURN) == TRUE)
			{
				DeleteGraph(TextBox_GenkanKagiNasi.handle);
			}
		}

	



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

	//�L����BGM
	if (CheckSoundMem(ROKA.handle) == 0)
	{
		//BGM�̉��ʂ�������
		ChangeVolumeSoundMem(255 * 50 / 100, ROKA.handle);	//50%�̉��ʂɂ���

		PlaySoundMem(ROKA.handle, DX_PLAYTYPE_LOOP);
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



	player.kind1 = D_1; //���������Ă��Ȃ��Ƃ��̃v���C���[�̌���
	int old_x = player.image.x; //�����蔻�莞
	int old_y = player.image.y;
	BOOL IsMove = TRUE; //�����܂�


	//��Ɉړ�����Ƃ�
	if (MY_KEY_DOWN(KEY_INPUT_W) == TRUE
		&& MY_KEY_DOWN(KEY_INPUT_D) == FALSE
		&& MY_KEY_DOWN(KEY_INPUT_S) == FALSE
		&& MY_KEY_DOWN(KEY_INPUT_A) == FALSE)
	{
		player.IsMoveNaname = FALSE;	//�΂߈ړ����Ă��Ȃ�

		if (player.kind1 >= U_1 && player.kind1 < U_4)
		{
			//�摜�ύX�J�E���^
			if (player.imgChangeCnt < player.imgChangeCntMAX)
			{
				player.imgChangeCnt++;
			}
			else //�摜��ς���^�C�~���O�ɂȂ�����
			{
				player.kind1++;			//���̉摜�ɂ���
				player.imgChangeCnt = 0;	//�ύX�J�E���^������
			}
		}
		else
		{
			player.kind1 = U_1;	//�ŏ��̉摜�ɂ���
		}

		player.image.y -= 1.5;	//�ړ�
	}

	//�E�Ɉړ�����Ƃ�
	if (MY_KEY_DOWN(KEY_INPUT_W) == FALSE
		&& MY_KEY_DOWN(KEY_INPUT_D) == TRUE
		&& MY_KEY_DOWN(KEY_INPUT_S) == FALSE
		&& MY_KEY_DOWN(KEY_INPUT_A) == FALSE)
	{
		player.IsMoveNaname = FALSE;	//�΂߈ړ����Ă��Ȃ�

		if (player.kind1 >= R_1 && player.kind1 < R_4)
		{
			//�摜�ύX�J�E���^
			if (player.imgChangeCnt < player.imgChangeCntMAX)
			{
				player.imgChangeCnt++;
			}
			else //�摜��ς���^�C�~���O�ɂȂ�����
			{
				player.kind1++;			//���̉摜�ɂ���
				player.imgChangeCnt = 0;	//�ύX�J�E���^������
			}
		}
		else
		{
			player.kind1 = R_1;	//�ŏ��̉摜�ɂ���
		}
		player.image.x += 2;	//�ړ�
	}

	//���Ɉړ�����Ƃ�
	if (MY_KEY_DOWN(KEY_INPUT_W) == FALSE
		&& MY_KEY_DOWN(KEY_INPUT_D) == FALSE
		&& MY_KEY_DOWN(KEY_INPUT_S) == FALSE
		&& MY_KEY_DOWN(KEY_INPUT_A) == TRUE)
	{
		player.IsMoveNaname = FALSE;	//�΂߈ړ����Ă��Ȃ�

		if (player.kind1 >= L_1 && player.kind1 < L_4)
		{
			//�摜�ύX�J�E���^
			if (player.imgChangeCnt < player.imgChangeCntMAX)
			{
				player.imgChangeCnt++;
			}
			else //�摜��ς���^�C�~���O�ɂȂ�����
			{
				player.kind1++;			//���̉摜�ɂ���
				player.imgChangeCnt = 0;	//�ύX�J�E���^������
			}
		}
		else
		{
			player.kind1 = L_1;	//�ŏ��̉摜�ɂ���
		}
		player.image.x -= 1.5;	//�ړ�
	}

	//���Ɉړ�����Ƃ�
	if (MY_KEY_DOWN(KEY_INPUT_W) == FALSE
		&& MY_KEY_DOWN(KEY_INPUT_D) == FALSE
		&& MY_KEY_DOWN(KEY_INPUT_S) == TRUE
		&& MY_KEY_DOWN(KEY_INPUT_A) == FALSE)
	{
		player.IsMoveNaname = FALSE;	//�΂߈ړ����Ă��Ȃ�

		if (player.kind1 >= D_1 && player.kind1 < D_4)
		{
			//�摜�ύX�J�E���^
			if (player.imgChangeCnt < player.imgChangeCntMAX)
			{
				player.imgChangeCnt++;
			}
			else //�摜��ς���^�C�~���O�ɂȂ�����
			{
				player.kind1++;			//���̉摜�ɂ���
				player.imgChangeCnt = 0;	//�ύX�J�E���^������
			}
		}
		else
		{
			player.kind1 = D_1;	//�ŏ��̉摜�ɂ���
		}
		player.image.y += 2;	//�ړ�
	}


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
		//���ւ̕����֑J��

			player.CenterX = startPt3.x;
			player.CenterY = startPt3.y;


			player.image.x = player.CenterX;
			player.image.y = player.CenterY;

			if (CheckSoundMem(ROKA.handle) != 0)
			{
				StopSoundMem(ROKA.handle);	//BGM���~�߂�
			}

			GameScene = GAME_SCENE_PLAY3;
		

		return;	//�����I�ɃG���h��ʂɔ��
	}

	if (MY_CHECK_RECT_COLL(PlayerRect, Modoru) == TRUE)
	{

		//�O�̕����ɖ߂邽�߂̓����蔻��A�O�̕����ɖ߂�

		player.CenterX = ModoruPt.x;
		player.CenterY = ModoruPt.y;


		player.image.x = player.CenterX;
		player.image.y = player.CenterY;

		if (CheckSoundMem(ROKA.handle) != 0)
		{
			StopSoundMem(ROKA.handle);	//BGM���~�߂�
		}

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
		//������O�ɖ߂�
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
	//�}�b�v��`��

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

	//�v���C���[�̕`��
	DrawGraph(player.image.x, player.image.y, playerChip1.handle[player.kind1], TRUE);

	//�����蔻��̕`��i�f�o�b�O�p�j
	for (int tate = 0; tate < MAP_HEIGHT_MAX; tate++)
	{
		for (int yoko = 0; yoko < MAP_WIDTH_MAX; yoko++)
		{

			//��O�ɖ߂锻��
			if (mapdata6[tate][yoko] == M)
			{
				DrawBox(mapColl[tate][yoko].left, mapColl[tate][yoko].top, mapColl[tate][yoko].right, mapColl[tate][yoko].bottom, GetColor(255, 0, 0), FALSE);
			}

		}
	}
	//�S�[�������蔻��p
	/*DrawBox(GoalRect2.left, GoalRect2.top, GoalRect2.right, GoalRect2.bottom, GetColor(255, 255, 0), TRUE);*/
	//�v���C���[�̓����蔻��p
	/*DrawBox(player.coll.left, player.coll.top, player.coll.right, player.coll.bottom, GetColor(255, 0, 0), FALSE);*/
	return;
}

VOID MY_PLAY3(VOID)
{
	MY_PLAY_PROC3();
	MY_PLAY_DRAW3();

	return;
}

VOID MY_PLAY_PROC3(VOID)
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

	player.kind1 = D_1; //���������Ă��Ȃ��Ƃ��̃v���C���̌���
	int old_x = player.image.x; //�����蔻��p
	int old_y = player.image.y;
	BOOL IsMove = TRUE;


	//��Ɉړ�����Ƃ�
	if (MY_KEY_DOWN(KEY_INPUT_W) == TRUE
		&& MY_KEY_DOWN(KEY_INPUT_D) == FALSE
		&& MY_KEY_DOWN(KEY_INPUT_S) == FALSE
		&& MY_KEY_DOWN(KEY_INPUT_A) == FALSE)
	{
		player.IsMoveNaname = FALSE;	//�΂߈ړ����Ă��Ȃ�

		if (player.kind1 >= U_1 && player.kind1 < U_4)
		{
			//�摜�ύX�J�E���^
			if (player.imgChangeCnt < player.imgChangeCntMAX)
			{
				player.imgChangeCnt++;
			}
			else //�摜��ς���^�C�~���O�ɂȂ�����
			{
				player.kind1++;			//���̉摜�ɂ���
				player.imgChangeCnt = 0;	//�ύX�J�E���^������
			}
		}
		else
		{
			player.kind1 = U_1;	//�ŏ��̉摜�ɂ���
		}

		player.image.y -= 1.5;	//�ړ�
	}

	//�E�Ɉړ�����Ƃ�
	if (MY_KEY_DOWN(KEY_INPUT_W) == FALSE
		&& MY_KEY_DOWN(KEY_INPUT_D) == TRUE
		&& MY_KEY_DOWN(KEY_INPUT_S) == FALSE
		&& MY_KEY_DOWN(KEY_INPUT_A) == FALSE)
	{
		player.IsMoveNaname = FALSE;	//�΂߈ړ����Ă��Ȃ�

		if (player.kind1 >= R_1 && player.kind1 < R_4)
		{
			//�摜�ύX�J�E���^
			if (player.imgChangeCnt < player.imgChangeCntMAX)
			{
				player.imgChangeCnt++;
			}
			else //�摜��ς���^�C�~���O�ɂȂ�����
			{
				player.kind1++;			//���̉摜�ɂ���
				player.imgChangeCnt = 0;	//�ύX�J�E���^������
			}
		}
		else
		{
			player.kind1 = R_1;	//�ŏ��̉摜�ɂ���
		}
		player.image.x += 2;	//�ړ�
	}

	//���Ɉړ�����Ƃ�
	if (MY_KEY_DOWN(KEY_INPUT_W) == FALSE
		&& MY_KEY_DOWN(KEY_INPUT_D) == FALSE
		&& MY_KEY_DOWN(KEY_INPUT_S) == FALSE
		&& MY_KEY_DOWN(KEY_INPUT_A) == TRUE)
	{
		player.IsMoveNaname = FALSE;	//�΂߈ړ����Ă��Ȃ�

		if (player.kind1 >= L_1 && player.kind1 < L_4)
		{
			//�摜�ύX�J�E���^
			if (player.imgChangeCnt < player.imgChangeCntMAX)
			{
				player.imgChangeCnt++;
			}
			else //�摜��ς���^�C�~���O�ɂȂ�����
			{
				player.kind1++;			//���̉摜�ɂ���
				player.imgChangeCnt = 0;	//�ύX�J�E���^������
			}
		}
		else
		{
			player.kind1 = L_1;	//�ŏ��̉摜�ɂ���
		}
		player.image.x -= 1.5;	//�ړ�
	}

	//���Ɉړ�����Ƃ�
	if (MY_KEY_DOWN(KEY_INPUT_W) == FALSE
		&& MY_KEY_DOWN(KEY_INPUT_D) == FALSE
		&& MY_KEY_DOWN(KEY_INPUT_S) == TRUE
		&& MY_KEY_DOWN(KEY_INPUT_A) == FALSE)
	{
		player.IsMoveNaname = FALSE;	//�΂߈ړ����Ă��Ȃ�

		if (player.kind1 >= D_1 && player.kind1 < D_4)
		{
			//�摜�ύX�J�E���^
			if (player.imgChangeCnt < player.imgChangeCntMAX)
			{
				player.imgChangeCnt++;
			}
			else //�摜��ς���^�C�~���O�ɂȂ�����
			{
				player.kind1++;			//���̉摜�ɂ���
				player.imgChangeCnt = 0;	//�ύX�J�E���^������
			}
		}
		else
		{
			player.kind1 = D_1;	//�ŏ��̉摜�ɂ���
		}
		player.image.y += 2;	//�ړ�
	}

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
	if (MY_CHECK_RECT_COLL(PlayerRect, GoalRect3) == TRUE && flag2 == 1)
	{

		//�O�֑J�ڂ���

		player.CenterX = startPt4.x;
		player.CenterY = startPt4.y;


		player.image.x = player.CenterX;
		player.image.y = player.CenterY;


		GameScene = GAME_SCENE_PLAY4;


		return;
	}



	if (MY_CHECK_RECT_COLL(PlayerRect, Modoru2) == TRUE)
	{

		//�L���ɖ߂锻��

		player.CenterX = Modoru2Pt.x;
		player.CenterY = Modoru2Pt.y;


		player.image.x = player.CenterX + 100;
		player.image.y = player.CenterY;

		GameScene = GAME_SCENE_PLAY2;


		return;	//�����I�ɃG���h��ʂɔ��
	}


	


	//�v���C���[�ƃ}�b�v���������Ă�����
	if (MY_CHECK_MAP3_PLAYER_COLL(player.coll) == TRUE)
	{
		//�����܂���
		IsMove = false;


	}

	if (IsMove == false)
	{
		player.image.x = old_x; //������O�ɖ߂�
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

VOID MY_PLAY_DRAW3(VOID)
{

	//�}�b�v��`�悷��
	for (int tate = 0; tate < MAP_HEIGHT_MAX; tate++)
	{
		for (int yoko = 0; yoko < MAP_WIDTH_MAX; yoko++)
		{


			DrawGraph(yoko * mapChip.width,
				tate * mapChip.height,
				mapChip.handle[mapdata7[tate][yoko]],
				TRUE);


		}

	}

	for (int tate = 0; tate < MAP_HEIGHT_MAX; tate++)
	{
		for (int yoko = 0; yoko < MAP_WIDTH_MAX; yoko++)
		{


			DrawGraph(yoko * mapChip.width,
				tate * mapChip.height,
				mapChip.handle[mapdata8[tate][yoko]],
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
				mapChip.handle[mapdata9[tate][yoko]],
				TRUE);


		}

	}

	//�S�[�������蔻��p
	/*DrawBox(GoalRect3.left, GoalRect3.top, GoalRect3.right, GoalRect3.bottom, GetColor(255, 255, 0), TRUE);
	//�߂锻��p
	DrawBox(Modoru2.left, Modoru2.top, Modoru2.right, Modoru2.bottom, GetColor(255, 0, 0), TRUE);*/
	
	//�A�C�e���t���O�̔���p
	//DrawBox(Itemflag.left, Itemflag.top, Itemflag.right, Itemflag.bottom, GetColor(0, 255, 0), TRUE);
	
	//�����蔻��̕`��i�f�o�b�O�p�j
	for (int tate = 0; tate < MAP_HEIGHT_MAX; tate++)
	{
		for (int yoko = 0; yoko < MAP_WIDTH_MAX; yoko++)
		{
			
			if (mapdata8[tate][yoko] == Z)
			{
				/*DrawBox(mapColl[tate][yoko].left + 30, mapColl[tate][yoko].top, mapColl[tate][yoko].right + 30, mapColl[tate][yoko].bottom, GetColor(255, 0, 0), FALSE);*/
			}

		}
	}

	DrawGraph(player.image.x, player.image.y, playerChip1.handle[player.kind1], TRUE);//�v���C���̕`��


	RECT PlayerRect;
	PlayerRect.left = player.CenterX - 40 / 20 + 5;
	PlayerRect.top = player.CenterY + 200 / 20 + 5;
	PlayerRect.right = player.CenterX + 650 / 20 - 5;
	PlayerRect.bottom = player.CenterY + 1000 / 20 - 5;


	//�t���O�C�x���g
	if (MY_CHECK_RECT_COLL(PlayerRect, Itemflag) == TRUE /*&& MY_KEY_DOWN(KEY_INPUT_RETURN)*/)
	{
		/*DrawString(0, 0, "��̃J�M����ɓ��ꂽ�I", GetColor(255, 0, 0));*/
		
		DrawGraph(TEXT_WIDTH_POSITION, TEXT_HEIGHT_POSITION, TextBox_flag.handle, TRUE);

		flag = 1;
		if (MY_KEY_DOWN(KEY_INPUT_RETURN) == TRUE)
		{
			DeleteGraph(TextBox_flag.handle);
		}
	
	}

	//����������Ă��Ȃ����A���ւ֍s���Ƃ�

	if (MY_CHECK_RECT_COLL(PlayerRect, GoalRect3) == TRUE && flag2 == 0)
	{
		

		DrawGraph(TEXT_WIDTH_POSITION, TEXT_HEIGHT_POSITION, TextBox_Null.handle, TRUE);

		if (MY_KEY_DOWN(KEY_INPUT_RETURN) == TRUE)
		{
			DeleteGraph(TextBox_Null.handle);
		}

	}

	return;
}

VOID MY_PLAY4(VOID)
{
	MY_PLAY_PROC4();	
	MY_PLAY_DRAW4();	

	return;
}

VOID MY_PLAY_PROC4(VOID)
{


	player.kind1 = D_1; //���������Ă��Ȃ��Ƃ��̃v���C���̌���
	int old_x = player.image.x;
	int old_y = player.image.y;
	BOOL IsMove = TRUE;


	//��Ɉړ�����Ƃ�
	if (MY_KEY_DOWN(KEY_INPUT_W) == TRUE
		&& MY_KEY_DOWN(KEY_INPUT_D) == FALSE
		&& MY_KEY_DOWN(KEY_INPUT_S) == FALSE
		&& MY_KEY_DOWN(KEY_INPUT_A) == FALSE)
	{
		player.IsMoveNaname = FALSE;	//�΂߈ړ����Ă��Ȃ�

		if (player.kind1 >= U_1 && player.kind1 < U_4)
		{
			//�摜�ύX�J�E���^
			if (player.imgChangeCnt < player.imgChangeCntMAX)
			{
				player.imgChangeCnt++;
			}
			else //�摜��ς���^�C�~���O�ɂȂ�����
			{
				player.kind1++;			//���̉摜�ɂ���
				player.imgChangeCnt = 0;	//�ύX�J�E���^������
			}
		}
		else
		{
			player.kind1 = U_1;	//�ŏ��̉摜�ɂ���
		}

		player.image.y -= 1.5;	//�ړ�
	}

	//�E�Ɉړ�����Ƃ�
	if (MY_KEY_DOWN(KEY_INPUT_W) == FALSE
		&& MY_KEY_DOWN(KEY_INPUT_D) == TRUE
		&& MY_KEY_DOWN(KEY_INPUT_S) == FALSE
		&& MY_KEY_DOWN(KEY_INPUT_A) == FALSE)
	{
		player.IsMoveNaname = FALSE;	//�΂߈ړ����Ă��Ȃ�

		if (player.kind1 >= R_1 && player.kind1 < R_4)
		{
			//�摜�ύX�J�E���^
			if (player.imgChangeCnt < player.imgChangeCntMAX)
			{
				player.imgChangeCnt++;
			}
			else //�摜��ς���^�C�~���O�ɂȂ�����
			{
				player.kind1++;			//���̉摜�ɂ���
				player.imgChangeCnt = 0;	//�ύX�J�E���^������
			}
		}
		else
		{
			player.kind1 = R_1;	//�ŏ��̉摜�ɂ���
		}
		player.image.x += 2;	//�ړ�
	}

	//���Ɉړ�����Ƃ�
	if (MY_KEY_DOWN(KEY_INPUT_W) == FALSE
		&& MY_KEY_DOWN(KEY_INPUT_D) == FALSE
		&& MY_KEY_DOWN(KEY_INPUT_S) == FALSE
		&& MY_KEY_DOWN(KEY_INPUT_A) == TRUE)
	{
		player.IsMoveNaname = FALSE;	//�΂߈ړ����Ă��Ȃ�

		if (player.kind1 >= L_1 && player.kind1 < L_4)
		{
			//�摜�ύX�J�E���^
			if (player.imgChangeCnt < player.imgChangeCntMAX)
			{
				player.imgChangeCnt++;
			}
			else //�摜��ς���^�C�~���O�ɂȂ�����
			{
				player.kind1++;			//���̉摜�ɂ���
				player.imgChangeCnt = 0;	//�ύX�J�E���^������
			}
		}
		else
		{
			player.kind1 = L_1;	//�ŏ��̉摜�ɂ���
		}
		player.image.x -= 1.5;	//�ړ�
	}

	//���Ɉړ�����Ƃ�
	if (MY_KEY_DOWN(KEY_INPUT_W) == FALSE
		&& MY_KEY_DOWN(KEY_INPUT_D) == FALSE
		&& MY_KEY_DOWN(KEY_INPUT_S) == TRUE
		&& MY_KEY_DOWN(KEY_INPUT_A) == FALSE)
	{
		player.IsMoveNaname = FALSE;	//�΂߈ړ����Ă��Ȃ�

		if (player.kind1 >= D_1 && player.kind1 < D_4)
		{
			//�摜�ύX�J�E���^
			if (player.imgChangeCnt < player.imgChangeCntMAX)
			{
				player.imgChangeCnt++;
			}
			else //�摜��ς���^�C�~���O�ɂȂ�����
			{
				player.kind1++;			//���̉摜�ɂ���
				player.imgChangeCnt = 0;	//�ύX�J�E���^������
			}
		}
		else
		{
			player.kind1 = D_1;	//�ŏ��̉摜�ɂ���
		}
		player.image.y += 2;	//�ړ�
	}

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
	if (MY_CHECK_RECT_COLL(PlayerRect, GoalRect4) == TRUE)
	{


		//�G���h��ʂ֑J��

		GameScene = GAME_SCENE_END;


		return;
	}


	//�Ƃ̒��ɖ߂��悤�ɂ���\��
	//if (MY_CHECK_RECT_COLL(PlayerRect, Modoru2) == TRUE)
	//{



	//	player.CenterX = Modoru2Pt.x;
	//	player.CenterY = Modoru2Pt.y;


	//	player.image.x = player.CenterX + 100;
	//	player.image.y = player.CenterY;

	//	GameScene = GAME_SCENE_PLAY3;


	//	return;	//�����I�ɃG���h��ʂɔ��
	//}





	//�v���C���[�ƃ}�b�v���������Ă�����
	if (MY_CHECK_MAP4_PLAYER_COLL(player.coll) == TRUE)
	{
		//�����܂���
		IsMove = false;


	}

	if (IsMove == false)
	{
		player.image.x = old_x;//������O�ɖ߂�
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

VOID MY_PLAY_DRAW4(VOID)
{

	//�}�b�v�̕`��

	for (int tate = 0; tate < MAP_HEIGHT_MAX; tate++)
	{
		for (int yoko = 0; yoko < MAP_WIDTH_MAX; yoko++)
		{


			DrawGraph(yoko * mapChip2.width,
				tate * mapChip2.height,
				mapChip2.handle[mapdata11[tate][yoko]],
				TRUE);


		}

	}

	for (int tate = 0; tate < MAP_HEIGHT_MAX; tate++)
	{
		for (int yoko = 0; yoko < MAP_WIDTH_MAX; yoko++)
		{


			DrawGraph(yoko * mapChip2.width,
				tate * mapChip2.height,
				mapChip2.handle[mapdata12[tate][yoko]],
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
				mapChip2.handle[mapdata13[tate][yoko]],
				TRUE);


		}

	}

	DrawGraph(player.image.x, player.image.y, playerChip1.handle[player.kind1], TRUE);//�v���C���̕`��

	//�o���p
	//DrawBox(GoalRect4.left, GoalRect4.top, GoalRect4.right, GoalRect4.bottom, GetColor(255, 255, 0), TRUE);

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
	DrawString(400, 400, "�I�����̃e�L�X�g", GetColor(255, 255, 255));

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

	//########################################################################
	
	strcpy_s(TextBox_start.path, TEXT_BOX);	//�v�摜
	TextBox_start.handle = LoadGraph(TextBox_start.path);			//�ǂݍ���
	if (TextBox_start.handle == -1)
	{
		//�G���[���b�Z�[�W�\��
		MessageBox(GetMainWindowHandle(), TEXT_BOX, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	strcpy_s(TextBox_flag.path, TEXT_BOX_1);//�ŏ��̃t���O�C�x���g�̃e�L�X�g�{�b�N�X
	TextBox_flag.handle = LoadGraph(TextBox_flag.path);			//�ǂݍ���
	if (TextBox_flag.handle == -1)
	{
		//�G���[���b�Z�[�W�\��
		MessageBox(GetMainWindowHandle(), TEXT_BOX_1, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	strcpy_s(TextBox_Null.path, TEXT_BOX_2); //�A�C�e����������Ă��Ȃ��Ƃ��̌��ւ̃e�L�X�g�{�b�N�X
	TextBox_Null.handle = LoadGraph(TextBox_Null.path);			//�ǂݍ���
	if (TextBox_Null.handle == -1)
	{
		//�G���[���b�Z�[�W�\��
		MessageBox(GetMainWindowHandle(), TEXT_BOX_2, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	strcpy_s(TextBox_GenkanKagiNasi.path, TEXT_BOX_3); //����������Ă��Ȃ��Ƃ��A���ɋ߂Â����Ƃ��ɔ�������e�L�X�g�{�b�N�X
	TextBox_GenkanKagiNasi.handle = LoadGraph(TextBox_GenkanKagiNasi.path);			//�ǂݍ���
	if (TextBox_GenkanKagiNasi.handle == -1)
	{
		//�G���[���b�Z�[�W�\��
		MessageBox(GetMainWindowHandle(), TEXT_BOX_3, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	strcpy_s(TextBox_GenkanKagi.path, TEXT_BOX_4); //����������Ă���Ƃ��ɔ����J������
	TextBox_GenkanKagi.handle = LoadGraph(TextBox_GenkanKagi.path);			//�ǂݍ���
	if (TextBox_GenkanKagi.handle == -1)
	{
		//�G���[���b�Z�[�W�\��
		MessageBox(GetMainWindowHandle(), TEXT_BOX_4, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}



	//###########################################################################

	int mapRes = LoadDivGraph(
		GAME_MAP_PATH,										//�}�b�v�`�b�v�p�X
		MAP_DIV_NUM, MAP_DIV_TATE, MAP_DIV_YOKO,			//�}�b�v�`�b�v�𕪊����鐔
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

	int mapRes10 = LoadDivGraph(
		GAME_MAP_PATH2,										//��ڂ̃}�b�v�`�b�v�̃p�X
		MAP_NUM, MAP_YOKO, MAP_TATE,						//�}�b�v�𕪊����鐔
		MAP_DIV_WIDTH, MAP_DIV_HEIGHT,						//�摜�𕪊�����̕��ƍ���
		&mapChip2.handle[0]);								//���������摜������n���h��

	if (mapRes10 == -1)
	{
		//�G���[���b�Z�[�W�\��
		MessageBox(GetMainWindowHandle(), GAME_MAP_PATH2, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	//���ƍ������擾
	GetGraphSize(mapChip2.handle[0], &mapChip2.width, &mapChip2.height);

	

	
	GetGraphSize(player.image.handle, &player.image.width, &player.image.height);
	player.image.x = GAME_WIDTH / 2 - player.image.width / 2;
	player.image.y = GAME_HEIGHT / 2 - player.image.height / 2;
	player.CenterX = player.image.x + player.image.width / 2;
	player.CenterY = player.image.y + player.image.height / 2;
	player.imgChangeCnt = 0;
	player.imgChangeCntMAX = PLAYER_IMG_CHANGE_MAX;	//�摜��ύX����J�E���^MAX


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

	
	return TRUE;
}

BOOL MY_LOAD_PLAYER(const char* path, PLAYERCHIP* player)
{
	//�v���C���[�̉摜�𕪊�����
	int mapRes = LoadDivGraph(
		GAME_PLAYER_PATH,										//�v���C���[�̃p�X
		PLAYER_DIV_NUM, PLAYER_DIV_TATE, PLAYER_DIV_YOKO,			
		PLAYER_DIV_WIDTH, PLAYER_DIV_HEIGHT,
		&player->handle[0]);								//�摜������n���h��

	if (mapRes == -1)	//�G���[���b�Z�[�W�\��
	{
		MessageBox(GetMainWindowHandle(), path, IMAGE_LOAD_ERR_TITLE, MB_OK); return FALSE;
	}

	//���ƍ������擾
	GetGraphSize(player->handle[0], &player->width, &player->height);

	return TRUE;
}

//�摜���܂Ƃ߂č폜����֐�
VOID DELETE_IMAGE(VOID)
{
	DeleteGraph(imageBACK.handle);
	DeleteGraph(ImageSetumei.handle);
	DeleteGraph(player.image.handle);
	DeleteGraph(TextBox_flag.handle);
	DeleteGraph(TextBox_Null.handle);
	DeleteGraph(TextBox_GenkanKagiNasi.handle);
	DeleteGraph(TextBox_GenkanKagi.handle);
	for (int i_num = 0; i_num < MAP_DIV_NUM; i_num++) { DeleteGraph(mapChip.handle[i_num]); }
	for (int i_num = 0; i_num < MAP_DIV_NUM; i_num++) { DeleteGraph(mapChip2.handle[i_num]); }
	for (int i_num = 0; i_num < MAP_DIV_NUM; i_num++) { DeleteGraph(mapChip_Nowalk.handle[i_num]); }
	for (int i_num = 0; i_num < MAP_DIV_NUM; i_num++) { DeleteGraph(mapChip_Object.handle[i_num]); }
	for (int i_num = 0; i_num < MAP_DIV_NUM; i_num++) { DeleteGraph(mapChip_Roka.handle[i_num]); }
	for (int i_num = 0; i_num < MAP_DIV_NUM; i_num++) { DeleteGraph(mapChip_RokaNowalk.handle[i_num]); }
	return;
}

//���y���܂Ƃ߂ēǂݍ��ފ֐�
BOOL LOAD_MUSIC(VOID)
{
	//�^�C�g��BGM
	strcpy_s(BGM.path, TITLE_BGM_PATH);		//�^�C�g��BGM�̐ݒ�
	BGM.handle = LoadSoundMem(BGM.path);	//�ǂݍ���
	if (BGM.handle == -1)
	{
		//�G���[���b�Z�[�W�\��
		MessageBox(GetMainWindowHandle(), TITLE_BGM_PATH, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	strcpy_s(ROKA.path, ROKA_BGM_PATH);		//�L��BGM�̐ݒ�
	ROKA.handle = LoadSoundMem(ROKA.path);	//�ǂݍ���
	if (ROKA.handle == -1)
	{
		//�G���[���b�Z�[�W�\��
		MessageBox(GetMainWindowHandle(), ROKA_BGM_PATH, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	strcpy_s(FLAG.path, FLAG_BGM_PATH);		//�A�C�e���l�������ʉ��̐ݒ�
	FLAG.handle = LoadSoundMem(FLAG.path);	//�ǂݍ���
	if (FLAG.handle == -1)
	{
		//�G���[���b�Z�[�W�\��
		MessageBox(GetMainWindowHandle(), FLAG_BGM_PATH, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}




	return TRUE;
}

//���y���܂Ƃ߂č폜����֐�
VOID DELETE_MUSIC(VOID)
{
	DeleteSoundMem(BGM.handle);
	DeleteSoundMem(ROKA.handle);
	DeleteSoundMem(FLAG.handle);
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
				
	
				//�v���C���[�ƃ}�b�v���������Ă���
				if (mapdata3[tate][yoko] == d) { return TRUE; }
				if (mapdata3[tate][yoko] == B) { return TRUE; }
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

BOOL MY_CHECK_MAP3_PLAYER_COLL(RECT player)
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
				if (mapdata8[tate][yoko] == t) { return TRUE; }
				if (mapdata8[tate][yoko] == s) { return TRUE; }
				if (mapdata8[tate][yoko] == g) { return TRUE; }
				if (mapdata8[tate][yoko] == P) { return TRUE; }
				if (mapdata8[tate][yoko] == N) { return TRUE; }
				if (mapdata8[tate][yoko] == O) { return TRUE; }
				if (mapdata9[tate][yoko] == d) { return TRUE; }
				if (mapdata9[tate][yoko] == p) { return TRUE; }
				if (mapdata9[tate][yoko] == q) { return TRUE; }
				if (mapdata9[tate][yoko] == R) { return TRUE; }
				if (mapdata9[tate][yoko] == v) { return TRUE; }
				if (mapdata9[tate][yoko] == w) { return TRUE; }
				if (mapdata9[tate][yoko] == z) { return TRUE; }
				if (mapdata9[tate][yoko] == A) { return TRUE; }
			}
		}
	}

	return FALSE;
}

BOOL MY_CHECK_MAP4_PLAYER_COLL(RECT player)
{
	//�}�b�v�̓����蔻���ݒ肷��
	for (int tate = 0; tate < MAP_HEIGHT_MAX; tate++)
	{
		for (int yoko = 0; yoko < MAP_WIDTH_MAX; yoko++)
		{
			//�v���C���[�ƃ}�b�v���������Ă���Ƃ�
			if (MY_CHECK_RECT_COLL(player, mapColl[tate][yoko]) == TRUE)
			{

				//�v���C���[�ƃ}�b�v���������Ă���
			

				if (mapdata13[tate][yoko] == FE) { return TRUE; }
				if (mapdata13[tate][yoko] == FE2) { return TRUE; }
				if (mapdata13[tate][yoko] == SB) { return TRUE; }
				
			}
		}
	}

	return FALSE;
}

