//======================================================
/// File Name	: main.cpp
/// Date		: 2020.1.28
/// Author		: Takumi Yanase
//======================================================
// �C���N���[�h
#include <iostream>
#include "MyText.h"
#include "Fuzzy.h"
//======================================================

int main()
{
	// ����
	float range = 20.0f;
	// �̗�
	float health = 90.0f;

	// ��������͂��u���̓x�����v���v�Z����
	float melee = FuzzyReverseGrade(range, 0.0f, 1.0f);
	// ��������͂��u���˂̓x�����v���v�Z����
	float projectile = FuzzyTrapezoid(range, 1.0f, 5.0f, 30.0f, 50.0f);
	// ��������͂��u���͈͊O�̓x�����v���v�Z����
	float outOfRange = FuzzyGrade(range, 40.0f, 60.0f);

	// �̗͂���͂��u�m���̓x�����v���v�Z����
	float nearDeath = FuzzyReverseGrade(health, 0.0f, 5.0f);
	// �̗͂���͂��u��Ă̓x�����v���v�Z����
	float critical = FuzzyTrapezoid(health, 2.0f, 10.0f, 15.0f, 20.0f);
	// �̗͂���͂��u�d�ǂ̓x�����v���v�Z����
	float serious = FuzzyTrapezoid(health, 15.0f, 25.0f, 30.0f, 35.0f);
	// �̗͂���͂��u�y���̓x�����v���v�Z����
	float minor = FuzzyTrapezoid(health, 70.0f, 85.0f, 90.0f, 95.0f);
	// �̗͂���͂��u�����̓x�����v���v�Z����
	float uninjured = FuzzyGrade(health, 97.0f, 100.0f);

	NewLine();
	OutPutText("�t�@�W�[���[����K�p����");
	OutPutText("if(���͈͓� AND ����)");
	float degreeAttack = FuzzyAND(melee, uninjured);
	OutPutText("�U��", degreeAttack);

	NewLine();
	OutPutText("if(NOT ���͈͓�) AND ���� THEN �������Ȃ�");
	float degreeDoNothing = FuzzyAND(FuzzyNOT(melee), uninjured);
	OutPutText("�������Ȃ�", degreeDoNothing);

	NewLine();
	OutPutText("if(NOT ���͈͊O AND NOT(����)) THEN ����");
	float degreeFree = FuzzyAND(FuzzyNOT(outOfRange), FuzzyNOT(uninjured));
	OutPutText("����", degreeFree);

	Partition(50);

	NewLine();
	OutPutText("����", range);
	OutPutText("���", melee);
	OutPutText("����", projectile);
	OutPutText("���͈͊O", outOfRange);

	NewLine();
	OutPutText("�̗�", health);
	OutPutText("�m��", nearDeath);
	OutPutText("���", critical);
	OutPutText("�d��", serious);
	OutPutText("�y��", minor);
	OutPutText("����", uninjured);

	return 0;
}