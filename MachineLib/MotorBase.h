/**
 * \file MotorBase.h
 *
 * \author Elizabeth Lipin
 *
 * Class for the motor base
 */
#pragma once
class CMotor;
#include "Component.h"
#include <memory>
/**
 * Class for the motor base
 */
class CMotorBase :
    public CComponent
{
public:
    /// Constructor
    CMotorBase();

    /// Destructor
    virtual ~CMotorBase() {}

    /// Copy constructor/disabled
    CMotorBase(const CMotorBase&) = delete;

    /// Assignment operator/disabled
    void operator=(const CMotorBase&) = delete;
    /**update
    \param elapsed time since last update*/
    virtual void Update(double elapsed) {};
    /**resets*/
    virtual void Reset() {};
    /**sets motor
    \param motor motor to set*/
    void SetMotor(std::shared_ptr<CMotor> motor) { mMotor = motor; }
private:
    /// motor
    std::shared_ptr<CMotor> mMotor = nullptr;
};

