#include "roundendinterface.h"

RoundEndInterface::RoundEndInterface(QWidget *parent):
    QGraphicsView(parent)
{
    m_scene = new QGraphicsScene;
    m_scene ->setSceneRect(0,0,WindowWidth,WindowHeight);

    //setTimer
    m_timer = new QTimer;
    m_timer ->setInterval(RoundEndShowInterval);

    //setBackground
    QPixmap *bkg = new QPixmap("/Users/poolei/Documents/Programme/LetMeDo/Background/round_end.png");
    setAutoFillBackground(true);
    QPixmap nbkg = bkg->scaled(QSize(WindowWidth,WindowHeight));
    setBackgroundBrush(nbkg);

    //round_info
    line = new QGraphicsLineItem;
    line->setPen(QPen(QColor(58,61,61)));
    line->setLine(605,370,605,405);
    m_scene->addItem(line);

    result = new QGraphicsTextItem;
    result->setPos(530,315);
    result->setFont(QFont(0,23));
    result->setTextWidth(250);
    result->setDefaultTextColor(QColor(217,28,28));
    m_scene->addItem(result);

    strength_A = new QGraphicsTextItem;
    strength_A->setPos(550,370);
    strength_A->setFont(QFont(0,24));
    strength_A->setTextWidth(250);
    strength_A->setDefaultTextColor(QColor(174,142,22));
    m_scene->addItem(strength_A);

    strength_B = new QGraphicsTextItem;
    strength_B->setPos(640,370);
    strength_B->setFont(QFont(0,24));
    strength_B->setTextWidth(250);
    strength_B->setDefaultTextColor(QColor(174,142,22));
    m_scene->addItem(strength_B);

    name_A = new QGraphicsTextItem;
    name_A->setPos(260,370);
    name_A->setFont(QFont(0,22));
    name_A->setTextWidth(250);
    name_A->setDefaultTextColor(QColor(172,174,176));
    m_scene->addItem(name_A);

    name_B = new QGraphicsTextItem;
    name_B->setPos(830,370);
    name_B->setFont(QFont(0,22));
    name_B->setTextWidth(250);
    name_B->setDefaultTextColor(QColor(172,174,176));
    m_scene->addItem(name_B);

    //setScene
    setScene(m_scene);
    resize(WindowWidth,WindowHeight);
}

void RoundEndInterface::set_result()
{
        name_A->setPlainText(tr("A（下方玩家）"));
        name_B->setPlainText(tr("B（上方玩家）"));
        strength_A->setPlainText(QString::number(m_logic->A_strength_round[m_logic->round-1]));
        strength_B->setPlainText(QString::number(m_logic->B_strength_round[m_logic->round-1]));

        if(m_logic->round_winner[m_logic->round-1] == 1)
            result->setPlainText(QString(tr("第 %1 回合 A 胜利").arg(m_logic->round)));
        else if (m_logic->round_winner[m_logic->round-1] == 0)
            result->setPlainText(QString(tr("第 %1 回合 B 胜利").arg(m_logic->round)));
        else if (m_logic->round_winner[m_logic->round-1] == 3)
            result->setPlainText(QString(tr("第 %1 回合 平局").arg(m_logic->round)));

}
