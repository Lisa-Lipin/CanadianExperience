/**
 * \file Picture.cpp
 *
 * \author Charles B. Owen
 */

#include "pch.h"
#include "Picture.h"
#include "Actor.h"

using namespace Gdiplus;
using namespace xmlnode;

/**
 * Constructor
 */
CPicture::CPicture()
{
}


/**
 * Destructor
 */
CPicture::~CPicture()
{
}

/** Set the current animation time
*
* This forces the animation of all
* objects to the current animation location.
* \param time The new time.
*/
void CPicture::SetAnimationTime(double time)
{
    mTimeline.SetCurrentTime(time);
    SetMachineFrame(GetTimeline()->GetCurrentFrame());
    UpdateObservers();

    for (auto actor : mActors)
    {
        actor->GetKeyframe();
    }
}

/** Add an observer to this picture.
* \param observer The observer to add
*/
void CPicture::AddObserver(CPictureObserver *observer)
{
    mObservers.push_back(observer);
}

/** Remove an observer from this picture
* \param observer The observer to remove
*/
void CPicture::RemoveObserver(CPictureObserver *observer)
{
    auto loc = find(std::begin(mObservers), std::end(mObservers), observer);
    if (loc != std::end(mObservers))
    {
        mObservers.erase(loc);
    }
}

/** Update all observers to indicate the picture has changed.
*/
void CPicture::UpdateObservers()
{
    for (auto observer : mObservers)
    {
        observer->UpdateObserver();
    }
}

/** Draw this picture on a device context
* \param graphics The device context to draw on
*/
void CPicture::Draw(Gdiplus::Graphics *graphics)
{
    for (auto actor : mActors)
    {
        actor->Draw(graphics);
    }
}


/** Add an actor to this picture.
* \param actor The actor to add
*/
void CPicture::AddActor(std::shared_ptr<CActor> actor)
{
    mActors.push_back(actor);
    actor->SetPicture(this);
}

/** Get the current animation time.
* \returns The current animation time
*/
double CPicture::GetAnimationTime()
{
    return mTimeline.GetCurrentTime();
}


/**
* Save the picture animation to a file
* \param filename File to save to.
*/
void CPicture::Save(const std::wstring &filename)
{
    //
    // Create an XML document
    //
    auto root = CXmlNode::CreateDocument(L"anim");

    // Save the timeline animation into the XML
    mTimeline.Save(root);

    root->SetAttribute(L"machine1start", mMachine1StartFrame);
    root->SetAttribute(L"machine2start", mMachine2StartFrame);
    root->SetAttribute(L"machine1num", mMachineOne->GetMachineNum());
    root->SetAttribute(L"machine2num", mMachineTwo->GetMachineNum());
    root->SetAttribute(L"machine1x", mMachineOne->GetPosition().X);
    root->SetAttribute(L"machine1y", mMachineOne->GetPosition().Y);
    root->SetAttribute(L"machine2x", mMachineTwo->GetPosition().X);
    root->SetAttribute(L"machine2y", mMachineTwo->GetPosition().Y);
    //
    // It is possible to add attributes to the root node here
    //
    //root->SetAttribute(L"something", mSomething);

    try
    {
        root->Save(filename);
    }
    catch (CXmlNode::Exception ex)
    {
        AfxMessageBox(ex.Message().c_str());
    }
}



/**
* Load a picture animation from a file
* \param filename file to load from
*/
void CPicture::Load(const std::wstring &filename)
{
    // We surround with a try/catch to handle errors
    try
    {
        // Open the document to read
        auto root = CXmlNode::OpenDocument(filename);
        
        // Load the animation from the XML
        mTimeline.Load(root);

        //
        // It is possible to load attributes from the root node here
        //
        // mSomething = root->GetAttributeIntValue(L"something", 123);

        mMachine1StartFrame = root->GetAttributeIntValue(L"machine1start", 123);
        mMachine2StartFrame = root->GetAttributeIntValue(L"machine2start",123);
        int x = root->GetAttributeIntValue(L"machine1num", 123);
        int y = root->GetAttributeIntValue(L"machine2num", 123);
        int w = root->GetAttributeIntValue(L"machine1x", 123);
        int z = root->GetAttributeIntValue(L"machine1y", 123);
        int a = root->GetAttributeIntValue(L"machine2x", 123);
        int b = root->GetAttributeIntValue(L"machine2y", 123);
        mMachineOne->SetMachineNum(x);
        mMachineTwo->SetMachineNum(y);
        mMachineOne->SetLocation(w - 180, z - 100);
        mMachineTwo->SetLocation(a - 150, b - 80);



        SetAnimationTime(0);
        UpdateObservers();
    }
    catch (CXmlNode::Exception ex)
    {
        AfxMessageBox(ex.Message().c_str());
    }

}

void CPicture::SetMachineFrame(int frame)
{
    if (mMachine1StartFrame >= mTimeline.GetCurrentFrame())
    {
        mMachineOne->SetFrame(0);
        
    }
    else {
        mMachineOne->SetFrame(frame - mMachine1StartFrame);
    }
    if (mMachine2StartFrame >= mTimeline.GetCurrentFrame())
    {
        mMachineTwo->SetFrame(0);

    }
    else {
        mMachineTwo->SetFrame(frame - mMachine2StartFrame);
    }
}

