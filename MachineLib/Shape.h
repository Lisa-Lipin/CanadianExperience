/**
 * \file Shape.h
 *
 * \author Elizabeth Lipin
 *
 * Class for the shape
 */
#pragma once
#include "Component.h"
#include "Sink.h"
#include "Source.h"
/**
 * Class for the shape
 */
class CShape :
    public CComponent
{
public:
    /*constructor*/
    CShape();
    /*destructor*/
    ~CShape();
    /// Copy constructor (disabled)
    CShape(const CShape&) = delete;

    /// Assignment operator (disabled)
    void operator=(const CShape&) = delete;
    /**update and
\param elapsed time since last update*/
    virtual void Update(double elapsed) override;
    /**reset*/
    virtual void Reset() override;
    /**get sink
    \return sink*/
    CSink* GetSink() { return &mSink; }
    /**set rotation
\param rotation to set*/
    virtual void SetRotation(double rotation) override;
    /**get speed 
    \return speed*/
    double GetSpeed() { return GetSink()->GetSpeed(); }
    /**setspeed
    \param speed to set*/
    void SetSpeed(double speed) { mSpeed = speed; }
private:
    /// sink
    CSink mSink;
    /// Rotation source for this component
    CSource mSource;
    /// speed
    double mSpeed = 1;
};

