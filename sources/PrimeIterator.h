
#ifndef INC_5TASKA_PRIMEITERATOR_H
#define INC_5TASKA_PRIMEITERATOR_H
#include "MagicalContainer.h"


class PrimeIterator {
private:
    std::vector<int> elements;// Store sorted elements
    std::vector<int>::size_type currentIndex; // Track the current index
    bool isPrime(int num);

public:
    //Constructor
    PrimeIterator(const MagicalContainer& container);
    // Default constructor
    PrimeIterator() : currentIndex(0), elements() {}
    //Copy constructor
    PrimeIterator(const PrimeIterator& other);
    //Destructor
    ~PrimeIterator() = default;

    //Operators
    int operator++();
    //    PrimeIterator& operator++();//I was not sure how to implement so I implemented 2 just in case
    int operator*() const;
    bool operator==(const PrimeIterator& other) const;
    bool operator!=(const PrimeIterator& other) const;
    PrimeIterator operator=(const PrimeIterator &primeIter);

    //begin,end
    int * begin();
    int * end();


};


#endif //INC_5TASKA_PRIMEITERATOR_H