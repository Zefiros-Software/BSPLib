/**
 * @cond ___LICENSE___
 *
 * Copyright (c) 2016 Koen Visscher, Paul Visscher and individual contributors.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 * @endcond
 */

#pragma once
#ifndef __DISTANCEDBARPLOT_H__
#define __DISTANCEDBARPLOT_H__

#include "plot/abstractPlot.h"
#include "plot/palette.h"

#include <string>
#include <tuple>

class DistancedBarPlot
    : public AbstractPlot
{
public:

    enum class Orientation
    {
        Vertical,
        Horizontal
    };

    DistancedBarPlot( const Vec &x, const Vec &y, const Vec &widths )
    {
        mStream << "plt.bar(" << ToArray( x ) << "," << ToArray( y ) << ",width=" << ToArray( widths );
    }

    DistancedBarPlot( const std::vector< std::pair< Vec, Vec > > &data, const Vec &widths )
    {
        mStream << "x = []\ny = []\n";
        mStream << "x = x ";

        for ( auto & tup : data )
        {
            mStream << "+ " << ToArray( tup.first );
        }

        mStream << "\ny = y ";

        for ( auto & tup : data )
        {
            mStream << "+ " << ToArray( tup.second );
        }

        mStream << "\nplt.bar( x, y" << ",width=" << ToArray( widths );
    }

    // DistancedBarPlot( const std::vector< std::pair< Vec, Vec > > &data, const std::vector< std::string > &hue )
    // {
    //     mStream << "x = []\ny = []\nh = []\n";
    //     mStream << "x = x ";

    //     for ( auto &tup : data )
    //     {
    //         assert( tup.first.GetSize() == tup.second.GetSize() );
    //         mStream << "+ " << ToArray( tup.first );
    //     }

    //     mStream << "\ny = y ";

    //     for ( auto &tup : data )
    //     {
    //         mStream << "+ " << ToArray( tup.second );
    //     }

    //     size_t i = 0;

    //     mStream << "\nh = h ";

    //     for ( auto &tup : data )
    //     {
    //         mStream << "+ " << ToArray( std::vector< std::string >( tup.first.GetSize(), hue[i++] ) );
    //     }

    //     mStream << "\nplt.bar( x, y, h";
    // }

    virtual std::string ToString() const override
    {
        return mStream.str() + " )";
    }

    // DistancedBarPlot &SetOrder( const Vec &order )
    // {
    //     mStream << ", order = " << ToArray( order );
    //     return *this;
    // }

    // DistancedBarPlot &SetHueOrder( const std::vector< std::string > &order )
    // {
    //     mStream << ", hue_order = " << ToArray( order );
    //     return *this;
    // }

    DistancedBarPlot &SetConfidenceInterval( double ci )
    {
        mStream << ", yerr = " << ci;
        return *this;
    }

    // DistancedBarPlot &SetNBoot( size_t bootstrap )
    // {
    //     mStream << ", n_boot = " << bootstrap;
    //     return *this;
    // }

    DistancedBarPlot &SetOrientation( Orientation orientation )
    {
        mStream << ", orientation = " << ( orientation == Orientation::Horizontal ? "'horizontal'" : "'vertical'" );
        return *this;
    }

    DistancedBarPlot &SetColour( const std::string &colour )
    {
        mStream << ", color = '" << colour << "'";
        return *this;
    }
    
    DistancedBarPlot &UseColourCycler( const std::string &colourCycler )
    {
        mStream << ", color = next(" << colourCycler << ")";
        return *this;
    }

    // DistancedBarPlot &SetColourMap( const Palette &pallet )
    // {
    //     mStream << ", palette = " << pallet.ToString();
    //     return *this;
    // }

    // DistancedBarPlot &SetSaturation( double sat )
    // {
    //     mStream << ", saturation = " << sat;
    //     return *this;
    // }

    // DistancedBarPlot &SetErrorColour( const std::string &colour )
    // {
    //     mStream << ", errcolor = '" << colour << "'";
    //     return *this;
    // }

    DistancedBarPlot &CycleColour()
    {
        mStream << ", color = next(colour_cycler)";
        return *this;
    }

private:

    std::stringstream mStream;
};

#endif