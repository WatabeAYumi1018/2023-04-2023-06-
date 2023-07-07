#include "../dxlib_ext/dxlib_ext.h"
#include "gm_main.h"
#include "mapScene_map.h"
#include "storyScene.h"
#include "tutorialScene.h"
#include "mapScene_battle.h"

//�`���[�g���A����p�摜----------------
// 
//�}�b�v�S�̐}
int g_tutorialMap = 0;
//�Q�[���ړI
int g_tutorialMapStream = 0;
//�����^�[���J�[�\��
int g_tutorialAllyTurnCursor = 0;
//����ʏ��
int g_tutorialAllyTurnInfoSpeed = 0;
//�����^�[���ړ���I��
int g_tutorialAllyTurnSelect = 0;
//�����^�[���ړ�
int g_tutorialAllyTurnMove = 0;
//�����^�[���U���\��
int g_tutorialPredictionBattle = 0;
//�G�^�[���؂�ւ�
int g_tutorialEnemyTurn = 0;
//�G�^�[������
int g_tutorialMapEnemyTurnMove = 0;
//�񕜃X�|�b�g�̐���
int g_tutorialMapHeal = 0;

//�������G
int g_bossNormal=0;
int g_bossSmile = 0;

//�`���[�g���A���摜�`��
void tutorialDraw() {

	//�w�i�摜�`��
	DrawExtendGraph(0, 0, DXE_WINDOW_WIDTH, DXE_WINDOW_WIDTH, g_battleGround, TRUE);

	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RETURN)) { g_messageRun++; }

	if (g_messageRun == 2 || g_messageRun == 13 || g_messageRun == 14 || g_messageRun == 15) {
		DrawExtendGraph(0, 0, 800, 500, g_tutorialMap, false);
	}

	else if (g_messageRun == 3 || g_messageRun == 4) {DrawExtendGraph(0, 0, 800, 500, g_tutorialMapStream, false);}
	
	else if (g_messageRun == 5) {DrawExtendGraph(0, 0, 800, 500, g_tutorialAllyTurnCursor, false);}
	
	else if (g_messageRun == 6) {DrawExtendGraph(0, 0, 800, 500, g_tutorialAllyTurnSelect, false);}
	
	else if (g_messageRun == 7) {DrawExtendGraph(0, 0, 800, 500, g_tutorialAllyTurnMove, false);}
	
	else if (g_messageRun == 8) { DrawExtendGraph(0, 0, 800, 500, g_tutorialPredictionBattle, false);}
		
	else if(g_messageRun == 9 || g_messageRun == 10) {DrawExtendGraph(0, 0, 800, 500, g_tutorialAllyTurnInfoSpeed, false);}
	
	else if (g_messageRun == 11) {DrawExtendGraph(0, 0, 800, 500, g_tutorialEnemyTurn, false);}

	else if (g_messageRun == 12) {DrawExtendGraph(0, 0, 800, 500, g_tutorialMapEnemyTurnMove, false);}

	else if (g_messageRun == 16) {DrawExtendGraph(0, 0, 800, 500, g_tutorialMapHeal, false);}

	//�������G	
	if (g_messageRun == 0 || g_messageRun == 4 || g_messageRun == 7 || g_messageRun == 11 || g_messageRun == 15) {
		DrawExtendGraph(1200, 100, 800, 500, g_bossSmile, TRUE);
	}
	else {DrawExtendGraph(1200, 100, 800, 500, g_bossNormal, TRUE);}
	
	//�X�g�[���[��b�E�B���h�E
	DrawExtendGraph(60, 500, 1200, 700, g_storyWindow, TRUE);
}

//�`���[�g���A����b���b�Z�[�W
void tutorialMessage() {

	SetFontSize(40);

	if (g_messageRun == 0) {

		DrawStringEx(150, 550, -TEXT_COLOR_WHITE, "���̃}���O���b�g��\n");
		DrawStringEx(150, 620, -TEXT_COLOR_WHITE, "�R�t�a�Ƃ̎荇�킹�@���h�Ɏv��\n");
	}
	else if (g_messageRun == 1) {

		DrawStringEx(150, 550, -TEXT_COLOR_WHITE, "�������X�������@���Ԃ��ɂ���\n");
		DrawStringEx(150, 620, -TEXT_COLOR_WHITE, "�P���ɂ��ā@���������Ă��炤\n");
	}
	else if (g_messageRun == 2) {

		DrawStringEx(150, 550, -TEXT_COLOR_WHITE, "�܂��́@�S�̂̊T�v����\n");
		DrawStringEx(150, 620, -TEXT_COLOR_WHITE, "�܂��@���Ă̒ʂ肾\n");
	}
	else if (g_messageRun == 3) {

		DrawStringEx(150, 550, -TEXT_COLOR_WHITE, "�R�t�a�ɒb���ė~�����̂́@���̎O�l\n");
		DrawStringEx(150, 620, -TEXT_COLOR_WHITE, "�䂪�ꑰ�́@�퓬������\n");
	}
	else if (g_messageRun == 4) {

		DrawStringEx(150, 550, -TEXT_COLOR_WHITE, "�O�l�𓱂��@����|��\n");
		DrawStringEx(150, 620, -TEXT_COLOR_WHITE, "�R�t�a�̍єz������΁@����������낤\n");
	}
	else if (g_messageRun == 5) {

		DrawStringEx(150, 550, -TEXT_COLOR_WHITE, "���������낤���@�����������悤\n");
		DrawStringEx(150, 620, -TEXT_COLOR_WHITE, "�܂��͒N�ōU�߂邩�@�s�x�I�肹��\n");
	}
	else if (g_messageRun == 6) {

		DrawStringEx(150, 550, -TEXT_COLOR_WHITE, "�e�X�̉^���ʂɂ��Ắ@�f�[�^����\n");
		DrawStringEx(150, 620, -TEXT_COLOR_WHITE, "����o���Ă���@�Q�l�ɂ��Ă���\n");
	}

	else if (g_messageRun == 7) {

		DrawStringEx(150, 550, -TEXT_COLOR_WHITE, "�G�ɑf�����߂Â��@�ꌂ��^����\n");
		DrawStringEx(150, 620, -TEXT_COLOR_WHITE, "�킢�̊�{����\n");
	}
	else if (g_messageRun == 8) {

		DrawStringEx(150, 550, -TEXT_COLOR_WHITE, "��n�ł͑I���ЂƂ��@�����ɂȂ�\n");
		DrawStringEx(150, 620, -TEXT_COLOR_WHITE, "���O�ɐ틵��c������̂��@�d�v�ȗv�f��\n");
	}
	else if (g_messageRun == 9) {

		DrawStringEx(150, 550, -TEXT_COLOR_WHITE, "���ā@�䂪�ꑰ�͓���\n");
		DrawStringEx(150, 620, -TEXT_COLOR_WHITE, "�f�����Ɂ@�d���������Ă���\n");
	}
	else if (g_messageRun == 10) {
		DrawStringEx(150, 550, -TEXT_COLOR_WHITE, "�r�q�ł���΁@����˂��₷�������\n");
		DrawStringEx(150, 620, -TEXT_COLOR_WHITE, "�T�ȏ������΁@�ǌ����\���낤\n");
	}
	else if (g_messageRun ==11) {

		DrawStringEx(150, 550, -TEXT_COLOR_WHITE, "�S���̍s��������������\n");
		DrawStringEx(150, 620, -TEXT_COLOR_WHITE, "���́@������̔Ԃ�\n");
	}
	else if (g_messageRun == 12) {

		DrawStringEx(150, 550, -TEXT_COLOR_WHITE, "���̋������Ɂ@�����Ă�����\n");
		DrawStringEx(150, 620, -TEXT_COLOR_WHITE, "�߂��܂Ł@�ړ������Ă��炤\n");
	}
	else if (g_messageRun == 13) {

		DrawStringEx(150, 550, -TEXT_COLOR_WHITE, "�Ō�́@�X�R�A�ɂ��Ă�\n");
		DrawStringEx(150, 620, -TEXT_COLOR_WHITE, "���R�����قǁ@��V�͒e�܂��Ă��炨��\n");
	}
	else if (g_messageRun == 14) {

		DrawStringEx(150, 550, -TEXT_COLOR_WHITE, "�������ȁ@�Ⴆ�Εs���ȕ���œ|����\n");
		DrawStringEx(150, 620, -TEXT_COLOR_WHITE, "��荂���_���@�����邾�낤\n");
	}
	else if (g_messageRun == 15) {

		DrawStringEx(150, 550, -TEXT_COLOR_WHITE, "�����ɍU�߂邩�@���]����ڎw������\n");
		DrawStringEx(150, 620, -TEXT_COLOR_WHITE, "�R�t�a�̎��R���@�S�͂Ō}�����Ƃ�\n");
	}
	else if (g_messageRun == 16) {

		DrawStringEx(150, 550, -TEXT_COLOR_WHITE, "�Ō�Ɂ@�P����ɂ͋~��ǂ��_�݂��Ă���\n");
		DrawStringEx(150, 620, -TEXT_COLOR_WHITE, "��肭���p���@�{���𐋂��Ă݂���\n");
	}
	else if (g_messageRun == 17) {

		g_messageRun = 0;
		g_gameScene_id = GAME_MAP;
	}
}
