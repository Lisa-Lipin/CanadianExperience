/**
 * \file WorkingMachine.cpp
 *
 * \author Elizabeth Lipin
 */
#include "pch.h"
#include "WorkingMachine.h"
#include "ActualMachine.h"

/**constructor
\param num to set*/
CWorkingMachine::CWorkingMachine(int num)
{
	SetMachineNumber(num);
}
/**destructor*/
CWorkingMachine::~CWorkingMachine()
{

}

/**add component
\param component to add*/
void CWorkingMachine::AddComponent(std::shared_ptr<CComponent> component)
{
	mComponentsInOrder.push_back(component);
}
/**draws the component
\param graphics to draw with
\param x coord
\param y coord*/
void CWorkingMachine::Draw(Gdiplus::Graphics* graphics, int x, int y)
{
	for (auto component : mComponentsInOrder)
	{
		component->Draw(graphics, x, y);
	}
}
/**set machine number
\param machine to set*/
void CWorkingMachine::SetMachineNumber(int machine)
{
	mMachine = machine;
}
/**update all components
\param elapsed time since last update*/
void CWorkingMachine::Update(double elapsed)
{
	for (auto component : mComponentsInOrder)
	{
		component->Update(elapsed);
	}
}
/**reset all components*/
void CWorkingMachine::Reset()
{
	for (auto component : mComponentsInOrder)
	{
		component->Reset();
	}
}
