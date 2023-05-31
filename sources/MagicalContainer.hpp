
#ifndef MAGICALCONTAINER_HPP
#define MAGICALCONTAINER_HPP
#include <vector>

namespace ariel{

class MagicalContainer {

private:

    std::vector<int> elements;

public:

    void addElement(int element);
    void removeElement(int element);
    int size() const;
    const std::vector<int>& getElements() const;//return all elements( because it is private)
    int contains(int number) const;//Check if container contain specific number

    class AscendingIterator
    {
    private:
   
    std::vector<int> elements;// Store sorted elements
    
    std::vector<int>::size_type currentIndex; // Track the current index
    
    public:
    
    //Constructor
    AscendingIterator(const MagicalContainer& container);
    // Default constructor
    AscendingIterator() : currentIndex(0), elements() {}
    //Copy constructor
    AscendingIterator(const AscendingIterator& other);
    
    //Destructor
    ~AscendingIterator() = default;

    //Operators
    int operator++();
    int operator*() const;
    bool operator==(const AscendingIterator& other) const;
    bool operator!=(const AscendingIterator& other) const;
    AscendingIterator& operator=(const AscendingIterator &ascIter);

    //begin,end
    int * begin();
    int * end();
    };
    class SideCrossIterator
    {
        private:
        
        std::vector<int> elements;// Store sorted elements
        std::vector<int>::size_type currentIndex; // Track the current index

        public:
   
        //Constructor
        SideCrossIterator(const MagicalContainer& container);
        // Default constructor
        SideCrossIterator() : currentIndex(0), elements() {}
        //Copy constructor
        SideCrossIterator(const SideCrossIterator& other)
            : currentIndex(other.currentIndex), elements(other.elements)
        {
        // Deep copy the vector
        elements = other.elements;
        }
        //Destructor
        ~SideCrossIterator() = default;
        //Operators
        int operator++();
        int operator*() const;
        bool operator==(const SideCrossIterator& other) const;
        bool operator!=(const SideCrossIterator& other) const;
    SideCrossIterator& operator=(const SideCrossIterator &sideCIter);

        //begin,end
        int * begin();
        int * end();
    };
    class PrimeIterator
    {
       
        private:
        
        std::vector<int> elements;// Store sorted elements
        std::vector<int>::size_type currentIndex; // Track the current index
        bool isPrime(int num);

        public:
    
        //Constructor
        PrimeIterator(const MagicalContainer& container);
        // Default constructor
        PrimeIterator() : currentIndex(0), elements() {}
        //Copy constructor
        PrimeIterator(const PrimeIterator& other);
        //Destructor
        ~PrimeIterator() = default;

        //Operators
        int operator++();
        //    PrimeIterator& operator++();//I was not sure how to implement so I implemented 2 just in case
        int operator*() const;
        bool operator==(const PrimeIterator& other) const;
        bool operator!=(const PrimeIterator& other) const;
        PrimeIterator& operator=(const PrimeIterator &primeIter);

        //begin,end
        int * begin();
        int * end();
    };


};
}

#endif //MAGICALCONTAINER_HPP