
#include "timer.h"
#include "texture.h"
#include "sprite.h"
#include "input.h"
#include "player.h"
#include "scene.h"
#include "fade.h"

#include <time.h>



//*****************************************************************************
// マクロ定義
//*****************************************************************************


//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************


//*****************************************************************************
// グローバル変数
//*****************************************************************************
static int	g_TimerTexture0 = 0;
static int	g_TimerTexture1 = 0;
static int	g_TimerTexture2 = 0;
static int	g_TimerTexture3 = 0;
static int	g_TimerTexture4 = 0;
static int	g_TimerTexture5 = 0;
static int	g_TimerTexture6 = 0;
static int	g_TimerTexture7 = 0;
static int	g_TimerTexture8 = 0;
static int	g_TimerTexture9 = 0;

TIMER g_Timer10m;
TIMER g_Timer1m;
TIMER g_Timer10s;
TIMER g_Timer1s;

DWORD g_Cnt;
DWORD g_Nextcnt;
int g_Gametime;



int m = 0;
int s = 0;

//=============================================================================
// 初期化処理
//=============================================================================




void InitTimer(void)
{
	g_TimerTexture0 = LoadTexture("data/TEXTURE/timer_0.png");
	g_TimerTexture1 = LoadTexture("data/TEXTURE/timer_1.png");
	g_TimerTexture2 = LoadTexture("data/TEXTURE/timer_2.png");
	g_TimerTexture3 = LoadTexture("data/TEXTURE/timer_3.png");
	g_TimerTexture4 = LoadTexture("data/TEXTURE/timer_4.png");
	g_TimerTexture5 = LoadTexture("data/TEXTURE/timer_5.png");
	g_TimerTexture6 = LoadTexture("data/TEXTURE/timer_6.png");
	g_TimerTexture7 = LoadTexture("data/TEXTURE/timer_7.png");
	g_TimerTexture8 = LoadTexture("data/TEXTURE/timer_8.png");
	g_TimerTexture9 = LoadTexture("data/TEXTURE/timer_9.png");

	g_Timer10m.pos.x = SCREEN_WIDTH  -180.0f;
	g_Timer10m.pos.y = 50.0f;
	g_Timer10m.size.x = 40.0f;
	g_Timer10m.size.y = 70.0f;

	g_Timer1m.pos.x = SCREEN_WIDTH  -140.0f;
	g_Timer1m.pos.y = 50.0f;
	g_Timer1m.size.x = 40.0f;
	g_Timer1m.size.y = 70.0f;

	g_Timer10s.pos.x = SCREEN_WIDTH  -90.0f;
	g_Timer10s.pos.y = 50.0f;
	g_Timer10s.size.x = 40.0f;
	g_Timer10s.size.y = 70.0f;

	g_Timer1s.pos.x = SCREEN_WIDTH  - 50.0f;
	g_Timer1s.pos.y = 50.0f;
	g_Timer1s.size.x = 40.0f;
	g_Timer1s.size.y = 70.0f;

	g_Cnt = 0;
	g_Nextcnt = 0;

	/*****************/
	  g_Gametime = 30;
	/*****************/


}
void UninitTimer(void)
{


}
void UpdateTimer(void)
{

	g_Cnt = timeGetTime();				// システム時刻を取得



		if ((g_Cnt - g_Nextcnt) >= 1000)	// 1秒ごとに実行
		{
			g_Nextcnt = g_Cnt;				// FPSを測定した時刻を保存

			m = g_Gametime / 60;
			s = g_Gametime % 60;


			g_Gametime--;
		}


	if (GetFadeState() == FADE_NONE && g_Gametime < 0
		//|| GetKeyboardTrigger(DIK_RETURN)
		) {

		//RESULTへ移行する
		SceneTransition(SCENE_RESULT);
	}


}
void DrawTimer(void)
{

	D3DXCOLOR col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);


	if (m == 20)
	{
			DrawSpriteColorRotate(g_TimerTexture2,
				g_Timer10m.pos.x, g_Timer10m.pos.y,
				g_Timer10m.size.x, g_Timer10m.size.y,
				0.0f, 0.0f,
				1.0f, 1.0f,
				col, g_Timer10m.rot);

			DrawSpriteColorRotate(g_TimerTexture0,
				g_Timer1m.pos.x, g_Timer1m.pos.y,
				g_Timer1m.size.x, g_Timer1m.size.y,
				0.0f, 0.0f,
				1.0f, 1.0f,
				col, g_Timer1m.rot);
	}
	if (m == 19)
	{
		DrawSpriteColorRotate(g_TimerTexture1,
			g_Timer10m.pos.x, g_Timer10m.pos.y,
			g_Timer10m.size.x, g_Timer10m.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer10m.rot);

		DrawSpriteColorRotate(g_TimerTexture9,
			g_Timer1m.pos.x, g_Timer1m.pos.y,
			g_Timer1m.size.x, g_Timer1m.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer1m.rot);
	}
	if (m == 18)
	{
		DrawSpriteColorRotate(g_TimerTexture1,
			g_Timer10m.pos.x, g_Timer10m.pos.y,
			g_Timer10m.size.x, g_Timer10m.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer10m.rot);

		DrawSpriteColorRotate(g_TimerTexture8,
			g_Timer1m.pos.x, g_Timer1m.pos.y,
			g_Timer1m.size.x, g_Timer1m.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer1m.rot);
	}
	if (m == 17)
	{
		DrawSpriteColorRotate(g_TimerTexture1,
			g_Timer10m.pos.x, g_Timer10m.pos.y,
			g_Timer10m.size.x, g_Timer10m.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer10m.rot);

		DrawSpriteColorRotate(g_TimerTexture7,
			g_Timer1m.pos.x, g_Timer1m.pos.y,
			g_Timer1m.size.x, g_Timer1m.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer1m.rot);
	}
	if (m == 16)
	{
		DrawSpriteColorRotate(g_TimerTexture1,
			g_Timer10m.pos.x, g_Timer10m.pos.y,
			g_Timer10m.size.x, g_Timer10m.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer10m.rot);

		DrawSpriteColorRotate(g_TimerTexture6,
			g_Timer1m.pos.x, g_Timer1m.pos.y,
			g_Timer1m.size.x, g_Timer1m.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer1m.rot);
	}
	if (m == 15)
	{
		DrawSpriteColorRotate(g_TimerTexture1,
			g_Timer10m.pos.x, g_Timer10m.pos.y,
			g_Timer10m.size.x, g_Timer10m.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer10m.rot);

		DrawSpriteColorRotate(g_TimerTexture5,
			g_Timer1m.pos.x, g_Timer1m.pos.y,
			g_Timer1m.size.x, g_Timer1m.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer1m.rot);
	}
	if (m == 14)
	{
		DrawSpriteColorRotate(g_TimerTexture1,
			g_Timer10m.pos.x, g_Timer10m.pos.y,
			g_Timer10m.size.x, g_Timer10m.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer10m.rot);

		DrawSpriteColorRotate(g_TimerTexture4,
			g_Timer1m.pos.x, g_Timer1m.pos.y,
			g_Timer1m.size.x, g_Timer1m.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer1m.rot);
	}
	if (m == 13)
	{
		DrawSpriteColorRotate(g_TimerTexture1,
			g_Timer10m.pos.x, g_Timer10m.pos.y,
			g_Timer10m.size.x, g_Timer10m.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer10m.rot);

		DrawSpriteColorRotate(g_TimerTexture3,
			g_Timer1m.pos.x, g_Timer1m.pos.y,
			g_Timer1m.size.x, g_Timer1m.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer1m.rot);
	}
	if (m == 12)
	{
		DrawSpriteColorRotate(g_TimerTexture1,
			g_Timer10m.pos.x, g_Timer10m.pos.y,
			g_Timer10m.size.x, g_Timer10m.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer10m.rot);

		DrawSpriteColorRotate(g_TimerTexture2,
			g_Timer1m.pos.x, g_Timer1m.pos.y,
			g_Timer1m.size.x, g_Timer1m.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer1m.rot);
	}
	if (m == 11)
	{
		DrawSpriteColorRotate(g_TimerTexture1,
			g_Timer10m.pos.x, g_Timer10m.pos.y,
			g_Timer10m.size.x, g_Timer10m.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer10m.rot);

		DrawSpriteColorRotate(g_TimerTexture1,
			g_Timer1m.pos.x, g_Timer1m.pos.y,
			g_Timer1m.size.x, g_Timer1m.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer1m.rot);
	}
	if (m == 10)
	{
		DrawSpriteColorRotate(g_TimerTexture1,
			g_Timer10m.pos.x, g_Timer10m.pos.y,
			g_Timer10m.size.x, g_Timer10m.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer10m.rot);

		DrawSpriteColorRotate(g_TimerTexture8,
			g_Timer1m.pos.x, g_Timer1m.pos.y,
			g_Timer1m.size.x, g_Timer1m.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer1m.rot);
	}
	if (m ==  9)
	{
		DrawSpriteColorRotate(g_TimerTexture0,
			g_Timer10m.pos.x, g_Timer10m.pos.y,
			g_Timer10m.size.x, g_Timer10m.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer10m.rot);

		DrawSpriteColorRotate(g_TimerTexture9,
			g_Timer1m.pos.x, g_Timer1m.pos.y,
			g_Timer1m.size.x, g_Timer1m.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer1m.rot);
	}
	if (m ==  8)
	{
		DrawSpriteColorRotate(g_TimerTexture0,
			g_Timer10m.pos.x, g_Timer10m.pos.y,
			g_Timer10m.size.x, g_Timer10m.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer10m.rot);

		DrawSpriteColorRotate(g_TimerTexture8,
			g_Timer1m.pos.x, g_Timer1m.pos.y,
			g_Timer1m.size.x, g_Timer1m.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer1m.rot);
	}
	if (m ==  7)
	{
		DrawSpriteColorRotate(g_TimerTexture0,
			g_Timer10m.pos.x, g_Timer10m.pos.y,
			g_Timer10m.size.x, g_Timer10m.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer10m.rot);

		DrawSpriteColorRotate(g_TimerTexture7,
			g_Timer1m.pos.x, g_Timer1m.pos.y,
			g_Timer1m.size.x, g_Timer1m.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer1m.rot);
	}
	if (m ==  6)
	{
		DrawSpriteColorRotate(g_TimerTexture0,
			g_Timer10m.pos.x, g_Timer10m.pos.y,
			g_Timer10m.size.x, g_Timer10m.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer10m.rot);

		DrawSpriteColorRotate(g_TimerTexture6,
			g_Timer1m.pos.x, g_Timer1m.pos.y,
			g_Timer1m.size.x, g_Timer1m.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer1m.rot);
	}
	if (m ==  5)
	{
		DrawSpriteColorRotate(g_TimerTexture0,
			g_Timer10m.pos.x, g_Timer10m.pos.y,
			g_Timer10m.size.x, g_Timer10m.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer10m.rot);

		DrawSpriteColorRotate(g_TimerTexture5,
			g_Timer1m.pos.x, g_Timer1m.pos.y,
			g_Timer1m.size.x, g_Timer1m.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer1m.rot);
	}
	if (m ==  4)
	{
		DrawSpriteColorRotate(g_TimerTexture0,
			g_Timer10m.pos.x, g_Timer10m.pos.y,
			g_Timer10m.size.x, g_Timer10m.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer10m.rot);

		DrawSpriteColorRotate(g_TimerTexture4,
			g_Timer1m.pos.x, g_Timer1m.pos.y,
			g_Timer1m.size.x, g_Timer1m.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer1m.rot);
	}
	if (m ==  3)
	{
		DrawSpriteColorRotate(g_TimerTexture0,
			g_Timer10m.pos.x, g_Timer10m.pos.y,
			g_Timer10m.size.x, g_Timer10m.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer10m.rot);

		DrawSpriteColorRotate(g_TimerTexture3,
			g_Timer1m.pos.x, g_Timer1m.pos.y,
			g_Timer1m.size.x, g_Timer1m.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer1m.rot);
	}
	if (m ==  2)
	{
		DrawSpriteColorRotate(g_TimerTexture0,
			g_Timer10m.pos.x, g_Timer10m.pos.y,
			g_Timer10m.size.x, g_Timer10m.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer10m.rot);

		DrawSpriteColorRotate(g_TimerTexture2,
			g_Timer1m.pos.x, g_Timer1m.pos.y,
			g_Timer1m.size.x, g_Timer1m.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer1m.rot);
	}
	if (m ==  1)
	{
		DrawSpriteColorRotate(g_TimerTexture0,
			g_Timer10m.pos.x, g_Timer10m.pos.y,
			g_Timer10m.size.x, g_Timer10m.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer10m.rot);

		DrawSpriteColorRotate(g_TimerTexture1,
			g_Timer1m.pos.x, g_Timer1m.pos.y,
			g_Timer1m.size.x, g_Timer1m.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer1m.rot);
	}
	if (m ==  0)
	{
		DrawSpriteColorRotate(g_TimerTexture0,
			g_Timer10m.pos.x, g_Timer10m.pos.y,
			g_Timer10m.size.x, g_Timer10m.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer10m.rot);

		DrawSpriteColorRotate(g_TimerTexture0,
			g_Timer1m.pos.x, g_Timer1m.pos.y,
			g_Timer1m.size.x, g_Timer1m.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer1m.rot);
	}


	if (s ==  0)
	{
		DrawSpriteColorRotate(g_TimerTexture0,
			g_Timer10s.pos.x, g_Timer10s.pos.y,
			g_Timer10s.size.x, g_Timer10s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer10s.rot);

		DrawSpriteColorRotate(g_TimerTexture0,
			g_Timer1s.pos.x, g_Timer1s.pos.y,
			g_Timer1s.size.x, g_Timer1s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer1s.rot);
	}
	if (s ==  1)
	{
		DrawSpriteColorRotate(g_TimerTexture0,
			g_Timer10s.pos.x, g_Timer10s.pos.y,
			g_Timer10s.size.x, g_Timer10s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer10s.rot);

		DrawSpriteColorRotate(g_TimerTexture1,
			g_Timer1s.pos.x, g_Timer1s.pos.y,
			g_Timer1s.size.x, g_Timer1s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer1s.rot);
	}
	if (s ==  2)
	{
		DrawSpriteColorRotate(g_TimerTexture0,
			g_Timer10s.pos.x, g_Timer10s.pos.y,
			g_Timer10s.size.x, g_Timer10s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer10s.rot);

		DrawSpriteColorRotate(g_TimerTexture2,
			g_Timer1s.pos.x, g_Timer1s.pos.y,
			g_Timer1s.size.x, g_Timer1s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer1s.rot);
	}
	if (s ==  3)
	{
		DrawSpriteColorRotate(g_TimerTexture0,
			g_Timer10s.pos.x, g_Timer10s.pos.y,
			g_Timer10s.size.x, g_Timer10s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer10s.rot);

		DrawSpriteColorRotate(g_TimerTexture3,
			g_Timer1s.pos.x, g_Timer1s.pos.y,
			g_Timer1s.size.x, g_Timer1s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer1s.rot);
	}
	if (s ==  4)
	{
		DrawSpriteColorRotate(g_TimerTexture0,
			g_Timer10s.pos.x, g_Timer10s.pos.y,
			g_Timer10s.size.x, g_Timer10s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer10s.rot);

		DrawSpriteColorRotate(g_TimerTexture4,
			g_Timer1s.pos.x, g_Timer1s.pos.y,
			g_Timer1s.size.x, g_Timer1s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer1s.rot);
	}
	if (s ==  5)
	{
		DrawSpriteColorRotate(g_TimerTexture0,
			g_Timer10s.pos.x, g_Timer10s.pos.y,
			g_Timer10s.size.x, g_Timer10s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer10s.rot);

		DrawSpriteColorRotate(g_TimerTexture5,
			g_Timer1s.pos.x, g_Timer1s.pos.y,
			g_Timer1s.size.x, g_Timer1s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer1s.rot);
	}
	if (s ==  6)
	{
		DrawSpriteColorRotate(g_TimerTexture0,
			g_Timer10s.pos.x, g_Timer10s.pos.y,
			g_Timer10s.size.x, g_Timer10s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer10s.rot);

		DrawSpriteColorRotate(g_TimerTexture6,
			g_Timer1s.pos.x, g_Timer1s.pos.y,
			g_Timer1s.size.x, g_Timer1s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer1s.rot);
	}
	if (s ==  7)
	{
		DrawSpriteColorRotate(g_TimerTexture0,
			g_Timer10s.pos.x, g_Timer10s.pos.y,
			g_Timer10s.size.x, g_Timer10s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer10s.rot);

		DrawSpriteColorRotate(g_TimerTexture7,
			g_Timer1s.pos.x, g_Timer1s.pos.y,
			g_Timer1s.size.x, g_Timer1s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer1s.rot);
	}
	if (s ==  8)
	{
		DrawSpriteColorRotate(g_TimerTexture0,
			g_Timer10s.pos.x, g_Timer10s.pos.y,
			g_Timer10s.size.x, g_Timer10s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer10s.rot);

		DrawSpriteColorRotate(g_TimerTexture8,
			g_Timer1s.pos.x, g_Timer1s.pos.y,
			g_Timer1s.size.x, g_Timer1s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer1s.rot);
	}
	if (s ==  9)
	{
		DrawSpriteColorRotate(g_TimerTexture0,
			g_Timer10s.pos.x, g_Timer10s.pos.y,
			g_Timer10s.size.x, g_Timer10s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer10s.rot);

		DrawSpriteColorRotate(g_TimerTexture9,
			g_Timer1s.pos.x, g_Timer1s.pos.y,
			g_Timer1s.size.x, g_Timer1s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer1s.rot);
	}
	if (s == 10)
	{
		DrawSpriteColorRotate(g_TimerTexture1,
			g_Timer10s.pos.x, g_Timer10s.pos.y,
			g_Timer10s.size.x, g_Timer10s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer10s.rot);

		DrawSpriteColorRotate(g_TimerTexture0,
			g_Timer1s.pos.x, g_Timer1s.pos.y,
			g_Timer1s.size.x, g_Timer1s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer1s.rot);
	}
	if (s == 11)
	{
		DrawSpriteColorRotate(g_TimerTexture1,
			g_Timer10s.pos.x, g_Timer10s.pos.y,
			g_Timer10s.size.x, g_Timer10s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer10s.rot);

		DrawSpriteColorRotate(g_TimerTexture1,
			g_Timer1s.pos.x, g_Timer1s.pos.y,
			g_Timer1s.size.x, g_Timer1s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer1s.rot);
	}
	if (s == 12)
	{
		DrawSpriteColorRotate(g_TimerTexture1,
			g_Timer10s.pos.x, g_Timer10s.pos.y,
			g_Timer10s.size.x, g_Timer10s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer10s.rot);

		DrawSpriteColorRotate(g_TimerTexture2,
			g_Timer1s.pos.x, g_Timer1s.pos.y,
			g_Timer1s.size.x, g_Timer1s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer1s.rot);
	}
	if (s == 13)
	{
		DrawSpriteColorRotate(g_TimerTexture1,
			g_Timer10s.pos.x, g_Timer10s.pos.y,
			g_Timer10s.size.x, g_Timer10s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer10s.rot);

		DrawSpriteColorRotate(g_TimerTexture3,
			g_Timer1s.pos.x, g_Timer1s.pos.y,
			g_Timer1s.size.x, g_Timer1s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer1s.rot);
	}
	if (s == 14)
	{
		DrawSpriteColorRotate(g_TimerTexture1,
			g_Timer10s.pos.x, g_Timer10s.pos.y,
			g_Timer10s.size.x, g_Timer10s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer10s.rot);

		DrawSpriteColorRotate(g_TimerTexture4,
			g_Timer1s.pos.x, g_Timer1s.pos.y,
			g_Timer1s.size.x, g_Timer1s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer1s.rot);
	}
	if (s == 15)
	{
		DrawSpriteColorRotate(g_TimerTexture1,
			g_Timer10s.pos.x, g_Timer10s.pos.y,
			g_Timer10s.size.x, g_Timer10s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer10s.rot);

		DrawSpriteColorRotate(g_TimerTexture5,
			g_Timer1s.pos.x, g_Timer1s.pos.y,
			g_Timer1s.size.x, g_Timer1s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer1s.rot);
	}
	if (s == 16)
	{
		DrawSpriteColorRotate(g_TimerTexture1,
			g_Timer10s.pos.x, g_Timer10s.pos.y,
			g_Timer10s.size.x, g_Timer10s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer10s.rot);

		DrawSpriteColorRotate(g_TimerTexture6,
			g_Timer1s.pos.x, g_Timer1s.pos.y,
			g_Timer1s.size.x, g_Timer1s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer1s.rot);
	}
	if (s == 17)
	{
		DrawSpriteColorRotate(g_TimerTexture1,
			g_Timer10s.pos.x, g_Timer10s.pos.y,
			g_Timer10s.size.x, g_Timer10s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer10s.rot);

		DrawSpriteColorRotate(g_TimerTexture7,
			g_Timer1s.pos.x, g_Timer1s.pos.y,
			g_Timer1s.size.x, g_Timer1s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer1s.rot);
	}
	if (s == 18)
	{
		DrawSpriteColorRotate(g_TimerTexture1,
			g_Timer10s.pos.x, g_Timer10s.pos.y,
			g_Timer10s.size.x, g_Timer10s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer10s.rot);

		DrawSpriteColorRotate(g_TimerTexture8,
			g_Timer1s.pos.x, g_Timer1s.pos.y,
			g_Timer1s.size.x, g_Timer1s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer1s.rot);
	}
	if (s == 19)
	{
		DrawSpriteColorRotate(g_TimerTexture1,
			g_Timer10s.pos.x, g_Timer10s.pos.y,
			g_Timer10s.size.x, g_Timer10s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer10s.rot);

		DrawSpriteColorRotate(g_TimerTexture9,
			g_Timer1s.pos.x, g_Timer1s.pos.y,
			g_Timer1s.size.x, g_Timer1s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer1s.rot);
	}
	if (s == 20)
	{
		DrawSpriteColorRotate(g_TimerTexture2,
			g_Timer10s.pos.x, g_Timer10s.pos.y,
			g_Timer10s.size.x, g_Timer10s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer10s.rot);

		DrawSpriteColorRotate(g_TimerTexture0,
			g_Timer1s.pos.x, g_Timer1s.pos.y,
			g_Timer1s.size.x, g_Timer1s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer1s.rot);
	}
	if (s == 21)
	{
		DrawSpriteColorRotate(g_TimerTexture2,
			g_Timer10s.pos.x, g_Timer10s.pos.y,
			g_Timer10s.size.x, g_Timer10s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer10s.rot);

		DrawSpriteColorRotate(g_TimerTexture1,
			g_Timer1s.pos.x, g_Timer1s.pos.y,
			g_Timer1s.size.x, g_Timer1s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer1s.rot);
	}
	if (s == 22)
	{
		DrawSpriteColorRotate(g_TimerTexture2,
			g_Timer10s.pos.x, g_Timer10s.pos.y,
			g_Timer10s.size.x, g_Timer10s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer10s.rot);

		DrawSpriteColorRotate(g_TimerTexture2,
			g_Timer1s.pos.x, g_Timer1s.pos.y,
			g_Timer1s.size.x, g_Timer1s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer1s.rot);
	}
	if (s == 23)
	{
		DrawSpriteColorRotate(g_TimerTexture2,
			g_Timer10s.pos.x, g_Timer10s.pos.y,
			g_Timer10s.size.x, g_Timer10s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer10s.rot);

		DrawSpriteColorRotate(g_TimerTexture3,
			g_Timer1s.pos.x, g_Timer1s.pos.y,
			g_Timer1s.size.x, g_Timer1s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer1s.rot);
	}
	if (s == 24)
{
		DrawSpriteColorRotate(g_TimerTexture2,
			g_Timer10s.pos.x, g_Timer10s.pos.y,
			g_Timer10s.size.x, g_Timer10s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer10s.rot);

		DrawSpriteColorRotate(g_TimerTexture4,
			g_Timer1s.pos.x, g_Timer1s.pos.y,
			g_Timer1s.size.x, g_Timer1s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer1s.rot);
	}
	if (s == 25)
	{
		DrawSpriteColorRotate(g_TimerTexture2,
			g_Timer10s.pos.x, g_Timer10s.pos.y,
			g_Timer10s.size.x, g_Timer10s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer10s.rot);

		DrawSpriteColorRotate(g_TimerTexture5,
			g_Timer1s.pos.x, g_Timer1s.pos.y,
			g_Timer1s.size.x, g_Timer1s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer1s.rot);
	}
	if (s == 26)
	{
		DrawSpriteColorRotate(g_TimerTexture2,
			g_Timer10s.pos.x, g_Timer10s.pos.y,
			g_Timer10s.size.x, g_Timer10s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer10s.rot);

		DrawSpriteColorRotate(g_TimerTexture6,
			g_Timer1s.pos.x, g_Timer1s.pos.y,
			g_Timer1s.size.x, g_Timer1s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer1s.rot);
	}
	if (s == 27)
	{
		DrawSpriteColorRotate(g_TimerTexture2,
			g_Timer10s.pos.x, g_Timer10s.pos.y,
			g_Timer10s.size.x, g_Timer10s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer10s.rot);

		DrawSpriteColorRotate(g_TimerTexture7,
			g_Timer1s.pos.x, g_Timer1s.pos.y,
			g_Timer1s.size.x, g_Timer1s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer1s.rot);
	}
	if (s == 28)
	{
		DrawSpriteColorRotate(g_TimerTexture2,
			g_Timer10s.pos.x, g_Timer10s.pos.y,
			g_Timer10s.size.x, g_Timer10s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer10s.rot);

		DrawSpriteColorRotate(g_TimerTexture8,
			g_Timer1s.pos.x, g_Timer1s.pos.y,
			g_Timer1s.size.x, g_Timer1s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer1s.rot);
	}
	if (s == 29)
	{
		DrawSpriteColorRotate(g_TimerTexture2,
			g_Timer10s.pos.x, g_Timer10s.pos.y,
			g_Timer10s.size.x, g_Timer10s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer10s.rot);

		DrawSpriteColorRotate(g_TimerTexture9,
			g_Timer1s.pos.x, g_Timer1s.pos.y,
			g_Timer1s.size.x, g_Timer1s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer1s.rot);
	}
	if (s == 30)
	{
		DrawSpriteColorRotate(g_TimerTexture3,
			g_Timer10s.pos.x, g_Timer10s.pos.y,
			g_Timer10s.size.x, g_Timer10s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer10s.rot);

		DrawSpriteColorRotate(g_TimerTexture0,
			g_Timer1s.pos.x, g_Timer1s.pos.y,
			g_Timer1s.size.x, g_Timer1s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer1s.rot);
	}
	if (s == 31)
	{
		DrawSpriteColorRotate(g_TimerTexture3,
			g_Timer10s.pos.x, g_Timer10s.pos.y,
			g_Timer10s.size.x, g_Timer10s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer10s.rot);

		DrawSpriteColorRotate(g_TimerTexture1,
			g_Timer1s.pos.x, g_Timer1s.pos.y,
			g_Timer1s.size.x, g_Timer1s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer1s.rot);
	}
	if (s == 32)
	{
		DrawSpriteColorRotate(g_TimerTexture3,
			g_Timer10s.pos.x, g_Timer10s.pos.y,
			g_Timer10s.size.x, g_Timer10s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer10s.rot);

		DrawSpriteColorRotate(g_TimerTexture2,
			g_Timer1s.pos.x, g_Timer1s.pos.y,
			g_Timer1s.size.x, g_Timer1s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer1s.rot);
	}
	if (s == 33)
	{
		DrawSpriteColorRotate(g_TimerTexture3,
			g_Timer10s.pos.x, g_Timer10s.pos.y,
			g_Timer10s.size.x, g_Timer10s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer10s.rot);

		DrawSpriteColorRotate(g_TimerTexture3,
			g_Timer1s.pos.x, g_Timer1s.pos.y,
			g_Timer1s.size.x, g_Timer1s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer1s.rot);
	}
	if (s == 34)
	{
		DrawSpriteColorRotate(g_TimerTexture3,
			g_Timer10s.pos.x, g_Timer10s.pos.y,
			g_Timer10s.size.x, g_Timer10s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer10s.rot);

		DrawSpriteColorRotate(g_TimerTexture4,
			g_Timer1s.pos.x, g_Timer1s.pos.y,
			g_Timer1s.size.x, g_Timer1s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer1s.rot);
	}
	if (s == 35)
	{
		DrawSpriteColorRotate(g_TimerTexture3,
			g_Timer10s.pos.x, g_Timer10s.pos.y,
			g_Timer10s.size.x, g_Timer10s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer10s.rot);

		DrawSpriteColorRotate(g_TimerTexture5,
			g_Timer1s.pos.x, g_Timer1s.pos.y,
			g_Timer1s.size.x, g_Timer1s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer1s.rot);
	}
	if (s == 36)
	{
		DrawSpriteColorRotate(g_TimerTexture3,
			g_Timer10s.pos.x, g_Timer10s.pos.y,
			g_Timer10s.size.x, g_Timer10s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer10s.rot);

		DrawSpriteColorRotate(g_TimerTexture6,
			g_Timer1s.pos.x, g_Timer1s.pos.y,
			g_Timer1s.size.x, g_Timer1s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer1s.rot);
	}
	if (s == 37)
	{
		DrawSpriteColorRotate(g_TimerTexture3,
			g_Timer10s.pos.x, g_Timer10s.pos.y,
			g_Timer10s.size.x, g_Timer10s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer10s.rot);

		DrawSpriteColorRotate(g_TimerTexture7,
			g_Timer1s.pos.x, g_Timer1s.pos.y,
			g_Timer1s.size.x, g_Timer1s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer1s.rot);
	}
	if (s == 38){
		DrawSpriteColorRotate(g_TimerTexture3,
			g_Timer10s.pos.x, g_Timer10s.pos.y,
			g_Timer10s.size.x, g_Timer10s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer10s.rot);

		DrawSpriteColorRotate(g_TimerTexture8,
			g_Timer1s.pos.x, g_Timer1s.pos.y,
			g_Timer1s.size.x, g_Timer1s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer1s.rot);
	}
	if (s == 39)
	{
		DrawSpriteColorRotate(g_TimerTexture3,
			g_Timer10s.pos.x, g_Timer10s.pos.y,
			g_Timer10s.size.x, g_Timer10s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer10s.rot);

		DrawSpriteColorRotate(g_TimerTexture9,
			g_Timer1s.pos.x, g_Timer1s.pos.y,
			g_Timer1s.size.x, g_Timer1s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer1s.rot);
	}
	if (s == 40)
	{
		DrawSpriteColorRotate(g_TimerTexture4,
			g_Timer10s.pos.x, g_Timer10s.pos.y,
			g_Timer10s.size.x, g_Timer10s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer10s.rot);

		DrawSpriteColorRotate(g_TimerTexture0,
			g_Timer1s.pos.x, g_Timer1s.pos.y,
			g_Timer1s.size.x, g_Timer1s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer1s.rot);
	}
	if (s == 41)	{
		DrawSpriteColorRotate(g_TimerTexture4,
			g_Timer10s.pos.x, g_Timer10s.pos.y,
			g_Timer10s.size.x, g_Timer10s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer10s.rot);

		DrawSpriteColorRotate(g_TimerTexture1,
			g_Timer1s.pos.x, g_Timer1s.pos.y,
			g_Timer1s.size.x, g_Timer1s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer1s.rot);
	}
	if (s == 42)
	{
		DrawSpriteColorRotate(g_TimerTexture4,
			g_Timer10s.pos.x, g_Timer10s.pos.y,
			g_Timer10s.size.x, g_Timer10s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer10s.rot);

		DrawSpriteColorRotate(g_TimerTexture2,
			g_Timer1s.pos.x, g_Timer1s.pos.y,
			g_Timer1s.size.x, g_Timer1s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer1s.rot);
	}
	if (s == 43)
	{
		DrawSpriteColorRotate(g_TimerTexture4,
			g_Timer10s.pos.x, g_Timer10s.pos.y,
			g_Timer10s.size.x, g_Timer10s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer10s.rot);

		DrawSpriteColorRotate(g_TimerTexture3,
			g_Timer1s.pos.x, g_Timer1s.pos.y,
			g_Timer1s.size.x, g_Timer1s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer1s.rot);
	}
	if (s == 44)
	{
		DrawSpriteColorRotate(g_TimerTexture4,
			g_Timer10s.pos.x, g_Timer10s.pos.y,
			g_Timer10s.size.x, g_Timer10s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer10s.rot);

		DrawSpriteColorRotate(g_TimerTexture4,
			g_Timer1s.pos.x, g_Timer1s.pos.y,
			g_Timer1s.size.x, g_Timer1s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer1s.rot);
	}
	if (s == 45)
	{
		DrawSpriteColorRotate(g_TimerTexture4,
			g_Timer10s.pos.x, g_Timer10s.pos.y,
			g_Timer10s.size.x, g_Timer10s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer10s.rot);

		DrawSpriteColorRotate(g_TimerTexture5,
			g_Timer1s.pos.x, g_Timer1s.pos.y,
			g_Timer1s.size.x, g_Timer1s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer1s.rot);
	}
	if (s == 46)
	{
		DrawSpriteColorRotate(g_TimerTexture4,
			g_Timer10s.pos.x, g_Timer10s.pos.y,
			g_Timer10s.size.x, g_Timer10s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer10s.rot);

		DrawSpriteColorRotate(g_TimerTexture6,
			g_Timer1s.pos.x, g_Timer1s.pos.y,
			g_Timer1s.size.x, g_Timer1s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer1s.rot);
	}
	if (s == 47)
	{
		DrawSpriteColorRotate(g_TimerTexture4,
			g_Timer10s.pos.x, g_Timer10s.pos.y,
			g_Timer10s.size.x, g_Timer10s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer10s.rot);

		DrawSpriteColorRotate(g_TimerTexture7,
			g_Timer1s.pos.x, g_Timer1s.pos.y,
			g_Timer1s.size.x, g_Timer1s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer1s.rot);
	}
	if (s == 48)
	{
		DrawSpriteColorRotate(g_TimerTexture4,
			g_Timer10s.pos.x, g_Timer10s.pos.y,
			g_Timer10s.size.x, g_Timer10s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer10s.rot);

		DrawSpriteColorRotate(g_TimerTexture8,
			g_Timer1s.pos.x, g_Timer1s.pos.y,
			g_Timer1s.size.x, g_Timer1s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer1s.rot);
	}
	if (s == 49)
	{
		DrawSpriteColorRotate(g_TimerTexture4,
			g_Timer10s.pos.x, g_Timer10s.pos.y,
			g_Timer10s.size.x, g_Timer10s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer10s.rot);

		DrawSpriteColorRotate(g_TimerTexture9,
			g_Timer1s.pos.x, g_Timer1s.pos.y,
			g_Timer1s.size.x, g_Timer1s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer1s.rot);
	}
	if (s == 50)
	{
		DrawSpriteColorRotate(g_TimerTexture5,
			g_Timer10s.pos.x, g_Timer10s.pos.y,
			g_Timer10s.size.x, g_Timer10s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer10s.rot);

		DrawSpriteColorRotate(g_TimerTexture0,
			g_Timer1s.pos.x, g_Timer1s.pos.y,
			g_Timer1s.size.x, g_Timer1s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer1s.rot);
	}
	if (s == 51)
	{
		DrawSpriteColorRotate(g_TimerTexture5,
			g_Timer10s.pos.x, g_Timer10s.pos.y,
			g_Timer10s.size.x, g_Timer10s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer10s.rot);

		DrawSpriteColorRotate(g_TimerTexture1,
			g_Timer1s.pos.x, g_Timer1s.pos.y,
			g_Timer1s.size.x, g_Timer1s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer1s.rot);
	}
	if (s == 52)
	{
		DrawSpriteColorRotate(g_TimerTexture5,
			g_Timer10s.pos.x, g_Timer10s.pos.y,
			g_Timer10s.size.x, g_Timer10s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer10s.rot);

		DrawSpriteColorRotate(g_TimerTexture2,
			g_Timer1s.pos.x, g_Timer1s.pos.y,
			g_Timer1s.size.x, g_Timer1s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer1s.rot);
	}
	if (s == 53)
	{
		DrawSpriteColorRotate(g_TimerTexture5,
			g_Timer10s.pos.x, g_Timer10s.pos.y,
			g_Timer10s.size.x, g_Timer10s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer10s.rot);

		DrawSpriteColorRotate(g_TimerTexture3,
			g_Timer1s.pos.x, g_Timer1s.pos.y,
			g_Timer1s.size.x, g_Timer1s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer1s.rot);
	}
	if (s == 54)
	{
		DrawSpriteColorRotate(g_TimerTexture5,
			g_Timer10s.pos.x, g_Timer10s.pos.y,
			g_Timer10s.size.x, g_Timer10s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer10s.rot);

		DrawSpriteColorRotate(g_TimerTexture4,
			g_Timer1s.pos.x, g_Timer1s.pos.y,
			g_Timer1s.size.x, g_Timer1s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer1s.rot);
	}
	if (s == 55)
	{
		DrawSpriteColorRotate(g_TimerTexture5,
			g_Timer10s.pos.x, g_Timer10s.pos.y,
			g_Timer10s.size.x, g_Timer10s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer10s.rot);

		DrawSpriteColorRotate(g_TimerTexture5,
			g_Timer1s.pos.x, g_Timer1s.pos.y,
			g_Timer1s.size.x, g_Timer1s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer1s.rot);
	}
	if (s == 56)
	{
		DrawSpriteColorRotate(g_TimerTexture5,
			g_Timer10s.pos.x, g_Timer10s.pos.y,
			g_Timer10s.size.x, g_Timer10s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer10s.rot);

		DrawSpriteColorRotate(g_TimerTexture6,
			g_Timer1s.pos.x, g_Timer1s.pos.y,
			g_Timer1s.size.x, g_Timer1s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer1s.rot);
	}
	if (s == 57)	{
		DrawSpriteColorRotate(g_TimerTexture5,
			g_Timer10s.pos.x, g_Timer10s.pos.y,
			g_Timer10s.size.x, g_Timer10s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer10s.rot);

		DrawSpriteColorRotate(g_TimerTexture7,
			g_Timer1s.pos.x, g_Timer1s.pos.y,
			g_Timer1s.size.x, g_Timer1s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer1s.rot);
	}
	if (s == 58)
	{
		DrawSpriteColorRotate(g_TimerTexture5,
			g_Timer10s.pos.x, g_Timer10s.pos.y,
			g_Timer10s.size.x, g_Timer10s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer10s.rot);

		DrawSpriteColorRotate(g_TimerTexture8,
			g_Timer1s.pos.x, g_Timer1s.pos.y,
			g_Timer1s.size.x, g_Timer1s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer1s.rot);
	}
	if (s == 59)	{
		DrawSpriteColorRotate(g_TimerTexture5,
			g_Timer10s.pos.x, g_Timer10s.pos.y,
			g_Timer10s.size.x, g_Timer10s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer10s.rot);

		DrawSpriteColorRotate(g_TimerTexture9,
			g_Timer1s.pos.x, g_Timer1s.pos.y,
			g_Timer1s.size.x, g_Timer1s.size.y,
			0.0f, 0.0f,
			1.0f, 1.0f,
			col, g_Timer1s.rot);
	}


}