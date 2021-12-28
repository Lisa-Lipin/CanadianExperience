
/**
 * \file Winch.h
 *
 * \author Elizabeth Lipin
 *
 * Class for the winch
 */
#pragma once
#include "Component.h"
#include "Sink.h"
#include "Source.h"
#include "Vector.h"
#include "TrapPin.h"
class CMotor;
class CTrap;
/**
 * Class for the winch
 */
class CWinch :
    public CComponent
{
public:
    /**constructor*/
    CWinch();
    /**destructor*/
    ~CWinch();
    /// Copy constructor (disabled)
    CWinch(const CWinch&) = delete;
    /// Assignment operator (disabled)
    void operator=(const CWinch&) = delete;
    /**draws the component
\param graphics to draw with
\param x coord
\param y coord*/
    virtual void Draw(Gdiplus::Graphics* graphics, int x, int y) override;
    /**update
\param elapsed time since last update*/
    virtual void Update(double elapsed) override;
    /**resets*/
    virtual void Reset() override;
    /**get sink
    \return sink*/
    CSink* GetSink() { return &mSink; }
    /**sets rotation
    \param rotation to set*/
    virtual void SetRotation(double rotation) override;
    /// Get a pointer to the source object
    /// \return Pointer to CRotationSource object
    CSource* GetSource() { return &mSource; }
    /**pull pin*/
    void PullPin();
    /**set end location
\param x x coord
\param y y coord*/
    void SetCableEnd(int x, int y);
    /**get radius
    \return radius*/
    int GetRadius() { return mRadius; }
    /**set radius
    \param radius to set*/
    void SetRadius(int radius) { mRadius = radius; }
    /**add pin
    \param pin to add*/
    void AddPin(std::shared_ptr<CTrapPin> pin) { mPins.push_back(pin); }
    /**set tangent location
\param x x coord
\param y y coord*/
    void SetTangent(int x, int y);
    /**set trap
    \param trap to set*/
    void SetTrap(std::shared_ptr<CTrap> trap) { mTrap = trap; }
    /**get speed
    \return speed*/
    double GetSpeed() { return GetSink()->GetSpeed(); }
    /**set speed
    \param speed to set*/
    void SetSpeed(double speed) { mSpeed = speed; }
    /**set motor
    \param motor to set*/
    void SetMotor(std::shared_ptr<CMotor> motor) { mMotor = motor; }
    /**set pull
    \param pull to set*/
    void SetPull(bool pull) { mPull = pull; }
private:
    /// sink
    CSink mSink;
    /// Rotation source for this component
    CSource mSource;
    /// current length
    double mCurrentLength = 0;
    /// radius
    int mRadius = 0;
    /// cable end position
    CVector mCableEnd;
    /// cable tangent position
    CVector mTangent;
    /// pin
    std::vector<std::shared_ptr<CTrapPin>> mPins;
    /// whether to pull
    bool mPull = false;
    /// trap
    std::shared_ptr<CTrap> mTrap = nullptr;
    /// speed
    double mSpeed = 1;
    /// motor
    std::shared_ptr<CMotor> mMotor = nullptr;
};

