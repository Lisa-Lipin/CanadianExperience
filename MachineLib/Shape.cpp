/**
 * \file Shape.cpp
 *
 * \author Elizabeth Lipin
 */
#include "pch.h"
#include "Shape.h"

/**constructor*/
CShape::CShape()
{
	
	mSink.SetComponent(this);
}
/**destructor*/
CShape::~CShape()
{
}


/**update
\param elapsed time since last update*/
void CShape::Update(double elapsed)
{
	mSink.SetSpeedTime(elapsed);
}
/**resets*/
void CShape::Reset()
{
	SetRotation(0);
}
/**set rotation
\param rotation to set*/
void CShape::SetRotation(double rotation)
{
	CComponent::SetRotation(rotation);
	mSource.Rotate();
}

