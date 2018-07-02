#ifndef SWITCHHANDCARD_H
#define SWITCHHANDCARD_H

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


class SwitchHandCard:public QGraphicsView
{
    Q_OBJECT

public:

    //每次重新归零
    int change_time;
    int pass_card_num;
    //
    Game_Local_Logic *m_logic;
    explicit SwitchHandCard(QWidget *parent = 0);
    QGraphicsScene *m_scene;
    MyButton *confirm_btn;
    QGraphicsWidget *confirm;
    int limited_times;

    //card_intro
    QGraphicsTextItem *card_name[4];
    QGraphicsTextItem *card_des[4];

    QGraphicsTextItem *limited_times_num;
    QGraphicsTextItem *have_switched_times;
    //side_info
    QGraphicsTextItem *side;
signals:
    void RestoreHandCard();
    void FinishProcess();
    void Init();
protected:
    void paintEvent(QPaintEvent *);
    void wheelEvent(QWheelEvent *);
    void mousePressEvent(QMouseEvent *);
public slots:
    void initialize();
    void restore_handcard();
};

#endif // SWITCHHANDCARD_H
