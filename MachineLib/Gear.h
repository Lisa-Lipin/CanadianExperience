/**
 * \file Gear.h
 *
 * \author Elizabeth Lipin
 *
 * Class for the Gears
 */
#pragma once
#include "Component.h"
#include "Sink.h"
#include "Source.h"
/**
 * Class for the Gears
 */
class CGear :
    public CComponent
{
public:
    /**constructor
    \param radius of gear
    \param teeth gear has*/
    CGear(int radius, int teeth);
    /**destructor*/
    ~CGear();
    /// Copy constructor (disabled)
    CGear(const CGear&) = delete;
    /** \brief Default constructor disabled */
    CGear() = delete;
    /// Assignment operator (disabled)
    void operator=(const CGear&) = delete;
    /**update
    \param elapsed time since last update*/
    virtual void Update(double elapsed) override;
    /*resets*/
    virtual void Reset() override;
    /**get the sink
    \return sink*/
    CSink* GetSink() { return &mSink; }
    /**set rotation and send to source
    \param rotation to rotate by*/
    virtual void SetRotation(double rotation) override;
    /**get the radius
    \return radius*/
    int GetRadius() { return mRadius; }
    /**get number of teeth
    \return num teeth*/
    int GetTeeth() { return mNumTeeth; }
    /**set driving gears and calc speeds
    \param gear2 gear to drive*/
    void Drive(std::shared_ptr<CGear> gear2);
    /// Get a pointer to the source object
    /// \return Pointer to CRotationSource object
    CSource* GetSource() { return &mSource; }
    /**Set Adjust
    \param adjust to set*/
    void SetAdjust(double adjust) { mAdjust = adjust; }
    /**set speed
    \param speed to set*/
    void SetSpeed(double speed) { mSpeed = speed; }
private:
    /// sink
    CSink mSink;
    /// Rotation source for this component
    CSource mSource;
    /// radius
    int mRadius = 0;
    /// number of teeth
    int mNumTeeth = 0;
    /// adjustment
    double mAdjust = 0;
    /// speed
    double mSpeed = 1;

};

