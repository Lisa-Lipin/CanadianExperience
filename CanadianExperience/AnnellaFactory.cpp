/**
 * \file AnnellaFactory.cpp
 *
 * \author Lisa Lipin
 */
#include "pch.h"
#include "AnnellaFactory.h"
#include "Actor.h"
#include <memory>
#include "PolyDrawable.h"
#include "ImageDrawable.h"
#include "HeadTop.h"
using namespace std;
using namespace Gdiplus;
/** This is a concrete factory method that creates our Annella actor.
* \returns Pointer to an actor object.
*/

std::shared_ptr<CActor> CAnnellaFactory::Create()
{
    shared_ptr<CActor> actor = make_shared<CActor>(L"Annella");

    auto shirt = make_shared<CImageDrawable>(L"Shirt", L"images/black_coat.png");
    shirt->SetCenter(Point(44, 138));
    shirt->SetPosition(Point(0, -114));
    actor->SetRoot(shirt);

    auto lleg = make_shared<CImageDrawable>(L"Left Leg", L"images/jeans_lleg.png");
    lleg->SetCenter(Point(11, 9));
    lleg->SetPosition(Point(15, 10));
    shirt->AddChild(lleg);

    auto rleg = make_shared<CImageDrawable>(L"Right Leg", L"images/jeans_rleg.png");
    rleg->SetCenter(Point(39, 9));
    rleg->SetPosition(Point(-15, 10));
    shirt->AddChild(rleg);

    auto headb = make_shared<CImageDrawable>(L"Head Bottom", L"images/headb3.png");
    headb->SetCenter(Point(44, 31));
    headb->SetPosition(Point(0, -130));
    shirt->AddChild(headb);

    auto headt = make_shared<CHeadTop>(L"Head Top", L"images/headt4.png");
    headt->SetCenter(Point(80, 109));
    headt->SetPosition(Point(0, -30));
    headt->SetEyesCenter(Point(80, 80));
    headt->GetLeftEye()->LoadImage(L"images/eye.png");
    headt->GetLeftEye()->SetCenter(Point(7, 16));
    headt->GetRightEye()->LoadImage(L"images/eye.png");
    headt->GetRightEye()->SetCenter(Point(15, 16));
    headt->SetInterocularDistance(30);
    headb->AddChild(headt);

    auto larm = make_shared<CPolyDrawable>(L"Left Arm");
    larm->SetColor(Color(180, 60, 184));
    larm->SetPosition(Point(50, -130));
    larm->AddPoint(Point(-7, -7));
    larm->AddPoint(Point(-7, 96));
    larm->AddPoint(Point(8, 96));
    larm->AddPoint(Point(8, -7));
    shirt->AddChild(larm);


    auto rarm = make_shared<CPolyDrawable>(L"Right Arm");
    rarm->SetColor(Color(180, 60, 184));
    rarm->SetPosition(Point(-45, -130));
    rarm->AddPoint(Point(-7, -7));
    rarm->AddPoint(Point(-7, 96));
    rarm->AddPoint(Point(8, 96));
    rarm->AddPoint(Point(8, -7));
    shirt->AddChild(rarm);

    auto lhand = make_shared<CPolyDrawable>(L"Left Hand");
    lhand->SetColor(Color(253, 218, 180));
    lhand->SetPosition(Point(0, 96));
    lhand->AddPoint(Point(-12, -2));
    lhand->AddPoint(Point(-12, 17));
    lhand->AddPoint(Point(11, 17));
    lhand->AddPoint(Point(11, -2));
    larm->AddChild(lhand);

    auto rhand = make_shared<CPolyDrawable>(L"Right Hand");
    rhand->SetColor(Color(253, 218, 180));
    rhand->SetPosition(Point(0, 96));
    rhand->AddPoint(Point(-12, -2));
    rhand->AddPoint(Point(-12, 17));
    rhand->AddPoint(Point(11, 17));
    rhand->AddPoint(Point(11, -2));
    rarm->AddChild(rhand);

    auto mug = make_shared<CImageDrawable>(L"Mug", L"images/mug.png");
    mug->SetCenter(Point(0, 40));
    mug->SetPosition(Point(0, 10));
    lhand->AddChild(mug);


    actor->AddDrawable(larm);
    actor->AddDrawable(rarm);
    actor->AddDrawable(rhand);
    actor->AddDrawable(lhand);
    actor->AddDrawable(rleg);
    actor->AddDrawable(lleg);
    actor->AddDrawable(shirt);
    actor->AddDrawable(headb);
    actor->AddDrawable(headt);
    actor->AddDrawable(mug);

    return actor;
}
