#include <iostream>
#include <string>

class ImmutablePair
{
    const int value1;
    const int value2;

public:
    ImmutablePair(int, int);
    const int getValue1();
    const int getValue2();
    ImmutablePair *operator+(ImmutablePair);
};

// See https://stackoverflow.com/questions/14495536/how-to-initialize-const-member-variable-in-a-class
/*
This is called using initializer list in the constructor function:
constructor (arglist) : initialization-section
{
    assignment-section
}
*/
ImmutablePair ::ImmutablePair(int value1, int value2) : value1(value1), value2(value2)
{
    std::cout << "Constructor invoked" << std::endl;
}

const int ImmutablePair ::getValue1()
{
    return value1;
}

const int ImmutablePair ::getValue2()
{
    return value2;
}

ImmutablePair *ImmutablePair ::operator+(ImmutablePair pair)
{
    return new ImmutablePair(pair.getValue1() + this->value1, pair.getValue2() + this->value2);
}

int main()
{

    ImmutablePair pair(10, 12);
    ImmutablePair pair2(13, 24);
    ImmutablePair *pair3 = pair + pair2;

    std::cout << pair3->getValue1() << " " << pair3->getValue2() << "\n";

    return 0;
}