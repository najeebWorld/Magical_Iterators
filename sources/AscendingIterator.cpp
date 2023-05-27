#include "AscendingIterator.h"
#include <algorithm>
#include <cmath>
#include <iostream>

AscendingIterator::AscendingIterator(const MagicalContainer& container) {
    elements = container.getElements();
    std::sort(elements.begin(), elements.end());
    currentIndex = 0;
}

AscendingIterator::AscendingIterator(const AscendingIterator& other)
        : currentIndex(other.currentIndex), elements(other.elements)
{
    // Deep copy the vector
    elements = other.elements;
}

int AscendingIterator::operator++() {
    if (currentIndex < elements.size()) {
        ++currentIndex;
        return currentIndex < elements.size() ? elements[currentIndex] : -1;
    } else {
        return -1; // Return -1 or throw an exception if we're at the end.
    }
}

int AscendingIterator::operator*() const {
    if (currentIndex < elements.size())
        return elements[currentIndex];
    else
        throw std::out_of_range("Iterator is out of range");
}

bool AscendingIterator::operator==(const AscendingIterator& other) const {
    return this->elements == other.elements && this->currentIndex == other.currentIndex;
}

bool AscendingIterator::operator!=(const AscendingIterator& other) const {
    return !(*this == other);
}

AscendingIterator AscendingIterator::operator=(const AscendingIterator &ascIter) {
    if (&ascIter == this)
        return *this;

    this->elements = ascIter.elements;
    this->currentIndex = ascIter.currentIndex;

    return *this;
}

int * AscendingIterator::begin() {
    return elements.data();
}

int * AscendingIterator::end() {
    return elements.data() + elements.size();
}
