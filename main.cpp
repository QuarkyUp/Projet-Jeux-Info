#include <QApplication>
#include "game.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Game* game = new Game();
    game->generateMap();

    return a.exec();
}
