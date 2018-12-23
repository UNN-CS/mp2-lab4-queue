//
// Created by rootreddragon on 12/23/2018.
//

#ifndef INC_3LAB_TQUEUE_H
#define INC_3LAB_TQUEUE_H


#include "TStack.h"

    class TQueue : public TStack
    {
    protected:
        int Hi;
        int Li;
        virtual int GetNextIndex(int index);
    public:
        TQueue(int Size = DefMemSize) : TStack(Size), Li(0) {}
        virtual void Put(const TData &);
        virtual TData Get();
        virtual TData GetTopElem();
    };






};


#endif
