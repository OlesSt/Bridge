#include <QCoreApplication>
#include "person.h"
#include "BridgeExample.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Person p;
    p.name = "James";
    p.greet();

    runBridge();

    return a.exec();
}
