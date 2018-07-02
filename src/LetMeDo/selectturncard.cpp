#include "selectturncard.h"

SelectTurnCard::SelectTurnCard(QWidget * parent):
    QGraphicsView(parent)
{
    pass_card_num = 0;

    m_scene = new QGraphicsScene;
    m_scene ->setSceneRect(0,0,WindowWidth,WindowHeight);


    for (int i = 0; i < 4;i++ )
    {
    card_name[i] = new QGraphicsTextItem;
    card_name[i]->setPos(140+250*i,480);
    card_name[i]->setFont(QFont(0,18));
    card_name[i]->setTextWidth(250);
    card_name[i]->setDefaultTextColor(QColor(172,174,176));
    m_scene->addItem(card_name[i]);
    card_des[i] = new QGraphicsTextItem;
    card_des[i]->setPos(140+250*i,530);
    card_des[i]->setTextWidth(180);
    card_des[i]->setDefaultTextColor(QColor(172,174,176));
    m_scene->addItem(card_des[i]);
    }


    QPixmap *bkg = new QPixmap(":/images/Background/select_card.png");
    setAutoFillBackground(true);
    QPixmap nbkg = bkg->scaled(QSize(WindowWidth,WindowHeight));
    setBackgroundBrush(nbkg);

    //setScene
    setScene(m_scene);
    resize(WindowWidth,WindowHeight);
}

void SelectTurnCard::initialize()
{
    pass_card_num = 0;
    int total = m_logic->turn_card->alternative.size(),total2 = total;
    for(int i = 0;i< 4;i++)
    {
        card_des[i]->setPlainText(NULL);
        card_name[i]->setPlainText(NULL);
    }

    if (total > 4) total2 = 4;

    for (int i = 0;i<total2;i++ )
     {
            card_name[i]->setPlainText(m_logic->turn_card->alternative[i]->card_name);
            card_des[i]->setPlainText(m_logic->turn_card->alternative[i]->description);
            m_logic->turn_card->alternative[i]->setScale(3.5);
            m_scene->addItem(m_logic->turn_card->alternative[i]);
     }

    show();
}

void SelectTurnCard::wheelEvent(QWheelEvent *event)
{
    QGraphicsView::wheelEvent(event);
      if (event->delta()>0)
          {
                if (pass_card_num > 0)
              {
                  pass_card_num--;
                  m_scene->addItem(m_logic->turn_card->alternative[pass_card_num]);
                  m_logic->turn_card->alternative[pass_card_num]->setScale(3.5);
                  m_scene->removeItem(m_logic->turn_card->alternative[pass_card_num+4]);
                  m_logic->turn_card->alternative[pass_card_num+4]->setScale(1);
                  for (int i = 0; i <4 ;i++)
                  {
                      card_name[i]->setPlainText(m_logic->turn_card->alternative[i+pass_card_num]->card_name);
                      card_des[i]->setPlainText(m_logic->turn_card->alternative[i+pass_card_num]->description);
                  }
              }
           }
         else if (event->delta() < 0)
          {
                if (pass_card_num < m_logic->turn_card->alternative.size()-4)
             {
                  pass_card_num++;
                  m_scene->addItem(m_logic->turn_card->alternative[pass_card_num+3]);
                  m_logic->turn_card->alternative[pass_card_num+3]->setScale(3.5);
                  m_scene->removeItem(m_logic->turn_card->alternative[pass_card_num-1]);
                  m_logic->turn_card->alternative[pass_card_num-1]->setScale(1);
                  for (int i = 0; i <4 ;i++)
                  {
                      card_name[i]->setPlainText(m_logic->turn_card->alternative[i+pass_card_num]->card_name);
                      card_des[i]->setPlainText(m_logic->turn_card->alternative[i+pass_card_num]->description);
                  }
             }
          }
}

void SelectTurnCard::paintEvent(QPaintEvent * event)
{
    int t = m_logic->turn_card->alternative.size();
    if (t > 4) t = 4;

    for(int i = 0;i < t; i++ )
             m_logic->turn_card->alternative[i + pass_card_num]->setPos(100+250*i,200);

    QGraphicsView::paintEvent(event);
}

void SelectTurnCard::mousePressEvent(QMouseEvent *event)
{
    QGraphicsView::mousePressEvent(event);

    QPoint viewPos = event->pos();
    QPointF scenePos = mapToScene(viewPos);
    QGraphicsItem *selected = scene()->itemAt(scenePos,QTransform());
        if (selected == card_name[0] || selected == card_name[1]
           || selected == card_name[2] || selected == card_name[3]
           || selected == card_des[0] || selected == card_des[1]
           || selected == card_des[2] || selected == card_des[3]
           || selected == NULL
                )
            return;
     Card* selected_card = static_cast<Card*>(selected);
     m_logic->turn_card->the_chosen = selected_card;
     emit  FinishSelect();
}

void SelectTurnCard::restore()
{
    int t  = m_logic->turn_card->alternative.size();
    if (t > 4)  t = 4;
    for (int i = 0; i<t ;i ++)
       {
        m_scene->removeItem(m_logic->turn_card->alternative[pass_card_num+ i]);
        m_logic->turn_card->alternative[pass_card_num + i]->setScale(1);
       }
}
