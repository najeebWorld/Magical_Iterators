
#ifndef INC_5TASKA_MAGICALCONTAINER_H
#define INC_5TASKA_MAGICALCONTAINER_H
#include <vector>

class AscendingIterator;
class SideCrossIterator;
class PrimeIterator;

class MagicalContainer {

private:
    std::vector<int> elements;
public:
    void addElement(int element);
    void removeElement(int element);
    int size() const;
    const std::vector<int>& getElements() const;//return all elements( because it is private)
    int contains(int number) const;//Check if container contain specific number



};
//Why in the end? because if I put it in the start, the 'AscendingIterator.h' for example use in MagicalContainer and it do not know what is it
#include "AscendingIterator.h"
#include "PrimeIterator.h"
#include "SideCrossIterator.h"

#endif //INC_5TASKA_MAGICALCONTAINER_H