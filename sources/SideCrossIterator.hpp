#ifndef SIDECROSSITERATOR_HPP
#define SIDECROSSITERATOR_HPP

#include "MagicalContainer.hpp"

    class SideCrossIterator {
    private:
        const MagicalContainer* container;
        int pos;
    public:
        SideCrossIterator();  // Default constructor
        SideCrossIterator(const MagicalContainer* c, int p);  // Copy constructor
        ~SideCrossIterator();  // Destructor

        SideCrossIterator& operator=(const SideCrossIterator& other);  // Assignment operator

        bool operator==(const SideCrossIterator& other) const;  // Equality comparison
        bool operator!=(const SideCrossIterator& other) const;  // Inequality comparison
        bool operator>(const SideCrossIterator& other) const;   // GT comparison
        bool operator<(const SideCrossIterator& other) const;   // LT comparison

        int operator*() const;  // Dereference operator
        SideCrossIterator& operator++();  // Pre-increment operator
    };


#endif // SIDECROSSITERATOR_HPP
