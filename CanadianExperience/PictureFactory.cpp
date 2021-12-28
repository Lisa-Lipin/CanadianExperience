/**
 * \file PictureFactory.cpp
 *
 * \author Charles B. Owen
 */

#include "pch.h"
#include "PictureFactory.h"
#include "HaroldFactory.h"
#include "SpartyFactory.h"
#include "ImageDrawable.h"
#include "AnnellaFactory.h"
#include <MachineFactory.h>
#include "MachineDrawable.h"
#include "SpeechActor.h"


using namespace std;
using namespace Gdiplus;

CPictureFactory::CPictureFactory()
{
}


CPictureFactory::~CPictureFactory()
{
}


/*! Factory method to create a new picture.
* \returns The created picture
*/
std::shared_ptr<CPicture> CPictureFactory::Create()
{
    shared_ptr<CPicture> picture = make_shared<CPicture>();

    // Create the background and add it
    auto background = make_shared<CActor>(L"Background");
    background->SetClickable(false);
    background->SetPosition(Point(-100, 0));
    auto backgroundI = make_shared<CImageDrawable>(L"Background", L"images/Background.png");
    background->AddDrawable(backgroundI);
    background->SetRoot(backgroundI);
    picture->AddActor(background);
    
    // add machine one
    CMachineFactory factory3;
    std::shared_ptr<CMachine> machine = factory3.CreateMachine();
    shared_ptr<CMachineDrawable> machineDrawable = make_shared<CMachineDrawable>(L"MachineOne");
    machineDrawable->SetMachine(machine);
    machineDrawable->SetSize(320,130);
    machineDrawable->SetLocation(600,350);
    shared_ptr<CActor> actor = make_shared<CActor>(L"MachineOne");
    actor->SetPosition(Point(600, 350));
    actor->AddDrawable(machineDrawable);
    picture->AddActor(actor);
    picture->SetMachine(machineDrawable, 1);

   


    // add machine two
    CMachineFactory factory4;
    std::shared_ptr<CMachine> machine2 = factory4.CreateMachine();
    machine2->SetMachineNumber(2);
    shared_ptr<CMachineDrawable> machineDrawable2 = make_shared<CMachineDrawable>(L"MachineTwo");
    machineDrawable2->SetMachine(machine2);
    machineDrawable2->SetSize(350, 110);
    shared_ptr<CActor> actor2 = make_shared<CActor>(L"MachineTwo");
    machineDrawable2->SetLocation(570,250);
    actor2->SetPosition(Point(570, 250));
    actor2->AddDrawable(machineDrawable2);

    picture->AddActor(actor2);
    picture->SetMachine(machineDrawable2, 2);

    
    // Add speech bubble
    shared_ptr<CSpeechActor> actor3 = make_shared<CSpeechActor>(L"Bubble");

    auto bubble = make_shared<CImageDrawable>(L"Bubble", L"images/speech-bubble.png");
    bubble->SetCenter(Point(44, 138));
    bubble->SetPosition(Point(0, -114));
    actor3->SetRoot(bubble);
    actor3->SetPosition(Point(490, 234));
    actor3->AddDrawable(bubble);
   // picture->AddActor(actor3);

    // Create and add Harold
    CHaroldFactory factory;
    auto harold = factory.Create();

    // This is where Harold will start out.
    harold->SetPosition(Point(750, 500));

    picture->AddActor(harold);

    // Create and add Sparty
    CSpartyFactory sfactory;
    auto sparty = sfactory.Create();

    sparty->SetPosition(Point(520, 500));
    picture->AddActor(sparty);

    // Create and add Annella
    CAnnellaFactory factory2;
    auto annella = factory2.Create();

    // This is where Harold will start out.
    annella->SetPosition(Gdiplus::Point(300, 500));

    picture->AddActor(annella);

    

    return picture;
}
