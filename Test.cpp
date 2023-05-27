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
    CHECK(container.size() == 0);
    container.addElement(1);
    CHECK(container.size() == 1);
    container.addElement(2);
    CHECK(container.size() == 2);
    container.removeElement(2);
    CHECK(container.size() == 1);
    container.addElement(3);
    CHECK(container.size() == 2);
    container.addElement(4);
    CHECK(container.size() == 3);
    container.removeElement(1);
    CHECK(container.size() == 2);
    container.removeElement(3);
    CHECK(container.size() == 1);
    container.removeElement(4);
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



