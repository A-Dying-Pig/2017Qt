#ifndef BATTLEINTERFACEVIEW_H
#define BATTLEINTERFACEVIEW_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include "game_local_logic.h"
#include "cardlibrary.h"
#include <QMouseEvent>
#include <QPaintEvent>
#include <QGraphicsTextItem>
#include <QGraphicsWidget>
#include <QKeyEvent>
#include <QLabel>
#include <QGraphicsProxyWidget>
#define WindowWidth 1200
#define WindowHeight 750


class BattleInterfaceView:public QGraphicsView
{
    Q_OBJECT
public:
    explicit BattleInterfaceView(QWidget *parent = 0);


    Game_Local_Logic* m_logic;
    QGraphicsScene *m_scene;
    QGraphicsWidget *card_intro;
    QLabel *card_intro_label;
    QGraphicsWidget *select_arrow;
    QGraphicsTextItem * card_intro_text;
    QGraphicsTextItem * card_name_text;
    QGraphicsTextItem * time_left;
    QCursor *game_cursor;
    QLabel *turn_label;
    QGraphicsWidget *turn;
    QPixmap *my_turn;
    QPixmap *enemy_turn;

    QGraphicsTextItem *row1_A_strength;
    QGraphicsTextItem *row2_A_strength;
    QGraphicsTextItem *row3_A_strength;
    QGraphicsTextItem *total_A_strength;
    QGraphicsTextItem *row1_B_strength;
    QGraphicsTextItem *row2_B_strength;
    QGraphicsTextItem *row3_B_strength;
    QGraphicsTextItem *total_B_strength;

    bool key_pressed_flag;
    QTimer *key_pressed_timer;

public slots:
    void initialize();
    void round_initialize();
    void init_strength();
    void add_item(Card *);
    void remove_item(Card *);

signals:
    void RoundToSwitch();
    void TurnCardRun();

protected:
    //event
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
private slots:
    void time_left_show();
    void view_update();
    void update_strength();
};

#endif // BATTLEINTERFACEVIEW_H
