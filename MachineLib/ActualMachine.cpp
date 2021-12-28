/**
 * \file ActualMachine.cpp
 *
 * \author Elizabeth Lipin
 */
#include "pch.h"
#include "ActualMachine.h"
#include "Machine1Factory.h"
#include "Machine2Factory.h"
/// <summary>
/// the frame rate
/// </summary>
const double FrameRate = 30;
/**constructor*/
CActualMachine::CActualMachine()
{
	SetMachineNumber(1);
	
}
/**setlocation
\param x x coord
\param y y coord*/
void CActualMachine::SetLocation(int x, int y)
{
	mX = x;
	mY = y;
}
/**draw the machine
\param graphics  to draw with*/
void CActualMachine::DrawMachine(Gdiplus::Graphics* graphics)
{
	mWorkingMachine->Draw(graphics, mX, mY);
}

/**Set the machine frame
\param frame to set*/
void CActualMachine::SetMachineFrame(int frame)
{
	if (mInitialFrame == 0)
	{
		if (frame < mCurrentFrame)
		{
			mCurrentFrame = 0;
			mWorkingMachine->Reset();
		}

		while (mCurrentFrame < frame) {
			mCurrentFrame++;
			mWorkingMachine->Update(1.0 / FrameRate);
		}
	}
	else
	{
		if (frame < mInitialFrame)
		{
			mCurrentFrame = 0;
			mWorkingMachine->Reset();
		}
		else if (frame < mCurrentFrame && frame >= mInitialFrame)
		{
			mCurrentFrame = mInitialFrame;
			mWorkingMachine->Reset();
		}

		while (mCurrentFrame + mInitialFrame < frame ) {
			mCurrentFrame++;
			mWorkingMachine->Update(1.0 / FrameRate);
		}
	}
	
}
/**set machine number and create working machines 
\param machine number*/
void CActualMachine::SetMachineNumber(int machine)
{
	mMachine = machine;
	if (machine == 1)
	{
		CMachine1Factory factory;
		std::shared_ptr<CMachine> machine1 = factory.CreateMachine();
		mWorkingMachine = std::dynamic_pointer_cast<CWorkingMachine> (machine1);
		mWorkingMachine->SetActualMachine(this);
		mInitialFrame = mWorkingMachine->GetInitialFrame();
	}
	else if (machine == 2)
	{
		CMachine2Factory factory;
		std::shared_ptr<CMachine> machine = factory.CreateMachine();
		mWorkingMachine = std::dynamic_pointer_cast<CWorkingMachine> (machine);
		mWorkingMachine->SetActualMachine(this);
		mInitialFrame = mWorkingMachine->GetInitialFrame();
	}
	
}

/**Get machine number
\return number*/
int CActualMachine::GetMachineNumber()
{
	return mMachine;
}
/**set working machine 
\param machine to set*/
void CActualMachine::SetWorkingMachine(std::shared_ptr<CWorkingMachine> machine)
{
	mWorkingMachine = machine;
}
