/**
 * \file Mouse.cpp
 *
 * \author Elizabeth Lipin
 */
#include "pch.h"
#include "Mouse.h"
#include "Polygon.h"
#include "Motor.h"
/// pixels until scurry
const int TotalPixelsToScurry = 20;
/**contructor*/
CMouse::CMouse()
{
	SetRotation(0.01);
}

/**calc position and tell when scurry*/
void CMouse::CalcPosition()
{
	//// Compute position of the mouse
	double t = mTime / mDuration;
	auto position = mInitialPosition * (1 - t) + mFinalPosition * t;
	mPixelsTillScurry -= GetX() - position.X();
	SetLocation((int)position.X(), (int)position.Y());
	if (mPixelsTillScurry <= 0)
	{
		mPixelsTillScurry = TotalPixelsToScurry;
		Scurry();
	}
	
}

/**change rotataion*/
void CMouse::Scurry()
{
	SetRotation(-GetRotation());
}

/**update and tell motor to start
\param elapsed time since last update*/
void CMouse::Update(double elapsed)
{
	// We are moving
	mTime += elapsed;
	if (mTime < mDuration)
	{
		CalcPosition();
	}
	else
	{
		for (auto motor : mMotors)
		{
			motor->SetGo(true);
		}
		
		// We are past the end
		SetLocation((int)mFinalPosition.X(), (int)mFinalPosition.Y());
	}
}

/**resets*/
void CMouse::Reset()
{
	for (auto motor : mMotors)
	{
		motor->SetGo(false);
	}
	mTime = 0;
	SetLocation((int)mInitialPosition.X(), (int)mInitialPosition.Y());
}

/**set initial location
\param x x coord
\param y y coord*/
void CMouse::SetInitialPosition(int x, int y)
{
	mInitialPosition.Set(x, y);
	SetLocation(x, y);
}
