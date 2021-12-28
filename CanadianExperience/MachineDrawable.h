/**
 * \file MachineDrawable.h
 *
 * \author Elizabeth Lipin
 *
 * Class for the machine drawable
 */
#pragma once
#include "Drawable.h"
#include "Machine.h"
/**
 * Class for the machine drawable
 */
class CMachineDrawable :
    public CDrawable
{
public:
    /**constructor
\param name name for drawable*/
    CMachineDrawable(const std::wstring& name);
    /**destructor*/
    virtual ~CMachineDrawable();

    /** Default constructor disabled */
    CMachineDrawable() = delete;
    /** Copy constructor disabled */
    CMachineDrawable(const CMachineDrawable&) = delete;
    /** Assignment operator disabled */
    void operator=(const CMachineDrawable&) = delete;
    /**draw machine
    \param graphics to draw with*/
    virtual void Draw(Gdiplus::Graphics* graphics) override;
    /**hit test
    \param pos point to test*/
    virtual bool HitTest(Gdiplus::Point pos) override;
    /**set machine 
    \param machine machine to set*/
    void SetMachine(std::shared_ptr<CMachine> machine) { mMachine = machine; }
    /**Set Keyframes*/
    virtual void SetKeyframe() {};
    /**get keyframes*/
    virtual void GetKeyframe() {};

    /// Is this drawable moveable?
    /// \returns true
    virtual bool IsMovable() { return true; }
    /**Set size for hit test
    \param width width of hit
    \param height height of hit*/
    void SetSize(int width, int height);
    /**Set machine location
    \param x x coord
   \param y y coord*/
    void SetLocation(int x, int y) { SetPosition(Gdiplus::Point(x,y)); mMachine->SetLocation(x, y); }

    /**set new machine numbers calling machine dialogue*/
    void SetNewNum();

    /**set frames
    \param frame frame to set*/
    void SetFrame(int frame) { mMachine->SetMachineFrame(frame); }
    /**gets the number of machine
    \return machine number*/
    int GetMachineNum() { return mMachine->GetMachineNumber(); }
    /**Sets machine number
    \param num number to set*/
    void SetMachineNum(int num) {  mMachine->SetMachineNumber(num); }

private:
    /// width of machine
    int mWidth = 0;
    /// height of machine
    int mHeight = 0;
    /// machine
    std::shared_ptr<CMachine> mMachine = nullptr;
};

