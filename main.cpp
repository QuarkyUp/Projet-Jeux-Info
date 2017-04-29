#include <QApplication>

#include "scene.h"
#include "game.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Scene* scene = new Scene();
    Game* game = new Game(scene);

    return a.exec();
}
