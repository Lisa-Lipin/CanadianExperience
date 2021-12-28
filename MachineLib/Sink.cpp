/**
 * \file Sink.cpp
 *
 * \author Elizabeth Lipin
 */
#include "pch.h"
#include "Sink.h"

/**constructor*/
CSink::CSink()
{
}
/**destructor*/
CSink::~CSink()
{
}
/**set component
\param component to set*/
void CSink::SetComponent(CComponent* component)
{
	mComponent = component;
}

/**rotate*/
void CSink::Rotate()
{
	GetComponent()->SetRotation(mSpeedTime + GetComponent()->GetRotation());
	
}
