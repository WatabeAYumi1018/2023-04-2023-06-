#include "DxLib.h"
#include <math.h>
#include <time.h>
#include <string>
#include "../dxlib_ext/dxlib_ext.h"
#include "gm_main.h"
#include "titleScene.h"
#include "storyScene.h"
#include "tutorialScene.h"
#include "mapScene_map.h"
#include "mapScene_character.h"
#include "mapScene_battle.h"
#include "endScene.h"

//-------------------------------------------------------------------------------------------
//

//ゲーム全体のシーン移行
int g_gameScene_id = GAME_START;

//サウンド関連ハンドル----------------------------------

//サウンド　タイトル
int g_bgmTitle = 0;
//サウンド　マップ
int g_bgmMap = 0;
//サウンド　エンディング
int g_bgmEnding = 0;
//サウンド　ゲームオーバー
int g_bgmGameOver = 0;

//攻撃SE　弓
int g_seEffectAllow = 0;
//攻撃SE　剣
int g_seEffectSword = 0;
//攻撃SE　魔法
int g_seEffectMagic = 0;
//攻撃SE　長
int g_seEffectBoss = 0;
//ターン移行　&&　バトル開始
int g_seMoveBattle = 0;

//操作ボタン画像ハンドル----------------------------------

//エンターボタン
int g_bottonEnter = 0;
//カーソルボタン
int g_bottonCursor = 0;
//タブボタン
int g_bottonTab = 0;
//スペースボタン
int g_bottonSpace = 0;
//シフトボタン
int g_bottonShift = 0;

//-------------------------------------------------------------------------------------------
//起動時に一回のみ実行されます
void gameStart() {
	srand(time(0));

	SetWindowText("GREEN OCEAN");

	//音楽の出力--------------------------------------------
	// 
	//BGMの出力
	g_bgmTitle = LoadSoundMem("sound/title.mp3");
	g_bgmMap = LoadSoundMem("sound/map.mp3");
	g_bgmEnding = LoadSoundMem("sound/ending.mp3");
	g_bgmGameOver = LoadSoundMem("sound/gameOver.mp3");

	//タイトル〜チュートリアルにて再生
	PlaySoundMem(g_bgmTitle, DX_PLAYTYPE_LOOP, TRUE);

	//SE出力	
	g_seEffectAllow = LoadSoundMem("sound/effectAllow.mp3");
	g_seEffectSword = LoadSoundMem("sound/effectSword.mp3");
	g_seEffectMagic = LoadSoundMem("sound/effectMagic.wav");
	g_seEffectBoss = LoadSoundMem("sound/effectBoss.mp3");
	g_seMoveBattle = LoadSoundMem("sound/battleStart.mp3");

	//文字の出力--------------------------------------------

	//文字フォント
	tnl::AddFontTTF("font/PixelMplus12-Regular.ttf");

	//画像の出力--------------------------------------------

	//ゲームスタート画面
	g_gameStart = LoadGraph("graphics/GameStartBack.jpg");

	//ゲームスタート画面アニメーション
	g_titleRight = LoadGraph("graphics/titleAnim.png");

	//動画のロード
	g_titleMovie = LoadGraph("graphics/titleLeaf.mp4");
	g_clearFlower = LoadGraph("graphics/clearEndFlower.mp4");

	//タイトル選択画像
	g_select_cursor = LoadGraph("graphics/flowerSelect.png");

	//タイトル文字画像
	g_title = LoadGraph("graphics/GREEN OCEAN.png");

	//ストーリーシーン背景
	g_storyBack = LoadGraph("graphics/GameStoryBack.png");

	//会話ウィンドウ
	g_storyWindow = LoadGraph("graphics/storyWindow.png");

	//マップデータ
	LoadDivGraph("graphics/pipo-map001.png", 88, 8, 11, CHIP_SIZE, CHIP_SIZE, map_chips[0]);

	//キャラ
	LoadDivGraph("graphics/player1.png", 12, 3, 4, CHIP_SIZE, CHIP_SIZE, character_chips[0]);
	LoadDivGraph("graphics/player2.png", 12, 3, 4, CHIP_SIZE, CHIP_SIZE, character_chips[1]);
	LoadDivGraph("graphics/player3.png", 12, 3, 4, CHIP_SIZE, CHIP_SIZE, character_chips[2]);
	LoadDivGraph("graphics/enemy1.png", 12, 3, 4, CHIP_SIZE, CHIP_SIZE, character_chips[3]);
	LoadDivGraph("graphics/enemy2.png", 12, 3, 4, CHIP_SIZE, CHIP_SIZE, character_chips[4]);
	LoadDivGraph("graphics/enemy3.png", 12, 3, 4, CHIP_SIZE, CHIP_SIZE, character_chips[5]);
	LoadDivGraph("graphics/enemyBOSS.png", 12, 3, 4, CHIP_SIZE, CHIP_SIZE, character_chips[6]);

	//カーソル
	g_cursor = LoadGraph("graphics/cursor.png");

	//マップ上での情報表示用（下画面）
	display_map = LoadGraph("graphics/mapInfo.png");

	//マップ上での行動可能範囲
	fill_map = LoadGraph("graphics/canMoveTile.png");

	//攻撃画面の背景
	g_battleGround = LoadGraph("graphics/battleback.jpg");

	//ゲームオーバー背景
	g_gameOver = LoadGraph("graphics/GameOver.jpg");

	//ゲームクリア背景
	g_gameClear = LoadGraph("graphics/GameClear.png");

	//攻撃中の下画面
	LoadDivGraph("graphics/battleHp.png", 35, 5, 7, 120, 60, g_battle_hp[0]);
	LoadDivGraph("graphics/battleAttack.png", 42, 3, 14, 300, 60, g_battle_attack[0]);
	LoadDivGraph("graphics/battleHit.png", 25, 5, 5, 180, 60, g_battle_hit[0]);

	//攻撃エフェクトアニメーション
	LoadDivGraph("graphics/effect_sword.png", 15, 5, 3, EFFECT_SIZE, EFFECT_SIZE, g_battle_effect_sword[0]);
	LoadDivGraph("graphics/effect_snip.png", 10, 5, 2, EFFECT_SIZE, EFFECT_SIZE, g_battle_effect_snip[0]);
	LoadDivGraph("graphics/effect_magic.png", 14, 14, 1, EFFECT_SIZE, EFFECT_SIZE, g_battle_effect_magic[0]);
	LoadDivGraph("graphics/effect_leader.png", 10, 5, 2, EFFECT_SIZE, EFFECT_SIZE, g_battle_effect_leader[0]);

	//職業アイコン
	icon_sword = LoadGraph("graphics/iconSWORD.png");
	icon_magic = LoadGraph("graphics/iconMAGIC.png");
	icon_snip = LoadGraph("graphics/iconSNIP.png");
	icon_boss = LoadGraph("graphics/iconBOSS.png");

	//三すくみエフェクト
	g_relation_back = LoadGraph("graphics/relationBack.png");
	g_relation = LoadGraph("graphics/relation.png");

	//マップ画面でのターン文字
	LoadDivGraph("graphics/mapTurn.png", 15, 1, 15, 600, 60, g_map_turn[0]);

	//操作ボタン関係-----------------------------

	//エンターボタン
	g_bottonEnter = LoadGraph("graphics/leafEnter.png");
	//カーソルボタン
	g_bottonCursor = LoadGraph("graphics/leafCursor.png");
	//タブボタン
	g_bottonTab = LoadGraph("graphics/leafTab.png");
	//スペースボタン
	g_bottonSpace = LoadGraph("graphics/leafSpace.png");

	//立ち絵関係-----------------------------

	//女性立ち絵
	g_girlNormal = LoadGraph("graphics/girlNormal.png");
	g_girlSmile = LoadGraph("graphics/girlSmile.png");
	g_girlTroubled = LoadGraph("graphics/girlTroubled.png");

	//長立ち絵
	g_bossNormal = LoadGraph("graphics/bossTutorialNormal.png");
	g_bossSmile = LoadGraph("graphics/bossTutorialSmile.png");

	//チュートリアル関係-----------------------------
	
	//マップ全体図
	g_tutorialMap = LoadGraph("graphics/tutorialMap.png");
	//ゲーム目的
	g_tutorialMapStream = LoadGraph("graphics/tutorialMapStream.png");
	//味方ターンカーソル
	g_tutorialAllyTurnCursor = LoadGraph("graphics/tutorialAllyTurnCursor.png");
	//下画面情報
	g_tutorialAllyTurnInfoSpeed = LoadGraph("graphics/tutorialAllyTurnInfoSpeed.png");
	//味方ターン移動先選択
	g_tutorialAllyTurnSelect = LoadGraph("graphics/tutorialAllyTurnSelect.png");
	//味方ターン移動
	g_tutorialAllyTurnMove = LoadGraph("graphics/tutorialAllyTurnMove.png");
	//味方ターン攻撃予測
	g_tutorialPredictionBattle = LoadGraph("graphics/tutorialPredictionBattle.png");
	//敵ターン
	g_tutorialEnemyTurn = LoadGraph("graphics/tutorialEnemyTurn.png");
	//敵ターン終了
	g_tutorialMapEnemyTurnMove = LoadGraph("graphics/tutorialEnemyTurnMove.png");
	//回復スポット説明
	g_tutorialMapHeal = LoadGraph("graphics/tutorialMapHeal.png");
}

//------------------------------------------------------------------------------------------------------------
// 毎フレーム実行されます,60FPS
void gameMain(float delta_time) {

	switch (g_gameScene_id) {

		case GAME_START: {

			soundTitle();					//タイトル画面でのサウンド制御
			titleBackDraw();				//タイトル背景画像
			movieDraw();					//タイトルアニメーション動画
			sceneTitle();					//タイトル全般

			break;
		}
		case GAME_STORY: {

			soundTitle();					//タイトル画面でのサウンド制御
			storyDraw();					//ストーリー背景描画
			storyMessage();					//ストーリーメッセージ描画
			leafBottonDrawStory(delta_time);//エンター画像描画

			break;
		}
		case GAME_TUTORIAL: {

			soundTitle();					//タイトル画面でのサウンド制御
			tutorialDraw();					//チュートリアル画像描画
			tutorialMessage();				//チュートリアルメッセージ描画
			leafBottonDrawStory(delta_time);//エンター画像描画

			break;
		}
		case GAME_MAP: {

			playMusic();					//音声関連
			getCharaPosition();				//charaData[MAP_HEIGHT][MAP_WIDTH]定義
			mapPosition(delta_time);		//画像描画
			display();						//下画面情報描画制御
			cellInfoDisplay();				//地形回復情報表示処理
			cursorMove(delta_time);			//カーソル移動手定義
			instructions(delta_time);		//指示文字描画
			scoreDraw();					//score描画
			turnMove(delta_time);			//ゲームの流れ全般
			
			break;
		}
		case GAME_OVER: {

			soundOver();					//ゲームオーバー音楽再生
			gameOver(delta_time);			//ゲームオーバー全般	
			scoreResult();					//スコア描画
				
			break;
		}
		case GAME_CLEAR: {

			soundClear();					//クリア音楽再生
			gameClear(delta_time);			//ゲームクリア全般
			leafBottonDrawStory(delta_time);//エンター画像描画
			movieDraw();					//エンドアニメーション動画

			break;
		}
	}
}
//
//------------------------------------------------------------------------------------------------------------
// ゲーム終了時に１度だけ実行されます
void gameEnd() {

}
