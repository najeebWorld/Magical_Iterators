
#ifndef INC_5TASKA_ASCENDINGITERATOR_H
#define INC_5TASKA_ASCENDINGITERATOR_H

#include "MagicalContainer.h"

class AscendingIterator {

private:
   
    std::vector<int> elements;// Store sorted elements
    
    std::vector<int>::size_type currentIndex; // Track the current index
public:
    
    //Constructor
    AscendingIterator(const MagicalContainer& container);
    // Default constructor
    AscendingIterator() : currentIndex(0), elements() {}
    //Copy constructor
    AscendingIterator(const AscendingIterator& other);
    
    //Destructor
    ~AscendingIterator() = default;

    //Operators
    int operator++();
    //AscendingIterator& operator++(); //I was not sure how to implement so I implemented 2 just in case
    int operator*() const;
    bool operator==(const AscendingIterator& other) const;
    bool operator!=(const AscendingIterator& other) const;
    AscendingIterator operator=(const AscendingIterator &ascIter);

    //begin,end
    int * begin();
    int * end();


};


#endif //INC_5TASKA_ASCENDINGITERATOR_H