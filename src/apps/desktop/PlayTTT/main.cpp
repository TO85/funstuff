#include "PlayT3Application.h"
#include "MainWindow.h"


int main(int argc, char *argv[])
{
    PlayT3Application a(argc, argv);
    MainWindow w;
    w.setup();
    w.show();
    return a.exec();
}
