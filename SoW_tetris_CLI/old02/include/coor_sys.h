/////////////////////////////////////////////////////////////////////////////////
// File:	coor_sys.h
// charset:	UTF-8
// Project:	SoW_tetris_CLI
// Author:	xtatrax
// Date:	2025/03/01
// Copyright (c) 2025 xtatrax
// All rights reserved.
///////////////////////////////////////////////////////////////////////////////


namespace tlibccp
{
	struct Size ;
	struct Point{
		int x;
		int y;
		Point(int x, int y) : x(x), y(y) {}
		Point() : x(0), y(0) {}
		Point(const Point& other) : x(other.x), y(other.y) {}
		Point(const Size& other) throw();

		inline bool   operator==(const Point& other) const throw();
		inline bool   operator==(const Size& other)  const throw();
		inline bool   operator==(int value)          const throw();
		inline bool   operator!=(const Point& other) const throw();
		inline bool   operator!=(const Size& other)  const throw();
		inline bool   operator!=(int value)          const throw();
		inline bool   operator<(const Point& other)  const throw();
		inline bool   operator<(const Size& other)   const throw();
		inline bool   operator<(int value)           const throw();
		inline bool   operator<=(const Point& other) const throw();
		inline bool   operator<=(const Size& other)  const throw();
		inline bool   operator<=(int value)          const throw();
		inline bool   operator>(const Point& other)  const throw();
		inline bool   operator>(const Size& other)   const throw();
		inline bool   operator>(int value)           const throw();
		inline bool   operator>=(const Point& other) const throw();
		inline bool   operator>=(const Size& other)  const throw();
		inline bool   operator>=(int value)          const throw();
		inline Point  operator+(const Point& other)  const throw();
		inline Point  operator+(const Size& other)   const throw();
		inline Point  operator+(const int value)     const throw();
		inline Point  operator-(const Point& other)  const throw();
		inline Point  operator-(const Size& other)   const throw();
		inline Point  operator-(const int value)     const throw();
		inline Point& operator-()                    throw() { x = -x; y = -y; return *this; }
		inline Point& operator!()                    throw() { x = !x; y = !y; return *this; }
		inline Point& operator~()                    throw() { x = ~x; y = ~y; return *this; }
		inline Point& operator++()                   throw() {                     ++x; ++y; return *this; }
		inline Point  operator++(int)                throw() { Point temp = *this; ++x; ++y; return temp; }
		inline Point& operator--()                   throw(){                     --x; --y; return *this; }
		inline Point  operator--(int)                throw(){ Point temp = *this; --x; --y; return temp; }
		inline Point  operator*(const Point& other)  const throw();
		inline Point  operator*(const Size& other)   const throw();
		inline Point  operator*(const int value)     const throw();
		inline Point  operator/(const Point& other)  const throw();
		inline Point  operator/(const Size& other)   const throw();
		inline Point  operator/(const int value)     const throw();
		inline Point& operator=(const Point& other)  throw();
		inline Point& operator=(const Size& other)   throw();
		inline Point& operator=(int value)           throw();
		inline Point& operator+=(const Point& other) throw();
		inline Point& operator+=(const Size& other)  throw();
		inline Point& operator+=(int value)          throw();
		inline Point& operator-=(const Point& other) throw();
		inline Point& operator-=(const Size& other)  throw();
		inline Point& operator-=(int value)          throw();
		inline Point& operator*=(const Point& other) throw();
		inline Point& operator*=(const Size& other)  throw();
		inline Point& operator*=(int value)          throw();
		inline Point& operator/=(const Point& other) throw();
		inline Point& operator/=(const Size& other)  throw();
		inline Point& operator/=(int value)          throw();
	


	};
	struct Size{
		int width;
		int height;
		Size(int width, int height) : width(width), height(height) {}
		Size() : width(0), height(0) {}
		Size(const Size& other) : width(other.width), height(other.height) {}
		Size(const Point& other) : width(other.x), height(other.y) {}

		inline bool operator==(const Size& other)  const { return width == other.width   && height == other.height; }
		inline bool operator==(const Point& other) const { return width == other.x       && height == other.y; }
		inline bool operator==(int value)          const { return width == value         && height == value; }
		inline bool operator!=(const Size& other)  const { return !(*this == other); }
		inline bool operator!=(const Point& other) const { return !(*this == other); }
		inline bool operator!=(int value)          const { return !(*this == value); }
		inline bool operator<(const Size& other)   const { return (width < other.width)   && (height < other.height); }
		inline bool operator<(const Point& other)  const { return (width < other.x)       && (height < other.y); }
		inline bool operator<(int value)           const { return (width < value)         && (height < value); }
		inline bool operator<=(const Size& other)  const { return (width <= other.width)   && (height <= other.height); }
		inline bool operator<=(const Point& other) const { return (width <= other.x)       && (height <= other.y); }
		inline bool operator<=(int value)          const { return (width <= value)         && (height <= value); }
		inline bool operator>(const Size& other)   const { return (width > other.width)   && (height > other.height); }
		inline bool operator>(const Point& other)  const { return (width > other.x)       && (height > other.y); }
		inline bool operator>(int value)           const { return (width > value)         && (height > value); }
		inline bool operator>=(const Size& other)  const { return (width >= other.width)   && (height >= other.height); }
		inline bool operator>=(const Point& other) const { return (width >= other.x)       && (height >= other.y); }
		inline bool operator>=(int value)          const { return (width >= value)         && (height >= value); }

		inline Size operator+(const Size& other)   const { return Size(width + other.width,   height + other.height); }
		inline Size operator+(const Point& other)  const { return Size(width + other.x,       height + other.y); }
		inline Size operator+(const int value)     const { return Size(width + value,         height + value); }
		inline Size operator-(const Size& other)   const { return Size(width - other.width,   height - other.height); }
		inline Size operator-(const Point& other)  const { return Size(width - other.x,       height - other.y); }
		inline Size operator-(const int value)     const { return Size(width - value,         height - value); }
		inline Size operator*(const Size& other)   const { return Size(width * other.width,   height * other.height); }
		inline Size operator*(const Point& other)  const { return Size(width * other.x,       height * other.y); }
		inline Size operator*(const int value)     const { return Size(width * value,         height * value); }
		inline Size operator/(const Size& other)   const { return Size(width / other.width,   height / other.height); }
		inline Size operator/(const Point& other)  const { return Size(width / other.x,       height / other.y); }
		inline Size operator/(const int value)     const { return Size(width / value,         height / value); }

		inline Size& operator-() { width = -width; height = -height; return *this; }
		inline Size& operator!() { width = !width; height = !height; return *this; }
		inline Size& operator~() { width = ~width; height = ~height; return *this; }
		inline Size& operator++()   {                    ++width; ++height; return *this; }
		inline Size operator++(int) { Size temp = *this; ++width; ++height; return temp; }
		inline Size& operator--()   {                    --width; --height; return *this; }
		inline Size operator--(int) { Size temp = *this; --width; --height; return temp; }

		inline Size& operator=(const Size& other)   { width = other.width;    height = other.height;  return *this; }
		inline Size& operator=(const Point& other)  { width = other.x;        height = other.y;       return *this; }
		inline Size& operator=(int value)           { width = value;          height = value;         return *this; }
		inline Size& operator+=(const Size& other)  { width += other.width;   height += other.height; return *this; }
		inline Size& operator+=(const Point& other) { width += other.x;       height += other.y;      return *this; }
		inline Size& operator+=(int value)          { width += value;         height += value;        return *this; }
		inline Size& operator-=(const Size& other)  { width -= other.width;   height -= other.height; return *this; }
		inline Size& operator-=(const Point& other) { width -= other.x;       height -= other.y;      return *this; }
		inline Size& operator-=(int value)          { width -= value;         height -= value;        return *this; }
		inline Size& operator*=(const Size& other)  { width *= other.width;   height *= other.height; return *this; }
		inline Size& operator*=(const Point& other) { width *= other.x;       height *= other.y;      return *this; }
		inline Size& operator*=(int value)          { width *= value;         height *= value;        return *this; }
		inline Size& operator/=(const Size& other)  { width /= other.width;   height /= other.height; return *this; }
		inline Size& operator/=(const Point& other) { width /= other.x;       height /= other.y;      return *this; }
		inline Size& operator/=(int value)          { width /= value;         height /= value;        return *this; }
	};


	inline Point::Point(const Size& other) throw() : x(other.width), y(other.height) {}
	inline bool Point::operator==(const Point& other)   const throw() { return x == other.x && y == other.y; }
	inline bool Point::operator==(const Size& other)    const throw() { return x == other.width && y == other.height; }
	inline bool Point::operator==(int value)            const throw() { return x == value && y == value; }
	inline bool Point::operator!=(const Point& other)   const throw() { return !(*this == other); }
	inline bool Point::operator!=(const Size& other)    const throw() { return !(*this == other); }
	inline bool Point::operator!=(int value)            const throw() { return !(*this == value); }
	inline bool Point::operator<(const Point& other)    const throw() { return (x < other.x) && (y < other.y); }
	inline bool Point::operator<(const Size& other)     const throw() { return (x < other.width) && (y < other.height); }
	inline bool Point::operator<(int value)             const throw() { return (x < value) && (y < value); }
	inline bool Point::operator<=(const Point& other)   const throw() { return (x <= other.x) && (y <= other.y); }
	inline bool Point::operator<=(const Size& other)    const throw() { return (x <= other.width) && (y <= other.height); }
	inline bool Point::operator<=(int value)            const throw() { return (x <= value) && (y <= value); }
	inline bool Point::operator>(const Point& other)    const throw() { return (x > other.x) && (y > other.y); }
	inline bool Point::operator>(const Size& other)     const throw() { return (x > other.width) && (y > other.height); }
	inline bool Point::operator>(int value)             const throw() { return (x > value) && (y > value); }
	inline bool Point::operator>=(const Point& other)   const throw() { return (x >= other.x) && (y >= other.y); }
	inline bool Point::operator>=(const Size& other)    const throw() { return (x >= other.width) && (y >= other.height); }
	inline bool Point::operator>=(int value)            const throw() { return (x >= value) && (y >= value); }
	inline Point Point::operator+(const Point& other)   const throw() { return Point(x + other.x, y + other.y); }
	inline Point Point::operator+(const Size& other)    const throw() { return Point(x + other.width, y + other.height); }
	inline Point Point::operator+(const int value)      const throw() { return Point(x + value, y + value); }
	inline Point Point::operator-(const Point& other)   const throw() { return Point(x - other.x, y - other.y); }
	inline Point Point::operator-(const Size& other)    const throw() { return Point(x - other.width, y - other.height); }	
	inline Point Point::operator-(const int value)      const throw() { return Point(x - value, y - value); }
	inline Point Point::operator*(const Point& other)   const throw() { return Point(x * other.x, y * other.y); }
	inline Point Point::operator*(const Size& other)    const throw() { return Point(x * other.width, y * other.height); }
	inline Point Point::operator*(const int value)      const throw() { return Point(x * value, y * value); }
	inline Point Point::operator/(const Point& other)   const throw() { return Point(x / other.x, y / other.y); }
	inline Point Point::operator/(const Size& other)    const throw() { return Point(x / other.width, y / other.height); }
	inline Point Point::operator/(const int value)      const throw() { return Point(x / value, y / value); }
	inline Point& Point::operator=(const Point& other)  throw() { x = other.x; y = other.y; return *this; }
	inline Point& Point::operator=(const Size& other)   throw() { x = other.width; y = other.height; return *this; }
	inline Point& Point::operator=(int value)           throw() { x = value; y = value; return *this; }
	inline Point& Point::operator+=(const Point& other) throw() { x += other.x; y += other.y; return *this; }
	inline Point& Point::operator+=(const Size& other)  throw() { x += other.width; y += other.height; return *this; }
	inline Point& Point::operator+=(int value)          throw() { x += value; y += value; return *this; }
	inline Point& Point::operator-=(const Point& other) throw() { x -= other.x; y -= other.y; return *this; }
	inline Point& Point::operator-=(const Size& other)  throw() { x -= other.width; y -= other.height; return *this; }
	inline Point& Point::operator-=(int value)          throw() { x -= value; y -= value; return *this; }
	inline Point& Point::operator*=(const Point& other) throw() { x *= other.x; y *= other.y; return *this; }
	inline Point& Point::operator*=(const Size& other)  throw() { x *= other.width; y *= other.height; return *this; }
	inline Point& Point::operator*=(int value)          throw() { x *= value; y *= value; return *this; }
	inline Point& Point::operator/=(const Point& other) throw() { x /= other.x; y /= other.y; return *this; }
	inline Point& Point::operator/=(const Size& other)  throw() { x /= other.width; y /= other.height; return *this; }
	inline Point& Point::operator/=(int value)          throw() { x /= value; y /= value; return *this; }
} // namespace tlibccp
