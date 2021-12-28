/**
 * \file Component.cpp
 *
 * \author Elizabeth Lipin
 */
#include "pch.h"
#include "Component.h"
/**consructor*/
CComponent::CComponent()
{
}
/**detructor*/
CComponent::~CComponent()
{
}
/**draws the component
\param graphics to draw with
\param x coord
\param y coord*/
void CComponent::Draw(Gdiplus::Graphics* graphics, int x, int y)
{
	DrawPolygon(graphics, mPosition.X + x, mPosition.Y + y);
}

/**sets the location
\param x coord
\param y coord*/
void CComponent::SetLocation(int x, int y)
{
	mPosition.X = x;
	mPosition.Y = y;
}

