////=============================================================================
////
//// エネミー発生管理 [enemy_emitter.cpp]
//// Author : 
////
////=============================================================================
//#include "enemy_emitter.h"
//#include "enemy.h"
//
////*****************************************************************************
//// マクロ定義
////*****************************************************************************
//struct ENEMY_EMIT_DATA
//{
//	float			frame;	//発生フレーム
//	D3DXVECTOR2		pos;	//発生する座標
//};
//
////*****************************************************************************
//// プロトタイプ宣言
////*****************************************************************************
//
//
////*****************************************************************************
//// グローバル変数
////*****************************************************************************
//static int g_StageFrame = 0;		//現在のステージが始まってからの時間
//static int g_EnemyEmitCount = 0;	//発生カウンター
//static int g_EmitTableSize = 0;		//テーブルのサイズ
//
//
//ENEMY_EMIT_DATA g_EnemyEmitData[] =
//{
//	{120.0f, {SCREEN_WIDTH + 50.0f, SCREEN_HEIGHT / 2}},
//	{140.0f, {SCREEN_WIDTH + 50.0f, SCREEN_HEIGHT / 2}},
//	{160.0f, {SCREEN_WIDTH + 50.0f, SCREEN_HEIGHT / 2}},
//	{180.0f, {SCREEN_WIDTH + 50.0f, SCREEN_HEIGHT / 2}},
//	{200.0f, {SCREEN_WIDTH + 50.0f, SCREEN_HEIGHT / 2}},
//
//	{320.0f, {SCREEN_WIDTH + 50.0f, SCREEN_HEIGHT / 2}},
//	{340.0f, {SCREEN_WIDTH + 50.0f, SCREEN_HEIGHT / 2}},
//	{360.0f, {SCREEN_WIDTH + 50.0f, SCREEN_HEIGHT / 2}},
//	{380.0f, {SCREEN_WIDTH + 50.0f, SCREEN_HEIGHT / 2}},
//	{400.0f, {SCREEN_WIDTH + 50.0f, SCREEN_HEIGHT / 2}},
//
//	{520.0f, {SCREEN_WIDTH + 50.0f, SCREEN_HEIGHT / 2}},
//	{540.0f, {SCREEN_WIDTH + 50.0f, SCREEN_HEIGHT / 2}},
//	{560.0f, {SCREEN_WIDTH + 50.0f, SCREEN_HEIGHT / 2}},
//	{580.0f, {SCREEN_WIDTH + 50.0f, SCREEN_HEIGHT / 2}},
//	{600.0f, {SCREEN_WIDTH + 50.0f, SCREEN_HEIGHT / 2}},
//
//};
//
////=============================================================================
//// 初期化処理
////=============================================================================
//HRESULT InitEnemyEmitter(void)
//{
//	//初期化
//	g_StageFrame = 0;
//	g_EnemyEmitCount = 0;
//	g_EmitTableSize = sizeof(g_EnemyEmitData) / sizeof(ENEMY_EMIT_DATA);
//
//	return S_OK;
//}
//
////=============================================================================
//// 終了処理
////=============================================================================
//void UninitEnemyEmitter(void)
//{
//
//}
//
////=============================================================================
//// 更新処理
////=============================================================================
//void UpdateEnemyEmitter(void)
//{
//	//発生テーブルの上限チェック
//	if (g_EnemyEmitCount >= g_EmitTableSize)
//	{
//		return;
//	}
//
//	//敵の発生タイミングの制御
//	if (g_StageFrame >= g_EnemyEmitData[g_EnemyEmitCount].frame)
//	{
//		SetEnemy(g_EnemyEmitData[g_EnemyEmitCount].pos);
//		g_EnemyEmitCount++;
//	}
//
//	g_StageFrame++;
//}
//
////=============================================================================
//// 描画処理
////=============================================================================
//void DrawEnemyEmitter(void)
//{
//
//}
