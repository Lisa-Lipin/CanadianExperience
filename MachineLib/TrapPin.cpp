/**
 * \file TrapPin.cpp
 *
 * \author Elizabeth Lipin
 */
#include "pch.h"
#include "TrapPin.h"
#include "Motor.h"
#include "Winch.h"

/// The limit of how far a pin can be moved 
/// in the X direction in pixels. At this 
/// limit the winch is stopped.
const double PinXLimit = 65;

/// How far out a pin must be removed to release
/// the trap in pixels. 
const double PinRemoved = 19;

/**constructor*/
CTrapPin::CTrapPin()
{
}

/**destructor*/
CTrapPin::~CTrapPin()
{
}

/**calculatees the next poition of the pin*/
void CTrapPin::CalcPosition()
{
	// Distance in the X and Y directions
	double dx = mInitialPosition.X() - (double)GetX() ;
	double dy = mInitialPosition.Y() - (double)GetY() ;

	double distance = sqrt(dx * dx + dy * dy);

	if (distance >= PinRemoved)
	{
		mOut = true;
	}
	if (mWinch->GetX() < GetX())
	{
		SetLocation((int)GetX() + mPull* abs(mWinch->GetRotation()), (int)GetY());
	}
	else if (mWinch->GetX() > GetX())
	{
		SetLocation((int)GetX() - mPull * (abs(mWinch->GetRotation())/abs(mWinch->GetSpeed())/10), (int)GetY());
	}
	
}
/** updates the pin
 \param elapsed the time since last update*/
void CTrapPin::Update(double elapsed)
{
	// We are moving
	mTime += elapsed;
	// Distance in the X and Y directions
	double dx = mInitialPosition.X() - (double)GetX();
	double dy = mInitialPosition.Y() - (double)GetY();

	double distance = sqrt(dx * dx + dy * dy);
	if (distance < PinXLimit)
	{
		CalcPosition();

	}
	else
	{
		SetLocation((int)mFinalPosition.X(), (int)mFinalPosition.Y());
		mWinch->SetPull(false);
		mMotor->SetGo(false);
		mMotor->SetStopped(true);
	}
}
/**reset the pin*/
void CTrapPin::Reset()
{
	mTime = 0;
	SetLocation((int)mInitialPosition.X(), (int)mInitialPosition.Y());
	mOut = false;
}

/**set initial position of pin
\param x x-coord
\param y y-coord*/
void CTrapPin::SetInitialPosition(int x, int y)
{
	mInitialPosition.Set(x, y);
	SetLocation(x, y);
}
