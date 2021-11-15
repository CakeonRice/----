//=============================================================================
//
// エネミー処理 [enemy.cpp]
// Author : 
//
//=============================================================================
#include "enemy.h"
#include "texture.h"
#include "sprite.h"
#include "input.h"
#include "bg.h"
#include "main.h"
#include "player.h"
#include <time.h>

//*****************************************************************************
// マクロ定義
//*****************************************************************************
#define ROT_SPD				(0.05f)
#define ENEMY_SPD			(2.0f)
#define ENEMY_SIZE			(50.0f)
#define MOVE_TIMER			(50)
#define SERCH_RANGE			(200.0f)
#define FIND_SPD			(1.5f)
//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************


//*****************************************************************************
// グローバル変数
//*****************************************************************************
static int	g_EnemyTexture = 0;
static ENEMY g_Enemy;							  // エネミー構造体
static float MAPleft, MAPright, MAPtop, MAPunder; // エネミーの行動範囲
static int g_Enemy_Timer;
int moveX;
int moveY;

//=============================================================================
// 初期化処理
//=============================================================================
HRESULT InitEnemy(void)
{
	g_EnemyTexture = LoadTexture("data/TEXTURE/tako.png");

	MAPleft = SCREEN_WIDTH / 2 + HALF_CHIP + CHIP_SIZE * ((-MAP_SIZE_X / 2));
	MAPright = SCREEN_WIDTH / 2 - HALF_CHIP + CHIP_SIZE * ((MAP_SIZE_X / 2));

	MAPtop = SCREEN_HEIGHT / 2 + HALF_CHIP + CHIP_SIZE * ((-MAP_SIZE_Y / 2));
	MAPunder = SCREEN_HEIGHT / 2 - HALF_CHIP + CHIP_SIZE * ((MAP_SIZE_Y / 2));

	// エネミー構造体の初期化
	g_Enemy.use   = true;
	g_Enemy.w     = ENEMY_SIZE;
	g_Enemy.h     = ENEMY_SIZE;
	g_Enemy.pos   = D3DXVECTOR2(SCREEN_WIDTH / 2 , SCREEN_HEIGHT / 2 - 150.0f);
	g_Enemy.rot   = 0.0f;
	g_Enemy.vel   = D3DXVECTOR2(ENEMY_SPD,ENEMY_SPD);
	g_Enemy.state = 0;
	g_Enemy.frame = 0;

	g_Enemy_Timer = 0;
	
	return S_OK;
}

//=============================================================================
// 終了処理
//=============================================================================
void UninitEnemy(void)
{

}

//=============================================================================
// 更新処理
//=============================================================================
void UpdateEnemy(void)
{

	if (g_Enemy.use == true)
	{
		// 追跡判定
		if (SerchPlayer(GetPlayerPosition(), g_Enemy.pos))
		{// 見つけた(範囲内に入った)

			//現在位置
			D3DXVECTOR2 position = g_Enemy.pos;

			//目標地点
			D3DXVECTOR2 destination = GetPlayerPosition();

			//成分
			D3DXVECTOR2 components;

			//大きさ
			float magnitude;

			//方向（単位ベクトル）
			D3DXVECTOR2 direction;

			//成分計算
			components.x = destination.x - position.x;
			components.y = destination.y - position.y;

			//大きさ計算
			magnitude = (float)sqrt(components.x * components.x + components.y * components.y);

			//方向計算（正規化）
			direction.x = components.x / magnitude;
			direction.y = components.y / magnitude;

			//移動後の位置を計算
			g_Enemy.pos.x += direction.x * FIND_SPD;
			if (GetMapEnter(D3DXVECTOR2(g_Enemy.pos.x + direction.x * FIND_SPD, g_Enemy.pos.y),
				D3DXVECTOR2(g_Enemy.w, g_Enemy.h))
				== 1)
			{
				g_Enemy.pos.x -= direction.x * FIND_SPD;
			}

			g_Enemy.pos.y += direction.y * FIND_SPD;
			if (GetMapEnter(D3DXVECTOR2(g_Enemy.pos.x, g_Enemy.pos.y + direction.y * FIND_SPD),
				D3DXVECTOR2(g_Enemy.w, g_Enemy.h))
				== 1)
			{
				g_Enemy.pos.y -= direction.y * FIND_SPD;
			}

		}
		else // 見つけていない
		{
			g_Enemy_Timer++;

			if (g_Enemy_Timer > MOVE_TIMER)
			{
				moveX = rand() % 3;
				moveY = rand() % 3;
				g_Enemy_Timer = 0;
				srand((unsigned)time(NULL));
			}

			// エネミー横移動
			if (moveX == 1) // +(右)
			{
				g_Enemy.pos.x += g_Enemy.vel.x;
				if (GetMapEnter(D3DXVECTOR2(g_Enemy.pos.x + g_Enemy.vel.x, g_Enemy.pos.y),
					D3DXVECTOR2(g_Enemy.w, g_Enemy.h))
					== 1)
				{
					g_Enemy.pos.x -= g_Enemy.vel.x;
				}
			}
			if (moveX == 2) // -(左)
			{
				g_Enemy.pos.x -= g_Enemy.vel.x;
				if (GetMapEnter(D3DXVECTOR2(g_Enemy.pos.x - g_Enemy.vel.x, g_Enemy.pos.y),
					D3DXVECTOR2(g_Enemy.w, g_Enemy.h))
					== 1)
				{
					g_Enemy.pos.x += g_Enemy.vel.x;
				}
			}

			// エネミー縦移動
			if (moveY == 1) // +(下)
			{
				g_Enemy.pos.y += g_Enemy.vel.y;
				if (GetMapEnter(D3DXVECTOR2(g_Enemy.pos.x, g_Enemy.pos.y + g_Enemy.vel.y),
					D3DXVECTOR2(g_Enemy.w, g_Enemy.h))
					== 1)
				{
					g_Enemy.pos.y -= g_Enemy.vel.y;
				}
			}
			if (moveY == 2) // -(上)
			{
				g_Enemy.pos.y -= g_Enemy.vel.y;
				if (GetMapEnter(D3DXVECTOR2(g_Enemy.pos.x, g_Enemy.pos.y - g_Enemy.vel.y),
					D3DXVECTOR2(g_Enemy.w, g_Enemy.h))
					== 1)
				{
					g_Enemy.pos.y += g_Enemy.vel.y;
				}
			}
		}
		
		
		// 反射処理
		
		// 左端
		if (g_Enemy.pos.x <= MAPleft)
		{
			g_Enemy.pos.x = MAPleft;
		}
		// 右端
		if (g_Enemy.pos.x >= MAPright)
		{
			g_Enemy.pos.x = MAPright;
		}
		// 上端
		if (g_Enemy.pos.y <= MAPtop)
		{
			g_Enemy.pos.y = MAPtop;
		}
		// 下端
		if (g_Enemy.pos.y >= MAPunder)
		{
			g_Enemy.pos.y = MAPunder;
		}
		
		// 回転させる
		if ((1 % 2) == 0)
		{
			g_Enemy.rot += ROT_SPD;
		}
		else
		{
			g_Enemy.rot -= ROT_SPD;
		}
		//フレームの追加
		g_Enemy.frame++;
	}
	
}

//=============================================================================
// 描画処理
//=============================================================================
void DrawEnemy(void)
{
	if (g_Enemy.use == true)
	{
		//エネミーの位置やテクスチャー座標を反映
		float px = g_Enemy.pos.x;	// エネミーの表示位置X
		float py = g_Enemy.pos.y;	// エネミーの表示位置Y
		float pw = g_Enemy.w;		// エネミーの表示幅
		float ph = g_Enemy.h;		// エネミーの表示高さ
		D3DXCOLOR col;

		if (SerchPlayer(GetPlayerPosition(), g_Enemy.pos))
		{
			col = D3DXCOLOR(0.2f, 1.0f, 1.0f, 1.0f);
		}
		else
		{
			col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		}

		// １枚のポリゴンの頂点とテクスチャ座標を設定
		DrawSpriteColorRotate(g_EnemyTexture,px, py, pw, ph, 0.0f, 0.0f, 1.0f, 1.0f, col, g_Enemy.rot);
	}
	
}

//=============================================================================
// エネミー構造体の先頭アドレスを取得
//=============================================================================
ENEMY *GetEnemy(void)
{
	return &g_Enemy;
}


//=============================================================================
// 敵の発生処理
//=============================================================================
void SetEnemy(D3DXVECTOR2 pos)
{
	// もし未使用のデータを探す
	if (g_Enemy.use == false)		// 未使用状態の敵データを見つける
	{
		g_Enemy.use = true;			// 使用状態へ変更する
		g_Enemy.pos = pos;			// 座標をセット
		g_Enemy.rot = 0.0f;			// 回転角のリセット
		g_Enemy.state = 0;			// 状態をリセット
		g_Enemy.frame = 0;			// フレームのリセット
		return;						// 敵をセットできたので終了する
	}
	
}

bool SerchPlayer(D3DXVECTOR2 Playerpos, D3DXVECTOR2 Enemypos)
{
	D3DXVECTOR2 maxRange, minRange;

	minRange.x = Enemypos.x - SERCH_RANGE;
	minRange.y = Enemypos.y - SERCH_RANGE;
	maxRange.x = Enemypos.x + SERCH_RANGE;
	maxRange.y = Enemypos.y + SERCH_RANGE;

	//X軸の判定
	if (minRange.x < Playerpos.x &&
		maxRange.x > Playerpos.x)
	{
		//Y軸の判定
		if (minRange.y < Playerpos.y &&
			maxRange.y > Playerpos.y)
		{
			//全ての条件がTRUEならヒット判定
			return true;
		}
	}

	return false;
}