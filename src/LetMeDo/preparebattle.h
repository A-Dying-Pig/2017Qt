#ifndef PREPAREBATTLE_H
#define PREPAREBATTLE_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsWidget>
#include "game_local_logic.h"
#include "mybutton.h"
#include <QGraphicsProxyWidget>
#include <QMouseEvent>
#include <QPaintEvent>
#define WindowWidth 1200
#define WindowHeight 750


class PrepareBattle :public QGraphicsView
{

    Q_OBJECT

public:
    QString file_dir;
    QGraphicsTextItem *show_card_name[4];
    QGraphicsScene *m_scene;
    Game_Local_Logic *m_logic;
    explicit PrepareBattle(QWidget *parent = 0);
    void receiveCard();
    MyButton *confirm_btn;
    QGraphicsWidget *confirm;
    MyButton *back_btn;
    QGraphicsWidget *back;
    QPushButton *m_cards_btn[4];
    QGraphicsWidget *m_cards[4];
    QGraphicsTextItem *side;
    int prepared_num;
    int selected_num;
    void reset();
signals:
    void StartReceive();
    void CardInit();
    void FinishProcess();
public slots:
    void card_initialize();
    void view_initialize();
    void select_1();
    void select_2();
    void select_3();
    void select_4();
};

#endif // PREPAREBATTLE_H
