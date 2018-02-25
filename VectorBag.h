/*
Name: Jie Wu
HW2
Due Date: Oct 5th 2017
*/
#ifndef VECTORBAG_H
#define VECTORBAG_H

#include "BagInterface.h"
using namespace std;

template <class ItemType>
class VectorBag
{
    vector<ItemType> bagData;
public:
    VectorBag<ItemType>(){}
    VectorBag<ItemType> (const vector<ItemType>& myData):bagData(myData){}
    VectorBag<ItemType> (const VectorBag<ItemType>& myBag):bagData(myBag.bagData){}
    bool isEmpty() const;
    bool remove(const ItemType &item);
    void clear();
    bool add(ItemType const &item);
    bool contains(const ItemType &item) const;
    vector<ItemType> toVector() const;
    int getCurrentSize() const;
    int getFrequencyOf(const ItemType &item) const;
};
#include "VectorBag.cpp"
#endif
