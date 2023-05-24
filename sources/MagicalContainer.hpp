#ifndef MAGICALCONTAINER_HPP
#define MAGICALCONTAINER_HPP

#include <vector>
using namespace std;

// Forward declaration of the iterators
class AscendingIterator;
class SideCrossIterator;
class PrimeIterator;

class MagicalContainer {
private:
    vector<int> data;
public:
    // changed add to addElement to match the usage in Demo.cpp
    void addElement(int val);

    // changed remove to removeElement to match the usage in Demo.cpp
    void removeElement(int val);

    // no change here
    int size() const;

    // change: AscendingIterator now takes no arguments and returns an object, not a method
    AscendingIterator beginAscending() const;
    AscendingIterator endAscending() const;

    // change: SideCrossIterator now takes no arguments and returns an object, not a method
    SideCrossIterator beginSideCross() const;
    SideCrossIterator endSideCross() const;

    // change: PrimeIterator now takes no arguments and returns an object, not a method
    PrimeIterator beginPrime() const;
    PrimeIterator endPrime() const;

    // Accessor method for iterators to use
    int operator[](int index) const;
};


#endif // MAGICALCONTAINER_HPP