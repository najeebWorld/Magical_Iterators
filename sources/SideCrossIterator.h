
#ifndef INC_5TASKA_SIDECROSSITERATOR_H
#define INC_5TASKA_SIDECROSSITERATOR_H
#include "MagicalContainer.h"


class SideCrossIterator {
private:
    std::vector<int> elements;// Store sorted elements
    std::vector<int>::size_type currentIndex; // Track the current index

public:
    //Constructor
    SideCrossIterator(const MagicalContainer& container);
    // Default constructor
    SideCrossIterator() : currentIndex(0), elements() {}
    //Copy constructor
    SideCrossIterator::SideCrossIterator(const SideCrossIterator& other)
            : currentIndex(other.currentIndex), elements(other.elements)
    {
        // Deep copy the vector
        elements = other.elements;
    }
    //Destructor
    ~SideCrossIterator() = default;
    //Operators
    int operator++();
    //SideCrossIterator& operator++();//I was not sure how to implement so I implemented 2 just in case
    int operator*() const;
    bool operator==(const SideCrossIterator& other) const;
    bool operator!=(const SideCrossIterator& other) const;
    SideCrossIterator operator=(const SideCrossIterator &sideCIter);

    //begin,end
    int * begin();
    int * end();


};


#endif //INC_5TASKA_SIDECROSSITERATOR_H