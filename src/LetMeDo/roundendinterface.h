#ifndef ROUNDENDINTERFACE_H
#define ROUNDENDINTERFACE_H


#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsTextItem>
#include <QGraphicsLineItem>
#include <QTimer>
#include "game_local_logic.h"

#define WindowWidth 1200
#define WindowHeight 750
#define RoundEndShowInterval 2000


class RoundEndInterface:public QGraphicsView
{
    Q_OBJECT

public:

    Game_Local_Logic *m_logic;
    explicit RoundEndInterface(QWidget *parent = 0);
    QGraphicsScene *m_scene;
    QTimer *m_timer;
    QGraphicsTextItem   *result;
    QGraphicsTextItem   *strength_A;
    QGraphicsTextItem   *strength_B;
    QGraphicsTextItem   *name_A;
    QGraphicsTextItem   *name_B;
    QGraphicsLineItem   *line;
    void set_result();
};

#endif // ROUNDENDINTERFACE_H
