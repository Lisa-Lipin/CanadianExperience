/**
 * \file TrapCage.cpp
 *
 * \author Elizabeth Lipin
 */
#include "pch.h"
#include "TrapCage.h"

/// The rate the trap falls when it is sprung
/// in pixels per second. 
const double TrapFallRate = 200;

/// The limit of how far a pin can be moved 
/// in the X direction in pixels. At this 
/// limit the winch is stopped.
const double PinXLimit = 65;

/// How far out a pin must be removed to release
/// the trap in pixels. 
const double PinRemoved = 19;
/**contructor*/
CTrapCage::CTrapCage()
{
}
/**destructor*/
CTrapCage::~CTrapCage()
{
}
/**calc position of trap*/
void CTrapCage::CalcPosition()
{
	SetLocation((int)GetX(), (int)GetY() + mFall);
}

/**update
\param elapsed time since last update*/
void CTrapCage::Update(double elapsed)
{
	if (mDrop) 
	{
		// We are moving
		mTime += elapsed;
		if (GetY() < mFinalPosition.Y())
		{
			mFall = TrapFallRate * elapsed;
			CalcPosition();
			
		}
		else
		{
			SetLocation((int)mFinalPosition.X(), (int)mFinalPosition.Y());
			mDrop = false;
		}
	}
}
/**resets*/
void CTrapCage::Reset()
{
	mTime = 0;
	SetLocation((int)mInitialPosition.X(), (int)mInitialPosition.Y());
	mDrop = false;
}
/**set initial location
\param x x coord
\param y y coord*/
void CTrapCage::SetInitialPosition(int x, int y)
{
	mInitialPosition.Set(x, y);
	SetLocation(x, y);
}
