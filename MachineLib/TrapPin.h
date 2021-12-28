/**
 * \file TrapPin.h
 *
 * \author Elizabeth Lipin
 *
 * Class for the trap pin
 */
#pragma once
#include "Component.h"
class CTrap;
class CWinch;
#include "Vector.h"
class CMotor;
/**
*Class for the trap pin
*/
class CTrapPin :
    public CComponent
{
public:
    /**constructor*/
    CTrapPin();
    /**destructor*/
    ~CTrapPin();
    /**calculatees the next poition of the pin*/
    void CalcPosition();
    /// Copy constructor (disabled)
    CTrapPin(const CTrapPin&) = delete;
    /// Assignment operator (disabled)
    void operator=(const CTrapPin&) = delete;
    /** updates the pin
    \param elapsed the time since last update*/
    virtual void Update(double elapsed) override;
    /**reset the pin*/
    virtual void Reset() override;
    /**set the trap
    \param trap trap to set*/
    void SetTrap(std::shared_ptr<CTrap> trap) { mTrap = trap; }
    /**set initial position of pin
    \param x x-coord
    \param y y-coord*/
    void SetInitialPosition(int x, int y);
    /**set the final position
    \param x x-coord
    \param y y coord*/
    void SetFinalPosition(int x, int y) { mFinalPosition.Set(x, y); };
    /**set the winch
    \param winch winch to set*/
    void SetWinch(std::shared_ptr<CWinch> winch) { mWinch = winch; }
    /**set pull
    \param pull bool to set*/
    void SetPull(double pull) { mPull = pull; }
    /**set the motor
    \param motor motor to set*/
    void SetMotor(std::shared_ptr<CMotor> motor) { mMotor = motor; }
    /**get out
    \return whether pin is out*/
    bool GetOut() { return mOut; }

private:
    /// trap
    std::shared_ptr<CTrap> mTrap = nullptr;
    /// winch
    std::shared_ptr<CWinch> mWinch = nullptr;
    /// motor
    std::shared_ptr<CMotor> mMotor = nullptr;
    /// where to start
    CVector mInitialPosition;
    /// where to end
    CVector mFinalPosition;
    /// time since movement started
    int mTime = 0;
    /// whether pin can be pulled
    double mPull = 0;
    /// whethwr pin is out
    bool mOut = false;
};

