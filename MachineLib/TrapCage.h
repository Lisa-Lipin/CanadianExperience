/**
 * \file TrapCage.h
 *
 * \author Elizabeth Lipin
 *
 * Class for the trap cage
 */
#pragma once
#include "Component.h"
#include "Vector.h"
class CTrap;
/**
 * Class for the trap cage
 */
class CTrapCage :
    public CComponent
{
public:
    /**contructor*/
    CTrapCage();
    /**destructor*/
    ~CTrapCage();
    /**calculate position*/
    void CalcPosition();
    /// Copy constructor (disabled)
    CTrapCage(const CTrapCage&) = delete;
    /// Assignment operator (disabled)
    void operator=(const CTrapCage&) = delete;
    /**update
\param elapsed time since last update*/
    virtual void Update(double elapsed) override;
    /**resets*/
    virtual void Reset() override;
    /**set trap
   \param trap to set*/
    void SetTrap(std::shared_ptr<CTrap> trap) { mTrap = trap; }
    /**set drop
    \param drop whether to drop*/
    void SetDrop(bool drop) { mDrop = drop; }
    /**set initial location
\param x x coord
\param y y coord*/
    void SetInitialPosition(int x, int y);
    /**set final location
\param x x coord
\param y y coord*/
    void SetFinalPosition(int x, int y) { mFinalPosition.Set(x, y); };
    
private:
    /// trap
    std::shared_ptr<CTrap> mTrap = nullptr;
    /// whether to drop
    bool mDrop = false;
    /// initial position
    CVector mInitialPosition;
    /// final position
    CVector mFinalPosition;
    /// time since movement began
    int mTime = 0;
    /// how much to fall by
    double mFall = 0;
};

