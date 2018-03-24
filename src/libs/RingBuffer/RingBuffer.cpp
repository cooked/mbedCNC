//
//  RingBuffer.cpp ... General purpose ring buffer library
//
//  Copyright 2012  Yoji KURODA
//
//  2009.11.13 ... Originally written in C by Y.Kuroda for Renesas H83664
//  2012.08.31 ... Code convert for mbed in C++
//

#include "string.h"
#include "RingBuffer.h"


/*
 *    Machine Independent Area
 */
RingBuffer::RingBuffer(int _bufsize)
:   bufsize(_bufsize)
{
    buf = new unsigned char [bufsize+1];
    sp = ep = buf;
    memset(buf,0,bufsize);
}

RingBuffer::~RingBuffer()
{
    delete [] buf;
}

int
RingBuffer::save(unsigned char c)
{
    mutex.lock();
    if( (ep==sp-1)||
        ((sp==buf)&&
            (ep==buf+bufsize-1)) ) {    /* buffer full */
        mutex.unlock();
        return 0;
    }

    *ep = c;
    ep++;

    if(ep > buf+bufsize)
        ep = buf;

    mutex.unlock();
    return 1;
}

unsigned char
RingBuffer::read(void)
{
    unsigned char ret;

    mutex.lock();
    if(sp == ep){
        mutex.unlock();
        return 0;    /* buffer empty */
    }
    ret = *sp;
    *sp = 0;
    sp++;

    if(sp > buf+bufsize)
        sp = buf;

    mutex.unlock();
    return ret;
}

int
RingBuffer::check(void)
{
    mutex.lock();
    int n = ep-sp;
    if(n<0)
        n = bufsize-n;

    mutex.unlock();
    return n;
}




