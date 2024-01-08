#include "person.h"

class Person::PersonImpl // ------- implementation of Bridge. Use to hide stuff inside this class insted of define it in Person class.
{
public:
    void greet(Person *p)
    {
        std::cout << "Hello, I'm " << p->name << std::endl;
    }
};

Person::Person() : impl(new PersonImpl)
{

}

Person::~Person()
{
    delete impl;
}

void Person::greet()
{
    impl->greet(this); // ----- call Bridge implement with pointer to current object
}
