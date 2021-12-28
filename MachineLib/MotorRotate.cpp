/**
 * \file MotorRotate.cpp
 *
 * \author Elizabeth Lipin
 */
#include "pch.h"
#include "MotorRotate.h"
#include "Motor.h"
/**constructor*/
CMotorRotate::CMotorRotate()
{
}

/**update
   \param elapsed time since last update*/
void CMotorRotate::Update(double elapsed)
{
	if (mMotor->IsGo() && !mMotor->HasStopped())
	{
		auto rotation = GetRotation();
		rotation += elapsed * mSpeed;
		SetRotation(rotation);
		mSource.Rotate();
	}
	
}
/**resets*/
void CMotorRotate::Reset()
{
	SetRotation(0);
}
