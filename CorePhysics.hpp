#pragma once
#include "MathFunctions.hpp"
struct vec2
{
	float x, y;
	vec2() : x(0), y(0) {}
	vec2(const float val) :x(val), y(val) {}
	vec2(const float x, const float y) :x(x), y(y) {}
	vec2 operator +(const vec2& a) const { return vec2{ x + a.x,y + a.y }; }
	vec2 operator -(const vec2& a) const { return vec2{ x - a.x,y - a.y }; }
	vec2 operator *(const float a) const { return vec2{ x * a,y * a }; }
	float dot(const vec2& a) { return x * a.x + y * a.y; }
	float magnitude() { return sqrt(x * x + y * y); }
	float sqrMagnitude() { return x * x + y * y; }
	vec2 normalized()
	{
		const float m = 1.0f / magnitude();
		return vec2(x * m, y * m);
	}
	void normalize()
	{
		const float m = 1.0f / magnitude();
		x = x * m;
		y = y * m;
	}
};
struct vec3
{
	float x, y, z;
	vec3() : x(0), y(0), z(0) {}
	vec3(const float val) :x(val), y(val), z(val) {}
	vec3(const float x, const float y, const float z) :x(x), y(y), z(z) {}
	vec3 operator +(const vec3& a) const { return vec3{ x + a.x, y + a.y, z + a.z }; }
	vec3 operator -(const vec3& a) const { return vec3{ x - a.x, y - a.y, z - a.z }; }
	vec3 operator *(const float a) const { return vec3{ x * a, y * a, z * a }; }
	bool operator ==(const vec3& a) const { return MathFunctions::areEqualRel(x, a.x) && MathFunctions::areEqualRel(y, a.y) && MathFunctions::areEqualRel(z, a.z); }
	float dot(const vec3& a)const { return x * a.x + y * a.y + z * a.z; }
	vec3 cross(const vec3& a) { return vec3{ y * a.z - z * a.y, z * a.x - x * a.z, y * a.z - z * a.y }; }
	float magnitude() { return sqrt(x * x + y * y + z * z); }
	float sqrMagnitude() { return x * x + y * y + z * z; }
	vec3 normalized()
	{
		const float m = 1.0f / magnitude();
		return vec3(x * m, y * m, z * m);
	}
	void normalize()
	{
		const float m = 1.0f / magnitude();
		x = x * m;
		y = y * m;
		z = z * m;
	}
};
struct mat3x3
{
	float m[3][3]{};

	//defaults to identity matrix
	mat3x3()
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (i == j)
				{
					m[i][j] = 1;
				}
				else
				{
					m[i][j] = 0;
				}
			}
		}


	}
	bool operator ==(const mat3x3& a) const
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (!MathFunctions::areEqualRel(a.m[i][j], m[i][j]))
				{
					return false;
				}
			}
		}
		return true;
	}
	mat3x3 operator *(const mat3x3& a) const
	{
		mat3x3 result;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				float sum = 0;
				for (int f = 0; f < 3; f++)
					sum += m[i][f] * a.m[f][j];


				result.m[i][j] = sum;
			}
		}
		return result;

	}


	//row vector multiplication
	static void rowVectorMultiplication(const mat3x3& m, vec3& a)
	{
		a.x = a.x * m.m[0][0] + a.y * m.m[1][0] + a.z * m.m[2][0];
		a.y = a.y * m.m[0][1] + a.y * m.m[1][1] + a.z * m.m[2][1];
		a.z = a.z * m.m[0][2] + a.y * m.m[1][2] + a.z * m.m[2][2];
	}
	static void transpose(mat3x3& m)
	{
		mat3x3 newM = {};
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				newM.m[j][i] = m.m[i][j];
			}
		}
		m = newM;
	}

};
struct mat2x2
{
	float m[2][2] = {};
	//defaults to identity matrix
	mat2x2()
	{
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				if (i == j)
				{
					m[i][j] = 1;
				}
				else
				{
					m[i][j] = 0;
				}
			}
		}


	}
	mat2x2 operator *(const mat2x2& a) const
	{
		mat2x2 result;
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				float sum = 0;
				for (int f = 0; f < 2; f++)
					sum += m[i][f] * a.m[f][j];


				result.m[i][j] = sum;
			}
		}
		return result;

	}
	bool operator ==(const mat2x2& a) const
	{
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				if (!MathFunctions::areEqualRel(a.m[i][j], m[i][j]))
				{
					return false;
				}
			}
		}
		return true;
	}
	//Returns the corresponding matrix to the 2D vector rotated by the angle in the mat variable
	//Note that angle is in radians and the rotation is positive counterclockwise
	static void Rotate2D(float angle, mat2x2& mat)
	{
		mat2x2 newM = {};

		//x axis
		newM.m[0][0] = cos(angle);
		newM.m[0][1] = sin(angle);
		//y axis
		newM.m[1][0] = -sin(angle);
		newM.m[1][1] = cos(angle);

		mat = newM;
	}
};
