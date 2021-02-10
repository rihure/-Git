#include "DxLib.h"
#include "stdlib.h"
#include "string.h"

#define TITLE_NAME TEXT("�s�v�c�ȉ�")

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
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
#define IMAGE_SETUMEI_KEY_W TEXT(".\\IMAGE\\�������3_W.png")//W�L�[���͎�
#define IMAGE_SETUMEI_KEY_A TEXT(".\\IMAGE\\�������3_A.png")//A�L�[���͎�
#define IMAGE_SETUMEI_KEY_S TEXT(".\\IMAGE\\�������3_S.png")//S�L�[���͎�
#define IMAGE_SETUMEI_KEY_D TEXT(".\\IMAGE\\�������3_D.png")//D�L�[���͎�
#define GAME_MAP_PATH TEXT(".\\IMAGE\\ST-Town-I01.png") //�}�b�v�`�b�v
#define GAME_MAP_PATH2 TEXT(".\\IMAGE\\mapchip1.png") //�}�b�v�`�b�v2
#define GAME_PLAYER_PATH TEXT(".\\IMAGE\\joshi03.png") //�v���C���[�̉摜
#define TEXT_BOX TEXT(".\\IMAGE\\TextBox_start.png")  //���݂͖v�ł���
#define TEXT_BOX_1 TEXT(".\\IMAGE\\TextBox1.png") //�A�C�e��������̃e�L�X�g�{�b�N�X
#define TEXT_BOX_2 TEXT(".\\IMAGE\\TextBox������.png") //�A�C�e��������Ă��Ȃ��Ƃ�
#define TEXT_BOX_3 TEXT(".\\IMAGE\\TextBox���֌�����.png")//�����擾��
#define TEXT_BOX_4 TEXT(".\\IMAGE\\TextBox���֌�����.png")//���������Ă��Ȃ�
#define TEXT_BOX_5 TEXT(".\\IMAGE\\TextBox_kanban.png")//�O�̊Ŕ�
#define TEXT_BOX_6 TEXT(".\\IMAGE\\TextBox_akanai.png") //��������Ȃ��Ƃ�
#define TEXT_BOX_7 TEXT(".\\IMAGE\\TextBox�����莆.png")//�B�������̃e�L�X�g�{�b�N�X
#define GAME_MENU_BTN TEXT(".\\IMAGE\\Menu_btn1.png")//�X�^�[�g�{�^��
#define GAME_MENU_BTN2 TEXT(".\\IMAGE\\Menu_btn2.png")//�I���{�^��
#define GAME_MENU_BTN3 TEXT(".\\IMAGE\\Menu_btn3.png")//�I�v�V�����{�^��

#define HINT TEXT(".\\IMAGE\\NazotokiYoushi.png")//�B�������̃q���g

#define OPTION_SOUND_VOLUME  TEXT(".\\IMAGE\\Volume0.png")//���ʃ{�^��
#define OPTION_SOUND_VOLUME1 TEXT(".\\IMAGE\\Volume25.png")//���ʃ{�^��
#define OPTION_SOUND_VOLUME2 TEXT(".\\IMAGE\\Volume50.png")//���ʃ{�^��
#define OPTION_SOUND_VOLUME3 TEXT(".\\IMAGE\\Volume75.png")//���ʃ{�^��
#define OPTION_SOUND_VOLUME4 TEXT(".\\IMAGE\\Volume100.png")//���ʃ{�^��

#define OPTION_SOUND_EFFECT  TEXT(".\\IMAGE\\SE_Volume0.png")//���ʉ����ʃ{�^��
#define OPTION_SOUND_EFFECT1 TEXT(".\\IMAGE\\SE_Volume25.png")//���ʉ����ʃ{�^��
#define OPTION_SOUND_EFFECT2 TEXT(".\\IMAGE\\SE_Volume50.png")//���ʉ����ʃ{�^��
#define OPTION_SOUND_EFFECT3 TEXT(".\\IMAGE\\SE_Volume75.png")//���ʉ����ʃ{�^��
#define OPTION_SOUND_EFFECT4 TEXT(".\\IMAGE\\SE_Volume100.png")//���ʉ����ʃ{�^��

#define OPTION_SOUND_DECISION  TEXT(".\\IMAGE\\DC_Volume0.png")//���艹���ʃ{�^��
#define OPTION_SOUND_DECISION1 TEXT(".\\IMAGE\\DC_Volume25.png")//���艹���ʃ{�^��
#define OPTION_SOUND_DECISION2 TEXT(".\\IMAGE\\DC_Volume50.png")//���艹���ʃ{�^��
#define OPTION_SOUND_DECISION3 TEXT(".\\IMAGE\\DC_Volume75.png")//���艹���ʃ{�^��
#define OPTION_SOUND_DECISION4 TEXT(".\\IMAGE\\DC_Volume100.png")//���艹���ʃ{�^��

//gif
#define SYBER_MAP TEXT(".\\IMAGE\\giphy.gif")//�B������

//BGM�̃p�X��ݒ�
#define TITLE_BGM_PATH TEXT(".\\MUSIC\\�~�̏�i�ɂ�.mp3") //�^�C�g��BGM
#define ROKA_BGM_PATH TEXT(".\\MUSIC\\����̊�.mp3") //�L���̂�����ƕ|��BGM
#define FLAG_BGM_PATH TEXT(".\\MUSIC\\se_maoudamashii_onepoint07.mp3")//�A�C�e���擾���̌��ʉ�
#define SERECT_EFFECT TEXT(".\\MUSIC\\�Z���N�g��_3.mp3")//�I�����̌��ʉ�
#define DECISION_EFFECT TEXT(".\\MUSIC\\�V�X�e�����艹_11.mp3")//���莞�̌��ʉ�
#define SYBER_BGM TEXT(".\\MUSIC\\Challenge_try_02.mp3")//�B������BGM

//�G���[���b�Z�[�W
#define IMAGE_LOAD_ERR_TITLE	TEXT("�摜�ǂݍ��݃G���[")
#define MUSIC_LOAD_ERR_TITLE	TEXT("���y�ǂݍ��݃G���[")

//�p�X�̒���
#define PATH_MAX			255	//255�����܂�
#define NAME_MAX			255	//255�����܂�

//�L�[�{�[�h�̎��
#define KEY_CODE_KIND		256	//256���

//�����`��p
#define STR_DRAW_SIZE	24		//�t�H���g�̃T�C�Y
#define STR_DRAW_ROW_MAX	4	//������̍ő�s
#define STR_ROW_MAX		30		//�����s�̍ő�l
#define STR_COL_MAX		255		//������̍ő�l
#define STR_DRAW_SPEED	1		//������̕`�摬�x(���t���[�����ƂɁA�P�����`�悷�邩�H)

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

//�摜�̊g�嗦
#define IMAGE_TITLE_ROGO_ROTA		0.005		//�g�嗦
#define GAME_MENU_BTN_ROTA	1			//�g�嗦MAX

enum GAME_SCENE {
	GAME_SCENE_START,
	GAME_SCENE_SETUMEI,
	GAME_SCENE_SCENARIO,
	GAME_SCENE_OPTION,
	GAME_SCENE_PLAY,
	GAME_SCENE_PLAY2,
	GAME_SCENE_PLAY3,
	GAME_SCENE_PLAY4,
	GAME_SCENE_KAKUSI,
	GAME_SCENE_END
};	//�Q�[���̃V�[��

enum GAME_MENU {
	GAME_MENU_START,
	GAME_MENU_EXIT,
	GAME_MENU_OPTION
};

enum VOLUME {
	VOLUME0,
	VOLUME25,
	VOLUME50,
	VOLUME75,
	VOLUME100,
	EFFECT0,
	EFFECT25,
	EFFECT50,
	EFFECT75,
	EFFECT100,
	DECISION0,
	DECISION25,
	DECISION50,
	DECISION75,
	DECISION100
};

enum GAME_MAP_KIND
{
	/*n = -1,*/	//(NONE)����
	GL = 0, //�O�̒n��
	k = 10,	//��
	t = 17,	//���
	s = 25,	//����
	KABE = 28,//�F�̈Ⴄ��
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
	KA = 269, //�B��������
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

typedef struct STRUCT_IMAGE_ROTA
{
	IMAGE image;		//IMAGE�\����
	double rate;		//�g�嗦
	double rateMAX;		//�g�嗦MAX

}IMAGE_ROTA;	//��]�g�傷��摜�̍\����

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
int mapdata14[MAP_HEIGHT_MAX][MAP_WIDTH_MAX];
int mapdata15[MAP_HEIGHT_MAX][MAP_WIDTH_MAX];


int MapDataMode[MAP_HEIGHT_MAX][MAP_WIDTH_MAX];

//�}�b�v�`�b�v�̉摜���Ǘ�
MAPCHIP mapChip;
MAPCHIP mapChip2;
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
IMAGE TextBox_Kanban; //�Ŕ�
IMAGE TextBox_akanai; //��������Ȃ��Ƃ�
IMAGE TextBox_kakushi; //�B�������̃e�L�X�g�{�b�N�X
IMAGE HINT_KAMI; //�q���g�p��
IMAGE_ROTA GameMenu_START; //�X�^�[�g�{�^��
IMAGE_ROTA GameMenu_EXIT;	//�I���{�^��
IMAGE_ROTA GameMenu_OPTION; //�ݒ�{�^��
IMAGE ImageSetumei_KEY_W; //�e�L�[
IMAGE ImageSetumei_KEY_A;
IMAGE ImageSetumei_KEY_S;
IMAGE ImageSetumei_KEY_D;
IMAGE_ROTA SOUND_VOLUME;//�e���ʒ����{�^��
IMAGE_ROTA SOUND_VOLUME1;
IMAGE_ROTA SOUND_VOLUME2;
IMAGE_ROTA SOUND_VOLUME3;
IMAGE_ROTA SOUND_VOLUME4;

IMAGE_ROTA SOUND_EFFECT;//���ʉ��e���ʒ����{�^��
IMAGE_ROTA SOUND_EFFECT1;
IMAGE_ROTA SOUND_EFFECT2;
IMAGE_ROTA SOUND_EFFECT3;
IMAGE_ROTA SOUND_EFFECT4;

IMAGE_ROTA SOUND_DECISION;//���艹�e���ʒ����{�^��
IMAGE_ROTA SOUND_DECISION1;
IMAGE_ROTA SOUND_DECISION2;
IMAGE_ROTA SOUND_DECISION3;
IMAGE_ROTA SOUND_DECISION4;

IMAGE SYBER;


iPOINT startPt{ -1, -1 }; //�ŏ��̃X�^�[�g�|�C���g
iPOINT startPt2{ -1 , -1 };//�L���̃X�^�[�g�|�C���g
iPOINT startPt3{ -1 , -1 }; //���ւ����镔���̃X�^�[�g�|�C���g
iPOINT startPt4{ -1,-1 }; //�O�̃X�^�[�g�|�C���g
iPOINT startPt5{ -1,-1 };//�B�������̃X�^�[�g�|�C���g
RECT GoalRect = { -1,-1, -1, -1 };	//�ŏ��̏o���|�C���g
RECT GoalRect2 = { -1, -1 , -1, -1 };//�L���̏o���|�C���g
RECT GoalRect3 = { -1, -1, -1, -1 };//���ւ�����o���|�C���g
RECT GoalRect4 = { -1,-1,-1,-1 };//�O�̏o���|�C���g
RECT Kakushi = { -1,-1,-1,-1 };//�B��������
RECT KakushiD = { -1,-1,-1,-1 };//�B����������̒E�o

RECT Modoru = { -1, -1, -1,-1 }; //��O�̕����ɖ߂锻��
RECT Modoru2 = { -1,-1,-1,-1 };//�L���ɖ߂锻��
RECT Itemflag = { -1,-1,-1,-1 }; //�A�C�e���t���O�̓����蔻��
RECT Itemflag2 = { -1,-1,-1,-1 };//�ŏ��̕����̃t���O����
RECT Kanban = { -1,-1,-1,-1 }; 
iPOINT ModoruPt{ -1,-1 };
iPOINT Modoru2Pt{ -1,-1, };

//BGM
MUSIC BGM; //�^�C�g��BGM
MUSIC ROKA;//�L����BGM
//SE
MUSIC FLAG; //�A�C�e���擾���̌��ʉ������݂͖v
MUSIC SERECT; //�Z���N�g���ʉ�
MUSIC DECISION; //����
MUSIC SYBERB;

int GameScene;		//�Q�[���V�[�����Ǘ�
int GameMenu = 0;	//�Q�[�����j���[���Ǘ�
int OptionMenu = 2; //�I�v�V�����V�[�����Ǘ�

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

//�e�L�X�g�{�b�N�X��\�����邩�̔���
int hyouji;
int hyouji2;
int hyouji3;
int hyouji4;
int hyouji5;
int hyouji6;
int hyouji7;
int KEY_A;
int KEY_W;
int KEY_S;
int KEY_D;

int DrawPointX, DrawPointY;	// ������`��̈ʒu
int RowPos;					// ������̍s��
int ColPos;					// ������̗�
BOOL EndFlag = FALSE;		// ������I���t���O
char OneMojiBuf[3];			// �P�������ꎞ�L���z��(�P�������{\0)
char DrawStringBuf[STR_DRAW_ROW_MAX][STR_COL_MAX];		// �`�悷�镶���������
int DefaultFontSize;								// �f�t�H���g�̃t�H���g�T�C�Y���擾
RECT rectString = { 0,GAME_HEIGHT - STR_DRAW_SIZE * STR_DRAW_ROW_MAX,GAME_WIDTH,GAME_HEIGHT };	// ������`��p�G���A
int DrawSpeedCnt = 0;					//�����̕`�摬�x�J�E���^
int DrawSpeedCntMax = STR_DRAW_SPEED;	//�����̕`�摬�x�J�E���^MAX

int Kaigyou(VOID);							//���s�֐�


char SCENARIO[STR_ROW_MAX][STR_COL_MAX] =
{
	"������̂��ƁA�ڂ��o�߂���l���͌��m��ʏꏊ�ɂ����BB",
	"@�@�q�ɂƂ��Ďg���Ă���̂��킩��Ȃ���",
	"@�@����ɂ͑����̃_���{�[�����ςݏd�Ȃ��Ă����BB",
	"@�@��l���͂��̓�̉Ƃ���o�邽�߂ɁA�T�������邱�Ƃɂ����BB",
	"E"

};

char SCENARIO_END[STR_ROW_MAX][STR_COL_MAX] =
{
	"���̉ƂɂȂ������͋����̂�B",
	"@�Ȃ������߂��Ă����̂��A�����ɕ�����Ȃ������BB",
	"@�������A���̉Ƃɂ͓��̂̂���Ȃ��i�j��������̂�B",
	"@��̕��͋C�ŕ��������BB",
	"@���̌���A�C�ɂȂ��ĉƂ��������ꏊ�֍s������B",
	"@�����͕��n�ő��؂���{�������Ă��Ȃ������BB",
	"E"

};



VOID MY_FPS_UPDATE(VOID);			//FPS�l���v���A�X�V����
BOOL LOAD_IMAGE(VOID);		//�摜���܂Ƃ߂ēǂݍ��ފ֐�
VOID DELETE_IMAGE(VOID);		//�摜���܂Ƃ߂č폜����֐�

VOID MY_FPS_WAIT(VOID);				//FPS�l���v�����A�҂�

BOOL LOAD_MUSIC(VOID);		//���y���܂Ƃ߂ēǂݍ��ފ֐�
VOID DELETE_MUSIC(VOID);		//���y���܂Ƃ߂č폜����֐�
VOID MY_ALL_KEYDOWN_UPDATE(VOID);	//�L�[�̓��͏�Ԃ��X�V����
BOOL MY_KEY_DOWN(int);				//�L�[�������Ă��邩�A�L�[�R�[�h�Ŕ��f����
BOOL MY_KEY_UP(int);				//�L�[�������グ�����A�L�[�R�[�h�Ŕ��f����


VOID MY_START(VOID);		//�X�^�[�g���
VOID MY_START_PROC(VOID);	//�X�^�[�g��ʂ̏���
VOID MY_START_DRAW(VOID);	//�X�^�[�g��ʂ̕`��

VOID MY_SETUMEI(VOID); //�������
VOID MY_START_SETUMEI_DRAW(VOID); //������ʂ̕`��

VOID MY_SCENARIO(VOID); //�V�i���I����
VOID MY_OPTION(VOID); //�ݒ���(�J����)

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
VOID MY_PLAY_KAKUSI(VOID); //�B������
VOID MY_PLAY_PROC_KAKUSI(VOID);
VOID MY_PLAY_KAKUSHI_DRAW(VOID);

VOID MY_END(VOID);			//�G���h���
VOID MY_END_PROC(VOID);		//�G���h��ʂ̏���
VOID MY_END_DRAW(VOID);		//�G���h��ʂ̕`��

VOID NovelProc(char str[][STR_COL_MAX]);	//���������񏈗��֐��i�����ŕ`�悷�镶��������炤�j
VOID NovelDraw(VOID);						//����������`��֐�

BOOL MY_CHECK_MAP1_PLAYER_COLL(RECT);	//�}�b�v�ƃv���C���[�̓����蔻�������֐�
BOOL MY_CHECK_RECT_COLL(RECT, RECT);	//�̈�̓����蔻�������֐�
BOOL MY_CHECK_MAP2_PLAYER_COLL(RECT);   //�L���̓����蔻���ݒ肷��֐�
BOOL MY_CHECK_MAP3_PLAYER_COLL(RECT);   //���ւ̕����̓����蔻���ݒ肷��֐�
BOOL MY_CHECK_MAP4_PLAYER_COLL(RECT);  //�O�̓����蔻���ݒ肷��֐�
BOOL MY_CHECK_SYBER_PLAYER_COLL(RECT); //�B�������̓����蔻�������֐�


BOOL MY_LOAD_PLAYER(const char* path, PLAYERCHIP* player); //�v���C���[�̃`�b�v�𕪊����X����



int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetOutApplicationLogValidFlag(FALSE);				//Log.txt���o�͂��Ȃ�
	ChangeWindowMode(TRUE);								//�E�B���h�E���[�h�ɐݒ�
	SetGraphMode(GAME_WIDTH, GAME_HEIGHT, GAME_COLOR);	//�w��̐��l�ŃE�B���h�E��\������
	SetWindowStyleMode(0);				//�^�C�g���o�[�̓f�t�H���g�ɂ���
	SetAlwaysRunFlag(TRUE);								//��A�N�e�B�u�ł����s����
	SetMainWindowText(TITLE_NAME);								//�^�C�g���l�[��
	SetWindowIconID(444);									//�Q�[���A�C�R��
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
				break;

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

			case 'K':
				//�ǂ̂Ƃ�
				mapdata5[tateCnt][yokoCnt] = KABE;
				yokoCnt++;

				Kakushi.left = (mapChip.width * yokoCnt) - mapChip.width;
				Kakushi.top = (mapChip.height * tateCnt);
				Kakushi.right = (mapChip.width * (yokoCnt + 1)) - mapChip.width;
				Kakushi.bottom = mapChip.height * (tateCnt + 1);

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

				Kanban.left = (mapChip2.width * yokoCnt) - mapChip2.width;
				Kanban.top = (mapChip2.height * tateCnt) + 20;
				Kanban.right = (mapChip2.width * (yokoCnt + 1)) - mapChip2.width;
				Kanban.bottom = mapChip2.height * (tateCnt + 1);
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

	//#########################�B������##################################################

	result = 0;
	tateCnt = 0;
	yokoCnt = 0;

	fp = fopen(".\\TXT\\Syber.txt", "r");

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
				mapdata14[tateCnt][yokoCnt] = n;
				yokoCnt++;
				break;

			case 'S':
				//�ǂ̂Ƃ�
				mapdata14[tateCnt][yokoCnt] = S;
				yokoCnt++;
				//�X�^�[�g�ʒu���Z�b�g
				startPt5.x = mapChip.width * yokoCnt - 30;	//���SX���W���擾
				startPt5.y = mapChip.height * tateCnt - 20;	//���SY���W���擾

				break;

			case 'G':
				//�ǂ̂Ƃ�
				mapdata14[tateCnt][yokoCnt] = G;
				yokoCnt++;

				KakushiD.left = (mapChip.width * yokoCnt) - mapChip.width;
				KakushiD.top = (mapChip.height * tateCnt);
				KakushiD.right = (mapChip.width * (yokoCnt + 1)) - mapChip.width;
				KakushiD.bottom = mapChip.height * (tateCnt + 1);

				break;

			case 'B':
				mapdata14[tateCnt][yokoCnt] = B;
				yokoCnt++;

				Itemflag.left = (mapChip.width * yokoCnt) - mapChip.width;
				Itemflag.top = (mapChip.height * tateCnt);
				Itemflag.right = (mapChip.width * (yokoCnt + 1)) - mapChip.width;
				Itemflag.bottom = mapChip.height * (tateCnt + 1);
				break;

			case 'Z':
				mapdata14[tateCnt][yokoCnt] = Z;
				yokoCnt++;

				Itemflag2.left = (mapChip.width * yokoCnt) - mapChip.width;
				Itemflag2.top = (mapChip.height * tateCnt);
				Itemflag2.right = (mapChip.width * (yokoCnt + 1)) - mapChip.width;
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

	//�J������A�K�����邱�ƁI
	fclose(fp);	//�t�@�C�������


	result = 0;
	tateCnt = 0;
	yokoCnt = 0;

	fp = fopen(".\\TXT\\Syber_Object.txt", "r");

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
				mapdata15[tateCnt][yokoCnt] = n;
				yokoCnt++;
				break;

			case 'd':
				//�ǂ̂Ƃ�
				mapdata15[tateCnt][yokoCnt] = d;
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

		case GAME_SCENE_OPTION:
			MY_OPTION(); //�I�v�V�������
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

		case GAME_SCENE_KAKUSI:
			MY_PLAY_KAKUSI(); //�B������
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

//�L�[�������グ�����A�L�[�R�[�h�Ŕ��f����
BOOL MY_KEY_UP(int KEY_INPUT_)
{
	if (OldAllKeyState[KEY_INPUT_] >= 1	//���O�͉����Ă���
		&& AllKeyState[KEY_INPUT_] == 0)	//���͉����Ă��Ȃ��Ƃ�
	{
		return TRUE;	//�L�[�������グ�Ă���
	}
	else
	{
		return FALSE;	//�L�[�������グ�Ă��Ȃ�
	}
}

//�L�[���v�b�V���������A�L�[�R�[�h�Ŕ��f����
BOOL MY_KEY_PUSH(int KEY_INPUT_)
{
	if (OldAllKeyState[KEY_INPUT_] == 0		//���O�͉����Ă��Ȃ���
		&& AllKeyState[KEY_INPUT_] >= 1)	//���͉����Ă���Ƃ�
	{
		return TRUE;	//�L�[���v�b�V�������i���������Ă��A�P��̂ݔ����j
	}
	else
	{
		return FALSE;	//�L�[���v�b�V�����Ă��Ȃ����A���������Ă���
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


	
	

	return;
}

//���s�֐�
int Kaigyou(VOID)
{
	// �`�����ŏ��ɖ߂�
	DrawPointX = 0;

	DrawPointY++;	// �`��s�ʒu���������

	

	return 0;
}

//���������񏈗��֐�
//�����ŁA�`�悳�������������������Ă���
VOID NovelProc(char str[][STR_COL_MAX])
{
	switch (str[RowPos][ColPos])	//�������P�擾
	{
	case '@':	// ���s����

		// ���s��������юQ�ƕ����ʒu����i�߂�
		Kaigyou();
		ColPos++;	//���̕�����ǂݎ��

		break;

	case 'B':	// �{�^�������҂�����

		//�{�^���������ꂽ��A���̕��͂�
		if (MY_KEY_DOWN(KEY_INPUT_RETURN) == TRUE) { ColPos++; }

		break;

	case 'Q':	// ���╶��

		//�P�{�^���������ꂽ�Ƃ�
		if (MY_KEY_DOWN(KEY_INPUT_1) == TRUE)
		{
			//�ŏ���1����n�܂镶�͂�T��
			for (int i = 0; i < STR_ROW_MAX; i++)
			{
				if (str[i][0] == '1')
				{
					RowPos = i;
					ColPos = 1;
					break;
				}
			}
		}

		//�Q�{�^���������ꂽ�Ƃ�
		if (MY_KEY_DOWN(KEY_INPUT_2) == TRUE)
		{
			//�ŏ���2����n�܂镶�͂�T��
			for (int i = 0; i < STR_ROW_MAX; i++)
			{
				if (str[i][0] == '2')
				{
					RowPos = i;
					ColPos = 1;
					break;
				}
			}
		}

		break;

	case 'X':	// ���₩��߂��Ă��镶��

		//�{�^���������ꂽ��A���̕��͂�
		if (MY_KEY_DOWN(KEY_INPUT_RETURN) == TRUE)
		{
			//�ŏ���X����n�܂镶�͂�T��
			for (int i = 0; i < STR_ROW_MAX; i++)
			{
				if (str[i][0] == 'X')
				{
					RowPos = i;
					ColPos = 1;
					break;
				}
			}
		}

		break;

	case 'E':	// �I������

		// �I���t���O�𗧂Ă邨��юQ�ƕ����ʒu����i�߂�
		EndFlag = TRUE;
		ColPos++;	//���̕�����ǂݎ��

		break;

	case 'C':	// �N���A����

		//�`�悵�Ă��镶�������ɂ���
		for (int i = 0; i < STR_DRAW_ROW_MAX; i++)
		{
			for (int j = 0; j < STR_COL_MAX; j++)
			{
				DrawStringBuf[i][j] = '\0';
			}
		}

		//�����̈ʒu��������
		DrawPointY = 0;
		DrawPointX = 0;
		ColPos++;

		break;

	default:	// ���̑��̕���

		//�`��^�C�~���O���v�Z
		if (DrawSpeedCnt < DrawSpeedCntMax)
		{
			DrawSpeedCnt++;
		}
		else
		{
			// �P�����������o��
			OneMojiBuf[0] = str[RowPos][ColPos];
			OneMojiBuf[1] = str[RowPos][ColPos + 1];
			OneMojiBuf[2] = '\0';

			// ���������������
			strcat(DrawStringBuf[DrawPointY], OneMojiBuf);

			// �Q�ƕ����ʒu���Q�o�C�g�i�߂�
			ColPos += 2;

			// �J�[�\�����ꕶ�����i�߂�
			DrawPointX++;

			// ��ʂ���͂ݏo������s����
			if (DrawPointX * STR_DRAW_SIZE + STR_DRAW_SIZE > rectString.right)
			{
				Kaigyou();
			}

			DrawSpeedCnt = 0;
		}

		break;
	}

	// �Q�ƕ�����̏I�[�܂ōs���Ă�����Q�ƕ������i�߂�
	if (str[RowPos][ColPos] == '\0')
	{
		RowPos++;
		ColPos = 0;
	}

	return;
}

//����������`��֐�
VOID NovelDraw(VOID)
{
	//������`�悷��Ƃ���
	if (EndFlag == FALSE)
	{
		//�������`��
		for (int cnt = 0; cnt <= DrawPointY; cnt++)
		{
			DrawString(0, 200 + cnt * STR_DRAW_SIZE, DrawStringBuf[cnt], GetColor(255, 255, 255));
		}

	}
}

//�v���C���(������)
VOID MY_PLAY_INIT(VOID)
{
	// �`��ʒu�̏����ʒu�Z�b�g
	DrawPointX = 0;
	DrawPointY = 0;

	// �Q�ƕ����ʒu���Z�b�g
	RowPos = 0;	// �P�s�ڂ�
	ColPos = 0;	// �O����

	// �I���t���O��|��
	EndFlag = FALSE;

	//�f�t�H���g�̃t�H���g�T�C�Y���擾
	DefaultFontSize = GetFontSize();

	//���������ɂ���
	OneMojiBuf[0] = '\0';
	OneMojiBuf[1] = '\0';
	OneMojiBuf[2] = '\0';

	for (int i = 0; i < STR_DRAW_ROW_MAX; i++)
	{
		for (int j = 0; j < STR_COL_MAX; j++)
		{
			DrawStringBuf[i][j] = '\0';
		}
	}

	return;
}

//�X�^�[�g��ʂ̕`��
VOID MY_START_DRAW(VOID)
{
	DrawGraph(imageBACK.x, imageBACK.y, imageBACK.handle, TRUE); //�^�C�g���̃o�b�N�C���[�W

	//DrawGraph(400, 500, GameMenu_START.handle, TRUE); //�Q�[�����j���[�̃X�^�[�g�C���[�W
	DrawRotaGraph(
		GameMenu_START.image.x, GameMenu_START.image.y - 50,			//�摜�̍��W
		GameMenu_START.rate,							//�摜�̊g�嗦
		0,											//�摜�̉�]��
		GameMenu_START.image.handle, TRUE);				//�摜�̃n���h��
	//DrawGraph(400, 550, GameMenu_EXIT.handle, TRUE); //�Q�[�����j���[�̏I���C���[�W

	DrawRotaGraph(
		GameMenu_EXIT.image.x + 200, GameMenu_EXIT.image.y - 50,			//�摜�̍��W
		GameMenu_EXIT.rate,						//�摜�̊g�嗦
		0,											//�摜�̉�]��
		GameMenu_EXIT.image.handle, TRUE);				//�摜�̃n���h��

	DrawRotaGraph(
		GameMenu_OPTION.image.x + 100, GameMenu_OPTION.image.y - 50,			//�摜�̍��W
		GameMenu_OPTION.rate,						//�摜�̊g�嗦
		0,											//�摜�̉�]��
		GameMenu_OPTION.image.handle, TRUE);				//�摜�̃n���h��
	
	
	while (true)
	{
		switch (GameMenu)
		{
		case GAME_MENU_START:

			GameMenu_START.rate = 1.2;
			GameMenu_EXIT.rate = 1;
			GameMenu_OPTION.rate = 1;

			if (MY_KEY_PUSH(KEY_INPUT_DOWN) == TRUE)
			{
				GameMenu = GAME_MENU_OPTION;

				if (CheckSoundMem(SERECT.handle) == 0)
				{
					//BGM�̉��ʂ�������
					ChangeVolumeSoundMem(255 * 60 / 100, SERECT.handle);	//60%�̉��ʂɂ���

					PlaySoundMem(SERECT.handle, DX_PLAYTYPE_BACK);
				}
			}

			if (MY_KEY_PUSH(KEY_INPUT_UP) == TRUE)
			{
				GameMenu = GAME_MENU_EXIT;

				if (CheckSoundMem(SERECT.handle) == 0)
				{
					//BGM�̉��ʂ�������
					ChangeVolumeSoundMem(255 * 60 / 100, SERECT.handle);	//60%�̉��ʂɂ���

					PlaySoundMem(SERECT.handle, DX_PLAYTYPE_BACK);
				}
			}

			if (MY_KEY_DOWN(KEY_INPUT_RETURN) == TRUE)
			{
				if (CheckSoundMem(DECISION.handle) == 0)
				{
					//BGM�̉��ʂ�������
					ChangeVolumeSoundMem(255 * 60 / 100, DECISION.handle);	//60%�̉��ʂɂ���

					PlaySoundMem(DECISION.handle, DX_PLAYTYPE_BACK);
				}

				GameScene = GAME_SCENE_SETUMEI;
			}
			break;

		case GAME_MENU_EXIT:

			GameMenu_EXIT.rate = 1.2;
			GameMenu_START.rate = 1;
			GameMenu_OPTION.rate = 1;


			if (MY_KEY_PUSH(KEY_INPUT_DOWN) == TRUE)
			{

				if (CheckSoundMem(SERECT.handle) == 0)
				{

					PlaySoundMem(SERECT.handle, DX_PLAYTYPE_BACK);
				}

				GameMenu = GAME_MENU_START;

				
			}

			if (MY_KEY_PUSH(KEY_INPUT_UP) == TRUE)
			{

				if (CheckSoundMem(SERECT.handle) == 0)
				{
					

					PlaySoundMem(SERECT.handle, DX_PLAYTYPE_BACK);
				}

				GameMenu = GAME_MENU_OPTION;

				
			}

			


			if (MY_KEY_DOWN(KEY_INPUT_RETURN) == TRUE)
			{

				if (CheckSoundMem(DECISION.handle) == 0)
				{
					//BGM�̉��ʂ�������
					ChangeVolumeSoundMem(255 * 60 / 100, DECISION.handle);	//60%�̉��ʂɂ���
					PlaySoundMem(DECISION.handle, DX_PLAYTYPE_BACK);
				}

				DxLib_End();	//�I������

			}
			break;


		case GAME_MENU_OPTION:

			GameMenu_EXIT.rate = 1;
			GameMenu_START.rate = 1;
			GameMenu_OPTION.rate = 1.2;


			if (MY_KEY_PUSH(KEY_INPUT_DOWN) == TRUE )
			{

				if (CheckSoundMem(SERECT.handle) == 0)
				{

					PlaySoundMem(SERECT.handle, DX_PLAYTYPE_BACK);
				}

				GameMenu = GAME_MENU_EXIT;


			}

			if (MY_KEY_PUSH(KEY_INPUT_UP) == TRUE)
			{

				if (CheckSoundMem(SERECT.handle) == 0)
				{
					

					PlaySoundMem(SERECT.handle, DX_PLAYTYPE_BACK);
				}

				GameMenu = GAME_MENU_START;
			}



			if (MY_KEY_DOWN(KEY_INPUT_RETURN) == TRUE)
			{

				if (CheckSoundMem(DECISION.handle) == 0)
				{
						//BGM�̉��ʂ�������
						ChangeVolumeSoundMem(255 * 60 / 100, DECISION.handle);	//60%�̉��ʂɂ���

					

					PlaySoundMem(DECISION.handle, DX_PLAYTYPE_BACK);
				}

				GameScene = GAME_SCENE_OPTION;

			}

			break;



		}

		break;
	}
	
	

	return;
}

VOID MY_OPTION(VOID)
{
	DrawString(0, 0, "�I�v�V������ʁy�J�����z(ESC�L�[�������ăX�^�[�g��ʂɖ߂�܂�)", GetColor(255, 255, 255));
	DrawString(SOUND_VOLUME.image.x - 240, 100, "BGM���ʐݒ�", GetColor(255, 0, 0));
	DrawString(SOUND_EFFECT.image.x , 100, "SE���ʐݒ�", GetColor(255, 0, 0));
	DrawString(SOUND_DECISION.image.x + 240, 100, "���艹���ʐݒ�", GetColor(255, 0, 0));



	//BGM���ʐݒ�
	DrawRotaGraph(
		SOUND_VOLUME.image.x - 200, SOUND_VOLUME.image.y - 100,			//�摜�̍��W
		SOUND_VOLUME.rate,						//�摜�̊g�嗦
		0,											//�摜�̉�]��
		SOUND_VOLUME.image.handle, TRUE);				//�摜�̃n���h��

	DrawRotaGraph(
		SOUND_VOLUME1.image.x - 200, SOUND_VOLUME1.image.y - 50,			//�摜�̍��W
		SOUND_VOLUME1.rate,						//�摜�̊g�嗦
		0,											//�摜�̉�]��
		SOUND_VOLUME1.image.handle, TRUE);				//�摜�̃n���h��

	DrawRotaGraph(
		SOUND_VOLUME2.image.x - 200, SOUND_VOLUME2.image.y ,			//�摜�̍��W
		SOUND_VOLUME2.rate,						//�摜�̊g�嗦
		0,											//�摜�̉�]��
		SOUND_VOLUME2.image.handle, TRUE);				//�摜�̃n���h��

	DrawRotaGraph(
		SOUND_VOLUME3.image.x - 200, SOUND_VOLUME3.image.y + 50,			//�摜�̍��W
		SOUND_VOLUME3.rate,						//�摜�̊g�嗦
		0,											//�摜�̉�]��
		SOUND_VOLUME3.image.handle, TRUE);				//�摜�̃n���h��

	DrawRotaGraph(
		SOUND_VOLUME4.image.x - 200, SOUND_VOLUME4.image.y + 100,			//�摜�̍��W
		SOUND_VOLUME4.rate,						//�摜�̊g�嗦
		0,											//�摜�̉�]��
		SOUND_VOLUME4.image.handle, TRUE);				//�摜�̃n���h��

	//�����܂ł�BGM���ʐݒ�

	//����������ʉ����ʐݒ�

	DrawRotaGraph(
		SOUND_EFFECT.image.x  + 50, SOUND_EFFECT.image.y - 100,			//�摜�̍��W
		SOUND_EFFECT.rate,						//�摜�̊g�嗦
		0,											//�摜�̉�]��
		SOUND_EFFECT.image.handle, TRUE);				//�摜�̃n���h��

	DrawRotaGraph(
		SOUND_EFFECT1.image.x + 50, SOUND_EFFECT1.image.y - 50,			//�摜�̍��W
		SOUND_EFFECT1.rate,						//�摜�̊g�嗦
		0,											//�摜�̉�]��
		SOUND_EFFECT1.image.handle, TRUE);				//�摜�̃n���h��

	DrawRotaGraph(
		SOUND_EFFECT2.image.x + 50, SOUND_EFFECT2.image.y,			//�摜�̍��W
		SOUND_EFFECT2.rate,						//�摜�̊g�嗦
		0,											//�摜�̉�]��
		SOUND_EFFECT2.image.handle, TRUE);				//�摜�̃n���h��

	DrawRotaGraph(
		SOUND_EFFECT3.image.x + 50, SOUND_EFFECT3.image.y + 50,			//�摜�̍��W
		SOUND_EFFECT3.rate,						//�摜�̊g�嗦
		0,											//�摜�̉�]��
		SOUND_EFFECT3.image.handle, TRUE);				//�摜�̃n���h��

	DrawRotaGraph(
		SOUND_EFFECT4.image.x + 50, SOUND_EFFECT4.image.y + 100,			//�摜�̍��W
		SOUND_EFFECT4.rate,						//�摜�̊g�嗦
		0,											//�摜�̉�]��
		SOUND_EFFECT4.image.handle, TRUE);				//�摜�̃n���h��

	//�����܂Ō��ʉ��{�^��

	//�������猈��{�^��

	DrawRotaGraph(
		SOUND_DECISION.image.x + 300, SOUND_DECISION.image.y - 100,			//�摜�̍��W
		SOUND_DECISION.rate,						//�摜�̊g�嗦
		0,											//�摜�̉�]��
		SOUND_DECISION.image.handle, TRUE);				//�摜�̃n���h��

	DrawRotaGraph(
		SOUND_DECISION1.image.x + 300, SOUND_DECISION1.image.y - 50,			//�摜�̍��W
		SOUND_DECISION1.rate,						//�摜�̊g�嗦
		0,											//�摜�̉�]��
		SOUND_DECISION1.image.handle, TRUE);				//�摜�̃n���h��

	DrawRotaGraph(
		SOUND_DECISION2.image.x + 300, SOUND_DECISION2.image.y,			//�摜�̍��W
		SOUND_DECISION2.rate,						//�摜�̊g�嗦
		0,											//�摜�̉�]��
		SOUND_DECISION2.image.handle, TRUE);				//�摜�̃n���h��

	DrawRotaGraph(
		SOUND_DECISION3.image.x + 300, SOUND_DECISION3.image.y + 50,			//�摜�̍��W
		SOUND_DECISION3.rate,						//�摜�̊g�嗦
		0,											//�摜�̉�]��
		SOUND_DECISION3.image.handle, TRUE);				//�摜�̃n���h��

	DrawRotaGraph(
		SOUND_DECISION4.image.x + 300, SOUND_DECISION4.image.y + 100,			//�摜�̍��W
		SOUND_DECISION4.rate,						//�摜�̊g�嗦
		0,											//�摜�̉�]��
		SOUND_DECISION4.image.handle, TRUE);				//�摜�̃n���h��




	while (true)
	{
		
		switch (OptionMenu)
		{
			case VOLUME0:
				SOUND_VOLUME.rate = 1.2;
				SOUND_VOLUME1.rate = 1;
				SOUND_VOLUME2.rate = 1;
				SOUND_VOLUME3.rate = 1;
				SOUND_VOLUME4.rate = 1;
				SOUND_EFFECT.rate = 1;
				SOUND_EFFECT1.rate = 1;
				SOUND_EFFECT2.rate = 1;
				SOUND_EFFECT3.rate = 1;
				SOUND_EFFECT4.rate = 1;
				SOUND_DECISION.rate = 1;
				SOUND_DECISION1.rate = 1;
				SOUND_DECISION2.rate = 1;
				SOUND_DECISION3.rate = 1;
				SOUND_DECISION4.rate = 1;
				



				if (MY_KEY_DOWN(KEY_INPUT_RETURN) == TRUE)
				{
					if (CheckSoundMem(DECISION.handle) == 0)
					{
					
						PlaySoundMem(DECISION.handle, DX_PLAYTYPE_BACK);
					}

					// ���ʂ̐ݒ�
					ChangeVolumeSoundMem(255 * 0 / 100, BGM.handle);
					ChangeVolumeSoundMem(255 * 0 / 100, SYBERB.handle);


				}

				if (MY_KEY_PUSH(KEY_INPUT_DOWN) == TRUE)
				{
					if (CheckSoundMem(SERECT.handle) == 0)
					{
						

						PlaySoundMem(SERECT.handle, DX_PLAYTYPE_BACK);
					}

					OptionMenu = VOLUME25;
				}

				if (MY_KEY_PUSH(KEY_INPUT_UP) == TRUE)
				{

					if (CheckSoundMem(SERECT.handle) == 0)
					{
						

						PlaySoundMem(SERECT.handle, DX_PLAYTYPE_BACK);
					}

					OptionMenu = VOLUME100;
				}

				if (MY_KEY_PUSH(KEY_INPUT_LEFT) == TRUE)
				{
					if (CheckSoundMem(SERECT.handle) == 0)
					{
						PlaySoundMem(SERECT.handle, DX_PLAYTYPE_BACK);
					}

					OptionMenu = DECISION0;

				}

				if (MY_KEY_PUSH(KEY_INPUT_RIGHT) == TRUE)
				{
					if (CheckSoundMem(SERECT.handle) == 0)
					{
						PlaySoundMem(SERECT.handle, DX_PLAYTYPE_BACK);
					}

					OptionMenu = EFFECT0;

				}



				break;



			case VOLUME25:
				SOUND_VOLUME.rate = 1;
				SOUND_VOLUME1.rate = 1.2;
				SOUND_VOLUME2.rate = 1;
				SOUND_VOLUME3.rate = 1;
				SOUND_VOLUME4.rate = 1;
				SOUND_EFFECT.rate = 1;
				SOUND_EFFECT1.rate = 1;
				SOUND_EFFECT2.rate = 1;
				SOUND_EFFECT3.rate = 1;
				SOUND_EFFECT4.rate = 1;
				SOUND_DECISION.rate = 1;
				SOUND_DECISION1.rate = 1;
				SOUND_DECISION2.rate = 1;
				SOUND_DECISION3.rate = 1;
				SOUND_DECISION4.rate = 1;


				if (MY_KEY_DOWN(KEY_INPUT_RETURN) == TRUE)
				{
					if (CheckSoundMem(DECISION.handle) == 0)
					{

						PlaySoundMem(DECISION.handle, DX_PLAYTYPE_BACK);
					}

					// ���ʂ̐ݒ�
					ChangeVolumeSoundMem(255 * 25 / 100, BGM.handle);
					ChangeVolumeSoundMem(255 * 25 / 100, SYBERB.handle);

				}

				if (MY_KEY_PUSH(KEY_INPUT_DOWN) == TRUE)
				{
					if (CheckSoundMem(SERECT.handle) == 0)
					{
						

						PlaySoundMem(SERECT.handle, DX_PLAYTYPE_BACK);
					}

					OptionMenu = VOLUME50;
				}

				if (MY_KEY_PUSH(KEY_INPUT_UP) == TRUE)
				{

					if (CheckSoundMem(SERECT.handle) == 0)
					{
						

						PlaySoundMem(SERECT.handle, DX_PLAYTYPE_BACK);
					}

					OptionMenu = VOLUME0;
				}

				if (MY_KEY_PUSH(KEY_INPUT_LEFT) == TRUE)
				{
					if (CheckSoundMem(SERECT.handle) == 0)
					{
						PlaySoundMem(SERECT.handle, DX_PLAYTYPE_BACK);
					}

					OptionMenu = DECISION25;

				}

				if (MY_KEY_PUSH(KEY_INPUT_RIGHT) == TRUE)
				{
					if (CheckSoundMem(SERECT.handle) == 0)
					{
						PlaySoundMem(SERECT.handle, DX_PLAYTYPE_BACK);
					}

					OptionMenu = EFFECT25;

				}

				break;

			case VOLUME50:
				SOUND_VOLUME.rate = 1;
				SOUND_VOLUME1.rate = 1;
				SOUND_VOLUME2.rate = 1.2;
				SOUND_VOLUME3.rate = 1;
				SOUND_VOLUME4.rate = 1;
				SOUND_EFFECT.rate = 1;
				SOUND_EFFECT1.rate = 1;
				SOUND_EFFECT2.rate = 1;
				SOUND_EFFECT3.rate = 1;
				SOUND_EFFECT4.rate = 1;
				SOUND_DECISION.rate = 1;
				SOUND_DECISION1.rate = 1;
				SOUND_DECISION2.rate = 1;
				SOUND_DECISION3.rate = 1;
				SOUND_DECISION4.rate = 1;


				if (MY_KEY_DOWN(KEY_INPUT_RETURN) == TRUE)
				{

					if (CheckSoundMem(DECISION.handle) == 0)
					{

						PlaySoundMem(DECISION.handle, DX_PLAYTYPE_BACK);
					}


					// ���ʂ̐ݒ�
					ChangeVolumeSoundMem(255 * 50 / 100, BGM.handle);
					ChangeVolumeSoundMem(255 * 50 / 100, SYBERB.handle);

				}

				if (MY_KEY_PUSH(KEY_INPUT_DOWN) == TRUE)
				{

					if (CheckSoundMem(SERECT.handle) == 0)
					{

						PlaySoundMem(SERECT.handle, DX_PLAYTYPE_BACK);
					}

					OptionMenu = VOLUME75;
				}

				if (MY_KEY_PUSH(KEY_INPUT_UP) == TRUE)
				{

					if (CheckSoundMem(SERECT.handle) == 0)
					{
						

						PlaySoundMem(SERECT.handle, DX_PLAYTYPE_BACK);
					}

					OptionMenu = VOLUME25;
				}

				if (MY_KEY_PUSH(KEY_INPUT_LEFT) == TRUE)
				{
					if (CheckSoundMem(SERECT.handle) == 0)
					{
						PlaySoundMem(SERECT.handle, DX_PLAYTYPE_BACK);
					}

					OptionMenu = DECISION50;

				}

				if (MY_KEY_PUSH(KEY_INPUT_RIGHT) == TRUE)
				{
					if (CheckSoundMem(SERECT.handle) == 0)
					{
						PlaySoundMem(SERECT.handle, DX_PLAYTYPE_BACK);
					}

					OptionMenu = EFFECT50;

				}



				break;

			case VOLUME75:
				SOUND_VOLUME.rate = 1;
				SOUND_VOLUME1.rate = 1;
				SOUND_VOLUME2.rate = 1;
				SOUND_VOLUME3.rate = 1.2;
				SOUND_VOLUME4.rate = 1;
				SOUND_EFFECT.rate = 1;
				SOUND_EFFECT1.rate = 1;
				SOUND_EFFECT2.rate = 1;
				SOUND_EFFECT3.rate = 1;
				SOUND_EFFECT4.rate = 1;
				SOUND_DECISION.rate = 1;
				SOUND_DECISION1.rate = 1;
				SOUND_DECISION2.rate = 1;
				SOUND_DECISION3.rate = 1;
				SOUND_DECISION4.rate = 1;


				if (MY_KEY_DOWN(KEY_INPUT_RETURN) == TRUE)
				{

					if (CheckSoundMem(DECISION.handle) == 0)
					{

						PlaySoundMem(DECISION.handle, DX_PLAYTYPE_BACK);
					}


					// ���ʂ̐ݒ�
					ChangeVolumeSoundMem(255 * 75 / 100, BGM.handle);
					ChangeVolumeSoundMem(255 * 75 / 100, SYBERB.handle);

				}

				if (MY_KEY_PUSH(KEY_INPUT_DOWN) == TRUE)
				{

					if (CheckSoundMem(SERECT.handle) == 0)
					{
						

						PlaySoundMem(SERECT.handle, DX_PLAYTYPE_BACK);
					}

					OptionMenu = VOLUME100;
				}

				if (MY_KEY_PUSH(KEY_INPUT_UP) == TRUE)
				{

					if (CheckSoundMem(SERECT.handle) == 0)
					{
						

						PlaySoundMem(SERECT.handle, DX_PLAYTYPE_BACK);
					}

					OptionMenu = VOLUME50;
				}

				if (MY_KEY_PUSH(KEY_INPUT_LEFT) == TRUE)
				{
					if (CheckSoundMem(SERECT.handle) == 0)
					{
						PlaySoundMem(SERECT.handle, DX_PLAYTYPE_BACK);
					}

					OptionMenu = DECISION75;

				}

				if (MY_KEY_PUSH(KEY_INPUT_RIGHT) == TRUE)
				{
					if (CheckSoundMem(SERECT.handle) == 0)
					{
						PlaySoundMem(SERECT.handle, DX_PLAYTYPE_BACK);
					}

					OptionMenu = EFFECT75;

				}

				break;

			case VOLUME100:
				SOUND_VOLUME.rate = 1;
				SOUND_VOLUME1.rate = 1;
				SOUND_VOLUME2.rate = 1;
				SOUND_VOLUME3.rate = 1;
				SOUND_VOLUME4.rate = 1.2;
				SOUND_EFFECT.rate = 1;
				SOUND_EFFECT1.rate = 1;
				SOUND_EFFECT2.rate = 1;
				SOUND_EFFECT3.rate = 1;
				SOUND_EFFECT4.rate = 1;
				SOUND_DECISION.rate = 1;
				SOUND_DECISION1.rate = 1;
				SOUND_DECISION2.rate = 1;
				SOUND_DECISION3.rate = 1;
				SOUND_DECISION4.rate = 1;


				if (MY_KEY_DOWN(KEY_INPUT_RETURN) == TRUE)
				{

					if (CheckSoundMem(DECISION.handle) == 0)
					{

						PlaySoundMem(DECISION.handle, DX_PLAYTYPE_BACK);
					}


					// ���ʂ̐ݒ�
					ChangeVolumeSoundMem(255 * 100 / 100, BGM.handle);
					ChangeVolumeSoundMem(255 * 100 / 100, SYBERB.handle);

				}

				if (MY_KEY_PUSH(KEY_INPUT_DOWN) == TRUE)
				{

					if (CheckSoundMem(SERECT.handle) == 0)
					{
						

						PlaySoundMem(SERECT.handle, DX_PLAYTYPE_BACK);
					}

					OptionMenu = VOLUME0;
				}

				if (MY_KEY_PUSH(KEY_INPUT_UP) == TRUE)
				{

					if (CheckSoundMem(SERECT.handle) == 0)
					{

						PlaySoundMem(SERECT.handle, DX_PLAYTYPE_BACK);
					}

					OptionMenu = VOLUME75;
				}

				if (MY_KEY_PUSH(KEY_INPUT_LEFT) == TRUE)
				{
					if (CheckSoundMem(SERECT.handle) == 0)
					{
						PlaySoundMem(SERECT.handle, DX_PLAYTYPE_BACK);
					}

					OptionMenu = DECISION100;

				}

				if (MY_KEY_PUSH(KEY_INPUT_RIGHT) == TRUE)
				{
					if (CheckSoundMem(SERECT.handle) == 0)
					{
						PlaySoundMem(SERECT.handle, DX_PLAYTYPE_BACK);
					}

					OptionMenu = EFFECT100;

				}

				break;

			case EFFECT0:
				SOUND_VOLUME.rate = 1;
				SOUND_VOLUME1.rate = 1;
				SOUND_VOLUME2.rate = 1;
				SOUND_VOLUME3.rate = 1;
				SOUND_VOLUME4.rate = 1;
				SOUND_EFFECT.rate = 1.2;
				SOUND_EFFECT1.rate = 1;
				SOUND_EFFECT2.rate = 1;
				SOUND_EFFECT3.rate = 1;
				SOUND_EFFECT4.rate = 1;
				SOUND_DECISION.rate = 1;
				SOUND_DECISION1.rate = 1;
				SOUND_DECISION2.rate = 1;
				SOUND_DECISION3.rate = 1;
				SOUND_DECISION4.rate = 1;


				if (MY_KEY_DOWN(KEY_INPUT_RETURN) == TRUE)
				{

					if (CheckSoundMem(DECISION.handle) == 0)
					{

						PlaySoundMem(DECISION.handle, DX_PLAYTYPE_BACK);
					}


					// ���ʂ̐ݒ�
					ChangeVolumeSoundMem(255 * 0 / 100, SERECT.handle);

				}

				if (MY_KEY_PUSH(KEY_INPUT_DOWN) == TRUE)
				{

					if (CheckSoundMem(SERECT.handle) == 0)
					{


						PlaySoundMem(SERECT.handle, DX_PLAYTYPE_BACK);
					}

					OptionMenu = EFFECT25;
				}

				if (MY_KEY_PUSH(KEY_INPUT_UP) == TRUE)
				{

					if (CheckSoundMem(SERECT.handle) == 0)
					{

						PlaySoundMem(SERECT.handle, DX_PLAYTYPE_BACK);
					}

					OptionMenu = EFFECT100;
				}

				if (MY_KEY_PUSH(KEY_INPUT_LEFT) == TRUE)
				{
					if (CheckSoundMem(SERECT.handle) == 0)
					{
						PlaySoundMem(SERECT.handle, DX_PLAYTYPE_BACK);
					}

					OptionMenu = VOLUME0;

				}

				if (MY_KEY_PUSH(KEY_INPUT_RIGHT) == TRUE)
				{
					if (CheckSoundMem(SERECT.handle) == 0)
					{
						PlaySoundMem(SERECT.handle, DX_PLAYTYPE_BACK);
					}

					OptionMenu = DECISION0;

				}

				break;

			case EFFECT25:
				SOUND_VOLUME.rate = 1;
				SOUND_VOLUME1.rate = 1;
				SOUND_VOLUME2.rate = 1;
				SOUND_VOLUME3.rate = 1;
				SOUND_VOLUME4.rate = 1;
				SOUND_EFFECT.rate = 1;
				SOUND_EFFECT1.rate = 1.2;
				SOUND_EFFECT2.rate = 1;
				SOUND_EFFECT3.rate = 1;
				SOUND_EFFECT4.rate = 1;
				SOUND_DECISION.rate = 1;
				SOUND_DECISION1.rate = 1;
				SOUND_DECISION2.rate = 1;
				SOUND_DECISION3.rate = 1;
				SOUND_DECISION4.rate = 1;


				if (MY_KEY_DOWN(KEY_INPUT_RETURN) == TRUE)
				{

					if (CheckSoundMem(DECISION.handle) == 0)
					{

						PlaySoundMem(DECISION.handle, DX_PLAYTYPE_BACK);
					}


					// ���ʂ̐ݒ�
					ChangeVolumeSoundMem(255 * 25 / 100, SERECT.handle);

				}

				if (MY_KEY_PUSH(KEY_INPUT_DOWN) == TRUE)
				{

					if (CheckSoundMem(SERECT.handle) == 0)
					{


						PlaySoundMem(SERECT.handle, DX_PLAYTYPE_BACK);
					}

					OptionMenu = EFFECT50;
				}

				if (MY_KEY_PUSH(KEY_INPUT_UP) == TRUE)
				{

					if (CheckSoundMem(SERECT.handle) == 0)
					{

						PlaySoundMem(SERECT.handle, DX_PLAYTYPE_BACK);
					}

					OptionMenu = EFFECT0;
				}

				if (MY_KEY_PUSH(KEY_INPUT_LEFT) == TRUE)
				{
					if (CheckSoundMem(SERECT.handle) == 0)
					{
						PlaySoundMem(SERECT.handle, DX_PLAYTYPE_BACK);
					}

					OptionMenu = VOLUME25;

				}

				if (MY_KEY_PUSH(KEY_INPUT_RIGHT) == TRUE)
				{
					if (CheckSoundMem(SERECT.handle) == 0)
					{
						PlaySoundMem(SERECT.handle, DX_PLAYTYPE_BACK);
					}

					OptionMenu = DECISION25;

				}

				break;

			case EFFECT50:
				SOUND_VOLUME.rate = 1;
				SOUND_VOLUME1.rate = 1;
				SOUND_VOLUME2.rate = 1;
				SOUND_VOLUME3.rate = 1;
				SOUND_VOLUME4.rate = 1;
				SOUND_EFFECT.rate = 1;
				SOUND_EFFECT1.rate = 1;
				SOUND_EFFECT2.rate = 1.2;
				SOUND_EFFECT3.rate = 1;
				SOUND_EFFECT4.rate = 1;
				SOUND_DECISION.rate = 1;
				SOUND_DECISION1.rate = 1;
				SOUND_DECISION2.rate = 1;
				SOUND_DECISION3.rate = 1;
				SOUND_DECISION4.rate = 1;


				if (MY_KEY_DOWN(KEY_INPUT_RETURN) == TRUE)
				{

					if (CheckSoundMem(DECISION.handle) == 0)
					{

						PlaySoundMem(DECISION.handle, DX_PLAYTYPE_BACK);
					}


					// ���ʂ̐ݒ�
					ChangeVolumeSoundMem(255 * 50 / 100, SERECT.handle);

				}

				if (MY_KEY_PUSH(KEY_INPUT_DOWN) == TRUE)
				{

					if (CheckSoundMem(SERECT.handle) == 0)
					{


						PlaySoundMem(SERECT.handle, DX_PLAYTYPE_BACK);
					}

					OptionMenu = EFFECT75;
				}

				if (MY_KEY_PUSH(KEY_INPUT_UP) == TRUE)
				{

					if (CheckSoundMem(SERECT.handle) == 0)
					{

						PlaySoundMem(SERECT.handle, DX_PLAYTYPE_BACK);
					}

					OptionMenu = EFFECT25;
				}

				if (MY_KEY_PUSH(KEY_INPUT_LEFT) == TRUE)
				{
					if (CheckSoundMem(SERECT.handle) == 0)
					{
						PlaySoundMem(SERECT.handle, DX_PLAYTYPE_BACK);
					}

					OptionMenu = VOLUME50;

				}

				if (MY_KEY_PUSH(KEY_INPUT_RIGHT) == TRUE)
				{
					if (CheckSoundMem(SERECT.handle) == 0)
					{
						PlaySoundMem(SERECT.handle, DX_PLAYTYPE_BACK);
					}

					OptionMenu = DECISION50;

				}

				break;

			case EFFECT75:
				SOUND_VOLUME.rate = 1;
				SOUND_VOLUME1.rate = 1;
				SOUND_VOLUME2.rate = 1;
				SOUND_VOLUME3.rate = 1;
				SOUND_VOLUME4.rate = 1;
				SOUND_EFFECT.rate = 1;
				SOUND_EFFECT1.rate = 1;
				SOUND_EFFECT2.rate = 1;
				SOUND_EFFECT3.rate = 1.2;
				SOUND_EFFECT4.rate = 1;
				SOUND_DECISION.rate = 1;
				SOUND_DECISION1.rate = 1;
				SOUND_DECISION2.rate = 1;
				SOUND_DECISION3.rate = 1;
				SOUND_DECISION4.rate = 1;


				if (MY_KEY_DOWN(KEY_INPUT_RETURN) == TRUE)
				{

					if (CheckSoundMem(DECISION.handle) == 0)
					{

						PlaySoundMem(DECISION.handle, DX_PLAYTYPE_BACK);
					}


					// ���ʂ̐ݒ�
					ChangeVolumeSoundMem(255 * 75 / 100, SERECT.handle);

				}

				if (MY_KEY_PUSH(KEY_INPUT_DOWN) == TRUE)
				{

					if (CheckSoundMem(SERECT.handle) == 0)
					{


						PlaySoundMem(SERECT.handle, DX_PLAYTYPE_BACK);
					}

					OptionMenu = EFFECT100;
				}

				if (MY_KEY_PUSH(KEY_INPUT_UP) == TRUE)
				{

					if (CheckSoundMem(SERECT.handle) == 0)
					{

						PlaySoundMem(SERECT.handle, DX_PLAYTYPE_BACK);
					}

					OptionMenu = EFFECT50;
				}

				if (MY_KEY_PUSH(KEY_INPUT_LEFT) == TRUE)
				{
					if (CheckSoundMem(SERECT.handle) == 0)
					{
						PlaySoundMem(SERECT.handle, DX_PLAYTYPE_BACK);
					}

					OptionMenu = VOLUME75;

				}

				if (MY_KEY_PUSH(KEY_INPUT_RIGHT) == TRUE)
				{
					if (CheckSoundMem(SERECT.handle) == 0)
					{
						PlaySoundMem(SERECT.handle, DX_PLAYTYPE_BACK);
					}

					OptionMenu = DECISION75;

				}
			break;

			case EFFECT100:
				SOUND_VOLUME.rate = 1;
				SOUND_VOLUME1.rate = 1;
				SOUND_VOLUME2.rate = 1;
				SOUND_VOLUME3.rate = 1;
				SOUND_VOLUME4.rate = 1;
				SOUND_EFFECT.rate = 1;
				SOUND_EFFECT1.rate = 1;
				SOUND_EFFECT2.rate = 1;
				SOUND_EFFECT3.rate = 1;
				SOUND_EFFECT4.rate = 1.2;
				SOUND_DECISION.rate = 1;
				SOUND_DECISION1.rate = 1;
				SOUND_DECISION2.rate = 1;
				SOUND_DECISION3.rate = 1;
				SOUND_DECISION4.rate = 1;


				if (MY_KEY_DOWN(KEY_INPUT_RETURN) == TRUE)
				{

					if (CheckSoundMem(DECISION.handle) == 0)
					{

						PlaySoundMem(DECISION.handle, DX_PLAYTYPE_BACK);
					}


					// ���ʂ̐ݒ�
					ChangeVolumeSoundMem(255 * 100 / 100, SERECT.handle);

				}

				if (MY_KEY_PUSH(KEY_INPUT_DOWN) == TRUE)
				{

					if (CheckSoundMem(SERECT.handle) == 0)
					{


						PlaySoundMem(SERECT.handle, DX_PLAYTYPE_BACK);
					}

					OptionMenu = EFFECT0;
				}

				if (MY_KEY_PUSH(KEY_INPUT_UP) == TRUE)
				{

					if (CheckSoundMem(SERECT.handle) == 0)
					{

						PlaySoundMem(SERECT.handle, DX_PLAYTYPE_BACK);
					}

					OptionMenu = EFFECT75;
				}

				if (MY_KEY_PUSH(KEY_INPUT_LEFT) == TRUE)
				{
					if (CheckSoundMem(SERECT.handle) == 0)
					{
						PlaySoundMem(SERECT.handle, DX_PLAYTYPE_BACK);
					}

					OptionMenu = VOLUME100;

				}

				if (MY_KEY_PUSH(KEY_INPUT_RIGHT) == TRUE)
				{
					if (CheckSoundMem(SERECT.handle) == 0)
					{
						PlaySoundMem(SERECT.handle, DX_PLAYTYPE_BACK);
					}

					OptionMenu = DECISION100;

				}

				break;

			case DECISION0:
				SOUND_VOLUME.rate = 1;
				SOUND_VOLUME1.rate = 1;
				SOUND_VOLUME2.rate = 1;
				SOUND_VOLUME3.rate = 1;
				SOUND_VOLUME4.rate = 1;
				SOUND_EFFECT.rate = 1;
				SOUND_EFFECT1.rate = 1;
				SOUND_EFFECT2.rate = 1;
				SOUND_EFFECT3.rate = 1;
				SOUND_EFFECT4.rate = 1;
				SOUND_DECISION.rate = 1.2;
				SOUND_DECISION1.rate = 1;
				SOUND_DECISION2.rate = 1;
				SOUND_DECISION3.rate = 1;
				SOUND_DECISION4.rate = 1;


				if (MY_KEY_DOWN(KEY_INPUT_RETURN) == TRUE)
				{

					if (CheckSoundMem(DECISION.handle) == 0)
					{

						PlaySoundMem(DECISION.handle, DX_PLAYTYPE_BACK);
					}


					// ���ʂ̐ݒ�
					ChangeVolumeSoundMem(255 * 0 / 100, DECISION.handle);

				}

				if (MY_KEY_PUSH(KEY_INPUT_DOWN) == TRUE)
				{

					if (CheckSoundMem(SERECT.handle) == 0)
					{


						PlaySoundMem(SERECT.handle, DX_PLAYTYPE_BACK);
					}

					OptionMenu = DECISION25;
				}

				if (MY_KEY_PUSH(KEY_INPUT_UP) == TRUE)
				{

					if (CheckSoundMem(SERECT.handle) == 0)
					{

						PlaySoundMem(SERECT.handle, DX_PLAYTYPE_BACK);
					}

					OptionMenu = DECISION100;
				}

				if (MY_KEY_PUSH(KEY_INPUT_LEFT) == TRUE)
				{
					if (CheckSoundMem(SERECT.handle) == 0)
					{
						PlaySoundMem(SERECT.handle, DX_PLAYTYPE_BACK);
					}

					OptionMenu = EFFECT0;

				}

				if (MY_KEY_PUSH(KEY_INPUT_RIGHT) == TRUE)
				{
					if (CheckSoundMem(SERECT.handle) == 0)
					{
						PlaySoundMem(SERECT.handle, DX_PLAYTYPE_BACK);
					}

					OptionMenu = VOLUME0;

				}

				break;

			case DECISION25:
				SOUND_VOLUME.rate = 1;
				SOUND_VOLUME1.rate = 1;
				SOUND_VOLUME2.rate = 1;
				SOUND_VOLUME3.rate = 1;
				SOUND_VOLUME4.rate = 1;
				SOUND_EFFECT.rate = 1;
				SOUND_EFFECT1.rate = 1;
				SOUND_EFFECT2.rate = 1;
				SOUND_EFFECT3.rate = 1;
				SOUND_EFFECT4.rate = 1;
				SOUND_DECISION.rate = 1;
				SOUND_DECISION1.rate = 1.2;
				SOUND_DECISION2.rate = 1;
				SOUND_DECISION3.rate = 1;
				SOUND_DECISION4.rate = 1;


				if (MY_KEY_DOWN(KEY_INPUT_RETURN) == TRUE)
				{

					if (CheckSoundMem(DECISION.handle) == 0)
					{

						PlaySoundMem(DECISION.handle, DX_PLAYTYPE_BACK);
					}


					// ���ʂ̐ݒ�
					ChangeVolumeSoundMem(255 * 25 / 100, DECISION.handle);

				}

				if (MY_KEY_PUSH(KEY_INPUT_DOWN) == TRUE)
				{

					if (CheckSoundMem(SERECT.handle) == 0)
					{


						PlaySoundMem(SERECT.handle, DX_PLAYTYPE_BACK);
					}

					OptionMenu = DECISION50;
				}

				if (MY_KEY_PUSH(KEY_INPUT_UP) == TRUE)
				{

					if (CheckSoundMem(SERECT.handle) == 0)
					{

						PlaySoundMem(SERECT.handle, DX_PLAYTYPE_BACK);
					}

					OptionMenu = DECISION0;
				}

				if (MY_KEY_PUSH(KEY_INPUT_LEFT) == TRUE)
				{
					if (CheckSoundMem(SERECT.handle) == 0)
					{
						PlaySoundMem(SERECT.handle, DX_PLAYTYPE_BACK);
					}

					OptionMenu = EFFECT25;

				}

				if (MY_KEY_PUSH(KEY_INPUT_RIGHT) == TRUE)
				{
					if (CheckSoundMem(SERECT.handle) == 0)
					{
						PlaySoundMem(SERECT.handle, DX_PLAYTYPE_BACK);
					}

					OptionMenu = VOLUME25;

				}

				break;

			case DECISION50:
				SOUND_VOLUME.rate = 1;
				SOUND_VOLUME1.rate = 1;
				SOUND_VOLUME2.rate = 1;
				SOUND_VOLUME3.rate = 1;
				SOUND_VOLUME4.rate = 1;
				SOUND_EFFECT.rate = 1;
				SOUND_EFFECT1.rate = 1;
				SOUND_EFFECT2.rate = 1;
				SOUND_EFFECT3.rate = 1;
				SOUND_EFFECT4.rate = 1;
				SOUND_DECISION.rate = 1;
				SOUND_DECISION1.rate = 1;
				SOUND_DECISION2.rate = 1.2;
				SOUND_DECISION3.rate = 1;
				SOUND_DECISION4.rate = 1;


				if (MY_KEY_DOWN(KEY_INPUT_RETURN) == TRUE)
				{

					if (CheckSoundMem(DECISION.handle) == 0)
					{

						PlaySoundMem(DECISION.handle, DX_PLAYTYPE_BACK);
					}


					// ���ʂ̐ݒ�
					ChangeVolumeSoundMem(255 * 50 / 100, DECISION.handle);

				}

				if (MY_KEY_PUSH(KEY_INPUT_DOWN) == TRUE)
				{

					if (CheckSoundMem(SERECT.handle) == 0)
					{


						PlaySoundMem(SERECT.handle, DX_PLAYTYPE_BACK);
					}

					OptionMenu = DECISION75;
				}

				if (MY_KEY_PUSH(KEY_INPUT_UP) == TRUE)
				{

					if (CheckSoundMem(SERECT.handle) == 0)
					{

						PlaySoundMem(SERECT.handle, DX_PLAYTYPE_BACK);
					}

					OptionMenu = DECISION25;
				}

				if (MY_KEY_PUSH(KEY_INPUT_LEFT) == TRUE)
				{
					if (CheckSoundMem(SERECT.handle) == 0)
					{
						PlaySoundMem(SERECT.handle, DX_PLAYTYPE_BACK);
					}

					OptionMenu = EFFECT50;

				}

				if (MY_KEY_PUSH(KEY_INPUT_RIGHT) == TRUE)
				{
					if (CheckSoundMem(SERECT.handle) == 0)
					{
						PlaySoundMem(SERECT.handle, DX_PLAYTYPE_BACK);
					}

					OptionMenu = VOLUME50;

				}

				break;

			case DECISION75:
				SOUND_VOLUME.rate = 1;
				SOUND_VOLUME1.rate = 1;
				SOUND_VOLUME2.rate = 1;
				SOUND_VOLUME3.rate = 1;
				SOUND_VOLUME4.rate = 1;
				SOUND_EFFECT.rate = 1;
				SOUND_EFFECT1.rate = 1;
				SOUND_EFFECT2.rate = 1;
				SOUND_EFFECT3.rate = 1;
				SOUND_EFFECT4.rate = 1;
				SOUND_DECISION.rate = 1;
				SOUND_DECISION1.rate = 1;
				SOUND_DECISION2.rate = 1;
				SOUND_DECISION3.rate = 1.2;
				SOUND_DECISION4.rate = 1;


				if (MY_KEY_DOWN(KEY_INPUT_RETURN) == TRUE)
				{

					if (CheckSoundMem(DECISION.handle) == 0)
					{

						PlaySoundMem(DECISION.handle, DX_PLAYTYPE_BACK);
					}


					// ���ʂ̐ݒ�
					ChangeVolumeSoundMem(255 * 75 / 100, DECISION.handle);

				}

				if (MY_KEY_PUSH(KEY_INPUT_DOWN) == TRUE)
				{

					if (CheckSoundMem(SERECT.handle) == 0)
					{


						PlaySoundMem(SERECT.handle, DX_PLAYTYPE_BACK);
					}

					OptionMenu = DECISION100;
				}

				if (MY_KEY_PUSH(KEY_INPUT_UP) == TRUE)
				{

					if (CheckSoundMem(SERECT.handle) == 0)
					{

						PlaySoundMem(SERECT.handle, DX_PLAYTYPE_BACK);
					}

					OptionMenu = DECISION50;
				}

				if (MY_KEY_PUSH(KEY_INPUT_LEFT) == TRUE)
				{
					if (CheckSoundMem(SERECT.handle) == 0)
					{
						PlaySoundMem(SERECT.handle, DX_PLAYTYPE_BACK);
					}

					OptionMenu = EFFECT75;

				}

				if (MY_KEY_PUSH(KEY_INPUT_RIGHT) == TRUE)
				{
					if (CheckSoundMem(SERECT.handle) == 0)
					{
						PlaySoundMem(SERECT.handle, DX_PLAYTYPE_BACK);
					}

					OptionMenu = VOLUME75;

				}

				break;

			case DECISION100:
				SOUND_VOLUME.rate = 1;
				SOUND_VOLUME1.rate = 1;
				SOUND_VOLUME2.rate = 1;
				SOUND_VOLUME3.rate = 1;
				SOUND_VOLUME4.rate = 1;
				SOUND_EFFECT.rate = 1;
				SOUND_EFFECT1.rate = 1;
				SOUND_EFFECT2.rate = 1;
				SOUND_EFFECT3.rate = 1;
				SOUND_EFFECT4.rate = 1;
				SOUND_DECISION.rate = 1;
				SOUND_DECISION1.rate = 1;
				SOUND_DECISION2.rate = 1;
				SOUND_DECISION3.rate = 1;
				SOUND_DECISION4.rate = 1.2;


				if (MY_KEY_DOWN(KEY_INPUT_RETURN) == TRUE)
				{

					if (CheckSoundMem(DECISION.handle) == 0)
					{

						PlaySoundMem(DECISION.handle, DX_PLAYTYPE_BACK);
					}


					// ���ʂ̐ݒ�
					ChangeVolumeSoundMem(255 * 100 / 100, DECISION.handle);

				}

				if (MY_KEY_PUSH(KEY_INPUT_DOWN) == TRUE)
				{

					if (CheckSoundMem(SERECT.handle) == 0)
					{


						PlaySoundMem(SERECT.handle, DX_PLAYTYPE_BACK);
					}

					OptionMenu = DECISION0;
				}

				if (MY_KEY_PUSH(KEY_INPUT_UP) == TRUE)
				{

					if (CheckSoundMem(SERECT.handle) == 0)
					{

						PlaySoundMem(SERECT.handle, DX_PLAYTYPE_BACK);
					}

					OptionMenu = DECISION75;
				}

				if (MY_KEY_PUSH(KEY_INPUT_LEFT) == TRUE)
				{
					if (CheckSoundMem(SERECT.handle) == 0)
					{
						PlaySoundMem(SERECT.handle, DX_PLAYTYPE_BACK);
					}

					OptionMenu = EFFECT100;

				}

				if (MY_KEY_PUSH(KEY_INPUT_RIGHT) == TRUE)
				{
					if (CheckSoundMem(SERECT.handle) == 0)
					{
						PlaySoundMem(SERECT.handle, DX_PLAYTYPE_BACK);
					}

					OptionMenu = VOLUME100;

				}

				break;

			

		}

		break;
	}

	if (MY_KEY_DOWN(KEY_INPUT_ESCAPE) == TRUE) 
	{

		if (CheckSoundMem(DECISION.handle) == 0)
		{
					
			PlaySoundMem(DECISION.handle, DX_PLAYTYPE_BACK);
		
		}

		GameScene = GAME_SCENE_START;


	}
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

	if(MY_KEY_DOWN(KEY_INPUT_W) == TRUE) //�L�[�摜��Ԃ�����
	{
		KEY_W = true;
		KEY_A = false;
		KEY_S = false;
		KEY_D = false;
		
	
	}

	if (MY_KEY_DOWN(KEY_INPUT_A) == TRUE) //�L�[�摜��Ԃ�����
	{
		KEY_W = false;
		KEY_A = true;
		KEY_S = false;
		KEY_D = false;

	}

	if (MY_KEY_DOWN(KEY_INPUT_S) == TRUE) //�L�[�摜��Ԃ�����
	{
		KEY_W = false;
		KEY_A = false;
		KEY_S = true;
		KEY_D = false;

	}

	if (MY_KEY_DOWN(KEY_INPUT_D) == TRUE) //�L�[�摜��Ԃ�����
	{
		KEY_W = false;
		KEY_A = false;
		KEY_S = false;
		KEY_D = true;
	}

	if (KEY_W == true) //true�ł���Ƃ��A�Ԃ�����
	{
		DrawGraph(ImageSetumei_KEY_W.x, ImageSetumei_KEY_W.y, ImageSetumei_KEY_W.handle, TRUE);
	}

	if (MY_KEY_DOWN(KEY_INPUT_W) == FALSE)//false�ł���Ƃ��A�Ԃ������Ă���̂���������
	{
		KEY_W = false;
	}

	if (KEY_A == true)//true�ł���Ƃ��A�Ԃ�����
	{
		DrawGraph(ImageSetumei_KEY_A.x, ImageSetumei_KEY_A.y, ImageSetumei_KEY_A.handle, TRUE);
	}

	if (MY_KEY_DOWN(KEY_INPUT_A) == FALSE) //false�ł���Ƃ��A�Ԃ������Ă���̂���������
	{
		KEY_A = false;
	}

	if (KEY_S == true)//true�ł���Ƃ��A�Ԃ�����
	{
		DrawGraph(ImageSetumei_KEY_S.x, ImageSetumei_KEY_S.y, ImageSetumei_KEY_S.handle, TRUE);
	}

	if (MY_KEY_DOWN(KEY_INPUT_S) == FALSE)//false�ł���Ƃ��A�Ԃ������Ă���̂���������
	{
		KEY_S = false;
	}

	if (KEY_D == true)//true�ł���Ƃ��A�Ԃ�����
	{
		DrawGraph(ImageSetumei_KEY_D.x, ImageSetumei_KEY_D.y, ImageSetumei_KEY_D.handle, TRUE);
	}

	if (MY_KEY_DOWN(KEY_INPUT_D) == FALSE)//false�ł���Ƃ��A�Ԃ������Ă���̂���������
	{
		KEY_D = false;
	}



	if (MY_KEY_DOWN(KEY_INPUT_0) == TRUE) //�V�i���I�V�[���֑J��
	{
		//�v���C��ʂ�������
		MY_PLAY_INIT();
		
		GameScene = GAME_SCENE_SCENARIO;
		
	}
	
	


	return;
}

VOID MY_SCENARIO(VOID)
{
	if (EndFlag == FALSE)
	{
		//����������`��
		NovelProc(SCENARIO);
	}

	//�������`��
	NovelDraw();

	if (EndFlag == TRUE)
	{
		SetFontSize(STR_DRAW_SIZE); //�t�H���g�T�C�Y24
		DrawString(0, 200, "�G�X�P�[�v�L�[(ESC)�������ĉ�����", GetColor(255, 255, 255));
		
	}


	if (MY_KEY_DOWN(KEY_INPUT_ESCAPE) == TRUE || MY_KEY_DOWN(KEY_INPUT_6) == TRUE) //�v���C��ʂ֑J��
	{
		SetFontSize(DefaultFontSize); //�f�t�H���g�ɂ���

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
	//DrawBox(GoalRect.left, GoalRect.top, GoalRect.right, GoalRect.bottom, GetColor(255, 255, 0), TRUE);
	//�v���C���[�̓����蔻��p
	/*DrawBox(player.coll.left, player.coll.top, player.coll.right, player.coll.bottom, GetColor(255, 0, 0), FALSE);*/

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
		if (MY_CHECK_RECT_COLL(PlayerRect, Itemflag2) == TRUE && flag == 1 && MY_KEY_PUSH(KEY_INPUT_RETURN) == TRUE)
		{
			flag2 = 1;
			hyouji2 = true;

			if (CheckSoundMem(FLAG.handle) == 0)
			{
				//BGM�̉��ʂ�������
				ChangeVolumeSoundMem(255 * 50 / 100, FLAG.handle);	//50%�̉��ʂɂ���

				PlaySoundMem(FLAG.handle, DX_PLAYTYPE_BACK);
			}
		}

		if (hyouji2 == true && flag2 == 1)
		{
			DrawGraph(TEXT_WIDTH_POSITION, TEXT_HEIGHT_POSITION, TextBox_GenkanKagi.handle, TRUE);
			
			


			if (MY_KEY_PUSH(KEY_INPUT_ESCAPE) == TRUE)
			{
				hyouji2 = false;
			}

		}

		
		//�����擾���Ă��Ȃ��Ƃ�
		if (MY_CHECK_RECT_COLL(PlayerRect, Itemflag2) == TRUE && flag == 0 && MY_KEY_PUSH(KEY_INPUT_RETURN) == TRUE)
		{
			hyouji = true;
			
		}
		//�e�L�X�g�{�b�N�X��\������
		if (hyouji == true)
		{
			DrawGraph(TEXT_WIDTH_POSITION, TEXT_HEIGHT_POSITION, TextBox_GenkanKagiNasi.handle, TRUE);

			if (MY_KEY_PUSH(KEY_INPUT_ESCAPE) == TRUE)
			{
				hyouji = false;
			}

		}

		DrawString(0, 0, "�e�L�X�g�{�b�N�X��ESC�L�[�ŕ��邱�Ƃ��ł��܂��B", GetColor(255, 255, 255));

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

	//�S�Ă𖞂����Ă��邩�`�F�b�N
	if (MY_CHECK_RECT_COLL(PlayerRect, Kakushi) == TRUE && MY_KEY_DOWN(KEY_INPUT_RETURN) == TRUE /*&& flag2 == true*/)
	{

		player.CenterX = startPt5.x;
		player.CenterY = startPt5.y;


		player.image.x = player.CenterX;
		player.image.y = player.CenterY;

		if (CheckSoundMem(ROKA.handle) != 0)
		{
			StopSoundMem(ROKA.handle);	//BGM���~�߂�
		}

		//�B��������
		GameScene = GAME_SCENE_KAKUSI;


		return;
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
			/*	DrawBox(mapColl[tate][yoko].left, mapColl[tate][yoko].top, mapColl[tate][yoko].right, mapColl[tate][yoko].bottom, GetColor(255, 0, 0), FALSE);*/
			}

		}
	}
	//�S�[�������蔻��p
	/*DrawBox(GoalRect2.left, GoalRect2.top, GoalRect2.right, GoalRect2.bottom, GetColor(255, 255, 0), TRUE);*/
	//�v���C���[�̓����蔻��p
	/*DrawBox(player.coll.left, player.coll.top, player.coll.right, player.coll.bottom, GetColor(255, 0, 0), FALSE);*/
	/*DrawBox(Kakushi.left, Kakushi.top, Kakushi.right, Kakushi.bottom, GetColor(255, 255, 0), TRUE);*/

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
	if (MY_CHECK_RECT_COLL(PlayerRect, Itemflag) == TRUE && MY_KEY_PUSH(KEY_INPUT_RETURN))
	{
		hyouji3 = true;
		flag = 1;


		if (CheckSoundMem(FLAG.handle) == 0)
		{
			//BGM�̉��ʂ�������
			ChangeVolumeSoundMem(255 * 50 / 100, FLAG.handle);	//50%�̉��ʂɂ���

			PlaySoundMem(FLAG.handle, DX_PLAYTYPE_BACK);
		}
		
	
	}
	if (hyouji3 == true)
	{
		DrawGraph(TEXT_WIDTH_POSITION, TEXT_HEIGHT_POSITION, TextBox_flag.handle, TRUE);

		

		if (MY_KEY_PUSH(KEY_INPUT_ESCAPE) == TRUE)
		{
			hyouji3 = false;
		}
	}
	//����������Ă��Ȃ����A���ւ֍s���Ƃ�

	if (MY_CHECK_RECT_COLL(PlayerRect, GoalRect3) == TRUE && flag2 == 0 && MY_KEY_PUSH(KEY_INPUT_RETURN))
	{
		hyouji4 = true;

	}
	if (hyouji4 == true)
	{
		DrawGraph(TEXT_WIDTH_POSITION, TEXT_HEIGHT_POSITION, TextBox_Null.handle, TRUE);

		if (MY_KEY_DOWN(KEY_INPUT_ESCAPE) == TRUE)
		{
			hyouji4 = false;
		}
	}

	//��ڂ̃J�M���擾���Ă��邪�A�J���Ȃ��Ƃ�

	if (MY_CHECK_RECT_COLL(PlayerRect, GoalRect3) == TRUE && flag == 1 && MY_KEY_PUSH(KEY_INPUT_RETURN))
	{
		hyouji6 = true;

	}
	if (hyouji6 == true)
	{
		DrawGraph(TEXT_WIDTH_POSITION, TEXT_HEIGHT_POSITION, TextBox_akanai.handle, TRUE);

		if (MY_KEY_DOWN(KEY_INPUT_ESCAPE) == TRUE)
		{
			hyouji6 = false;
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
		//�v���C��ʂ�������
		MY_PLAY_INIT();

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

	RECT PlayerRect;
	PlayerRect.left = player.CenterX - 40 / 20 + 5;
	PlayerRect.top = player.CenterY + 200 / 20 + 5;
	PlayerRect.right = player.CenterX + 650 / 20 - 5;
	PlayerRect.bottom = player.CenterY + 1000 / 20 - 5;

	//�t���O��������Ă��邩�ǂ����̃C�x���g
	if (MY_CHECK_RECT_COLL(PlayerRect, Kanban) == TRUE && MY_KEY_PUSH(KEY_INPUT_RETURN) == TRUE)
	{

		hyouji5 = true;
	}

	if (hyouji5 == true)
	{
		DrawGraph(TEXT_WIDTH_POSITION, TEXT_HEIGHT_POSITION, TextBox_Kanban.handle, TRUE);




		if (MY_KEY_PUSH(KEY_INPUT_ESCAPE) == TRUE)
		{
			hyouji5 = false;
		}

	}


	//�o���p
	//DrawBox(GoalRect4.left, GoalRect4.top, GoalRect4.right, GoalRect4.bottom, GetColor(255, 255, 0), TRUE);
	/*DrawBox(Kanban.left, Kanban.top, Kanban.right, Kanban.bottom, GetColor(255, 255, 0), TRUE);*/
	return;
}

VOID MY_PLAY_KAKUSI(VOID)
{
	MY_PLAY_PROC_KAKUSI(); //����
	MY_PLAY_KAKUSHI_DRAW();//�`��

	return;
}

VOID MY_PLAY_PROC_KAKUSI(VOID)
{

	//�B��������BGM
	if (CheckSoundMem(SYBERB.handle) == 0)
	{
		//BGM�̉��ʂ�������
		ChangeVolumeSoundMem(255 * 50 / 100, SYBERB.handle);	//50%�̉��ʂɂ���

		PlaySoundMem(SYBERB.handle, DX_PLAYTYPE_LOOP);
	}

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
	if (MY_CHECK_RECT_COLL(PlayerRect, KakushiD) == TRUE)
	{

		player.CenterX = startPt3.x;
		player.CenterY = startPt3.y;


		player.image.x = player.CenterX;
		player.image.y = player.CenterY;

		if (CheckSoundMem(SYBERB.handle) != 0)
		{
			StopSoundMem(SYBERB.handle);	//BGM���~�߂�
		}

		//�L����
		GameScene = GAME_SCENE_PLAY3;


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
	if (MY_CHECK_SYBER_PLAYER_COLL(player.coll) == TRUE)
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

VOID MY_PLAY_KAKUSHI_DRAW(VOID)
{

	

	

	//�}�b�v�̕`��

	for (int tate = 0; tate < MAP_HEIGHT_MAX; tate++)
	{
		for (int yoko = 0; yoko < MAP_WIDTH_MAX; yoko++)
		{


			DrawGraph(yoko * mapChip.width,
				tate * mapChip.height,
				mapChip.handle[mapdata14[tate][yoko]],
				TRUE);


		}

	}

	for (int tate = 0; tate < MAP_HEIGHT_MAX; tate++)
	{
		for (int yoko = 0; yoko < MAP_WIDTH_MAX; yoko++)
		{


			DrawGraph(yoko * mapChip.width,
				tate * mapChip.height,
				mapChip.handle[mapdata15[tate][yoko]],
				TRUE);


		}

	}

	

	RECT PlayerRect;
	PlayerRect.left = player.CenterX - 40 / 20 + 5;
	PlayerRect.top = player.CenterY + 200 / 20 + 5;
	PlayerRect.right = player.CenterX + 650 / 20 - 5;
	PlayerRect.bottom = player.CenterY + 1000 / 20 - 5;

	

	DrawGraph(player.image.x, player.image.y, playerChip1.handle[player.kind1], TRUE);//�v���C���̕`��

	if (MY_CHECK_RECT_COLL(PlayerRect, Itemflag) == TRUE && MY_KEY_PUSH(KEY_INPUT_RETURN) == TRUE)
	{

		hyouji7 = true;
	}

	if (hyouji7 == true)
	{
		DrawGraph(TEXT_WIDTH_POSITION, TEXT_HEIGHT_POSITION, TextBox_kakushi.handle, TRUE);

		DrawGraph(TEXT_WIDTH_POSITION, 300, HINT_KAMI.handle, TRUE);


		if (MY_KEY_PUSH(KEY_INPUT_ESCAPE) == TRUE)
		{
			hyouji7 = false;
		}

	}

	DrawBox(Itemflag.left, Itemflag.top, Itemflag.right, Itemflag.bottom, GetColor(255, 255, 0), TRUE);

	
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

	DrawString(0, 0, "�G���h���[���e�L�X�g�I����A�G�X�P�[�v�L�[�������ĉ�����", GetColor(255, 255, 255));
	return;
}

//�G���h��ʂ̕`��
VOID MY_END_DRAW(VOID)
{
	
	if (EndFlag == FALSE)
	{
		//����������`��
		NovelProc(SCENARIO_END);
	}

	//�������`��
	NovelDraw();
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

	//######################������ʂ̃L�[���͉摜####################

	strcpy_s(ImageSetumei_KEY_W.path, IMAGE_SETUMEI_KEY_W);	//������ʔw�i�摜�Ǎ�
	ImageSetumei_KEY_W.handle = LoadGraph(ImageSetumei_KEY_W.path);			//�ǂݍ���
	if (ImageSetumei_KEY_W.handle == -1)
	{
		//�G���[���b�Z�[�W�\��
		MessageBox(GetMainWindowHandle(), IMAGE_SETUMEI_KEY_W, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(ImageSetumei_KEY_W.handle, &ImageSetumei_KEY_W.width, &ImageSetumei_KEY_W.height);	//�摜�̕��ƍ������擾
	ImageSetumei_KEY_W.x = GAME_WIDTH / 2 - ImageSetumei_KEY_W.width / 2;		//���E��������
	ImageSetumei_KEY_W.y = GAME_HEIGHT / 2 - ImageSetumei_KEY_W.height / 2;		//�㉺��������


	//-----------------------------------------------------------------------

	strcpy_s(ImageSetumei_KEY_A.path, IMAGE_SETUMEI_KEY_A);	//������ʔw�i�摜�Ǎ�
	ImageSetumei_KEY_A.handle = LoadGraph(ImageSetumei_KEY_A.path);			//�ǂݍ���
	if (ImageSetumei_KEY_A.handle == -1)
	{
		//�G���[���b�Z�[�W�\��
		MessageBox(GetMainWindowHandle(), IMAGE_SETUMEI_KEY_A, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(ImageSetumei_KEY_A.handle, &ImageSetumei_KEY_A.width, &ImageSetumei_KEY_A.height);	//�摜�̕��ƍ������擾
	ImageSetumei_KEY_A.x = GAME_WIDTH / 2 - ImageSetumei_KEY_A.width / 2;		//���E��������
	ImageSetumei_KEY_A.y = GAME_HEIGHT / 2 - ImageSetumei_KEY_A.height / 2;		//�㉺��������

	//-----------------------------------------------------------------------

	strcpy_s(ImageSetumei_KEY_S.path, IMAGE_SETUMEI_KEY_S);	//������ʔw�i�摜�Ǎ�
	ImageSetumei_KEY_S.handle = LoadGraph(ImageSetumei_KEY_S.path);			//�ǂݍ���
	if (ImageSetumei_KEY_S.handle == -1)
	{
		//�G���[���b�Z�[�W�\��
		MessageBox(GetMainWindowHandle(), IMAGE_SETUMEI_KEY_S, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(ImageSetumei_KEY_S.handle, &ImageSetumei_KEY_S.width, &ImageSetumei_KEY_S.height);	//�摜�̕��ƍ������擾
	ImageSetumei_KEY_S.x = GAME_WIDTH / 2 - ImageSetumei_KEY_S.width / 2;		//���E��������
	ImageSetumei_KEY_S.y = GAME_HEIGHT / 2 - ImageSetumei_KEY_S.height / 2;		//�㉺��������

	//-----------------------------------------------------------------------

	strcpy_s(ImageSetumei_KEY_D.path, IMAGE_SETUMEI_KEY_D);	//������ʔw�i�摜�Ǎ�
	ImageSetumei_KEY_D.handle = LoadGraph(ImageSetumei_KEY_D.path);			//�ǂݍ���
	if (ImageSetumei_KEY_D.handle == -1)
	{
		//�G���[���b�Z�[�W�\��
		MessageBox(GetMainWindowHandle(), IMAGE_SETUMEI_KEY_D, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(ImageSetumei_KEY_D.handle, &ImageSetumei_KEY_D.width, &ImageSetumei_KEY_D.height);	//�摜�̕��ƍ������擾
	ImageSetumei_KEY_D.x = GAME_WIDTH / 2 - ImageSetumei_KEY_D.width / 2;		//���E��������
	ImageSetumei_KEY_D.y = GAME_HEIGHT / 2 - ImageSetumei_KEY_D.height / 2;		//�㉺��������




	//######################���j���[��ʂ̃{�^���摜�̓Ǎ�#############

	strcpy_s(GameMenu_START.image.path, GAME_MENU_BTN);	//�X�^�[�g�{�^���摜�Ǎ�
	GameMenu_START.image.handle = LoadGraph(GameMenu_START.image.path);			//�ǂݍ���
	if (GameMenu_START.image.handle == -1)
	{
		//�G���[���b�Z�[�W�\��
		MessageBox(GetMainWindowHandle(), GAME_MENU_BTN, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(GameMenu_START.image.handle, &GameMenu_START.image.width, &GameMenu_START.image.height);	//�摜�̕��ƍ������擾
	GameMenu_START.image.x = (GAME_WIDTH / 2 - GameMenu_START.image.width / 2) + 50;		//���E��������
	GameMenu_START.image.y = (GAME_HEIGHT / 2 - GameMenu_START.image.height / 2) + 250;		//�㉺��������
	GameMenu_START.rate = 2;

	//--------------------------------------------------------------------------------------------

	strcpy_s(GameMenu_EXIT.image.path, GAME_MENU_BTN2);	//�I���{�^���摜�Ǎ�
	GameMenu_EXIT.image.handle = LoadGraph(GameMenu_EXIT.image.path);			//�ǂݍ���
	if (GameMenu_EXIT.image.handle == -1)
	{
		//�G���[���b�Z�[�W�\��
		MessageBox(GetMainWindowHandle(), GAME_MENU_BTN2, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(GameMenu_EXIT.image.handle, &GameMenu_EXIT.image.width, &GameMenu_EXIT.image.height);	//�摜�̕��ƍ������擾
	GameMenu_EXIT.image.x = (GAME_WIDTH / 2 - GameMenu_EXIT.image.width / 2)+ 50;		//���E��������
	GameMenu_EXIT.image.y = (GAME_HEIGHT / 2 - GameMenu_EXIT.image.height / 2) + 350;		//�㉺��������
	GameMenu_EXIT.rate = 1;

	//--------------------------------------------------------------------------------------------

	strcpy_s(GameMenu_OPTION.image.path, GAME_MENU_BTN3);	//�ݒ�{�^���摜�Ǎ�
	GameMenu_OPTION.image.handle = LoadGraph(GameMenu_OPTION.image.path);			//�ǂݍ���
	if (GameMenu_OPTION.image.handle == -1)
	{
		//�G���[���b�Z�[�W�\��
		MessageBox(GetMainWindowHandle(), GAME_MENU_BTN3, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(GameMenu_OPTION.image.handle, &GameMenu_OPTION.image.width, &GameMenu_OPTION.image.height);	//�摜�̕��ƍ������擾
	GameMenu_OPTION.image.x = (GAME_WIDTH / 2 - GameMenu_OPTION.image.width / 2) + 50;		//���E��������
	GameMenu_OPTION.image.y = (GAME_HEIGHT / 2 - GameMenu_OPTION.image.height / 2) + 300;		//�㉺��������
	GameMenu_OPTION.rate = 1;

	//##################################�I�v�V������ʁE���ʒ����{�^��#############################

	strcpy_s(SOUND_VOLUME.image.path, OPTION_SOUND_VOLUME);	//�I���{�^���摜�Ǎ�
	SOUND_VOLUME.image.handle = LoadGraph(SOUND_VOLUME.image.path);			//�ǂݍ���
	if (SOUND_VOLUME.image.handle == -1)
	{
		//�G���[���b�Z�[�W�\��
		MessageBox(GetMainWindowHandle(), OPTION_SOUND_VOLUME, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(SOUND_VOLUME.image.handle, &SOUND_VOLUME.image.width, &SOUND_VOLUME.image.height);	//�摜�̕��ƍ������擾
	SOUND_VOLUME.image.x = (GAME_WIDTH / 2 - SOUND_VOLUME.image.width / 2);		//���E��������
	SOUND_VOLUME.image.y = (GAME_HEIGHT / 2 - SOUND_VOLUME.image.height / 2);		//�㉺��������
	SOUND_VOLUME.rate = 1;

	//--------------------------------------------------------------------------------------------

	strcpy_s(SOUND_VOLUME1.image.path, OPTION_SOUND_VOLUME1);	//�I���{�^���摜�Ǎ�
	SOUND_VOLUME1.image.handle = LoadGraph(SOUND_VOLUME1.image.path);			//�ǂݍ���
	if (SOUND_VOLUME1.image.handle == -1)
	{
		//�G���[���b�Z�[�W�\��
		MessageBox(GetMainWindowHandle(), OPTION_SOUND_VOLUME1, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(SOUND_VOLUME1.image.handle, &SOUND_VOLUME1.image.width, &SOUND_VOLUME1.image.height);	//�摜�̕��ƍ������擾
	SOUND_VOLUME1.image.x = (GAME_WIDTH / 2 - SOUND_VOLUME1.image.width / 2);		//���E��������
	SOUND_VOLUME1.image.y = (GAME_HEIGHT / 2 - SOUND_VOLUME1.image.height / 2);		//�㉺��������
	SOUND_VOLUME1.rate = 1;

	//--------------------------------------------------------------------------------------------

	strcpy_s(SOUND_VOLUME2.image.path, OPTION_SOUND_VOLUME2);	//�I���{�^���摜�Ǎ�
	SOUND_VOLUME2.image.handle = LoadGraph(SOUND_VOLUME2.image.path);			//�ǂݍ���
	if (SOUND_VOLUME2.image.handle == -1)
	{
		//�G���[���b�Z�[�W�\��
		MessageBox(GetMainWindowHandle(), OPTION_SOUND_VOLUME2, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(SOUND_VOLUME2.image.handle, &SOUND_VOLUME2.image.width, &SOUND_VOLUME2.image.height);	//�摜�̕��ƍ������擾
	SOUND_VOLUME2.image.x = (GAME_WIDTH / 2 - SOUND_VOLUME2.image.width / 2);		//���E��������
	SOUND_VOLUME2.image.y = (GAME_HEIGHT / 2 - SOUND_VOLUME2.image.height / 2);		//�㉺��������
	SOUND_VOLUME2.rate = 1;

	//--------------------------------------------------------------------------------------------

	strcpy_s(SOUND_VOLUME3.image.path, OPTION_SOUND_VOLUME3);	//�I���{�^���摜�Ǎ�
	SOUND_VOLUME3.image.handle = LoadGraph(SOUND_VOLUME3.image.path);			//�ǂݍ���
	if (SOUND_VOLUME3.image.handle == -1)
	{
		//�G���[���b�Z�[�W�\��
		MessageBox(GetMainWindowHandle(), OPTION_SOUND_VOLUME3, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(SOUND_VOLUME3.image.handle, &SOUND_VOLUME3.image.width, &SOUND_VOLUME3.image.height);	//�摜�̕��ƍ������擾
	SOUND_VOLUME3.image.x = (GAME_WIDTH / 2 - SOUND_VOLUME3.image.width / 2);		//���E��������
	SOUND_VOLUME3.image.y = (GAME_HEIGHT / 2 - SOUND_VOLUME3.image.height / 2);		//�㉺��������
	SOUND_VOLUME3.rate = 1;

	//--------------------------------------------------------------------------------------------

	strcpy_s(SOUND_VOLUME4.image.path, OPTION_SOUND_VOLUME4);	//�I���{�^���摜�Ǎ�
	SOUND_VOLUME4.image.handle = LoadGraph(SOUND_VOLUME4.image.path);			//�ǂݍ���
	if (SOUND_VOLUME4.image.handle == -1)
	{
		//�G���[���b�Z�[�W�\��
		MessageBox(GetMainWindowHandle(), OPTION_SOUND_VOLUME4, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(SOUND_VOLUME4.image.handle, &SOUND_VOLUME4.image.width, &SOUND_VOLUME4.image.height);	//�摜�̕��ƍ������擾
	SOUND_VOLUME4.image.x = (GAME_WIDTH / 2 - SOUND_VOLUME4.image.width / 2);		//���E��������
	SOUND_VOLUME4.image.y = (GAME_HEIGHT / 2 - SOUND_VOLUME4.image.height / 2);		//�㉺��������
	SOUND_VOLUME4.rate = 1;

	//################################���ʉ��{�^���摜########################

	strcpy_s(SOUND_EFFECT.image.path, OPTION_SOUND_EFFECT);	//�I���{�^���摜�Ǎ�
	SOUND_EFFECT.image.handle = LoadGraph(SOUND_EFFECT.image.path);			//�ǂݍ���
	if (SOUND_EFFECT.image.handle == -1)
	{
		//�G���[���b�Z�[�W�\��
		MessageBox(GetMainWindowHandle(), OPTION_SOUND_EFFECT, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(SOUND_EFFECT.image.handle, &SOUND_EFFECT.image.width, &SOUND_EFFECT.image.height);	//�摜�̕��ƍ������擾
	SOUND_EFFECT.image.x = (GAME_WIDTH / 2 - SOUND_EFFECT.image.width / 2);		//���E��������
	SOUND_EFFECT.image.y = (GAME_HEIGHT / 2 - SOUND_EFFECT.image.height / 2);		//�㉺��������
	SOUND_EFFECT.rate = 1;

	//------------------------------------------------------------------------------------

	strcpy_s(SOUND_EFFECT1.image.path, OPTION_SOUND_EFFECT1);	//���ʉ��{�^���摜�Ǎ�
	SOUND_EFFECT1.image.handle = LoadGraph(SOUND_EFFECT1.image.path);			//�ǂݍ���
	if (SOUND_EFFECT1.image.handle == -1)
	{
		//�G���[���b�Z�[�W�\��
		MessageBox(GetMainWindowHandle(), OPTION_SOUND_EFFECT1, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(SOUND_EFFECT1.image.handle, &SOUND_EFFECT1.image.width, &SOUND_EFFECT1.image.height);	//�摜�̕��ƍ������擾
	SOUND_EFFECT1.image.x = (GAME_WIDTH / 2 - SOUND_EFFECT1.image.width / 2);		//���E��������
	SOUND_EFFECT1.image.y = (GAME_HEIGHT / 2 - SOUND_EFFECT1.image.height / 2);		//�㉺��������
	SOUND_EFFECT1.rate = 1;

	//------------------------------------------------------------------------------------

	strcpy_s(SOUND_EFFECT2.image.path, OPTION_SOUND_EFFECT2);	//���ʉ��{�^���摜�Ǎ�
	SOUND_EFFECT2.image.handle = LoadGraph(SOUND_EFFECT2.image.path);			//�ǂݍ���
	if (SOUND_EFFECT2.image.handle == -1)
	{
		//�G���[���b�Z�[�W�\��
		MessageBox(GetMainWindowHandle(), OPTION_SOUND_EFFECT2, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(SOUND_EFFECT2.image.handle, &SOUND_EFFECT2.image.width, &SOUND_EFFECT2.image.height);	//�摜�̕��ƍ������擾
	SOUND_EFFECT2.image.x = (GAME_WIDTH / 2 - SOUND_EFFECT2.image.width / 2);		//���E��������
	SOUND_EFFECT2.image.y = (GAME_HEIGHT / 2 - SOUND_EFFECT2.image.height / 2);		//�㉺��������
	SOUND_EFFECT2.rate = 1;

	//------------------------------------------------------------------------------------

	strcpy_s(SOUND_EFFECT3.image.path, OPTION_SOUND_EFFECT3);	//���ʉ��{�^���摜�Ǎ�
	SOUND_EFFECT3.image.handle = LoadGraph(SOUND_EFFECT3.image.path);			//�ǂݍ���
	if (SOUND_EFFECT3.image.handle == -1)
	{
		//�G���[���b�Z�[�W�\��
		MessageBox(GetMainWindowHandle(), OPTION_SOUND_EFFECT3, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(SOUND_EFFECT3.image.handle, &SOUND_EFFECT3.image.width, &SOUND_EFFECT3.image.height);	//�摜�̕��ƍ������擾
	SOUND_EFFECT3.image.x = (GAME_WIDTH / 2 - SOUND_EFFECT3.image.width / 2);		//���E��������
	SOUND_EFFECT3.image.y = (GAME_HEIGHT / 2 - SOUND_EFFECT3.image.height / 2);		//�㉺��������
	SOUND_EFFECT3.rate = 1;

	//------------------------------------------------------------------------------------

	strcpy_s(SOUND_EFFECT4.image.path, OPTION_SOUND_EFFECT4);	//���ʉ��{�^���摜�Ǎ�
	SOUND_EFFECT4.image.handle = LoadGraph(SOUND_EFFECT4.image.path);			//�ǂݍ���
	if (SOUND_EFFECT4.image.handle == -1)
	{
		//�G���[���b�Z�[�W�\��
		MessageBox(GetMainWindowHandle(), OPTION_SOUND_EFFECT4, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(SOUND_EFFECT4.image.handle, &SOUND_EFFECT4.image.width, &SOUND_EFFECT4.image.height);	//�摜�̕��ƍ������擾
	SOUND_EFFECT4.image.x = (GAME_WIDTH / 2 - SOUND_EFFECT4.image.width / 2);		//���E��������
	SOUND_EFFECT4.image.y = (GAME_HEIGHT / 2 - SOUND_EFFECT4.image.height / 2);		//�㉺��������
	SOUND_EFFECT4.rate = 1;

	//############################����{�^���Ǎ�#############################

	strcpy_s(SOUND_DECISION.image.path, OPTION_SOUND_DECISION);	//���ʉ��{�^���摜�Ǎ�
	SOUND_DECISION.image.handle = LoadGraph(SOUND_DECISION.image.path);			//�ǂݍ���
	if (SOUND_DECISION.image.handle == -1)
	{
		//�G���[���b�Z�[�W�\��
		MessageBox(GetMainWindowHandle(), OPTION_SOUND_DECISION, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(SOUND_DECISION.image.handle, &SOUND_DECISION.image.width, &SOUND_DECISION.image.height);	//�摜�̕��ƍ������擾
	SOUND_DECISION.image.x = (GAME_WIDTH / 2 - SOUND_DECISION.image.width / 2);		//���E��������
	SOUND_DECISION.image.y = (GAME_HEIGHT / 2 - SOUND_DECISION.image.height / 2);		//�㉺��������
	SOUND_DECISION.rate = 1;

	//-------------------------------------------------------------------------------------

	strcpy_s(SOUND_DECISION1.image.path, OPTION_SOUND_DECISION1);	//���ʉ��{�^���摜�Ǎ�
	SOUND_DECISION1.image.handle = LoadGraph(SOUND_DECISION1.image.path);			//�ǂݍ���
	if (SOUND_DECISION1.image.handle == -1)
	{
		//�G���[���b�Z�[�W�\��
		MessageBox(GetMainWindowHandle(), OPTION_SOUND_DECISION1, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(SOUND_DECISION1.image.handle, &SOUND_DECISION1.image.width, &SOUND_DECISION1.image.height);	//�摜�̕��ƍ������擾
	SOUND_DECISION1.image.x = (GAME_WIDTH / 2 - SOUND_DECISION1.image.width / 2);		//���E��������
	SOUND_DECISION1.image.y = (GAME_HEIGHT / 2 - SOUND_DECISION1.image.height / 2);		//�㉺��������
	SOUND_DECISION1.rate = 1;

	//-------------------------------------------------------------------------------------

	strcpy_s(SOUND_DECISION2.image.path, OPTION_SOUND_DECISION2);	//���ʉ��{�^���摜�Ǎ�
	SOUND_DECISION2.image.handle = LoadGraph(SOUND_DECISION2.image.path);			//�ǂݍ���
	if (SOUND_DECISION2.image.handle == -1)
	{
		//�G���[���b�Z�[�W�\��
		MessageBox(GetMainWindowHandle(), OPTION_SOUND_DECISION2, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(SOUND_DECISION2.image.handle, &SOUND_DECISION2.image.width, &SOUND_DECISION2.image.height);	//�摜�̕��ƍ������擾
	SOUND_DECISION2.image.x = (GAME_WIDTH / 2 - SOUND_DECISION2.image.width / 2);		//���E��������
	SOUND_DECISION2.image.y = (GAME_HEIGHT / 2 - SOUND_DECISION2.image.height / 2);		//�㉺��������
	SOUND_DECISION2.rate = 1;

	//-------------------------------------------------------------------------------------

	strcpy_s(SOUND_DECISION3.image.path, OPTION_SOUND_DECISION3);	//���ʉ��{�^���摜�Ǎ�
	SOUND_DECISION3.image.handle = LoadGraph(SOUND_DECISION3.image.path);			//�ǂݍ���
	if (SOUND_DECISION3.image.handle == -1)
	{
		//�G���[���b�Z�[�W�\��
		MessageBox(GetMainWindowHandle(), OPTION_SOUND_DECISION3, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(SOUND_DECISION3.image.handle, &SOUND_DECISION3.image.width, &SOUND_DECISION3.image.height);	//�摜�̕��ƍ������擾
	SOUND_DECISION3.image.x = (GAME_WIDTH / 2 - SOUND_DECISION3.image.width / 2);		//���E��������
	SOUND_DECISION3.image.y = (GAME_HEIGHT / 2 - SOUND_DECISION3.image.height / 2);		//�㉺��������
	SOUND_DECISION3.rate = 1;

	//-------------------------------------------------------------------------------------

	strcpy_s(SOUND_DECISION4.image.path, OPTION_SOUND_DECISION4);	//���ʉ��{�^���摜�Ǎ�
	SOUND_DECISION4.image.handle = LoadGraph(SOUND_DECISION4.image.path);			//�ǂݍ���
	if (SOUND_DECISION4.image.handle == -1)
	{
		//�G���[���b�Z�[�W�\��
		MessageBox(GetMainWindowHandle(), OPTION_SOUND_DECISION4, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(SOUND_DECISION4.image.handle, &SOUND_DECISION4.image.width, &SOUND_DECISION4.image.height);	//�摜�̕��ƍ������擾
	SOUND_DECISION4.image.x = (GAME_WIDTH / 2 - SOUND_DECISION4.image.width / 2);		//���E��������
	SOUND_DECISION4.image.y = (GAME_HEIGHT / 2 - SOUND_DECISION4.image.height / 2);		//�㉺��������
	SOUND_DECISION4.rate = 1;




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


	strcpy_s(TextBox_Kanban.path, TEXT_BOX_5); //�Ŕ�
	TextBox_Kanban.handle = LoadGraph(TextBox_Kanban.path);			//�ǂݍ���
	if (TextBox_Kanban.handle == -1)
	{
		//�G���[���b�Z�[�W�\��
		MessageBox(GetMainWindowHandle(), TEXT_BOX_5, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	strcpy_s(TextBox_akanai.path, TEXT_BOX_6); //�Ŕ�
	TextBox_akanai.handle = LoadGraph(TextBox_akanai.path);			//�ǂݍ���
	if (TextBox_akanai.handle == -1)
	{
		//�G���[���b�Z�[�W�\��
		MessageBox(GetMainWindowHandle(), TEXT_BOX_6, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	strcpy_s(TextBox_kakushi.path, TEXT_BOX_7); //�B������
	TextBox_kakushi.handle = LoadGraph(TextBox_kakushi.path);			//�ǂݍ���
	if (TextBox_kakushi.handle == -1)
	{
		//�G���[���b�Z�[�W�\��
		MessageBox(GetMainWindowHandle(), TEXT_BOX_7, IMAGE_LOAD_ERR_TITLE, MB_OK);
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

	//gif 

	strcpy_s(SYBER.path, SYBER_MAP); //�A�C�e����������Ă��Ȃ��Ƃ��̌��ւ̃e�L�X�g�{�b�N�X
	SYBER.handle = LoadGraph(SYBER.path);			//�ǂݍ���
	if (SYBER.handle == -1)
	{
		//�G���[���b�Z�[�W�\��
		MessageBox(GetMainWindowHandle(), SYBER_MAP, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	//########################�B�������q���g########################

	strcpy_s(HINT_KAMI.path, HINT);	//�B�������q���g�摜�Ǎ�
	HINT_KAMI.handle = LoadGraph(HINT_KAMI.path);			//�ǂݍ���
	if (HINT_KAMI.handle == -1)
	{
		//�G���[���b�Z�[�W�\��
		MessageBox(GetMainWindowHandle(), HINT, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(HINT_KAMI.handle, &HINT_KAMI.width, &HINT_KAMI.height);	//�摜�̕��ƍ������擾
	HINT_KAMI.x = GAME_WIDTH / 2 - HINT_KAMI.width / 2;		//���E��������
	HINT_KAMI.y = GAME_HEIGHT / 2 - HINT_KAMI.height / 2;		//�㉺��������


	
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
	DeleteGraph(TextBox_Kanban.handle);
	DeleteGraph(TextBox_akanai.handle);
	DeleteGraph(TextBox_kakushi.handle);
	DeleteGraph(HINT_KAMI.handle);
	DeleteGraph(GameMenu_START.image.handle);
	DeleteGraph(GameMenu_EXIT.image.handle);
	DeleteGraph(GameMenu_OPTION.image.handle);
	DeleteGraph(ImageSetumei_KEY_W.handle);
	DeleteGraph(ImageSetumei_KEY_A.handle);
	DeleteGraph(ImageSetumei_KEY_S.handle);
	DeleteGraph(ImageSetumei_KEY_D.handle);
	DeleteGraph(SOUND_VOLUME.image.handle);
	DeleteGraph(SOUND_VOLUME1.image.handle);
	DeleteGraph(SOUND_VOLUME2.image.handle);
	DeleteGraph(SOUND_VOLUME3.image.handle);
	DeleteGraph(SOUND_VOLUME4.image.handle);
	DeleteGraph(SOUND_EFFECT.image.handle);
	DeleteGraph(SOUND_EFFECT1.image.handle);
	DeleteGraph(SOUND_EFFECT2.image.handle);
	DeleteGraph(SOUND_EFFECT3.image.handle);
	DeleteGraph(SOUND_EFFECT4.image.handle);
	DeleteGraph(SOUND_DECISION.image.handle);
	DeleteGraph(SOUND_DECISION1.image.handle);
	DeleteGraph(SOUND_DECISION2.image.handle);
	DeleteGraph(SOUND_DECISION3.image.handle);
	DeleteGraph(SOUND_DECISION4.image.handle);
	DeleteGraph(SYBER.handle);
	for (int i_num = 0; i_num < MAP_DIV_NUM; i_num++) { DeleteGraph(mapChip.handle[i_num]); }
	for (int i_num2 = 0; i_num2 < MAP_DIV_NUM; i_num2++) { DeleteGraph(mapChip2.handle[i_num2]); }
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

	strcpy_s(SERECT.path, SERECT_EFFECT);		//�Z���N�g�����ʉ��̐ݒ�
	SERECT.handle = LoadSoundMem(SERECT.path);	//�ǂݍ���
	if (SERECT.handle == -1)
	{
		//�G���[���b�Z�[�W�\��
		MessageBox(GetMainWindowHandle(), SERECT_EFFECT, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	strcpy_s(DECISION.path, DECISION_EFFECT);		//���莞���ʉ��̐ݒ�
	DECISION.handle = LoadSoundMem(DECISION.path);	//�ǂݍ���
	if (DECISION.handle == -1)
	{
		//�G���[���b�Z�[�W�\��
		MessageBox(GetMainWindowHandle(), DECISION_EFFECT, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	strcpy_s(SYBERB.path, SYBER_BGM);		//���莞���ʉ��̐ݒ�
	SYBERB.handle = LoadSoundMem(SYBERB.path);	//�ǂݍ���
	if (SYBERB.handle == -1)
	{
		//�G���[���b�Z�[�W�\��
		MessageBox(GetMainWindowHandle(), SYBER_BGM, MUSIC_LOAD_ERR_TITLE, MB_OK);
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
	DeleteSoundMem(SERECT.handle);
	DeleteSoundMem(DECISION.handle);
	DeleteSoundMem(SYBERB.handle);

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
				if (mapdata5[tate][yoko] == KABE) { return TRUE; }
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

BOOL MY_CHECK_SYBER_PLAYER_COLL(RECT player)
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

				if (mapdata14[tate][yoko] == B) { return TRUE; }
				if (mapdata15[tate][yoko] == d) { return TRUE; }

			}
		}
	}

	return FALSE;
}


