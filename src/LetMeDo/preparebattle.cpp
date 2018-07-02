#include "preparebattle.h"
#include "cardlibrary.h"
#include <QXmlStreamReader>
#include <QTime>
#include <QDebug>
#include <QDir>

PrepareBattle::PrepareBattle(QWidget *parent):
    QGraphicsView(parent)
{
    m_scene = new QGraphicsScene;
    m_scene ->setSceneRect(0,0,WindowWidth,WindowHeight);

    //btn
    prepared_num = 0;
    selected_num = 0;
    confirm_btn = new MyButton;
    confirm = new QGraphicsWidget;
    back_btn = new MyButton ;
    back = new QGraphicsWidget;

    confirm_btn->pix= new QPixmap(":/images/Widgets/confirm.png");
    confirm_btn->pix_blue = new QPixmap(":/images/Widgets/confirm_blue.png");
    confirm_btn->setIcon(*confirm_btn->pix);
    confirm_btn->setIconSize(QSize(70,30));
    confirm_btn->setFixedSize(55,21);
    confirm_btn->setAttribute(Qt::WA_TranslucentBackground);
    back_btn->pix = new QPixmap(":/images/Widgets/back.png");
    back_btn->pix_blue = new QPixmap(":/images/Widgets/back_blue.png");
    back_btn->setIcon(*back_btn->pix);
    back_btn->setIconSize(QSize(70,30));
    back_btn->setFixedSize(55,21);
    back_btn->setAttribute(Qt::WA_TranslucentBackground);
    confirm_btn->move(460,660);
    back_btn->move(670,660);
    confirm =  m_scene->addWidget(confirm_btn);
    back  =  m_scene->addWidget(back_btn);

    //setBackground
    QPixmap *bkg = new QPixmap(":/images/Background/prepare_battle.png");
    setAutoFillBackground(true);
    QPixmap nbkg = bkg->scaled(QSize(WindowWidth,WindowHeight));
    setBackgroundBrush(nbkg);

    for (int i = 0;i <4; i++)
         {
            m_cards_btn[i] = new QPushButton;
            show_card_name[i] = new QGraphicsTextItem;
            m_cards[i] = NULL;
         }

    //setScene
    side = new QGraphicsTextItem;
    side->setPos(550,60);
    side->setFont(QFont(0,20));
    side->setDefaultTextColor(QColor(172,174,176));
    m_scene->addItem(side);
    setScene(m_scene);
    resize(WindowWidth,WindowHeight);
}


void PrepareBattle::receiveCard()
{
    QDir dir(file_dir+"/Prepared_Cards/");
    QStringList filters;
    filters<<"*.xml";
    dir.setNameFilters(filters);
    QFileInfoList list = dir.entryInfoList();
    prepared_num  = list.count();

    qDebug()<<prepared_num;
    if (prepared_num >4) prepared_num = 4;
}

void PrepareBattle::view_initialize()
{

    m_logic->step = 0;
    QPixmap pix[4];
    pix[0].load(":/images/CardImage/Monsters/Dagon.png");
    pix[1].load(":/images/CardImage/Monsters/Unseen_Elder.png");
    pix[2].load(":/images/CardImage/Monsters/Woodland_Spirit.png");
    pix[3].load(":/images/CardImage/Monsters/Caranthir.png");



    side->setPlainText(tr("请为A选牌"));

    for (int i = 0;i < prepared_num;i++ )
    { 
        if (m_cards[i] ==NULL)
             m_cards[i] = new QGraphicsWidget;


        m_cards_btn[i]->setStyleSheet("background-position:"
                                     "center;background-attachment: fixed");
        m_cards_btn[i]->setIcon(pix[i]);
        m_cards_btn[i]->setIconSize(QSize(220,380));
        m_cards_btn[i]->setFixedSize(150,210);
        m_cards_btn[i]->move(150+240*i,260);
        m_cards_btn[i]->setAttribute(Qt::WA_TranslucentBackground);
        m_cards[i] = m_scene->addWidget(m_cards_btn[i])  ;

        show_card_name[i]->setPlainText(tr("卡组 %1").arg(i+1));
        show_card_name[i]->setPos(190+240*i,200);
        show_card_name[i]->setFont(QFont(0,20));
        show_card_name[i]->setDefaultTextColor(QColor(172,174,176));
        m_scene->addItem(show_card_name[i]);

    }
    connect(m_cards_btn[0],SIGNAL(clicked()),this,SLOT(select_1()));
    connect(m_cards_btn[1],SIGNAL(clicked()),this,SLOT(select_2()));
    connect(m_cards_btn[2],SIGNAL(clicked()),this,SLOT(select_3()));
    connect(m_cards_btn[3],SIGNAL(clicked()),this,SLOT(select_4()));
}

void PrepareBattle::select_1()
{
    selected_num = 0;
    show_card_name[0]->setDefaultTextColor(QColor(217,28,28));
     show_card_name[1]->setDefaultTextColor(QColor(172,174,176));
     show_card_name[2]->setDefaultTextColor(QColor(172,174,176));
      show_card_name[3]->setDefaultTextColor(QColor(172,174,176));
}

void PrepareBattle::select_2()
{
    selected_num = 1;
    show_card_name[1]->setDefaultTextColor(QColor(217,28,28));
    show_card_name[0]->setDefaultTextColor(QColor(172,174,176));
    show_card_name[2]->setDefaultTextColor(QColor(172,174,176));
     show_card_name[3]->setDefaultTextColor(QColor(172,174,176));
}
void PrepareBattle::select_3()
{
    selected_num = 2;
    show_card_name[2]->setDefaultTextColor(QColor(217,28,28));
    show_card_name[1]->setDefaultTextColor(QColor(172,174,176));
    show_card_name[0]->setDefaultTextColor(QColor(172,174,176));
     show_card_name[3]->setDefaultTextColor(QColor(172,174,176));
}
void PrepareBattle::select_4()
{
    selected_num = 3;
    show_card_name[3]->setDefaultTextColor(QColor(217,28,28));
    show_card_name[1]->setDefaultTextColor(QColor(172,174,176));
    show_card_name[2]->setDefaultTextColor(QColor(172,174,176));
     show_card_name[0]->setDefaultTextColor(QColor(172,174,176));
}


void PrepareBattle::card_initialize()
{
    QDir dir(file_dir+"/Prepared_Cards/");
    QStringList filters;
    filters<<"*.xml";
    dir.setNameFilters(filters);
    QFileInfoList list = dir.entryInfoList();
    QString filename = list.at(selected_num).fileName();

    filename = QString(file_dir+"/Prepared_Cards/")+filename;
    QFile file (filename);

     if (!file.open(QFile::ReadOnly | QFile::Text))
     {
        qDebug()<<"Error:cannot open file";
        return;
     }
    QXmlStreamReader m_reader;
    m_reader.setDevice(&file);
    int card_id,object_id;
    QList<int> id;

     Biting_Frost *bt ;
     First_Light *FL ;
     Impenetrable_Fog *IF;
     Lacerate *Lc ;
     Torrential_Rain *TR ;
     Immune_Boost *IB ;
     Commanders_Horn *CH ;
     Bekkers_Twisted_Mirror *BTM ;
     Geralt_Igni *GI ;
     Dagon *Dg ;
     Foglet *Fgl ;
     Geels *Gls ;
     Celaeno_Harpy *CHpy ;
     Harpy *Hpy = new Harpy;
     Woodland_Spirit *WS;
     Earth_Elemental *EE ;
     Crone_Weavess *CWss ;
     Crone_Whispess *CWh ;
     Crone_Brewess *CBss ;
     Archgriffin *Ach ;
     Wild_Hunt_Rider *Nth ;
     Caranthir *Cara ;
     Frightener *Ftn ;
     Unseen_Elder *UE ;
     Arachas *Arc ;
      Arachas_Behemoth *AB ;
     Vran_Warrior *VW ;
     Sunny_Day *SD ;
     Restart *Rs;
     Lesser_Earth *LE ;
     Harpy_Egg *HE ;
     Harpy_Cub *HC ;
     Arachas_Larva *AL ;
     Raging_Wolf *RW ;


    if (m_logic->step == 0)
    {
         while(!m_reader.atEnd())
         {
              QXmlStreamReader::TokenType type = m_reader.readNext();
              if (type == QXmlStreamReader::StartElement)
             {
                 if (m_reader.attributes().hasAttribute("card_id"))
                 {
                     card_id = m_reader.attributes().value("card_id").toInt();
                 }
             }
              if (type == QXmlStreamReader::Characters && !m_reader.isWhitespace())
              {
                  qDebug()<<m_reader.text();
                  object_id = m_reader.text().toInt();
                  id.clear();
              switch(card_id)
              {
                case 1:
                  bt = new Biting_Frost;
                  bt->the_logic = m_logic;
                  id.push_back(card_id);
                  id.push_back(object_id);
                  m_logic->m_map1.insert(id,bt);
                  m_logic->m_map2.insert(bt,id);
                  m_logic->aLL_A.push_back(bt);
                  break;
                case 2:
                  FL = new First_Light;
                  FL->the_logic = m_logic;
                  id.push_back(card_id);
                  id.push_back(object_id);
                  m_logic->m_map1.insert(id,FL);
                  m_logic->m_map2.insert(FL,id);
                  m_logic->aLL_A.push_back(FL);
                  break;
              case 3:
                IF = new Impenetrable_Fog;
                IF->the_logic = m_logic;
                id.push_back(card_id);
                id.push_back(object_id);
                m_logic->m_map1.insert(id,IF);
                m_logic->m_map2.insert(IF,id);
                m_logic->aLL_A.push_back(IF);
                break;
              case 4:
                Lc = new Lacerate;
                Lc->the_logic = m_logic;
                id.push_back(card_id);
                id.push_back(object_id);
                m_logic->m_map1.insert(id,Lc);
                m_logic->m_map2.insert(Lc,id);
                m_logic->aLL_A.push_back(Lc);
                break;
              case 5:
                TR = new Torrential_Rain;
                TR->the_logic = m_logic;
                id.push_back(card_id);
                id.push_back(object_id);
                m_logic->m_map1.insert(id,TR);
                m_logic->m_map2.insert(TR,id);
                m_logic->aLL_A.push_back(TR);
                break;
              case 6:
                IB = new Immune_Boost;
                IB->the_logic = m_logic;
                id.push_back(card_id);
                id.push_back(object_id);
                m_logic->m_map1.insert(id,IB);
                m_logic->m_map2.insert(IB,id);
                m_logic->aLL_A.push_back(IB);
                break;
              case 7:
                CH = new Commanders_Horn;
                CH->the_logic = m_logic;
                id.push_back(card_id);
                id.push_back(object_id);
                m_logic->m_map1.insert(id,CH);
                m_logic->m_map2.insert(CH,id);
                m_logic->aLL_A.push_back(CH);
                break;
              case 8:
                BTM = new Bekkers_Twisted_Mirror;
                BTM->the_logic = m_logic;
                id.push_back(card_id);
                id.push_back(object_id);
                m_logic->m_map1.insert(id,BTM);
                m_logic->m_map2.insert(BTM,id);
                m_logic->aLL_A.push_back(BTM);
                break;
              case 9:
                GI = new Geralt_Igni;
                GI->the_logic = m_logic;
                id.push_back(card_id);
                id.push_back(object_id);
                m_logic->m_map1.insert(id,GI);
                m_logic->m_map2.insert(GI,id);
                m_logic->aLL_A.push_back(GI);
                break;
              case 10:
                Dg= new Dagon;
                Dg->the_logic = m_logic;
                id.push_back(card_id);
                id.push_back(object_id);
                m_logic->m_map1.insert(id,Dg);
                m_logic->m_map2.insert(Dg,id);
                m_logic->aLL_A.push_back(Dg);
                break;
              case 11:
                Fgl = new Foglet;
                Fgl->the_logic = m_logic;
                id.push_back(card_id);
                id.push_back(object_id);
                m_logic->m_map1.insert(id,Fgl);
                m_logic->m_map2.insert(Fgl,id);
                m_logic->aLL_A.push_back(Fgl);
                break;
              case 12:
                Gls = new Geels;
                Gls->the_logic = m_logic;
                id.push_back(card_id);
                id.push_back(object_id);
                m_logic->m_map1.insert(id,Gls);
                m_logic->m_map2.insert(Gls,id);
                m_logic->aLL_A.push_back(Gls);
                break;
              case 13:
                CHpy = new Celaeno_Harpy;
                CHpy->the_logic = m_logic;
                id.push_back(card_id);
                id.push_back(object_id);
                m_logic->m_map1.insert(id,CHpy);
                m_logic->m_map2.insert(CHpy,id);
                m_logic->aLL_A.push_back(CHpy);
                break;
              case 14:
                Hpy = new Harpy;
                Hpy->the_logic = m_logic;
                id.push_back(card_id);
                id.push_back(object_id);
                m_logic->m_map1.insert(id,Hpy);
                m_logic->m_map2.insert(Hpy,id);
                m_logic->aLL_A.push_back(Hpy);
                break;
              case 15:
                WS= new Woodland_Spirit;
                WS->the_logic = m_logic;
                id.push_back(card_id);
                id.push_back(object_id);
                m_logic->m_map1.insert(id,WS);
                m_logic->m_map2.insert(WS,id);
                m_logic->aLL_A.push_back(WS);
                break;
              case 16:
                EE = new Earth_Elemental;
                EE->the_logic = m_logic;
                id.push_back(card_id);
                id.push_back(object_id);
                m_logic->m_map1.insert(id,EE);
                m_logic->m_map2.insert(EE,id);
                m_logic->aLL_A.push_back(EE);
                break;
              case 17:
                CWss = new Crone_Weavess;
                CWss->the_logic = m_logic;
                id.push_back(card_id);
                id.push_back(object_id);
                m_logic->m_map1.insert(id,CWss);
                m_logic->m_map2.insert(CWss,id);
                m_logic->aLL_A.push_back(CWss);
                break;
              case 18:
                CWh = new Crone_Whispess;
                CWh->the_logic = m_logic;
                id.push_back(card_id);
                id.push_back(object_id);
                m_logic->m_map1.insert(id,CWh);
                m_logic->m_map2.insert(CWh,id);
                m_logic->aLL_A.push_back(CWh);
                break;
              case 19:
                CBss = new Crone_Brewess;
                CBss->the_logic = m_logic;
                id.push_back(card_id);
                id.push_back(object_id);
                m_logic->m_map1.insert(id,CBss);
                m_logic->m_map2.insert(CBss,id);
                m_logic->aLL_A.push_back(CBss);
                break;
              case 20:
                Ach = new Archgriffin;
                Ach->the_logic = m_logic;
                id.push_back(card_id);
                id.push_back(object_id);
                m_logic->m_map1.insert(id,Ach);
                m_logic->m_map2.insert(Ach,id);
                m_logic->aLL_A.push_back(Ach);
                break;
              case 21:
                Nth = new Wild_Hunt_Rider;
                Nth->the_logic = m_logic;
                id.push_back(card_id);
                id.push_back(object_id);
                m_logic->m_map1.insert(id,Nth);
                m_logic->m_map2.insert(Nth,id);
                m_logic->aLL_A.push_back(Nth);
                break;
              case 22:
                Cara = new Caranthir;
                Cara->the_logic = m_logic;
                id.push_back(card_id);
                id.push_back(object_id);
                m_logic->m_map1.insert(id,Cara);
                m_logic->m_map2.insert(Cara,id);
                m_logic->aLL_A.push_back(Cara);
                break;
              case 23:
                Ftn = new Frightener;
                Ftn->the_logic = m_logic;
                id.push_back(card_id);
                id.push_back(object_id);
                m_logic->m_map1.insert(id,Ftn);
                m_logic->m_map2.insert(Ftn,id);
                m_logic->aLL_A.push_back(Ftn);
                break;
              case 24:
                UE = new Unseen_Elder;
                UE->the_logic = m_logic;
                id.push_back(card_id);
                id.push_back(object_id);
                m_logic->m_map1.insert(id,UE);
                m_logic->m_map2.insert(UE,id);
                m_logic->aLL_A.push_back(UE);
                break;
              case 25:
                Arc = new Arachas;
                Arc->the_logic = m_logic;
                id.push_back(card_id);
                id.push_back(object_id);
                m_logic->m_map1.insert(id,Arc);
                m_logic->m_map2.insert(Arc,id);
                m_logic->aLL_A.push_back(Arc);
                break;
              case 26:
                AB = new Arachas_Behemoth;
                AB->the_logic = m_logic;
                id.push_back(card_id);
                id.push_back(object_id);
                m_logic->m_map1.insert(id,AB);
                m_logic->m_map2.insert(AB,id);
                m_logic->aLL_A.push_back(AB);
                break;
              case 27:
                VW = new Vran_Warrior;
                VW->the_logic = m_logic;
                id.push_back(card_id);
                id.push_back(object_id);
                m_logic->m_map1.insert(id,VW);
                m_logic->m_map2.insert(VW,id);
                m_logic->aLL_A.push_back(VW);
                break;
              case 28:
                SD = new Sunny_Day;
                SD->the_logic = m_logic;
                id.push_back(card_id);
                id.push_back(object_id);
                m_logic->m_map1.insert(id,SD);
                m_logic->m_map2.insert(SD,id);
                m_logic->aLL_A.push_back(SD);
                break;
              case 29:
                Rs = new Restart;
                Rs->the_logic = m_logic;
                id.push_back(card_id);
                id.push_back(object_id);
                m_logic->m_map1.insert(id,Rs);
                m_logic->m_map2.insert(Rs,id);
                m_logic->aLL_A.push_back(Rs);
                break;


              case 30:
                LE = new Lesser_Earth;
                LE->the_logic = m_logic;
                id.push_back(card_id);
                id.push_back(object_id);
                m_logic->m_map1.insert(id,LE);
                m_logic->m_map2.insert(LE,id);
                m_logic->aLL_A.push_back(LE);
                break;
              case 31:
                HE = new Harpy_Egg;
                HE->the_logic = m_logic;
                id.push_back(card_id);
                id.push_back(object_id);
                m_logic->m_map1.insert(id,HE);
                m_logic->m_map2.insert(HE,id);
                m_logic->aLL_A.push_back(HE);
                break;
              case 32:
                HC = new Harpy_Cub;
                HC->the_logic = m_logic;
                id.push_back(card_id);
                id.push_back(object_id);
                m_logic->m_map1.insert(id,HC);
                m_logic->m_map2.insert(HC,id);
                m_logic->aLL_A.push_back(HC);
                break;
              case 33:
                AL = new Arachas_Larva;
                AL->the_logic = m_logic;
                id.push_back(card_id);
                id.push_back(object_id);
                m_logic->m_map1.insert(id,AL);
                m_logic->m_map2.insert(AL,id);
                m_logic->aLL_A.push_back(AL);
                break;
              case 34:
                RW = new Raging_Wolf;
                RW->the_logic = m_logic;
                id.push_back(card_id);
                id.push_back(object_id);
                m_logic->m_map1.insert(id,RW);
                m_logic->m_map2.insert(RW,id);
                m_logic->aLL_A.push_back(RW);
                break;
                }
              }
         }

         int total = m_logic->aLL_A.size();
         qsrand(QTime::currentTime().msec());
         for (int i = 0 ;i < 1000 ; i++)
             m_logic->aLL_A.swap(qrand() % total,qrand() %total);

         for (int i = 0;i<10 ;i ++)
            m_logic->hand_A.push_back(m_logic->aLL_A.at(i));
         for (int i = 10;i<total;i++ )
             m_logic->library_A.push_back(m_logic->aLL_A.at(i));
         m_logic->step ++;
    }
    else if (m_logic->step == 1)
    {
         while(!m_reader.atEnd())
         {
              QXmlStreamReader::TokenType type = m_reader.readNext();
              if (type == QXmlStreamReader::StartElement)
             {
                 if (m_reader.attributes().hasAttribute("card_id"))
                 {
                     card_id = m_reader.attributes().value("card_id").toInt();
                 }
             }
              if (type == QXmlStreamReader::Characters && !m_reader.isWhitespace())
              {
                  qDebug()<<m_reader.text();
                  object_id = m_reader.text().toInt();
                  id.clear();
              switch(card_id)
              {
                case 1:
                  bt = new Biting_Frost;
                  bt->the_logic = m_logic;
                  id.push_back(card_id);
                  id.push_back(object_id);
                  m_logic->m_map1.insert(id,bt);
                  m_logic->m_map2.insert(bt,id);
                  m_logic->aLL_B.push_back(bt);
                  break;
                case 2:
                  FL = new First_Light;
                  FL->the_logic = m_logic;
                  id.push_back(card_id);
                  id.push_back(object_id);
                  m_logic->m_map1.insert(id,FL);
                  m_logic->m_map2.insert(FL,id);
                  m_logic->aLL_B.push_back(FL);
                  break;
              case 3:
                IF = new Impenetrable_Fog;
                IF->the_logic = m_logic;
                id.push_back(card_id);
                id.push_back(object_id);
                m_logic->m_map1.insert(id,IF);
                m_logic->m_map2.insert(IF,id);
                m_logic->aLL_B.push_back(IF);
                break;
              case 4:
                Lc = new Lacerate;
                Lc->the_logic = m_logic;
                id.push_back(card_id);
                id.push_back(object_id);
                m_logic->m_map1.insert(id,Lc);
                m_logic->m_map2.insert(Lc,id);
                m_logic->aLL_B.push_back(Lc);
                break;
              case 5:
                TR = new Torrential_Rain;
                TR->the_logic = m_logic;
                id.push_back(card_id);
                id.push_back(object_id);
                m_logic->m_map1.insert(id,TR);
                m_logic->m_map2.insert(TR,id);
                m_logic->aLL_B.push_back(TR);
                break;
              case 6:
                IB = new Immune_Boost;
                IB->the_logic = m_logic;
                id.push_back(card_id);
                id.push_back(object_id);
                m_logic->m_map1.insert(id,IB);
                m_logic->m_map2.insert(IB,id);
                m_logic->aLL_B.push_back(IB);
                break;
              case 7:
                CH = new Commanders_Horn;
                CH->the_logic = m_logic;
                id.push_back(card_id);
                id.push_back(object_id);
                m_logic->m_map1.insert(id,CH);
                m_logic->m_map2.insert(CH,id);
                m_logic->aLL_B.push_back(CH);
                break;
              case 8:
                BTM = new Bekkers_Twisted_Mirror;
                BTM->the_logic = m_logic;
                id.push_back(card_id);
                id.push_back(object_id);
                m_logic->m_map1.insert(id,BTM);
                m_logic->m_map2.insert(BTM,id);
                m_logic->aLL_B.push_back(BTM);
                break;
              case 9:
                GI = new Geralt_Igni;
                GI->the_logic = m_logic;
                id.push_back(card_id);
                id.push_back(object_id);
                m_logic->m_map1.insert(id,GI);
                m_logic->m_map2.insert(GI,id);
                m_logic->aLL_B.push_back(GI);
                break;
              case 10:
                Dg= new Dagon;
                Dg->the_logic = m_logic;
                id.push_back(card_id);
                id.push_back(object_id);
                m_logic->m_map1.insert(id,Dg);
                m_logic->m_map2.insert(Dg,id);
                m_logic->aLL_B.push_back(Dg);
                break;
              case 11:
                Fgl = new Foglet;
                Fgl->the_logic = m_logic;
                id.push_back(card_id);
                id.push_back(object_id);
                m_logic->m_map1.insert(id,Fgl);
                m_logic->m_map2.insert(Fgl,id);
                m_logic->aLL_B.push_back(Fgl);
                break;
              case 12:
                Gls = new Geels;
                Gls->the_logic = m_logic;
                id.push_back(card_id);
                id.push_back(object_id);
                m_logic->m_map1.insert(id,Gls);
                m_logic->m_map2.insert(Gls,id);
                m_logic->aLL_B.push_back(Gls);
                break;
              case 13:
                CHpy = new Celaeno_Harpy;
                CHpy->the_logic = m_logic;
                id.push_back(card_id);
                id.push_back(object_id);
                m_logic->m_map1.insert(id,CHpy);
                m_logic->m_map2.insert(CHpy,id);
                m_logic->aLL_B.push_back(CHpy);
                break;
              case 14:
                Hpy = new Harpy;
                Hpy->the_logic = m_logic;
                id.push_back(card_id);
                id.push_back(object_id);
                m_logic->m_map1.insert(id,Hpy);
                m_logic->m_map2.insert(Hpy,id);
                m_logic->aLL_B.push_back(Hpy);
                break;
              case 15:
                WS= new Woodland_Spirit;
                WS->the_logic = m_logic;
                id.push_back(card_id);
                id.push_back(object_id);
                m_logic->m_map1.insert(id,WS);
                m_logic->m_map2.insert(WS,id);
                m_logic->aLL_B.push_back(WS);
                break;
              case 16:
                EE = new Earth_Elemental;
                EE->the_logic = m_logic;
                id.push_back(card_id);
                id.push_back(object_id);
                m_logic->m_map1.insert(id,EE);
                m_logic->m_map2.insert(EE,id);
                m_logic->aLL_B.push_back(EE);
                break;
              case 17:
                CWss = new Crone_Weavess;
                CWss->the_logic = m_logic;
                id.push_back(card_id);
                id.push_back(object_id);
                m_logic->m_map1.insert(id,CWss);
                m_logic->m_map2.insert(CWss,id);
                m_logic->aLL_B.push_back(CWss);
                break;
              case 18:
                CWh = new Crone_Whispess;
                CWh->the_logic = m_logic;
                id.push_back(card_id);
                id.push_back(object_id);
                m_logic->m_map1.insert(id,CWh);
                m_logic->m_map2.insert(CWh,id);
                m_logic->aLL_B.push_back(CWh);
                break;
              case 19:
                CBss = new Crone_Brewess;
                CBss->the_logic = m_logic;
                id.push_back(card_id);
                id.push_back(object_id);
                m_logic->m_map1.insert(id,CBss);
                m_logic->m_map2.insert(CBss,id);
                m_logic->aLL_B.push_back(CBss);
                break;
              case 20:
                Ach = new Archgriffin;
                Ach->the_logic = m_logic;
                id.push_back(card_id);
                id.push_back(object_id);
                m_logic->m_map1.insert(id,Ach);
                m_logic->m_map2.insert(Ach,id);
                m_logic->aLL_B.push_back(Ach);
                break;
              case 21:
                Nth = new Wild_Hunt_Rider;
                Nth->the_logic = m_logic;
                id.push_back(card_id);
                id.push_back(object_id);
                m_logic->m_map1.insert(id,Nth);
                m_logic->m_map2.insert(Nth,id);
                m_logic->aLL_B.push_back(Nth);
                break;
              case 22:
                Cara = new Caranthir;
                Cara->the_logic = m_logic;
                id.push_back(card_id);
                id.push_back(object_id);
                m_logic->m_map1.insert(id,Cara);
                m_logic->m_map2.insert(Cara,id);
                m_logic->aLL_B.push_back(Cara);
                break;
              case 23:
                Ftn = new Frightener;
                Ftn->the_logic = m_logic;
                id.push_back(card_id);
                id.push_back(object_id);
                m_logic->m_map1.insert(id,Ftn);
                m_logic->m_map2.insert(Ftn,id);
                m_logic->aLL_B.push_back(Ftn);
                break;
              case 24:
                UE = new Unseen_Elder;
                UE->the_logic = m_logic;
                id.push_back(card_id);
                id.push_back(object_id);
                m_logic->m_map1.insert(id,UE);
                m_logic->m_map2.insert(UE,id);
                m_logic->aLL_B.push_back(UE);
                break;
              case 25:
                Arc = new Arachas;
                Arc->the_logic = m_logic;
                id.push_back(card_id);
                id.push_back(object_id);
                m_logic->m_map1.insert(id,Arc);
                m_logic->m_map2.insert(Arc,id);
                m_logic->aLL_B.push_back(Arc);
                break;
              case 26:
                AB = new Arachas_Behemoth;
                AB->the_logic = m_logic;
                id.push_back(card_id);
                id.push_back(object_id);
                m_logic->m_map1.insert(id,AB);
                m_logic->m_map2.insert(AB,id);
                m_logic->aLL_B.push_back(AB);
                break;
              case 27:
                VW = new Vran_Warrior;
                VW->the_logic = m_logic;
                id.push_back(card_id);
                id.push_back(object_id);
                m_logic->m_map1.insert(id,VW);
                m_logic->m_map2.insert(VW,id);
                m_logic->aLL_B.push_back(VW);
                break;
              case 28:
                SD = new Sunny_Day;
                SD->the_logic = m_logic;
                id.push_back(card_id);
                id.push_back(object_id);
                m_logic->m_map1.insert(id,SD);
                m_logic->m_map2.insert(SD,id);
                m_logic->aLL_B.push_back(SD);
                break;
              case 29:
                Rs = new Restart;
                Rs->the_logic = m_logic;
                id.push_back(card_id);
                id.push_back(object_id);
                m_logic->m_map1.insert(id,Rs);
                m_logic->m_map2.insert(Rs,id);
                m_logic->aLL_B.push_back(Rs);
                break;


              case 30:
                LE = new Lesser_Earth;
                LE->the_logic = m_logic;
                id.push_back(card_id);
                id.push_back(object_id);
                m_logic->m_map1.insert(id,LE);
                m_logic->m_map2.insert(LE,id);
                m_logic->aLL_B.push_back(LE);
                break;
              case 31:
                HE = new Harpy_Egg;
                HE->the_logic = m_logic;
                id.push_back(card_id);
                id.push_back(object_id);
                m_logic->m_map1.insert(id,HE);
                m_logic->m_map2.insert(HE,id);
                m_logic->aLL_B.push_back(HE);
                break;
              case 32:
                HC = new Harpy_Cub;
                HC->the_logic = m_logic;
                id.push_back(card_id);
                id.push_back(object_id);
                m_logic->m_map1.insert(id,HC);
                m_logic->m_map2.insert(HC,id);
                m_logic->aLL_B.push_back(HC);
                break;
              case 33:
                AL = new Arachas_Larva;
                AL->the_logic = m_logic;
                id.push_back(card_id);
                id.push_back(object_id);
                m_logic->m_map1.insert(id,AL);
                m_logic->m_map2.insert(AL,id);
                m_logic->aLL_B.push_back(AL);
                break;
              case 34:
                RW = new Raging_Wolf;
                RW->the_logic = m_logic;
                id.push_back(card_id);
                id.push_back(object_id);
                m_logic->m_map1.insert(id,RW);
                m_logic->m_map2.insert(RW,id);
                m_logic->aLL_B.push_back(RW);
                break;
                }
              }
         }

         int total = m_logic->aLL_B.size();
         qsrand(QTime::currentTime().msec());
         for (int i = 0 ;i < 1000 ; i++)
             m_logic->aLL_B.swap(qrand() % total,qrand() %total);

         for (int i = 0;i<10 ;i ++)
            m_logic->hand_B.push_back(m_logic->aLL_B.at(i));
         for (int i = 10;i<total;i++ )
             m_logic->library_B.push_back(m_logic->aLL_B.at(i));
         m_logic->step++;
    }

    if (m_logic->step == 1)
        reset();
    else if (m_logic->step == 2)
     {
        hide();
        emit FinishProcess();
     }
}

void PrepareBattle::reset()
{
    for (int i = 0;i<4 ;i++)
      show_card_name[1]->setDefaultTextColor(QColor(172,174,176));

    side->setPlainText(tr("请为B选牌"));
}

