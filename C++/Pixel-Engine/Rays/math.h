#ifndef _MATH_H_
#define _MATH_H_

const float DEG2RAD = 0.01745329251994329576923690768f;
const float RAD2DEG = 57.2957795130823208767981548141f;

inline float ToRadian(const float Degree) {
	return (Degree * DEG2RAD);
}

inline float ToDegree(const float Radian) {
	return (Radian * RAD2DEG);
}

template<class T>
struct Vec4 {
	T x, y, z, w;
	template<class P>
	Vec4(P x, P y, P z, P w) : x(x), y(y), z(z), w(w) {}
	template<class P>
	Vec4(P all) : x(all), y(all), z(all), w(all) {}
	Vec4() : x(0), y(0), z(0), w(0) {}
	inline Vec4& dot(const Vec4<T>& v) {
		return (x * v.x + y * v.y + z * v.z + w * v.w);
	}
	inline const Vec4& operator+() {
		return *this;
	}
	inline Vec4& operator-() {
		return Vec4<T>(-x, -y, -z, -w);
	}
	inline Vec4& operator+(const Vec4<T>& v) {
		return new Vec4(x + v.x, y + v.y, z + v.z, w + v.w);
	}
	inline Vec4& operator-(const Vec4<T>& v) {
		return new Vec4(x - v.x, y - v.y, z - v.z, w - v.w);
	}	
	inline Vec4& operator*(const Vec4<T>& v) {
		return new Vec4(x * v.x, y * v.y, z * v.z, w * v.w);
	}
	inline Vec4& operator/(const Vec4<T>& v) {
		return new Vec4(x / v.x, y / v.y, z / v.z, w / v.w);
	}
	inline Vec4& operator+=(const Vec4<T>& v) {
		x+=v.x; y+=v.y; z+=v.z; w+=v.w;
		return *this;
	}
	inline Vec4& operator-=(const Vec4<T>& v) {
		x-=v.x; y-=v.y; z-=v.z; w-=v.w;
		return *this;
	}
	inline Vec4& operator*=(const Vec4<T>& v) {
		x*=v.x; y*=v.y; z*=v.z; w*=v.w;
		return *this;
	}
	inline Vec4& operator/=(const Vec4<T>& v) {
		x/=v.x; y/=v.y; z/=v.z; w/=v.w;
		return *this;
	}
	template<class P>
	inline Vec4& operator+=(P s) {
		x+=s; y+=s; z+=s; w+=s;
		return *this;
	}
	template<class P>
	inline Vec4& operator-=(P s) {
		x-=s; y-=s; z-=s; w-=s;
		return *this;
	}
	template<class P>
	inline Vec4& operator*=(P s) {
		x*=s; y*=s; z*=s; w*=s;
		return *this;
	}
	template<class P>
	inline Vec4& operator/=(P s) {
		x/=s; y/=s; z/=s; w/=s;
		return *this;
	}
};

template<class T>
struct Vec3 {
	T x, y, z;
	template<class P>
	Vec3(P x, P y, P z) : x(x), y(y), z(z) {}
	template<class P>
	Vec3(P all) : x(all), y(all), z(all) {}
	Vec3() : x(0), y(0), z(0) {}
	inline Vec3& cross(const Vec3<T>& v) {
		return new Vec3(
			(y * v.z - z * v.y),
			(x * v.z - z * v.x),
			(x * v.y - y * v.x)
		);
	}
	inline Vec3& dot(const Vec3<T>& v) {
		return (x * v.x + y * v.y + z * v.z);
	}
	inline const Vec3& operator+() {
		return *this;
	}
	inline Vec3& operator-() {
		return Vec3<T>(-x, -y, -z);
	}
	inline Vec3& operator+(const Vec3<T>& v) {
		return new Vec3(x + v.x, y + v.y, z + v.z);
	}
	inline Vec3& operator-(const Vec3<T>& v) {
		return new Vec3(x - v.x, y - v.y, z - v.z);
	}	
	inline Vec3& operator*(const Vec3<T>& v) {
		return new Vec3(x * v.x, y * v.y, z * v.z);
	}
	inline Vec3& operator/(const Vec3<T>& v) {
		return new Vec3(x / v.x, y / v.y, z / v.z);
	}
	inline Vec3& operator+=(const Vec3<T>& v) {
		x+=v.x; y+=v.y; z+=v.z;
		return *this;
	}
	inline Vec3& operator-=(const Vec3<T>& v) {
		x-=v.x; y-=v.y; z-=v.z;
		return *this;
	}
	inline Vec3& operator*=(const Vec3<T>& v) {
		x*=v.x; y*=v.y; z*=v.z;
		return *this;
	}
	inline Vec3& operator/=(const Vec3<T>& v) {
		x/=v.x; y/=v.y; z/=v.z;
		return *this;
	}
	template<class P>
	inline Vec3& operator+=(P s) {
		x+=s; y+=s; z+=s;
		return *this;
	}
	template<class P>
	inline Vec3& operator-=(P s) {
		x-=s; y-=s; z-=s;
		return *this;
	}
	template<class P>
	inline Vec3& operator*=(P s) {
		x*=s; y*=s; z*=s;
		return *this;
	}
	template<class P>
	inline Vec3& operator/=(P s) {
		x/=s; y/=s; z/=s;
		return *this;
	}
};

template<class T>
struct Vec2 {
	T x, y;
	template<class P>
	Vec2(P x, P y) : x(x), y(y) {}
	template<class P>
	Vec2(P all) : x(all), y(all) {}
	Vec2() : x(0), y(0) {}
		inline const Vec2& operator+() {
		return *this;
	}
	inline Vec2& dot(const Vec3<T>& v) {
		return (x * v.x + y * v.y);
	}
	inline Vec2& operator-() {
		return Vec3<T>(-x, -y);
	}
	inline Vec2& operator+(const Vec2<T>& v) {
		return new Vec2(x + v.x, y + v.y);
	}
	inline Vec2& operator-(const Vec2<T>& v) {
		return new Vec2(x - v.x, y - v.y);
	}	
	inline Vec2& operator*(const Vec2<T>& v) {
		return new Vec2(x * v.x, y * v.y);
	}
	inline Vec2& operator/(const Vec2<T>& v) {
		return new Vec2(x / v.x, y / v.y);
	}
	inline Vec2& operator+=(const Vec2<T>& v) {
		x+=v.x; y+=v.y;
		return *this;
	}
	inline Vec2& operator-=(const Vec2<T>& v) {
		x-=v.x; y-=v.y;
		return *this;
	}
	inline Vec2& operator*=(const Vec2<T>& v) {
		x*=v.x; y*=v.y;
		return *this;
	}
	inline Vec2& operator/=(const Vec2<T>& v) {
		x/=v.x; y/=v.y;
		return *this;
	}
	template<class P>
	inline Vec2& operator+=(P s) {
		x+=s; y+=s;
		return *this;
	}
	template<class P>
	inline Vec2& operator-=(P s) {
		x-=s; y-=s;
		return *this;
	}
	template<class P>
	inline Vec2& operator*=(P s) {
		x*=s; y*=s;
		return *this;
	}
	template<class P>
	inline Vec2& operator/=(P s) {
		x/=s; y/=s;
		return *this;
	}
};

#endif