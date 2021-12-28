/**
 * \file Mouse.h
 *
 * \author Elizabeth Lipin
 *
 * Class for the mouse
 */
#pragma once
#include "Component.h"
#include "Vector.h"
class CMotor;
/**
*Class for the mouse
*/
class CMouse :
    public CComponent
{
public:
    /// Constructor
    CMouse();

    /// Destructor
    virtual ~CMouse() {}

    /// Copy constructor/disabled
    CMouse(const CMouse&) = delete;

    /// Assignment operator/disabled
    void operator=(const CMouse&) = delete;
    /**calc position to move*/
    void CalcPosition();
    /**change rotation*/
    void Scurry();
    /**update and tell motor to start
\param elapsed time since last update*/
    virtual void Update(double elapsed) override;
    /**resets*/
    virtual void Reset() override;
    /**set initial location
\param x x coord
\param y y coord*/
    void SetInitialPosition(int x, int y);
    /**set final location
\param x x coord
\param y y coord*/
    void SetFinalPosition(int x, int y) { mFinalPosition.Set(x, y); };
    /**add a motor
    \param motor to add*/
    void AddMotor(std::shared_ptr<CMotor> motor) { mMotors.push_back(motor); }
private:
    /// initial position
    CVector mInitialPosition;
    /// final position
    CVector mFinalPosition;
    /// pixels left till scurry
    int mPixelsTillScurry = 20;
    /// time since started moving
    double mTime = 0;
    /// how long to move for
    double mDuration = 2.0;
    /// motors
    std::vector<std::shared_ptr<CMotor>> mMotors;
};

