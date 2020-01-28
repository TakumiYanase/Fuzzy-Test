//======================================================
/// File Name	: Fuzzy.h
/// Date		: 2020.1.28
/// Author		: Takumi Yanase
//======================================================
// インクルードガード
#ifndef INCLUDE_FUZZY
#define INCLUDE_FUZZY
//======================================================

template<typename T1,typename T2>
constexpr auto MIN(T1 x, T2 y)
{
	return (x < y) ? x : y;
}

template<typename T1, typename T2>
constexpr auto MAX(T1 x, T2 y)
{
	return (x > y) ? x : y;
}

float FuzzyGrade(float value, float x0, float x1)
{
	float result = 0.0f;
	float x = value;

	if (x <= x0)
		result = 0.0f;
	else if (x >= x1)
		result = 1.0f;
	else
		result = (x / (x1 - x0)) - (x0 / (x1 - x0));

	return result;
}

float FuzzyReverseGrade(float value, float x0, float x1)
{
	float result = 0.0f;
	float x = value;

	if (x <= x0)
		result = 1.0f;
	else if (x > x1)
		result = 0.0f;
	else
		result = (-x / (x1 - x0)) + (x1 / (x1 - x0));

	return result;
}

float FuzzyTriangle(float value, float x0, float x1, float x2)
{
	float result = 0.0f;
	float x = value;

	if (x <= x0 || x >= x2)
		result = 0.0f;
	else if (x == x1)
		result = 1.0f;
	else if (x > x0 && x < x1)
		result = (x / (x1 - x0)) - (x0 / (x1 - x0));
	else
		result = (-x / (x2 - x1)) + (x2 / (x2 - x1));

	return result;
}

float FuzzyTrapezoid(float value, float x0, float x1, float x2, float x3)
{
	float result = 0.0f;
	float x = value;

	if (x <= x0 || x >= x3)
		result = 0.0f;
	else if (x >= x1 && x <= x2)
		result = 1.0f;
	else if (x > x0 && x < x1)
		result = (x / (x1 - x0)) - (x0 / (x1 - x0));
	else
		result = (-x / (x3 - x2)) + (x3 / (x3 - x2));

	return result;
}

// ファジールール
float FuzzyAND(float A, float B)
{
	return MIN(A, B);
}

float FuzzyOR(float A, float B)
{
	return MAX(A, B);
}

float FuzzyNOT(float A)
{
	return 1.0 - A;
}

#endif // INCLUDE_FUZZY