#pragma once
#include "MathFunctions.hpp"
#include <algorithm>



struct vec2
{
	union {
		struct {
			float x, y;
		};
		float cell[2];
	};
	float& operator [] (const int x) { return cell[x]; }
	float operator [] (const int x) const { return cell[x]; }

	vec2() : x(0), y(0) {}
	vec2(const float& val) :x(val), y(val) {}
	vec2(const float& x, const float& y) :x(x), y(y) {}
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
	const float tolerance = 0.0001f;
	bool operator ==(const vec2& a) const { return MathFunctions::areEqualRel(x, a.x, tolerance) && MathFunctions::areEqualRel(y, a.y, tolerance); }

};
struct vec3
{
	union {
		struct {
			float x, y, z;
		};
		float cell[3];
	};
	float& operator [] (const int x) { return cell[x]; }
	float operator [] (const int x) const { return cell[x]; }

	vec3() : x(0), y(0), z(0) {}
	vec3(const float val) :x(val), y(val), z(val) {}
	vec3(const float x, const float y, const float z) :x(x), y(y), z(z) {}
	vec3(const vec2& v) :x(v.x), y(v.y), z(0) {}
	vec3 operator +(const vec3& a) const { return vec3{ x + a.x, y + a.y, z + a.z }; }
	vec3 operator -(const vec3& a) const { return vec3{ x - a.x, y - a.y, z - a.z }; }
	vec3 operator -() const { return vec3{ -x,  -y,  -z }; }
	vec3 operator *(const float a) const { return vec3{ x * a, y * a, z * a }; }
	vec3 operator /(const float a) const { return vec3{ x / a, y / a, z / a }; }


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
	//Returns the corresponding matrix to the 2D vector rotated by the a in the mat variable
	//Note that a is in radians and the rotation is positive counterclockwise
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
	static float det(const mat2x2& mat)
	{
		return mat.m[0][0] * mat.m[1][1] - mat.m[0][1] * mat.m[1][0];
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

	mat3x3 operator /(const float d) const
	{
		mat3x3 result;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				result.m[i][j] = m[i][j] / d;

			}
		}
		return result;

	}
	/// <summary>
	/// Stores the matrix for the specified 3D rotation in mat
	/// </summary>
	/// <param name="angle_to_rotate">the a in radians</param>
	/// <param name="axisToRotate">Axis which we are going to rotate around</param>
	/// <param name="mat">where the rotation gets stored</param>
	static void Rotate3D(const float angle_to_rotate, const vec3& axisToRotate, mat3x3& mat)
	{
		mat3x3 newM;
		const float COS_SIN_COMBINATIONS[3] = { cosf(angle_to_rotate),sinf(angle_to_rotate) ,-sinf(angle_to_rotate) };
		float SECONDARY_AXIS[4] = { 1,axisToRotate[2] ,axisToRotate[1],axisToRotate[0] };

		for (int i = 0; i < 3; i++) {
			const float axis = axisToRotate[i];
			for (int j = 0; j < 3; j++) {
				const int index = (3 - i + j) % 3;
				newM.m[i][j] = axis * axisToRotate[j] * (1 - cos(angle_to_rotate)) + COS_SIN_COMBINATIONS[index] * SECONDARY_AXIS[index];
			}
			if (i == 1)
			{
				std::swap(SECONDARY_AXIS[1], SECONDARY_AXIS[3]);
				std::swap(SECONDARY_AXIS[2], SECONDARY_AXIS[3]);
			}
			else
			{
				std::swap(SECONDARY_AXIS[1], SECONDARY_AXIS[2]);
				std::swap(SECONDARY_AXIS[1], SECONDARY_AXIS[3]);
			}
		}
		mat = newM;

	}
	static mat3x3 RoundToInt(const mat3x3& mat)
	{
		mat3x3 newM;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				newM.m[i][j] = round(mat.m[i][j] * 1000);
			}
		}
		return  newM;
	}


	/// <summary>
	/// Multiplies the matrix m with the vector a from left to right.
	///	Results a 1x3 matrix (which is the vec3)
	/// </summary>
	/// <param name="m"></param>
	/// <param name="a"></param>
	static void rowVectorMultiplication(const mat3x3& m, vec3& a)
	{
		a.x = a.x * m.m[0][0] + a.y * m.m[1][0] + a.z * m.m[2][0];
		a.y = a.y * m.m[0][1] + a.y * m.m[1][1] + a.z * m.m[2][1];
		a.z = a.z * m.m[0][2] + a.y * m.m[1][2] + a.z * m.m[2][2];
	}
	static void transpose(mat3x3& m)
	{
		mat3x3 newM;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				newM.m[j][i] = m.m[i][j];
			}
		}
		m = newM;
	}
	/// <summary>
	/// Scales uniformly along all axis by s
	/// </summary>
	/// <param name="m"></param>
	/// <param name="s"></param>
	static void Scale(mat3x3& m, const float s)
	{
		m = mat3x3();
		for (int i = 0; i < 3; i++)
		{
			m.m[i][i] = s;
		}
	}
	static void ScaleAlongAxis(mat3x3& m, const float& s, const vec3& axis)
	{
		m = mat3x3();
		const float k = s - 1;
		for (int i = 0; i < 3; i++)
		{

			for (int j = 0; j < 3; j++)
			{
				m.m[i][j] = axis[i] * axis[j] * k;
				if (i == j)
					m.m[i][j]++;
			}
		}
	}
	/// <summary>
	/// Does the same as the scaling but it uses a scaling factor of 0.
	/// </summary>
	/// <param name="m"></param>
	/// <param name="axis"></param>
	static void OrthographicProjection(mat3x3& m, const vec3& axis)
	{
		ScaleAlongAxis(m, 0, axis);
	}
	/// <summary>
	/// Does the same as scaling but it uses a scaling of -1.
	/// </summary>
	/// <param name="m"></param>
	/// <param name="axis"></param>
	static void Reflection(mat3x3& m, const vec3& axis)
	{
		ScaleAlongAxis(m, -1, axis);
	}
	static float det(const mat3x3& mat)
	{
		return mat.m[0][0] * mat.m[1][1] * mat.m[2][2] + mat.m[1][0] * mat.m[2][1] * mat.m[0][2] + mat.m[0][1] * mat.m[1][2] * mat.m[2][0] -
			(mat.m[0][2] * mat.m[1][1] * mat.m[2][0] +
				mat.m[0][1] * mat.m[1][0] * mat.m[2][2] +
				mat.m[0][0] * mat.m[1][2] * mat.m[2][1]);
	}
	static float min(const mat3x3& mat, const int i, const int j)
	{
		mat2x2 minor;
		int x = 0, y = 0;

		for (int c = 0; c < 3; c++) {
			for (int d = 0; d < 3; d++) {
				if (c != i && d != j) {
					minor.m[x][y++] = mat.m[c][d];
					if (y == 2)
					{
						y = 0;
						x++;
					}

				}

			}

		}

		return mat2x2::det(minor);
	}

	static mat3x3 adj(const mat3x3& mat)
	{
		mat3x3 newM;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if ((i + j) % 2 == 0)
					newM.m[i][j] = min(mat, i, j);
				else
					newM.m[i][j] = -min(mat, i, j);

			}
		}
		transpose(newM);
		return  newM;
	}
	static mat3x3 inv(const mat3x3& mat)
	{
		const float de = det(mat);
		return  adj(mat) / de;

	}
};

struct mat4x4
{
	float m[4][4]{};

	//defaults to identity matrix
	mat4x4()
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
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
	bool operator ==(const mat4x4& a) const
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (!MathFunctions::areEqualRel(a.m[i][j], m[i][j]))
				{
					return false;
				}
			}
		}
		return true;
	}
	static mat4x4 multiplyTranslationLinear(const mat3x3& linearTrans, const vec3& translation)
	{
		mat4x4 mat;

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{

				mat.m[i][j] = linearTrans.m[i][j];

				mat.m[3][i] += translation[j] * linearTrans.m[j][i];

			}
		}
		return mat;
	}
	static mat4x4 constructLinearTransformation(const mat3x3& linearTrans, const vec3& translation)
	{
		mat4x4 mat;

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{

				mat.m[i][j] = linearTrans.m[i][j];

			}
			mat.m[3][i] = translation[i];
		}
		return mat;
	}

	static mat4x4 PerspectiveProjection(const vec3& axis, const float distance)
	{
		mat4x4 mat;
		mat.m[3][3] = 0;
		for (int i = 0; i < 3; i++)
		{
			mat.m[i][3] = axis[i] / distance;
		}
		return mat;
	}
	static vec3 PerspectiveProjectionToVec3(const mat4x4& mat, const vec3& v)
	{
		vec3 newV;
		for (int i = 0; i < 3; i++)
		{
			float sum = 0;
			for (int j = 0; j < 3; j++)
			{
				sum += mat.m[j][i] * v[j];
			}
			newV[i] = sum;
		}
		float sum = 0;

		for (int i = 0; i < 3; i++)
		{
			sum += mat.m[i][3] * v[i];
		}


		return newV / sum;
	}
	static mat3x3 GetLinearTransformation(const mat4x4& mat)
	{
		mat3x3 M;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				M.m[i][j] = mat.m[i][j];
			}
		}
		return M;
	}

	static vec3 GetTranslation(const mat4x4& mat)
	{
		vec3 v;

		for (int j = 0; j < 3; j++)
		{
			v[j] = mat.m[3][j];
		}

		return v;
	}
	static mat4x4 RoundToInt(const mat4x4& mat)
	{
		mat4x4 newM;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				newM.m[i][j] = round(mat.m[i][j] * 1000);
			}
		}
		return  newM;
	}
};
/// <summary>
/// polar coordinates in 2D with angles expressed in radians
/// </summary>
struct poco2 {
	/// <summary>
	/// radius r and angle in radians a
	/// </summary>
	float r, a;
	const float tolerance = 0.000001f;
	bool operator ==(const poco2& p) const
	{
		return MathFunctions::areEqualRel(a, p.a, tolerance) && MathFunctions::areEqualRel(r, p.r, tolerance);
	}

	poco2()
		:
		r(0.0f),
		a(0.0f)
	{

	}
	poco2(float r, float a)
		:
		r(r),
		a(a)
	{
		ToCanonicalForm(*this);
	}
	poco2(const vec2& v)
	{
		r = sqrt(v.x * v.x + v.y * v.y);
		a = atan2(v.y, v.x);
		ToCanonicalForm(*this);
	}
	poco2(const vec3& v)
	{
		r = sqrt(v.x * v.x + v.y * v.y);
		a = atan2(v.y, v.x);
		ToCanonicalForm(*this);
	}

	//from https://gamemath.com/book/polarspace.html
	static void ToCanonicalForm(poco2& p)
	{
		if (p.r == 0.0f)
		{
			p.a = 0.0f;
		}
		else {

			//angle out side of -PI and PI
			if (fabs(p.a) > PI)
			{

				p.a += PI;

				p.a -= floor(p.a / TWO_PI) * TWO_PI;

				p.a -= PI;
			}
			//negative radius
			if (p.r < 0)
			{
				p.r = -p.r;
				p.a += PI;
			}
		}
	}
	static vec2 ToCartesianForm(const poco2& p)
	{
		vec2 c;
		c.x = p.r * cosf(p.a);
		c.y = p.r * sinf(p.a);
		return c;
	}
};
/// <summary>
/// cylindrical  coordinates
/// </summary>
struct cyco3 {
	poco2 p;
	float z;

	const float tolerance = 0.000001f;
	bool operator ==(const cyco3& c) const
	{
		return MathFunctions::areEqualRel(p.a, c.p.a, tolerance) && MathFunctions::areEqualRel(p.r, c.p.r, tolerance && MathFunctions::areEqualRel(z, c.z, tolerance));
	}
	cyco3()
		:
		p(0.0f, 0.0f),
		z(0.0f)
	{

	}
	cyco3(float r, float a, float z)
		:
		p(r, a),
		z(z)
	{
		poco2::ToCanonicalForm(p);
	}
	cyco3(const poco2& p, float z)
		:
		p(p),
		z(z)
	{
		poco2::ToCanonicalForm(this->p);
	}
};
/// <summary>
/// Spherical coordinates
/// </summary>
struct spco3 {

	union
	{
		struct {

			/// radius, heading

			float r, h;
		};
		poco2 po;
	};
	// pitch
	float p;
	const float tolerance = 0.000001f;
	bool operator ==(const spco3& c) const
	{
		return MathFunctions::areEqualRel(po.a, c.po.a, tolerance) && MathFunctions::areEqualRel(po.r, c.po.r, tolerance && MathFunctions::areEqualRel(p, c.p, tolerance));
	}
	spco3()
		:
		po(0.0f, 0.0f),
		p(0.0f)
	{

	}
	spco3(float r, float a, float p)
		:
		po(r, a),
		p(p)
	{
		ToCanonicalForm(*this);

	}
	spco3(const poco2& po, float p)
		:
		po(po),
		p(p)
	{
		ToCanonicalForm(*this);
	}
	spco3(const vec3& v)
	{
		r = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
		h = atan2(v.x, v.z);
		p = asin(-v.y / r);
		ToCanonicalForm(*this);
	}
	/// <summary>
	/// In the math way 
	/// </summary>
	/// <param name="s"></param>
	/// <returns></returns>
	static vec3 ToCartesianFormRightHanded(const spco3& s)
	{
		vec3 c;
		c.x = s.po.r * sin(s.p) * cos(s.po.a);
		c.y = s.po.r * sin(s.p) * sin(s.po.a);
		c.z = s.po.r * cos(s.p);
		return c;
	}
	/// <summary>
	/// Left handed suitable for game development
	///	For h=0 it points to z+
	///	For p=0 it is horizontal only around the center of a circle and positive is downward 
	/// </summary>
	/// <param name="s"></param>
	/// <returns></returns>
	static vec3 ToCartesianForm(const spco3& s)
	{
		vec3 c;
		c.x = s.r * cos(s.p) * sin(s.h);
		c.y = -s.r * sin(s.p);
		c.z = s.r * cos(s.p) * cos(s.h);
		return c;
	}
	//from https://gamemath.com/book/polarspace.html
	static void ToCanonicalForm(spco3& s)
	{
		if (s.r == 0.0f)
		{
			s.h = s.p = 0.0f;
		}
		else {
			//negative radius
			if (s.r < 0.0f)
			{
				s.r = -s.r;
				s.h += PI;
				s.p = -s.p;
			}
			if (fabs(s.p) > PI_OVER_TWO)
			{

				s.p += PI_OVER_TWO;

				s.p -= floor(s.p / TWO_PI) * TWO_PI;

				if (s.p > PI)
				{
					s.h += PI;
					s.p = 3.0f * PI / 2.0f - s.p;//270 - pitch
				}
				else
				{
					s.p -= PI_OVER_TWO;

				}
			}
			if (fabs(s.p >= PI_OVER_TWO * 0.9999f))
			{
				s.h = 0.0f;
			}
			else
			{
				if (fabs(s.h) > PI) {

					s.h += PI;

					s.h -= floor(s.h / TWO_PI) * TWO_PI;

					s.h -= PI;
				}
			}
		}
	}
};