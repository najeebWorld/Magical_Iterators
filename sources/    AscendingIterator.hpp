#ifndef ASCENDINGITERATOR_HPP
#define ASCENDINGITERATOR_HPP

#include "MagicalContainer.hpp"

    class AscendingIterator {
    private:
        const MagicalContainer* container;
        int pos;
    public:
        AscendingIterator();  // Default constructor
        AscendingIterator(const MagicalContainer* c, int p);  // Copy constructor
        ~AscendingIterator();  // Destructor

        AscendingIterator& operator=(const AscendingIterator& other);  // Assignment operator

        bool operator==(const AscendingIterator& other) const;  // Equality comparison
        bool operator!=(const AscendingIterator& other) const;  // Inequality comparison
        bool operator>(const AscendingIterator& other) const;   // GT comparison
        bool operator<(const AscendingIterator& other) const;   // LT comparison

        int operator*() const;  // Dereference operator
        AscendingIterator& operator++();  // Pre-increment operator
    };


#endif // ASCENDINGITERATOR_HPP
