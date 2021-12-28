/**
 * \file Source.h
 *
 * \author Elizabeth Lipin
 *
 * Class for the sounrce
 */
#pragma once
#include "Sink.h"
/**
 * Class for the sounrce
 */
class CSource
{
public:
    /**constructor*/
    CSource();
    /**destructor*/
    ~CSource();
    /// Copy constructor (disabled)
    CSource(const CSource&) = delete;

    /// Assignment operator (disabled)
    void operator=(const CSource&) = delete;
    /**add sink
    \param sink to add*/
    void AddSink(CSink* sink);
    /**rotate*/
    void Rotate() { if (mSink != nullptr) { mSink->Rotate(); } }
private:
    /// sink
    CSink* mSink = nullptr;
};

