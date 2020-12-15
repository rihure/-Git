#include "DxLib.h"
#include "stdlib.h"
#include "string.h"
#include "prototype_mapp.h"

#define _CRT_SECURE_NO_WARNINGS
#define MAP_NUM         3           // マップの数
#define GAME_WIDTH			800	//画面の横の大きさ
#define GAME_HEIGHT			640	//画面の縦の大きさ
#define GAME_COLOR			32	//画面のカラービット

#define MAP_SIZE        32          // マップチップ一つのドットサイズ

#define MAP_WIDTH_MAX   25          // マップの最大幅
#define MAP_HEIGHT_MAX  20          // マップの最大縦長さ

#define MAP_DIV_WIDTH		32	//画像を分割する幅サイズ
#define MAP_DIV_HEIGHT		32	//画像を分割する高さサイズ
#define MAP_DIV_TATE		8	//画像を縦に分割する数8
#define MAP_DIV_YOKO		50	//画像を横に分割する数50
#define MAP_DIV_NUM	MAP_DIV_TATE * MAP_DIV_YOKO	//画像を分割する総数 400

#define PLAYER_DIV_WIDTH 32 //プレイヤーの横幅32ビット
#define PLAYER_DIV_HEIGHT 48 //プレイヤー立幅48ビット
#define PLAYER_DIV_TATE 4 //タテ分割数4
#define PLAYER_DIV_YOKO 4 //ヨコ分割数4
#define PLAYER_DIV_NUM PLAYER_DIV_TATE * PLAYER_DIV_YOKO //16

#define GAME_FPS			60	//FPSの数値	

//画像のパス設定
#define TITLE_BACK_PATH TEXT(".\\IMAGE\\ダウンロード (2).png") //タイトルの画像
#define IMAGE_SETUMEI_PATH		TEXT(".\\IMAGE\\操作説明2.png") //説明画面の画像
#define GAME_MAP_PATH TEXT(".\\IMAGE\\ST-Town-I01.png")
#define GAME_PLAYER_PATH TEXT(".\\IMAGE\\joshi03.png")

//エラーメッセージ
#define IMAGE_LOAD_ERR_TITLE	TEXT("画像読み込みエラー")

//パスの長さ
#define PATH_MAX			255	//255文字まで
#define NAME_MAX			255	//255文字まで

//キーボードの種類
#define KEY_CODE_KIND		256	//256種類

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

enum GAME_SCENE {
	GAME_SCENE_START,
	GAME_SCENE_SETUMEI,
	GAME_SCENE_PLAY,
	GAME_SCENE_PLAY2,
	GAME_SCENE_END,
};	//ゲームのシーン

enum GAME_MAP_KIND
{
	/*n = -1,*/	//(NONE)未定
	k = 10,	//床
	t = 17,	//上壁
	s = 25,	//中壁
	g = 33,	//下壁
	n = 196, // 虚無
	d = 150, // ダンボール
	a = 66, //左窓上
	b = 67, // 右窓上
	c = 74, //左窓下
	h = 75, // 右窓下
	u = 349, //左カーペット
	e = 350, //カーペット左
	f = 351, //カーペット真ん中
	r = 2, //横床
	S = 198, //start
	G = 197, //goal
	M = 195, //一つ前の場所に戻る判定

};	//マップの種類

enum GAME_END {
	GAME_END_COMP,	//コンプリート
	GAME_END_FAIL	//フォールト
};	//ゲームの終了状態




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
	int handle[MAP_DIV_NUM];			//分割したの弾の画像ハンドルを取得
	int kind[MAP_DIV_NUM];				//マップの種類
	int width;							//幅
	int height;							//高さ
}MAPCHIP;	//MAP_IMAGE構造体

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
	char path[PATH_MAX];
	IMAGE image;
	int speed;
	int CenterX;
	int CenterY;
	int handle[PLAYER_DIV_NUM];
	int Part;
	double Muki;		//0：前　+1：右　-1：左
	 
	RECT coll; //当たり判定
	iPOINT collBeforePt; //当たる前の判定
}CHARA;



//マップ
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

//マップチップの画像を管理
MAPCHIP mapChip;
MAPCHIP mapChip_Nowalk;
MAPCHIP mapChip_Object;
MAPCHIP mapChip_Roka;
MAPCHIP mapChip_RokaNowalk;
CHARA player;

//マップの場所を管理
MAP map[MAP_HEIGHT_MAX][MAP_WIDTH_MAX];
MAP map2[MAP_HEIGHT_MAX][MAP_WIDTH_MAX];
MAP map3[MAP_HEIGHT_MAX][MAP_WIDTH_MAX];
MAP map4[MAP_HEIGHT_MAX][MAP_WIDTH_MAX];
MAP map5[MAP_HEIGHT_MAX][MAP_WIDTH_MAX];


RECT mapColl[MAP_HEIGHT_MAX][MAP_WIDTH_MAX]; //マップの当たり判定

//イメージ構造体の複製
IMAGE imageBACK; //タイトル背景
IMAGE ImageSetumei; //説明画面の画像
iPOINT startPt{ -1, -1 };
iPOINT startPt2{ -1 , -1 };
RECT GoalRect = { -1,-1, -1, -1 };	//ゴールの当たり判定
RECT GoalRect2 = { -1, -1 , -1, -1 };
RECT Modoru = { -1, -1, -1,-1 }; //一つ前の部屋に戻る判定
iPOINT ModoruPt{ -1,-1 };

int GameScene;		//ゲームシーンを管理
//キーボードの入力を取得
char AllKeyState[KEY_CODE_KIND] = { '\0' };		//すべてのキーの状態が入る
char OldAllKeyState[KEY_CODE_KIND] = { '\0' };	//すべてのキーの状態(直前)が入る

//FPS関連
int StartTimeFps;				//測定開始時刻
int CountFps;					//カウンタ
float CalcFps;					//計算結果
int SampleNumFps = GAME_FPS;	//平均を取るサンプル数
char key[256];
int playerhandle[16];

int count;

int x;
int y;
int result = 0;			//ファイルの最後かチェック
int tateCnt = 0;		//縦カウント用
int yokoCnt = 0;		//横カウント用

FILE* fp = NULL;




VOID MY_FPS_UPDATE(VOID);			//FPS値を計測、更新する
BOOL LOAD_IMAGE(VOID);		//画像をまとめて読み込む関数
VOID DELETE_IMAGE(VOID);		//画像をまとめて削除する関数

VOID MY_FPS_WAIT(VOID);				//FPS値を計測し、待つ

BOOL LOAD_MUSIC(VOID);		//音楽をまとめて読み込む関数
VOID DELETE_MUSIC(VOID);		//音楽をまとめて削除する関数
VOID MY_ALL_KEYDOWN_UPDATE(VOID);	//キーの入力状態を更新する
BOOL MY_KEY_DOWN(int);				//キーを押しているか、キーコードで判断する
BOOL MY_KEY_UP(int);				//キーを押し上げたか、キーコードで判断する
BOOL MY_KEYDOWN_KEEP(int, int);		//キーを押し続けているか、キーコードで判断する


VOID MY_START(VOID);		//スタート画面
VOID MY_START_PROC(VOID);	//スタート画面の処理
VOID MY_START_DRAW(VOID);	//スタート画面の描画

VOID MY_SETUMEI(VOID); //説明画面
VOID MY_START_SETUMEI_DRAW(VOID); //説明画面の描画

VOID MY_PLAY_INIT(VOID);	//プレイ画面初期化
VOID MY_PLAY(VOID);			//プレイ画面
VOID MY_PLAY_PROC(VOID);	//プレイ画面の処理
VOID MY_PLAY_DRAW(VOID);	//プレイ画面の描画
VOID MY_PLAY2(VOID);		//廊下画面
VOID MY_PLAY_PROC2(VOID);   //廊下の処理
VOID MY_PLAY_DRAW2(VOID);	//廊下のステージ描画

VOID MY_END(VOID);			//エンド画面
VOID MY_END_PROC(VOID);		//エンド画面の処理
VOID MY_END_DRAW(VOID);		//エンド画面の描画

BOOL MY_CHECK_MAP1_PLAYER_COLL(RECT);	//マップとプレイヤーの当たり判定をする関数
BOOL MY_CHECK_RECT_COLL(RECT, RECT);	//領域の当たり判定をする関数
BOOL MY_CHECK_MAP2_PLAYER_COLL(RECT);
BOOL MY_CHECK_RECT2_COLL(RECT, RECT);




//########## プログラムで最初に実行される関数 ##########
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetOutApplicationLogValidFlag(FALSE);				//Log.txtを出力しない
	ChangeWindowMode(TRUE);								//ウィンドウモードに設定
	SetGraphMode(GAME_WIDTH, GAME_HEIGHT, GAME_COLOR);	//指定の数値でウィンドウを表示する
	SetWindowStyleMode(0);				//タイトルバーはデフォルトにする
	SetAlwaysRunFlag(TRUE);								//非アクティブでも実行する
	
	SetWindowUserCloseEnableFlag(FALSE);				//閉じるボタンで、勝手にウィンドウが閉じないようにする

	if (DxLib_Init() == -1) { return -1; }	//ＤＸライブラリ初期化処理

	if (LOAD_IMAGE() == FALSE) { return -1; }

	//音楽を読み込む
	if (LOAD_MUSIC() == FALSE) { return -1; }

	GameScene = GAME_SCENE_START;	//ゲームシーンはスタート画面から
	SetDrawScreen(DX_SCREEN_BACK);	//Draw系関数は裏画面に描画

	fp = fopen(".\\sakuhin_remake.txt", "r");


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

	//開いたら、必ず閉じること！
	fclose(fp);	//ファイルを閉じる

	result = 0;
	tateCnt = 0;
	yokoCnt = 0;

	fp = fopen(".\\sakuhin_remake_nowalk.txt", "r");

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

	fp = fopen(".\\sakuhin_remake_object.txt", "r");

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


	//-----------------------廊下csv-----------------------
	result = 0;
	tateCnt = 0;
	yokoCnt = 0;

	fp = fopen(".\\sakuhin_roka.txt", "r");

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

	//開いたら、必ず閉じること！
	fclose(fp);	//ファイルを閉じる

	result = 0;
	tateCnt = 0;
	yokoCnt = 0;

	fp = fopen(".\\sakuhin_roka_nowalk.txt", "r");

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
				startPt2.x = mapChip.width * yokoCnt + mapChip.width / 2;	//中心X座標を取得
				startPt2.y = mapChip.height * tateCnt + mapChip.height / 2;	//中心Y座標を取得
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

			case 'u':
				//壁のとき
				mapdata5[tateCnt][yokoCnt] = u;
				yokoCnt++;
				break;

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

	fp = fopen(".\\sakuhin_roka_maenimodoru.txt", "r");

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

		case GAME_SCENE_PLAY:
			MY_PLAY();	//プレイ画面
			break;
		case GAME_SCENE_PLAY2:
			MY_PLAY2(); //廊下画面
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
//引　数：int：キーコード：KEY_INPUT_???
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
	
	//エンターキーを押したら、プレイシーンへ移動する
	if (MY_KEY_DOWN(KEY_INPUT_RETURN) == TRUE)
	{

		//ゲームのシーンをプレイ画面にする
		GameScene = GAME_SCENE_SETUMEI;

		return;
	}

	return;
}

//スタート画面の描画
VOID MY_START_DRAW(VOID)
{
	DrawGraph(imageBACK.x, imageBACK.y, imageBACK.handle, TRUE);
	/*DrawExtendGraph(imageBACK.x, imageBACK.y, 1136, 640, imageBACK.handle, TRUE);*/
	return;
}

VOID MY_SETUMEI(VOID)
{
	MY_START_SETUMEI_DRAW();//説明画面の描画
}
//説明画面の描画
VOID MY_START_SETUMEI_DRAW(VOID)
{
	DrawGraph(ImageSetumei.x, ImageSetumei.y, ImageSetumei.handle, TRUE);
	DrawString(0, 0, "スタート画面(Hキーを押して下さい)", GetColor(255, 255, 255));

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

//プレイ画面
VOID MY_PLAY(VOID)
{
	MY_PLAY_PROC();	//プレイ画面の処理
	MY_PLAY_DRAW();	//プレイ画面の描画

	DrawString(0, 0, "プレイ画面(スペースキーを押して下さい)", GetColor(255, 255, 255));
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

		////画面外にプレイヤーが行かないようにする
		//if (player.coll.top < 0) { player.image.x = 0; }
		//if (player.coll.top + player.coll.right > GAME_WIDTH) { player.image.x = GAME_WIDTH - player.image.width; }
		//if (player.coll.bottom < 0) { player.image.y = 0; }
		//if (player.coll.bottom + player.coll.left > GAME_HEIGHT) { player.image.y = GAME_HEIGHT - player.image.height; }
	
	

	return;
}

//プレイ画面の描画
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

			//虚無のとき
			DrawGraph(yoko * mapChip.width,
				tate * mapChip.height,
				mapChip.handle[mapdata3[tate][yoko]],
				TRUE);


		}

	}
	
	
	
	DrawGraph(player.image.x, player.image.y, playerhandle[13], TRUE);

	//当たり判定の描画（デバッグ用）
	for (int tate = 0; tate < MAP_HEIGHT_MAX; tate++)
	{
		for (int yoko = 0; yoko < MAP_WIDTH_MAX; yoko++)
		{
			//ダンボールならば
			if (mapdata3[tate][yoko] == d)
			{
				DrawBox(mapColl[tate][yoko].left, mapColl[tate][yoko].top, mapColl[tate][yoko].right, mapColl[tate][yoko].bottom, GetColor(255, 0, 0), FALSE);
			}

		}
	}
	//ゴール当たり判定用
	DrawBox(GoalRect.left, GoalRect.top, GoalRect.right, GoalRect.bottom, GetColor(255, 255, 0), TRUE);
	//プレイヤーの当たり判定用
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




		/*GameScene = GAME_SCENE_PLAY2;*/
		

		return;	//強制的にエンド画面に飛ぶ
	}

	if (MY_CHECK_RECT_COLL(PlayerRect, Modoru) == TRUE)
	{



		player.CenterX = ModoruPt.x;
		player.CenterY = ModoruPt.y;


		player.image.x = player.CenterX;
		player.image.y = player.CenterY;

		GameScene = GAME_SCENE_PLAY;


		return;	//強制的にエンド画面に飛ぶ
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

	//当たり判定の描画（デバッグ用）
	for (int tate = 0; tate < MAP_HEIGHT_MAX; tate++)
	{
		for (int yoko = 0; yoko < MAP_WIDTH_MAX; yoko++)
		{
			//床ならば
			//if (MapData_RokaNoWalk[tate][yoko] == s)
			//{
			//	DrawBox(mapColl[tate][yoko].left, mapColl[tate][yoko].top, mapColl[tate][yoko].right, mapColl[tate][yoko].bottom, GetColor(0, 0, 255), FALSE);
			//}

			////ダンボールならば
			//if (MapData_Object[tate][yoko] == d)
			//{
			//	DrawBox(mapColl[tate][yoko].left, mapColl[tate][yoko].top, mapColl[tate][yoko].right, mapColl[tate][yoko].bottom, GetColor(255, 0, 0), FALSE);
			//}
			////上壁ならば
			//if (MapData_RokaNoWalk[tate][yoko] == t)
			//{
			//	DrawBox(mapColl[tate][yoko].left, mapColl[tate][yoko].top, mapColl[tate][yoko].right, mapColl[tate][yoko].bottom, GetColor(255, 0, 0), FALSE);
			//}
			////中壁
			//if (MapData_RokaNoWalk[tate][yoko] == g)
			//{
			//	DrawBox(mapColl[tate][yoko].left, mapColl[tate][yoko].top, mapColl[tate][yoko].right, mapColl[tate][yoko].bottom, GetColor(255, 0, 0), FALSE);
			//}

			////床ならば
			//if (MapData_NoWalk[tate][yoko] == s)
			//{
			//	DrawBox(mapColl[tate][yoko].left, mapColl[tate][yoko].top, mapColl[tate][yoko].right, mapColl[tate][yoko].bottom, GetColor(0, 0, 255), FALSE);
			//}

			////ダンボールならば
			//if (MapData_Object[tate][yoko] == d)
			//{
			//	DrawBox(mapColl[tate][yoko].left, mapColl[tate][yoko].top, mapColl[tate][yoko].right, mapColl[tate][yoko].bottom, GetColor(255, 0, 0), FALSE);
			//}
			////上壁ならば
			//if (MapData_NoWalk[tate][yoko] == t)
			//{
			//	DrawBox(mapColl[tate][yoko].left, mapColl[tate][yoko].top, mapColl[tate][yoko].right, mapColl[tate][yoko].bottom, GetColor(255, 0, 0), FALSE);
			//}
			////中壁
			if (mapdata6[tate][yoko] == M)
			{
				DrawBox(mapColl[tate][yoko].left, mapColl[tate][yoko].top, mapColl[tate][yoko].right, mapColl[tate][yoko].bottom, GetColor(255, 0, 0), FALSE);
			}

		}
	}
	//ゴール当たり判定用
	DrawBox(GoalRect2.left, GoalRect2.top, GoalRect2.right, GoalRect2.bottom, GetColor(255, 255, 0), TRUE);
	//プレイヤーの当たり判定用
	DrawBox(player.coll.left, player.coll.top, player.coll.right, player.coll.bottom, GetColor(255, 0, 0), FALSE);
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

	DrawString(0, 0, "エンド画面(エスケープキーを押して下さい)", GetColor(255, 255, 255));
	return;
}

//エンド画面の描画
VOID MY_END_DRAW(VOID)
{

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

	int mapRes = LoadDivGraph(
		GAME_MAP_PATH,										//赤弾のパス
		MAP_DIV_NUM, MAP_DIV_TATE, MAP_DIV_YOKO,			//赤弾を分割する数
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

	for (int tate = 0; tate < MAP_HEIGHT_MAX; tate++)
	{
		for (int yoko = 0; yoko < MAP_WIDTH_MAX; yoko++)
		{
			//マップデータ初期化用に情報をコピー
			mapDataInit[tate][yoko] = MapData[tate][yoko];

			//マップの種類をコピー
			map[tate][yoko].kind = MapData[tate][yoko];

			//マップの幅と高さをコピー
			map[tate][yoko].width = mapChip.width;
			map[tate][yoko].height = mapChip.height;

			//マップの座標を設定
			map[tate][yoko].x = yoko * map[tate][yoko].width;
			map[tate][yoko].y = tate * map[tate][yoko].height;
		}
	}

	int mapRes2 =LoadDivGraph(
		GAME_MAP_PATH,										//赤弾のパス
		MAP_DIV_NUM, MAP_DIV_TATE, MAP_DIV_YOKO,			//赤弾を分割する数
		MAP_DIV_WIDTH, MAP_DIV_HEIGHT,						//画像を分割するの幅と高さ
		&mapChip_Nowalk.handle[0]);								//分割した画像が入るハンドル

	if (mapRes2 == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), GAME_MAP_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	GetGraphSize(mapChip_Nowalk.handle[0], &mapChip_Nowalk.width, &mapChip_Nowalk.height);
	for (int tate = 0; tate < MAP_HEIGHT_MAX; tate++)
	{
		for (int yoko = 0; yoko < MAP_WIDTH_MAX; yoko++)
		{
			//マップデータ初期化用に情報をコピー
			mapDataInit_Nowalk[tate][yoko] = MapData_NoWalk[tate][yoko];

			//マップの種類をコピー
			map2[tate][yoko].kind = MapData_NoWalk[tate][yoko];

			//マップの幅と高さをコピー
			map2[tate][yoko].width = mapChip.width;
			map2[tate][yoko].height = mapChip.height;

			//マップの座標を設定
			map2[tate][yoko].x = yoko * map2[tate][yoko].width;
			map2[tate][yoko].y = tate * map2[tate][yoko].height;
		}
	}


	


	int mapRes3 = LoadDivGraph(
		GAME_MAP_PATH,										//赤弾のパス
		MAP_DIV_NUM, MAP_DIV_TATE, MAP_DIV_YOKO,			//赤弾を分割する数
		MAP_DIV_WIDTH, MAP_DIV_HEIGHT,						//画像を分割するの幅と高さ
		&mapChip_Object.handle[0]);								//分割した画像が入るハンドル

	if (mapRes3 == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), GAME_MAP_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	GetGraphSize(mapChip_Object.handle[0], &mapChip_Object.width, &mapChip_Object.height);
	for (int tate = 0; tate < MAP_HEIGHT_MAX; tate++)
	{
		for (int yoko = 0; yoko < MAP_WIDTH_MAX; yoko++)
		{
			//マップデータ初期化用に情報をコピー
			mapDataInit_Object[tate][yoko] = MapData_Object[tate][yoko];

			//マップの種類をコピー
			map3[tate][yoko].kind = MapData_Object[tate][yoko];

			//マップの幅と高さをコピー
			map3[tate][yoko].width = mapChip.width;
			map3[tate][yoko].height = mapChip.height;

			//マップの座標を設定
			map3[tate][yoko].x = yoko * map3[tate][yoko].width;
			map3[tate][yoko].y = tate * map3[tate][yoko].height;
		}
	}

	LoadDivGraph(
		GAME_PLAYER_PATH,										//プレイヤーのパス
		PLAYER_DIV_NUM, PLAYER_DIV_TATE, PLAYER_DIV_YOKO,			//赤弾を分割する数
		PLAYER_DIV_WIDTH, PLAYER_DIV_HEIGHT,						//画像を分割するの幅と高さ
		&playerhandle[0]);								//分割した画像が入るハンドル

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

	LoadDivGraph(
		GAME_MAP_PATH,										//廊下のパス
		MAP_DIV_NUM, MAP_DIV_TATE, MAP_DIV_YOKO,			//マップチップを分割する数
		MAP_DIV_WIDTH, MAP_DIV_HEIGHT,						//画像を分割するの幅と高さ
		&mapChip_Roka.handle[0]);								//分割した画像が入るハンドル

	GetGraphSize(mapChip_Roka.handle[0], &mapChip_Roka.width, &mapChip_Roka.height);
	for (int tate = 0; tate < MAP_HEIGHT_MAX; tate++)
	{
		for (int yoko = 0; yoko < MAP_WIDTH_MAX; yoko++)
		{
			//マップデータ初期化用に情報をコピー
			mapDataInit_Roka[tate][yoko] = MapData_Roka[tate][yoko];

			//マップの種類をコピー
			map4[tate][yoko].kind = MapData_Roka[tate][yoko];

			//マップの幅と高さをコピー
			map4[tate][yoko].width = mapChip.width;
			map4[tate][yoko].height = mapChip.height;

			//マップの座標を設定
			map4[tate][yoko].x = yoko * map4[tate][yoko].width;
			map4[tate][yoko].y = tate * map4[tate][yoko].height;
		}
	}

	LoadDivGraph(
		GAME_MAP_PATH,										//赤弾のパス
		MAP_DIV_NUM, MAP_DIV_TATE, MAP_DIV_YOKO,			//赤弾を分割する数
		MAP_DIV_WIDTH, MAP_DIV_HEIGHT,						//画像を分割するの幅と高さ
		&mapChip_RokaNowalk.handle[0]);								//分割した画像が入るハンドル

	GetGraphSize(mapChip_RokaNowalk.handle[0], &mapChip_RokaNowalk.width, &mapChip_RokaNowalk.height);
	for (int tate = 0; tate < MAP_HEIGHT_MAX; tate++)
	{
		for (int yoko = 0; yoko < MAP_WIDTH_MAX; yoko++)
		{
			//マップデータ初期化用に情報をコピー
			mapDataInit_RokaNoWalk[tate][yoko] = MapData_RokaNoWalk[tate][yoko];

			//マップの種類をコピー
			map5[tate][yoko].kind = MapData_RokaNoWalk[tate][yoko];

			//マップの幅と高さをコピー
			map5[tate][yoko].width = mapChip.width;
			map5[tate][yoko].height = mapChip.height;

			//マップの座標を設定
			map5[tate][yoko].x = yoko * map5[tate][yoko].width;
			map5[tate][yoko].y = tate * map5[tate][yoko].height;
		}
	}
	return TRUE;
}

//画像をまとめて削除する関数
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

//音楽をまとめて読み込む関数
BOOL LOAD_MUSIC(VOID)
{

	return TRUE;
}

//音楽をまとめて削除する関数
VOID DELETE_MUSIC(VOID)
{

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
				/*if (GAME_SCENE_PLAY2 == TRUE)
				{
					return false;
				}*/
	
				//壁のときは、プレイヤーとマップが当たっている
				if (mapdata3[tate][yoko] == d) { return TRUE; }
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
			}
		}
	}

	return FALSE;
}

//領域の当たり判定をする関数
//BOOL MY_CHECK_RECT2_COLL(RECT a, RECT b)
//{
//	if (a.left < b.right &&
//		a.top < b.bottom &&
//		a.right > b.left &&
//		a.bottom > b.top
//		)
//	{
//		return TRUE;	//当たっている
//	}
//
//	return FALSE;		//当たっていない
//}

