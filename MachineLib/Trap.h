/**
 * \file Trap.h
 *
 * \author Elizabeth Lipin
 *
 * Class for the trap
 */
#pragma once
#include "Component.h"
#include "TrapCage.h"
#include "TrapPin.h"
#include "TrapHolder.h"
/**
* Class for the trap
*/
class CTrap :
    public CComponent
{
public:
    /**constructor*/
    CTrap();
    /**detructor*/
    ~CTrap();
    /// Copy constructor (disabled)
    CTrap(const CTrap&) = delete;
    /// Assignment operator (disabled)
    void operator=(const CTrap&) = delete;
    /**update
\param elapsed time since last update*/
    virtual void Update(double elapsed) override;
    /**resets*/
    virtual void Reset() {};
    /**set cage
   \param cage tor set*/
    void SetCage(std::shared_ptr<CTrapCage> cage) { mCage = cage; }
    /**set holder
   \param holder tor set*/
    void SetHolder(std::shared_ptr<CTrapHolder> holder) { mHolder = holder; }
    /**add pin
   \param pin to add*/
    void AddPin(std::shared_ptr<CTrapPin> pin) { mPins.push_back(pin); }
    /**drop cage*/
    void Drop() { mCage->SetDrop(true);}
private:
    /// cage
    std::shared_ptr<CTrapCage> mCage = nullptr;
    /// pins
    std::vector<std::shared_ptr<CTrapPin>> mPins;
    /// holder
    std::shared_ptr<CTrapHolder> mHolder = nullptr;
};

