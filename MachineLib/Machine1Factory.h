/**
 * \file Machine1Factory.h
 *
 * \author Elizabeth Lipin
 *
 * Class for the factory for the first machine
 */
#pragma once
#include "MachineFactory.h"
#include "WorkingMachine.h"
/**
 * Class for the factory for the first machine
 */
class CMachine1Factory :
    public CMachineFactory
{
public:
    /**create machine one
\return machine*/
    std::shared_ptr<CMachine> CreateMachine();
    /**
 * Add a post
 *
 * \param machine Machine we are adding the post to.
 * \param x X location for the post
 * \param height Height of the post
 */
    void AddPost(std::shared_ptr<CWorkingMachine> machine, int x, int height);
};

