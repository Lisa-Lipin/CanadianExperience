/**
 * \file MachineDrawable.cpp
 *
 * \author Elizabeth Lipin
 */
#include "pch.h"
#include "MachineDrawable.h"
#include <MachineDlg.h>


/**constructor
\param name name for drawable*/
CMachineDrawable::CMachineDrawable(const std::wstring& name):CDrawable(name)
{
}
/**destructor*/
CMachineDrawable::~CMachineDrawable()
{
}
/**draw
\param graphics to draw with*/
void CMachineDrawable::Draw(Gdiplus::Graphics* graphics)
{
    float scale = 0.35f;

    auto save = graphics->Save();
    graphics->TranslateTransform((float)GetPosition().X,
        (float)GetPosition().Y);
    graphics->ScaleTransform(scale, scale);
    mMachine->DrawMachine(graphics);
    graphics->Restore(save);
}

/**hit test
\param pos to test
\return whether hit*/
bool CMachineDrawable::HitTest(Gdiplus::Point pos)
{
	int machineX = pos.X - GetPosition().X;
	int machineY = pos.Y - GetPosition().Y;
    if (machineX < 0 || machineY < 0 || machineX >= mWidth || machineY >= mHeight)
    {
        // We are outside the machine
        return false;
    }
	return true;
}
/**set the size for hit test
\param width width for hit
\param height height for hit*/
void CMachineDrawable::SetSize(int width, int height)
{
    mWidth = width;
    mHeight = height;
}

/**call machine dlg to change machine number*/
void CMachineDrawable::SetNewNum()
{
    CMachineDlg dlg(mMachine);
    if (dlg.DoModal() == IDOK)
    {
        // A machine has been selected
    }
}
