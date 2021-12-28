/**
 * \file Source.cpp
 *
 * \author Elizabeth Lipin
 */
#include "pch.h"
#include "Source.h"

/**constructor*/
CSource::CSource()
{
}
/**detructor*/
CSource::~CSource()
{
}
/**add sink
\param sink to add*/
void CSource::AddSink(CSink* sink)
{
	mSink = sink;
}
