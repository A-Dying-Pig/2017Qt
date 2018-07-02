#ifndef WELCOMEINTERFACE_H
#define WELCOMEINTERFACE_H

#include <QGraphicsView>
#include <QGraphicsWidget>
#include <QGraphicsScene>
#include "mybutton.h"
#include <QGraphicsProxyWidget>

#define WindowWidth 1200
#define WindowHeight 750

class WelcomeInterface :public QGraphicsView
{
    Q_OBJECT

public:

    explicit WelcomeInterface(QWidget *parent = 0);

    QGraphicsScene *m_scene;
    MyButton *begin_game_btn;
    MyButton *edit_card_btn;
    QGraphicsWidget *begin_game;
    QGraphicsWidget *edit_card;
};

#endif // WELCOMEINTERFACE_H
