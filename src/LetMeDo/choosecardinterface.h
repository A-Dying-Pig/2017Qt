#ifndef CHOOSECARDINTERFACE_H
#define CHOOSECARDINTERFACE_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include "card_local_logic.h"
#include "cardlibrary.h"
#include <QPaintEvent>
#include <QMouseEvent>
#include "mybutton.h"
#include <QLabel>
#include <QGraphicsTextItem>
#include <QGraphicsWidget>
#include <QGraphicsProxyWidget>



class ChooseCardInterface:public QGraphicsView
{
    Q_OBJECT

public:
    QString file_dir;
    explicit ChooseCardInterface(QWidget *parent = 0);
    QGraphicsScene *m_scene;
    Card_Local_Logic *m_logic;
    QGraphicsWidget * all_btn_r;
    QGraphicsWidget * all_btn_l;
    QGraphicsWidget * row_4_btn_r;
    QGraphicsWidget * row_4_btn_l;
    int row4_current_page;
    int row4_newpage_end;
    int all_current_page;
    int all_newpage_end; //end item pointer
    QGraphicsTextItem *total_card;
    QGraphicsTextItem *gold_card;
    QGraphicsTextItem *bronze_card;
    QGraphicsTextItem *silver_card;
    QGraphicsWidget *card_intro;
    QLabel *card_intro_label;
    QGraphicsTextItem * card_intro_text;
    QGraphicsTextItem * card_name_text;

    MyButton *confirm_btn;
    QGraphicsWidget *confirm;
    MyButton *back_btn;
    QGraphicsWidget *back;

protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
public slots:
    void write_ALLCARD();
private slots:
    void row_4_l_down();
    void row_4_r_down();
    void all_btn_l_down();
    void all_btn_r_down();
};

#endif // CHOOSECARDINTERFACE_H
