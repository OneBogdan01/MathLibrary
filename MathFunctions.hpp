#pragma once
#include <cmath>
constexpr float PI = 3.141592653589793238462643383279502884197169399375105820f;
constexpr float TWO_PI = PI * 2.0f;
constexpr float PI_OVER_TWO = PI / 2.0f;
constexpr float PI_OVER_180 = PI / 180.0f;

class MathFunctions
{

public:
	//from https://stackoverflow.com/questions/4548004/how-to-correctly-and-standardly-compare-floats
	static bool areEqualRel(float a, float b, float epsilon);
	static bool areEqualRel(float a, float b);

};


