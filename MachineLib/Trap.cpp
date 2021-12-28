/**
 * \file Trap.cpp
 *
 * \author Elizabeth Lipin
 */
#include "pch.h"
#include "Trap.h"

/**contructor*/
CTrap::CTrap()
{
}
/**destructor*/
CTrap::~CTrap()
{
}
/**update
\param elapsed time since last update*/
void CTrap::Update(double elapsed)
{
	int outCount = 0;
	for (auto pin : mPins)
	{
		if (pin->GetOut())
		{
			outCount++;
		}
	}
	if (outCount == mPins.size())
	{
		Drop();
	}
}

