/**
 * \file Gear.cpp
 *
 * \author Elizabeth Lipin
 */
#include "pch.h"
#include "Gear.h"
#include "Const.h"

const double ToothDepth = 5;     ///< Depth of a tooth in pixels
const double ToothWidth = 0.33;  ///< Width of a tooth at the top as fraction of tooth pitch
const double ToothSlope = 0.1;   ///< Fraction of pitch where the tooth slopes up or down

/**constructor
\param radius of gear
\param teeth gear has*/
CGear::CGear(int radius, int teeth)
{
	mRadius = radius;
	mNumTeeth = teeth;
	mSink.SetComponent(this);
    // Where the tooth starts in the arc
    double toothStart = 1.0 - ToothWidth - ToothSlope * 2;
    double innerRadius = mRadius - ToothDepth;

    for (int t = 0; t < mNumTeeth; t++)
    {
        double angle1 = double(t) / double(mNumTeeth) * CConst::PI2;
        double angle2 = double(t + toothStart) / double(mNumTeeth) * CConst::PI2;
        double angle3 = double(t + toothStart + ToothSlope) / double(mNumTeeth) * CConst::PI2;
        double angle4 = double(t + toothStart + ToothSlope + ToothWidth) / double(mNumTeeth) * CConst::PI2;
        double angle5 = double(t + toothStart + ToothSlope * 2 + ToothWidth) / double(mNumTeeth) * CConst::PI2;

        AddPoint(innerRadius * cos(angle1), innerRadius * sin(angle1));
        AddPoint(innerRadius * cos(angle2), innerRadius * sin(angle2));
        AddPoint(mRadius * cos(angle3), mRadius * sin(angle3));
        AddPoint(mRadius * cos(angle4), mRadius * sin(angle4));
        AddPoint(innerRadius * cos(angle5), innerRadius * sin(angle5));
    }
}
/**destructor*/
CGear::~CGear()
{
}

/**update 
\param elapsed time since last update*/
void CGear::Update(double elapsed)
{
    mSink.SetSpeedTime(elapsed);
}

/**resets*/
void CGear::Reset()
{
	SetRotation(0);
}

/**set rotation and send to source
\param rotation to rotate by*/
void CGear::SetRotation(double rotation)
{
	CComponent::SetRotation(rotation - mAdjust);
	mSource.Rotate();
}

/**set driving gears and calc speeds
\param gear2 gear to drive*/
void CGear::Drive(std::shared_ptr<CGear> gear2)
{
	this->GetSource()->AddSink(gear2->GetSink());
	gear2->GetSink()->SetSpeed(-(double)this->GetTeeth() / (double)gear2->GetTeeth()*mSpeed);
    gear2->SetSpeed(gear2->GetSink()->GetSpeed());
}
