#include "PlayTttApplication.h"
#include "MainWindow.h"


int main(int argc, char *argv[])
{
    PlayTttApplication a(argc, argv);
    MainWindow w;
    a.start(&w);
//    w.setup();
    w.show();
    return a.exec();
}
