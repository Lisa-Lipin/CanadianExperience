/**
 * \file Picture.h
 *
 * \author Charles B. Owen
 *
 * The picture we are drawing
 */

#pragma once

#include <vector>
#include "PictureObserver.h"
#include "Timeline.h"
#include <Machine.h>

class CActor;
#include "MachineDrawable.h"
#include "SpeechActor.h"

/**
 * The picture we are drawing.
 *
 * There will be one picture object that contains all of 
 * our actors, which then contains the drawables. 
 */
class CPicture
{
public:
    CPicture();
    virtual ~CPicture();

    /// Copy Constructor (Disabled)
    CPicture(const CPicture &) = delete;
    /// Assignment Operator (Disabled)
    /// \return nothing
    CPicture &operator=(const CPicture &) = delete;

    /** The picture size
    * \returns Size */
    Gdiplus::Size GetSize() { return mSize; }

    /** The picture size
    * \param size The new picture size */
    void SetSize(Gdiplus::Size size) { mSize = size; }

    void AddObserver(CPictureObserver *observer);
    void RemoveObserver(CPictureObserver *observer);
    void UpdateObservers();
    void Draw(Gdiplus::Graphics *graphics);
    void AddActor(std::shared_ptr<CActor> actor);

    void Save(const std::wstring &filename);
    void Load(const std::wstring &filename);
    /**Set the machines
    \param machine to set
    \param num which machine to set*/
    void SetMachine(std::shared_ptr<CMachineDrawable> machine, int num) {
        if (num == 1) { mMachineOne = machine; }
        else if (num == 2) { mMachineTwo = machine; };
    }
    /**Set the start frames
    \param frame to set
    \param num which machine to set*/
    void SetStartFrame(int frame, int num) {
        if (num == 1) { mMachine1StartFrame = frame; }
        else if (num == 2) { mMachine2StartFrame = frame; }
    }
    /**choose which machine to change
    \param x x coord to check
    \param y y coord to check*/
    void ChooseMachine(int x, int y) {
            if (mMachineOne->HitTest(Gdiplus::Point(x,y))) {
                mMachineOne->SetNewNum();
            }
            else if (mMachineTwo->HitTest(Gdiplus::Point(x, y))) {
                mMachineTwo->SetNewNum();
            }
            ;
        }
   /**set the frame for both machines
  \param frame to set*/
    void SetMachineFrame(int frame);
    /**get the start frame for machine one
    \return start frame machine 1*/
    int GetMachineOneStart() { return mMachine1StartFrame; }
    /**get the start frame for machine 2
    \return start frame machine 2*/
    int GetMachineTwoStart() { return mMachine2StartFrame; }
    /**set the start frame for machine one
    \param frame start frame machine 1*/
    void SetMachineOneStart(int frame) { mMachine1StartFrame = frame; }
    /**set the start frame for machine 2
    \param frame start frame machine 2*/
    void SetMachineTwoStart(int frame) { mMachine2StartFrame = frame; }

    std::shared_ptr<CSpeechActor> ChangeSpeech() { return mSpeech; }
    /** Iterator that iterates over the actors in a picture */
    class ActorIter
    {
    public:
        /** Constructor
        * \param picture Picture we are iterating
        * \param pos Starting position */
        ActorIter(CPicture *picture, int pos) : mPicture(picture), mPos(pos) {}

        /** Test for end of the iterator
        * \param other Other object to test against
        * \returns True if we this position equals not equal to the other position */
        bool operator!=(const ActorIter &other) const
        {
            return mPos != other.mPos;
        }

        /** Get value at current position
        * \returns Value at mPos in the collection */
        std::shared_ptr<CActor> operator *() const { return mPicture->mActors[mPos]; }

        /** Increment the iterator
        * \returns Reference to this iterator */
        const ActorIter& operator++()
        {
            mPos++;
            return *this;
        }


    private:
        CPicture *mPicture; ///< Picture we are iterating over
        int mPos;           ///< Position in the collection
    };

    /** Get an iterator for the beginning of the collection
    * \returns Iter object at position 0 */
    ActorIter begin() { return ActorIter(this, 0); }

    /** Get an iterator for the end of the collection
    * \returns Iter object at position past the end */
    ActorIter end() { return ActorIter(this, mActors.size()); }

    /** Get a pointer to the Timeline object
    * \returns Pointer to the Timeline object
    */
    CTimeline *GetTimeline() { return &mTimeline; }
    void SetAnimationTime(double time);
    double GetAnimationTime();

private:
    /// The picture size
    Gdiplus::Size mSize = Gdiplus::Size(800, 600);

    /// The observers of this picture
    std::vector<CPictureObserver *> mObservers;

    //! The actors associated with this picture
    std::vector<std::shared_ptr<CActor>> mActors;

    /// The animation timeline
    CTimeline mTimeline;

    ///Machine one
    std::shared_ptr<CMachineDrawable> mMachineOne = nullptr;

    ///Machine two
    std::shared_ptr<CMachineDrawable> mMachineTwo = nullptr;

    ///machine 1 start frame
    int mMachine1StartFrame = 0;
    /// machine 2 start frame
    int mMachine2StartFrame = 0;

    std::shared_ptr<CSpeechActor> mSpeech = nullptr;
};

