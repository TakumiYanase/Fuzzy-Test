//======================================================
/// File Name	: main.cpp
/// Date		: 2020.1.28
/// Author		: Takumi Yanase
//======================================================
// インクルード
#include <iostream>
#include "MyText.h"
#include "Fuzzy.h"
//======================================================

int main()
{
	// 距離
	float range = 20.0f;
	// 体力
	float health = 90.0f;

	// 距離を入力し「交戦の度合い」を計算する
	float melee = FuzzyReverseGrade(range, 0.0f, 1.0f);
	// 距離を入力し「発射の度合い」を計算する
	float projectile = FuzzyTrapezoid(range, 1.0f, 5.0f, 30.0f, 50.0f);
	// 距離を入力し「交戦範囲外の度合い」を計算する
	float outOfRange = FuzzyGrade(range, 40.0f, 60.0f);

	// 体力を入力し「瀕死の度合い」を計算する
	float nearDeath = FuzzyReverseGrade(health, 0.0f, 5.0f);
	// 体力を入力し「危篤の度合い」を計算する
	float critical = FuzzyTrapezoid(health, 2.0f, 10.0f, 15.0f, 20.0f);
	// 体力を入力し「重症の度合い」を計算する
	float serious = FuzzyTrapezoid(health, 15.0f, 25.0f, 30.0f, 35.0f);
	// 体力を入力し「軽傷の度合い」を計算する
	float minor = FuzzyTrapezoid(health, 70.0f, 85.0f, 90.0f, 95.0f);
	// 体力を入力し「無傷の度合い」を計算する
	float uninjured = FuzzyGrade(health, 97.0f, 100.0f);

	NewLine();
	OutPutText("ファジールールを適用する");
	OutPutText("if(交戦範囲内 AND 無傷)");
	float degreeAttack = FuzzyAND(melee, uninjured);
	OutPutText("攻撃", degreeAttack);

	NewLine();
	OutPutText("if(NOT 交戦範囲内) AND 無傷 THEN 何もしない");
	float degreeDoNothing = FuzzyAND(FuzzyNOT(melee), uninjured);
	OutPutText("何もしない", degreeDoNothing);

	NewLine();
	OutPutText("if(NOT 交戦範囲外 AND NOT(無傷)) THEN 逃避");
	float degreeFree = FuzzyAND(FuzzyNOT(outOfRange), FuzzyNOT(uninjured));
	OutPutText("逃避", degreeFree);

	Partition(50);

	NewLine();
	OutPutText("距離", range);
	OutPutText("交戦", melee);
	OutPutText("発射", projectile);
	OutPutText("交戦範囲外", outOfRange);

	NewLine();
	OutPutText("体力", health);
	OutPutText("瀕死", nearDeath);
	OutPutText("危篤", critical);
	OutPutText("重症", serious);
	OutPutText("軽傷", minor);
	OutPutText("無傷", uninjured);

	return 0;
}