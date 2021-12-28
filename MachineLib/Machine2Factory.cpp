/**
 * \file Machine2Factory.cpp
 *
 * \author Elizabeth Lipin
 */
#include "pch.h"
#include "Machine2Factory.h"
#include "WorkingMachine.h"
#include "ActualMachine.h"
#include "Shape.h"
#include "Mouse.h"
#include "Motor.h"
#include "MotorBase.h"
#include "MotorRotate.h"
#include "Gear.h"
#include "TrapPin.h"
#include "TrapCage.h"
#include "Trap.h"
#include "Winch.h"
#include "TrapHolder.h"

 /**create machine two
 \return machine*/
std::shared_ptr<CMachine> CMachine2Factory::CreateMachine()
{
    // Locations of stuff
    const int CheeseSize = 70;
    const int CheeseX = -63;
    const int CheeseY = 2;
    const int MouseSize = 76;

    const int MotorX = -400;
    const int MotorY = -50;
    const int WinchX = -280;

    // Gear locations. Gear 1 is the location of the motor, 
    // Gear 2 and 3 are at the same location.
    const int Gear2X = MotorX + 75;
    const int Gear2Y = -130;
    const int Gear4X = Gear2X - 45;
    const int Gear4Y = Gear2Y - 80;
    const int Gear6X = Gear4X - 10;
    const int Gear6Y = Gear4Y - 60;

    // The machine itself
    auto machine = std::make_shared<CWorkingMachine>(2);

    // The base
    auto base = std::make_shared<CShape>();
    int wid = 1000;
    base->Rectangle(-wid / 2, 10, wid, 10);
    base->SetColor(Gdiplus::Color::DarkGray);
    machine->AddComponent(base);

    // Add post that hol the 2nd and 4th gears
    // You can only just barely see the one 
    // for the 4th gear behind the motor and gears
    AddPost(machine, Gear2X, -Gear2Y + 10);
    AddPost(machine, Gear4X, -Gear4Y + 10);
    AddPost(machine, -Gear2X,-Gear2Y + 20);
    AddPost(machine, -Gear4X,-Gear4Y + 50);

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
    motorBase->SetLocation(MotorX, MotorY);
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
    motorRotate->SetSpeed(2);
    machine->AddComponent(motorRotate);

    // The motor
    auto motor1 = std::make_shared<CMotor>();
    motor1->SetLocation(-MotorX, MotorY);
    motor1->CenteredSquare(0);
    mouse->AddMotor(motor1);
    motor1->SetMouse(mouse);
    machine->AddComponent(motor1);

    auto motorBase1 = std::make_shared<CMotorBase>();
    motorBase1->SetLocation(-MotorX, MotorY);
    motorBase1->SetImage(L"images/motor2.png");
    motorBase1->CenteredSquare(100);
    motorBase1->SetMotor(motor1);
    motor1->SetBase(motorBase1);
    machine->AddComponent(motorBase1);

    auto motorRotate1 = std::make_shared<CMotorRotate>();
    motorRotate1->SetLocation(-MotorX, MotorY);
    motorRotate1->SetImage(L"images/shaft.png");
    motorRotate1->CenteredSquare(20);
    motor1->SetRotate(motorRotate1);
    motorRotate1->SetMotor(motor1);
    motorRotate1->SetSpeed(4);
    machine->AddComponent(motorRotate1);

    // The trap
    auto trap = std::make_shared<CTrap>();
    trap->SetLocation(10, -150);
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
    

    // The trap pin
    auto trapPin1 = std::make_shared<CTrapPin>();
    trapPin1->SetInitialPosition(20, -150);
    trapPin1->SetFinalPosition(85, -150);
    trapPin1->SetImage(L"images/trap-pin2.png");
    trapPin1->CenteredSquare(300);
    trapPin1->SetTrap(trap);
    trap->AddPin(trapPin1);
    trapPin1->SetMotor(motor);
    // The trap cage
    auto trapCage = std::make_shared<CTrapCage>();
    trapCage->SetInitialPosition(10, -250);
    trapCage->SetFinalPosition(10, -150);
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
    trapHolder->SetLocation(10, -150);
    trap->SetHolder(trapHolder);
    machine->AddComponent(trapHolder);


    // The winch
    auto winch = std::make_shared<CWinch>();
    winch->SetImage(L"images/drum.png");
    winch->CenteredSquare(80);
    winch->SetRadius(35);
    winch->AddPin(trapPin);
    winch->SetLocation(WinchX, -280 + winch->GetRadius());
    winch->SetTrap(trap);
    winch->SetMotor(motor);
    motor->AddWinch(winch);
    trapPin->SetWinch(winch);
    winch->SetCableEnd(17, -268);

    // The winch
    auto winch1 = std::make_shared<CWinch>();
    winch1->SetImage(L"images/drum.png");
    winch1->CenteredSquare(120);
    winch1->SetRadius(60);
    winch1->AddPin(trapPin1);
    winch1->SetLocation(-WinchX, -340 + winch1->GetRadius());
    winch1->SetTrap(trap);
    winch1->SetMotor(motor);
    trapPin1->SetWinch(winch1);
    motor->AddWinch(winch1);
    winch1->SetCableEnd(-45, -265);

    // The gear driven by the motor
    // Radius=30pixels, 15 teeth
    auto gear1 = std::make_shared<CGear>(40, 25);
    gear1->SetImage(L"images/iron.png");
    gear1->SetLocation(MotorX, MotorY);
    machine->AddComponent(gear1);

    motorRotate->GetSource()->AddSink(gear1->GetSink());

    // The gear driven by the motor
    // Radius=30pixels, 15 teeth
    auto gear1a = std::make_shared<CGear>(40, 25);
    gear1a->SetImage(L"images/iron.png");
    gear1a->SetLocation(-MotorX, MotorY);
    machine->AddComponent(gear1a);

    motorRotate1->GetSource()->AddSink(gear1a->GetSink());

    // The second gear
    // Radius=60pixels, 35 teeth
    auto gear2 = std::make_shared<CGear>(80, 45);
    gear2->SetImage(L"images/hammered-copper.png");
    gear2->SetLocation(Gear2X, Gear2Y);
    gear2->SetAdjust(0.01);

    // We add the post before the gear,
    // so it is behind it.
    machine->AddComponent(gear2);
    gear1->Drive(gear2);

    // The second gear
    // Radius=60pixels, 35 teeth
    auto gear2a = std::make_shared<CGear>(75, 35);
    gear2a->SetImage(L"images/rust.png");
    gear2a->SetLocation(-Gear2X, Gear2Y);
    gear2a->SetAdjust(0.01);

    // We add the post before the gear,
    // so it is behind it.
    machine->AddComponent(gear2a);
    gear1a->Drive(gear2a);

    // A third gear
    auto gear3 = std::make_shared<CGear>(25, 15);
    gear3->SetImage(L"images/steel.png");
    gear3->SetLocation(gear2->GetX(), gear2->GetY());
    machine->AddComponent(gear3);

    // Direct connection
    gear2->GetSource()->AddSink(gear3->GetSink());
    gear3->SetSpeed(gear2->GetSink()->GetSpeed());
    gear3->GetSink()->SetSpeed(gear2->GetSink()->GetSpeed());

    // A third gear
    auto gear3a = std::make_shared<CGear>(20, 57);
    gear3a->SetImage(L"images/iron.png");
    gear3a->SetLocation(gear2a->GetX(), gear2a->GetY());
    machine->AddComponent(gear3a);

    // Direct connection
    gear2a->GetSource()->AddSink(gear3a->GetSink());
    gear3a->SetSpeed(gear2a->GetSink()->GetSpeed());
    gear3a->GetSink()->SetSpeed(gear2a->GetSink()->GetSpeed());


    auto gear4 = std::make_shared<CGear>(70, 50);
    gear4->SetImage(L"images/steel.png");
    gear4->SetLocation(Gear4X, Gear4Y);
    gear4->SetAdjust(0.005);
    machine->AddComponent(gear4);

    gear3->Drive(gear4);

    auto gear4a = std::make_shared<CGear>(75, 50);
    gear4a->SetImage(L"images/steel.png");
    gear4a->SetLocation(-Gear4X, Gear4Y);
    gear4a->SetAdjust(0.005);
    machine->AddComponent(gear4a);

    gear3a->Drive(gear4a);


    // Gear 5: Radius=21pixels, 13 teeth
    auto gear5 = std::make_shared<CGear>(20, 24);
    gear5->SetImage(L"images/iron.png");
    gear5->SetLocation(gear4->GetX(), gear4->GetY());
    machine->AddComponent(gear5);

    // Direct connection
    gear4->GetSource()->AddSink(gear5->GetSink());
    gear5->SetSpeed(gear4->GetSink()->GetSpeed());
    gear5->GetSink()->SetSpeed(gear4->GetSink()->GetSpeed());


    // Gear 5: Radius=21pixels, 13 teeth
    auto gear5a = std::make_shared<CGear>(30, 30);
    gear5a->SetImage(L"images/hammered-copper.png");
    gear5a->SetLocation(gear4a->GetX(), gear4a->GetY());
    machine->AddComponent(gear5a);

    // Direct connection
    gear4a->GetSource()->AddSink(gear5a->GetSink());
    gear5a->SetSpeed(gear4a->GetSink()->GetSpeed());
    gear5a->GetSink()->SetSpeed(gear4a->GetSink()->GetSpeed());

    auto gear6 = std::make_shared<CGear>(80, 80);
    gear6->SetImage(L"images/iron.png");
    gear6->SetLocation(winch->GetX(), winch->GetY());
    gear6->SetAdjust(0.013);
    machine->AddComponent(gear6);

    gear5->Drive(gear6);

    gear6->GetSource()->AddSink(winch->GetSink());
    winch->SetSpeed(gear6->GetSink()->GetSpeed());
    winch->GetSink()->SetSpeed(gear6->GetSink()->GetSpeed());

    auto gear6a = std::make_shared<CGear>(40, 60);
    gear6a->SetImage(L"images/iron.png");
    gear6a->SetLocation(-Gear6X, Gear6Y);
    gear6a->SetAdjust(0.013);
    machine->AddComponent(gear6a);

    gear5a->Drive(gear6a);

    // Gear 5: Radius=21pixels, 13 teeth
    auto gear7 = std::make_shared<CGear>(25, 10);
    gear7->SetImage(L"images/hammered-copper.png");
    gear7->SetLocation(gear6a->GetX(), gear6a->GetY());
    machine->AddComponent(gear7);

    // Direct connection
    gear6a->GetSource()->AddSink(gear7->GetSink());
    gear7->SetSpeed(gear6a->GetSink()->GetSpeed());
    gear7->GetSink()->SetSpeed(gear6a->GetSink()->GetSpeed());

    auto gear8 = std::make_shared<CGear>(80, 80);
    gear8->SetImage(L"images/steel.png");
    gear8->SetLocation(winch1->GetX(), winch1->GetY());
    gear8->SetAdjust(0.013);
    machine->AddComponent(gear8);

    gear7->Drive(gear8);

    gear8->GetSource()->AddSink(winch1->GetSink());
    winch1->SetSpeed(gear8->GetSink()->GetSpeed());
    winch1->GetSink()->SetSpeed(gear8->GetSink()->GetSpeed());

    machine->AddComponent(winch);
    machine->AddComponent(winch1);
    machine->AddComponent(trapPin1);
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

    // Flag that is driven by the winch as it moves
    auto flag1 = std::make_shared<CShape>();
    flag1->AddPoint(0, 0);
    flag1->AddPoint(0, -120);
    flag1->AddPoint(60, -120);
    flag1->AddPoint(60, 0);
    flag1->SetImage(L"images/msu-flag.png");
    flag1->SetLocation(winch1->GetX(), winch1->GetY());
    machine->AddComponent(flag1);
    winch1->GetSource()->AddSink(flag1->GetSink());
    flag1->SetSpeed(winch1->GetSpeed());
    flag1->GetSink()->SetSpeed(winch1->GetSpeed());

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
void CMachine2Factory::AddPost(std::shared_ptr<CWorkingMachine> machine, int x, int height)
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