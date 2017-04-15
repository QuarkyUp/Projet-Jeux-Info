#include <QApplication>
#include "scene.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Scene* scene = new Scene();
    scene->start();

    return a.exec();
}
