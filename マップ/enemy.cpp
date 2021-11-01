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

//*****************************************************************************
// �}�N����`
//*****************************************************************************


//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************


//*****************************************************************************
// �O���[�o���ϐ�
//*****************************************************************************
static int	g_EnemyTexture = 0;
static ENEMY g_Enemy;							// �G�l�~�[�\����


//=============================================================================
// ����������
//=============================================================================
HRESULT InitEnemy(void)
{
	g_EnemyTexture = LoadTexture("data/TEXTURE/tako.png");

	// �G�l�~�[�\���̂̏�����
	
	
		g_Enemy.use   = true;
		g_Enemy.w     = 50.0f;
		g_Enemy.h     = 50.0f;
		g_Enemy.pos   = D3DXVECTOR2(SCREEN_WIDTH / 2 - 150.0f , SCREEN_HEIGHT / 2 - 100.0f);
		g_Enemy.rot   = 0.0f;

		g_Enemy.state = 0;
		g_Enemy.frame = 0;
	
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
	for (int i = 0; i < 1; i++)
	{
		if (g_Enemy.use == true)		// ���̃G�l�~�[���g���Ă���H
		{								// Yes	
			switch (g_Enemy.state)
			{
			case 0:
				g_Enemy.pos.x -= 1.0f;
				if (g_Enemy.frame > 50)
				{
					g_Enemy.state = 1;
					g_Enemy.frame = 0;
				}
				break;
			case 1:
				g_Enemy.pos.x += 3.0f;
				g_Enemy.pos.y += 3.0f;

				if (g_Enemy.frame > 20)
				{
					g_Enemy.state = 2;
					g_Enemy.frame = 0;
				}
				break;
			case 2:
				g_Enemy.pos.x -= 3.0f;
				if (g_Enemy.frame > 40)
				{
					g_Enemy.state = 3;
					g_Enemy.frame = 0;
				}
				break;
			case 3:
				g_Enemy.pos.x += 3.0f;
				g_Enemy.pos.y += 3.0f;
				if (g_Enemy.frame > 40)
				{
					g_Enemy.state = 4;
					g_Enemy.frame = 0;
				}
				break;
			case 4:
				g_Enemy.pos.x += 3.0f;
				if (g_Enemy.frame > 200)
				{
					g_Enemy.use = 0;
				}
				break;
			}

			// ��]������
			if ((i % 2) == 0)
			{
				g_Enemy.rot += 0.05f;
			}
			else
			{
				g_Enemy.rot -= 0.05f;
			}

			//�t���[���̒ǉ�
			g_Enemy.frame++;
		}
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
			D3DXCOLOR col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

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
			return;							// �G���Z�b�g�ł����̂ŏI������
		}
	
}

