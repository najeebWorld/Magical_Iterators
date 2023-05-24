#ifndef PRIMEITERATOR_HPP
#define PRIMEITERATOR_HPP

#include "MagicalContainer.hpp"

namespace ariel {
    class PrimeIterator {
    private:
        const MagicalContainer* container;
        int pos;
    public:
        PrimeIterator();  // Default constructor
        PrimeIterator(const MagicalContainer* c, int p);  // Copy constructor
        ~PrimeIterator();  // Destructor

        PrimeIterator& operator=(const PrimeIterator& other);  // Assignment operator

        bool operator==(const PrimeIterator& other) const;  // Equality comparison
        bool operator!=(const PrimeIterator& other) const;  // Inequality comparison
        bool operator>(const PrimeIterator& other) const;   // GT comparison
        bool operator<(const PrimeIterator& other) const;   // LT comparison

        int operator*() const;  // Dereference operator
        PrimeIterator& operator++();  // Pre-increment operator
    };
}

#endif // PRIMEITERATOR_HPP
