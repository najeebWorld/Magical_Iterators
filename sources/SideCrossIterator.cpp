#include "SideCrossIterator.h"
#include <iostream>
#include <cmath>

SideCrossIterator::SideCrossIterator(const MagicalContainer& container) {
    elements = container.getElements();
    currentIndex = 0;
}

int SideCrossIterator::operator++() {
    if (currentIndex / 2 < elements.size()) {
        currentIndex += 2;
        if (currentIndex >= elements.size() && currentIndex % 2 == 0) {
            currentIndex = 1;
        }
        return currentIndex < elements.size() ? elements[currentIndex] : -1;
    } else {
        return -1; // Return -1 or throw an exception if we're at the end.
    }
}

int SideCrossIterator::operator*() const {
    if (currentIndex < elements.size())
        return elements[currentIndex];
    else
        throw std::out_of_range("Iterator is out of range");
}

bool SideCrossIterator::operator==(const SideCrossIterator& other) const {
    return this->elements == other.elements && this->currentIndex == other.currentIndex;
}

bool SideCrossIterator::operator!=(const SideCrossIterator& other) const {
    return !(*this == other);
}

SideCrossIterator SideCrossIterator::operator=(const SideCrossIterator &sideCIter) {
    if (&sideCIter == this)
        return *this;

    this->elements = sideCIter.elements;
    this->currentIndex = sideCIter.currentIndex;

    return *this;
}

int * SideCrossIterator::begin() {
    return elements.data();
}

int * SideCrossIterator::end() {
    return elements.data() + elements.size();
}
