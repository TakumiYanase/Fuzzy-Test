//======================================================
/// File Name	: MyText.h
/// Date		: 2020.1.28
/// Author		: Takumi Yanase
//======================================================
// インクルードガード
#ifndef INCLUDE_MY_TEXT
#define INCLUDE_MY_TEXT
//======================================================
// インクルード
#include <iostream>
#include <string>
//======================================================

// 改行
void NewLine()
{
	std::cout << std::endl;
}

// パーティション
void Partition(int count)
{
	std::cout << std::endl;
	for (int i = 0; i < count; i++)
	{
		std::cout << "=";
	}
	std::cout << std::endl;
}

// 出力(string型)
void OutPutText(const std::string str)
{
	std::cout << str << std::endl;
}

// 出力(string & float)
void OutPutText(const std::string str, const float value)
{
	std::cout << str << "：" << value << std::endl;
}

// 出力(float & float)
void OutPutText(const float value1, const float value2)
{
	std::cout << value1 << "：" << value2 << std::endl;
}

#endif 