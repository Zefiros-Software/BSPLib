/**
 * Copyright (c) 2015 Mick van Duijn, Koen Visscher and Paul Visscher
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
 */
#pragma once
#ifndef __BSPLIB_REQUESTS_H__
#define __BSPLIB_REQUESTS_H__

#include "bsp/stackAllocator.h"

namespace BspInternal
{
    struct RegisterInfo
    {
        size_t size;
        size_t registerCount;
    };

    struct PutRequest
    {
        StackAllocator::StackLocation bufferLocation;
        //const void *destination;
        size_t globalId;
        ptrdiff_t offset;
        size_t size;
    };

    struct GetRequest
    {
        const void *destination;
        size_t globalId;
        ptrdiff_t offset;
        size_t size;
    };

    struct BufferedGetRequest
    {
        StackAllocator::StackLocation bufferLocation;
        const void *destination;
        size_t size;
    };

    struct SendRequest
    {
        StackAllocator::StackLocation bufferLocation;
        size_t bufferSize;

        StackAllocator::StackLocation tagLocation;
        size_t tagSize;
    };

    struct PushRequest
    {
        const void *pushRegister;
        RegisterInfo registerInfo;
    };

    struct PopRequest
    {
        const void *popRegister;
    };

}

#endif