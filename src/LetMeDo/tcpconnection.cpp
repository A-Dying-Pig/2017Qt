#include "tcpconnection.h"
#include "cardlibrary.h"
#include <QtXml>
#include <QDebug>


TcpConnection::TcpConnection()
{
    //IPAddress and Server Port init
    wait_timer = new QTimer;
    wait_timer->setInterval(TurnWaitTime);
    wait_timer2 = new QTimer;
    wait_timer2->setInterval(WaitTime);

    ready = false;
    ip_address = QString("47.94.253.51");
    server_port = 63238;
    //
    m_socket1 = new QTcpSocket;
    m_socket1->abort();
    m_socket = new QTcpSocket;
    m_socket->abort();

    connect_order = new QTimer;
    connect_order ->setInterval(3000);
    connect(connect_order,SIGNAL(timeout()),this,SLOT(connect2()));
    connect1();
    //signals
    connect (m_socket,&QIODevice::readyRead,this,&TcpConnection::receive_turn_info);
   // connect (m_socket1,&QIODevice::readyRead,this,&TcpConnection::receive_ALLCARD_data);
}

void TcpConnection::connect1()
{
    m_socket1->connectToHost(ip_address,server_port);
    emit connect_order->start();
}

void TcpConnection::connect2()
{
    connect_order->stop();
    m_socket->connectToHost(ip_address,server_port);
}


void TcpConnection::receive_ALLCARD_data()
{
    wait_timer2->stop();
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

    bool is_handcard = false;
    QByteArray data = m_socket1->readAll();
    qDebug()<<"receive_ALLCARD_info"<<data;

    QFile file ("youCards.xml");
    file.open(QFile::WriteOnly | QFile::Text);
    file.write(data);
    file.close();
    if (!file.open(QIODevice::ReadOnly)) return;
    QDomDocument doc;
    doc.setContent(&file);
    file.close();


    QDomNode firstNode = doc.firstChild();
    QDomElement docElem = doc.documentElement();
    QDomNode n = docElem.firstChild();

    int card_id,object_id;
    QList<int> id;

    if (m_logic->paint_side)
    {

            m_logic->hand_B.clear();
            m_logic->library_B.clear();
            while(!n.isNull())
           {
              QDomElement e = n.toElement();
              if(e.tagName() == "hand_card")
                   is_handcard = true;
              card_id = e.attribute("id").toInt();
              object_id = e.text().toInt();
              id.clear();
                    if (m_logic->round == 0)
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
                      m_logic->m_map1.insert(id,Ftn);
                      m_logic->m_map2.insert(Ftn,id);
                      m_logic->aLL_B.push_back(Ftn);
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
                    if (is_handcard)
                    {
                        m_logic->hand_B.push_back(m_logic->m_map1.find(id).value());
                        is_handcard = false;
                    }
                    else
                        m_logic->library_B.push_back(m_logic->m_map1.find(id).value());
                    n.nextSibling();
              }

    }
    else
    {
        m_logic->hand_A.clear();
        m_logic->library_A.clear();
        while(!n.isNull())
       {
          QDomElement e = n.toElement();
          if(e.tagName() == "hand_card")
               is_handcard = true;
          card_id = e.attribute("id").toInt();
          object_id = e.text().toInt();
          id.clear();
                if (m_logic->round == 0)
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
                  m_logic->aLL_A.push_back(Ftn);
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
                if (is_handcard)
                {
                    m_logic->hand_A.push_back(m_logic->m_map1.find(id).value());
                    is_handcard = false;
                }
                else
                    m_logic->library_A.push_back(m_logic->m_map1.find(id).value());
            n = n.nextSibling();
          }

    }

    emit FinishALLCARD();
}

void TcpConnection::send_ALLCARD()
{
    QByteArray data;

    QDomDocument doc;
    QDomProcessingInstruction instruction;
    instruction = doc.createProcessingInstruction
            ("xml","version =\"1.0\"encoding = \"UTF - 8\"");
    doc.appendChild(instruction);
    QDomElement root = doc.createElement("Card");
    doc.appendChild(root);

    if (m_logic->paint_side)
    {
         foreach(Card * i,m_logic->hand_A)
         {
             QDomElement hand_card = doc.createElement("hand_card");
             QDomAttr id = doc.createAttribute("id");
             QDomElement object = doc.createElement("object_id");
             QDomText text;
             id.setValue(QString("%1").arg(i->ID));
             hand_card.setAttributeNode(id);
             text = doc.createTextNode(QString("%1").arg(m_logic->m_map2.find(i).value()[1]));
             object.appendChild(text);
             hand_card.appendChild(object);
             root.appendChild(hand_card);
         }
         foreach(Card * i,m_logic->library_A)
         {
             QDomElement hand_card = doc.createElement("card");
             QDomAttr id = doc.createAttribute("id");
             QDomElement object = doc.createElement("object_id");
             QDomText text;
             id.setValue(QString("%1").arg(i->ID));
             hand_card.setAttributeNode(id);
             text = doc.createTextNode(QString("%1").arg(m_logic->m_map2.find(i).value()[1]));
             object.appendChild(text);
             hand_card.appendChild(object);
             root.appendChild(hand_card);
         }
    }
    else
    {
        foreach(Card * i,m_logic->hand_B)
        {
            QDomElement hand_card = doc.createElement("hand_card");
            QDomAttr id = doc.createAttribute("id");
            QDomElement object = doc.createElement("object_id");
            QDomText text;
            id.setValue(QString("%1").arg(i->ID));
            hand_card.setAttributeNode(id);
            text = doc.createTextNode(QString("%1").arg(m_logic->m_map2.find(i).value()[1]));
            object.appendChild(text);
            hand_card.appendChild(object);
            root.appendChild(hand_card);
        }
        foreach(Card * i,m_logic->library_B)
        {
            QDomElement hand_card = doc.createElement("card");
            QDomAttr id = doc.createAttribute("id");
            QDomElement object = doc.createElement("object_id");
            QDomText text;
            id.setValue(QString("%1").arg(i->ID));
            hand_card.setAttributeNode(id);
            text = doc.createTextNode(QString("%1").arg(m_logic->m_map2.find(i).value()[1]));
            object.appendChild(text);
            hand_card.appendChild(object);
            root.appendChild(hand_card);
        }
    }


    QFile file("/Users/poolei/Documents/LetMeDo/Cards/myCards.xml");
    if (!file.open(QFile::WriteOnly | QFile::Truncate))
    {
        return;
        qDebug()<<"error: file cannot open";
    }
    QTextStream out(&file);
    doc.save(out,4);
    file.close();

    file.open(QFile::ReadOnly | QFile::Text);
    data = file.readAll();
    m_socket1->write(data);
    emit ReceiveALLCARD();

}
void TcpConnection::send_turn_info()
{
    QByteArray data;
    QDataStream out(&data,QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_6);
    QFile file("/Users/poolei/Documents/Programme/LetMeDo/Cards/myTurn.xml");
    if (!file.open(QFile::WriteOnly | QFile::Text))
    {
        return;
        qDebug()<<"error: file cannot open";
    }
    m_writer.setDevice(&file);
    m_writer.setAutoFormatting(true);
    int obj_id;


    m_writer.writeStartDocument();
         //Turn Card
         m_writer.writeStartElement("turn_card");
         if (m_logic->turn_card != NULL)
         {
             m_writer.writeAttribute("turn_card",QString("%1").arg(m_logic->turn_card->ID));
             obj_id = m_logic->m_map2.find(m_logic->turn_card).value()[1];
             m_writer.writeTextElement("object_id",QString("%1").arg(obj_id));
         }
         else
         {
             m_writer.writeAttribute("turn_card","0");
             m_writer.writeTextElement("object_id","0");
         }

         m_writer.writeEndElement();

         //stand_row
         if(m_logic->turn_card!=NULL && m_logic->turn_card->is_attendent)
         {
         m_writer.writeStartElement("stand_row");
         m_writer.writeAttribute("stand_row",QString("%1").arg(m_logic->turn_card->stand_row));
         m_writer.writeEndElement();
         }

         //stop_putting
         if (m_logic->paint_side)
         {
             m_writer.writeStartElement("stop");
             if(m_logic->A_stop_putting)
                    m_writer.writeAttribute("stop","1");
             else
                    m_writer.writeAttribute("stop","0");
             m_writer.writeTextElement("side","1");
             m_writer.writeEndElement();
         }
         else
         {
             m_writer.writeStartElement("stop");
             if(m_logic->B_stop_putting)
                    m_writer.writeAttribute("stop","1");
             else
                    m_writer.writeAttribute("stop","0");
             m_writer.writeTextElement("side","0");
             m_writer.writeEndElement();
         }

         //target
         if(m_logic->turn_card != NULL && !m_logic->turn_card->target.isEmpty())
         {
             foreach(Card *i ,m_logic->turn_card->target)
             {
             m_writer.writeStartElement("target");
             m_writer.writeAttribute("target",QString("%1").arg(i->ID));
             obj_id = m_logic->m_map2.find(i).value()[1];
             m_writer.writeTextElement("object_id",QString("%1").arg(obj_id));
             m_writer.writeEndElement();
             }
         }
         m_writer.writeEndDocument();

    file.close();
    file.open(QFile::ReadOnly | QFile::Text);
    out<<file.readAll();
    m_socket->write(data);

}

void TcpConnection::receive_turn_info()
{
    wait_timer->stop();
    QByteArray data = m_socket->readAll();
    qDebug()<<"receive turn_info"<<data;

    QFile file ("youTurn.xml");
    file.open(QFile::WriteOnly | QFile::Text);
    QTextStream write_in_file(&file);
    write_in_file<<data;
    file.close();

    file.open(QFile::ReadOnly| QFile::Text);
    m_reader.setDevice(&file);

    int card_id,object_id;
    QList<int> id;
    bool is_card;
    int stop;

    m_logic->turn_card = NULL;

    while(!m_reader.atEnd())
   {
      QXmlStreamReader::TokenType type = m_reader.readNext();

      //turn_card and target
      if (type == QXmlStreamReader::StartElement)
       {
           if (m_reader.attributes().hasAttribute("turn_card"))
             {
               card_id = m_reader.attributes().value("turn_card").toInt();
               is_card = true;
             }
           if (m_reader.attributes().hasAttribute("target"))
             {
               card_id = m_reader.attributes().value("target").toInt();
               is_card = true;
              }
       }
       if (type == QXmlStreamReader::Characters && !m_reader.isWhitespace() && is_card)
       {
            object_id = m_reader.text().toInt();
            id.push_back(card_id);
            id.push_back(object_id);
            m_logic->turn_card = m_logic->m_map1.find(id).value();
            is_card  = false;
       }

       //stand_row
       if (QXmlStreamReader::StartElement )
       {
           if (m_reader.attributes().hasAttribute("stand_row"))
                     m_logic->turn_card->stand_row = m_reader.attributes().value("stand_row").toInt();
       }

       //effect_row
       if (QXmlStreamReader::StartElement )
       {
           if (m_reader.attributes().hasAttribute("effect_row"))
                     m_logic->turn_card->stand_row = m_reader.attributes().value("effect_row").toInt();
       }

       //stop_putting
       if (type == QXmlStreamReader::StartElement)
       {
           if (m_reader.attributes().hasAttribute("stop"))
                       stop = m_reader.attributes().value("stop").toInt();
       }
       if (type == QXmlStreamReader::Characters && !m_reader.isWhitespace() && !is_card)
       {
           if (m_reader.text().toInt())
               m_logic->A_stop_putting = stop;
           else
               m_logic->B_stop_putting = stop;
       }
   }


    if (m_logic->turn_card != NULL)
   {
        if (m_logic->order)
      {
        m_logic->hand_A.removeOne(m_logic->turn_card);
        if(m_logic->turn_card->is_attendent)
        {
            if (m_logic->turn_card->stand_row == 1)
                m_logic->row_1_A.push_back(m_logic->turn_card);
            else if (m_logic->turn_card->stand_row == 2)
                m_logic->row_2_A.push_back(m_logic->turn_card);
            else if (m_logic->turn_card->stand_row == 3)
                m_logic->row_3_A.push_back(m_logic->turn_card);
        }
       }
    else
        {
             m_logic->hand_A.removeOne(m_logic->turn_card);
            if(m_logic->turn_card->is_attendent)
             {
            if (m_logic->turn_card->stand_row == 1)
                m_logic->row_1_B.push_back(m_logic->turn_card);
            else if (m_logic->turn_card->stand_row == 2)
                m_logic->row_2_B.push_back(m_logic->turn_card);
            else if (m_logic->turn_card->stand_row == 3)
                m_logic->row_3_B.push_back(m_logic->turn_card);
            }
         }
    }
    else
    {
        if(m_logic->order)
            m_logic->A_stop_putting = true;
        else
            m_logic->B_stop_putting = true;
    }

    emit m_logic->PaintView();
    emit m_logic->TurnChanged();
}

