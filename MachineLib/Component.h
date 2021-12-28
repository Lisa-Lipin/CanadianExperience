/**
 * \file Component.h
 *
 * \author Elizabeth Lipin
 *
 * Class for the Components of the machines
 */
#pragma once
#include "Polygon.h"
class CActualMachine;
/**
 * Class for the Components of the machines
 */
class CComponent :
    public CPolygon
{
public:
    /**constructor*/
    CComponent();
    /** \brief Copy constructor disabled */
    CComponent(const CComponent&) = delete;
    /** \brief Assignment operator disabled */
    void operator=(const CComponent&) = delete;
    /**destructor*/
    ~CComponent();
    /**draws the component
    \param graphics to draw with
    \param x coord
    \param y coord*/
    virtual void Draw(Gdiplus::Graphics* graphics, int x, int y);
    /**sets the location
    \param x coord
    \param y coord*/
    void SetLocation(int x, int y);
    /**updates
    \param elapsed time since last update*/
    virtual void Update(double elapsed) = 0;
    /**resets*/
    virtual void Reset() = 0;
    /**Gets x coord
    \return x coord*/
    double GetX() { return mPosition.X; }
    /**Gets y coord
    \return y coord*/
    double GetY() { return mPosition.Y; }

private:
    /// position
    Gdiplus::Point mPosition = Gdiplus::Point(0, 0);
};

