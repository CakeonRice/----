//=============================================================================
//
// �G�l�~�[���� [enemy.cpp]
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
// �}�N����`
//*****************************************************************************
#define ROT_SPD				(0.05f)
#define ENEMY_SPD			(2.0f)
#define ENEMY_SIZE			(50.0f)
#define MOVE_TIMER			(50)
#define SERCH_RANGE			(200.0f)
#define FIND_SPD			(1.5f)
//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************


//*****************************************************************************
// �O���[�o���ϐ�
//*****************************************************************************
static int	g_EnemyTexture = 0;
static ENEMY g_Enemy;							  // �G�l�~�[�\����
static float MAPleft, MAPright, MAPtop, MAPunder; // �G�l�~�[�̍s���͈�
static int g_Enemy_Timer;
int moveX;
int moveY;

//=============================================================================
// ����������
//=============================================================================
HRESULT InitEnemy(void)
{
	g_EnemyTexture = LoadTexture("data/TEXTURE/tako.png");

	MAPleft = SCREEN_WIDTH / 2 + HALF_CHIP + CHIP_SIZE * ((-MAP_SIZE_X / 2));
	MAPright = SCREEN_WIDTH / 2 - HALF_CHIP + CHIP_SIZE * ((MAP_SIZE_X / 2));

	MAPtop = SCREEN_HEIGHT / 2 + HALF_CHIP + CHIP_SIZE * ((-MAP_SIZE_Y / 2));
	MAPunder = SCREEN_HEIGHT / 2 - HALF_CHIP + CHIP_SIZE * ((MAP_SIZE_Y / 2));

	// �G�l�~�[�\���̂̏�����
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
// �I������
//=============================================================================
void UninitEnemy(void)
{

}

//=============================================================================
// �X�V����
//=============================================================================
void UpdateEnemy(void)
{

	if (g_Enemy.use == true)
	{
		// �ǐՔ���
		if (SerchPlayer(GetPlayerPosition(), g_Enemy.pos))
		{// ������(�͈͓��ɓ�����)

			//���݈ʒu
			D3DXVECTOR2 position = g_Enemy.pos;

			//�ڕW�n�_
			D3DXVECTOR2 destination = GetPlayerPosition();

			//����
			D3DXVECTOR2 components;

			//�傫��
			float magnitude;

			//�����i�P�ʃx�N�g���j
			D3DXVECTOR2 direction;

			//�����v�Z
			components.x = destination.x - position.x;
			components.y = destination.y - position.y;

			//�傫���v�Z
			magnitude = (float)sqrt(components.x * components.x + components.y * components.y);

			//�����v�Z�i���K���j
			direction.x = components.x / magnitude;
			direction.y = components.y / magnitude;

			//�ړ���̈ʒu���v�Z
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
		else // �����Ă��Ȃ�
		{
			g_Enemy_Timer++;

			if (g_Enemy_Timer > MOVE_TIMER)
			{
				moveX = rand() % 3;
				moveY = rand() % 3;
				g_Enemy_Timer = 0;
				srand((unsigned)time(NULL));
			}

			// �G�l�~�[���ړ�
			if (moveX == 1) // +(�E)
			{
				g_Enemy.pos.x += g_Enemy.vel.x;
				if (GetMapEnter(D3DXVECTOR2(g_Enemy.pos.x + g_Enemy.vel.x, g_Enemy.pos.y),
					D3DXVECTOR2(g_Enemy.w, g_Enemy.h))
					== 1)
				{
					g_Enemy.pos.x -= g_Enemy.vel.x;
				}
			}
			if (moveX == 2) // -(��)
			{
				g_Enemy.pos.x -= g_Enemy.vel.x;
				if (GetMapEnter(D3DXVECTOR2(g_Enemy.pos.x - g_Enemy.vel.x, g_Enemy.pos.y),
					D3DXVECTOR2(g_Enemy.w, g_Enemy.h))
					== 1)
				{
					g_Enemy.pos.x += g_Enemy.vel.x;
				}
			}

			// �G�l�~�[�c�ړ�
			if (moveY == 1) // +(��)
			{
				g_Enemy.pos.y += g_Enemy.vel.y;
				if (GetMapEnter(D3DXVECTOR2(g_Enemy.pos.x, g_Enemy.pos.y + g_Enemy.vel.y),
					D3DXVECTOR2(g_Enemy.w, g_Enemy.h))
					== 1)
				{
					g_Enemy.pos.y -= g_Enemy.vel.y;
				}
			}
			if (moveY == 2) // -(��)
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
		
		
		// ���ˏ���
		
		// ���[
		if (g_Enemy.pos.x <= MAPleft)
		{
			g_Enemy.pos.x = MAPleft;
		}
		// �E�[
		if (g_Enemy.pos.x >= MAPright)
		{
			g_Enemy.pos.x = MAPright;
		}
		// ��[
		if (g_Enemy.pos.y <= MAPtop)
		{
			g_Enemy.pos.y = MAPtop;
		}
		// ���[
		if (g_Enemy.pos.y >= MAPunder)
		{
			g_Enemy.pos.y = MAPunder;
		}
		
		// ��]������
		if ((1 % 2) == 0)
		{
			g_Enemy.rot += ROT_SPD;
		}
		else
		{
			g_Enemy.rot -= ROT_SPD;
		}
		//�t���[���̒ǉ�
		g_Enemy.frame++;
	}
	
}

//=============================================================================
// �`�揈��
//=============================================================================
void DrawEnemy(void)
{
	if (g_Enemy.use == true)
	{
		//�G�l�~�[�̈ʒu��e�N�X�`���[���W�𔽉f
		float px = g_Enemy.pos.x;	// �G�l�~�[�̕\���ʒuX
		float py = g_Enemy.pos.y;	// �G�l�~�[�̕\���ʒuY
		float pw = g_Enemy.w;		// �G�l�~�[�̕\����
		float ph = g_Enemy.h;		// �G�l�~�[�̕\������
		D3DXCOLOR col;

		if (SerchPlayer(GetPlayerPosition(), g_Enemy.pos))
		{
			col = D3DXCOLOR(0.2f, 1.0f, 1.0f, 1.0f);
		}
		else
		{
			col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		}

		// �P���̃|���S���̒��_�ƃe�N�X�`�����W��ݒ�
		DrawSpriteColorRotate(g_EnemyTexture,px, py, pw, ph, 0.0f, 0.0f, 1.0f, 1.0f, col, g_Enemy.rot);
	}
	
}

//=============================================================================
// �G�l�~�[�\���̂̐擪�A�h���X���擾
//=============================================================================
ENEMY *GetEnemy(void)
{
	return &g_Enemy;
}


//=============================================================================
// �G�̔�������
//=============================================================================
void SetEnemy(D3DXVECTOR2 pos)
{
	// �������g�p�̃f�[�^��T��
	if (g_Enemy.use == false)		// ���g�p��Ԃ̓G�f�[�^��������
	{
		g_Enemy.use = true;			// �g�p��Ԃ֕ύX����
		g_Enemy.pos = pos;			// ���W���Z�b�g
		g_Enemy.rot = 0.0f;			// ��]�p�̃��Z�b�g
		g_Enemy.state = 0;			// ��Ԃ����Z�b�g
		g_Enemy.frame = 0;			// �t���[���̃��Z�b�g
		return;						// �G���Z�b�g�ł����̂ŏI������
	}
	
}

bool SerchPlayer(D3DXVECTOR2 Playerpos, D3DXVECTOR2 Enemypos)
{
	D3DXVECTOR2 maxRange, minRange;

	minRange.x = Enemypos.x - SERCH_RANGE;
	minRange.y = Enemypos.y - SERCH_RANGE;
	maxRange.x = Enemypos.x + SERCH_RANGE;
	maxRange.y = Enemypos.y + SERCH_RANGE;

	//X���̔���
	if (minRange.x < Playerpos.x &&
		maxRange.x > Playerpos.x)
	{
		//Y���̔���
		if (minRange.y < Playerpos.y &&
			maxRange.y > Playerpos.y)
		{
			//�S�Ă̏�����TRUE�Ȃ�q�b�g����
			return true;
		}
	}

	return false;
}