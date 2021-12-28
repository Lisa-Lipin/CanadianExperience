/**
 * \file Machine1Factory.cpp
 *
 * \author Elizabeth Lipin
 */
#include "pch.h"
#include "Machine1Factory.h"
#include "WorkingMachine.h"
#include "ActualMachine.h"
#include "Shape.h"
#include "Mouse.h"
#include "Motor.h"
#include "Gear.h"
#include "Winch.h"
#include "Trap.h"
#include "TrapHolder.h"

/**create machine one
\return machine*/
std::shared_ptr<CMachine> CMachine1Factory::CreateMachine()
{
    // Locations of stuff
    const int CheeseSize = 70;
    const int CheeseX = -73;
    const int CheeseY = 2;
    const int MouseSize = 76;

    const int MotorX = -250;
    const int MotorY = -50;
    const int WinchX = -250;

    // Gear locations. Gear 1 is the location of the motor, 
    // Gear 2 and 3 are at the same location.
    const int Gear2X = MotorX + 59;
    const int Gear2Y = -109;
    const int Gear4X = Gear2X - 79;
    const int Gear4Y = Gear2Y - 60;

    // The machine itself
    auto machine = std::make_shared<CWorkingMachine>(1);

    // The base
    auto base = std::make_shared<CShape>();
    int wid = 650;
    base->Rectangle(-wid / 2, 10, wid, 10);
    base->SetColor(Gdiplus::Color::DarkGray);
    machine->AddComponent(base);

    // Add post that hol the 2nd and 4th gears
    // You can only just barely see the one 
    // for the 4th gear behind the motor and gears
    AddPost(machine, Gear2X, -Gear2Y + 10);
    AddPost(machine, Gear4X, -Gear4Y + 10);

    // The cheese
    auto cheese = std::make_shared<CShape>();
    cheese->Rectangle(0, 0, CheeseSize, CheeseSize);
    cheese->SetLocation(CheeseX, CheeseY);
    cheese->SetImage(L"images/cheese.png");
    machine->AddComponent(cheese);

    // The mouse
    auto mouse = std::make_shared<CMouse>();
    mouse->SetInitialPosition(260, 0);
    mouse->SetImage(L"images/mouse.png");
    mouse->Rectangle(0, 0, MouseSize, MouseSize);
    // This puts the mouse final position to the right of the 
    // cheese. The -3 moves the mouse a bit left so it appears
    // to be touching the cheese.
    mouse->SetFinalPosition(CheeseX + CheeseSize + MouseSize / 40 - 3, 0);
    machine->AddComponent(mouse);

    // The motor
    auto motor = std::make_shared<CMotor>();
    motor->SetLocation(MotorX, MotorY);
    motor->CenteredSquare(0);
    mouse->AddMotor(motor);
    motor->SetMouse(mouse);
    machine->AddComponent(motor);

    auto motorBase = std::make_shared<CMotorBase>();
    motorBase->SetLocation(MotorX, MotorY );
    motorBase->SetImage(L"images/motor2.png");
    motorBase->CenteredSquare(100);
    motorBase->SetMotor(motor);
    motor->SetBase(motorBase);
    machine->AddComponent(motorBase);

    auto motorRotate = std::make_shared<CMotorRotate>();
    motorRotate->SetLocation(MotorX, MotorY);
    motorRotate->SetImage(L"images/shaft.png");
    motorRotate->CenteredSquare(20);
    motor->SetRotate(motorRotate);
    motorRotate->SetMotor(motor);
    motorRotate->SetSpeed(1);
    machine->AddComponent(motorRotate);

    // The trap
    auto trap = std::make_shared<CTrap>();
    trap->SetLocation(0, -150);
    trap->SetImage(L"images/trap-stand.png");
    trap->CenteredSquare(300);
    

    
    
    // The trap pin
    auto trapPin = std::make_shared<CTrapPin>();
    trapPin->SetInitialPosition(0, -150);
    trapPin->SetFinalPosition(-65, -150);
    trapPin->SetImage(L"images/trap-pin.png");
    trapPin->CenteredSquare(300);
    trapPin->SetTrap(trap);
    trap->AddPin(trapPin);
    trapPin->SetMotor(motor);

// The trap cage
    auto trapCage = std::make_shared<CTrapCage>();
    trapCage->SetInitialPosition(0, -250);
    trapCage->SetFinalPosition(0, -150);
    trapCage->SetImage(L"images/trap-trap.png");
    trapCage->CenteredSquare(300);
    trapCage->SetTrap(trap);
    trap->SetCage(trapCage);
    machine->AddComponent(trapCage);
    
    machine->AddComponent(trap);
    // The trap holder
    auto trapHolder = std::make_shared<CTrapHolder>();
    trapHolder->SetImage(L"images/trap-stand-front.png");
    trapHolder->CenteredSquare(300);
    trapHolder->SetLocation(0, -150);
    trap->SetHolder(trapHolder);
    machine->AddComponent(trapHolder);
    

    // The winch
    auto winch = std::make_shared<CWinch>();
    winch->SetImage(L"images/drum.png");
    winch->CenteredSquare(80);
    winch->SetRadius(35);
    winch->AddPin(trapPin);
    winch->SetLocation(WinchX, -266 + winch->GetRadius());
    winch->SetTrap(trap);
    winch->SetMotor(motor);
    motor->AddWinch(winch);
    trapPin->SetWinch(winch);
    winch->SetCableEnd(10, -266);

    // The gear driven by the motor
    // Radius=30pixels, 15 teeth
    auto gear1 = std::make_shared<CGear>(30, 15);
    gear1->SetImage(L"images/iron.png");
    gear1->SetLocation(MotorX, MotorY);
    machine->AddComponent(gear1);

    motorRotate->GetSource()->AddSink(gear1->GetSink());
    gear1->SetSpeed(motorRotate->GetSpeed());
    gear1->GetSink()->SetSpeed(motorRotate->GetSpeed());

    // The second gear
    // Radius=60pixels, 35 teeth
    auto gear2 = std::make_shared<CGear>(60, 35);
    gear2->SetImage(L"images/hammered-copper.png");
    gear2->SetLocation(Gear2X, Gear2Y);
    gear2->SetAdjust(0.01);

    // We add the post before the gear,
    // so it is behind it.
    machine->AddComponent(gear2);
    gear1->Drive(gear2);

    // A third gear
    auto gear3 = std::make_shared<CGear>(25, 15);
    gear3->SetImage(L"images/iron.png");
    gear3->SetLocation(gear2->GetX(), gear2->GetY());
    machine->AddComponent(gear3);

    // Direct connection
    gear2->GetSource()->AddSink(gear3->GetSink());
    gear3->SetSpeed(gear2->GetSink()->GetSpeed());
    gear3->GetSink()->SetSpeed(gear2->GetSink()->GetSpeed());

    auto gear4 = std::make_shared<CGear>(80, 50);
    gear4->SetImage(L"images/steel.png");
    gear4->SetLocation(Gear4X, Gear4Y);
    gear4->SetAdjust(0.005);
    machine->AddComponent(gear4);

    gear3->Drive(gear4);

    // Gear 5: Radius=21pixels, 13 teeth
    auto gear5 = std::make_shared<CGear>(21, 13);
    gear5->SetImage(L"images/iron.png");
    gear5->SetLocation(gear4->GetX(), gear4->GetY());
    machine->AddComponent(gear5);

    // Direct connection
    gear4->GetSource()->AddSink(gear5->GetSink());
    gear5->SetSpeed(gear4->GetSink()->GetSpeed());
    gear5->GetSink()->SetSpeed(gear4->GetSink()->GetSpeed());

    auto gear6 = std::make_shared<CGear>(50, 40);
    gear6->SetImage(L"images/hammered-copper.png");
    gear6->SetLocation(winch->GetX(), winch->GetY());
    gear6->SetAdjust(0.013);
    machine->AddComponent(gear6);

    gear5->Drive(gear6);

    gear6->GetSource()->AddSink(winch->GetSink());
    winch->SetSpeed(gear6->GetSink()->GetSpeed());
    winch->GetSink()->SetSpeed(gear6->GetSink()->GetSpeed());

    machine->AddComponent(winch);
    machine->AddComponent(trapPin);

    // Flag that is driven by the winch as it moves
    auto flag = std::make_shared<CShape>();
    flag->AddPoint(0, 0);
    flag->AddPoint(0, -120);
    flag->AddPoint(60, -120);
    flag->AddPoint(60, 0);
    flag->SetImage(L"images/mouse-flag.png");
    flag->SetLocation(winch->GetX(), winch->GetY());
    machine->AddComponent(flag);
    winch->GetSource()->AddSink(flag->GetSink());
    flag->SetSpeed(winch->GetSpeed());
    flag->GetSink()->SetSpeed(winch->GetSpeed());

    return machine;
}

/**
 * Add a post.
 *
 *
 * \param machine Machine we are adding the post to.
 * \param x X location for the post
 * \param height Height of the post
 */
void CMachine1Factory::AddPost(std::shared_ptr<CWorkingMachine> machine, int x, int height)
{
    // The post itself
    auto post = std::make_shared<CShape>();
    post->Rectangle(-5, 0, 10, height);
    post->SetLocation(x, 0);
    post->SetImage(L"images/post.png");
    machine->AddComponent(post);

    // The post base. It's a square image that
    // is 4 times as wide as the post image
    auto base = std::make_shared<CShape>();
    base->Rectangle(-20, 0, 40, 40);
    base->SetLocation(x, 0);
    base->SetImage(L"images/post-base.png");
    machine->AddComponent(base);
}