/**
 * \file Winch.cpp
 *
 * \author Elizabeth Lipin
 */
#include "pch.h"
#include "Winch.h"
#include "Const.h"
#include "Trap.h"
#include "TrapPin.h"
#include "Motor.h"
/**constructor*/
CWinch::CWinch()
{
	mSink.SetComponent(this);
	SetRotation(0);
}
/**detructor*/
CWinch::~CWinch()
{
}
/**draws the component
\param graphics to draw with
\param x coord
\param y coord*/
void CWinch::Draw(Gdiplus::Graphics* graphics, int x, int y)
{
	Gdiplus::Pen pen(Gdiplus::Color(142, 80, 60), 4);
	if (!mMotor->HasStopped())
	{
		if (!mPull)
		{
			SetTangent(x, y);
		}
		else
		{
			mCurrentLength -= -abs(GetRotation()) * (mRadius - 3.00);
		}
	}
	
	auto saveSM = graphics->GetSmoothingMode();
	graphics->SetSmoothingMode(Gdiplus::SmoothingMode::SmoothingModeHighQuality);
	// Draw a partial line
	// First, how far is it from the tangent point to the cable end?
	double d = mTangent.Distance(mCableEnd);

	// What percentage of the line is still outstanding?
	double t = mCurrentLength / d;

	// Draw just that much
	auto drawEndpoint = mTangent + (mCableEnd - mTangent) * t;
	
	graphics->DrawLine(&pen, mTangent.X()+x, mTangent.Y()+y,  -(int)drawEndpoint.X()+x,  (int)drawEndpoint.Y()+y);

	graphics->SetSmoothingMode(saveSM);
	CComponent::Draw(graphics, x, y);
}
/**update
\param elapsed time since last update*/
void CWinch::Update(double elapsed)
{
	mSink.SetSpeedTime(elapsed);
	PullPin();
}
/**resets*/
void CWinch::Reset()
{
	SetRotation(0);
	mPull = false;
	mCurrentLength = mTangent.Distance(mCableEnd);
}
/**set rotation
\param rotation to set*/
void CWinch::SetRotation(double rotation)
{
	CComponent::SetRotation(rotation);
	mSource.Rotate();
	
}
/**pull pin*/
void CWinch::PullPin()
{
	if (mPull) {
		for (auto pin : mPins)
		{
			pin->SetPull(mTangent.Distance(mCableEnd) - mCurrentLength);
		}
	}
	
}
/**set end location
\param x x coord
\param y y coord*/
void CWinch::SetCableEnd(int x, int y)
{
	mCableEnd.Set(x, y);
}
/**set tangent position
\param x x coord
\param y y coord*/
void CWinch::SetTangent(int x, int y)
{
	// Distance in the X and Y directions
	double dx = mCableEnd.X() - ((double)GetX() );
	double dy = mCableEnd.Y() - ((double)GetY() );

	double distance = sqrt(dx * dx + dy * dy);
	double theta = atan2(dy,dx);
	double phi = acos((mRadius - 3.00) / distance);
	double beta = theta - phi;
	mTangent.Set(GetX()  + (mRadius - 3.00) * cos(beta), GetY()  + (mRadius - 3.00) * sin(beta));
	mCurrentLength = mTangent.Distance(mCableEnd);
}

