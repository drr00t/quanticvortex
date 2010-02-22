// Copyright (C) 2007-2009 Matthias Specht
// For conditions of distribution and use, see copyright notice in license.txt

#ifndef __S_VALUE_H_INCLUDED__
#define __S_VALUE_H_INCLUDED__

namespace irr
{
namespace io
{

//! Class for holding a 2 dimensional value.
template<class T>
class SValue2D
{
public:
	inline SValue2D() : X(0), Y(0) {};
	inline SValue2D( const core::dimension2d<T>& d) : X(d.Width), Y(d.Height) {};
	inline SValue2D( const core::vector2d<T>& v) : X(v.X), Y(v.Y) {};
	inline SValue2D(T x, T y) : X(x), Y(y) {};
	SValue2D( const core::stringc& str ) : X(0), Y(0)
	{
		s32 sep = str.findFirst('x');
		if( sep != -1)
		{
			X = (T)atof( str.subString(0, sep).c_str() );
			Y = (T)atof( str.subString(sep+1, str.size()-sep-1).c_str() );
		}
	}

	//! First value
	T X;
	//! Second value
	T Y;

	//! Returns the 2 values as an Irrlicht dimension
	inline core::dimension2d<T> toDimension() const
	{
		return core::dimension2d<T>(X,Y);
	}
	//! Returns the 2 values as an Irrlicht 2D-Vector
	inline core::vector2d<T> toVector() const
	{
		return core::vector2d<T>(X,Y);
	}
	//! Returns the 2 values a string
	inline core::stringc toString() const
	{
		return core::stringc(X) + core::stringc("x") + core::stringc(Y);
	}
};

//! Class for holding a 3 dimensional value.
template<class T>
class SValue3D
{
public:
	inline SValue3D() : X(0), Y(0), Z(0) {};
	inline SValue3D( const video::SColor& c) : X(c.getRed()), Y(c.getGreen()), Z(c.getBlue()) {};
	inline SValue3D( const core::vector3d<T>& v) : X(v.X), Y(v.Y), Z(v.Z) {};
	inline SValue3D(T x, T y, T z) : X(x), Y(y), Z(z) {};
	SValue3D( const core::stringc& str ) : X(0), Y(0), Z(0)
	{
		s32 sep = str.findFirst('x');
		if( sep == -1)
			return;

		s32 sep2 = str.findNext('x', sep+1);
		if( sep2 == -1)
			return;

		X = (T)atof( str.subString(0, sep).c_str() );
		Y = (T)atof( str.subString(sep+1, sep2-1-sep ).c_str() );
		Z = (T)atof( str.subString(sep2+1, str.size()-1-sep2 ).c_str() );
	}

	//! First value
	T X;
	//! Second value
	T Y;
	//! Third value
	T Z;

	//! Returns the 3 values as an Irrlicht color
	inline video::SColor toSColor() const
	{
		return video::SColor(X,Y,Z);
	}
	//! Returns the 3 values as an Irrlicht color
	inline video::SColorf toSColorf() const
	{
		return video::SColorf(X,Y,Z);
	}
	//! Returns the 3 values as an Irrlicht 3D-Vector
	inline core::vector3d<T> toVector() const
	{
		return core::vector3d<T>(X,Y,Z);
	}
	//! Returns the 3 values as a string
	inline core::stringc toString() const
	{
		return core::stringc(X) + core::stringc("x") + core::stringc(Y) + core::stringc("x") + core::stringc(Z);
	}
};

//! Class for holding a 4 dimensional value.
template<class T>
class SValue4D
{
public:
	inline SValue4D() : X1(0), X2(0), Y1(0), Y2(0) {};
	inline SValue4D( const video::SColor& c) : X1(c.getAlpha()), Y1(c.getRed()), X2(c.getGreen()), Y2(c.getBlue()) {};
	inline SValue4D( const core::rect<T>& r) : X1(r.UpperLeftCorner.X), Y1(r.UpperLeftCorner.Y), X2(r.LowerRightCorner.X), Y2(r.LowerRightCorner.Y) {};
	inline SValue4D(T x1, T y1, T x2, T y2) : X1(x1), Y1(y1), X2(x2), Y2(y2) {};
	inline SValue4D( const core::stringc& str ) : X1(0), X2(0), Y1(0), Y2(0)
	{
		s32 sep = str.findFirst('x');
		if( sep == -1)
			return;

		s32 sep2 = str.findNext('x', sep+1);
		if( sep2 == -1)
			return;

		s32 sep3 = str.findNext('x', sep2+1);
		if( sep3 == -1)
			return;

		X1 = (T)atof( str.subString(0, sep).c_str() );
		Y1 = (T)atof( str.subString(sep+1, sep2-1-sep ).c_str() );
		X2 = (T)atof( str.subString(sep2+1, sep3-1-sep2 ).c_str() );
		Y2 = (T)atof( str.subString(sep3+1, str.size()-1-sep3).c_str() );
	}

	//! First value
	T X1;
	//! Second value
	T Y1;
	//! Third value
	T X2;
	//! Fourth value
	T Y2;

	//! Returns the 4 values as an Irrlicht color
	inline video::SColor toSColor() const
	{
		return video::SColor(X1,Y1,X2,Y2);
	}
	//! Returns the 4 values as an Irrlicht color
	inline video::SColorf toScolorf() const
	{
		return video::SColorf(X1,Y1,X2,Y2);
	}
	//! Returns the 4 values as an Irrlicht rectangle
	inline core::rect<s32> toRect() const
	{
		return core::rect<T>(X1,Y1,X2,Y2);
	}
	//! Returns the 4 values as a string
	inline core::stringc toString() const
	{
		return core::stringc(X1) + core::stringc("x") + core::stringc(Y1) + core::stringc("x") + core::stringc(X2) + core::stringc("x") + core::stringc(Y2);
	}
};

typedef SValue2D<s32> SValue2Di;
typedef SValue2D<f32> SValue2Df;
typedef SValue3D<s32> SValue3Di;
typedef SValue3D<f32> SValue3Df;
typedef SValue4D<s32> SValue4Di;
typedef SValue4D<f32> SValue4Df;

} // end namespace io
} // end namespace irr

#endif
