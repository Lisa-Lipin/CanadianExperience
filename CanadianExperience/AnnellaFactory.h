/**
 * \file AnnellaFactory.h
 *
 * \author Lisa Lipin
 *
 *   Factory class that builds the Annella character
 */
#pragma once
#include "ActorFactory.h"
#include <memory>
class CActor;
/**
 *   Factory class that builds the Annella character
 */
class CAnnellaFactory :
    public CActorFactory
{
public:
    std::shared_ptr<CActor> Create();
};



