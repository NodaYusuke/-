#pragma once

#define	SCRW		    1280   // ウィンドウ幅  （Width
#define	SCRH		    720    // ウィンドウ高さ（Height
#define	FVF_VERTEX (D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1)

const int MISS = -1;            /*あっていない*/
const float NOTGO = 4.0f;       /*これ以上近寄れない距離*/
const float LIMITLENGH = 20.0f;       /*これ以上近寄れない距離*/
const int LIMITLEN = 15;        /*敵がこれ以上は慣れない距離*/
const int EFFECTNUM = 50;       /*攻撃エフェクトのポリゴン枚数*/
const float POLYNUM = 5.0f;      /*ステージのポリゴンの枚数*/
const float POLYSIZE = 10.0f;
const int   DAMEAGECNTNUM = 10;  /*攻撃された時の無敵時間*/
const float MOVESPEED = 0.15f;   /*移動速度*/
const float SIDEMOVESPEED = 0.2f;/*移動速度*/
const float STEPSPEED = 0.4f;    /*ステップ速度*/
const float SIDESTEPSPEED = 0.6f;/*横ステップ速度*/
const int STEPTIME = 10;         /*ステップ時間*/
const int STEPKEYTIME = 30;      /*ステップの受付時間*/
const int ATTACKMOTIONEND = 2;   /*攻撃のモーションの数*/
const int GUARDMOTIONEND = 2;    /*防御のモーションの数*/
const float CHARAANGSPEED = 2.0f;/*キャラクターの回転速度*/
const int   TESTATTACKCNT = 120; /*テスト用のてきの攻撃頻度*/

const int TEXTALPHASWICHCNT = 60;/*タイトルのテキストの点滅頻度*/
const int BATTLESTARTTEXCNTNUM = 120;/*戦いが開始した時にテキストを表示する時間*/

const int LIMITTIME = 10800;
const int TIMETEXSIZEX = 50;
const float SCALESIZE = 1.5f;

const float GAUGEPOSX = 10.0f;/*バーのX座標*/
const float MAXHP = 100.0f;/*最大体力*/
const float HPGAUGEWIDTH = 550.0f;  /*HPバーの横の長さ*/
const float HPGAUGEHEIGHT = 50.0f; /*HPバーの縦の長さ*/

const float MAXST = 100.0f;/*最大スタミナ*/
const float STGAUGEWIDTH = 550.0f;  /*HPバーの横の長さ*/
const float STGAUGEHEIGHT = 25.0f; /*HPバーの縦の長さ*/
const float STHEELNUM = 0.2f;
const int   STCOLORCHAGECNT = 60;

const int EFFECTRENDERTIME=60;/*エフェクトが表示される時間*/

const int CHAGENEXTSTAYTIMEMIN = 100;
const int CHAGENEXTSTAYTIMEMAX = 10;

const int OTHER = -1;
const float OVERSTAGELENMARGIN = -5;

const int attackUpPoint = 5;


//stack関連
const int POSITIONSTACKDOWNSPEED = 1;//減少速度
const int POSITIONSTACKUPSPEED = 5;//増加速度

const int OTHERSTACKUPSPEED = 100;//増加速度
const int OTHERSTACKDOWNSPEED = 50;//増加速度

const int STACKMAXRIMIT = 1200;//最大値

const int MOVEWAYCHAGECNT = 30;

const int ATTACKRANDNUM = 10;

const int RANDOMSEED = 50;

const int UPATTACKRIMIT = 10;

const enum { TOP = 0, NORMAL, UNDER };
const enum { STAY = 0,STEP,MOVE, ATTACK,GUARD ,};
const enum { FORWARD = 0, REVERSE, LEFT, RIGHT };