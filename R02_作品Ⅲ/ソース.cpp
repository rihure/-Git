#include "DxLib.h"
#include "stdlib.h"
#include "string.h"

#define TITLE_NAME TEXT("不思議な家")

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
#define MAP_NUM         3           // マップの数
#define GAME_WIDTH			800	//画面の横の大きさ
#define GAME_HEIGHT			640	//画面の縦の大きさ
#define GAME_COLOR			32	//画面のカラービット
#define TEXT_WIDTH_POSITION	100
#define TEXT_HEIGHT_POSITION 500

#define MAP_SIZE        32          // マップチップ一つのドットサイズ

#define MAP_WIDTH_MAX   25          // マップの最大幅
#define MAP_HEIGHT_MAX  20          // マップの最大縦長さ
#define MAP_DIV_WIDTH		32	//画像を分割する幅サイズ
#define MAP_DIV_HEIGHT		32	//画像を分割する高さサイズ
#define MAP_DIV_TATE		8	//画像を縦に分割する数8
#define MAP_DIV_YOKO		50	//画像を横に分割する数50 
#define MAP_DIV_NUM	MAP_DIV_TATE * MAP_DIV_YOKO	//画像を分割する総数 400

#define MAP_TATE		41	//画像を縦に分割する数41
#define MAP_YOKO		32	//画像を横に分割する数32
#define MAP_NUM	MAP_TATE * MAP_YOKO	//画像を分割する総数 1312


#define PLAYER_DIV_WIDTH 32 //プレイヤーの横幅32ビット 
#define PLAYER_DIV_HEIGHT 48 //プレイヤー立幅48ビット
#define PLAYER_DIV_TATE 4 //タテ分割数4
#define PLAYER_DIV_YOKO 4 //ヨコ分割数4
#define PLAYER_DIV_NUM PLAYER_DIV_TATE * PLAYER_DIV_YOKO //16
#define PLAYER_IMG_CHANGE_MAX 16

#define GAME_FPS			60	//FPSの数値	

//画像のパス設定
#define TITLE_BACK_PATH TEXT(".\\IMAGE\\ゲームタイトル.png") //タイトルの画像
#define IMAGE_SETUMEI_PATH		TEXT(".\\IMAGE\\操作説明3.png") //説明画面の画像
#define IMAGE_SETUMEI_KEY_W TEXT(".\\IMAGE\\操作説明3_W.png")//Wキー入力時
#define IMAGE_SETUMEI_KEY_A TEXT(".\\IMAGE\\操作説明3_A.png")//Aキー入力時
#define IMAGE_SETUMEI_KEY_S TEXT(".\\IMAGE\\操作説明3_S.png")//Sキー入力時
#define IMAGE_SETUMEI_KEY_D TEXT(".\\IMAGE\\操作説明3_D.png")//Dキー入力時
#define GAME_MAP_PATH TEXT(".\\IMAGE\\ST-Town-I01.png") //マップチップ
#define GAME_MAP_PATH2 TEXT(".\\IMAGE\\mapchip1.png") //マップチップ2
#define GAME_PLAYER_PATH TEXT(".\\IMAGE\\joshi03.png") //プレイヤーの画像
#define TEXT_BOX TEXT(".\\IMAGE\\TextBox_start.png")  //現在は没である
#define TEXT_BOX_1 TEXT(".\\IMAGE\\TextBox1.png") //アイテム回収時のテキストボックス
#define TEXT_BOX_2 TEXT(".\\IMAGE\\TextBox鍵無し.png") //アイテム回収していないとき
#define TEXT_BOX_3 TEXT(".\\IMAGE\\TextBox玄関鍵無し.png")//鍵を取得時
#define TEXT_BOX_4 TEXT(".\\IMAGE\\TextBox玄関鍵あり.png")//鍵を持っていない
#define TEXT_BOX_5 TEXT(".\\IMAGE\\TextBox_kanban.png")//外の看板
#define TEXT_BOX_6 TEXT(".\\IMAGE\\TextBox_akanai.png") //鍵が合わないとき
#define TEXT_BOX_7 TEXT(".\\IMAGE\\TextBoxちぎり紙.png")//隠し部屋のテキストボックス
#define GAME_MENU_BTN TEXT(".\\IMAGE\\Menu_btn1.png")//スタートボタン
#define GAME_MENU_BTN2 TEXT(".\\IMAGE\\Menu_btn2.png")//終了ボタン
#define GAME_MENU_BTN3 TEXT(".\\IMAGE\\Menu_btn3.png")//オプションボタン

#define HINT TEXT(".\\IMAGE\\NazotokiYoushi.png")//隠し部屋のヒント

#define OPTION_SOUND_VOLUME  TEXT(".\\IMAGE\\Volume0.png")//音量ボタン
#define OPTION_SOUND_VOLUME1 TEXT(".\\IMAGE\\Volume25.png")//音量ボタン
#define OPTION_SOUND_VOLUME2 TEXT(".\\IMAGE\\Volume50.png")//音量ボタン
#define OPTION_SOUND_VOLUME3 TEXT(".\\IMAGE\\Volume75.png")//音量ボタン
#define OPTION_SOUND_VOLUME4 TEXT(".\\IMAGE\\Volume100.png")//音量ボタン

#define OPTION_SOUND_EFFECT  TEXT(".\\IMAGE\\SE_Volume0.png")//効果音音量ボタン
#define OPTION_SOUND_EFFECT1 TEXT(".\\IMAGE\\SE_Volume25.png")//効果音音量ボタン
#define OPTION_SOUND_EFFECT2 TEXT(".\\IMAGE\\SE_Volume50.png")//効果音音量ボタン
#define OPTION_SOUND_EFFECT3 TEXT(".\\IMAGE\\SE_Volume75.png")//効果音音量ボタン
#define OPTION_SOUND_EFFECT4 TEXT(".\\IMAGE\\SE_Volume100.png")//効果音音量ボタン

#define OPTION_SOUND_DECISION  TEXT(".\\IMAGE\\DC_Volume0.png")//決定音音量ボタン
#define OPTION_SOUND_DECISION1 TEXT(".\\IMAGE\\DC_Volume25.png")//決定音音量ボタン
#define OPTION_SOUND_DECISION2 TEXT(".\\IMAGE\\DC_Volume50.png")//決定音音量ボタン
#define OPTION_SOUND_DECISION3 TEXT(".\\IMAGE\\DC_Volume75.png")//決定音音量ボタン
#define OPTION_SOUND_DECISION4 TEXT(".\\IMAGE\\DC_Volume100.png")//決定音音量ボタン

//gif
#define SYBER_MAP TEXT(".\\IMAGE\\giphy.gif")//隠し部屋

//BGMのパスを設定
#define TITLE_BGM_PATH TEXT(".\\MUSIC\\冬の情景にて.mp3") //タイトルBGM
#define ROKA_BGM_PATH TEXT(".\\MUSIC\\死霊の館.mp3") //廊下のちょっと怖いBGM
#define FLAG_BGM_PATH TEXT(".\\MUSIC\\se_maoudamashii_onepoint07.mp3")//アイテム取得時の効果音
#define SERECT_EFFECT TEXT(".\\MUSIC\\セレクト音_3.mp3")//選択時の効果音
#define DECISION_EFFECT TEXT(".\\MUSIC\\システム決定音_11.mp3")//決定時の効果音
#define SYBER_BGM TEXT(".\\MUSIC\\Challenge_try_02.mp3")//隠し部屋BGM

//エラーメッセージ
#define IMAGE_LOAD_ERR_TITLE	TEXT("画像読み込みエラー")
#define MUSIC_LOAD_ERR_TITLE	TEXT("音楽読み込みエラー")

//パスの長さ
#define PATH_MAX			255	//255文字まで
#define NAME_MAX			255	//255文字まで

//キーボードの種類
#define KEY_CODE_KIND		256	//256種類

//文字描画用
#define STR_DRAW_SIZE	24		//フォントのサイズ
#define STR_DRAW_ROW_MAX	4	//文字列の最大行
#define STR_ROW_MAX		30		//文字行の最大値
#define STR_COL_MAX		255		//文字列の最大値
#define STR_DRAW_SPEED	1		//文字列の描画速度(何フレームごとに、１文字描画するか？)

//スタートエラー
#define START_ERR_TITLE		TEXT("スタート位置エラー")
#define START_ERR_CAPTION	TEXT("スタート位置が決まっていません")
//ゴールエラー
#define GOAL_ERR_TITLE		TEXT("ゴール位置エラー")
#define GOAL_ERR_CAPTION	TEXT("ゴール位置が決まっていません")
//閉じるボタンを押したとき
#define MSG_CLOSE_TITLE			TEXT("終了メッセージ")
#define MSG_CLOSE_CAPTION		TEXT("ゲームを終了しますか？")
//終了ダイアログ用
#define MOUSE_R_CLICK_TITLE		TEXT("ゲーム中断")
#define MOUSE_R_CLICK_CAPTION	TEXT("ゲームを中断し、タイトル画面に戻りますか？")

//画像の拡大率
#define IMAGE_TITLE_ROGO_ROTA		0.005		//拡大率
#define GAME_MENU_BTN_ROTA	1			//拡大率MAX

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
};	//ゲームのシーン

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
	/*n = -1,*/	//(NONE)未定
	GL = 0, //外の地面
	k = 10,	//床
	t = 17,	//上壁
	s = 25,	//中壁
	KABE = 28,//色の違う壁
	g = 33,	//下壁
	n = 196, // 虚無
	d = 150, // ダンボール
	m = 64, //左上ドア
	l = 65, //右上ドア
	a = 66, //左窓上
	b = 67, // 右窓上
	j = 72, //左下ドア
	o = 73, //右下ドア
	c = 74, //左窓下
	h = 75, // 右窓下
	p = 90, //ソファ
	q = 91, //ソファ
	R = 92, //ソファ
	v = 98, //ソファ
	w = 99, //ソファ
	z = 100, //ソファ
	P = 106, //机
	N = 107, //机
	O = 108, //机
	A = 149, //ゴミ箱
	B = 156, //置物
	NU = 190, //虚無
	START = 189, //外スタート
	GOAL = 221,//ゴール
	KA = 269, //隠し部屋へ
	Z = 319, //アイテムフラグ
	SB = 340,
	C = 344, //階段
	D = 345, //階段
	E = 346, //階段
	F = 352, //階段
	H = 353, //階段
	I = 354, //階段
	u = 349, //左カーペット
	e = 350, //カーペット左
	f = 351, //カーペット真ん中
	J = 360, //階段
	K = 361, //階段
	L = 362, //階段
	r = 2, //横床
	S = 198, //start
	G = 197, //goal
	M = 195, //一つ前の場所に戻る判定
	FL = 1188,
	FL2 = 1189,
	FL3 = 1190,
	FL4 = 1191,
	FE = 1192,
	FE2 = 1224,

};	//マップの種類


typedef struct STRUCT_IMAGE
{
	char path[PATH_MAX];		//パス
	int handle;					//ハンドル
	int x;						//X位置
	int y;						//Y位置
	int width;					//幅
	int height;					//高さ

}IMAGE;	//画像構造体

typedef struct STRUCT_MAP_IMAGE
{
	char path[PATH_MAX];				//パス
	int handle[MAP_NUM];			//分割したの弾の画像ハンドルを取得
	int kind[MAP_NUM];				//マップの種類
	int width;							//幅
	int height;							//高さ
}MAPCHIP;	//MAP_IMAGE構造体




typedef struct STRUCT_MUSIC
{
	char path[PATH_MAX];		//パス
	int handle;					//ハンドル
}MUSIC;	//音楽構造体

typedef struct STRUCT_MAP
{
	GAME_MAP_KIND kind;			//マップの種類
	int x;						//X位置
	int y;						//Y位置
	int width;					//幅
	int height;					//高さ
}MAP;	//MAP構造体

typedef struct STRUCT_I_POINT
{
	int x = -1;
	int y = -1;

}iPOINT;

typedef struct STRUCT_CHARA
{

	int kind1;			//画像の種類１
	int kind2;			//画像の種類２
	char path[PATH_MAX];
	IMAGE image;
	int speed;
	int CenterX;
	int CenterY;
	int handle[PLAYER_DIV_NUM];
	int Part;

	int imgChangeCnt;	//画像更新カウンタ
	int imgChangeCntMAX;//画像更新カウンタMAX値
	BOOL IsMoveNaname;	//斜め移動をしているか
	 
	RECT coll; //当たり判定
	iPOINT collBeforePt; //当たる前の判定
}CHARA;

typedef struct STRUCT_PLAYERCHIP
{
	char path[PATH_MAX];				//パス
	int handle[PLAYER_DIV_NUM];			//分割した画像ハンドルを取得
	int width;							//幅
	int height;							//高さ
}PLAYERCHIP;

typedef struct STRUCT_IMAGE_ROTA
{
	IMAGE image;		//IMAGE構造体
	double rate;		//拡大率
	double rateMAX;		//拡大率MAX

}IMAGE_ROTA;	//回転拡大する画像の構造体

enum PLAYER_KIND_1 {
	D_1, D_2, D_3,D_4,
	L_1, L_2, L_3,L_4,
	R_1, R_2, R_3,R_4,
	U_1, U_2, U_3,U_4
};//(U上/D下/R右/L左)





//マップの幅と高さを格納する
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

//マップチップの画像を管理
MAPCHIP mapChip;
MAPCHIP mapChip2;
CHARA player;
PLAYERCHIP playerChip1;

RECT mapColl[MAP_HEIGHT_MAX][MAP_WIDTH_MAX]; //マップの当たり判定

//イメージ構造体の複製
IMAGE imageBACK; //タイトル背景
IMAGE ImageSetumei; //説明画面の画像
IMAGE TextBox_start;
IMAGE TextBox_flag; //アイテム回収時のテキストボックス
IMAGE TextBox_Null; //アイテム回収していないとき
IMAGE TextBox_GenkanKagi;
IMAGE TextBox_GenkanKagiNasi;
IMAGE TextBox_Kanban; //看板
IMAGE TextBox_akanai; //鍵が合わないとき
IMAGE TextBox_kakushi; //隠し部屋のテキストボックス
IMAGE HINT_KAMI; //ヒント用紙
IMAGE_ROTA GameMenu_START; //スタートボタン
IMAGE_ROTA GameMenu_EXIT;	//終了ボタン
IMAGE_ROTA GameMenu_OPTION; //設定ボタン
IMAGE ImageSetumei_KEY_W; //各キー
IMAGE ImageSetumei_KEY_A;
IMAGE ImageSetumei_KEY_S;
IMAGE ImageSetumei_KEY_D;
IMAGE_ROTA SOUND_VOLUME;//各音量調整ボタン
IMAGE_ROTA SOUND_VOLUME1;
IMAGE_ROTA SOUND_VOLUME2;
IMAGE_ROTA SOUND_VOLUME3;
IMAGE_ROTA SOUND_VOLUME4;

IMAGE_ROTA SOUND_EFFECT;//効果音各音量調整ボタン
IMAGE_ROTA SOUND_EFFECT1;
IMAGE_ROTA SOUND_EFFECT2;
IMAGE_ROTA SOUND_EFFECT3;
IMAGE_ROTA SOUND_EFFECT4;

IMAGE_ROTA SOUND_DECISION;//決定音各音量調整ボタン
IMAGE_ROTA SOUND_DECISION1;
IMAGE_ROTA SOUND_DECISION2;
IMAGE_ROTA SOUND_DECISION3;
IMAGE_ROTA SOUND_DECISION4;

IMAGE SYBER;


iPOINT startPt{ -1, -1 }; //最初のスタートポイント
iPOINT startPt2{ -1 , -1 };//廊下のスタートポイント
iPOINT startPt3{ -1 , -1 }; //玄関がある部屋のスタートポイント
iPOINT startPt4{ -1,-1 }; //外のスタートポイント
iPOINT startPt5{ -1,-1 };//隠し部屋のスタートポイント
RECT GoalRect = { -1,-1, -1, -1 };	//最初の出口ポイント
RECT GoalRect2 = { -1, -1 , -1, -1 };//廊下の出口ポイント
RECT GoalRect3 = { -1, -1, -1, -1 };//玄関がある出口ポイント
RECT GoalRect4 = { -1,-1,-1,-1 };//外の出口ポイント
RECT Kakushi = { -1,-1,-1,-1 };//隠し部屋へ
RECT KakushiD = { -1,-1,-1,-1 };//隠し部屋からの脱出

RECT Modoru = { -1, -1, -1,-1 }; //一つ前の部屋に戻る判定
RECT Modoru2 = { -1,-1,-1,-1 };//廊下に戻る判定
RECT Itemflag = { -1,-1,-1,-1 }; //アイテムフラグの当たり判定
RECT Itemflag2 = { -1,-1,-1,-1 };//最初の部屋のフラグ判定
RECT Kanban = { -1,-1,-1,-1 }; 
iPOINT ModoruPt{ -1,-1 };
iPOINT Modoru2Pt{ -1,-1, };

//BGM
MUSIC BGM; //タイトルBGM
MUSIC ROKA;//廊下のBGM
//SE
MUSIC FLAG; //アイテム取得時の効果音※現在は没
MUSIC SERECT; //セレクト効果音
MUSIC DECISION; //決定
MUSIC SYBERB;

int GameScene;		//ゲームシーンを管理
int GameMenu = 0;	//ゲームメニューを管理
int OptionMenu = 2; //オプションシーンを管理

//キーボードの入力を取得
char AllKeyState[KEY_CODE_KIND] = { '\0' };		//すべてのキーの状態が入る
char OldAllKeyState[KEY_CODE_KIND] = { '\0' };	//すべてのキーの状態(直前)が入る

//FPS関連
int StartTimeFps;				//測定開始時刻
int CountFps;					//カウンタ
float CalcFps;					//計算結果
int SampleNumFps = GAME_FPS;	//平均を取るサンプル数
char key[256];					//キーを受け取る
int playerhandle[16];			//キャラクターのチップが入る

int count;	//フレームを取得してカウントする

int x;
int y;
int result = 0;			//ファイルの最後かチェック
int tateCnt = 0;		//縦カウント用
int yokoCnt = 0;		//横カウント用

FILE* fp = NULL; //ファイルポインタ

int flag = 0;  //アイテムフラグ
int flag2 = 0; //アイテムフラグ

//テキストボックスを表示するかの判定
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

int DrawPointX, DrawPointY;	// 文字列描画の位置
int RowPos;					// 文字列の行数
int ColPos;					// 文字列の列数
BOOL EndFlag = FALSE;		// 文字列終了フラグ
char OneMojiBuf[3];			// １文字分一時記憶配列(１文字分＋\0)
char DrawStringBuf[STR_DRAW_ROW_MAX][STR_COL_MAX];		// 描画する文字列を入れる
int DefaultFontSize;								// デフォルトのフォントサイズを取得
RECT rectString = { 0,GAME_HEIGHT - STR_DRAW_SIZE * STR_DRAW_ROW_MAX,GAME_WIDTH,GAME_HEIGHT };	// 文字列描画用エリア
int DrawSpeedCnt = 0;					//文字の描画速度カウンタ
int DrawSpeedCntMax = STR_DRAW_SPEED;	//文字の描画速度カウンタMAX

int Kaigyou(VOID);							//改行関数


char SCENARIO[STR_ROW_MAX][STR_COL_MAX] =
{
	"ある日のこと、目が覚めた主人公は見知らぬ場所にいた。B",
	"@　倉庫として使っているのかわからないが",
	"@　周りには多くのダンボールが積み重なっていた。B",
	"@　主人公はこの謎の家から出るために、探索をすることにした。B",
	"E"

};

char SCENARIO_END[STR_ROW_MAX][STR_COL_MAX] =
{
	"あの家になぜ自分は居たのかB",
	"@なぜ閉じ込められていたのか、未だに分からなかった。B",
	"@しかし、あの家には得体のしれないナニかが居るのはB",
	"@謎の雰囲気で分かった。B",
	"@その後日、気になって家があった場所へ行ったがB",
	"@そこは平地で草木が一本も生えていなかった。B",
	"E"

};



VOID MY_FPS_UPDATE(VOID);			//FPS値を計測、更新する
BOOL LOAD_IMAGE(VOID);		//画像をまとめて読み込む関数
VOID DELETE_IMAGE(VOID);		//画像をまとめて削除する関数

VOID MY_FPS_WAIT(VOID);				//FPS値を計測し、待つ

BOOL LOAD_MUSIC(VOID);		//音楽をまとめて読み込む関数
VOID DELETE_MUSIC(VOID);		//音楽をまとめて削除する関数
VOID MY_ALL_KEYDOWN_UPDATE(VOID);	//キーの入力状態を更新する
BOOL MY_KEY_DOWN(int);				//キーを押しているか、キーコードで判断する
BOOL MY_KEY_UP(int);				//キーを押し上げたか、キーコードで判断する


VOID MY_START(VOID);		//スタート画面
VOID MY_START_PROC(VOID);	//スタート画面の処理
VOID MY_START_DRAW(VOID);	//スタート画面の描画

VOID MY_SETUMEI(VOID); //説明画面
VOID MY_START_SETUMEI_DRAW(VOID); //説明画面の描画

VOID MY_SCENARIO(VOID); //シナリオ説明
VOID MY_OPTION(VOID); //設定画面(開発中)

VOID MY_PLAY_INIT(VOID);	//プレイ画面初期化
VOID MY_PLAY(VOID);			//プレイ画面
VOID MY_PLAY_PROC(VOID);	//プレイ画面の処理
VOID MY_PLAY_DRAW(VOID);	//プレイ画面の描画
VOID MY_PLAY2(VOID);		//廊下画面
VOID MY_PLAY_PROC2(VOID);   //廊下の処理
VOID MY_PLAY_DRAW2(VOID);	//廊下のステージ描画
VOID MY_PLAY3(VOID);		//最後の部屋
VOID MY_PLAY_PROC3(VOID);	//最後の部屋の処理
VOID MY_PLAY_DRAW3(VOID);	//最後の部屋の描画
VOID MY_PLAY4(VOID);		//外
VOID MY_PLAY_PROC4(VOID);	//外の処理
VOID MY_PLAY_DRAW4(VOID);	//外の描画
VOID MY_PLAY_KAKUSI(VOID); //隠し部屋
VOID MY_PLAY_PROC_KAKUSI(VOID);
VOID MY_PLAY_KAKUSHI_DRAW(VOID);

VOID MY_END(VOID);			//エンド画面
VOID MY_END_PROC(VOID);		//エンド画面の処理
VOID MY_END_DRAW(VOID);		//エンド画面の描画

VOID NovelProc(char str[][STR_COL_MAX]);	//小説文字列処理関数（引数で描画する文字列をもらう）
VOID NovelDraw(VOID);						//小説文字列描画関数

BOOL MY_CHECK_MAP1_PLAYER_COLL(RECT);	//マップとプレイヤーの当たり判定をする関数
BOOL MY_CHECK_RECT_COLL(RECT, RECT);	//領域の当たり判定をする関数
BOOL MY_CHECK_MAP2_PLAYER_COLL(RECT);   //廊下の当たり判定を設定する関数
BOOL MY_CHECK_MAP3_PLAYER_COLL(RECT);   //玄関の部屋の当たり判定を設定する関数
BOOL MY_CHECK_MAP4_PLAYER_COLL(RECT);  //外の当たり判定を設定する関数
BOOL MY_CHECK_SYBER_PLAYER_COLL(RECT); //隠し部屋の当たり判定をする関数


BOOL MY_LOAD_PLAYER(const char* path, PLAYERCHIP* player); //プレイヤーのチップを分割諸々する



int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetOutApplicationLogValidFlag(FALSE);				//Log.txtを出力しない
	ChangeWindowMode(TRUE);								//ウィンドウモードに設定
	SetGraphMode(GAME_WIDTH, GAME_HEIGHT, GAME_COLOR);	//指定の数値でウィンドウを表示する
	SetWindowStyleMode(0);				//タイトルバーはデフォルトにする
	SetAlwaysRunFlag(TRUE);								//非アクティブでも実行する
	SetMainWindowText(TITLE_NAME);								//タイトルネーム
	SetWindowIconID(444);									//ゲームアイコン
	SetWindowUserCloseEnableFlag(FALSE);				//閉じるボタンで、勝手にウィンドウが閉じないようにする




	if (DxLib_Init() == -1) { return -1; }	//ＤＸライブラリ初期化処理

	if (LOAD_IMAGE() == FALSE) { return -1; } //イメージの宣言をする関数を呼ぶ
	if (MY_LOAD_PLAYER(GAME_PLAYER_PATH, &playerChip1) == FALSE) { return -1; } //プレイヤーの分割をする関数を呼ぶ
	
	

	//音楽を読み込む
	if (LOAD_MUSIC() == FALSE) { return -1; }

	GameScene = GAME_SCENE_START;	//ゲームシーンはスタート画面から
	SetDrawScreen(DX_SCREEN_BACK);	//Draw系関数は裏画面に描画



	//###################################ここからテキストファイル読込##########################################

	fp = fopen(".\\TXT\\sakuhin_remake.txt", "r");


	if (fp == NULL) { exit(EXIT_FAILURE); }	//プログラムをエラーとして強制終了}
	int result = 0;			//ファイルの最後かチェック
	int tateCnt = 0;		//縦カウント用
	int yokoCnt = 0;		//横カウント用
	while (result != EOF)	//End Of File（ファイルの最後）ではないとき繰り返す
	{
		char mapData[MAP_WIDTH_MAX * 3 + 1];
		//ファイルから数値を一つ読み込み(%d,)、配列に格納する
		result = fscanf(fp, "%s,", mapData);
		for (int i = 0; i < strlen(mapData); i++)
		{
			switch (mapData[i])
			{
			case 'n':
				//通路のとき
				mapdata[tateCnt][yokoCnt] = n;
				yokoCnt++;
				break;
			case 'k':
				//壁のとき
				mapdata[tateCnt][yokoCnt] = k;
				yokoCnt++;
				break;
			case 'S':
				//スタートのとき
				mapdata[tateCnt][yokoCnt] = S;
				yokoCnt++;
				break;
			case 'G':
				//ゴールのとき
				mapdata[tateCnt][yokoCnt] = G;
				yokoCnt++;
				break;
			default:
				break;
			}
		}



		//横のデータが１行読めたら
		if (yokoCnt >= MAP_WIDTH_MAX)
		{
			tateCnt++;		//縦のカウントアップ
			yokoCnt = 0;	//横のカウンタ初期化
		}
	}
	fclose(fp);	//ファイルを閉じる

	result = 0;
	tateCnt = 0;
	yokoCnt = 0;

	fp = fopen(".\\TXT\\sakuhin_remake_nowalk.txt", "r");

	while (result != EOF)	//End Of File（ファイルの最後）ではないとき繰り返す
	{
		char mapData[MAP_WIDTH_MAX * 3 + 1];
		//ファイルから数値を一つ読み込み(%d,)、配列に格納する
		result = fscanf(fp, "%s,", mapData);
		for (int i = 0; i < strlen(mapData); i++)
		{
			switch (mapData[i])
			{
			case 'n':
				//通路のとき
				mapdata2[tateCnt][yokoCnt] = n;
				yokoCnt++;
				break;
			case 'k':
				//壁のとき
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
				//スタートのとき
				mapdata2[tateCnt][yokoCnt] = S;
				yokoCnt++;

				//スタート位置を計算
				startPt.x = mapChip.width * yokoCnt + mapChip.width / 2;	//中心X座標を取得
				startPt.y = mapChip.height * tateCnt + mapChip.height / 2;	//中心Y座標を取得
				break;
			case 'G':
				//ゴールのとき
				mapdata2[tateCnt][yokoCnt] = G;
				yokoCnt++;

				GoalRect.left = mapChip.width * yokoCnt;
				GoalRect.top = mapChip.height * tateCnt;
				GoalRect.right = mapChip.width * (yokoCnt + 1);
				GoalRect.bottom = mapChip.height * (tateCnt + 1);

			case 'M':
				mapdata2[tateCnt][yokoCnt] = M;
				yokoCnt++;

				ModoruPt.x = mapChip.width * yokoCnt + mapChip.width -125;	//中心X座標を取得
				ModoruPt.y = mapChip.height * tateCnt + mapChip.height -40;	//中心Y座標を取得
				
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



		//横のデータが１行読めたら
		if (yokoCnt >= MAP_WIDTH_MAX)
		{
			tateCnt++;		//縦のカウントアップ
			yokoCnt = 0;	//横のカウンタ初期化
		}
	}

	
	fclose(fp);	//ファイルを閉じる
	result = 0;
	tateCnt = 0;
	yokoCnt = 0;

	fp = fopen(".\\TXT\\sakuhin_remake_object.txt", "r");

	while (result != EOF)	//End Of File（ファイルの最後）ではないとき繰り返す
	{
		char mapData[MAP_WIDTH_MAX * 3 + 1];
		//ファイルから数値を一つ読み込み(%d,)、配列に格納する
		result = fscanf(fp, "%s,", mapData);
		for (int i = 0; i < strlen(mapData); i++)
		{
			switch (mapData[i])
			{
			case 'a':
				//通路のとき
				mapdata3[tateCnt][yokoCnt] = a;
				yokoCnt++;
				break;
			case 'b':
				//壁のとき
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
				//スタートのとき
				mapdata3[tateCnt][yokoCnt] = f;
				yokoCnt++;
				break;
			case 'd':
				//スタートのとき
				mapdata3[tateCnt][yokoCnt] = d;
				yokoCnt++;
				break;
			case 'n':
				//スタートのとき
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



		//横のデータが１行読めたら
		if (yokoCnt >= MAP_WIDTH_MAX)
		{
			tateCnt++;		//縦のカウントアップ
			yokoCnt = 0;	//横のカウンタ初期化
		}
	}

	fclose(fp);	//ファイルを閉じる



	//-----------------------廊下txt-----------------------
	result = 0;
	tateCnt = 0;
	yokoCnt = 0;

	fp = fopen(".\\TXT\\sakuhin_roka.txt", "r");

	while (result != EOF)	//End Of File（ファイルの最後）ではないとき繰り返す
	{
		char mapData[MAP_WIDTH_MAX * 3 + 1];
		//ファイルから数値を一つ読み込み(%d,)、配列に格納する
		result = fscanf(fp, "%s,", mapData);
		for (int i = 0; i < strlen(mapData); i++)
		{
			switch (mapData[i])
			{
			case 'n':
				//通路のとき
				mapdata4[tateCnt][yokoCnt] = n;
				yokoCnt++;
				break;
			case 'r':
				//壁のとき
				mapdata4[tateCnt][yokoCnt] = r;
				yokoCnt++;
				break;

			default:
				break;
			}
		}



		//横のデータが１行読めたら
		if (yokoCnt >= MAP_WIDTH_MAX)
		{
			tateCnt++;		//縦のカウントアップ
			yokoCnt = 0;	//横のカウンタ初期化
		}
	}


	fclose(fp);	//ファイルを閉じる

	result = 0;
	tateCnt = 0;
	yokoCnt = 0;

	fp = fopen(".\\TXT\\sakuhin_roka_nowalk.txt", "r");

	while (result != EOF)	//End Of File（ファイルの最後）ではないとき繰り返す
	{
		char mapData[MAP_WIDTH_MAX * 3 + 1];
		//ファイルから数値を一つ読み込み(%d,)、配列に格納する
		result = fscanf(fp, "%s,", mapData);
		for (int i = 0; i < strlen(mapData); i++)
		{
			switch (mapData[i])
			{
			case 't':
				//通路のとき
				mapdata5[tateCnt][yokoCnt] = t;
				yokoCnt++;
				break;
			case 's':
				//壁のとき
				mapdata5[tateCnt][yokoCnt] = s;
				yokoCnt++;
				break;
			case 'g':
				//壁のとき
				mapdata5[tateCnt][yokoCnt] = g;
				yokoCnt++;
				break;
			case 'n':
				//壁のとき
				mapdata5[tateCnt][yokoCnt] = n;
				yokoCnt++;
				break;

			case 'S':
				//壁のとき
				mapdata5[tateCnt][yokoCnt] = S;
				yokoCnt++;
				//スタート位置を計算
				startPt2.x = mapChip.width * yokoCnt - 30 ;	//中心X座標を取得
				startPt2.y = mapChip.height * tateCnt -20 ;	//中心Y座標を取得
				break;
			case 'G':
				//壁のとき
				mapdata5[tateCnt][yokoCnt] = G;
				yokoCnt++;
				//ゴールを計算
				GoalRect2.left = mapChip.width * yokoCnt;
				GoalRect2.top = mapChip.height * tateCnt;
				GoalRect2.right = mapChip.width * (yokoCnt + 1);
				GoalRect2.bottom = mapChip.height * (tateCnt + 1);
				break;

			case 'u':
				//壁のとき
				mapdata5[tateCnt][yokoCnt] = u;
				yokoCnt++;
				break;

			case 'M':
				mapdata5[tateCnt][yokoCnt] = M;
				yokoCnt++;

				Modoru2Pt.x = mapChip.width * yokoCnt + mapChip.width - 125;	//中心X座標を取得
				Modoru2Pt.y = mapChip.height * tateCnt + mapChip.height - 40;	//中心Y座標を取得
				break;

			case 'K':
				//壁のとき
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



		//横のデータが１行読めたら
		if (yokoCnt >= MAP_WIDTH_MAX)
		{
			tateCnt++;		//縦のカウントアップ
			yokoCnt = 0;	//横のカウンタ初期化
		}
	}

	
	fclose(fp);	//ファイルを閉じる

	result = 0;
	tateCnt = 0;
	yokoCnt = 0;

	fp = fopen(".\\TXT\\sakuhin_roka_maenimodoru.txt", "r");

	while (result != EOF)	//End Of File（ファイルの最後）ではないとき繰り返す
	{
		char mapData[MAP_WIDTH_MAX * 3 + 1];
		//ファイルから数値を一つ読み込み(%d,)、配列に格納する
		result = fscanf(fp, "%s,", mapData);
		for (int i = 0; i < strlen(mapData); i++)
		{
			switch (mapData[i])
			{
			case 'n':
				//通路のとき
				mapdata6[tateCnt][yokoCnt] = n;
				yokoCnt++;
				break;
			case 'M':
				//壁のとき
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



		//横のデータが１行読めたら
		if (yokoCnt >= MAP_WIDTH_MAX)
		{
			tateCnt++;		//縦のカウントアップ
			yokoCnt = 0;	//横のカウンタ初期化
		}
	}

	fclose(fp);	//ファイルを閉じる

	//########################部屋2#######################

	result = 0;
	tateCnt = 0;
	yokoCnt = 0;

	fp = fopen(".\\TXT\\sakuhin_heya2.txt", "r");

	while (result != EOF)	//End Of File（ファイルの最後）ではないとき繰り返す
	{
		char mapData[MAP_WIDTH_MAX * 3 + 1];
		//ファイルから数値を一つ読み込み(%d,)、配列に格納する
		result = fscanf(fp, "%s,", mapData);
		for (int i = 0; i < strlen(mapData); i++)
		{
			switch (mapData[i])
			{
			case 'n':
				//通路のとき
				mapdata7[tateCnt][yokoCnt] = n;
				yokoCnt++;
				break;
			case 'k':
				//壁のとき
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



		//横のデータが１行読めたら
		if (yokoCnt >= MAP_WIDTH_MAX)
		{
			tateCnt++;		//縦のカウントアップ
			yokoCnt = 0;	//横のカウンタ初期化
		}
	}

	//開いたら、必ず閉じること！
	fclose(fp);	//ファイルを閉じる

	result = 0;
	tateCnt = 0;
	yokoCnt = 0;

	fp = fopen(".\\TXT\\sakuhin_heya2_nowalk.txt", "r");

	while (result != EOF)	//End Of File（ファイルの最後）ではないとき繰り返す
	{
		char mapData[MAP_WIDTH_MAX * 3 + 1];
		//ファイルから数値を一つ読み込み(%d,)、配列に格納する
		result = fscanf(fp, "%s,", mapData);
		for (int i = 0; i < strlen(mapData); i++)
		{
			switch (mapData[i])
			{
			case 'n':
				//通路のとき
				mapdata8[tateCnt][yokoCnt] = n;
				yokoCnt++;
				break;
			case 's':
				//壁のとき
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

				//スタート位置をセット
				startPt3.x = mapChip.width * yokoCnt - 30;	//中心X座標を取得
				startPt3.y = mapChip.height * tateCnt - 20;	//中心Y座標を取得
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
				//壁のとき
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





		//横のデータが１行読めたら
		if (yokoCnt >= MAP_WIDTH_MAX)
		{
			tateCnt++;		//縦のカウントアップ
			yokoCnt = 0;	//横のカウンタ初期化
		}
	}


	fclose(fp);	//ファイルを閉じる

	result = 0;
	tateCnt = 0;
	yokoCnt = 0;

	fp = fopen(".\\TXT\\sakuhin_heya2_Object.txt", "r");

	while (result != EOF)	//End Of File（ファイルの最後）ではないとき繰り返す
	{
		char mapData[MAP_WIDTH_MAX * 3 + 1];
		//ファイルから数値を一つ読み込み(%d,)、配列に格納する
		result = fscanf(fp, "%s,", mapData);
		for (int i = 0; i < strlen(mapData); i++)
		{
			switch (mapData[i])
			{
			case 'n':
				//通路のとき
				mapdata9[tateCnt][yokoCnt] = n;
				yokoCnt++;
				break;
			case 'm':
				//壁のとき
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





		//横のデータが１行読めたら
		if (yokoCnt >= MAP_WIDTH_MAX)
		{
			tateCnt++;		//縦のカウントアップ
			yokoCnt = 0;	//横のカウンタ初期化
		}
	}

	//開いたら、必ず閉じること！
	fclose(fp);	//ファイルを閉じる

	result = 0;
	tateCnt = 0;
	yokoCnt = 0;

	fp = fopen(".\\TXT\\a.txt", "r");

	while (result != EOF)	//End Of File（ファイルの最後）ではないとき繰り返す
	{
		char mapData[MAP_WIDTH_MAX * 3 + 1];
		//ファイルから数値を一つ読み込み(%d,)、配列に格納する
		result = fscanf(fp, "%s,", mapData);
		for (int i = 0; i < strlen(mapData); i++)
		{
			switch (mapData[i])
			{
			
			case 'n':
				//壁のとき
				mapdata10[tateCnt][yokoCnt] = n;
				yokoCnt++;
				break;

			default:
				break;
			}
		}



		//横のデータが１行読めたら
		if (yokoCnt >= MAP_WIDTH_MAX)
		{
			tateCnt++;		//縦のカウントアップ
			yokoCnt = 0;	//横のカウンタ初期化
		}
	}

	
	fclose(fp);	//ファイルを閉じる

	result = 0;
	tateCnt = 0;
	yokoCnt = 0;

		//################################外######################################

	fp = fopen(".\\TXT\\soto.txt", "r");

	while (result != EOF)	//End Of File（ファイルの最後）ではないとき繰り返す
	{
		char mapData[MAP_WIDTH_MAX * 3 + 1];
		//ファイルから数値を一つ読み込み(%d,)、配列に格納する
		result = fscanf(fp, "%s,", mapData);
		for (int i = 0; i < strlen(mapData); i++)
		{
			switch (mapData[i])
			{

			case 'G':
				//壁のとき
				mapdata11[tateCnt][yokoCnt] = GL;
				yokoCnt++;
				break;

			default:
				break;
			}
		}



		//横のデータが１行読めたら
		if (yokoCnt >= MAP_WIDTH_MAX)
		{
			tateCnt++;		//縦のカウントアップ
			yokoCnt = 0;	//横のカウンタ初期化
		}
	}

	//開いたら、必ず閉じること！
	fclose(fp);	//ファイルを閉じる

	result = 0;
	tateCnt = 0;
	yokoCnt = 0;

	fp = fopen(".\\TXT\\soto_nowalk.txt", "r");

	while (result != EOF)	//End Of File（ファイルの最後）ではないとき繰り返す
	{
		char mapData[MAP_WIDTH_MAX * 3 + 1];
		//ファイルから数値を一つ読み込み(%d,)、配列に格納する
		result = fscanf(fp, "%s,", mapData);
		for (int i = 0; i < strlen(mapData); i++)
		{
			switch (mapData[i])
			{

			case 'N':
				//壁のとき
				mapdata12[tateCnt][yokoCnt] = NU;
				yokoCnt++;
				break;
			case 'S':
				//壁のとき
				mapdata12[tateCnt][yokoCnt] = START;
				yokoCnt++;
			
				//スタート位置をセット
				startPt4.x = mapChip2.width * yokoCnt - 30;	//中心X座標を取得
				startPt4.y = mapChip2.height * tateCnt - 20;	//中心Y座標を取得

				break;

			case'G':
				//ゴールの時
				mapdata12[tateCnt][yokoCnt] = GOAL;
				yokoCnt++;
				//ゴールの判定を設定
				GoalRect4.left = mapChip2.width * yokoCnt;
				GoalRect4.top = mapChip2.height * tateCnt;
				GoalRect4.right = mapChip2.width * (yokoCnt + 1);
				GoalRect4.bottom = mapChip2.height * (tateCnt + 1);

				break;
				

			default:
				break;
			}
		}



		//横のデータが１行読めたら
		if (yokoCnt >= MAP_WIDTH_MAX)
		{
			tateCnt++;		//縦のカウントアップ
			yokoCnt = 0;	//横のカウンタ初期化
		}
	}

	//開いたら、必ず閉じること！
	fclose(fp);	//ファイルを閉じる

	result = 0;
	tateCnt = 0;
	yokoCnt = 0;

	fp = fopen(".\\TXT\\soto_object.txt", "r");

	while (result != EOF)	//End Of File（ファイルの最後）ではないとき繰り返す
	{
		char mapData[MAP_WIDTH_MAX * 3 + 1];
		//ファイルから数値を一つ読み込み(%d,)、配列に格納する
		result = fscanf(fp, "%s,", mapData);
		for (int i = 0; i < strlen(mapData); i++)
		{
			switch (mapData[i])
			{

			case 'N':
				//壁のとき
				mapdata13[tateCnt][yokoCnt] = NU;
				yokoCnt++;
				break;

			case 'F':
				//壁のとき
				mapdata13[tateCnt][yokoCnt] = FE2;
				yokoCnt++;
				break;
			case 'E':
				//壁のとき
				mapdata13[tateCnt][yokoCnt] = FE;
				yokoCnt++;
				break;
			case 'R':
				//壁のとき
				mapdata13[tateCnt][yokoCnt] = FL;
				yokoCnt++;
				break;
			case 'L':
				//壁のとき
				mapdata13[tateCnt][yokoCnt] = FL2;
				yokoCnt++;
				break;
			case 'O':
				//壁のとき
				mapdata13[tateCnt][yokoCnt] = FL3;
				yokoCnt++;
				break;
			case 'W':
				//壁のとき
				mapdata13[tateCnt][yokoCnt] = FL4;
				yokoCnt++;
				break;
			case 'S':
				//壁のとき
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



		//横のデータが１行読めたら
		if (yokoCnt >= MAP_WIDTH_MAX)
		{
			tateCnt++;		//縦のカウントアップ
			yokoCnt = 0;	//横のカウンタ初期化
		}
	}

	//開いたら、必ず閉じること！
	fclose(fp);	//ファイルを閉じる

	//#########################隠し部屋##################################################

	result = 0;
	tateCnt = 0;
	yokoCnt = 0;

	fp = fopen(".\\TXT\\Syber.txt", "r");

	while (result != EOF)	//End Of File（ファイルの最後）ではないとき繰り返す
	{
		char mapData[MAP_WIDTH_MAX * 3 + 1];
		//ファイルから数値を一つ読み込み(%d,)、配列に格納する
		result = fscanf(fp, "%s,", mapData);
		for (int i = 0; i < strlen(mapData); i++)
		{
			switch (mapData[i])
			{

			case 'n':
				//壁のとき
				mapdata14[tateCnt][yokoCnt] = n;
				yokoCnt++;
				break;

			case 'S':
				//壁のとき
				mapdata14[tateCnt][yokoCnt] = S;
				yokoCnt++;
				//スタート位置をセット
				startPt5.x = mapChip.width * yokoCnt - 30;	//中心X座標を取得
				startPt5.y = mapChip.height * tateCnt - 20;	//中心Y座標を取得

				break;

			case 'G':
				//壁のとき
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



		//横のデータが１行読めたら
		if (yokoCnt >= MAP_WIDTH_MAX)
		{
			tateCnt++;		//縦のカウントアップ
			yokoCnt = 0;	//横のカウンタ初期化
		}
	}

	//開いたら、必ず閉じること！
	fclose(fp);	//ファイルを閉じる


	result = 0;
	tateCnt = 0;
	yokoCnt = 0;

	fp = fopen(".\\TXT\\Syber_Object.txt", "r");

	while (result != EOF)	//End Of File（ファイルの最後）ではないとき繰り返す
	{
		char mapData[MAP_WIDTH_MAX * 3 + 1];
		//ファイルから数値を一つ読み込み(%d,)、配列に格納する
		result = fscanf(fp, "%s,", mapData);
		for (int i = 0; i < strlen(mapData); i++)
		{
			switch (mapData[i])
			{

			case 'n':
				//壁のとき
				mapdata15[tateCnt][yokoCnt] = n;
				yokoCnt++;
				break;

			case 'd':
				//壁のとき
				mapdata15[tateCnt][yokoCnt] = d;
				yokoCnt++;
				break;

			default:
				break;
			}
		}



		//横のデータが１行読めたら
		if (yokoCnt >= MAP_WIDTH_MAX)
		{
			tateCnt++;		//縦のカウントアップ
			yokoCnt = 0;	//横のカウンタ初期化
		}
	}

	//開いたら、必ず閉じること！
	fclose(fp);	//ファイルを閉じる

	


	//#########################ここまでがtxtファイルの読み込み################################
				
		
	//無限ループ
	while (TRUE)
	{
		if (ProcessMessage() != 0) { break; }	//メッセージ処理の結果がエラーのとき、強制終了
		if (ClearDrawScreen() != 0) { break; }	//画面を消去できなかったとき、強制終了

		//画面の閉じるボタンを押されたとき
		if (GetWindowUserCloseFlag(TRUE))
		{
			//終了ダイアログを表示
			int Ret = MessageBox(GetMainWindowHandle(), MSG_CLOSE_CAPTION, MSG_CLOSE_TITLE, MB_YESNO | MB_ICONASTERISK);
			if (Ret == IDYES) { break; }	//YESなら、ゲームを中断する
		}

		MY_ALL_KEYDOWN_UPDATE();				//押しているキー状態を取得

		

		ChangeFontType(DX_FONTTYPE_ANTIALIASING_8X8); //アンチエイリアス

		MY_FPS_UPDATE();	//FPSの処理[更新]


		//シーンごとに処理を行う
		switch (GameScene)
		{
		case GAME_SCENE_START:
			MY_START();	//スタート画面
			break;

		case GAME_SCENE_SETUMEI:
			MY_SETUMEI(); //説明画面
			break; 

		case GAME_SCENE_SCENARIO:
			MY_SCENARIO(); //シナリオ画面
			break;

		case GAME_SCENE_OPTION:
			MY_OPTION(); //オプション画面
			break;

		case GAME_SCENE_PLAY:
			MY_PLAY();	//プレイ画面
			break;
		case GAME_SCENE_PLAY2:
			MY_PLAY2(); //廊下画面
			break;

		case GAME_SCENE_PLAY3:
			MY_PLAY3(); //玄関の部屋
			break;
		case GAME_SCENE_PLAY4:
			MY_PLAY4(); //外
			break;

		case GAME_SCENE_KAKUSI:
			MY_PLAY_KAKUSI(); //隠し部屋
			break;

		case GAME_SCENE_END:
			MY_END();	//エンド画面
			break;
		}

		

		ScreenFlip();		//モニタのリフレッシュレートの速さで裏画面を再描画

		MY_FPS_WAIT();		//FPSの処理[待つ]
	}


	//画像ハンドルを破棄
	DELETE_IMAGE();

	//音楽ハンドルを破棄
	DELETE_MUSIC();

	DxLib_End();	//ＤＸライブラリ使用の終了処理

	return 0;
}


//########## FPS値を計測、更新する関数 ##########
VOID MY_FPS_UPDATE(VOID)
{
	if (CountFps == 0) //1フレーム目なら時刻を記憶
	{
		StartTimeFps = GetNowCount();
	}

	if (CountFps == SampleNumFps) //60フレーム目なら平均を計算
	{
		int now = GetNowCount();
		//現在の時間から、0フレーム目の時間を引き、FPSの数値で割る＝1FPS辺りの平均時間が計算される
		CalcFps = 1000.f / ((now - StartTimeFps) / (float)SampleNumFps);
		CountFps = 0;
		StartTimeFps = now;
	}
	CountFps++;
	return;
}

//########## FPS値を計測し、待つ関数 ##########
VOID MY_FPS_WAIT(VOID)
{
	int resultTime = GetNowCount() - StartTimeFps;					//かかった時間
	int waitTime = CountFps * 1000 / GAME_FPS - resultTime;	//待つべき時間

	if (waitTime > 0)		//指定のFPS値よりも早い場合
	{
		WaitTimer(waitTime);	//待つ
	}
	return;
}

//########## キーの入力状態を更新する関数 ##########
VOID MY_ALL_KEYDOWN_UPDATE(VOID)
{

	//一時的に、現在のキーの入力状態を格納する
	char TempKey[KEY_CODE_KIND];

	//直前のキー入力をとっておく
	for (int i = 0; i < KEY_CODE_KIND; i++)
	{
		OldAllKeyState[i] = AllKeyState[i];
	}

	GetHitKeyStateAll(TempKey); // 全てのキーの入力状態を得る

	for (int i = 0; i < KEY_CODE_KIND; i++)
	{
		if (TempKey[i] != 0)	//押されているキーのキーコードを押しているとき
		{
			AllKeyState[i]++;	//押されている
		}
		else
		{
			AllKeyState[i] = 0;	//押されていない
		}
	}
	return;
}

//キーを押しているか、キーコードで判断する
BOOL MY_KEY_DOWN(int KEY_INPUT_)
{
	//キーコードのキーを押している時
	if (AllKeyState[KEY_INPUT_] != 0)
	{
		return TRUE;	//キーを押している
	}
	else
	{
		return FALSE;	//キーを押していない
	}
}

//キーを押し上げたか、キーコードで判断する
BOOL MY_KEY_UP(int KEY_INPUT_)
{
	if (OldAllKeyState[KEY_INPUT_] >= 1	//直前は押していて
		&& AllKeyState[KEY_INPUT_] == 0)	//今は押していないとき
	{
		return TRUE;	//キーを押し上げている
	}
	else
	{
		return FALSE;	//キーを押し上げていない
	}
}

//キーをプッシュしたか、キーコードで判断する
BOOL MY_KEY_PUSH(int KEY_INPUT_)
{
	if (OldAllKeyState[KEY_INPUT_] == 0		//直前は押していなくて
		&& AllKeyState[KEY_INPUT_] >= 1)	//今は押しているとき
	{
		return TRUE;	//キーをプッシュした（押し続けても、１回のみ発生）
	}
	else
	{
		return FALSE;	//キーをプッシュしていないか、押し続けている
	}
}

//スタート画面
VOID MY_START(VOID)
{
	MY_START_PROC();	//スタート画面の処理
	MY_START_DRAW();	//スタート画面の描画
	

	
	DrawString(0, 0, "スタート画面(エンターキーを押して下さい)", GetColor(255, 255, 255));
	return;
}

//スタート画面の処理
VOID MY_START_PROC(VOID)
{
	if (CheckSoundMem(BGM.handle) == 0)
	{
		//BGMの音量を下げる
		ChangeVolumeSoundMem(255 * 50 / 100, BGM.handle);	//50%の音量にする

		PlaySoundMem(BGM.handle, DX_PLAYTYPE_LOOP);
	}


	
	

	return;
}

//改行関数
int Kaigyou(VOID)
{
	// 描画列を最初に戻す
	DrawPointX = 0;

	DrawPointY++;	// 描画行位置を一つ下げる

	

	return 0;
}

//小説文字列処理関数
//引数で、描画させたい文字列をもらってくる
VOID NovelProc(char str[][STR_COL_MAX])
{
	switch (str[RowPos][ColPos])	//文字を１つ取得
	{
	case '@':	// 改行文字

		// 改行処理および参照文字位置を一つ進める
		Kaigyou();
		ColPos++;	//次の文字を読み取る

		break;

	case 'B':	// ボタン押し待ち文字

		//ボタンを押されたら、次の文章へ
		if (MY_KEY_DOWN(KEY_INPUT_RETURN) == TRUE) { ColPos++; }

		break;

	case 'Q':	// 質問文字

		//１ボタンを押されたとき
		if (MY_KEY_DOWN(KEY_INPUT_1) == TRUE)
		{
			//最初が1から始まる文章を探す
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

		//２ボタンを押されたとき
		if (MY_KEY_DOWN(KEY_INPUT_2) == TRUE)
		{
			//最初が2から始まる文章を探す
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

	case 'X':	// 質問から戻ってくる文字

		//ボタンを押されたら、次の文章へ
		if (MY_KEY_DOWN(KEY_INPUT_RETURN) == TRUE)
		{
			//最初がXから始まる文章を探す
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

	case 'E':	// 終了文字

		// 終了フラグを立てるおよび参照文字位置を一つ進める
		EndFlag = TRUE;
		ColPos++;	//次の文字を読み取る

		break;

	case 'C':	// クリア文字

		//描画している文字列を空にする
		for (int i = 0; i < STR_DRAW_ROW_MAX; i++)
		{
			for (int j = 0; j < STR_COL_MAX; j++)
			{
				DrawStringBuf[i][j] = '\0';
			}
		}

		//文字の位置を初期化
		DrawPointY = 0;
		DrawPointX = 0;
		ColPos++;

		break;

	default:	// その他の文字

		//描画タイミングを計算
		if (DrawSpeedCnt < DrawSpeedCntMax)
		{
			DrawSpeedCnt++;
		}
		else
		{
			// １文字分抜き出す
			OneMojiBuf[0] = str[RowPos][ColPos];
			OneMojiBuf[1] = str[RowPos][ColPos + 1];
			OneMojiBuf[2] = '\0';

			// 文字列を結合する
			strcat(DrawStringBuf[DrawPointY], OneMojiBuf);

			// 参照文字位置を２バイト進める
			ColPos += 2;

			// カーソルを一文字分進める
			DrawPointX++;

			// 画面からはみ出たら改行する
			if (DrawPointX * STR_DRAW_SIZE + STR_DRAW_SIZE > rectString.right)
			{
				Kaigyou();
			}

			DrawSpeedCnt = 0;
		}

		break;
	}

	// 参照文字列の終端まで行っていたら参照文字列を進める
	if (str[RowPos][ColPos] == '\0')
	{
		RowPos++;
		ColPos = 0;
	}

	return;
}

//小説文字列描画関数
VOID NovelDraw(VOID)
{
	//文字を描画するときは
	if (EndFlag == FALSE)
	{
		//文字列を描画
		for (int cnt = 0; cnt <= DrawPointY; cnt++)
		{
			DrawString(0, 200 + cnt * STR_DRAW_SIZE, DrawStringBuf[cnt], GetColor(255, 255, 255));
		}

	}
}

//プレイ画面(初期化)
VOID MY_PLAY_INIT(VOID)
{
	// 描画位置の初期位置セット
	DrawPointX = 0;
	DrawPointY = 0;

	// 参照文字位置をセット
	RowPos = 0;	// １行目の
	ColPos = 0;	// ０文字

	// 終了フラグを倒す
	EndFlag = FALSE;

	//デフォルトのフォントサイズを取得
	DefaultFontSize = GetFontSize();

	//文字列を空にする
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

//スタート画面の描画
VOID MY_START_DRAW(VOID)
{
	DrawGraph(imageBACK.x, imageBACK.y, imageBACK.handle, TRUE); //タイトルのバックイメージ

	//DrawGraph(400, 500, GameMenu_START.handle, TRUE); //ゲームメニューのスタートイメージ
	DrawRotaGraph(
		GameMenu_START.image.x, GameMenu_START.image.y - 50,			//画像の座標
		GameMenu_START.rate,							//画像の拡大率
		0,											//画像の回転率
		GameMenu_START.image.handle, TRUE);				//画像のハンドル
	//DrawGraph(400, 550, GameMenu_EXIT.handle, TRUE); //ゲームメニューの終了イメージ

	DrawRotaGraph(
		GameMenu_EXIT.image.x + 200, GameMenu_EXIT.image.y - 50,			//画像の座標
		GameMenu_EXIT.rate,						//画像の拡大率
		0,											//画像の回転率
		GameMenu_EXIT.image.handle, TRUE);				//画像のハンドル

	DrawRotaGraph(
		GameMenu_OPTION.image.x + 100, GameMenu_OPTION.image.y - 50,			//画像の座標
		GameMenu_OPTION.rate,						//画像の拡大率
		0,											//画像の回転率
		GameMenu_OPTION.image.handle, TRUE);				//画像のハンドル
	
	
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
					//BGMの音量を下げる
					ChangeVolumeSoundMem(255 * 60 / 100, SERECT.handle);	//60%の音量にする

					PlaySoundMem(SERECT.handle, DX_PLAYTYPE_BACK);
				}
			}

			if (MY_KEY_PUSH(KEY_INPUT_UP) == TRUE)
			{
				GameMenu = GAME_MENU_EXIT;

				if (CheckSoundMem(SERECT.handle) == 0)
				{
					//BGMの音量を下げる
					ChangeVolumeSoundMem(255 * 60 / 100, SERECT.handle);	//60%の音量にする

					PlaySoundMem(SERECT.handle, DX_PLAYTYPE_BACK);
				}
			}

			if (MY_KEY_DOWN(KEY_INPUT_RETURN) == TRUE)
			{
				if (CheckSoundMem(DECISION.handle) == 0)
				{
					//BGMの音量を下げる
					ChangeVolumeSoundMem(255 * 60 / 100, DECISION.handle);	//60%の音量にする

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
					//BGMの音量を下げる
					ChangeVolumeSoundMem(255 * 60 / 100, DECISION.handle);	//60%の音量にする
					PlaySoundMem(DECISION.handle, DX_PLAYTYPE_BACK);
				}

				DxLib_End();	//終了処理

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
						//BGMの音量を下げる
						ChangeVolumeSoundMem(255 * 60 / 100, DECISION.handle);	//60%の音量にする

					

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
	DrawString(0, 0, "オプション画面【開発中】(ESCキーを押してスタート画面に戻ります)", GetColor(255, 255, 255));
	DrawString(SOUND_VOLUME.image.x - 240, 100, "BGM音量設定", GetColor(255, 0, 0));
	DrawString(SOUND_EFFECT.image.x , 100, "SE音量設定", GetColor(255, 0, 0));
	DrawString(SOUND_DECISION.image.x + 240, 100, "決定音音量設定", GetColor(255, 0, 0));



	//BGM音量設定
	DrawRotaGraph(
		SOUND_VOLUME.image.x - 200, SOUND_VOLUME.image.y - 100,			//画像の座標
		SOUND_VOLUME.rate,						//画像の拡大率
		0,											//画像の回転率
		SOUND_VOLUME.image.handle, TRUE);				//画像のハンドル

	DrawRotaGraph(
		SOUND_VOLUME1.image.x - 200, SOUND_VOLUME1.image.y - 50,			//画像の座標
		SOUND_VOLUME1.rate,						//画像の拡大率
		0,											//画像の回転率
		SOUND_VOLUME1.image.handle, TRUE);				//画像のハンドル

	DrawRotaGraph(
		SOUND_VOLUME2.image.x - 200, SOUND_VOLUME2.image.y ,			//画像の座標
		SOUND_VOLUME2.rate,						//画像の拡大率
		0,											//画像の回転率
		SOUND_VOLUME2.image.handle, TRUE);				//画像のハンドル

	DrawRotaGraph(
		SOUND_VOLUME3.image.x - 200, SOUND_VOLUME3.image.y + 50,			//画像の座標
		SOUND_VOLUME3.rate,						//画像の拡大率
		0,											//画像の回転率
		SOUND_VOLUME3.image.handle, TRUE);				//画像のハンドル

	DrawRotaGraph(
		SOUND_VOLUME4.image.x - 200, SOUND_VOLUME4.image.y + 100,			//画像の座標
		SOUND_VOLUME4.rate,						//画像の拡大率
		0,											//画像の回転率
		SOUND_VOLUME4.image.handle, TRUE);				//画像のハンドル

	//ここまでがBGM音量設定

	//ここから効果音音量設定

	DrawRotaGraph(
		SOUND_EFFECT.image.x  + 50, SOUND_EFFECT.image.y - 100,			//画像の座標
		SOUND_EFFECT.rate,						//画像の拡大率
		0,											//画像の回転率
		SOUND_EFFECT.image.handle, TRUE);				//画像のハンドル

	DrawRotaGraph(
		SOUND_EFFECT1.image.x + 50, SOUND_EFFECT1.image.y - 50,			//画像の座標
		SOUND_EFFECT1.rate,						//画像の拡大率
		0,											//画像の回転率
		SOUND_EFFECT1.image.handle, TRUE);				//画像のハンドル

	DrawRotaGraph(
		SOUND_EFFECT2.image.x + 50, SOUND_EFFECT2.image.y,			//画像の座標
		SOUND_EFFECT2.rate,						//画像の拡大率
		0,											//画像の回転率
		SOUND_EFFECT2.image.handle, TRUE);				//画像のハンドル

	DrawRotaGraph(
		SOUND_EFFECT3.image.x + 50, SOUND_EFFECT3.image.y + 50,			//画像の座標
		SOUND_EFFECT3.rate,						//画像の拡大率
		0,											//画像の回転率
		SOUND_EFFECT3.image.handle, TRUE);				//画像のハンドル

	DrawRotaGraph(
		SOUND_EFFECT4.image.x + 50, SOUND_EFFECT4.image.y + 100,			//画像の座標
		SOUND_EFFECT4.rate,						//画像の拡大率
		0,											//画像の回転率
		SOUND_EFFECT4.image.handle, TRUE);				//画像のハンドル

	//ここまで効果音ボタン

	//ここから決定ボタン

	DrawRotaGraph(
		SOUND_DECISION.image.x + 300, SOUND_DECISION.image.y - 100,			//画像の座標
		SOUND_DECISION.rate,						//画像の拡大率
		0,											//画像の回転率
		SOUND_DECISION.image.handle, TRUE);				//画像のハンドル

	DrawRotaGraph(
		SOUND_DECISION1.image.x + 300, SOUND_DECISION1.image.y - 50,			//画像の座標
		SOUND_DECISION1.rate,						//画像の拡大率
		0,											//画像の回転率
		SOUND_DECISION1.image.handle, TRUE);				//画像のハンドル

	DrawRotaGraph(
		SOUND_DECISION2.image.x + 300, SOUND_DECISION2.image.y,			//画像の座標
		SOUND_DECISION2.rate,						//画像の拡大率
		0,											//画像の回転率
		SOUND_DECISION2.image.handle, TRUE);				//画像のハンドル

	DrawRotaGraph(
		SOUND_DECISION3.image.x + 300, SOUND_DECISION3.image.y + 50,			//画像の座標
		SOUND_DECISION3.rate,						//画像の拡大率
		0,											//画像の回転率
		SOUND_DECISION3.image.handle, TRUE);				//画像のハンドル

	DrawRotaGraph(
		SOUND_DECISION4.image.x + 300, SOUND_DECISION4.image.y + 100,			//画像の座標
		SOUND_DECISION4.rate,						//画像の拡大率
		0,											//画像の回転率
		SOUND_DECISION4.image.handle, TRUE);				//画像のハンドル




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

					// 音量の設定
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

					// 音量の設定
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


					// 音量の設定
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


					// 音量の設定
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


					// 音量の設定
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


					// 音量の設定
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


					// 音量の設定
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


					// 音量の設定
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


					// 音量の設定
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


					// 音量の設定
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


					// 音量の設定
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


					// 音量の設定
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


					// 音量の設定
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


					// 音量の設定
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


					// 音量の設定
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
	MY_START_SETUMEI_DRAW();//説明画面の描画
}
//説明画面の描画
VOID MY_START_SETUMEI_DRAW(VOID)
{
	DrawGraph(ImageSetumei.x, ImageSetumei.y, ImageSetumei.handle, TRUE); //説明画像
	DrawString(0, 0, "スタート画面(ゼロ(0)キーを押して下さい)", GetColor(255, 255, 255));

	if(MY_KEY_DOWN(KEY_INPUT_W) == TRUE) //キー画像を赤くする
	{
		KEY_W = true;
		KEY_A = false;
		KEY_S = false;
		KEY_D = false;
		
	
	}

	if (MY_KEY_DOWN(KEY_INPUT_A) == TRUE) //キー画像を赤くする
	{
		KEY_W = false;
		KEY_A = true;
		KEY_S = false;
		KEY_D = false;

	}

	if (MY_KEY_DOWN(KEY_INPUT_S) == TRUE) //キー画像を赤くする
	{
		KEY_W = false;
		KEY_A = false;
		KEY_S = true;
		KEY_D = false;

	}

	if (MY_KEY_DOWN(KEY_INPUT_D) == TRUE) //キー画像を赤くする
	{
		KEY_W = false;
		KEY_A = false;
		KEY_S = false;
		KEY_D = true;
	}

	if (KEY_W == true) //trueであるとき、赤くする
	{
		DrawGraph(ImageSetumei_KEY_W.x, ImageSetumei_KEY_W.y, ImageSetumei_KEY_W.handle, TRUE);
	}

	if (MY_KEY_DOWN(KEY_INPUT_W) == FALSE)//falseであるとき、赤く光っているのを解除する
	{
		KEY_W = false;
	}

	if (KEY_A == true)//trueであるとき、赤くする
	{
		DrawGraph(ImageSetumei_KEY_A.x, ImageSetumei_KEY_A.y, ImageSetumei_KEY_A.handle, TRUE);
	}

	if (MY_KEY_DOWN(KEY_INPUT_A) == FALSE) //falseであるとき、赤く光っているのを解除する
	{
		KEY_A = false;
	}

	if (KEY_S == true)//trueであるとき、赤くする
	{
		DrawGraph(ImageSetumei_KEY_S.x, ImageSetumei_KEY_S.y, ImageSetumei_KEY_S.handle, TRUE);
	}

	if (MY_KEY_DOWN(KEY_INPUT_S) == FALSE)//falseであるとき、赤く光っているのを解除する
	{
		KEY_S = false;
	}

	if (KEY_D == true)//trueであるとき、赤くする
	{
		DrawGraph(ImageSetumei_KEY_D.x, ImageSetumei_KEY_D.y, ImageSetumei_KEY_D.handle, TRUE);
	}

	if (MY_KEY_DOWN(KEY_INPUT_D) == FALSE)//falseであるとき、赤く光っているのを解除する
	{
		KEY_D = false;
	}



	if (MY_KEY_DOWN(KEY_INPUT_0) == TRUE) //シナリオシーンへ遷移
	{
		//プレイ画面を初期化
		MY_PLAY_INIT();
		
		GameScene = GAME_SCENE_SCENARIO;
		
	}
	
	


	return;
}

VOID MY_SCENARIO(VOID)
{
	if (EndFlag == FALSE)
	{
		//小説文字列描画
		NovelProc(SCENARIO);
	}

	//文字列を描画
	NovelDraw();

	if (EndFlag == TRUE)
	{
		SetFontSize(STR_DRAW_SIZE); //フォントサイズ24
		DrawString(0, 200, "エスケープキー(ESC)を押して下さい", GetColor(255, 255, 255));
		
	}


	if (MY_KEY_DOWN(KEY_INPUT_ESCAPE) == TRUE || MY_KEY_DOWN(KEY_INPUT_6) == TRUE) //プレイ画面へ遷移
	{
		SetFontSize(DefaultFontSize); //デフォルトにする

		if (CheckSoundMem(BGM.handle) != 0)
		{
			StopSoundMem(BGM.handle);	//BGMを止める
		}
		GameScene = GAME_SCENE_PLAY;

		SetMouseDispFlag(FALSE);

		//プレイヤーの位置を設定
		player.CenterX = startPt.x;
		player.CenterY = startPt.y;


		player.image.x = player.CenterX;
		player.image.y = player.CenterY;


	}
}

//プレイ画面
VOID MY_PLAY(VOID)
{
	MY_PLAY_PROC();	//プレイ画面の処理
	MY_PLAY_DRAW();	//プレイ画面の描画
	return;
}

//プレイ画面の処理
VOID MY_PLAY_PROC(VOID)
{
	
	
	count++;
	//スペースキーを押したら、エンドシーンへ移動する
	if (MY_KEY_DOWN(KEY_INPUT_SPACE) == TRUE)
	{
		//ゲームのシーンをエンド画面にする
		GameScene = GAME_SCENE_END;

		return;
	}

	//マウスを右クリックすると、タイトル画面に戻る
	if (MY_KEY_DOWN(KEY_INPUT_L) == TRUE)
	{
		

		//マウスを表示
		SetMouseDispFlag(TRUE);

		//終了ダイアログを表示
		int Ret = MessageBox(GetMainWindowHandle(), MOUSE_R_CLICK_CAPTION, MOUSE_R_CLICK_TITLE, MB_YESNO);

		if (Ret == IDYES)		//YESなら、ゲームを中断する
		{
			//強制的にタイトル画面に飛ぶ
			GameScene = GAME_SCENE_START;
			return;

		}
		else if (Ret == IDNO)	//NOなら、ゲームを続行する
		{

			//マウスを非表示にする。
			SetMouseDispFlag(FALSE);
		}
	}

	player.kind1 = D_1; //何も押していないときのプレイヤーの向き
	int old_x = player.image.x; //当たり判定時、前に居た位置へ戻る
	int old_y = player.image.y;
	BOOL IsMove = TRUE; //移動可能


	//上に移動するとき
	if (MY_KEY_DOWN(KEY_INPUT_W) == TRUE
		&& MY_KEY_DOWN(KEY_INPUT_D) == FALSE
		&& MY_KEY_DOWN(KEY_INPUT_S) == FALSE
		&& MY_KEY_DOWN(KEY_INPUT_A) == FALSE)
	{
		player.IsMoveNaname = FALSE;	//斜め移動していない

		if (player.kind1 >= U_1 && player.kind1 < U_4)
		{
			//画像変更カウンタ
			if (player.imgChangeCnt < player.imgChangeCntMAX)
			{
				player.imgChangeCnt++;
			}
			else //画像を変えるタイミングになったら
			{
				player.kind1++;			//次の画像にする
				player.imgChangeCnt = 0;	//変更カウンタ初期化
			}
		}
		else
		{
			player.kind1 = U_1;	//最初の画像にする
		}

		player.image.y -= 1.5;	//移動
	}

	//右に移動するとき
	if (MY_KEY_DOWN(KEY_INPUT_W) == FALSE
		&& MY_KEY_DOWN(KEY_INPUT_D) == TRUE
		&& MY_KEY_DOWN(KEY_INPUT_S) == FALSE
		&& MY_KEY_DOWN(KEY_INPUT_A) == FALSE)
	{
		player.IsMoveNaname = FALSE;	//斜め移動していない

		if (player.kind1 >= R_1 && player.kind1 < R_4)
		{
			//画像変更カウンタ
			if (player.imgChangeCnt < player.imgChangeCntMAX)
			{
				player.imgChangeCnt++;
			}
			else //画像を変えるタイミングになったら
			{
				player.kind1++;			//次の画像にする
				player.imgChangeCnt = 0;	//変更カウンタ初期化
			}
		}
		else
		{
			player.kind1 = R_1;	//最初の画像にする
		}
		player.image.x += 2;	//移動
	}

	//左に移動するとき
	if (MY_KEY_DOWN(KEY_INPUT_W) == FALSE
		&& MY_KEY_DOWN(KEY_INPUT_D) == FALSE
		&& MY_KEY_DOWN(KEY_INPUT_S) == FALSE
		&& MY_KEY_DOWN(KEY_INPUT_A) == TRUE)
	{
		player.IsMoveNaname = FALSE;	//斜め移動していない

		if (player.kind1 >= L_1 && player.kind1 < L_4)
		{
			//画像変更カウンタ
			if (player.imgChangeCnt < player.imgChangeCntMAX)
			{
				player.imgChangeCnt++;
			}
			else //画像を変えるタイミングになったら
			{
				player.kind1++;			//次の画像にする
				player.imgChangeCnt = 0;	//変更カウンタ初期化
			}
		}
		else
		{
			player.kind1 = L_1;	//最初の画像にする
		}
		player.image.x -= 1.5;	//移動
	}

	//下に移動するとき
	if (MY_KEY_DOWN(KEY_INPUT_W) == FALSE
		&& MY_KEY_DOWN(KEY_INPUT_D) == FALSE
		&& MY_KEY_DOWN(KEY_INPUT_S) == TRUE
		&& MY_KEY_DOWN(KEY_INPUT_A) == FALSE)
	{
		player.IsMoveNaname = FALSE;	//斜め移動していない

		if (player.kind1 >= D_1 && player.kind1 < D_4)
		{
			//画像変更カウンタ
			if (player.imgChangeCnt < player.imgChangeCntMAX)
			{
				player.imgChangeCnt++;
			}
			else //画像を変えるタイミングになったら
			{
				player.kind1++;			//次の画像にする
				player.imgChangeCnt = 0;	//変更カウンタ初期化
			}
		}
		else
		{
			player.kind1 = D_1;	//最初の画像にする
		}
		player.image.y += 2;	//移動
	}

	//画面内にマウスがいれば
		if (player.image.x >= 0 && player.image.x <= GAME_WIDTH
			&& player.image.y >= 0 && player.image.y <= GAME_HEIGHT)
		{
			//プレイヤーの中心位置を設定する
			player.CenterX = player.image.x;
			player.CenterY = player.image.y;
		}

		//プレイヤーの当たり判定の設定
		player.coll.left = player.CenterX - 40 / 20 + 5;
		player.coll.top = player.CenterY + 200 / 20 + 5;
		player.coll.right = player.CenterX + 650 / 20 - 5;
		player.coll.bottom = player.CenterY + 1000 / 20 - 5;

		RECT PlayerRect;
		PlayerRect.left = player.CenterX - 40 / 20 + 5;
		PlayerRect.top = player.CenterY + 200 / 20 + 5;
		PlayerRect.right = player.CenterX + 650 / 20 - 5;
		PlayerRect.bottom = player.CenterY + 1000 / 20 - 5;

		//ゴールに触れているかチェック
		if (MY_CHECK_RECT_COLL(PlayerRect, GoalRect) == TRUE)
		{

			
			
			//廊下のスタートポイントに設定し遷移
			player.CenterX = startPt2.x;
			player.CenterY = startPt2.y;


			player.image.x = player.CenterX;
			player.image.y = player.CenterY;

			GameScene = GAME_SCENE_PLAY2;

		

			return;	//強制的にエンド画面に飛ぶ
		}

		//プレイヤーが画面外に出たら
		/*if (player.image.x > GAME_WIDTH || player.image.y > GAME_HEIGHT
			|| player.image.x + player.image.width < 0 || player.image.y + player.image.height < 0)
		{
			
			IsMove = false;
			
		}*/

	

		

		//プレイヤーとマップがあたっていたら
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
				////プレイヤーの位置に置き換える
				//player.image.x = player.CenterX - player.image.width / 2;
				//player.image.y = player.CenterY - player.image.height / 2;

				//あたっていないときの座標を取得
				player.collBeforePt.x = player.CenterX;
				player.collBeforePt.y = player.CenterY;
			}
		}

		
	
	

	return;
}

//プレイ画面の描画
VOID MY_PLAY_DRAW(VOID)
{

	//マップの描画
	

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

			//虚無のとき
			DrawGraph(yoko * mapChip.width,
				tate * mapChip.height,
				mapChip.handle[mapdata3[tate][yoko]],
				TRUE);


		}

	}


	//当たり判定の描画（デバッグ用）
	for (int tate = 0; tate < MAP_HEIGHT_MAX; tate++)
	{
		for (int yoko = 0; yoko < MAP_WIDTH_MAX; yoko++)
		{
			//ダンボールならば
			/*if (mapdata3[tate][yoko] == d)
			{
				DrawBox(mapColl[tate][yoko].left, mapColl[tate][yoko].top, mapColl[tate][yoko].right, mapColl[tate][yoko].bottom, GetColor(255, 0, 0), FALSE);
			}
			//出口ならば
			if (mapdata2[tate][yoko] == Z)
			{
				DrawBox(mapColl[tate][yoko].left, mapColl[tate][yoko].top, mapColl[tate][yoko].right, mapColl[tate][yoko].bottom, GetColor(255, 0, 0), FALSE);
			}*/

		}
	}

	//ゴール当たり判定用
	//DrawBox(GoalRect.left, GoalRect.top, GoalRect.right, GoalRect.bottom, GetColor(255, 255, 0), TRUE);
	//プレイヤーの当たり判定用
	/*DrawBox(player.coll.left, player.coll.top, player.coll.right, player.coll.bottom, GetColor(255, 0, 0), FALSE);*/

	//現在は没の予定
	//DrawGraph(TEXT_WIDTH_POSITION, TEXT_HEIGHT_POSITION, TextBox_start.handle, TRUE);
	//if (MY_KEY_DOWN(KEY_INPUT_RETURN) == TRUE)
	//{
	//	DeleteGraph(TextBox_start.handle);
	//}
	
	//プレイヤーの描画
		DrawGraph(player.image.x, player.image.y, playerChip1.handle[player.kind1], TRUE);

		RECT PlayerRect;
		PlayerRect.left = player.CenterX - 40 / 20 + 5;
		PlayerRect.top = player.CenterY + 200 / 20 + 5;
		PlayerRect.right = player.CenterX + 650 / 20 - 5;
		PlayerRect.bottom = player.CenterY + 1000 / 20 - 5;

	
		//フラグを回収しているかどうかのイベント
		if (MY_CHECK_RECT_COLL(PlayerRect, Itemflag2) == TRUE && flag == 1 && MY_KEY_PUSH(KEY_INPUT_RETURN) == TRUE)
		{
			flag2 = 1;
			hyouji2 = true;

			if (CheckSoundMem(FLAG.handle) == 0)
			{
				//BGMの音量を下げる
				ChangeVolumeSoundMem(255 * 50 / 100, FLAG.handle);	//50%の音量にする

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

		
		//鍵を取得していないとき
		if (MY_CHECK_RECT_COLL(PlayerRect, Itemflag2) == TRUE && flag == 0 && MY_KEY_PUSH(KEY_INPUT_RETURN) == TRUE)
		{
			hyouji = true;
			
		}
		//テキストボックスを表示する
		if (hyouji == true)
		{
			DrawGraph(TEXT_WIDTH_POSITION, TEXT_HEIGHT_POSITION, TextBox_GenkanKagiNasi.handle, TRUE);

			if (MY_KEY_PUSH(KEY_INPUT_ESCAPE) == TRUE)
			{
				hyouji = false;
			}

		}

		DrawString(0, 0, "テキストボックスはESCキーで閉じることができます。", GetColor(255, 255, 255));

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

	//廊下のBGM
	if (CheckSoundMem(ROKA.handle) == 0)
	{
		//BGMの音量を下げる
		ChangeVolumeSoundMem(255 * 50 / 100, ROKA.handle);	//50%の音量にする

		PlaySoundMem(ROKA.handle, DX_PLAYTYPE_LOOP);
	}

	
	//マウスを右クリックすると、タイトル画面に戻る
	if (MY_KEY_DOWN(KEY_INPUT_L) == TRUE)
	{


		//マウスを表示
		SetMouseDispFlag(TRUE);

		//終了ダイアログを表示
		int Ret = MessageBox(GetMainWindowHandle(), MOUSE_R_CLICK_CAPTION, MOUSE_R_CLICK_TITLE, MB_YESNO);

		if (Ret == IDYES)		//YESなら、ゲームを中断する
		{
			//強制的にタイトル画面に飛ぶ
			GameScene = GAME_SCENE_START;
			return;

		}
		else if (Ret == IDNO)	//NOなら、ゲームを続行する
		{

			//マウスを非表示にする。
			SetMouseDispFlag(FALSE);
		}
	}



	player.kind1 = D_1; //何も押していないときのプレイヤーの向き
	int old_x = player.image.x; //当たり判定時
	int old_y = player.image.y;
	BOOL IsMove = TRUE; //動けます


	//上に移動するとき
	if (MY_KEY_DOWN(KEY_INPUT_W) == TRUE
		&& MY_KEY_DOWN(KEY_INPUT_D) == FALSE
		&& MY_KEY_DOWN(KEY_INPUT_S) == FALSE
		&& MY_KEY_DOWN(KEY_INPUT_A) == FALSE)
	{
		player.IsMoveNaname = FALSE;	//斜め移動していない

		if (player.kind1 >= U_1 && player.kind1 < U_4)
		{
			//画像変更カウンタ
			if (player.imgChangeCnt < player.imgChangeCntMAX)
			{
				player.imgChangeCnt++;
			}
			else //画像を変えるタイミングになったら
			{
				player.kind1++;			//次の画像にする
				player.imgChangeCnt = 0;	//変更カウンタ初期化
			}
		}
		else
		{
			player.kind1 = U_1;	//最初の画像にする
		}

		player.image.y -= 1.5;	//移動
	}

	//右に移動するとき
	if (MY_KEY_DOWN(KEY_INPUT_W) == FALSE
		&& MY_KEY_DOWN(KEY_INPUT_D) == TRUE
		&& MY_KEY_DOWN(KEY_INPUT_S) == FALSE
		&& MY_KEY_DOWN(KEY_INPUT_A) == FALSE)
	{
		player.IsMoveNaname = FALSE;	//斜め移動していない

		if (player.kind1 >= R_1 && player.kind1 < R_4)
		{
			//画像変更カウンタ
			if (player.imgChangeCnt < player.imgChangeCntMAX)
			{
				player.imgChangeCnt++;
			}
			else //画像を変えるタイミングになったら
			{
				player.kind1++;			//次の画像にする
				player.imgChangeCnt = 0;	//変更カウンタ初期化
			}
		}
		else
		{
			player.kind1 = R_1;	//最初の画像にする
		}
		player.image.x += 2;	//移動
	}

	//左に移動するとき
	if (MY_KEY_DOWN(KEY_INPUT_W) == FALSE
		&& MY_KEY_DOWN(KEY_INPUT_D) == FALSE
		&& MY_KEY_DOWN(KEY_INPUT_S) == FALSE
		&& MY_KEY_DOWN(KEY_INPUT_A) == TRUE)
	{
		player.IsMoveNaname = FALSE;	//斜め移動していない

		if (player.kind1 >= L_1 && player.kind1 < L_4)
		{
			//画像変更カウンタ
			if (player.imgChangeCnt < player.imgChangeCntMAX)
			{
				player.imgChangeCnt++;
			}
			else //画像を変えるタイミングになったら
			{
				player.kind1++;			//次の画像にする
				player.imgChangeCnt = 0;	//変更カウンタ初期化
			}
		}
		else
		{
			player.kind1 = L_1;	//最初の画像にする
		}
		player.image.x -= 1.5;	//移動
	}

	//下に移動するとき
	if (MY_KEY_DOWN(KEY_INPUT_W) == FALSE
		&& MY_KEY_DOWN(KEY_INPUT_D) == FALSE
		&& MY_KEY_DOWN(KEY_INPUT_S) == TRUE
		&& MY_KEY_DOWN(KEY_INPUT_A) == FALSE)
	{
		player.IsMoveNaname = FALSE;	//斜め移動していない

		if (player.kind1 >= D_1 && player.kind1 < D_4)
		{
			//画像変更カウンタ
			if (player.imgChangeCnt < player.imgChangeCntMAX)
			{
				player.imgChangeCnt++;
			}
			else //画像を変えるタイミングになったら
			{
				player.kind1++;			//次の画像にする
				player.imgChangeCnt = 0;	//変更カウンタ初期化
			}
		}
		else
		{
			player.kind1 = D_1;	//最初の画像にする
		}
		player.image.y += 2;	//移動
	}


//画面内にキャラがいれば
	if (player.image.x >= 0 && player.image.x <= GAME_WIDTH
		&& player.image.y >= 0 && player.image.y <= GAME_HEIGHT)
	{
		//プレイヤーの中心位置を設定する
		player.CenterX = player.image.x;
		player.CenterY = player.image.y;
	}

	//プレイヤーの当たり判定の設定
	player.coll.left = player.CenterX - 40 / 20 + 5;
	player.coll.top = player.CenterY + 200 / 20 + 5;
	player.coll.right = player.CenterX + 650 / 20 - 5;
	player.coll.bottom = player.CenterY + 1000 / 20 - 5;

	RECT PlayerRect;
	PlayerRect.left = player.CenterX - 40 / 20 + 5;
	PlayerRect.top = player.CenterY + 200 / 20 + 5;
	PlayerRect.right = player.CenterX + 650 / 20 - 5;
	PlayerRect.bottom = player.CenterY + 1000 / 20 - 5;
	
	

		//ゴールに触れているかチェック
	if (MY_CHECK_RECT_COLL(PlayerRect, GoalRect2) == TRUE)
	{
		//玄関の部屋へ遷移

			player.CenterX = startPt3.x;
			player.CenterY = startPt3.y;


			player.image.x = player.CenterX;
			player.image.y = player.CenterY;



			GameScene = GAME_SCENE_PLAY3;
		

		return;	//強制的にエンド画面に飛ぶ
	}

	if (MY_CHECK_RECT_COLL(PlayerRect, Modoru) == TRUE)
	{

		//前の部屋に戻るための当たり判定、前の部屋に戻る

		player.CenterX = ModoruPt.x;
		player.CenterY = ModoruPt.y;


		player.image.x = player.CenterX;
		player.image.y = player.CenterY;

		if (CheckSoundMem(ROKA.handle) != 0)
		{
			StopSoundMem(ROKA.handle);	//BGMを止める
		}

		GameScene = GAME_SCENE_PLAY;


		return;	//強制的にエンド画面に飛ぶ
	}

	//全てを満たしているかチェック
	if (MY_CHECK_RECT_COLL(PlayerRect, Kakushi) == TRUE && MY_KEY_DOWN(KEY_INPUT_RETURN) == TRUE /*&& flag2 == true*/)
	{

		player.CenterX = startPt5.x;
		player.CenterY = startPt5.y;


		player.image.x = player.CenterX;
		player.image.y = player.CenterY;

		if (CheckSoundMem(ROKA.handle) != 0)
		{
			StopSoundMem(ROKA.handle);	//BGMを止める
		}

		//隠し部屋へ
		GameScene = GAME_SCENE_KAKUSI;


		return;
	}


	//プレイヤーが画面外に出たら
	/*if (player.image.x > GAME_WIDTH || player.image.y > GAME_HEIGHT
		|| player.image.x + player.image.width < 0 || player.image.y + player.image.height < 0)
	{

		IsMove = false;

	}*/





	//プレイヤーとマップがあたっていたら
	if (MY_CHECK_MAP2_PLAYER_COLL(player.coll) == TRUE)
	{
		
		IsMove = false;


	}

	if (IsMove == false)
	{
		//当たる前に戻る
		player.image.x = old_x;
		player.image.y = old_y;
	}


	if (IsMove == TRUE)
	{

		{
			////プレイヤーの位置に置き換える
			//player.image.x = player.CenterX - player.image.width / 2;
			//player.image.y = player.CenterY - player.image.height / 2;

			//あたっていないときの座標を取得
			player.collBeforePt.x = player.CenterX;
			player.collBeforePt.y = player.CenterY;
		}
	}

	return;
}

VOID MY_PLAY_DRAW2(VOID)
{
	//マップを描画

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

	//プレイヤーの描画
	DrawGraph(player.image.x, player.image.y, playerChip1.handle[player.kind1], TRUE);

	//当たり判定の描画（デバッグ用）
	for (int tate = 0; tate < MAP_HEIGHT_MAX; tate++)
	{
		for (int yoko = 0; yoko < MAP_WIDTH_MAX; yoko++)
		{

			//一つ前に戻る判定
			if (mapdata6[tate][yoko] == M)
			{
			/*	DrawBox(mapColl[tate][yoko].left, mapColl[tate][yoko].top, mapColl[tate][yoko].right, mapColl[tate][yoko].bottom, GetColor(255, 0, 0), FALSE);*/
			}

		}
	}
	//ゴール当たり判定用
	/*DrawBox(GoalRect2.left, GoalRect2.top, GoalRect2.right, GoalRect2.bottom, GetColor(255, 255, 0), TRUE);*/
	//プレイヤーの当たり判定用
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

	//マウスを右クリックすると、タイトル画面に戻る
	if (MY_KEY_DOWN(KEY_INPUT_L) == TRUE)
	{


		//マウスを表示
		SetMouseDispFlag(TRUE);

		//終了ダイアログを表示
		int Ret = MessageBox(GetMainWindowHandle(), MOUSE_R_CLICK_CAPTION, MOUSE_R_CLICK_TITLE, MB_YESNO);

		if (Ret == IDYES)		//YESなら、ゲームを中断する
		{
			//強制的にタイトル画面に飛ぶ
			GameScene = GAME_SCENE_START;
			return;

		}
		else if (Ret == IDNO)	//NOなら、ゲームを続行する
		{

			//マウスを非表示にする。
			SetMouseDispFlag(FALSE);
		}
	}

	player.kind1 = D_1; //何も押していないときのプレイヤの向き
	int old_x = player.image.x; //当たり判定用
	int old_y = player.image.y;
	BOOL IsMove = TRUE;


	//上に移動するとき
	if (MY_KEY_DOWN(KEY_INPUT_W) == TRUE
		&& MY_KEY_DOWN(KEY_INPUT_D) == FALSE
		&& MY_KEY_DOWN(KEY_INPUT_S) == FALSE
		&& MY_KEY_DOWN(KEY_INPUT_A) == FALSE)
	{
		player.IsMoveNaname = FALSE;	//斜め移動していない

		if (player.kind1 >= U_1 && player.kind1 < U_4)
		{
			//画像変更カウンタ
			if (player.imgChangeCnt < player.imgChangeCntMAX)
			{
				player.imgChangeCnt++;
			}
			else //画像を変えるタイミングになったら
			{
				player.kind1++;			//次の画像にする
				player.imgChangeCnt = 0;	//変更カウンタ初期化
			}
		}
		else
		{
			player.kind1 = U_1;	//最初の画像にする
		}

		player.image.y -= 1.5;	//移動
	}

	//右に移動するとき
	if (MY_KEY_DOWN(KEY_INPUT_W) == FALSE
		&& MY_KEY_DOWN(KEY_INPUT_D) == TRUE
		&& MY_KEY_DOWN(KEY_INPUT_S) == FALSE
		&& MY_KEY_DOWN(KEY_INPUT_A) == FALSE)
	{
		player.IsMoveNaname = FALSE;	//斜め移動していない

		if (player.kind1 >= R_1 && player.kind1 < R_4)
		{
			//画像変更カウンタ
			if (player.imgChangeCnt < player.imgChangeCntMAX)
			{
				player.imgChangeCnt++;
			}
			else //画像を変えるタイミングになったら
			{
				player.kind1++;			//次の画像にする
				player.imgChangeCnt = 0;	//変更カウンタ初期化
			}
		}
		else
		{
			player.kind1 = R_1;	//最初の画像にする
		}
		player.image.x += 2;	//移動
	}

	//左に移動するとき
	if (MY_KEY_DOWN(KEY_INPUT_W) == FALSE
		&& MY_KEY_DOWN(KEY_INPUT_D) == FALSE
		&& MY_KEY_DOWN(KEY_INPUT_S) == FALSE
		&& MY_KEY_DOWN(KEY_INPUT_A) == TRUE)
	{
		player.IsMoveNaname = FALSE;	//斜め移動していない

		if (player.kind1 >= L_1 && player.kind1 < L_4)
		{
			//画像変更カウンタ
			if (player.imgChangeCnt < player.imgChangeCntMAX)
			{
				player.imgChangeCnt++;
			}
			else //画像を変えるタイミングになったら
			{
				player.kind1++;			//次の画像にする
				player.imgChangeCnt = 0;	//変更カウンタ初期化
			}
		}
		else
		{
			player.kind1 = L_1;	//最初の画像にする
		}
		player.image.x -= 1.5;	//移動
	}

	//下に移動するとき
	if (MY_KEY_DOWN(KEY_INPUT_W) == FALSE
		&& MY_KEY_DOWN(KEY_INPUT_D) == FALSE
		&& MY_KEY_DOWN(KEY_INPUT_S) == TRUE
		&& MY_KEY_DOWN(KEY_INPUT_A) == FALSE)
	{
		player.IsMoveNaname = FALSE;	//斜め移動していない

		if (player.kind1 >= D_1 && player.kind1 < D_4)
		{
			//画像変更カウンタ
			if (player.imgChangeCnt < player.imgChangeCntMAX)
			{
				player.imgChangeCnt++;
			}
			else //画像を変えるタイミングになったら
			{
				player.kind1++;			//次の画像にする
				player.imgChangeCnt = 0;	//変更カウンタ初期化
			}
		}
		else
		{
			player.kind1 = D_1;	//最初の画像にする
		}
		player.image.y += 2;	//移動
	}

//画面内にキャラがいれば
	if (player.image.x >= 0 && player.image.x <= GAME_WIDTH
		&& player.image.y >= 0 && player.image.y <= GAME_HEIGHT)
	{
		//プレイヤーの中心位置を設定する
		player.CenterX = player.image.x;
		player.CenterY = player.image.y;
	}

	//プレイヤーの当たり判定の設定
	player.coll.left = player.CenterX - 40 / 20 + 5;
	player.coll.top = player.CenterY + 200 / 20 + 5;
	player.coll.right = player.CenterX + 650 / 20 - 5;
	player.coll.bottom = player.CenterY + 1000 / 20 - 5;

	RECT PlayerRect;
	PlayerRect.left = player.CenterX - 40 / 20 + 5;
	PlayerRect.top = player.CenterY + 200 / 20 + 5;
	PlayerRect.right = player.CenterX + 650 / 20 - 5;
	PlayerRect.bottom = player.CenterY + 1000 / 20 - 5;



	//ゴールに触れているかチェック
	if (MY_CHECK_RECT_COLL(PlayerRect, GoalRect3) == TRUE && flag2 == 1)
	{

		//外へ遷移する

		player.CenterX = startPt4.x;
		player.CenterY = startPt4.y;


		player.image.x = player.CenterX;
		player.image.y = player.CenterY;


		GameScene = GAME_SCENE_PLAY4;


		return;
	}



	if (MY_CHECK_RECT_COLL(PlayerRect, Modoru2) == TRUE)
	{

		//廊下に戻る判定

		player.CenterX = Modoru2Pt.x;
		player.CenterY = Modoru2Pt.y;


		player.image.x = player.CenterX + 100;
		player.image.y = player.CenterY;

		GameScene = GAME_SCENE_PLAY2;


		return;	//強制的にエンド画面に飛ぶ
	}


	


	//プレイヤーとマップがあたっていたら
	if (MY_CHECK_MAP3_PLAYER_COLL(player.coll) == TRUE)
	{
		//動けません
		IsMove = false;


	}

	if (IsMove == false)
	{
		player.image.x = old_x; //当たる前に戻る
		player.image.y = old_y;
	}


	if (IsMove == TRUE)
	{

		{
			////プレイヤーの位置に置き換える
			//player.image.x = player.CenterX - player.image.width / 2;
			//player.image.y = player.CenterY - player.image.height / 2;

			//あたっていないときの座標を取得
			player.collBeforePt.x = player.CenterX;
			player.collBeforePt.y = player.CenterY;
		}
	}

	return;
}

VOID MY_PLAY_DRAW3(VOID)
{

	//マップを描画する
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

			//虚無のとき
			DrawGraph(yoko * mapChip.width,
				tate * mapChip.height,
				mapChip.handle[mapdata9[tate][yoko]],
				TRUE);


		}

	}

	//ゴール当たり判定用
	/*DrawBox(GoalRect3.left, GoalRect3.top, GoalRect3.right, GoalRect3.bottom, GetColor(255, 255, 0), TRUE);
	//戻る判定用
	DrawBox(Modoru2.left, Modoru2.top, Modoru2.right, Modoru2.bottom, GetColor(255, 0, 0), TRUE);*/
	
	//アイテムフラグの判定用
	//DrawBox(Itemflag.left, Itemflag.top, Itemflag.right, Itemflag.bottom, GetColor(0, 255, 0), TRUE);
	
	//当たり判定の描画（デバッグ用）
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

	DrawGraph(player.image.x, player.image.y, playerChip1.handle[player.kind1], TRUE);//プレイヤの描画


	RECT PlayerRect;
	PlayerRect.left = player.CenterX - 40 / 20 + 5;
	PlayerRect.top = player.CenterY + 200 / 20 + 5;
	PlayerRect.right = player.CenterX + 650 / 20 - 5;
	PlayerRect.bottom = player.CenterY + 1000 / 20 - 5;


	//フラグイベント
	if (MY_CHECK_RECT_COLL(PlayerRect, Itemflag) == TRUE && MY_KEY_PUSH(KEY_INPUT_RETURN))
	{
		hyouji3 = true;
		flag = 1;


		if (CheckSoundMem(FLAG.handle) == 0)
		{
			//BGMの音量を下げる
			ChangeVolumeSoundMem(255 * 50 / 100, FLAG.handle);	//50%の音量にする

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
	//鍵を回収していないかつ、玄関へ行くとき

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

	//一つ目のカギを取得しているが、開かないとき

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


	player.kind1 = D_1; //何も押していないときのプレイヤの向き
	int old_x = player.image.x;
	int old_y = player.image.y;
	BOOL IsMove = TRUE;


	//上に移動するとき
	if (MY_KEY_DOWN(KEY_INPUT_W) == TRUE
		&& MY_KEY_DOWN(KEY_INPUT_D) == FALSE
		&& MY_KEY_DOWN(KEY_INPUT_S) == FALSE
		&& MY_KEY_DOWN(KEY_INPUT_A) == FALSE)
	{
		player.IsMoveNaname = FALSE;	//斜め移動していない

		if (player.kind1 >= U_1 && player.kind1 < U_4)
		{
			//画像変更カウンタ
			if (player.imgChangeCnt < player.imgChangeCntMAX)
			{
				player.imgChangeCnt++;
			}
			else //画像を変えるタイミングになったら
			{
				player.kind1++;			//次の画像にする
				player.imgChangeCnt = 0;	//変更カウンタ初期化
			}
		}
		else
		{
			player.kind1 = U_1;	//最初の画像にする
		}

		player.image.y -= 1.5;	//移動
	}

	//右に移動するとき
	if (MY_KEY_DOWN(KEY_INPUT_W) == FALSE
		&& MY_KEY_DOWN(KEY_INPUT_D) == TRUE
		&& MY_KEY_DOWN(KEY_INPUT_S) == FALSE
		&& MY_KEY_DOWN(KEY_INPUT_A) == FALSE)
	{
		player.IsMoveNaname = FALSE;	//斜め移動していない

		if (player.kind1 >= R_1 && player.kind1 < R_4)
		{
			//画像変更カウンタ
			if (player.imgChangeCnt < player.imgChangeCntMAX)
			{
				player.imgChangeCnt++;
			}
			else //画像を変えるタイミングになったら
			{
				player.kind1++;			//次の画像にする
				player.imgChangeCnt = 0;	//変更カウンタ初期化
			}
		}
		else
		{
			player.kind1 = R_1;	//最初の画像にする
		}
		player.image.x += 2;	//移動
	}

	//左に移動するとき
	if (MY_KEY_DOWN(KEY_INPUT_W) == FALSE
		&& MY_KEY_DOWN(KEY_INPUT_D) == FALSE
		&& MY_KEY_DOWN(KEY_INPUT_S) == FALSE
		&& MY_KEY_DOWN(KEY_INPUT_A) == TRUE)
	{
		player.IsMoveNaname = FALSE;	//斜め移動していない

		if (player.kind1 >= L_1 && player.kind1 < L_4)
		{
			//画像変更カウンタ
			if (player.imgChangeCnt < player.imgChangeCntMAX)
			{
				player.imgChangeCnt++;
			}
			else //画像を変えるタイミングになったら
			{
				player.kind1++;			//次の画像にする
				player.imgChangeCnt = 0;	//変更カウンタ初期化
			}
		}
		else
		{
			player.kind1 = L_1;	//最初の画像にする
		}
		player.image.x -= 1.5;	//移動
	}

	//下に移動するとき
	if (MY_KEY_DOWN(KEY_INPUT_W) == FALSE
		&& MY_KEY_DOWN(KEY_INPUT_D) == FALSE
		&& MY_KEY_DOWN(KEY_INPUT_S) == TRUE
		&& MY_KEY_DOWN(KEY_INPUT_A) == FALSE)
	{
		player.IsMoveNaname = FALSE;	//斜め移動していない

		if (player.kind1 >= D_1 && player.kind1 < D_4)
		{
			//画像変更カウンタ
			if (player.imgChangeCnt < player.imgChangeCntMAX)
			{
				player.imgChangeCnt++;
			}
			else //画像を変えるタイミングになったら
			{
				player.kind1++;			//次の画像にする
				player.imgChangeCnt = 0;	//変更カウンタ初期化
			}
		}
		else
		{
			player.kind1 = D_1;	//最初の画像にする
		}
		player.image.y += 2;	//移動
	}

	//画面内にキャラがいれば
	if (player.image.x >= 0 && player.image.x <= GAME_WIDTH
		&& player.image.y >= 0 && player.image.y <= GAME_HEIGHT)
	{
		//プレイヤーの中心位置を設定する
		player.CenterX = player.image.x;
		player.CenterY = player.image.y;
	}

	//プレイヤーの当たり判定の設定
	player.coll.left = player.CenterX - 40 / 20 + 5;
	player.coll.top = player.CenterY + 200 / 20 + 5;
	player.coll.right = player.CenterX + 650 / 20 - 5;
	player.coll.bottom = player.CenterY + 1000 / 20 - 5;

	RECT PlayerRect;
	PlayerRect.left = player.CenterX - 40 / 20 + 5;
	PlayerRect.top = player.CenterY + 200 / 20 + 5;
	PlayerRect.right = player.CenterX + 650 / 20 - 5;
	PlayerRect.bottom = player.CenterY + 1000 / 20 - 5;



	//ゴールに触れているかチェック
	if (MY_CHECK_RECT_COLL(PlayerRect, GoalRect4) == TRUE)
	{
		//プレイ画面を初期化
		MY_PLAY_INIT();

		//エンド画面へ遷移

		GameScene = GAME_SCENE_END;


		return;
	}


	//家の中に戻れるようにする予定
	//if (MY_CHECK_RECT_COLL(PlayerRect, Modoru2) == TRUE)
	//{



	//	player.CenterX = Modoru2Pt.x;
	//	player.CenterY = Modoru2Pt.y;


	//	player.image.x = player.CenterX + 100;
	//	player.image.y = player.CenterY;

	//	GameScene = GAME_SCENE_PLAY3;


	//	return;	//強制的にエンド画面に飛ぶ
	//}





	//プレイヤーとマップがあたっていたら
	if (MY_CHECK_MAP4_PLAYER_COLL(player.coll) == TRUE)
	{
		//動けません
		IsMove = false;


	}

	if (IsMove == false)
	{
		player.image.x = old_x;//当たる前に戻る
		player.image.y = old_y;
	}


	if (IsMove == TRUE)
	{

		{
			////プレイヤーの位置に置き換える
			//player.image.x = player.CenterX - player.image.width / 2;
			//player.image.y = player.CenterY - player.image.height / 2;

			//あたっていないときの座標を取得
			player.collBeforePt.x = player.CenterX;
			player.collBeforePt.y = player.CenterY;
		}
	}

	return;

}

VOID MY_PLAY_DRAW4(VOID)
{

	//マップの描画

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

			//虚無のとき
			DrawGraph(yoko * mapChip.width,
				tate * mapChip.height,
				mapChip2.handle[mapdata13[tate][yoko]],
				TRUE);


		}

	}

	DrawGraph(player.image.x, player.image.y, playerChip1.handle[player.kind1], TRUE);//プレイヤの描画

	RECT PlayerRect;
	PlayerRect.left = player.CenterX - 40 / 20 + 5;
	PlayerRect.top = player.CenterY + 200 / 20 + 5;
	PlayerRect.right = player.CenterX + 650 / 20 - 5;
	PlayerRect.bottom = player.CenterY + 1000 / 20 - 5;

	//フラグを回収しているかどうかのイベント
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


	//出口用
	//DrawBox(GoalRect4.left, GoalRect4.top, GoalRect4.right, GoalRect4.bottom, GetColor(255, 255, 0), TRUE);
	/*DrawBox(Kanban.left, Kanban.top, Kanban.right, Kanban.bottom, GetColor(255, 255, 0), TRUE);*/
	return;
}

VOID MY_PLAY_KAKUSI(VOID)
{
	MY_PLAY_PROC_KAKUSI(); //処理
	MY_PLAY_KAKUSHI_DRAW();//描画

	return;
}

VOID MY_PLAY_PROC_KAKUSI(VOID)
{

	//隠し部屋のBGM
	if (CheckSoundMem(SYBERB.handle) == 0)
	{
		//BGMの音量を下げる
		ChangeVolumeSoundMem(255 * 50 / 100, SYBERB.handle);	//50%の音量にする

		PlaySoundMem(SYBERB.handle, DX_PLAYTYPE_LOOP);
	}

	player.kind1 = D_1; //何も押していないときのプレイヤの向き
	int old_x = player.image.x;
	int old_y = player.image.y;
	BOOL IsMove = TRUE;


	//上に移動するとき
	if (MY_KEY_DOWN(KEY_INPUT_W) == TRUE
		&& MY_KEY_DOWN(KEY_INPUT_D) == FALSE
		&& MY_KEY_DOWN(KEY_INPUT_S) == FALSE
		&& MY_KEY_DOWN(KEY_INPUT_A) == FALSE)
	{
		player.IsMoveNaname = FALSE;	//斜め移動していない

		if (player.kind1 >= U_1 && player.kind1 < U_4)
		{
			//画像変更カウンタ
			if (player.imgChangeCnt < player.imgChangeCntMAX)
			{
				player.imgChangeCnt++;
			}
			else //画像を変えるタイミングになったら
			{
				player.kind1++;			//次の画像にする
				player.imgChangeCnt = 0;	//変更カウンタ初期化
			}
		}
		else
		{
			player.kind1 = U_1;	//最初の画像にする
		}

		player.image.y -= 1.5;	//移動
	}

	//右に移動するとき
	if (MY_KEY_DOWN(KEY_INPUT_W) == FALSE
		&& MY_KEY_DOWN(KEY_INPUT_D) == TRUE
		&& MY_KEY_DOWN(KEY_INPUT_S) == FALSE
		&& MY_KEY_DOWN(KEY_INPUT_A) == FALSE)
	{
		player.IsMoveNaname = FALSE;	//斜め移動していない

		if (player.kind1 >= R_1 && player.kind1 < R_4)
		{
			//画像変更カウンタ
			if (player.imgChangeCnt < player.imgChangeCntMAX)
			{
				player.imgChangeCnt++;
			}
			else //画像を変えるタイミングになったら
			{
				player.kind1++;			//次の画像にする
				player.imgChangeCnt = 0;	//変更カウンタ初期化
			}
		}
		else
		{
			player.kind1 = R_1;	//最初の画像にする
		}
		player.image.x += 2;	//移動
	}

	//左に移動するとき
	if (MY_KEY_DOWN(KEY_INPUT_W) == FALSE
		&& MY_KEY_DOWN(KEY_INPUT_D) == FALSE
		&& MY_KEY_DOWN(KEY_INPUT_S) == FALSE
		&& MY_KEY_DOWN(KEY_INPUT_A) == TRUE)
	{
		player.IsMoveNaname = FALSE;	//斜め移動していない

		if (player.kind1 >= L_1 && player.kind1 < L_4)
		{
			//画像変更カウンタ
			if (player.imgChangeCnt < player.imgChangeCntMAX)
			{
				player.imgChangeCnt++;
			}
			else //画像を変えるタイミングになったら
			{
				player.kind1++;			//次の画像にする
				player.imgChangeCnt = 0;	//変更カウンタ初期化
			}
		}
		else
		{
			player.kind1 = L_1;	//最初の画像にする
		}
		player.image.x -= 1.5;	//移動
	}

	//下に移動するとき
	if (MY_KEY_DOWN(KEY_INPUT_W) == FALSE
		&& MY_KEY_DOWN(KEY_INPUT_D) == FALSE
		&& MY_KEY_DOWN(KEY_INPUT_S) == TRUE
		&& MY_KEY_DOWN(KEY_INPUT_A) == FALSE)
	{
		player.IsMoveNaname = FALSE;	//斜め移動していない

		if (player.kind1 >= D_1 && player.kind1 < D_4)
		{
			//画像変更カウンタ
			if (player.imgChangeCnt < player.imgChangeCntMAX)
			{
				player.imgChangeCnt++;
			}
			else //画像を変えるタイミングになったら
			{
				player.kind1++;			//次の画像にする
				player.imgChangeCnt = 0;	//変更カウンタ初期化
			}
		}
		else
		{
			player.kind1 = D_1;	//最初の画像にする
		}
		player.image.y += 2;	//移動
	}

	//画面内にキャラがいれば
	if (player.image.x >= 0 && player.image.x <= GAME_WIDTH
		&& player.image.y >= 0 && player.image.y <= GAME_HEIGHT)
	{
		//プレイヤーの中心位置を設定する
		player.CenterX = player.image.x;
		player.CenterY = player.image.y;
	}

	//プレイヤーの当たり判定の設定
	player.coll.left = player.CenterX - 40 / 20 + 5;
	player.coll.top = player.CenterY + 200 / 20 + 5;
	player.coll.right = player.CenterX + 650 / 20 - 5;
	player.coll.bottom = player.CenterY + 1000 / 20 - 5;

	RECT PlayerRect;
	PlayerRect.left = player.CenterX - 40 / 20 + 5;
	PlayerRect.top = player.CenterY + 200 / 20 + 5;
	PlayerRect.right = player.CenterX + 650 / 20 - 5;
	PlayerRect.bottom = player.CenterY + 1000 / 20 - 5;



	//ゴールに触れているかチェック
	if (MY_CHECK_RECT_COLL(PlayerRect, KakushiD) == TRUE)
	{

		player.CenterX = startPt3.x;
		player.CenterY = startPt3.y;


		player.image.x = player.CenterX;
		player.image.y = player.CenterY;

		if (CheckSoundMem(SYBERB.handle) != 0)
		{
			StopSoundMem(SYBERB.handle);	//BGMを止める
		}

		//廊下へ
		GameScene = GAME_SCENE_PLAY3;


		return;
	}


	//家の中に戻れるようにする予定
	//if (MY_CHECK_RECT_COLL(PlayerRect, Modoru2) == TRUE)
	//{



	//	player.CenterX = Modoru2Pt.x;
	//	player.CenterY = Modoru2Pt.y;


	//	player.image.x = player.CenterX + 100;
	//	player.image.y = player.CenterY;

	//	GameScene = GAME_SCENE_PLAY3;


	//	return;	//強制的にエンド画面に飛ぶ
	//}





	//プレイヤーとマップがあたっていたら
	if (MY_CHECK_SYBER_PLAYER_COLL(player.coll) == TRUE)
	{
		//動けません
		IsMove = false;


	}

	if (IsMove == false)
	{
		player.image.x = old_x;//当たる前に戻る
		player.image.y = old_y;
	}


	if (IsMove == TRUE)
	{

		{
			////プレイヤーの位置に置き換える
			//player.image.x = player.CenterX - player.image.width / 2;
			//player.image.y = player.CenterY - player.image.height / 2;

			//あたっていないときの座標を取得
			player.collBeforePt.x = player.CenterX;
			player.collBeforePt.y = player.CenterY;
		}
	}

	return;
}

VOID MY_PLAY_KAKUSHI_DRAW(VOID)
{

	

	

	//マップの描画

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

	

	DrawGraph(player.image.x, player.image.y, playerChip1.handle[player.kind1], TRUE);//プレイヤの描画

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

//エンド画面
VOID MY_END(VOID)
{
	MY_END_PROC();	//エンド画面の処理
	MY_END_DRAW();	//エンド画面の描画


	return;
}

//エンド画面の処理
VOID MY_END_PROC(VOID)
{
	

	//エスケープキーを押したら、スタートシーンへ移動する
	if (MY_KEY_DOWN(KEY_INPUT_ESCAPE) == TRUE)
	{
		GameScene = GAME_SCENE_START;
	}

	DrawString(0, 0, "エンドロールテキスト終了後、エスケープキーを押して下さい", GetColor(255, 255, 255));
	return;
}

//エンド画面の描画
VOID MY_END_DRAW(VOID)
{
	
	if (EndFlag == FALSE)
	{
		//小説文字列描画
		NovelProc(SCENARIO_END);
	}

	//文字列を描画
	NovelDraw();
	return;
}


//画像をまとめて読み込む関数
BOOL LOAD_IMAGE(VOID)
{
	strcpy_s(imageBACK.path, TITLE_BACK_PATH);	//タイトル背景画像読込
	imageBACK.handle = LoadGraph(imageBACK.path);			//読み込み
	if (imageBACK.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), TITLE_BACK_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(imageBACK.handle, &imageBACK.width, &imageBACK.height);	//画像の幅と高さを取得
	imageBACK.x = GAME_WIDTH / 2 - imageBACK.width / 2;		//左右中央揃え
	imageBACK.y = GAME_HEIGHT / 2 - imageBACK.height / 2;		//上下中央揃え

	strcpy_s(ImageSetumei.path, IMAGE_SETUMEI_PATH);	//説明画面背景画像読込
	ImageSetumei.handle = LoadGraph(ImageSetumei.path);			//読み込み
	if (ImageSetumei.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), IMAGE_SETUMEI_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(ImageSetumei.handle, &ImageSetumei.width, &ImageSetumei.height);	//画像の幅と高さを取得
	ImageSetumei.x = GAME_WIDTH / 2 - ImageSetumei.width / 2;		//左右中央揃え
	ImageSetumei.y = GAME_HEIGHT / 2 - ImageSetumei.height / 2;		//上下中央揃え

	//######################説明画面のキー入力画像####################

	strcpy_s(ImageSetumei_KEY_W.path, IMAGE_SETUMEI_KEY_W);	//説明画面背景画像読込
	ImageSetumei_KEY_W.handle = LoadGraph(ImageSetumei_KEY_W.path);			//読み込み
	if (ImageSetumei_KEY_W.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), IMAGE_SETUMEI_KEY_W, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(ImageSetumei_KEY_W.handle, &ImageSetumei_KEY_W.width, &ImageSetumei_KEY_W.height);	//画像の幅と高さを取得
	ImageSetumei_KEY_W.x = GAME_WIDTH / 2 - ImageSetumei_KEY_W.width / 2;		//左右中央揃え
	ImageSetumei_KEY_W.y = GAME_HEIGHT / 2 - ImageSetumei_KEY_W.height / 2;		//上下中央揃え


	//-----------------------------------------------------------------------

	strcpy_s(ImageSetumei_KEY_A.path, IMAGE_SETUMEI_KEY_A);	//説明画面背景画像読込
	ImageSetumei_KEY_A.handle = LoadGraph(ImageSetumei_KEY_A.path);			//読み込み
	if (ImageSetumei_KEY_A.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), IMAGE_SETUMEI_KEY_A, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(ImageSetumei_KEY_A.handle, &ImageSetumei_KEY_A.width, &ImageSetumei_KEY_A.height);	//画像の幅と高さを取得
	ImageSetumei_KEY_A.x = GAME_WIDTH / 2 - ImageSetumei_KEY_A.width / 2;		//左右中央揃え
	ImageSetumei_KEY_A.y = GAME_HEIGHT / 2 - ImageSetumei_KEY_A.height / 2;		//上下中央揃え

	//-----------------------------------------------------------------------

	strcpy_s(ImageSetumei_KEY_S.path, IMAGE_SETUMEI_KEY_S);	//説明画面背景画像読込
	ImageSetumei_KEY_S.handle = LoadGraph(ImageSetumei_KEY_S.path);			//読み込み
	if (ImageSetumei_KEY_S.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), IMAGE_SETUMEI_KEY_S, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(ImageSetumei_KEY_S.handle, &ImageSetumei_KEY_S.width, &ImageSetumei_KEY_S.height);	//画像の幅と高さを取得
	ImageSetumei_KEY_S.x = GAME_WIDTH / 2 - ImageSetumei_KEY_S.width / 2;		//左右中央揃え
	ImageSetumei_KEY_S.y = GAME_HEIGHT / 2 - ImageSetumei_KEY_S.height / 2;		//上下中央揃え

	//-----------------------------------------------------------------------

	strcpy_s(ImageSetumei_KEY_D.path, IMAGE_SETUMEI_KEY_D);	//説明画面背景画像読込
	ImageSetumei_KEY_D.handle = LoadGraph(ImageSetumei_KEY_D.path);			//読み込み
	if (ImageSetumei_KEY_D.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), IMAGE_SETUMEI_KEY_D, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(ImageSetumei_KEY_D.handle, &ImageSetumei_KEY_D.width, &ImageSetumei_KEY_D.height);	//画像の幅と高さを取得
	ImageSetumei_KEY_D.x = GAME_WIDTH / 2 - ImageSetumei_KEY_D.width / 2;		//左右中央揃え
	ImageSetumei_KEY_D.y = GAME_HEIGHT / 2 - ImageSetumei_KEY_D.height / 2;		//上下中央揃え




	//######################メニュー画面のボタン画像の読込#############

	strcpy_s(GameMenu_START.image.path, GAME_MENU_BTN);	//スタートボタン画像読込
	GameMenu_START.image.handle = LoadGraph(GameMenu_START.image.path);			//読み込み
	if (GameMenu_START.image.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), GAME_MENU_BTN, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(GameMenu_START.image.handle, &GameMenu_START.image.width, &GameMenu_START.image.height);	//画像の幅と高さを取得
	GameMenu_START.image.x = (GAME_WIDTH / 2 - GameMenu_START.image.width / 2) + 50;		//左右中央揃え
	GameMenu_START.image.y = (GAME_HEIGHT / 2 - GameMenu_START.image.height / 2) + 250;		//上下中央揃え
	GameMenu_START.rate = 2;

	//--------------------------------------------------------------------------------------------

	strcpy_s(GameMenu_EXIT.image.path, GAME_MENU_BTN2);	//終了ボタン画像読込
	GameMenu_EXIT.image.handle = LoadGraph(GameMenu_EXIT.image.path);			//読み込み
	if (GameMenu_EXIT.image.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), GAME_MENU_BTN2, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(GameMenu_EXIT.image.handle, &GameMenu_EXIT.image.width, &GameMenu_EXIT.image.height);	//画像の幅と高さを取得
	GameMenu_EXIT.image.x = (GAME_WIDTH / 2 - GameMenu_EXIT.image.width / 2)+ 50;		//左右中央揃え
	GameMenu_EXIT.image.y = (GAME_HEIGHT / 2 - GameMenu_EXIT.image.height / 2) + 350;		//上下中央揃え
	GameMenu_EXIT.rate = 1;

	//--------------------------------------------------------------------------------------------

	strcpy_s(GameMenu_OPTION.image.path, GAME_MENU_BTN3);	//設定ボタン画像読込
	GameMenu_OPTION.image.handle = LoadGraph(GameMenu_OPTION.image.path);			//読み込み
	if (GameMenu_OPTION.image.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), GAME_MENU_BTN3, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(GameMenu_OPTION.image.handle, &GameMenu_OPTION.image.width, &GameMenu_OPTION.image.height);	//画像の幅と高さを取得
	GameMenu_OPTION.image.x = (GAME_WIDTH / 2 - GameMenu_OPTION.image.width / 2) + 50;		//左右中央揃え
	GameMenu_OPTION.image.y = (GAME_HEIGHT / 2 - GameMenu_OPTION.image.height / 2) + 300;		//上下中央揃え
	GameMenu_OPTION.rate = 1;

	//##################################オプション画面・音量調整ボタン#############################

	strcpy_s(SOUND_VOLUME.image.path, OPTION_SOUND_VOLUME);	//終了ボタン画像読込
	SOUND_VOLUME.image.handle = LoadGraph(SOUND_VOLUME.image.path);			//読み込み
	if (SOUND_VOLUME.image.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), OPTION_SOUND_VOLUME, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(SOUND_VOLUME.image.handle, &SOUND_VOLUME.image.width, &SOUND_VOLUME.image.height);	//画像の幅と高さを取得
	SOUND_VOLUME.image.x = (GAME_WIDTH / 2 - SOUND_VOLUME.image.width / 2);		//左右中央揃え
	SOUND_VOLUME.image.y = (GAME_HEIGHT / 2 - SOUND_VOLUME.image.height / 2);		//上下中央揃え
	SOUND_VOLUME.rate = 1;

	//--------------------------------------------------------------------------------------------

	strcpy_s(SOUND_VOLUME1.image.path, OPTION_SOUND_VOLUME1);	//終了ボタン画像読込
	SOUND_VOLUME1.image.handle = LoadGraph(SOUND_VOLUME1.image.path);			//読み込み
	if (SOUND_VOLUME1.image.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), OPTION_SOUND_VOLUME1, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(SOUND_VOLUME1.image.handle, &SOUND_VOLUME1.image.width, &SOUND_VOLUME1.image.height);	//画像の幅と高さを取得
	SOUND_VOLUME1.image.x = (GAME_WIDTH / 2 - SOUND_VOLUME1.image.width / 2);		//左右中央揃え
	SOUND_VOLUME1.image.y = (GAME_HEIGHT / 2 - SOUND_VOLUME1.image.height / 2);		//上下中央揃え
	SOUND_VOLUME1.rate = 1;

	//--------------------------------------------------------------------------------------------

	strcpy_s(SOUND_VOLUME2.image.path, OPTION_SOUND_VOLUME2);	//終了ボタン画像読込
	SOUND_VOLUME2.image.handle = LoadGraph(SOUND_VOLUME2.image.path);			//読み込み
	if (SOUND_VOLUME2.image.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), OPTION_SOUND_VOLUME2, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(SOUND_VOLUME2.image.handle, &SOUND_VOLUME2.image.width, &SOUND_VOLUME2.image.height);	//画像の幅と高さを取得
	SOUND_VOLUME2.image.x = (GAME_WIDTH / 2 - SOUND_VOLUME2.image.width / 2);		//左右中央揃え
	SOUND_VOLUME2.image.y = (GAME_HEIGHT / 2 - SOUND_VOLUME2.image.height / 2);		//上下中央揃え
	SOUND_VOLUME2.rate = 1;

	//--------------------------------------------------------------------------------------------

	strcpy_s(SOUND_VOLUME3.image.path, OPTION_SOUND_VOLUME3);	//終了ボタン画像読込
	SOUND_VOLUME3.image.handle = LoadGraph(SOUND_VOLUME3.image.path);			//読み込み
	if (SOUND_VOLUME3.image.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), OPTION_SOUND_VOLUME3, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(SOUND_VOLUME3.image.handle, &SOUND_VOLUME3.image.width, &SOUND_VOLUME3.image.height);	//画像の幅と高さを取得
	SOUND_VOLUME3.image.x = (GAME_WIDTH / 2 - SOUND_VOLUME3.image.width / 2);		//左右中央揃え
	SOUND_VOLUME3.image.y = (GAME_HEIGHT / 2 - SOUND_VOLUME3.image.height / 2);		//上下中央揃え
	SOUND_VOLUME3.rate = 1;

	//--------------------------------------------------------------------------------------------

	strcpy_s(SOUND_VOLUME4.image.path, OPTION_SOUND_VOLUME4);	//終了ボタン画像読込
	SOUND_VOLUME4.image.handle = LoadGraph(SOUND_VOLUME4.image.path);			//読み込み
	if (SOUND_VOLUME4.image.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), OPTION_SOUND_VOLUME4, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(SOUND_VOLUME4.image.handle, &SOUND_VOLUME4.image.width, &SOUND_VOLUME4.image.height);	//画像の幅と高さを取得
	SOUND_VOLUME4.image.x = (GAME_WIDTH / 2 - SOUND_VOLUME4.image.width / 2);		//左右中央揃え
	SOUND_VOLUME4.image.y = (GAME_HEIGHT / 2 - SOUND_VOLUME4.image.height / 2);		//上下中央揃え
	SOUND_VOLUME4.rate = 1;

	//################################効果音ボタン画像########################

	strcpy_s(SOUND_EFFECT.image.path, OPTION_SOUND_EFFECT);	//終了ボタン画像読込
	SOUND_EFFECT.image.handle = LoadGraph(SOUND_EFFECT.image.path);			//読み込み
	if (SOUND_EFFECT.image.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), OPTION_SOUND_EFFECT, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(SOUND_EFFECT.image.handle, &SOUND_EFFECT.image.width, &SOUND_EFFECT.image.height);	//画像の幅と高さを取得
	SOUND_EFFECT.image.x = (GAME_WIDTH / 2 - SOUND_EFFECT.image.width / 2);		//左右中央揃え
	SOUND_EFFECT.image.y = (GAME_HEIGHT / 2 - SOUND_EFFECT.image.height / 2);		//上下中央揃え
	SOUND_EFFECT.rate = 1;

	//------------------------------------------------------------------------------------

	strcpy_s(SOUND_EFFECT1.image.path, OPTION_SOUND_EFFECT1);	//効果音ボタン画像読込
	SOUND_EFFECT1.image.handle = LoadGraph(SOUND_EFFECT1.image.path);			//読み込み
	if (SOUND_EFFECT1.image.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), OPTION_SOUND_EFFECT1, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(SOUND_EFFECT1.image.handle, &SOUND_EFFECT1.image.width, &SOUND_EFFECT1.image.height);	//画像の幅と高さを取得
	SOUND_EFFECT1.image.x = (GAME_WIDTH / 2 - SOUND_EFFECT1.image.width / 2);		//左右中央揃え
	SOUND_EFFECT1.image.y = (GAME_HEIGHT / 2 - SOUND_EFFECT1.image.height / 2);		//上下中央揃え
	SOUND_EFFECT1.rate = 1;

	//------------------------------------------------------------------------------------

	strcpy_s(SOUND_EFFECT2.image.path, OPTION_SOUND_EFFECT2);	//効果音ボタン画像読込
	SOUND_EFFECT2.image.handle = LoadGraph(SOUND_EFFECT2.image.path);			//読み込み
	if (SOUND_EFFECT2.image.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), OPTION_SOUND_EFFECT2, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(SOUND_EFFECT2.image.handle, &SOUND_EFFECT2.image.width, &SOUND_EFFECT2.image.height);	//画像の幅と高さを取得
	SOUND_EFFECT2.image.x = (GAME_WIDTH / 2 - SOUND_EFFECT2.image.width / 2);		//左右中央揃え
	SOUND_EFFECT2.image.y = (GAME_HEIGHT / 2 - SOUND_EFFECT2.image.height / 2);		//上下中央揃え
	SOUND_EFFECT2.rate = 1;

	//------------------------------------------------------------------------------------

	strcpy_s(SOUND_EFFECT3.image.path, OPTION_SOUND_EFFECT3);	//効果音ボタン画像読込
	SOUND_EFFECT3.image.handle = LoadGraph(SOUND_EFFECT3.image.path);			//読み込み
	if (SOUND_EFFECT3.image.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), OPTION_SOUND_EFFECT3, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(SOUND_EFFECT3.image.handle, &SOUND_EFFECT3.image.width, &SOUND_EFFECT3.image.height);	//画像の幅と高さを取得
	SOUND_EFFECT3.image.x = (GAME_WIDTH / 2 - SOUND_EFFECT3.image.width / 2);		//左右中央揃え
	SOUND_EFFECT3.image.y = (GAME_HEIGHT / 2 - SOUND_EFFECT3.image.height / 2);		//上下中央揃え
	SOUND_EFFECT3.rate = 1;

	//------------------------------------------------------------------------------------

	strcpy_s(SOUND_EFFECT4.image.path, OPTION_SOUND_EFFECT4);	//効果音ボタン画像読込
	SOUND_EFFECT4.image.handle = LoadGraph(SOUND_EFFECT4.image.path);			//読み込み
	if (SOUND_EFFECT4.image.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), OPTION_SOUND_EFFECT4, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(SOUND_EFFECT4.image.handle, &SOUND_EFFECT4.image.width, &SOUND_EFFECT4.image.height);	//画像の幅と高さを取得
	SOUND_EFFECT4.image.x = (GAME_WIDTH / 2 - SOUND_EFFECT4.image.width / 2);		//左右中央揃え
	SOUND_EFFECT4.image.y = (GAME_HEIGHT / 2 - SOUND_EFFECT4.image.height / 2);		//上下中央揃え
	SOUND_EFFECT4.rate = 1;

	//############################決定ボタン読込#############################

	strcpy_s(SOUND_DECISION.image.path, OPTION_SOUND_DECISION);	//効果音ボタン画像読込
	SOUND_DECISION.image.handle = LoadGraph(SOUND_DECISION.image.path);			//読み込み
	if (SOUND_DECISION.image.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), OPTION_SOUND_DECISION, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(SOUND_DECISION.image.handle, &SOUND_DECISION.image.width, &SOUND_DECISION.image.height);	//画像の幅と高さを取得
	SOUND_DECISION.image.x = (GAME_WIDTH / 2 - SOUND_DECISION.image.width / 2);		//左右中央揃え
	SOUND_DECISION.image.y = (GAME_HEIGHT / 2 - SOUND_DECISION.image.height / 2);		//上下中央揃え
	SOUND_DECISION.rate = 1;

	//-------------------------------------------------------------------------------------

	strcpy_s(SOUND_DECISION1.image.path, OPTION_SOUND_DECISION1);	//効果音ボタン画像読込
	SOUND_DECISION1.image.handle = LoadGraph(SOUND_DECISION1.image.path);			//読み込み
	if (SOUND_DECISION1.image.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), OPTION_SOUND_DECISION1, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(SOUND_DECISION1.image.handle, &SOUND_DECISION1.image.width, &SOUND_DECISION1.image.height);	//画像の幅と高さを取得
	SOUND_DECISION1.image.x = (GAME_WIDTH / 2 - SOUND_DECISION1.image.width / 2);		//左右中央揃え
	SOUND_DECISION1.image.y = (GAME_HEIGHT / 2 - SOUND_DECISION1.image.height / 2);		//上下中央揃え
	SOUND_DECISION1.rate = 1;

	//-------------------------------------------------------------------------------------

	strcpy_s(SOUND_DECISION2.image.path, OPTION_SOUND_DECISION2);	//効果音ボタン画像読込
	SOUND_DECISION2.image.handle = LoadGraph(SOUND_DECISION2.image.path);			//読み込み
	if (SOUND_DECISION2.image.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), OPTION_SOUND_DECISION2, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(SOUND_DECISION2.image.handle, &SOUND_DECISION2.image.width, &SOUND_DECISION2.image.height);	//画像の幅と高さを取得
	SOUND_DECISION2.image.x = (GAME_WIDTH / 2 - SOUND_DECISION2.image.width / 2);		//左右中央揃え
	SOUND_DECISION2.image.y = (GAME_HEIGHT / 2 - SOUND_DECISION2.image.height / 2);		//上下中央揃え
	SOUND_DECISION2.rate = 1;

	//-------------------------------------------------------------------------------------

	strcpy_s(SOUND_DECISION3.image.path, OPTION_SOUND_DECISION3);	//効果音ボタン画像読込
	SOUND_DECISION3.image.handle = LoadGraph(SOUND_DECISION3.image.path);			//読み込み
	if (SOUND_DECISION3.image.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), OPTION_SOUND_DECISION3, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(SOUND_DECISION3.image.handle, &SOUND_DECISION3.image.width, &SOUND_DECISION3.image.height);	//画像の幅と高さを取得
	SOUND_DECISION3.image.x = (GAME_WIDTH / 2 - SOUND_DECISION3.image.width / 2);		//左右中央揃え
	SOUND_DECISION3.image.y = (GAME_HEIGHT / 2 - SOUND_DECISION3.image.height / 2);		//上下中央揃え
	SOUND_DECISION3.rate = 1;

	//-------------------------------------------------------------------------------------

	strcpy_s(SOUND_DECISION4.image.path, OPTION_SOUND_DECISION4);	//効果音ボタン画像読込
	SOUND_DECISION4.image.handle = LoadGraph(SOUND_DECISION4.image.path);			//読み込み
	if (SOUND_DECISION4.image.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), OPTION_SOUND_DECISION4, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(SOUND_DECISION4.image.handle, &SOUND_DECISION4.image.width, &SOUND_DECISION4.image.height);	//画像の幅と高さを取得
	SOUND_DECISION4.image.x = (GAME_WIDTH / 2 - SOUND_DECISION4.image.width / 2);		//左右中央揃え
	SOUND_DECISION4.image.y = (GAME_HEIGHT / 2 - SOUND_DECISION4.image.height / 2);		//上下中央揃え
	SOUND_DECISION4.rate = 1;




	//########################################################################
	
	strcpy_s(TextBox_start.path, TEXT_BOX);	//没画像
	TextBox_start.handle = LoadGraph(TextBox_start.path);			//読み込み
	if (TextBox_start.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), TEXT_BOX, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	strcpy_s(TextBox_flag.path, TEXT_BOX_1);//最初のフラグイベントのテキストボックス
	TextBox_flag.handle = LoadGraph(TextBox_flag.path);			//読み込み
	if (TextBox_flag.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), TEXT_BOX_1, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	strcpy_s(TextBox_Null.path, TEXT_BOX_2); //アイテムを回収していないときの玄関のテキストボックス
	TextBox_Null.handle = LoadGraph(TextBox_Null.path);			//読み込み
	if (TextBox_Null.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), TEXT_BOX_2, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	strcpy_s(TextBox_GenkanKagiNasi.path, TEXT_BOX_3); //鍵を回収していないとき、箱に近づいたときに発生するテキストボックス
	TextBox_GenkanKagiNasi.handle = LoadGraph(TextBox_GenkanKagiNasi.path);			//読み込み
	if (TextBox_GenkanKagiNasi.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), TEXT_BOX_3, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	strcpy_s(TextBox_GenkanKagi.path, TEXT_BOX_4); //鍵を回収しているときに箱を開けられる
	TextBox_GenkanKagi.handle = LoadGraph(TextBox_GenkanKagi.path);			//読み込み
	if (TextBox_GenkanKagi.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), TEXT_BOX_4, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}


	strcpy_s(TextBox_Kanban.path, TEXT_BOX_5); //看板
	TextBox_Kanban.handle = LoadGraph(TextBox_Kanban.path);			//読み込み
	if (TextBox_Kanban.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), TEXT_BOX_5, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	strcpy_s(TextBox_akanai.path, TEXT_BOX_6); //看板
	TextBox_akanai.handle = LoadGraph(TextBox_akanai.path);			//読み込み
	if (TextBox_akanai.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), TEXT_BOX_6, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	strcpy_s(TextBox_kakushi.path, TEXT_BOX_7); //隠し部屋
	TextBox_kakushi.handle = LoadGraph(TextBox_kakushi.path);			//読み込み
	if (TextBox_kakushi.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), TEXT_BOX_7, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	

	//###########################################################################

	int mapRes = LoadDivGraph(
		GAME_MAP_PATH,										//マップチップパス
		MAP_DIV_NUM, MAP_DIV_TATE, MAP_DIV_YOKO,			//マップチップを分割する数
		MAP_DIV_WIDTH, MAP_DIV_HEIGHT,						//画像を分割するの幅と高さ
		&mapChip.handle[0]);								//分割した画像が入るハンドル



	if (mapRes == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), GAME_MAP_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	//幅と高さを取得
	GetGraphSize(mapChip.handle[0], &mapChip.width, &mapChip.height);

	int mapRes10 = LoadDivGraph(
		GAME_MAP_PATH2,										//二つ目のマップチップのパス
		MAP_NUM, MAP_YOKO, MAP_TATE,						//マップを分割する数
		MAP_DIV_WIDTH, MAP_DIV_HEIGHT,						//画像を分割するの幅と高さ
		&mapChip2.handle[0]);								//分割した画像が入るハンドル

	if (mapRes10 == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), GAME_MAP_PATH2, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	//幅と高さを取得
	GetGraphSize(mapChip2.handle[0], &mapChip2.width, &mapChip2.height);

	

	
	GetGraphSize(player.image.handle, &player.image.width, &player.image.height);
	player.image.x = GAME_WIDTH / 2 - player.image.width / 2;
	player.image.y = GAME_HEIGHT / 2 - player.image.height / 2;
	player.CenterX = player.image.x + player.image.width / 2;
	player.CenterY = player.image.y + player.image.height / 2;
	player.imgChangeCnt = 0;
	player.imgChangeCntMAX = PLAYER_IMG_CHANGE_MAX;	//画像を変更するカウンタMAX


	//マップの当たり判定を設定する
	for (int tate = 0; tate < MAP_HEIGHT_MAX; tate++)
	{
		for (int yoko = 0; yoko < MAP_WIDTH_MAX; yoko++)
		{
			//マップの当たり判定を設定
			mapColl[tate][yoko].left = (yoko + 0) * mapChip.width + 1;
			mapColl[tate][yoko].top = (tate + 0) * mapChip.height + 1;
			mapColl[tate][yoko].right = (yoko + 1) * mapChip.width - 1;
			mapColl[tate][yoko].bottom = (tate + 1) * mapChip.height - 1;
		}
	}

	//gif 

	strcpy_s(SYBER.path, SYBER_MAP); //アイテムを回収していないときの玄関のテキストボックス
	SYBER.handle = LoadGraph(SYBER.path);			//読み込み
	if (SYBER.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), SYBER_MAP, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	//########################隠し部屋ヒント########################

	strcpy_s(HINT_KAMI.path, HINT);	//隠し部屋ヒント画像読込
	HINT_KAMI.handle = LoadGraph(HINT_KAMI.path);			//読み込み
	if (HINT_KAMI.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), HINT, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(HINT_KAMI.handle, &HINT_KAMI.width, &HINT_KAMI.height);	//画像の幅と高さを取得
	HINT_KAMI.x = GAME_WIDTH / 2 - HINT_KAMI.width / 2;		//左右中央揃え
	HINT_KAMI.y = GAME_HEIGHT / 2 - HINT_KAMI.height / 2;		//上下中央揃え


	
	return TRUE;
}

BOOL MY_LOAD_PLAYER(const char* path, PLAYERCHIP* player)
{
	//プレイヤーの画像を分割する
	int mapRes = LoadDivGraph(
		GAME_PLAYER_PATH,										//プレイヤーのパス
		PLAYER_DIV_NUM, PLAYER_DIV_TATE, PLAYER_DIV_YOKO,			
		PLAYER_DIV_WIDTH, PLAYER_DIV_HEIGHT,
		&player->handle[0]);								//画像が入るハンドル

	if (mapRes == -1)	//エラーメッセージ表示
	{
		MessageBox(GetMainWindowHandle(), path, IMAGE_LOAD_ERR_TITLE, MB_OK); return FALSE;
	}

	//幅と高さを取得
	GetGraphSize(player->handle[0], &player->width, &player->height);

	return TRUE;
}

//画像をまとめて削除する関数
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

//音楽をまとめて読み込む関数
BOOL LOAD_MUSIC(VOID)
{
	//タイトルBGM
	strcpy_s(BGM.path, TITLE_BGM_PATH);		//タイトルBGMの設定
	BGM.handle = LoadSoundMem(BGM.path);	//読み込み
	if (BGM.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), TITLE_BGM_PATH, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	strcpy_s(ROKA.path, ROKA_BGM_PATH);		//廊下BGMの設定
	ROKA.handle = LoadSoundMem(ROKA.path);	//読み込み
	if (ROKA.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), ROKA_BGM_PATH, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	strcpy_s(FLAG.path, FLAG_BGM_PATH);		//アイテム獲得時効果音の設定
	FLAG.handle = LoadSoundMem(FLAG.path);	//読み込み
	if (FLAG.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), FLAG_BGM_PATH, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	strcpy_s(SERECT.path, SERECT_EFFECT);		//セレクト時効果音の設定
	SERECT.handle = LoadSoundMem(SERECT.path);	//読み込み
	if (SERECT.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), SERECT_EFFECT, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	strcpy_s(DECISION.path, DECISION_EFFECT);		//決定時効果音の設定
	DECISION.handle = LoadSoundMem(DECISION.path);	//読み込み
	if (DECISION.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), DECISION_EFFECT, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	strcpy_s(SYBERB.path, SYBER_BGM);		//決定時効果音の設定
	SYBERB.handle = LoadSoundMem(SYBERB.path);	//読み込み
	if (SYBERB.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), SYBER_BGM, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}






	return TRUE;
}

//音楽をまとめて削除する関数
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

//マップとプレイヤーの当たり判定をする関数
BOOL MY_CHECK_MAP1_PLAYER_COLL(RECT player)
{
	//マップの当たり判定を設定する
	for (int tate = 0; tate < MAP_HEIGHT_MAX; tate++)
	{
		for (int yoko = 0; yoko < MAP_WIDTH_MAX; yoko++)
		{
			//プレイヤーとマップが当たっているとき
			if (MY_CHECK_RECT_COLL(player, mapColl[tate][yoko]) == TRUE)
			{
				
	
				//プレイヤーとマップが当たっている
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

//領域の当たり判定をする関数
BOOL MY_CHECK_RECT_COLL(RECT a, RECT b)
{
	if (a.left < b.right &&
		a.top < b.bottom &&
		a.right > b.left &&
		a.bottom > b.top
		)
	{
		return TRUE;	//当たっている
	}

	return FALSE;		//当たっていない
}

BOOL MY_CHECK_MAP2_PLAYER_COLL(RECT player)
{
	//マップの当たり判定を設定する
	for (int tate = 0; tate < MAP_HEIGHT_MAX; tate++)
	{
		for (int yoko = 0; yoko < MAP_WIDTH_MAX; yoko++)
		{
			//プレイヤーとマップが当たっているとき
			if (MY_CHECK_RECT_COLL(player, mapColl[tate][yoko]) == TRUE)
			{
				
				//壁のときは、プレイヤーとマップが当たっている
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
	//マップの当たり判定を設定する
	for (int tate = 0; tate < MAP_HEIGHT_MAX; tate++)
	{
		for (int yoko = 0; yoko < MAP_WIDTH_MAX; yoko++)
		{
			//プレイヤーとマップが当たっているとき
			if (MY_CHECK_RECT_COLL(player, mapColl[tate][yoko]) == TRUE)
			{

				//壁のときは、プレイヤーとマップが当たっている
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
	//マップの当たり判定を設定する
	for (int tate = 0; tate < MAP_HEIGHT_MAX; tate++)
	{
		for (int yoko = 0; yoko < MAP_WIDTH_MAX; yoko++)
		{
			//プレイヤーとマップが当たっているとき
			if (MY_CHECK_RECT_COLL(player, mapColl[tate][yoko]) == TRUE)
			{

				//プレイヤーとマップが当たっている
			

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
	//マップの当たり判定を設定する
	for (int tate = 0; tate < MAP_HEIGHT_MAX; tate++)
	{
		for (int yoko = 0; yoko < MAP_WIDTH_MAX; yoko++)
		{
			//プレイヤーとマップが当たっているとき
			if (MY_CHECK_RECT_COLL(player, mapColl[tate][yoko]) == TRUE)
			{

				//プレイヤーとマップが当たっている

				if (mapdata14[tate][yoko] == B) { return TRUE; }
				if (mapdata15[tate][yoko] == d) { return TRUE; }

			}
		}
	}

	return FALSE;
}


