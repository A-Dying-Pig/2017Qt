#include "switchhandcard.h"
#include <QTime>

SwitchHandCard::SwitchHandCard(QWidget *parent):
    QGraphicsView(parent)
{
    m_scene = new QGraphicsScene;
    m_scene ->setSceneRect(0,0,WindowWidth,WindowHeight);

    change_time = 0;
    pass_card_num = 0;

    //btn
    confirm_btn = new MyButton();
    confirm = new QGraphicsWidget;

    confirm_btn->pix = new QPixmap(":/images/Widgets/confirm.png");
    confirm_btn->pix_blue  = new QPixmap(":/images/Widgets/confirm_blue.png");
    confirm_btn->setIcon(*confirm_btn->pix);
    confirm_btn->setIconSize(QSize(70,30));
    confirm_btn->setFixedSize(55,21);
    confirm_btn->setAttribute(Qt::WA_TranslucentBackground);
    confirm_btn->move(570,680);
    confirm =  m_scene->addWidget(confirm_btn);

    //card_info

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

    //side_info
    side  = new QGraphicsTextItem;
    side->setPos(530,60);
    side->setFont(QFont(0,20));
    side->setDefaultTextColor(QColor(172,174,176));
    m_scene->addItem(side);

    //switch_limited_times_num
    limited_times_num = new QGraphicsTextItem;
    limited_times_num->setPos(534,118);
    limited_times_num->setFont(QFont(0,20));
    limited_times_num->setDefaultTextColor(QColor(172,174,176));
    m_scene->addItem(limited_times_num);

    have_switched_times = new QGraphicsTextItem;
    have_switched_times->setPos(660,121);
    have_switched_times->setFont(QFont(0,15));
    have_switched_times->setDefaultTextColor(QColor(172,174,176));
    m_scene->addItem(have_switched_times);

    connect(this,SIGNAL(Init()),this,SLOT(initialize()));
    //setBackground
    QPixmap *bkg = new QPixmap(":/images/Background/switch_card.png");
    setAutoFillBackground(true);
    QPixmap nbkg = bkg->scaled(QSize(WindowWidth,WindowHeight));
    setBackgroundBrush(nbkg);

    //setScene
    setScene(m_scene);
    resize(WindowWidth,WindowHeight);
}

void SwitchHandCard::paintEvent(QPaintEvent *event)
{
    if (m_logic->step == 2)
    {
        for(int i = 0;i < 4; i++ )
                 m_logic->hand_A[i + pass_card_num]->setPos(100+250*i,200);
     }
    else if (m_logic->step == 3)
    {
        for(int i = 0;i < 4; i++ )
                 m_logic->hand_B[i + pass_card_num]->setPos(100+250*i,200);
    }
    QGraphicsView::paintEvent(event);
}

void SwitchHandCard::wheelEvent(QWheelEvent *event)
{
    QGraphicsView::wheelEvent(event);
    if (m_logic->step == 2)
    {
            if (event->delta()>0)
          {
                if (pass_card_num > 0)
              {
                  pass_card_num--;
                  m_scene->addItem(m_logic->hand_A[pass_card_num]);
                  m_logic->hand_A[pass_card_num]->setScale(3.5);
                  m_scene->removeItem(m_logic->hand_A[pass_card_num+4]);
                  m_logic->hand_A[pass_card_num+4]->setScale(1);
                  for (int i = 0; i <4 ;i++)
                  {
                      card_name[i]->setPlainText(m_logic->hand_A[i+pass_card_num]->card_name);
                      card_des[i]->setPlainText(m_logic->hand_A[i+pass_card_num]->description);
                  }
              }
           }
         else if (event->delta() < 0)
          {
                if (pass_card_num < m_logic->hand_A.size()-4)
             {
                  pass_card_num++;
                  m_scene->addItem(m_logic->hand_A[pass_card_num+3]);
                  m_logic->hand_A[pass_card_num+3]->setScale(3.5);
                  m_scene->removeItem(m_logic->hand_A[pass_card_num-1]);
                  m_logic->hand_A[pass_card_num-1]->setScale(1);
                  for (int i = 0; i <4 ;i++)
                  {
                      card_name[i]->setPlainText(m_logic->hand_A[i+pass_card_num]->card_name);
                      card_des[i]->setPlainText(m_logic->hand_A[i+pass_card_num]->description);
                  }
             }
          }
      }
    else if (m_logic->step == 3)
    {
            if (event->delta()>0)
         {
                if (pass_card_num > 0)
             {
                 pass_card_num--;
                 m_scene->addItem(m_logic->hand_B[pass_card_num]);
                 m_logic->hand_B[pass_card_num]->setScale(3.5);
                 m_scene->removeItem(m_logic->hand_B[pass_card_num+4]);
                 m_logic->hand_B[pass_card_num+4]->setScale(1);
                 for (int i = 0; i <4 ;i++)
                 {
                     card_name[i]->setPlainText(m_logic->hand_B[i+pass_card_num]->card_name);
                     card_des[i]->setPlainText(m_logic->hand_B[i+pass_card_num]->description);
                 }
             }
         }
            else
         {
                if (pass_card_num < m_logic->hand_B.size()-4)
              {
                pass_card_num++;
                m_scene->addItem(m_logic->hand_B[pass_card_num+3]);
                m_logic->hand_B[pass_card_num+3]->setScale(3.5);
                m_scene->removeItem(m_logic->hand_B[pass_card_num-1]);
                m_logic->hand_B[pass_card_num-1]->setScale(1);
                for (int i = 0; i <4 ;i++)
                {
                    card_name[i]->setPlainText(m_logic->hand_B[i+pass_card_num]->card_name);
                    card_des[i]->setPlainText(m_logic->hand_B[i+pass_card_num]->description);
                }
              }
         }
     }
}

void SwitchHandCard::mousePressEvent(QMouseEvent *event)
{
    QGraphicsView::mousePressEvent(event);
    if (change_time< limited_times)
    {
        QPoint viewPos = event->pos();
        QPointF scenePos = mapToScene(viewPos);
        QGraphicsItem *selected = scene()->itemAt(scenePos,QTransform());
        if (selected == card_name[0] || selected == card_name[1]
           || selected == card_name[2] || selected == card_name[3]
           || selected == card_des[0] || selected == card_des[1]
           || selected == card_des[2] || selected == card_des[3]
           || selected == confirm
           || selected == limited_times_num ||selected == have_switched_times
           || selected == NULL
                )
            return;
         Card* selected_card = static_cast<Card*>(selected);

         if (m_logic->step == 2)
         {
             selected_card->setScale(1);
             m_scene->removeItem(selected_card);
             selected_card->card_has_switched();

             qsrand(QTime::currentTime().msec());
             //random
             int num,library_ptr;
             do
             {
             num = m_logic->library_A.size();
             library_ptr = qrand() % num;
             }while(m_logic->library_A[library_ptr]->get_has_switched());
             //    
             int hand_ptr = m_logic->hand_A.indexOf(selected_card);
             m_logic->hand_A[hand_ptr] = m_logic->library_A[library_ptr];
             m_logic->library_A[library_ptr] = selected_card;
             card_name[hand_ptr - pass_card_num]->setPlainText(m_logic->hand_A[hand_ptr]->card_name);
             card_des[hand_ptr - pass_card_num]->setPlainText( m_logic->hand_A[hand_ptr]->description);
             m_scene->addItem(m_logic->hand_A[hand_ptr]);
             m_logic->hand_A[hand_ptr]->setScale(3.5);
             change_time++;
             have_switched_times->setPlainText(QString("[%1/%2]").arg(change_time).arg(limited_times));
         }
         else if (m_logic->step == 3)
         {
             selected_card->setScale(1);
             m_scene->removeItem(selected_card);
             selected_card->card_has_switched();

             int num,library_ptr;
             //random
             qsrand(QTime::currentTime().msec());
             do
             {
             num = m_logic->library_B.size();
             library_ptr = qrand() % num;
             }while(m_logic->library_B[library_ptr]->get_has_switched());
             //

             int hand_ptr = m_logic->hand_B.indexOf(selected_card);
             m_logic->hand_B[hand_ptr] = m_logic->library_B[library_ptr];
             m_logic->library_B[library_ptr] = selected_card;
             card_name[hand_ptr - pass_card_num]->setPlainText(m_logic->hand_B[hand_ptr]->card_name);
             card_des[hand_ptr - pass_card_num]->setPlainText( m_logic->hand_B[hand_ptr]->description);
             m_scene->addItem(m_logic->hand_B[hand_ptr]);
             m_logic->hand_B[hand_ptr]->setScale(3.5);
             change_time++;
             have_switched_times->setPlainText(QString("[%1/%2]").arg(change_time).arg(limited_times));
         }
    }

}

void SwitchHandCard::initialize()
{

    change_time = 0;
    pass_card_num = 0;

    if (m_logic->round == 0)
        limited_times = 3;
    else if (m_logic->round == 1)
        limited_times = 2;
    else if (m_logic->round == 2)
        limited_times = 1;

    limited_times_num->setPlainText(QString::number(limited_times));
    have_switched_times->setPlainText(QString("[%1/%2]").arg(change_time).arg(limited_times));

    if (m_logic->step == 2)
    {
        side->setPlainText(tr("请为A重新抽牌"));
        for (int i = 0;i<4;i++ )
        {
            card_name[i]->setPlainText(m_logic->hand_A[i]->card_name);
            card_des[i]->setPlainText(m_logic->hand_A[i]->description);
            m_logic->hand_A[i]->setScale(3.5);
            m_scene->addItem(m_logic->hand_A[i]);
        }
    }
    else if (m_logic->step == 3)
    {
        side->setPlainText(tr("请为B重新抽牌"));
        for (int i = 0;i<4;i++ )
        {
            card_name[i]->setPlainText(m_logic->hand_B[i]->card_name);
            card_des[i]->setPlainText(m_logic->hand_B[i]->description);
            m_logic->hand_B[i]->setScale(3.5);
            m_scene->addItem(m_logic->hand_B[i]);
        }
    }
    if (m_logic->step == 2)
      show();
}

void SwitchHandCard::restore_handcard()
{
    if (m_logic->step == 2)
    {
        for (int i = 0; i<4 ;i ++)
        {
            m_logic->hand_A[pass_card_num + i]->setScale(1);
            m_scene->removeItem(m_logic->hand_A[pass_card_num + i]);
        }

    }
    else if (m_logic->step == 3)
    {
        for (int i = 0; i<4 ;i ++)
        {
            m_logic->hand_B[pass_card_num + i]->setScale(1);
            m_scene->removeItem(m_logic->hand_B[pass_card_num + i]);
        }
    }
    if (m_logic->step == 2)
       {
        m_logic->step++;
        emit Init();
        }
    else if (m_logic->step == 3)
    {
        hide();
        emit FinishProcess();
    }
}

