/**
 * \file TrapHolder.h
 *
 * \author Elizabeth Lipin
 *
 * Class for the trap holder
 */
#pragma once
#include "Component.h"
/**
 * Class for the trap holder
 */
class CTrapHolder :
    public CComponent
{
public:
    /**contructor*/
    CTrapHolder();
    /**destructor*/
    ~CTrapHolder();
    /**calculate position*/
    /// Copy constructor (disabled)
    CTrapHolder(const CTrapHolder&) = delete;
    /// Assignment operator (disabled)
    void operator=(const CTrapHolder&) = delete;
    /**update
\param elapsed time since last update*/
    virtual void Update(double elapsed) {};
    /**resets*/
    virtual void Reset() {};
};

