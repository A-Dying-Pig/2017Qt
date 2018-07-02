#include <QApplication>
#include "apprun.h"

int main (int argc,char*argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication app(argc,argv);
    AppRun m_game;
    m_game.file_dir = app.applicationDirPath();
    emit m_game.SetDir();
    emit m_game.GameStart();
    return app.exec();

}
