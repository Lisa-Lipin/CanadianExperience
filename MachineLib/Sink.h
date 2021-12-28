/**
 * \file Sink.h
 *
 * \author Elizabeth Lipin
 *
 * Class for the ink
 */
#pragma once
#include "Component.h"
/**
 * Class for the ink
 */
class CSink
{
public:
    /**constructor*/
    CSink();
    /**destructor*/
    ~CSink();
    /// Copy constructor (disabled)
    CSink(const CSink&) = delete;

    /// Assignment operator (disabled)
    void operator=(const CSink&) = delete;
    /**set component
\param component to set*/
    void SetComponent(CComponent* component);
    /**get component
\return component*/
    CComponent* GetComponent() { return mComponent;}
    /**rotate*/
    void Rotate();
    /**set speed
\param speed to set*/
    void SetSpeed(double speed) { mSpeed = speed; }
    /**set speedtime
\param elapsed time to multply by*/
    void SetSpeedTime(double elapsed) { mSpeedTime = mSpeed * elapsed; }
    /**get speed
\return speed*/
    double GetSpeed() { return mSpeed; }

private:
    /// component
    CComponent* mComponent = nullptr;
    /// speed
    double mSpeed = 1;
    /// speed times elapsed
    double mSpeedTime = 0;
};

