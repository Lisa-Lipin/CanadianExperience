/**
 * \file Motor.h
 *
 * \author Elizabeth Lipin
 *
 * Class for the motor
 */
#pragma once
#include "Component.h"
#include "MotorBase.h"
#include "MotorRotate.h"
#include "Source.h"
class CWinch;
class CMouse;
/**
*Class for the motor
*/
class CMotor :
    public CComponent
{
public:
    /// Constructor
    CMotor();

    /// Destructor
    virtual ~CMotor() {}

    /// Copy constructor/disabled
    CMotor(const CMotor&) = delete;

    /// Assignment operator/disabled
    void operator=(const CMotor&) = delete;
    /**update
    \param elapsed time since last update*/
    virtual void Update(double elapsed) {};
    /**resets*/
    virtual void Reset() override;
    /**Set Rotate
    \param rotate rotation part to set*/
    void SetRotate(std::shared_ptr<CMotorRotate> rotate) { mRotate = rotate; }
    /**Set base
    \param base base part to set*/
    void SetBase(std::shared_ptr<CMotorBase> base) { mBase = base; }
    /**Set moue
    \param mouse mouse to set*/
    void SetMouse(std::shared_ptr<CMouse> mouse) { mMouse = mouse; }
    /**check if go
    \return if go*/
    bool IsGo() { return mGo; }
    /**start/stop motor and tell winches they can pull
    \param go whether can go*/
    void SetGo(bool go);
    /**Add winch
    \param winch to add */
    void AddWinch(std::shared_ptr<CWinch> winch) { mWinches.push_back(winch); }
    /**check if has stopped
    \return if has stopped*/
    bool HasStopped() { return mHasStopped; }
    /**set stopped
    \param stopped whether has stopped*/
    void SetStopped(bool stopped) { mHasStopped = stopped; }
    
private:
    /// base
    std::shared_ptr<CMotorBase> mBase = nullptr;
    /// mouse
    std::shared_ptr<CMouse> mMouse = nullptr;
    /// rotation part
    std::shared_ptr<CMotorRotate> mRotate = nullptr;
    /// winches
    std::vector<std::shared_ptr<CWinch>> mWinches;
    /// if running
    bool mGo = false;
    /// if has stopped
    bool mHasStopped = false;
    
};

