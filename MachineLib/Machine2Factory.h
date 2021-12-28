/**
 * \file Machine2Factory.h
 *
 * \author Elizabeth Lipin
 *
 * Class for the factory for the second machine
 */
#pragma once
#include "MachineFactory.h"
#include "WorkingMachine.h"
/**
 * Class for the factory for the second machine
 */
class CMachine2Factory :
    public CMachineFactory
{
public:
    /**create machine two
\return machine*/
    std::shared_ptr<CMachine> CreateMachine();
    /**
 * Add a post.
 *
 *
 * \param machine Machine we are adding the post to.
 * \param x X location for the post
 * \param height Height of the post
 */
    void AddPost(std::shared_ptr<CWorkingMachine> machine, int x, int height);
};

