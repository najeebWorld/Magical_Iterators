#include <stdexcept>
#include "doctest.h"
#include "sources/MagicalContainer.h"

#define DOCTEST


using namespace std;


TEST_CASE("Add, Remove and Size with negative numbers"){
    MagicalContainer container;
    CHECK(container.size() == 0);
    container.addElement(-1);//-1
    CHECK(container.size() == 1);
    container.addElement(-2);// -1 -2
    CHECK(container.size() == 2);
    container.removeElement(-2);// -1
    CHECK(container.size() == 1);
    //Add same element
    container.addElement(-1);//-1 -1
    CHECK(container.size() == 2);
    //Remove element that does not exist in the container
    CHECK(container.contains(-2) == false);
    container.removeElement(-2);// Do nothing
    CHECK(container.size() == 2);// -1 -1
    // Remove element appears in few instances")
    container.removeElement(-1);// now the container should be empty
    CHECK(container.size() == 0);
}

TEST_CASE("MagicalContainer contains checks with negative numbers")
{
    MagicalContainer container;
    container.addElement(-1);// -1
    container.addElement(-2);// -1 -2
    CHECK(container.contains(-1) == true);
    CHECK(container.contains(-2) == true);
    CHECK(container.contains(0) == false);
    container.removeElement(-2);//-1
    CHECK(container.size() == 1);
    CHECK(container.contains(-2) == false); //because we removed it
}

TEST_CASE("Iterators with single element containers checks")
{
    MagicalContainer container;
    container.addElement(5);
    
    //AscendingIterator
    AscendingIterator ascIter(container);
    CHECK(ascIter.begin() != ascIter.end());
    CHECK(container.size() == 1);
    //SideCrossIterator
    SideCrossIterator crossIter(container);
    CHECK(crossIter.begin() != crossIter.end());
    CHECK(container.size() == 1);
    //PrimeIterator
    PrimeIterator primeIter(container);
    CHECK(primeIter.begin() != primeIter.end());
    CHECK(container.size() == 1);
}



TEST_CASE("Iterators with single non-prime number") {
    MagicalContainer container;
    CHECK(container.size() == 0);
    
    container.addElement(8);
    CHECK(container.size() == 1);

    PrimeIterator primeIter(container);
    CHECK(primeIter.begin() == primeIter.end());

    // SideCrossIterator
    SideCrossIterator sCrossIter(container);
    CHECK(*sCrossIter.begin() == 8);

    // AscendingIterator
    AscendingIterator ascIter(container);
    CHECK(*ascIter.end() == 8);
    CHECK(*ascIter.begin() == 8);
}

TEST_CASE("Iterators with single prime number") {
    MagicalContainer container;
    CHECK(container.size() == 0);

    container.addElement(7);
    CHECK(container.size() == 1);

    // PrimeIterator
    PrimeIterator primeIter(container);
    CHECK(*primeIter.begin() == 7);

    // SideCrossIterator
    SideCrossIterator sCrossIter(container);
    CHECK(*sCrossIter.begin() == 7);

    // AscendingIterator
    AscendingIterator ascIter(container);
    CHECK(*ascIter.end() == 7);
    CHECK(*ascIter.begin() == 7);
}

TEST_CASE("Iterators with single negative number") {
    MagicalContainer container;
    CHECK(container.size() == 0);

    container.addElement(-5);
    CHECK(container.size() == 1);

    PrimeIterator primeIter(container);
    CHECK(primeIter.begin() == primeIter.end());

    // SideCrossIterator
    SideCrossIterator sCrossIter(container);
    CHECK(*sCrossIter.begin() == -5);

    // AscendingIterator
    AscendingIterator ascIter(container);
    CHECK(*ascIter.end() == -5);
    CHECK(*ascIter.begin() == -5);
}

TEST_CASE("SideCrossIterator mixed odd and even elements") {
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    container.addElement(3);
    container.addElement(4);
    container.addElement(5);
    container.addElement(6);
    container.addElement(7);
    container.addElement(8);
    CHECK(container.size()==8);

    SideCrossIterator crossIter(container);
    std::vector<int> crossOrderElements(crossIter.begin(), crossIter.end());
    CHECK(crossOrderElements == std::vector<int>({1, 8, 2, 7, 3, 6, 4, 5}));

    // Checking operator
    CHECK(crossIter.operator*() == 1);
    CHECK(crossIter.operator++() == 8);
    CHECK(crossIter.operator++() == 2);
    CHECK(crossIter.operator++() == 7);
    CHECK(crossIter.operator++() == 3);
    CHECK(crossIter.operator++() == 6);
    CHECK(crossIter.operator++() == 4);
    CHECK(crossIter.operator++() == 5);
    CHECK_THROWS(crossIter.operator++());
}

TEST_CASE("SideCrossIterator with negative numbers") {
    MagicalContainer container;
    container.addElement(-1);
    container.addElement(-2);
    container.addElement(-3);
    CHECK(container.size()==3);

    SideCrossIterator crossIter(container);
    std::vector<int> crossOrderElements(crossIter.begin(), crossIter.end());
    CHECK(crossOrderElements == std::vector<int>({-1, -3, -2}));
    
    // Checking operator
    CHECK(crossIter.operator*() == -1);
    CHECK(crossIter.operator++() == -3);
    CHECK(crossIter.operator++() == -2);
    CHECK_THROWS(crossIter.operator++());
}

TEST_CASE("SideCrossIterator with single element") {
    MagicalContainer container;
    container.addElement(1);
    CHECK(container.size()==1);

    SideCrossIterator crossIter(container);
    std::vector<int> crossOrderElements(crossIter.begin(), crossIter.end());
    CHECK(crossOrderElements == std::vector<int>({1}));
    
    // Checking operator
    CHECK(crossIter.operator*() == 1);
    CHECK_THROWS(crossIter.operator++());
}



TEST_CASE("Ascending Iterator checks") {
    MagicalContainer elements_;
    elements_.addElement(11);
    elements_.addElement(-1);
    elements_.addElement(13);
    elements_.addElement(4);

    CHECK(elements_.size() == 4);

    AscendingIterator ascIter(elements_);

    std::vector<int> ascendElements(ascIter.begin(), ascIter.end());
    CHECK(ascendElements == std::vector<int>({-1, 4, 11, 13}));

    CHECK(ascIter.operator*() == -1);    
    CHECK(ascIter.operator++() == 4); 
    CHECK(ascIter.operator++() == 11); 
    CHECK(ascIter.operator++() == 13); 
    CHECK_THROWS(ascIter.operator++()); 
}

TEST_CASE("Add, Remove and Size edge cases") {
    MagicalContainer container;
    container.addElement(1);
    CHECK(container.size() == 1);
    container.removeElement(1);
    CHECK(container.size() == 0);
    container.addElement(1);
    CHECK(container.size() == 1);

    container.addElement(2);
    CHECK(container.size() == 2);
    container.removeElement(2);
    CHECK(container.size() == 1);
    container.addElement(2);
    CHECK(container.size() == 2);
}

TEST_CASE("MagicalContainer clear") {
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    container.addElement(3);
    CHECK(container.size() == 3);
    // container.clear();
    CHECK(container.size() == 0);
}

TEST_CASE("Iterators over large container") {
    MagicalContainer container;
    for (int i = 1; i <= 1000; ++i) {
        container.addElement(i);
    }

    AscendingIterator ascIter(container);
    PrimeIterator primeIter(container);
    SideCrossIterator crossIter(container);

    std::vector<int> primeNumbers(primeIter.begin(), primeIter.end());
    CHECK(primeNumbers.size() == 168);

    std::vector<int> ascendingNumbers(ascIter.begin(), ascIter.end());
    CHECK(ascendingNumbers.size() == 1000);

    std::vector<int> crossNumbers(crossIter.begin(), crossIter.end());
    CHECK(crossNumbers.size() == 1000);
}

TEST_CASE("Iterators with large prime numbers") {
    MagicalContainer container;
    container.addElement(7919);
    container.addElement(99371);
    container.addElement(999331);
    CHECK(container.size() == 3);

    PrimeIterator primeIter(container);
    std::vector<int> primeNumbers(primeIter.begin(), primeIter.end());
    CHECK(primeNumbers.size() == 3);
    CHECK(primeNumbers[0] == 7919);
    CHECK(primeNumbers[1] == 99371);
    CHECK(primeNumbers[2] == 999331);
}

TEST_CASE("Iterators with negative numbers") {
    MagicalContainer container;
    container.addElement(-1);
    container.addElement(-2);
    container.addElement(-3);
    CHECK(container.size() == 3);

    AscendingIterator ascIter(container);
    std::vector<int> ascendingNumbers(ascIter.begin(), ascIter.end());
    CHECK(ascendingNumbers.size() == 3);
    CHECK(ascendingNumbers[0] == -3);
    CHECK(ascendingNumbers[1] == -2);
    CHECK(ascendingNumbers[2] == -1);
}

TEST_CASE("Iterators with zero") {
    MagicalContainer container;
    container.addElement(0);
    CHECK(container.size() == 1);

    // AscendingIterator
    AscendingIterator ascIter(container);
    CHECK(*ascIter.begin() == 0);
    CHECK(*ascIter.end() == 0);

    // SideCrossIterator
    SideCrossIterator crossIter(container);
    CHECK(*crossIter.begin() == 0);
    CHECK(*crossIter.end() == 0);

    // PrimeIterator should ignore zero
    PrimeIterator primeIter(container);
    CHECK(primeIter.begin() == primeIter.end());
}
