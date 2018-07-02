#ifndef SELECTTURNCARD_H
#define SELECTTURNCARD_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsWidget>
#include "game_local_logic.h"
#include <QGraphicsProxyWidget>
#include <QGraphicsTextItem>
#include <QMouseEvent>
#include "mybutton.h"
#define WindowWidth 1200
#define WindowHeight 750


class SelectTurnCard:public QGraphicsView
{
    Q_OBJECT

public:
    QGraphicsScene* m_scene;
    Game_Local_Logic *m_logic;
    explicit SelectTurnCard(QWidget *parent = 0);

    int pass_card_num;
    QGraphicsTextItem *card_name[4];
    QGraphicsTextItem *card_des[4];
protected:
    void paintEvent(QPaintEvent *);
    void wheelEvent(QWheelEvent *);
    void mousePressEvent(QMouseEvent *);
public slots:
    void initialize();
    void restore();
signals:
    void FinishSelect();

};

#endif // SELECTTURNCARD_H
