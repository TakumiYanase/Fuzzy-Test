//======================================================
/// File Name	: MyText.h
/// Date		: 2020.1.28
/// Author		: Takumi Yanase
//======================================================
// �C���N���[�h�K�[�h
#ifndef INCLUDE_MY_TEXT
#define INCLUDE_MY_TEXT
//======================================================
// �C���N���[�h
#include <iostream>
#include <string>
//======================================================

// ���s
void NewLine()
{
	std::cout << std::endl;
}

// �p�[�e�B�V����
void Partition(int count)
{
	std::cout << std::endl;
	for (int i = 0; i < count; i++)
	{
		std::cout << "=";
	}
	std::cout << std::endl;
}

// �o��(string�^)
void OutPutText(const std::string str)
{
	std::cout << str << std::endl;
}

// �o��(string & float)
void OutPutText(const std::string str, const float value)
{
	std::cout << str << "�F" << value << std::endl;
}

// �o��(float & float)
void OutPutText(const float value1, const float value2)
{
	std::cout << value1 << "�F" << value2 << std::endl;
}

#endif 