#include "welcomeinterface.h"
#include <QPixmap>

WelcomeInterface::WelcomeInterface(QWidget *parent):
    QGraphicsView (parent)
{
    //scene
    m_scene = new QGraphicsScene;
    m_scene ->setSceneRect(0,0,WindowWidth,WindowHeight);

    //btn
    begin_game_btn = new MyButton;
    edit_card_btn = new MyButton;
    begin_game = new QGraphicsWidget;
    edit_card = new QGraphicsWidget;


    begin_game_btn->pix = new QPixmap(":/images/Widgets/begin_game.png");
    begin_game_btn->pix_blue = new QPixmap(":/images/Widgets/begin_game_blue.png");
    begin_game_btn->setIcon(*begin_game_btn->pix);
    begin_game_btn->setIconSize(QSize(70,30));
    begin_game_btn->setFixedSize(55,21);
    edit_card_btn->pix = new QPixmap(":/images/Widgets/edit_card.png");
    edit_card_btn->pix_blue = new QPixmap(":/images/Widgets/edit_card_blue.png");
    edit_card_btn->setIcon(*edit_card_btn->pix);
    edit_card_btn->setIconSize(QSize(70,30));
    edit_card_btn->setFixedSize(55,21);
    begin_game_btn->move(450,650);
    edit_card_btn->move(650,650);
    begin_game =  m_scene->addWidget(begin_game_btn);
    edit_card  =  m_scene->addWidget(edit_card_btn);

    //setBackground
    QPixmap *bkg = new QPixmap(":/images/Background/welcome.png");
    setAutoFillBackground(true);
    QPixmap nbkg = bkg->scaled(QSize(WindowWidth,WindowHeight));
    setBackgroundBrush(nbkg);
    //setScene
    setScene(m_scene);
    resize(WindowWidth,WindowHeight);
}

