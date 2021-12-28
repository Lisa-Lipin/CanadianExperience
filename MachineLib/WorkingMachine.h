/**
 * \file WorkingMachine.h
 *
 * \author Elizabeth Lipin
 *
 * Class for the working machine
 */
#pragma once
#include "Machine.h"
#include "Component.h"
class CActualMachine;
/**
 * Class for the working machine
 */
class CWorkingMachine :
    public CMachine
{
public:
    /**constructor
    \param num machine number*/
    CWorkingMachine(int num);
    /**destructor*/
    ~CWorkingMachine();
    /** \brief Default constructor disabled */
    CWorkingMachine() = delete;
    /** \brief Copy constructor disabled */
    CWorkingMachine(const CWorkingMachine&) = delete;
    /** \brief Assignment operator disabled */
    void operator=(const CWorkingMachine&) = delete;
    /*vadd component to vector
    \param component component to add*/
    void AddComponent(std::shared_ptr<CComponent> component);
    /**draw machine
    \param graphics graphics to draw with
    \param x x-coord
    \param y y-coord*/
    void Draw(Gdiplus::Graphics* graphics, int x, int y);
    /**set the actual machine
    * \param machine actual machine to set
    */
    void SetActualMachine(CActualMachine* machine) {mActualMachine = machine;};
    /**get the actual machine
    \return pointer to actual machine*/
    CActualMachine* GetActualMachine() { return mActualMachine; }
    /**
    * Set the machine number
    * \param machine An integer number. Each number makes a different machine
    */
    virtual void SetMachineNumber(int machine) override;
    /**update all components
    \param elapsed time since last update*/
    void Update(double elapsed);
    /**reset all components*/
    void Reset();
    /**set initial frame 
    \param frame to set*/
    void SetInitialFrame(int frame) { mInitialFrame = frame; }
    /**get initial frame
    \return frame*/
    int GetInitialFrame() { return mInitialFrame; }
private:
    /// the actual machine
    CActualMachine* mActualMachine = nullptr;
    /// vector of components
    std::vector<std::shared_ptr<CComponent>> mComponentsInOrder;
    /// machine number
    int mMachine = 1;
    /// initial frame
    int mInitialFrame = 0;
};

