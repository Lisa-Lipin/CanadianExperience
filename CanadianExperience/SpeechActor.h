#pragma once
#include "Actor.h"
class CSpeechActor: public CActor
{
public:
    CSpeechActor(const std::wstring& name);

    /** Default constructor disabled */
    CSpeechActor() = delete;
    /** Copy constructor disabled */
    CSpeechActor(const  CSpeechActor&) = delete;
    /** Assignment operator disabled */
    void operator=(const  CSpeechActor&) = delete;

    virtual ~CSpeechActor();
    virtual void Draw(Gdiplus::Graphics* graphics) override;
    void SetDialogue(std::wstring dialogue) { mDialogue = dialogue; }
    std::wstring GetDialogue() { return mDialogue; }

private:
    std::wstring mDialogue;
};

