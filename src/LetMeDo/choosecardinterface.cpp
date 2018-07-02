#include "choosecardinterface.h"
#include <QXmlStreamWriter>
#include <QString>
#include <QtXml>
#include <QFile>
#include <QDebug>
#define WindowWidth 1200
#define WindowHeight 750
#define LabelWidth  240
#define LabelHeight 300

ChooseCardInterface::ChooseCardInterface(QWidget *parent):
    QGraphicsView(parent)
{


    m_logic = new Card_Local_Logic;
    m_scene = new QGraphicsScene;
    m_scene ->setSceneRect(0,0,WindowWidth,WindowHeight);
    setMouseTracking(true);

    //btn
    confirm_btn = new MyButton;
    confirm = new QGraphicsWidget;
    back_btn = new MyButton ;
    back = new QGraphicsWidget;

    confirm_btn->pix = new QPixmap (":/images/Widgets/confirm.png");
    confirm_btn->pix_blue = new QPixmap (":/images/Widgets/confirm_blue.png");
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
    confirm_btn->move(460,680);
    back_btn->move(640,680);
    confirm =  m_scene->addWidget(confirm_btn);
    back  =  m_scene->addWidget(back_btn);

    //card_intro
    card_intro_label = new QLabel;
    card_intro = new QGraphicsWidget;
    card_intro_label->move(965,100);
    card_intro_label->resize(LabelWidth,LabelHeight);
    card_intro_label->setAttribute(Qt::WA_TranslucentBackground);
    card_intro_label->setScaledContents(true);
    card_intro = m_scene->addWidget(card_intro_label);
    card_intro_text = new QGraphicsTextItem;
    card_intro_text->setPos(995,430);
    card_intro_text->setTextWidth(190);
    card_intro_text->setDefaultTextColor(QColor(172,174,176));
    m_scene->addItem(card_intro_text);
    card_name_text = new QGraphicsTextItem;
    card_name_text->setPos(995,380);
    card_name_text->setFont(QFont(0,18));
    card_name_text->setTextWidth(250);
    card_name_text->setDefaultTextColor(QColor(172,174,176));
    m_scene->addItem(card_name_text);

    //SetText
    total_card = new QGraphicsTextItem;
    gold_card = new QGraphicsTextItem;
    silver_card = new QGraphicsTextItem;
    bronze_card = new QGraphicsTextItem;
    total_card->setPlainText(QString::number(m_logic->totalCard));
    gold_card->setPlainText(QString::number(m_logic->goldCard));
    silver_card->setPlainText(QString::number(m_logic->silverCard));
    bronze_card->setPlainText(QString::number(m_logic->bronzeCard));
    total_card->setPos(140,100);
    gold_card->setPos(175,293);
    silver_card->setPos(175,235);
    bronze_card->setPos(187,180);
    m_scene->addItem(total_card);
    m_scene->addItem(gold_card);
    m_scene->addItem(silver_card);
    m_scene->addItem(bronze_card);
    total_card->setDefaultTextColor(QColor(131,4,2));
    total_card->setFont(QFont(0,18));
    gold_card->setDefaultTextColor(QColor(172,174,176));
    gold_card->setFont(QFont(0,18));
    silver_card->setDefaultTextColor(QColor(172,174,176));
    silver_card->setFont(QFont(0,18));
    bronze_card->setDefaultTextColor(QColor(172,174,176));
    bronze_card->setFont(QFont(0,18));

    //setButton
    //all_row
    QPushButton* btn_l = new QPushButton;
    QPushButton* btn_r = new QPushButton;
    QPixmap l (":/images/Widgets/l_arrow.png");
    btn_l->setIcon(l);
    btn_l->setFixedSize(10,15);
    QPixmap r(":/images/Widgets/r_arrow.png");
    btn_r->setIcon(r);
    btn_r->setFixedSize(10,15);
    btn_l->move(225,575);
    btn_r->move(960,575);
    all_btn_l =  m_scene->addWidget(btn_l);
    all_btn_r =  m_scene->addWidget(btn_r);
    connect(btn_l,SIGNAL(clicked()),this,SLOT(all_btn_l_down()));
    connect(btn_r,SIGNAL(clicked()),this,SLOT(all_btn_r_down()));
    //row_4
    QPushButton *btn2_l = new QPushButton;
    QPushButton *btn2_r = new QPushButton;
    btn2_l->setIcon(l);
    btn2_l->setFixedSize(10,15);
    btn2_r->setIcon(r);
    btn2_r->setFixedSize(10,15);
    //btn2_r->setAttribute(Qt::WA_TranslucentBackground);
    btn2_r->move(935,400);
    btn2_l->move(255,400);
    row_4_btn_l =  m_scene->addWidget(btn2_l);
    row_4_btn_r =  m_scene->addWidget(btn2_r);
    connect(btn2_l,SIGNAL(clicked()),this,SLOT(row_4_l_down()));
    connect(btn2_r,SIGNAL(clicked()),this,SLOT(row_4_r_down()));

    //setBackground
    QPixmap *bkg = new QPixmap(":/images/Background/choose_card.png");
    setAutoFillBackground(true);
    QPixmap nbkg = bkg->scaled(QSize(WindowWidth,WindowHeight));
    setBackgroundBrush(nbkg);
    //initialize
    m_scene->addItem(m_logic->ALL_Selectable_Card[0]);
    m_scene->addItem(m_logic->ALL_Selectable_Card[1]);
    m_scene->addItem(m_logic->ALL_Selectable_Card[2]);
    m_scene->addItem(m_logic->ALL_Selectable_Card[3]);
    m_scene->addItem(m_logic->ALL_Selectable_Card[4]);
    m_scene->addItem(m_logic->ALL_Selectable_Card[5]);
    m_scene->addItem(m_logic->ALL_Selectable_Card[6]);
    m_scene->addItem(m_logic->ALL_Selectable_Card[7]);

    all_current_page = 1;
    if(m_logic->ALL_Selectable_Card.size()>8) all_newpage_end=7;
    else   all_newpage_end = m_logic->ALL_Selectable_Card.size()-1;

    row4_current_page = 1;
    if (m_logic->row_4.size()>7) row4_newpage_end = 6;
    else row4_newpage_end = m_logic->row_4.size()-1;

    //

    setScene(m_scene);
    resize(WindowWidth,WindowHeight);

}


void ChooseCardInterface::mousePressEvent(QMouseEvent *event)
{
    QGraphicsView::mousePressEvent(event);
    QPoint viewPos = event->pos();
    QPointF scenePos = mapToScene(viewPos);
    QGraphicsItem *selected = scene()->itemAt(scenePos,QTransform());

    if (selected == all_btn_l || selected ==all_btn_r
            || selected ==row_4_btn_l || selected == row_4_btn_r
            || selected == total_card || selected == gold_card
            || selected == silver_card || selected == bronze_card
            || selected == card_intro
            || selected == card_intro_text
            || selected == card_name_text
            || selected == confirm || selected == back
            ||selected ==NULL) return;

    Card* selected_card = static_cast<Card*>(selected);
    if(m_logic->SelectedCard.contains(selected_card))
    {
        m_logic->SelectedCard.removeOne(selected_card);
        m_logic->ALL_Selectable_Card.push_back(selected_card);

        if(selected_card->is_attendent == false ||
                selected_card->stand_position==4)
        {
            m_logic->row_4.removeOne(selected_card);
            if (row4_current_page*7 <= m_logic->row_4.size())
            {
                row4_newpage_end = row4_current_page*7-1;
                m_scene->addItem(m_logic->row_4[row4_newpage_end]);
            }
            else
                row4_newpage_end = m_logic->row_4.size()-1;
        }
        else if (selected_card->stand_position == 1)
            m_logic->row_1.removeOne(selected_card);
        else if (selected_card->stand_position == 2)
            m_logic->row_2.removeOne(selected_card);
        else if (selected_card->stand_position == 3)
            m_logic->row_3.removeOne(selected_card);

        if (all_newpage_end == all_current_page*8-1)
            m_scene->removeItem(selected_card);
        if (all_current_page*8< m_logic->ALL_Selectable_Card.size())
            all_newpage_end = all_current_page*8-1;
        else
            all_newpage_end = m_logic->ALL_Selectable_Card.size()-1;

        selected_card->same_name_num--;
        if (selected_card->quality ==3)
            m_logic->goldCard--;
        else if(selected_card->quality==2)
            m_logic->silverCard--;
        else if (selected_card->quality==1)
            m_logic->bronzeCard--;
        m_logic->totalCard--;
    }
    else
    {
        if (m_logic->silverCard==6&&selected_card->quality == 2)
            return;
        else if (m_logic->goldCard==4&&selected_card->quality == 3)
            return;
        if (selected_card->quality==1 && selected_card->same_name_num == 3)
            return;
        else if (selected_card->quality==2 && selected_card->same_name_num == 1)
            return;
        else if (selected_card->quality==3 && selected_card->same_name_num == 1)
            return;

        m_logic->ALL_Selectable_Card.removeOne(selected_card);
        m_logic->SelectedCard.push_back(selected_card);

        if (selected_card->quality == 2)
            m_logic->silverCard++;
        else if (selected_card->quality ==3)
            m_logic->goldCard++;
        else if (selected_card->quality ==1)
            m_logic->bronzeCard++;

        if(selected_card->is_attendent == false ||
               selected_card->stand_position==4)
        {
            m_logic->row_4.push_back(selected_card);
            if (row4_newpage_end == row4_current_page*7-1)
                m_scene->removeItem(selected_card);
            if (row4_current_page*7< m_logic->row_4.size())
                row4_newpage_end = row4_current_page*7-1;
            else
                row4_newpage_end = m_logic->row_4.size()-1;
        }
        else if (selected_card->stand_position == 1)
            m_logic->row_1.push_back(selected_card);
        else if (selected_card->stand_position == 2)
            m_logic->row_2.push_back(selected_card);
        else if (selected_card->stand_position == 3)
            m_logic->row_3.push_back(selected_card);

        if (all_current_page*8 <= m_logic->ALL_Selectable_Card.size())
        {
            all_newpage_end = all_current_page*8-1;
            m_scene->addItem(m_logic->ALL_Selectable_Card[all_newpage_end]);
        }
        else
            all_newpage_end = m_logic->ALL_Selectable_Card.size()-1;

        selected_card->same_name_num++;
        m_logic->totalCard++;
    }
    total_card->setPlainText(QString::number(m_logic->totalCard));
    gold_card->setPlainText(QString::number(m_logic->goldCard));
    silver_card->setPlainText(QString::number(m_logic->silverCard));
    bronze_card->setPlainText(QString::number(m_logic->bronzeCard));
    this->viewport()->update();
}

void ChooseCardInterface::paintEvent(QPaintEvent *event)
{
    int n = m_logic->row_1.size();
    for (int i = 0 ;i < n; i++)
    {
        m_logic->row_1[i]->setPos(380+i*80,95);
    }

    n = m_logic->row_2.size();
    for (int i = 0 ;i < n; i++)
    {
        m_logic->row_2[i]->setPos(380+i*80,180);
    }

    n = m_logic->row_3.size();
    for (int i = 0 ;i < n; i++)
    {
        m_logic->row_3[i]->setPos(380+i*80,265);
    }

    n = row4_newpage_end-row4_current_page*7+8;
    for (int i = 0 ;i < n; i++)
    {
        m_logic->row_4[row4_current_page*7-7+i]->setPos(320+i*80,360);
    }

    n = all_newpage_end - all_current_page*8+9;
    for (int i = 0 ;i < n; i++)
    {
        m_logic->ALL_Selectable_Card[all_current_page*8-8+i]->setPos(270+i*80,530);
    }
    QGraphicsView::paintEvent(event);
}

void ChooseCardInterface:: all_btn_l_down()
{
    if(all_current_page==1)
        return;
    int all_total_num = m_logic->ALL_Selectable_Card.size();
    int end;
    if (all_total_num<all_current_page*8)
        end = all_total_num-1;
    else
        end = all_current_page*8-1;

    for (int i=all_current_page*8-8;i<=end;i++)
        m_scene->removeItem(m_logic->ALL_Selectable_Card[i]);

    for (int i =all_current_page*8-16;i<=all_current_page*8-9;i++)
        m_scene->addItem(m_logic->ALL_Selectable_Card[i]);
    all_newpage_end = all_current_page*8-9;
    all_current_page--;
    this->viewport()->update();
}

void ChooseCardInterface::all_btn_r_down()
{
    int page_num = (m_logic->ALL_Selectable_Card.size()-1)/8+1;
    if (all_current_page == page_num)
        return;

    for (int i = all_current_page*8-8;i<=all_current_page*8-1;i++)
        m_scene->removeItem(m_logic->ALL_Selectable_Card[i]);

    if (all_current_page*8+8 < m_logic->ALL_Selectable_Card.size())
        all_newpage_end = all_current_page*8+7;
    else
        all_newpage_end = m_logic->ALL_Selectable_Card.size()-1;

    for (int i = all_current_page*8;i<=all_newpage_end;i++)
        m_scene->addItem(m_logic->ALL_Selectable_Card[i]);

    all_current_page++;
    this->viewport()->update();
}

void ChooseCardInterface::row_4_l_down()
{
    if(row4_current_page==1)
        return;
    int row4_total_num = m_logic->row_4.size();
    int end;
    if (row4_total_num<row4_current_page*7)
        end = row4_total_num-1;
    else
        end = row4_current_page*7-1;

    for (int i=row4_current_page*7-7;i<=end;i++)
        m_scene->removeItem(m_logic->row_4[i]);

    for (int i =row4_current_page*7-14;i<=row4_current_page*7-8;i++)
        m_scene->addItem(m_logic->row_4[i]);
    all_newpage_end = row4_current_page*7-8;
    row4_current_page--;
    this->viewport()->update();
}

void ChooseCardInterface::row_4_r_down()
{
    int page_num = (m_logic->row_4.size()-1)/7+1;
    if (row4_current_page == page_num)
        return;

    for (int i = row4_current_page*7-7;i<=row4_current_page*7-1;i++)
        m_scene->removeItem(m_logic->row_4[i]);

    if (row4_current_page*7+7 < m_logic->row_4.size())
        row4_newpage_end = row4_current_page*7+6;
    else
        row4_newpage_end = m_logic->row_4.size()-1;

    for (int i = row4_current_page*7;i<=row4_newpage_end;i++)
        m_scene->addItem(m_logic->row_4[i]);

    row4_current_page++;
    this->viewport()->update();
}

void ChooseCardInterface::mouseMoveEvent(QMouseEvent *event)
{
    QGraphicsView::mouseMoveEvent(event);
    QPoint viewPos = event->pos();
    QPointF scenePos = mapToScene(viewPos);
    QGraphicsItem *selected = scene()->itemAt(scenePos,QTransform());

    if (selected == all_btn_l || selected ==all_btn_r
            || selected ==row_4_btn_l || selected == row_4_btn_r
            || selected == total_card || selected == gold_card
            || selected == silver_card || selected == bronze_card
            || selected == card_intro
            || selected == card_intro_text
            || selected == card_name_text
            || selected == confirm || selected == back
            || selected ==NULL) return;

    Card* selected_card = static_cast<Card*>(selected);
    QPixmap p = *(selected_card->pix);
    card_intro_label->setPixmap(p);
    card_intro_text->setPlainText(selected_card->description);
    card_name_text->setPlainText(selected_card->card_name);
}

void ChooseCardInterface::write_ALLCARD()
{
    QString name = QDateTime::currentDateTime().toString();
    QFile file(file_dir+"/Prepared_Cards/"+name+".xml");
    if (!file.open(QFile::WriteOnly | QFile::Text))
    {
        qDebug()<<"Error:cannot open file";
        return;
    }
    QXmlStreamWriter m_writer(&file);
    m_writer.setAutoFormatting(true);
    m_writer.writeStartDocument();

    m_writer.writeStartElement(tr("Cards"));

    foreach(Card * i,m_logic->SelectedCard)
    {
        m_writer.writeStartElement("Card");
        m_writer.writeAttribute("card_id",QString("%1").arg(i->ID));
        m_writer.writeTextElement("object_id",QString("%1").arg(i->get_object_id()));
        m_writer.writeEndElement();
    }

    m_writer.writeEndElement();
    m_writer.writeEndDocument();
    file.close();
    qDebug()<<"write finished!";

}
