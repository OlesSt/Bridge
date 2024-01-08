#include <QCoreApplication>
#include "person.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Person p;
    p.name = "James";
    p.greet();

    return a.exec();
}
