/**
 * \file ActualMachine.h
 *
 * \author Elizabeth Lipin
 *
 * Class for the Actual Machine
 */
#pragma once
#include "Machine.h"
#include "WorkingMachine.h"
#include "Component.h"
/**
 * Class for the Actual Machine
 */
class CActualMachine :
    public CMachine
{
public:
    /// Constructor
    CActualMachine();

    /// Destructor
    virtual ~CActualMachine() {}

    /// Copy constructor/disabled
    CActualMachine(const CActualMachine&) = delete;

    /// Assignment operator/disabled
    void operator=(const CActualMachine&) = delete;

    /**
    * Set the position for the root of the machine
    * \param x X location (pixels)
    * \param y Y location (pixels)
    */
    virtual void SetLocation(int x, int y) override;

    /**
    * Draw the machine at the currently specified location
    * \param graphics GDI+ Graphics object
    */
    virtual void DrawMachine(Gdiplus::Graphics* graphics) override;

    /**
    * Set the current machine animation frame
    * \param frame Frame number
    */
    virtual void SetMachineFrame(int frame) override;

    /**
    * Set the machine number
    * \param machine An integer number. Each number makes a different machine
    */
    virtual void SetMachineNumber(int machine) override;

    /**
     * Get the current machine number
     * \return Machine number integer
     */
    virtual int GetMachineNumber() override;
    /**Set the working machine
    \param machine to set*/
    void SetWorkingMachine(std::shared_ptr<CWorkingMachine> machine);
    /**get the x coord
    \return x coord*/
    int GetX() { return mX; }
    /**get the y coord
    \return y coord*/
    int GetY() { return mY; }
    /**set the initial frame
    \param frame frame to set*/
    void SetInitialFrame(int frame) { mWorkingMachine->SetInitialFrame(frame); }
    

private:
    /**
     * the working machine
     *
     */
    std::shared_ptr<CWorkingMachine> mWorkingMachine;
    /// x coord
    int mX = 0;
    /// y coord
    int mY = 0;
    /// current frame
    int mCurrentFrame = 0;
    /// machine number
    int mMachine = 1;
    /// initial frame
    int mInitialFrame = 0;
    
};

