/**
 * \file Motor.cpp
 *
 * \author Elizabeth Lipin
 */
#include "pch.h"
#include "Motor.h"
#include "MotorRotate.h"
#include "Winch.h"
/**contructor*/
CMotor::CMotor()
{
}


/**reset motor*/
void CMotor::Reset()
{
	SetRotation(0);
	mGo = false;
	mHasStopped = false;
}
/**start/stop motor and tell winches they can pull
\param go whether can go*/
void CMotor::SetGo(bool go)
{
	mGo = go;
	for (auto winch : mWinches)
	{
		winch->SetPull(go);
	}
}
