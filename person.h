#ifndef PERSON_H
#define PERSON_H
#include <iostream>

class Person
{
public:
    std::string name;

    class PersonImpl; // ---- Bridge for implementation
    PersonImpl *impl;

    Person();
    ~Person();

    void greet();
};

#endif // PERSON_H
