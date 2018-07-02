#include "battleendinterface.h"

BattleEndInterface::BattleEndInterface(QWidget *parent):
    QGraphicsView(parent)
{
    m_scene = new QGraphicsScene;
    m_scene ->setSceneRect(0,0,WindowWidth,WindowHeight);

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


    //result_info
    for (int i = 0;i < 3; i ++)
    {
        line[i] = new QGraphicsLineItem;
        line[i]->setPen(QPen(QColor(58,61,61)));
        line[i]->setLine(605,220+100*i,605,250+100*i);
        m_scene->addItem(line[i]);
    }

    result = new QGraphicsTextItem;
    result->setPos(560,135);
    result->setFont(QFont(0,40));
    result->setTextWidth(250);
    result->setDefaultTextColor(QColor(217,28,28));
    m_scene->addItem(result);

    for (int i = 0;i < 3; i ++)
    {
        strength_A[i] = new QGraphicsTextItem;
        strength_A[i]->setPos(560,220+i*100);
        strength_A[i]->setFont(QFont(0,30));
        strength_A[i]->setTextWidth(250);
        strength_A[i]->setDefaultTextColor(QColor(174,142,22));
        m_scene->addItem(strength_A[i]);
    }

    for(int i = 0 ;i< 3; i ++)
    {
        strength_B[i] = new QGraphicsTextItem;
        strength_B[i]->setPos(630,220+i*100);
        strength_B[i]->setFont(QFont(0,30));
        strength_B[i]->setTextWidth(250);
        strength_B[i]->setDefaultTextColor(QColor(174,142,22));
        m_scene->addItem(strength_B[i]);
    }

    name_A = new QGraphicsTextItem;
    name_A->setPos(300,210);
    name_A->setFont(QFont(0,22));
    name_A->setTextWidth(250);
    name_A->setDefaultTextColor(QColor(172,174,176));
    m_scene->addItem(name_A);

    name_B = new QGraphicsTextItem;
    name_B->setPos(810,210);
    name_B->setFont(QFont(0,22));
    name_B->setTextWidth(250);
    name_B->setDefaultTextColor(QColor(172,174,176));
    m_scene->addItem(name_B);


    //setBackground
    QPixmap *bkg = new QPixmap(":/images/Background/battle_end.png");
    setAutoFillBackground(true);
    QPixmap nbkg = bkg->scaled(QSize(WindowWidth,WindowHeight));
    setBackgroundBrush(nbkg);

    //setScene
    setScene(m_scene);
    resize(WindowWidth,WindowHeight);

}

void BattleEndInterface::set_result()
{

        name_A->setPlainText(tr("A（下方玩家）"));
        name_B->setPlainText(tr("B（上方玩家）"));

        for(int i = 0;i < m_logic->round ;i ++)
        {
        strength_A[i]->setPlainText(QString::number(m_logic->A_strength_round[i]));
        strength_B[i]->setPlainText(QString::number(m_logic->B_strength_round[i]));
        }

        if(m_logic->game_winner == 1)
            result->setPlainText(QString(tr("A 胜 利")));
        else if (m_logic->game_winner == 0)
            result->setPlainText(QString(tr("B 胜 利")));
        else if (m_logic->game_winner == 2)
            result->setPlainText(QString(tr("平 局")));
}

