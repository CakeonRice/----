/*==============================================================================

   ���_�Ǘ� [player.cpp]
														 Author :
														 Date   :
--------------------------------------------------------------------------------

==============================================================================*/
#include "player.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"
#include "bg.h"
#include "enemy.h"

//*****************************************************************************
// �}�N����`
//*****************************************************************************
#define PLAYER_SPD			(3.0f)
#define PLAYER_SIZE			(50.0f)

#define GRAVITY_VEL			(0.5f)

//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************


//*****************************************************************************
// �O���[�o���ϐ�
//*****************************************************************************
static int	g_PlayerTexture = 0;
PLAYER		g_Player;
float		control_timer;
float		gravity_timer;

float		g_DrawGrav = 0;

//=============================================================================
// ����������
//=============================================================================
HRESULT InitPlayer(void)
{
	g_PlayerTexture = LoadTexture("data/TEXTURE/player.png");

	g_Player.pos.x = SCREEN_WIDTH / 2;
	g_Player.pos.y = SCREEN_HEIGHT / 2;
	g_Player.size.x = PLAYER_SIZE;
	g_Player.size.y = PLAYER_SIZE;
	g_Player.vel.x = PLAYER_SPD;
	g_Player.vel.y = PLAYER_SPD;
	g_Player.rot = 0.0f;
	g_Player.rot_vel = 0.1f;
	control_timer = 0.0f;
	gravity_timer = 0.0f;

	return S_OK;
}

//=============================================================================
// �I������
//=============================================================================
void UninitPlayer(void)
{

}

//=============================================================================
// �X�V����
//=============================================================================
void UpdatePlayer(void)
{
	/*if (GetKeyboardTrigger(DIK_RETURN) && GetFadeState() == FADE_NONE)
	{
		SceneTransition(SCENE_GAME);
	}*/
	ZeroGravity();
	ControlPlayer();
	FramePlayer();

}

//=============================================================================
// �`�揈��
//=============================================================================
void DrawPlayer(void)
{
	D3DXCOLOR col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

	DrawSpriteColorRotate(g_PlayerTexture,
		g_Player.pos.x, g_Player.pos.y + g_DrawGrav,
		g_Player.size.x, g_Player.size.y,
		0.57f, 0.04f,
		0.34f, 0.38f,
		col, g_Player.rot);
}

void ControlPlayer(void)
{


	if (GetKeyboardPress(DIK_J))
	{
		SetEnemy(D3DXVECTOR2(SCREEN_WIDTH-75.0f , SCREEN_HEIGHT-75.0f ));
	}


	//��(�ړ�)
	if (GetKeyboardPress(DIK_A))
	{
		g_Player.pos.x -= g_Player.vel.x;

		if (GetMapEnter(D3DXVECTOR2(g_Player.pos.x - 1.0f, g_Player.pos.y),
			D3DXVECTOR2(g_Player.size.x, g_Player.size.y))
			== 1)
			g_Player.pos.x += g_Player.vel.x;

		control_timer++;
		if (control_timer >= 20.0f)
		{
			g_Player.rot -= g_Player.rot_vel;
			control_timer = 0.0f;
		}



	}

	//�E(�ړ�)
	if (GetKeyboardPress(DIK_D))
	{
		g_Player.pos.x += g_Player.vel.x;

		if (GetMapEnter(D3DXVECTOR2(g_Player.pos.x - 1.0f, g_Player.pos.y),
			D3DXVECTOR2(g_Player.size.x, g_Player.size.y))
			== 1)
			g_Player.pos.x -= g_Player.vel.x;

		control_timer++;
		if (control_timer >= 20.0f)
		{
			g_Player.rot += g_Player.rot_vel;
			control_timer = 0.0f;
		}
	}

	//��(�ړ�)
	if (GetKeyboardPress(DIK_W))
	{
		g_Player.pos.y -= g_Player.vel.y;

		if (GetMapEnter(D3DXVECTOR2(g_Player.pos.x, g_Player.pos.y - 1.0f),
			D3DXVECTOR2(g_Player.size.x, g_Player.size.y))
			== 1)
		{
			g_Player.pos.y += g_Player.vel.y;
		}
			
	}

	//��(�ړ�)
	if (GetKeyboardPress(DIK_S))
	{
		g_Player.pos.y += g_Player.vel.y;

		if (GetMapEnter(D3DXVECTOR2(g_Player.pos.x, g_Player.pos.y + 1.0f),
			D3DXVECTOR2(g_Player.size.x, g_Player.size.y))
			== 1)
		{
			g_Player.pos.y -= g_Player.vel.y;
		}
	}

	//����]
	if (GetKeyboardPress(DIK_Q))
	{
		g_Player.rot -= 0.01f;
	}

	//�E��]
	if (GetKeyboardPress(DIK_E))
	{
		g_Player.rot += 0.01f;
	}
}

void ZeroGravity(void)
{
	if (gravity_timer < 20.0f)
	{
		g_DrawGrav -= GRAVITY_VEL;
		gravity_timer++;
	}
	if (gravity_timer >= 20.0f && gravity_timer < 40.0f)
	{
		g_DrawGrav += GRAVITY_VEL;
		gravity_timer++;
	}
	if (gravity_timer >= 40.0f && gravity_timer < 60.0f)
	{
		g_DrawGrav += GRAVITY_VEL;
		gravity_timer++;
	}
	if (gravity_timer >= 60.0f && gravity_timer < 80.0f)
	{
		g_DrawGrav -= GRAVITY_VEL;
		gravity_timer++;
	}

	if (gravity_timer >= 80.0f)
	{
		gravity_timer = 0.0f;
	}
}

void FramePlayer(void)
{
	//��(�g)
	if (g_Player.pos.x <= 0.0f + (g_Player.size.x / 2))
	{
		g_Player.pos.x = 0.0f + (g_Player.size.x / 2);
	}
	//�E(�g)
	if (g_Player.pos.x >= SCREEN_WIDTH - (g_Player.size.x / 2))
	{
		g_Player.pos.x = SCREEN_WIDTH - (g_Player.size.x / 2);
	}

	//��(�g)
	if (g_Player.pos.y <= 0.0f + (g_Player.size.y / 2))
	{
		g_Player.pos.y = 0.0f + (g_Player.size.y / 2);
	}

	//��(�g)
	if (g_Player.pos.y >= SCREEN_HEIGHT - (g_Player.size.y / 2))
	{
		g_Player.pos.y = SCREEN_HEIGHT - (g_Player.size.y / 2);
	}
}