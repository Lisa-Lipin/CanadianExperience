/**
 * \file MotorRotate.h
 *
 * \author Elizabeth Lipin
 *
 * Class for the motor rotating part
 */
#pragma once
#include "Component.h"
#include "Source.h"
class CMotor;
/**
 * Class for the motor rotating part
 */
class CMotorRotate :
    public CComponent
{
public:
    /// Constructor
    CMotorRotate();

    /// Destructor
    virtual ~CMotorRotate() {}

    /// Copy constructor/disabled
    CMotorRotate(const CMotorRotate&) = delete;

    /// Assignment operator/disabled
    void operator=(const CMotorRotate&) = delete;
    /**update
   \param elapsed time since last update*/
    virtual void Update(double elapsed) override;
    /**resets*/
    virtual void Reset() override;
    /**set motor
    \param motor to set*/
    void SetMotor(std::shared_ptr<CMotor> motor) { mMotor = motor; }
    /**set speed
    \param speed to set*/
    void SetSpeed(double speed) { mSpeed = speed; }
    /**get speed
    \return speed*/
    double GetSpeed() { return mSpeed; }
    /// Get a pointer to the source object
    /// \return Pointer to CRotationSource object
    CSource* GetSource() { return &mSource; }
private:
    /// motor
    std::shared_ptr<CMotor> mMotor = nullptr;
    /// speed
    double mSpeed = 0;
    /// Rotation source for this component
    CSource mSource;
};

