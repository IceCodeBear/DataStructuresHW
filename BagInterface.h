/*
Name: Jie Wu
HW2
Due Date: Oct 5th 2017
*/

#ifndef BAG_INTERFACE
#define BAG_INTERFACE

#include <vector>
using namespace std;

template<class ItemType>
class BagInterface
{
public:
    //adds a new entry
    virtual bool add(const ItemType& newEntry) = 0;

    //removes an entry
    virtual bool remove(const ItemType& anEntry) = 0;

    //see if a certain entry exist
    virtual bool contains(const ItemType& anEntry) const = 0;

    //removes all the entries
    virtual void clear() = 0;

    //sees whether this bag is empty
    virtual bool isEmpty() const = 0;

    //the number of entries in the bag
    virtual int getCurrentSize() const = 0;

    //gets the number of times a entry appears in the bag
    virtual int getFrequencyOf(const ItemType& anEntry) const = 0;

    // returns a vector with all entries
    virtual vector<ItemType>toVector() const = 0;
};
#endif
