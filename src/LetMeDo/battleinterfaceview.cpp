#include "battleinterfaceview.h"
#include <QGraphicsView>
#include <QPropertyAnimation>
#include <QDebug>
#include <QList>
#define CardIntroLabelWidth 237
#define CardIntroLabelHeight 280
#define SelectArrowLabelWidth 30
#define SelectArrowLabelHeight 30
#define TurnLabelWidth      120
#define TurnLabelHeight     120

BattleInterfaceView::BattleInterfaceView(QWidget *parent):
    QGraphicsView(parent)
{
    m_scene = new QGraphicsScene;
    m_scene ->setSceneRect(0,0,WindowWidth,WindowHeight);

    //key_pressed
    key_pressed_flag = false;
    key_pressed_timer = new QTimer(this);
    key_pressed_timer->setInterval(3000);

    //card_intro
    setMouseTracking(true);
    card_intro_label = new QLabel;
    card_intro = new QGraphicsWidget;
    card_intro_label->move(942,135);
    card_intro_label->resize(CardIntroLabelWidth,CardIntroLabelHeight);
    card_intro_label->setAttribute(Qt::WA_TranslucentBackground);
    card_intro_label->setScaledContents(true);
    card_intro = m_scene->addWidget(card_intro_label);
    card_intro_text = new QGraphicsTextItem;
    card_intro_text->setPos(990,435);
    card_intro_text->setTextWidth(165);
    card_intro_text->setFont(QFont(0,11));
    card_intro_text->setDefaultTextColor(QColor(172,174,176));
    m_scene->addItem(card_intro_text);
    card_name_text = new QGraphicsTextItem;
    card_name_text->setPos(990,395);
    card_name_text->setFont(QFont(0,18));
    card_name_text->setTextWidth(250);
    card_name_text->setDefaultTextColor(QColor(172,174,176));
    m_scene->addItem(card_name_text);

    //turn_info
    turn_label = new QLabel;
    turn = new QGraphicsWidget;
    turn_label -> move(70,330);
    turn_label->setAttribute(Qt::WA_TranslucentBackground);
    turn_label->setScaledContents(true);
    turn = m_scene->addWidget(turn_label);
    my_turn = new QPixmap(":/images/Widgets/my_turn.png");
    enemy_turn = new QPixmap (":/images/Widgets/enemy_turn.png");


    //connect(m_logic,SIGNAL(UpdateStrength()),this,SLOT(update_strength()));

    //time_left
    time_left = new QGraphicsTextItem;
    time_left->setPos(990,580);
    time_left->setFont(QFont(0,17));
    time_left->setTextWidth(250);
    time_left->setDefaultTextColor(QColor(172,174,176));
    m_scene->addItem(time_left);

    //setBackground
    QPixmap *bkg = new QPixmap(":/images/Background/game_1.png");
    setAutoFillBackground(true);
    QPixmap nbkg = bkg->scaled(QSize(WindowWidth,WindowHeight));
    setBackgroundBrush(nbkg);

    //setScene
    setScene(m_scene);
    resize(WindowWidth,WindowHeight);

}

void BattleInterfaceView::init_strength()
{
    //strength_info
    if (m_logic->paint_side)
    {
    row1_A_strength = new QGraphicsTextItem;
    row1_A_strength->setPos(275,402);
    row1_A_strength->setFont(QFont(0,20));
    row1_A_strength->setTextWidth(50);
    row1_A_strength->setDefaultTextColor(QColor(172,174,176));
    row1_A_strength->setPlainText("0");
    m_scene->addItem( row1_A_strength);

    row2_A_strength = new QGraphicsTextItem;
    row2_A_strength->setPos(275,475);
    row2_A_strength->setFont(QFont(0,20));
    row2_A_strength->setTextWidth(50);
    row2_A_strength->setDefaultTextColor(QColor(172,174,176));
    row2_A_strength->setPlainText("0");
    m_scene->addItem( row2_A_strength);

    row3_A_strength = new QGraphicsTextItem;
    row3_A_strength->setPos(275,547);
    row3_A_strength->setFont(QFont(0,20));
    row3_A_strength->setTextWidth(50);
    row3_A_strength->setDefaultTextColor(QColor(172,174,176));
    row3_A_strength->setPlainText("0");
    m_scene->addItem( row3_A_strength);

    total_A_strength = new QGraphicsTextItem;
    total_A_strength->setPos(170,470);
    total_A_strength->setFont(QFont(0,35));
    total_A_strength->setTextWidth(100);
    total_A_strength->setDefaultTextColor(QColor(254,209,0));
    total_A_strength->setPlainText("0");
    m_scene->addItem( total_A_strength);

    row1_B_strength = new QGraphicsTextItem;
    row1_B_strength->setPos(275,310);
    row1_B_strength->setFont(QFont(0,20));
    row1_B_strength->setTextWidth(50);
    row1_B_strength->setDefaultTextColor(QColor(172,174,176));
    row1_B_strength->setPlainText("0");
    m_scene->addItem( row1_B_strength);

    row2_B_strength = new QGraphicsTextItem;
    row2_B_strength->setPos(275,238);
    row2_B_strength->setFont(QFont(0,20));
    row2_B_strength->setTextWidth(50);
    row2_B_strength->setDefaultTextColor(QColor(172,174,176));
    row2_B_strength->setPlainText("0");
    m_scene->addItem( row2_B_strength);

    row3_B_strength = new QGraphicsTextItem;
    row3_B_strength->setPos(275,166);
    row3_B_strength->setFont(QFont(0,20));
    row3_B_strength->setTextWidth(50);
    row3_B_strength->setDefaultTextColor(QColor(172,174,176));
    row3_B_strength->setPlainText("0");
    m_scene->addItem( row3_B_strength);

    total_B_strength = new QGraphicsTextItem;
    total_B_strength->setPos(170,230);
    total_B_strength->setFont(QFont(0,35));
    total_B_strength->setTextWidth(100);
    total_B_strength->setDefaultTextColor(QColor(254,209,0));
    total_B_strength->setPlainText("0");
    m_scene->addItem( total_B_strength);
    }
    else
    {
        row1_B_strength = new QGraphicsTextItem;
        row1_B_strength->setPos(275,402);
        row1_B_strength->setFont(QFont(0,20));
        row1_B_strength->setTextWidth(50);
        row1_B_strength->setDefaultTextColor(QColor(172,174,176));
        row1_B_strength->setPlainText("0");
        m_scene->addItem( row1_B_strength);

        row2_B_strength = new QGraphicsTextItem;
        row2_B_strength->setPos(275,475);
        row2_B_strength->setFont(QFont(0,20));
        row2_B_strength->setTextWidth(50);
        row2_B_strength->setDefaultTextColor(QColor(172,174,176));
        row2_B_strength->setPlainText("0");
        m_scene->addItem( row2_B_strength);

        row3_B_strength = new QGraphicsTextItem;
        row3_B_strength->setPos(275,547);
        row3_B_strength->setFont(QFont(0,20));
        row3_B_strength->setTextWidth(50);
        row3_B_strength->setDefaultTextColor(QColor(172,174,176));
        row3_B_strength->setPlainText("0");
        m_scene->addItem( row3_B_strength);

        total_B_strength = new QGraphicsTextItem;
        total_B_strength->setPos(170,470);
        total_B_strength->setFont(QFont(0,35));
        total_B_strength->setTextWidth(100);
        total_B_strength->setDefaultTextColor(QColor(254,209,0));
        total_B_strength->setPlainText("0");
        m_scene->addItem( total_B_strength);

        row1_A_strength = new QGraphicsTextItem;
        row1_A_strength->setPos(275,310);
        row1_A_strength->setFont(QFont(0,20));
        row1_A_strength->setTextWidth(50);
        row1_A_strength->setDefaultTextColor(QColor(172,174,176));
        row1_A_strength->setPlainText("0");
        m_scene->addItem( row1_A_strength);

        row2_A_strength = new QGraphicsTextItem;
        row2_A_strength->setPos(275,238);
        row2_A_strength->setFont(QFont(0,20));
        row2_A_strength->setTextWidth(50);
        row2_A_strength->setDefaultTextColor(QColor(172,174,176));
        row2_A_strength->setPlainText("0");
        m_scene->addItem( row2_A_strength);

        row3_A_strength = new QGraphicsTextItem;
        row3_A_strength->setPos(275,166);
        row3_A_strength->setFont(QFont(0,20));
        row3_A_strength->setTextWidth(50);
        row3_A_strength->setDefaultTextColor(QColor(172,174,176));
        row3_A_strength->setPlainText("0");
        m_scene->addItem( row3_A_strength);

        total_A_strength = new QGraphicsTextItem;
        total_A_strength->setPos(170,230);
        total_A_strength->setFont(QFont(0,35));
        total_A_strength->setTextWidth(100);
        total_A_strength->setDefaultTextColor(QColor(254,209,0));
        total_A_strength->setPlainText("0");
        m_scene->addItem( total_A_strength);
    }

}

void BattleInterfaceView::mousePressEvent(QMouseEvent *event)
{
    QGraphicsView::mousePressEvent(event);
    if (m_logic->stage == -2)
           return;
    QPoint viewPos = event->pos();
    QPointF scenePos = mapToScene(viewPos);
    QGraphicsItem *selected = scene()->itemAt(scenePos,QTransform());

    QGraphicsItem *right_itm = NULL;
    Card* right;
    QPointF rightPos;
    rightPos.setX(scenePos.x() +  PixmapWidth-5);
    rightPos.setY(scenePos.y());
    right_itm = scene()->itemAt(rightPos,QTransform());
    if (right_itm == card_intro
            || right_itm == card_intro_text
            || right_itm == card_name_text
            || right_itm== time_left
            || right_itm == row1_A_strength ||right_itm == row2_A_strength ||right_itm == row3_A_strength
            || right_itm == row1_B_strength ||right_itm == row2_B_strength ||right_itm == row3_B_strength
            || right_itm == total_A_strength ||right_itm == total_B_strength
            || right_itm == turn)
    right_itm=NULL;
    right = static_cast<Card*> (right_itm);


    if ( selected == card_intro
        || selected == card_intro_text
        || selected == card_name_text
        || selected == time_left
        || selected == row1_A_strength ||selected == row2_A_strength ||selected == row3_A_strength
        || selected == row1_B_strength ||selected == row2_B_strength ||selected == row3_B_strength
        || selected == total_A_strength ||selected == total_B_strength
        || selected == turn
        )
        return;

    if (m_logic->order ==true)
    {
        qreal scenePosY = scenePos.y();
        Card* selected_card = static_cast<Card*>(selected);


        if (m_logic->stage == 1&& m_logic->turn_card->loyality&&scenePosY < 620 && scenePosY >380)
        {
            if(m_logic->turn_card->stand_position == 1 && scenePosY<=455)
                    {
                        m_logic->turn_card->stand_row = 1;
                        if(right == NULL)
                            m_logic->row_1_A.push_back(m_logic->turn_card);
                        else
                            m_logic->row_1_A.insert(m_logic->row_1_A.indexOf(right),m_logic->turn_card);
                        m_logic->stage = 3;
                    }
            else if (m_logic->turn_card->stand_position == 2 && scenePosY<=530 && scenePosY>455)
                    {
                        m_logic->turn_card->stand_row = 2;
                        if(right == NULL)
                            m_logic->row_2_A.push_back(m_logic->turn_card);
                        else
                            m_logic->row_2_A.insert(m_logic->row_2_A.indexOf(right),m_logic->turn_card);
                        m_logic->stage = 3;
                    }
            else if (m_logic->turn_card->stand_position ==3  && scenePosY <=620 && scenePosY>530)
                    {
                         m_logic->turn_card->stand_row = 3;
                         if(right == NULL)
                             m_logic->row_3_A.push_back(m_logic->turn_card);
                         else
                             m_logic->row_3_A.insert(m_logic->row_3_A.indexOf(right),m_logic->turn_card);
                         m_logic->stage = 3;
                    }
            else if (m_logic->turn_card->stand_position ==4)
            {
                if(scenePosY<=455)
                    {
                    if(right == NULL)
                        m_logic->row_1_A.push_back(m_logic->turn_card);
                    else
                        m_logic->row_1_A.insert(m_logic->row_1_A.indexOf(right),m_logic->turn_card);
                        m_logic->turn_card->stand_row = 1;
                        m_logic->stage = 3;
                    }
                else if (scenePosY<=530)
                    {
                    if(right == NULL)
                        m_logic->row_2_A.push_back(m_logic->turn_card);
                    else
                        m_logic->row_2_A.insert(m_logic->row_2_A.indexOf(right),m_logic->turn_card);
                        m_logic->turn_card->stand_row = 2;
                        m_logic->stage = 3;
                     }
                else if (scenePosY <=620)
                     {
                    if(right == NULL)
                        m_logic->row_3_A.push_back(m_logic->turn_card);
                    else
                        m_logic->row_3_A.insert(m_logic->row_3_A.indexOf(right),m_logic->turn_card);
                        m_logic->turn_card->stand_row = 3;
                        m_logic->stage = 3;
                     }
            }
            if (m_logic->turn_card->is_choosing_enemy == -1 && m_logic->turn_card->is_choosing_row == -1
                    && m_logic->stage == 3)
                m_logic->stage = -1;
            else if (m_logic->turn_card->is_choosing_enemy == -1 && m_logic->turn_card->is_choosing_row != -1
                     &&m_logic->stage == 3)
                m_logic->stage = 5;

            else if (m_logic->turn_card->is_choosing_enemy != -1 && m_logic->stage == 3)
            {
                 if(m_logic->row_1_A.isEmpty()&&m_logic->row_2_A.isEmpty()&&m_logic->row_3_A.isEmpty()
                    &&m_logic->row_1_B.isEmpty()&&m_logic->row_2_B.isEmpty()&&m_logic->row_3_B.isEmpty())
                    m_logic->stage = -1;
                 else if (m_logic->turn_card->is_choosing_enemy == 0
                         && m_logic->row_1_B.isEmpty() && m_logic->row_2_B.isEmpty()&&m_logic->row_3_B.isEmpty())
                     m_logic->stage = -1;
                 else if (m_logic->turn_card->is_choosing_enemy == 1
                          && m_logic->row_1_A.isEmpty() && m_logic->row_2_A.isEmpty()&&m_logic->row_3_A.isEmpty())
                      m_logic->stage = -1;
            }
        }

            if (m_logic->stage == 1&& !m_logic->turn_card->loyality&&scenePosY < 380 && scenePosY >145)
            {
                if(m_logic->turn_card->stand_position == 1 && scenePosY>290)
                        {
                            m_logic->turn_card->stand_row = 4;
                            if(right == NULL)
                                m_logic->row_1_B.push_back(m_logic->turn_card);
                            else
                                m_logic->row_1_B.insert(m_logic->row_1_B.indexOf(right),m_logic->turn_card);
                            m_logic->stage = 3;

                        }
                else if (m_logic->turn_card->stand_position == 2 && scenePosY<=290 && scenePosY>215)
                        {
                            m_logic->turn_card->stand_row = 5;
                            if(right == NULL)
                                m_logic->row_2_B.push_back(m_logic->turn_card);
                            else
                                m_logic->row_2_B.insert(m_logic->row_2_B.indexOf(right),m_logic->turn_card);
                            m_logic->stage = 3;
                        }
                else if (m_logic->turn_card->stand_position ==3  && scenePosY <=215 && scenePosY>145)
                        {
                             m_logic->turn_card->stand_row = 6;
                             if(right == NULL)
                                 m_logic->row_3_B.push_back(m_logic->turn_card);
                             else
                                 m_logic->row_3_B.insert(m_logic->row_3_B.indexOf(right),m_logic->turn_card);
                             m_logic->stage = 3;
                        }
                else if (m_logic->turn_card->stand_position ==4)
                {
                    if(scenePosY>=290)
                        {
                        if(right == NULL)
                            m_logic->row_1_B.push_back(m_logic->turn_card);
                        else
                            m_logic->row_1_B.insert(m_logic->row_1_B.indexOf(right),m_logic->turn_card);
                            m_logic->turn_card->stand_row = 4;
                            m_logic->stage = 3;
                        }
                    else if (scenePosY>=215)
                        {
                        if(right == NULL)
                            m_logic->row_2_B.push_back(m_logic->turn_card);
                        else
                            m_logic->row_2_B.insert(m_logic->row_2_B.indexOf(right),m_logic->turn_card);
                            m_logic->turn_card->stand_row = 5;
                            m_logic->stage = 3;
                         }
                    else if (scenePosY >=145)
                         {
                        if(right == NULL)
                            m_logic->row_3_B.push_back(m_logic->turn_card);
                        else
                            m_logic->row_3_B.insert(m_logic->row_3_B.indexOf(right),m_logic->turn_card);
                            m_logic->turn_card->stand_row = 6;
                            m_logic->stage = 3;
                         }
                }

            if (m_logic->turn_card->is_choosing_enemy == -1 && m_logic->turn_card->is_choosing_row == -1
                    && m_logic->stage == 3)
                m_logic->stage = -1;

            else if (m_logic->turn_card->is_choosing_enemy == -1 && m_logic->turn_card->is_choosing_row != -1
                     &&m_logic->stage == 3)
                m_logic->stage = 5;

            else if (m_logic->turn_card->is_choosing_enemy != -1 && m_logic->stage == 3)
            {
                 if(m_logic->row_1_A.isEmpty()&&m_logic->row_2_A.isEmpty()&&m_logic->row_3_A.isEmpty()
                    &&m_logic->row_1_B.isEmpty()&&m_logic->row_2_B.isEmpty()&&m_logic->row_3_B.isEmpty())
                    m_logic->stage = -1;
                 else if (m_logic->turn_card->is_choosing_enemy == 0
                         && m_logic->row_1_B.isEmpty() && m_logic->row_2_B.isEmpty()&&m_logic->row_3_B.isEmpty())
                     m_logic->stage = -1;
                 else if (m_logic->turn_card->is_choosing_enemy == 1
                          && m_logic->row_1_A.isEmpty() && m_logic->row_2_A.isEmpty()&&m_logic->row_3_A.isEmpty())
                      m_logic->stage = -1;

            }
        }

        else if (m_logic->stage == 3)
        {        
            if (m_logic->have_selected < m_logic->turn_card->select_num)
            {
                if(m_logic->turn_card->is_choosing_enemy == 0)
              {
                 if((m_logic->row_1_B.contains(selected_card)||m_logic->row_2_B.contains(selected_card)
                            ||m_logic->row_3_B.contains(selected_card))&& selected_card !=NULL
                         && !m_logic->turn_card->target.contains(selected_card))
                 {
                      m_logic->have_selected++;
                      m_logic->turn_card->target.push_back(selected_card);
                 }
              }

               else if (m_logic->turn_card->is_choosing_enemy == 1)
              {
                 if((m_logic->row_1_A.contains(selected_card)||m_logic->row_2_A.contains(selected_card)
                           ||m_logic->row_3_A.contains(selected_card)) && selected_card !=NULL
                         && !m_logic->turn_card->target.contains(selected_card))
                 {
                     m_logic->have_selected++;
                     m_logic->turn_card->target.push_back(selected_card);
                 }
              }
                else if (m_logic->turn_card->is_choosing_enemy == 2)
                {
                   if(selected_card != NULL && !m_logic->turn_card->target.contains(selected_card))
                   {
                       m_logic->have_selected++;
                       m_logic->turn_card->target.push_back(selected_card);
                    }
                }
            }

             if (m_logic->have_selected == m_logic->turn_card->select_num)
                  m_logic->stage = -2;

             else if (m_logic->turn_card->is_choosing_enemy == 0 && m_logic->have_selected ==
                      m_logic->row_1_B.size()+ m_logic->row_2_B.size()+m_logic->row_3_B.size())
                  m_logic->stage = -2;

             else if (m_logic->turn_card->is_choosing_enemy == 1 && m_logic->have_selected ==
                      m_logic->row_1_A.size()+ m_logic->row_2_A.size()+m_logic->row_3_A.size() -1)
                  m_logic->stage = -2;

             else if (m_logic->turn_card->is_choosing_enemy == 2 && m_logic->have_selected ==
                      m_logic->row_1_A.size()+ m_logic->row_2_A.size()+m_logic->row_3_A.size()
                      +m_logic->row_1_B.size()+m_logic->row_2_B.size()+m_logic->row_3_B.size() -1)
                  m_logic->stage = -2;

             emit TurnCardRun();

        }

        else if (m_logic->stage == 5)
        {
            if (m_logic->turn_card->is_choosing_row == 2 && scenePosY > 145)
            {
                if(scenePosY<215)
                    {
                    m_logic->turn_card->target = m_logic->row_3_B;
                    m_logic->turn_card->effect_row = 3;
                    }
                else if (scenePosY<290)
                    {
                    m_logic->turn_card->target = m_logic->row_2_B;
                    m_logic->turn_card->effect_row = 2;
                    }
                else if (scenePosY<380)
                    {
                    m_logic->turn_card->target = m_logic->row_1_B;
                    m_logic->turn_card->effect_row = 1;
                    }
                else if (scenePosY<455)
                    {
                    m_logic->turn_card->target = m_logic->row_1_A;
                    m_logic->turn_card->effect_row = 4;
                    }
                else if (scenePosY<530)
                    {
                    m_logic->turn_card->target = m_logic->row_2_A;
                    m_logic->turn_card->effect_row = 5;
                    }
                else if (scenePosY<620)
                    {
                    m_logic->turn_card->target = m_logic->row_3_A;
                    m_logic->turn_card->effect_row = 6;
                    }
            }
            else if (m_logic->turn_card->is_choosing_row == 1 && scenePosY > 380)
                {
                  if (scenePosY<455)
                     {
                      m_logic->turn_card->target = m_logic->row_1_A;
                      m_logic->turn_card->effect_row = 4;
                      }
                  else if (scenePosY<530)
                      {
                      m_logic->turn_card->target = m_logic->row_2_A;
                      m_logic->turn_card->effect_row = 5;
                      }
                   else if (scenePosY<620)
                      {
                      m_logic->turn_card->target = m_logic->row_3_A;
                      m_logic->turn_card->effect_row = 6;
                      }

            else if (m_logic->turn_card->is_choosing_row == 0 && scenePosY > 145)
                {
                  if (scenePosY<215)
                     {
                      m_logic->turn_card->target = m_logic->row_3_B;
                      m_logic->turn_card->effect_row = 3;
                      }
                  else if (scenePosY<290)
                      {
                      m_logic->turn_card->target = m_logic->row_2_B;
                      m_logic->turn_card->effect_row = 2;
                      }
                   else if (scenePosY<380)
                      {
                      m_logic->turn_card->target = m_logic->row_1_B;
                      m_logic->turn_card->effect_row = 1;
                      }
                }
            }
            m_logic->stage = -1;
        }

        else if( (m_logic->stage == 0||m_logic->stage==1||m_logic->stage==2)&&m_logic->hand_A.contains(selected_card))
        {
            m_logic->stage = 0;
            if (selected_card ->is_attendent)
                m_logic->stage = 1;
            else
                m_logic->stage = 2;
            m_logic->turn_card = selected_card;
        }

        else if (m_logic->stage == 2 && m_logic->turn_card->is_choosing_enemy!= -1)
        {
            if(m_logic->row_1_A.isEmpty()&&m_logic->row_2_A.isEmpty()&&m_logic->row_3_A.isEmpty()
               &&m_logic->row_1_B.isEmpty()&&m_logic->row_2_B.isEmpty()&&m_logic->row_3_B.isEmpty())
               m_logic->stage = -1;
            else if (m_logic->turn_card->is_choosing_enemy == 0
                    && m_logic->row_1_B.isEmpty() && m_logic->row_2_B.isEmpty()&&m_logic->row_3_B.isEmpty())
                m_logic->stage = -1;
            else if (m_logic->turn_card->is_choosing_enemy == 1
                     && m_logic->row_1_A.isEmpty() && m_logic->row_2_A.isEmpty()&&m_logic->row_3_A.isEmpty())
                 m_logic->stage = -1;

            if (m_logic->have_selected < m_logic->turn_card->select_num)
            {
                if(m_logic->turn_card->is_choosing_enemy == 0)
              {
                 if((m_logic->row_1_B.contains(selected_card)||m_logic->row_2_B.contains(selected_card)
                            ||m_logic->row_3_B.contains(selected_card))&& selected_card != NULL)
                 {
                      m_logic->have_selected++;
                      m_logic->turn_card->target.push_back(selected_card);
                 }
              }

               else if (m_logic->turn_card->is_choosing_enemy == 1)
              {
                 if((m_logic->row_1_A.contains(selected_card)||m_logic->row_2_A.contains(selected_card)
                           ||m_logic->row_3_A.contains(selected_card))&& selected_card!= NULL)
                 {
                      m_logic->have_selected++;
                      m_logic->turn_card->target.push_back(selected_card);
                 }
              }
                else if (m_logic->turn_card->is_choosing_enemy == 2)
                {
                   if(selected_card != NULL)
                   {
                       m_logic->have_selected++;
                       m_logic->turn_card->target.push_back(selected_card);
                    }
                }
            }
            if (m_logic->have_selected == m_logic->turn_card->select_num)
                        m_logic->stage = -1;
        }
        else if (m_logic->stage == 2 && m_logic->turn_card->is_choosing_enemy== -1)
        {
            if(m_logic->turn_card->is_choosing_row == 2 && scenePosY>145)
            {
                if(scenePosY<215)
                {
                    m_logic->turn_card->target = m_logic->row_3_B;
                    if (m_logic->turn_card->is_weather)
                        m_logic->row_3_B.push_back(m_logic->turn_card);
                    m_logic->turn_card->effect_row = 3;
                }
                else if (scenePosY<290)
                {
                    m_logic->turn_card->target = m_logic->row_2_B;
                    if (m_logic->turn_card->is_weather)
                        m_logic->row_2_B.push_back(m_logic->turn_card);
                    m_logic->turn_card->effect_row = 2;
                }
                else if (scenePosY<380)
                {
                    m_logic->turn_card->target = m_logic->row_1_B;
                    if (m_logic->turn_card->is_weather)
                        m_logic->row_1_B.push_back(m_logic->turn_card);
                    m_logic->turn_card->effect_row = 1;
                }
                else if (scenePosY<455)
                {
                    m_logic->turn_card->target = m_logic->row_1_A;
                    if (m_logic->turn_card->is_weather)
                         m_logic->row_1_A.push_back(m_logic->turn_card);
                    m_logic->turn_card->effect_row = 4;
                }
                else if (scenePosY<530)
                {
                    m_logic->turn_card->target = m_logic->row_2_A;
                    if (m_logic->turn_card->is_weather)
                        m_logic->row_2_A.push_back(m_logic->turn_card);
                    m_logic->turn_card->effect_row = 5;
                }
                else if (scenePosY<620)
                {
                    m_logic->turn_card->target = m_logic->row_3_A;
                    if (m_logic->turn_card->is_weather)
                        m_logic->row_3_A.push_back(m_logic->turn_card);
                    m_logic->turn_card->effect_row = 6;
                }
            }
            else if(m_logic->turn_card->is_choosing_row == 0 && scenePosY>145)
            {
                if(scenePosY<215)
              {
                 m_logic->turn_card->target = m_logic->row_3_B;
                 if (m_logic->turn_card->is_weather)
                    m_logic->row_3_B.push_back(m_logic->turn_card);
                 m_logic->turn_card->effect_row = 3;
                 }
                 else if (scenePosY<290)
                 {
                 m_logic->turn_card->target = m_logic->row_2_B;
                 if (m_logic->turn_card->is_weather)
                    m_logic->row_2_B.push_back(m_logic->turn_card);
                 m_logic->turn_card->effect_row = 2;
                    }
                    else if (scenePosY<380)
                    {
                    m_logic->turn_card->target = m_logic->row_1_B;
                    if (m_logic->turn_card->is_weather)
                        m_logic->row_1_B.push_back(m_logic->turn_card);
                     m_logic->turn_card->effect_row = 1;
                     }
                }
            else if(m_logic->turn_card->is_choosing_row == 1 && scenePosY>380)
            {
                if(scenePosY<455)
              {
                 m_logic->turn_card->target = m_logic->row_1_A;
                 if (m_logic->turn_card->is_weather)
                    m_logic->row_3_B.push_back(m_logic->turn_card);
                 m_logic->turn_card->effect_row = 4;
                 }
                 else if (scenePosY<530)
                 {
                 m_logic->turn_card->target = m_logic->row_2_A;
                 if (m_logic->turn_card->is_weather)
                    m_logic->row_2_B.push_back(m_logic->turn_card);
                 m_logic->turn_card->effect_row = 5;
                  }
                 else if (scenePosY<620)
                  {
                    m_logic->turn_card->target = m_logic->row_3_A;
                    if (m_logic->turn_card->is_weather)
                        m_logic->row_1_B.push_back(m_logic->turn_card);
                    m_logic->turn_card->effect_row = 6;
                   }
                }

            m_logic->stage = -1;
         }
                this->viewport()->update();
                if (m_logic->stage==-1)
             {
               if (!m_logic->turn_card->is_attendent)
                   m_scene->removeItem(m_logic->turn_card);
               m_logic->hand_A.removeOne(m_logic->turn_card);
               m_logic->stage = -2;
               this->viewport()->update();
               emit m_logic->TurnProcess();
             }
     }

    else
    {
            qreal scenePosY = scenePos.y();
            Card* selected_card = static_cast<Card*>(selected);


            if (m_logic->stage == 1&& !m_logic->turn_card->loyality&&scenePosY < 620 && scenePosY >380)
            {
                if(m_logic->turn_card->stand_position == 1 && scenePosY<=455)
                        {
                            m_logic->turn_card->stand_row = 4;
                            if(right == NULL)
                                m_logic->row_1_A.push_back(m_logic->turn_card);
                            else
                                m_logic->row_1_A.insert(m_logic->row_1_A.indexOf(right),m_logic->turn_card);
                            m_logic->stage = 3;
                        }
                else if (m_logic->turn_card->stand_position == 2 && scenePosY<=530 && scenePosY>455)
                        {
                            m_logic->turn_card->stand_row = 5;
                            if(right == NULL)
                                m_logic->row_2_A.push_back(m_logic->turn_card);
                            else
                                m_logic->row_2_A.insert(m_logic->row_2_A.indexOf(right),m_logic->turn_card);
                            m_logic->stage = 3;
                        }
                else if (m_logic->turn_card->stand_position ==3  && scenePosY <=620 && scenePosY>530)
                        {
                             m_logic->turn_card->stand_row = 6;
                             if(right == NULL)
                                 m_logic->row_3_A.push_back(m_logic->turn_card);
                             else
                                 m_logic->row_3_A.insert(m_logic->row_3_A.indexOf(right),m_logic->turn_card);
                             m_logic->stage = 3;
                        }
                else if (m_logic->turn_card->stand_position ==4)
                {
                    if(scenePosY<=455)
                        {
                        if(right == NULL)
                            m_logic->row_1_A.push_back(m_logic->turn_card);
                        else
                            m_logic->row_1_A.insert(m_logic->row_1_A.indexOf(right),m_logic->turn_card);
                            m_logic->turn_card->stand_row = 4;
                            m_logic->stage = 3;
                        }
                    else if (scenePosY<=530)
                        {
                        if(right == NULL)
                            m_logic->row_2_A.push_back(m_logic->turn_card);
                        else
                            m_logic->row_2_A.insert(m_logic->row_2_A.indexOf(right),m_logic->turn_card);
                            m_logic->turn_card->stand_row = 5;
                            m_logic->stage = 3;
                         }
                    else if (scenePosY <=620)
                         {
                        if(right == NULL)
                            m_logic->row_3_A.push_back(m_logic->turn_card);
                        else
                            m_logic->row_3_A.insert(m_logic->row_3_A.indexOf(right),m_logic->turn_card);
                            m_logic->turn_card->stand_row = 6;
                            m_logic->stage = 3;
                         }
                }
                if (m_logic->turn_card->is_choosing_enemy == -1 && m_logic->turn_card->is_choosing_row == -1
                        && m_logic->stage == 3)
                    m_logic->stage = -1;
                else if (m_logic->turn_card->is_choosing_enemy == -1 && m_logic->turn_card->is_choosing_row != -1
                         &&m_logic->stage == 3)
                    m_logic->stage = 5;
                else if (m_logic->turn_card->is_choosing_enemy != -1 && m_logic->stage == 3)
                {
                     if(m_logic->row_1_A.isEmpty()&&m_logic->row_2_A.isEmpty()&&m_logic->row_3_A.isEmpty()
                        &&m_logic->row_1_B.isEmpty()&&m_logic->row_2_B.isEmpty()&&m_logic->row_3_B.isEmpty())
                        m_logic->stage = -1;
                     else if (m_logic->turn_card->is_choosing_enemy == 0
                             && m_logic->row_1_A.isEmpty() && m_logic->row_2_A.isEmpty()&&m_logic->row_3_A.isEmpty())
                         m_logic->stage = -1;
                     else if (m_logic->turn_card->is_choosing_enemy == 1
                              && m_logic->row_1_B.isEmpty() && m_logic->row_2_B.isEmpty()&&m_logic->row_3_B.isEmpty())
                          m_logic->stage = -1;


                }
            }

                if (m_logic->stage == 1&& m_logic->turn_card->loyality&&scenePosY < 380 && scenePosY >145)
                {
                    if(m_logic->turn_card->stand_position == 1 && scenePosY>290)
                            {
                                m_logic->turn_card->stand_row = 1;
                                if(right == NULL)
                                    m_logic->row_1_B.push_back(m_logic->turn_card);
                                else
                                    m_logic->row_1_B.insert(m_logic->row_1_B.indexOf(right),m_logic->turn_card);
                                m_logic->stage = 3;
                            }
                    else if (m_logic->turn_card->stand_position == 2 && scenePosY<=290 && scenePosY>215)
                            {
                                m_logic->turn_card->stand_row = 2;
                                if(right == NULL)
                                    m_logic->row_2_B.push_back(m_logic->turn_card);
                                else
                                    m_logic->row_2_B.insert(m_logic->row_2_B.indexOf(right),m_logic->turn_card);
                                m_logic->stage = 3;
                            }
                    else if (m_logic->turn_card->stand_position ==3  && scenePosY <=215 && scenePosY>145)
                            {
                                 m_logic->turn_card->stand_row = 3;
                                 if(right == NULL)
                                     m_logic->row_3_B.push_back(m_logic->turn_card);
                                 else
                                     m_logic->row_3_B.insert(m_logic->row_3_B.indexOf(right),m_logic->turn_card);
                                 m_logic->stage = 3;
                            }
                    else if (m_logic->turn_card->stand_position ==4)
                    {
                        if(scenePosY>=290)
                            {
                            if(right == NULL)
                                m_logic->row_1_B.push_back(m_logic->turn_card);
                            else
                                m_logic->row_1_B.insert(m_logic->row_1_B.indexOf(right),m_logic->turn_card);
                                m_logic->turn_card->stand_row = 1;
                                m_logic->stage = 3;
                            }
                        else if (scenePosY>=215)
                            {
                            if(right == NULL)
                                m_logic->row_2_B.push_back(m_logic->turn_card);
                            else
                                m_logic->row_2_B.insert(m_logic->row_2_B.indexOf(right),m_logic->turn_card);
                                m_logic->turn_card->stand_row = 2;
                                m_logic->stage = 3;
                             }
                        else if (scenePosY >=145)
                             {
                            if(right == NULL)
                                m_logic->row_3_B.push_back(m_logic->turn_card);
                            else
                                m_logic->row_3_B.insert(m_logic->row_3_B.indexOf(right),m_logic->turn_card);
                                m_logic->turn_card->stand_row = 3;
                                m_logic->stage = 3;
                             }
                    }

                if (m_logic->turn_card->is_choosing_enemy == -1 && m_logic->turn_card->is_choosing_row == -1
                        && m_logic->stage == 3)
                    m_logic->stage = -1;
                else if (m_logic->turn_card->is_choosing_enemy == -1 && m_logic->turn_card->is_choosing_row != -1
                         &&m_logic->stage == 3)
                    m_logic->stage = 5;
                else if (m_logic->turn_card->is_choosing_enemy != -1 && m_logic->stage == 3)
                {
                     if(m_logic->row_1_A.isEmpty()&&m_logic->row_2_A.isEmpty()&&m_logic->row_3_A.isEmpty()
                        &&m_logic->row_1_B.isEmpty()&&m_logic->row_2_B.isEmpty()&&m_logic->row_3_B.isEmpty())
                        m_logic->stage = -1;
                     else if (m_logic->turn_card->is_choosing_enemy == 0
                             && m_logic->row_1_A.isEmpty() && m_logic->row_2_A.isEmpty()&&m_logic->row_3_A.isEmpty())
                         m_logic->stage = -1;
                     else if (m_logic->turn_card->is_choosing_enemy == 1
                              && m_logic->row_1_B.isEmpty() && m_logic->row_2_B.isEmpty()&&m_logic->row_3_B.isEmpty())
                          m_logic->stage = -1;


                }
            }

            else if (m_logic->stage == 3)
            {
                if (m_logic->have_selected < m_logic->turn_card->select_num)
                {
                    if(m_logic->turn_card->is_choosing_enemy == 0)
                  {
                     if((m_logic->row_1_A.contains(selected_card)||m_logic->row_2_A.contains(selected_card)
                                ||m_logic->row_3_A.contains(selected_card))&& selected_card !=NULL
                             && !m_logic->turn_card->target.contains(selected_card))
                     {
                          m_logic->have_selected++;
                          m_logic->turn_card->target.push_back(selected_card);
                     }
                  }

                   else if (m_logic->turn_card->is_choosing_enemy == 1)
                  {
                     if((m_logic->row_1_B.contains(selected_card)||m_logic->row_2_B.contains(selected_card)
                               ||m_logic->row_3_B.contains(selected_card)) && selected_card !=NULL
                             && !m_logic->turn_card->target.contains(selected_card))
                     {
                         m_logic->have_selected++;
                         m_logic->turn_card->target.push_back(selected_card);
                     }
                  }
                    else if (m_logic->turn_card->is_choosing_enemy == 2)
                    {
                       if(selected_card != NULL && !m_logic->turn_card->target.contains(selected_card))
                       {
                           m_logic->have_selected++;
                           m_logic->turn_card->target.push_back(selected_card);
                        }
                    }
                }

                 if (m_logic->have_selected == m_logic->turn_card->select_num)
                         m_logic->stage = -2;

                 else if (m_logic->turn_card->is_choosing_enemy == 0 && m_logic->have_selected ==
                          m_logic->row_1_A.size()+ m_logic->row_2_A.size()+m_logic->row_3_A.size() )

                         m_logic->stage = -2;

                 else if (m_logic->turn_card->is_choosing_enemy == 1 && m_logic->have_selected ==
                          m_logic->row_1_B.size()+ m_logic->row_2_B.size()+m_logic->row_3_B.size() -1)

                         m_logic->stage = -2;

                 else if (m_logic->turn_card->is_choosing_enemy == 2 && m_logic->have_selected ==
                          m_logic->row_1_A.size()+ m_logic->row_2_A.size()+m_logic->row_3_A.size()
                          +m_logic->row_1_B.size()+m_logic->row_2_B.size()+m_logic->row_3_B.size() -1)

                         m_logic->stage = -2;

                emit TurnCardRun();
            }

            else if (m_logic->stage == 5)
            {
                if (m_logic->turn_card->is_choosing_row == 2 && scenePosY > 145)
                {
                    if(scenePosY<215)
                        {
                        m_logic->turn_card->target = m_logic->row_3_B;
                        m_logic->turn_card->effect_row = 6;
                        }
                    else if (scenePosY<290)
                        {
                        m_logic->turn_card->target = m_logic->row_2_B;
                        m_logic->turn_card->effect_row = 5;
                        }
                    else if (scenePosY<380)
                        {
                        m_logic->turn_card->target = m_logic->row_1_B;
                        m_logic->turn_card->effect_row = 4;
                        }
                    else if (scenePosY<455)
                        {
                        m_logic->turn_card->target = m_logic->row_1_A;
                        m_logic->turn_card->effect_row = 1;
                        }
                    else if (scenePosY<530)
                        {
                        m_logic->turn_card->target = m_logic->row_2_A;
                        m_logic->turn_card->effect_row = 2;
                        }
                    else if (scenePosY<620)
                        {
                        m_logic->turn_card->target = m_logic->row_3_A;
                        m_logic->turn_card->effect_row = 3;
                        }
                }
                else if (m_logic->turn_card->is_choosing_row == 0 && scenePosY > 380)
                    {
                      if (scenePosY<455)
                         {
                          m_logic->turn_card->target = m_logic->row_1_A;
                          m_logic->turn_card->effect_row = 1;
                          }
                      else if (scenePosY<530)
                          {
                          m_logic->turn_card->target = m_logic->row_2_A;
                          m_logic->turn_card->effect_row = 2;
                          }
                       else if (scenePosY<620)
                          {
                          m_logic->turn_card->target = m_logic->row_3_A;
                          m_logic->turn_card->effect_row = 3;
                          }

                else if (m_logic->turn_card->is_choosing_row == 1 && scenePosY > 145)
                    {
                      if (scenePosY<215)
                         {
                          m_logic->turn_card->target = m_logic->row_3_B;
                          m_logic->turn_card->effect_row = 6;
                          }
                      else if (scenePosY<290)
                          {
                          m_logic->turn_card->target = m_logic->row_2_B;
                          m_logic->turn_card->effect_row = 5;
                          }
                       else if (scenePosY<380)
                          {
                          m_logic->turn_card->target = m_logic->row_1_B;
                          m_logic->turn_card->effect_row = 4;
                          }
                    }
                }
                m_logic->stage = -1;
            }

            else if( (m_logic->stage == 0||m_logic->stage==1||m_logic->stage==2)&&m_logic->hand_B.contains(selected_card))
            {
                m_logic->stage = 0;
                if (selected_card ->is_attendent)
                    m_logic->stage = 1;
                else
                    m_logic->stage = 2;
                m_logic->turn_card = selected_card;
            }

            else if (m_logic->stage == 2 && m_logic->turn_card->is_choosing_enemy!= -1)
            {
                if(m_logic->row_1_A.isEmpty()&&m_logic->row_2_A.isEmpty()&&m_logic->row_3_A.isEmpty()
                   &&m_logic->row_1_B.isEmpty()&&m_logic->row_2_B.isEmpty()&&m_logic->row_3_B.isEmpty())
                   m_logic->stage = -1;
                else if (m_logic->turn_card->is_choosing_enemy == 0
                        && m_logic->row_1_A.isEmpty() && m_logic->row_2_A.isEmpty()&&m_logic->row_3_A.isEmpty())
                    m_logic->stage = -1;
                else if (m_logic->turn_card->is_choosing_enemy == 1
                         && m_logic->row_1_B.isEmpty() && m_logic->row_2_B.isEmpty()&&m_logic->row_3_B.isEmpty())
                     m_logic->stage = -1;

                if (m_logic->have_selected < m_logic->turn_card->select_num)
                {
                    if(m_logic->turn_card->is_choosing_enemy == 0)
                  {
                     if((m_logic->row_1_A.contains(selected_card)||m_logic->row_2_A.contains(selected_card)
                                ||m_logic->row_3_A.contains(selected_card))&& selected_card != NULL)
                     {
                          m_logic->have_selected++;
                          m_logic->turn_card->target.push_back(selected_card);
                     }
                  }

                   else if (m_logic->turn_card->is_choosing_enemy == 1)
                  {
                     if((m_logic->row_1_B.contains(selected_card)||m_logic->row_2_B.contains(selected_card)
                               ||m_logic->row_3_B.contains(selected_card))&& selected_card!= NULL)
                     {
                          m_logic->have_selected++;
                          m_logic->turn_card->target.push_back(selected_card);
                     }
                  }
                    else if (m_logic->turn_card->is_choosing_enemy == 2)
                    {
                       if(selected_card != NULL)
                       {
                           m_logic->have_selected++;
                           m_logic->turn_card->target.push_back(selected_card);
                        }
                    }
                }
                if (m_logic->have_selected == m_logic->turn_card->select_num)
                            m_logic->stage = -1;
            }
            else if (m_logic->stage == 2 && m_logic->turn_card->is_choosing_enemy== -1)
            {
                if(m_logic->turn_card->is_choosing_row == 2 && scenePosY>145)
                {
                    if(scenePosY<215)
                    {
                        m_logic->turn_card->target = m_logic->row_3_B;
                        if (m_logic->turn_card->is_weather)
                            m_logic->row_3_B.push_back(m_logic->turn_card);
                        m_logic->turn_card->effect_row = 6;
                    }
                    else if (scenePosY<290)
                    {
                        m_logic->turn_card->target = m_logic->row_2_B;
                        if (m_logic->turn_card->is_weather)
                            m_logic->row_2_B.push_back(m_logic->turn_card);
                        m_logic->turn_card->effect_row = 5;
                    }
                    else if (scenePosY<380)
                    {
                        m_logic->turn_card->target = m_logic->row_1_B;
                        if (m_logic->turn_card->is_weather)
                            m_logic->row_1_B.push_back(m_logic->turn_card);
                        m_logic->turn_card->effect_row = 4;
                    }
                    else if (scenePosY<455)
                    {
                        m_logic->turn_card->target = m_logic->row_1_A;
                        if (m_logic->turn_card->is_weather)
                             m_logic->row_1_A.push_back(m_logic->turn_card);
                        m_logic->turn_card->effect_row = 1;
                    }
                    else if (scenePosY<530)
                    {
                        m_logic->turn_card->target = m_logic->row_2_A;
                        if (m_logic->turn_card->is_weather)
                            m_logic->row_2_A.push_back(m_logic->turn_card);
                        m_logic->turn_card->effect_row = 2;
                    }
                    else if (scenePosY<620)
                    {
                        m_logic->turn_card->target = m_logic->row_3_A;
                        if (m_logic->turn_card->is_weather)
                            m_logic->row_3_A.push_back(m_logic->turn_card);
                        m_logic->turn_card->effect_row = 3;
                    }
                }
                else if(m_logic->turn_card->is_choosing_row == 1 && scenePosY>145)
                {
                    if(scenePosY<215)
                  {
                     m_logic->turn_card->target = m_logic->row_3_B;
                     if (m_logic->turn_card->is_weather)
                        m_logic->row_3_B.push_back(m_logic->turn_card);
                     m_logic->turn_card->effect_row = 6;
                     }
                     else if (scenePosY<290)
                     {
                     m_logic->turn_card->target = m_logic->row_2_B;
                     if (m_logic->turn_card->is_weather)
                        m_logic->row_2_B.push_back(m_logic->turn_card);
                     m_logic->turn_card->effect_row = 5;
                        }
                        else if (scenePosY<380)
                        {
                        m_logic->turn_card->target = m_logic->row_1_B;
                        if (m_logic->turn_card->is_weather)
                            m_logic->row_1_B.push_back(m_logic->turn_card);
                         m_logic->turn_card->effect_row = 4;
                         }
                    }
                else if(m_logic->turn_card->is_choosing_row == 0 && scenePosY>380)
                {
                    if(scenePosY<455)
                  {
                     m_logic->turn_card->target = m_logic->row_1_A;
                     if (m_logic->turn_card->is_weather)
                        m_logic->row_3_B.push_back(m_logic->turn_card);
                     m_logic->turn_card->effect_row = 1;
                     }
                     else if (scenePosY<530)
                     {
                     m_logic->turn_card->target = m_logic->row_2_A;
                     if (m_logic->turn_card->is_weather)
                        m_logic->row_2_B.push_back(m_logic->turn_card);
                     m_logic->turn_card->effect_row = 2;
                      }
                     else if (scenePosY<620)
                      {
                        m_logic->turn_card->target = m_logic->row_3_A;
                        if (m_logic->turn_card->is_weather)
                            m_logic->row_1_B.push_back(m_logic->turn_card);
                        m_logic->turn_card->effect_row = 3;
                       }
                    }

                m_logic->stage = -1;
             }
                    this->viewport()->update();
                    if (m_logic->stage==-1)
                 {
                   if (!m_logic->turn_card->is_attendent)
                       m_scene->removeItem(m_logic->turn_card);
                   m_logic->hand_B.removeOne(m_logic->turn_card);
                   m_logic->stage = -2;
                   this->viewport()->update();
                   emit m_logic->TurnProcess();
                 }
         }




}


void BattleInterfaceView::paintEvent(QPaintEvent *event)
{

        if (m_logic->order)
        {
           turn_label->setPixmap(*(my_turn));
           turn_label ->resize (TurnLabelWidth,TurnLabelHeight);
        }
        else
        {
            turn_label ->setPixmap (*enemy_turn);
            turn_label ->resize (TurnLabelWidth,TurnLabelHeight);
        }

        int hand_number = m_logic->hand_A.size();
        for (int i = 0;i < hand_number;i++ )
        {
            m_logic->hand_A[i]->setPos(250+i*70,620);
        }

        int row_1_A_number = m_logic->row_1_A.size();
        for (int i= 0,j=0;i< row_1_A_number;i++)
                if (m_logic->row_1_A[i]->is_attendent)
                {
                    m_logic->row_1_A[i]->setPos(440+j*70,380);
                    j++;
                 }

        int row_2_A_number = m_logic->row_2_A.size();
        for (int i= 0,j=0;i < row_2_A_number;i++)
             if (m_logic->row_2_A[i]->is_attendent)
               {
                 m_logic->row_2_A[i]->setPos(440+j*70,455);
                 j++;
               }

        int row_3_A_number = m_logic->row_3_A.size();
        for (int i= 0,j=0;i < row_3_A_number;i++)
            if (m_logic->row_3_A[i]->is_attendent)
              {
                m_logic->row_3_A[i]->setPos(440+j*70,530);
                j++;
              }

        hand_number = m_logic->hand_B.size();
        for (int i = 0;i < hand_number;i++ )
        {
            m_logic->hand_B[i]->setPos(250+i*70,40);
        }

        int row_1_B_number = m_logic->row_1_B.size();
        for (int i= 0,j=0;i< row_1_B_number;i++)
            if (m_logic->row_1_B[i]->is_attendent)
              {
                m_logic->row_1_B[i]->setPos(440+j*70,290);
                j++;
              }

        int row_2_B_number = m_logic->row_2_B.size();
        for (int i= 0,j=0;i < row_2_B_number;i++)
            if (m_logic->row_2_B[i]->is_attendent)
               {
                m_logic->row_2_B[i]->setPos(440+j*70,215);
                j++;
                }

        int row_3_B_number = m_logic->row_3_B.size();
        for (int i= 0,j=0;i < row_3_B_number;i++)
            if (m_logic->row_3_B[i]->is_attendent)
            {
                m_logic->row_3_B[i]->setPos(440+j*70,145);
                j++;
             }
        QGraphicsView::paintEvent(event);
}

void BattleInterfaceView::mouseMoveEvent(QMouseEvent *event)
{
    QPoint viewPos = event->pos();
    QPointF scenePos = mapToScene(viewPos);
    QGraphicsItem *selected = scene()->itemAt(scenePos,QTransform());

    if ( selected == card_intro
        || selected == card_intro_text
        || selected == card_name_text
        || selected == time_left
        || selected == turn
        || selected == row1_A_strength ||selected == row2_A_strength ||selected == row3_A_strength
        || selected == row1_B_strength ||selected == row2_B_strength ||selected == row3_B_strength
        || selected == total_A_strength ||selected == total_B_strength
        || selected ==NULL) return;

    Card* selected_card = static_cast<Card*>(selected);
    if (selected_card->show_front)
   {
        card_intro_label->setPixmap(*(selected_card->pix));
        card_intro_text->setPlainText(selected_card->description);
        card_name_text->setPlainText(selected_card->card_name);
   }
    else
    {
        QPixmap p = *(selected_card->back);
        card_intro_label->setPixmap(p);
        card_intro_text->setPlainText(NULL);
        card_name_text->setPlainText(NULL);
    }

    if (m_logic->stage ==3 || m_logic->stage == 2 ||m_logic->stage ==5)
    {
        setCursor(Qt::PointingHandCursor);
    }
    else
    {
        setCursor(Qt::ArrowCursor);
    }

}

void BattleInterfaceView::time_left_show()
{
    m_logic->time_past ++;
    time_left->setPlainText(QString("回合剩余时间: %1").arg(30 - m_logic->time_past));
}

void BattleInterfaceView::keyPressEvent(QKeyEvent *event)
{
    if (m_logic->stage == -2)
           return;
    if (m_logic->order)
    {
        switch(event->key())
      {
          case Qt::Key_Space:
                             if (!event->isAutoRepeat()&&!key_pressed_flag)
                         {
                              key_pressed_flag = true;
                              key_pressed_timer->start();
                         }
                          break;
      }
        QGraphicsView::keyPressEvent(event);
    }
    else if (!m_logic->order)
    {
        switch(event->key())
      {
          case Qt::Key_Space:
                             if (!event->isAutoRepeat()&&!key_pressed_flag)
                         {
                              key_pressed_flag = true;
                              key_pressed_timer->start();
                         }
                          break;
      }
        QGraphicsView::keyPressEvent(event);
    }
}

void BattleInterfaceView::keyReleaseEvent(QKeyEvent *event)
{

    switch(event->key())
         {
             case Qt::Key_Space:  if (!event->isAutoRepeat()&&key_pressed_flag)
                                 {
                                    key_pressed_flag = false;
                                    key_pressed_timer->stop();
                                  }
                                   break;
        }
         QGraphicsView::keyReleaseEvent(event);
}

void BattleInterfaceView::view_update()
{
    this->viewport()->update();
}

void BattleInterfaceView::update_strength()
{
    row1_A_strength ->setPlainText(QString::number(m_logic->A_row1_strength));
    row2_A_strength ->setPlainText(QString::number(m_logic->A_row2_strength));
    row3_A_strength ->setPlainText(QString::number(m_logic->A_row3_strength));
    total_A_strength ->setPlainText(QString::number(m_logic->A_total_strength));

    row1_B_strength ->setPlainText(QString::number(m_logic->B_row1_strength));
    row2_B_strength ->setPlainText(QString::number(m_logic->B_row2_strength));
    row3_B_strength ->setPlainText(QString::number(m_logic->B_row3_strength));
    total_B_strength ->setPlainText(QString::number(m_logic->B_total_strength));
}


void BattleInterfaceView::initialize ()
{
    key_pressed_flag = false;

    if (m_logic->order)
    {
         foreach(Card* i,m_logic->hand_A)
         {
             m_scene->addItem(i);
         }
         foreach(Card* i,m_logic->hand_B)
         {
             i->show_front = false;
             m_scene->addItem(i);
         }
    }

    else
    {
        foreach(Card* i,m_logic->hand_A)
        {
            i->show_front = false;
            m_scene->addItem(i);
        }
        foreach(Card* i,m_logic->hand_B)
        {
            m_scene->addItem(i);
        }
    }
    show();
    emit m_logic->RoundStart();
}

void BattleInterfaceView::round_initialize()
{
    foreach(Card* i, m_logic->row_1_A)
        m_scene->removeItem(i);
    foreach(Card* i, m_logic->row_2_A)
        m_scene->removeItem(i);
    foreach(Card* i, m_logic->row_3_A)
        m_scene->removeItem(i);
    foreach(Card* i, m_logic->hand_A)
        m_scene->removeItem(i);

    foreach(Card* i, m_logic->row_1_B)
        m_scene->removeItem(i);
    foreach(Card* i, m_logic->row_2_B)
        m_scene->removeItem(i);
    foreach(Card* i, m_logic->row_3_B)
        m_scene->removeItem(i);
    foreach(Card* i, m_logic->hand_B)
        m_scene->removeItem(i);

    emit RoundToSwitch();
}

void BattleInterfaceView::add_item(Card * it)
{
    m_scene->addItem(it);
}

void BattleInterfaceView::remove_item(Card * it)
{
    m_scene->removeItem(it);
}
