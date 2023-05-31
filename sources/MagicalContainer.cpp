#include "MagicalContainer.hpp"
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace ariel;
using namespace std;



void MagicalContainer::addElement(int element) {
    // Implementation goes here.
}

void MagicalContainer::removeElement(int element) {
    // Implementation goes here.
}

int MagicalContainer::size() const {
    // Implementation goes here.
    return 0; // Placeholder return value.
}

const std::vector<int>& MagicalContainer::getElements() const {
    // Implementation goes here.
    return elements; // Placeholder return value.
}

int MagicalContainer::contains(int number) const {
    // Implementation goes here.
    return 0; // Placeholder return value.
}

//******AscendingIterator*******

MagicalContainer::AscendingIterator::AscendingIterator(const MagicalContainer& container) {
    elements = container.getElements();
    sort(elements.begin(), elements.end());
    currentIndex = 0;
}

MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator& other)
        : currentIndex(other.currentIndex), elements(other.elements)
{
    // Deep copy the vector
    elements = other.elements;
}

int MagicalContainer::AscendingIterator::operator++() {
    if (currentIndex < elements.size()) {
        ++currentIndex;
        return currentIndex < elements.size() ? elements[currentIndex] : -1;
    } else {
        return -1; // Return -1 or throw an exception if we're at the end.
    }
}

int MagicalContainer::AscendingIterator::operator*() const {
    if (currentIndex < elements.size())
        return elements[currentIndex];
    else
        throw std::out_of_range("Iterator is out of range");
}

bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator& other) const {
    return this->elements == other.elements && this->currentIndex == other.currentIndex;
}

bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator& other) const {
    return !(*this == other);
}

MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator=(const AscendingIterator& ascIter) {
    if (&ascIter == this)
        return *this;

    this->elements = ascIter.elements;
    this->currentIndex = ascIter.currentIndex;

    return *this;
}


int* MagicalContainer::AscendingIterator::begin() {
    return elements.data();
}

int* MagicalContainer::AscendingIterator::end() {
    return elements.data() + elements.size();
}

//******PrimeIterator*****

bool MagicalContainer::PrimeIterator::isPrime(int num) {
    if (num <= 1) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;
    for (int i = 3; i * i <= num; i += 2)
        if (num % i == 0)
            return false;
    return true;
}

MagicalContainer::PrimeIterator::PrimeIterator(const MagicalContainer& container) {
    elements = container.getElements();
    currentIndex = 0;
    while (currentIndex < elements.size() && !isPrime(elements[currentIndex]))
        ++currentIndex;
}

int MagicalContainer::PrimeIterator::operator++() {
    if (currentIndex < elements.size()) {
        do {
            ++currentIndex;
        } while (currentIndex < elements.size() && !isPrime(elements[currentIndex]));
    }
    return currentIndex < elements.size() ? elements[currentIndex] : -1;
}

int MagicalContainer::PrimeIterator::operator*() const {
    if (currentIndex < elements.size())
        return elements[currentIndex];
    else
        throw std::out_of_range("Iterator is out of range");
}

bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator& other) const {
    return this->elements == other.elements && this->currentIndex == other.currentIndex;
}

bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator& other) const {
    return !(*this == other);
}

MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator=(const PrimeIterator& primeIter) {
    if (&primeIter == this)
        return *this;

    this->elements = primeIter.elements;
    this->currentIndex = primeIter.currentIndex;

    return *this;
}

MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator& other)
        : currentIndex(other.currentIndex), elements(other.elements)
{
    // Deep copy the vector
    elements = other.elements;
}

int* MagicalContainer::PrimeIterator::begin() {
    return elements.data();
}

int* MagicalContainer::PrimeIterator::end() {
    return elements.data() + elements.size();
}

//******SideCrossIterator********

MagicalContainer::SideCrossIterator::SideCrossIterator(const MagicalContainer& container) {
    elements = container.getElements();
    currentIndex = 0;
}

int MagicalContainer::SideCrossIterator::operator++() {
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

int MagicalContainer::SideCrossIterator::operator*() const {
    if (currentIndex < elements.size())
        return elements[currentIndex];
    else
        throw std::out_of_range("Iterator is out of range");
}

bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator& other) const {
    return this->elements == other.elements && this->currentIndex == other.currentIndex;
}

bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator& other) const {
    return !(*this == other);
}

MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator& sideCIter) {
    if (&sideCIter == this)
        return *this;

    this->elements = sideCIter.elements;
    this->currentIndex = sideCIter.currentIndex;

    return *this;
}


int* MagicalContainer::SideCrossIterator::begin() {
    return elements.data();
}

int* MagicalContainer::SideCrossIterator::end() {
    return elements.data() + elements.size();
}