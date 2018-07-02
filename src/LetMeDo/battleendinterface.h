#ifndef BATTLEENDINTERFACE_H
#define BATTLEENDINTERFACE_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsWidget>
#include "mybutton.h"
#include <QGraphicsTextItem>
#include <QGraphicsLineItem>
#include <QGraphicsProxyWidget>
#include "game_local_logic.h"

#define WindowWidth 1200
#define WindowHeight 750


class BattleEndInterface:public QGraphicsView
{
    Q_OBJECT

public:
    Game_Local_Logic *m_logic;
    explicit BattleEndInterface(QWidget *parent = 0);
    QGraphicsScene* m_scene;
    MyButton *confirm_btn;
    QGraphicsWidget *confirm;

    QGraphicsTextItem   *result;
    QGraphicsTextItem   *strength_A[3];
    QGraphicsTextItem   *strength_B[3];
    QGraphicsTextItem   *name_A;
    QGraphicsTextItem   *name_B;
    QGraphicsLineItem   *line[3];

    void set_result();
};

#endif // BATTLEENDINTERFACE_H
