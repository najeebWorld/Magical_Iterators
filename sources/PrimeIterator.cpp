#include "PrimeIterator.h"
#include <iostream>
#include <cmath>

bool PrimeIterator::isPrime(int num) {
    if (num <= 1) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;
    for (int i = 3; i * i <= num; i += 2)
        if (num % i == 0)
            return false;
    return true;
}

PrimeIterator::PrimeIterator(const MagicalContainer& container) {
    elements = container.getElements();
    currentIndex = 0;
    while (currentIndex < elements.size() && !isPrime(elements[currentIndex]))
        ++currentIndex;
}

int PrimeIterator::operator++() {
    if (currentIndex < elements.size()) {
        do {
            ++currentIndex;
        } while (currentIndex < elements.size() && !isPrime(elements[currentIndex]));
    }
    return currentIndex < elements.size() ? elements[currentIndex] : -1;
}

int PrimeIterator::operator*() const {
    if (currentIndex < elements.size())
        return elements[currentIndex];
    else
        throw std::out_of_range("Iterator is out of range");
}

bool PrimeIterator::operator==(const PrimeIterator& other) const {
    return this->elements == other.elements && this->currentIndex == other.currentIndex;
}

bool PrimeIterator::operator!=(const PrimeIterator& other) const {
    return !(*this == other);
}

PrimeIterator PrimeIterator::operator=(const PrimeIterator &primeIter) {
    if (&primeIter == this)
        return *this;

    this->elements = primeIter.elements;
    this->currentIndex = primeIter.currentIndex;

    return *this;
}
PrimeIterator::PrimeIterator(const PrimeIterator& other)
        : currentIndex(other.currentIndex), elements(other.elements)
{
    // Deep copy the vector
    elements = other.elements;
}

int * PrimeIterator::begin() {
    return elements.data();
}

int * PrimeIterator::end() {
    return elements.data() + elements.size();
}
