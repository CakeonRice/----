//=============================================================================
//
// 背景処理 [bg.cpp]
// Author : 古市
//
//=============================================================================
#include "bg.h"
#include "texture.h"
#include "sprite.h"


//*****************************************************************************
// マクロ定義
//*****************************************************************************
#define MAP_SIZE_X							(8)
#define MAP_SIZE_Y							(8)
#define CHIP_SIZE							(60.0f)
#define HALF_CHIP							(CHIP_SIZE / 2)

//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************
struct MAP_DATA_T 
{
	D3DXVECTOR2 uv;			//UV値
	int			stop = 0;	//侵入可能フラグ(1は進入禁止)

};

MAP_DATA_T g_MapInfo[3] =
{
	{ {0.625f,   0.0f}, 0},//地面
	{ {0.250f, 0.0f}, 0},  //なにもなし
	{ {0.625f, 0.625f}, 0},//切り株
};


//*****************************************************************************
// グローバル変数
//*****************************************************************************
int g_map_base[MAP_SIZE_X][MAP_SIZE_Y] = {
	//マップ０
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0},

};

int g_map_obj[MAP_SIZE_X][MAP_SIZE_Y] = {

	{1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,1},
	{1,0,0,1,1,0,0,1},
	{1,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,1},
	{1,0,1,0,0,1,0,1},
	{1,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1}
	
};

//マップの当たり判定用データ
int g_map_hitchk[MAP_SIZE_X][MAP_SIZE_Y] =
{
	{1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,1},
	{1,0,0,1,1,0,0,1},
	{1,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,1},
	{1,0,1,0,0,1,0,1},
	{1,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1}
};

static int g_Ground = 0;		// 背景用テクスチャ情報
static int g_Back = 0;

//=============================================================================
// 初期化処理
//=============================================================================
HRESULT InitBG(void)
{
	g_Ground = LoadTexture("data/TEXTURE/basechip.png");
	g_Back = LoadTexture("data/TEXTURE/back.jpg");

	return S_OK;
}

//=============================================================================
// 終了処理
//=============================================================================
void UninitBG(void)
{

}

//=============================================================================
// 更新処理
//=============================================================================
void UpdateBG(void)
{

}

//=============================================================================
// 描画処理
//=============================================================================
void DrawBG(void)
{
	DrawSpriteLeftTop(g_Back, 0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT, 0.0f, 0.0f, 1.0f, 1.0f);

	//マップの表示
	for (int y = 0; y < MAP_SIZE_Y; y++)
	{
		for (int x = 0; x < MAP_SIZE_X; x++)
		{
			float sx, sy;

			sx = SCREEN_WIDTH  / 2 + HALF_CHIP + CHIP_SIZE * ((-MAP_SIZE_X / 2) + x);
			sy = SCREEN_HEIGHT / 2 + HALF_CHIP + CHIP_SIZE * ((-MAP_SIZE_Y / 2) + y);
			DrawSprite(g_Ground,
				sx, sy,
				CHIP_SIZE, CHIP_SIZE, 
				0.0f, 0.0f, 0.125f, 0.125f);
		}
	}

	//オブジェクトの表示
	for (int y = 0; y < MAP_SIZE_Y; y++)
	{
		for (int x = 0; x < MAP_SIZE_X; x++)
		{
			MAP_DATA_T mapchip;
			mapchip = g_MapInfo[ g_map_obj[y][x] ];

			float sx, sy;
			sx = SCREEN_WIDTH  / 2 + HALF_CHIP + CHIP_SIZE * ((-MAP_SIZE_X / 2) + x);
			sy = SCREEN_HEIGHT / 2 + HALF_CHIP + CHIP_SIZE * ((-MAP_SIZE_Y / 2) + y);

			DrawSprite(g_Ground,
				sx, sy,
				CHIP_SIZE, CHIP_SIZE,
				mapchip.uv.x, mapchip.uv.y, 0.125f, 0.125f);
		}
	}
}

// マップの当たり判定 1がリターンされると押し返す
int GetMapEnter(D3DXVECTOR2 pos, D3DXVECTOR2 size)
{
	D3DXVECTOR2 min, max;
	
	min.x = pos.x - size.x / 2;
	min.y = pos.y - size.y / 2;
	max.x = pos.x + size.x / 2;
	max.y = pos.y + size.y / 2;

	int gx = 0;
	int gy = 0;

	float sx, sy;
	
	// 横軸
	for (int x = 0; x < MAP_SIZE_X; x++)
	{
		sx = SCREEN_WIDTH / 2 + (HALF_CHIP / 6 * 5) + CHIP_SIZE * ((-MAP_SIZE_X / 2) + x);

		if (min.x < sx + CHIP_SIZE && // プレイヤー小、マップ大
			max.x > sx)				  // プレイヤー大、マップ小
		{
			gx = x;
		}
	}

	// 縦軸
	for (int y = 0; y < MAP_SIZE_Y; y++)
	{
		sy = SCREEN_HEIGHT / 2 + (HALF_CHIP / 3) + CHIP_SIZE * ((-MAP_SIZE_Y / 2) + y);

		if (min.y < sy + CHIP_SIZE && // プレイヤー小、マップ大
			max.y > sy)				  // プレイヤー大、マップ小
		{
			gy = y;
		}
	}

	//左、上から

	return g_map_hitchk[gy][gx];
}