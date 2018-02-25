/*
Name: Jie Wu
HW2
Due Date: Oct 5th 2017
*/
#include <iostream>
#include "VectorBag.h"
using namespace std;

//Adds two bags and returns the union of the two bags
template <class ItemType>
VectorBag<ItemType> operator+(const VectorBag<ItemType>& first,
                            const VectorBag<ItemType>& second)
{
    vector<ItemType> firstVector = first.toVector(); //first bag
    vector<ItemType> secondVector = second.toVector(); //second bag
    for (int i = 0; i < secondVector.size(); i++)
        firstVector.push_back(secondVector[i]);
    return firstVector;
}
//subtracts the objects in two bags and return the difference
template <class ItemType>
VectorBag<ItemType> operator-(const VectorBag<ItemType>& first,
                            const VectorBag<ItemType>& second)
{
    vector<ItemType> firstVector = first.toVector();
    vector<ItemType> secondVector = second.toVector();
    VectorBag<ItemType> bagDiff(first);
    for (int i = 0; i < secondVector.size(); i++)
        bagDiff.remove(secondVector[i]);
    return bagDiff;
}
//returns the intersection
template <class ItemType>
VectorBag<ItemType> operator*(const VectorBag<ItemType>& first,
                            const VectorBag<ItemType>& second)
{
    return first-(first-second);
}
//test to see if the bag is empty
template <class ItemType>
bool VectorBag<ItemType>::isEmpty() const
{
    return bagData.size() == 0;
}
//removes an entry
template<class ItemType>
bool VectorBag<ItemType>::remove(const ItemType &item)
{
    for (int i = 0; i < bagData.size(); i++)
    {
        if (bagData[i] == item)
        {
            bagData[i] = bagData[bagData.size() - 1];
            bagData.pop_back();
            return true;
        }
    }
    return false;
}
//Tests if the bag contains a given entry
template<class ItemType>
bool VectorBag<ItemType>::contains(const ItemType &item) const
{
    for (int i = 0; i < bagData.size(); i++)
    {
        if (bagData[i] == item)
            return true;
    }
    return false;
}
//add a entry
template <class ItemType>
bool VectorBag<ItemType>::add(ItemType const &item)
{
    bagData.push_back(item);
    return true;
}
//returns all the entries in the bag
template<class ItemType>
vector<ItemType> VectorBag<ItemType>::toVector() const
{
    return bagData;
}
//gets the current number of entries
template<class ItemType>
int VectorBag<ItemType>::getCurrentSize() const
{
    return bagData.size();
}
//count the number of entries
template<class ItemType>
int VectorBag<ItemType>::getFrequencyOf(const ItemType &item) const
{
    int count = 0;
    for (int i = 0; i < bagData.size(); i++)
    {
        if (bagData[i] == item)
            count++;
    }
    return count;
}
//removes all entries
template<class ItemType>
void VectorBag<ItemType>::clear()
{
    bagData.clear();
}

