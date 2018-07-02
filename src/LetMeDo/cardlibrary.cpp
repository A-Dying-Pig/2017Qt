#include "cardlibrary.h"
#include <QPixmap>
#include <QPainter>
#include <QDebug>
#include <QTime>
#include "game_local_logic.h"

//Biting_Frost
int Biting_Frost::total_object_id = 0;
int First_Light::total_object_id = 0;
int Impenetrable_Fog::total_object_id = 0;
int Lacerate::total_object_id = 0;
int Torrential_Rain::total_object_id = 0;
int Immune_Boost::total_object_id = 0;
int Commanders_Horn::total_object_id = 0;
int Bekkers_Twisted_Mirror::total_object_id = 0;
int Geralt_Igni::total_object_id = 0;
int Dagon::total_object_id = 0;
int Foglet::total_object_id = 0;
int Geels::total_object_id = 0;
int Celaeno_Harpy::total_object_id = 0;
int Harpy::total_object_id = 0;
int Woodland_Spirit::total_object_id = 0;
int Earth_Elemental::total_object_id = 0;
int Crone_Weavess::total_object_id = 0;
int Crone_Whispess::total_object_id = 0;
int Crone_Brewess::total_object_id = 0;
int Archgriffin::total_object_id = 0;
int Wild_Hunt_Rider::total_object_id = 0;
int Caranthir::total_object_id = 0;
int Frightener::total_object_id = 0;
int Unseen_Elder::total_object_id = 0;
int Arachas::total_object_id = 0;
int Arachas_Behemoth::total_object_id = 0;
int Vran_Warrior::total_object_id = 0;
int Sunny_Day::total_object_id = 0;
int Restart::total_object_id = 0;
int Lesser_Earth::total_object_id = 0;
int Harpy_Egg::total_object_id = 0;
int Harpy_Cub::total_object_id = 0;
int Arachas_Larva::total_object_id = 0;
int Raging_Wolf::total_object_id = 0;
int Roach::total_object_id = 0;



bool Biting_Frost::has_switched = false;
bool First_Light::has_switched = false;
bool Impenetrable_Fog::has_switched = false;
bool Lacerate::has_switched = false;
bool Torrential_Rain::has_switched = false;
bool Immune_Boost::has_switched = false;
bool Commanders_Horn::has_switched = false;
bool Bekkers_Twisted_Mirror::has_switched = false;
bool Geralt_Igni::has_switched = false;
bool Dagon::has_switched = false;
bool Foglet::has_switched = false;
bool Geels::has_switched = false;
bool Celaeno_Harpy::has_switched = false;
bool Harpy::has_switched = false;
bool Woodland_Spirit::has_switched = false;
bool Earth_Elemental::has_switched = false;
bool Crone_Weavess::has_switched = false;
bool Crone_Whispess::has_switched = false;
bool Crone_Brewess::has_switched = false;
bool Archgriffin::has_switched = false;
bool Wild_Hunt_Rider::has_switched = false;
bool Caranthir::has_switched = false;
bool Frightener::has_switched = false;
bool Unseen_Elder::has_switched = false;
bool Arachas::has_switched = false;
bool Arachas_Behemoth::has_switched = false;
bool Vran_Warrior::has_switched = false;
bool Sunny_Day::has_switched = false;
bool Restart::has_switched = false;
bool Lesser_Earth::has_switched = false;
bool Harpy_Egg::has_switched = false;
bool Harpy_Cub::has_switched = false;
bool Arachas_Larva::has_switched = false;
bool Raging_Wolf::has_switched = false;
bool Roach::has_switched = false;

Biting_Frost::Biting_Frost()
{
    total_object_id++;is_lord = false;loyality = true;race = 0;
    shield = false;
    object_id = total_object_id;
    can_revive = true;

    is_active = false;
    the_chosen = NULL;
    hurt = 2;

    is_weather = true;
    is_selecting = false;
    is_put_another = false;

    ID = 1;
    strength = 0;
    armor = 0;
    party = 1;
    quality = 1;
    lock =  false;

    is_choosing_enemy = -1;            // -1: no choose,0:enemy; 1:friend;2:al
    is_choosing_row = 2;
    is_attendent = false;
    pix = new QPixmap(":/images/CardImage/Neutral/Biting_Frost.png");
    show_front = true;
    back = new QPixmap(":/images/Widgets/Card_Back.png");
    description = QObject::tr("在对方单排降下\"刺骨冰霜\"。\r\r刺骨冰霜：每当己方回合开始时，对所在排最弱的单个单位造成2点伤害。");
    card_name = QObject::tr("刺骨冰霜 ");
}
QRectF Biting_Frost::boundingRect() const
{
    qreal penWidth = 1;
    return QRectF (0 - penWidth,0-penWidth,PixmapWidth + penWidth,PixmapHeight+ penWidth);
}

void Biting_Frost::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{

    if (show_front)
        painter-> drawPixmap(0,0,PixmapWidth,PixmapHeight,*pix);
    else
        painter-> drawPixmap(0,0,PixmapWidth,PixmapHeight,*back);
}

int Biting_Frost::eaten_strength()
{return 0;}

void Biting_Frost::before_turncard_effect()
{}

void Biting_Frost::set_alternatives()
{}

void Biting_Frost::card_effect()
{}
void Biting_Frost:: card_library_effect ()
{

}

void Biting_Frost:: card_hand_effect ()
{}

void Biting_Frost::card_turn_end_effect ()
{}

void Biting_Frost::card_death_effect ()
{}

void Biting_Frost::card_round_end_effect ()
{}

void Biting_Frost::card_in_tomb_effect ()
{}

void Biting_Frost::card_lord_effect ()
{}

void Biting_Frost::card_turn_begin_effect ()
{
    int lowest= 999;
    is_active = true;
    target.clear();
    if (the_logic->order)
    {
         if(effect_row == 3)
        {
            foreach(Card *i,the_logic->row_3_B)
                if (i->is_attendent && lowest > i->strength)
                    lowest = i->strength;

            foreach(Card *i,the_logic->row_3_B)
                if (i->strength == lowest)
                    target.push_back(i);
         }
        else if (effect_row == 2)
        {
            foreach(Card *i,the_logic->row_2_B)
                if (i->is_attendent && lowest > i->strength)
                     lowest = i->strength;

            foreach(Card *i,the_logic->row_2_B)
                if (i->strength == lowest)
                    target.push_back(i);
        }
        else if (effect_row == 1)
        {
            foreach(Card *i,the_logic->row_1_B)
                if (i->is_attendent && lowest > i->strength)
                     lowest = i->strength;

            foreach(Card *i,the_logic->row_1_B)
                if (i->strength == lowest)
                    target.push_back(i);
        }
    }
    else
    {
        if(effect_row == 3)
       {
           foreach(Card *i,the_logic->row_3_A)
               if (i->is_attendent && lowest > i->strength)
                  lowest = i->strength;

           foreach(Card *i,the_logic->row_3_A)
               if (i->strength == lowest)
                   target.push_back(i);
        }
       else if (effect_row == 2)
       {
           foreach(Card *i,the_logic->row_2_A)
               if (i->is_attendent && lowest > i->strength)
                     lowest = i->strength;
           foreach(Card *i,the_logic->row_2_A)
               if (i->strength == lowest)
                   target.push_back(i);
       }
       else if (effect_row == 1)
       {
           foreach(Card *i,the_logic->row_1_A)
               if (i->is_attendent && lowest > i->strength)
                    lowest = i->strength;

           foreach(Card *i,the_logic->row_1_A)
               if (i->strength == lowest)
                   target.push_back(i);
       }
    }
    if (!target.isEmpty())
    {
        foreach(Card *i,target)
             {
                if(i->shield)
                    i->shield = false;
                else
                    i->strength -=hurt;
             }
    }
}


//First_Light



First_Light::First_Light()
{
    ID = 2;
    total_object_id++;is_lord = false;loyality = true;race = 0;shield = false;
    object_id = total_object_id;can_revive = true;

    is_weather = false;
    is_selecting = true;
    is_put_another = true;

    the_chosen = NULL;
    hurt = 0;

    strength = 0;
    armor = 0;
    party = 1;
    quality = 1;
    lock =  false;
    same_name_num = 0;

    is_choosing_enemy = -1;            // -1: no choose,0:enemy; 1:friend;2:all
    is_choosing_row = -1;               // -1:no choose,0:enemy;1 friend;2 all
    is_attendent = false;
    pix = new QPixmap(":/images/CardImage/Neutral/First_Light.png");
    show_front = true;
    back = new QPixmap(":/images/Widgets/Card_Back.png");
    description = QObject::tr("生成\"晴空\"或\"重整\"。");
    card_name = QObject::tr("破晓");
}

QRectF First_Light::boundingRect() const
{
    qreal penWidth = 1;
    return QRectF (0 - penWidth,0-penWidth,PixmapWidth + penWidth,PixmapHeight + penWidth);
}

void First_Light::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{

    if (show_front)
        painter-> drawPixmap(0,0,PixmapWidth,PixmapHeight,*pix);
    else
        painter-> drawPixmap(0,0,PixmapWidth,PixmapHeight,*back);
}

int First_Light::eaten_strength()
{return 0;}

void First_Light::before_turncard_effect()
{}

void First_Light::set_alternatives()
{
    Sunny_Day *sd = new Sunny_Day;
    Restart *r = new Restart;
    sd->the_logic = the_logic;
    r->the_logic = the_logic;
    alternative.push_back(sd);
    alternative.push_back(r);

}

void First_Light:: card_library_effect ()
{}

void First_Light:: card_hand_effect ()
{}

void First_Light::card_turn_end_effect ()
{}

void First_Light::card_death_effect ()
{}

void First_Light::card_round_end_effect ()
{}

void First_Light::card_in_tomb_effect ()
{}

void First_Light::card_lord_effect ()
{}

void First_Light::card_turn_begin_effect ()
{}

void First_Light::card_effect()
{}

//Impenetrable_Fog


Impenetrable_Fog::Impenetrable_Fog()
{
    ID = 3;
    total_object_id++;is_lord = false;loyality = true;race = 0;shield = false;
    object_id = total_object_id;can_revive = true;
    strength = 0;
    armor = 0;
    party = 1;
    quality = 1;
    lock =  false;
    is_active = false;

    the_chosen = NULL;
    hurt = 2;

    is_weather = true;
    is_selecting = false;
    is_put_another = false;

    is_choosing_enemy = -1;            // -1: no choose,0:enemy; 1:friend;2:all
    is_choosing_row = 0;               // -1:no choose,0:enemy;1 friend;2 all
    is_attendent = false;
    pix = new QPixmap(":/images/CardImage/Neutral/Impenetrable_Fog.png");
    show_front = true;
    back = new QPixmap(":/images/Widgets/Card_Back.png");
    description = QObject::tr("在对方单排降下\"蔽日浓雾\"。\r\r蔽日浓雾：每当己方回合开始时，对所在排最强的单位造成2点伤害。");
    card_name = QObject::tr("蔽日浓雾");
}

QRectF Impenetrable_Fog::boundingRect() const
{
    qreal penWidth = 1;
    return QRectF (0 - penWidth,0-penWidth,PixmapWidth + penWidth,PixmapHeight + penWidth);
}

void Impenetrable_Fog::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{

    if (show_front)
        painter-> drawPixmap(0,0,PixmapWidth,PixmapHeight,*pix);
    else
        painter-> drawPixmap(0,0,PixmapWidth,PixmapHeight,*back);
}

int Impenetrable_Fog::eaten_strength()
{return 0;}

void Impenetrable_Fog::before_turncard_effect()
{}


void Impenetrable_Fog::set_alternatives()
{}

void Impenetrable_Fog:: card_library_effect ()
{}

void Impenetrable_Fog:: card_hand_effect ()
{}

void Impenetrable_Fog::card_turn_end_effect ()
{}

void Impenetrable_Fog::card_death_effect ()
{}

void Impenetrable_Fog::card_round_end_effect ()
{}

void Impenetrable_Fog::card_in_tomb_effect ()
{}

void Impenetrable_Fog::card_lord_effect ()
{}

void Impenetrable_Fog::card_turn_begin_effect ()
{
    int highest= 0;
    target.clear();
    is_active = true;
    if (the_logic->order)
    {
         if(effect_row == 3)
        {
            foreach(Card *i,the_logic->row_3_B)
                if (i->is_attendent && highest < i->strength)
                    highest = i->strength;

            foreach(Card *i,the_logic->row_3_B)
                if (i->strength == highest)
                    target.push_back(i);
         }
        else if (effect_row == 2)
        {
            foreach(Card *i,the_logic->row_2_B)
                if (i->is_attendent && highest < i->strength)
                     highest = i->strength;

            foreach(Card *i,the_logic->row_2_B)
                if (i->strength == highest)
                    target.push_back(i);
        }
        else if (effect_row == 1)
        {
            foreach(Card *i,the_logic->row_1_B)
                if (i->is_attendent && highest < i->strength)
                     highest = i->strength;

            foreach(Card *i,the_logic->row_1_B)
                if (i->strength == highest)
                    target.push_back(i);
        }
    }
    else
    {
        if(effect_row == 3)
       {
           foreach(Card *i,the_logic->row_3_A)
               if (i->is_attendent && highest < i->strength)
                  highest = i->strength;

           foreach(Card *i,the_logic->row_3_A)
               if (i->strength == highest)
                   target.push_back(i);
        }
       else if (effect_row == 2)
       {
           foreach(Card *i,the_logic->row_2_A)
               if (i->is_attendent && highest < i->strength)
                     highest = i->strength;
           foreach(Card *i,the_logic->row_2_A)
               if (i->strength == highest)
                   target.push_back(i);
       }
       else if (effect_row == 1)
       {
           foreach(Card *i,the_logic->row_1_A)
               if (i->is_attendent && highest < i->strength)
                    highest = i->strength;

           foreach(Card *i,the_logic->row_1_A)
               if (i->strength == highest)
                   target.push_back(i);
       }
   }
    if (!target.isEmpty())
    {
        foreach(Card* i ,target)
        {
           if(i->shield)
               i->shield = false;
           else
               i->strength -=hurt;
        }
    }
}

void Impenetrable_Fog::card_effect()
{}
//Lacerate


Lacerate::Lacerate()
{
    ID = 4;
    total_object_id++;is_lord = false;loyality = true;race = 0;shield = false;
    object_id = total_object_id;can_revive = true;
    strength = 0;
    armor = 0;
    party = 1;
    quality = 1;
    lock =  false;

    the_chosen = NULL;
    hurt = 3;

    is_weather = false;
    is_selecting = false;
    is_put_another = false;

    is_choosing_enemy = -1;            // -1: no choose,0:enemy; 1:friend;2:all
    is_choosing_row = 0;               // -1:no choose,0:enemy;1 friend;2 all
    is_attendent = false;
    pix = new QPixmap(":/images/CardImage/Neutral/Lacerate.png");
    show_front = true;
    back = new QPixmap(":/images/Widgets/Card_Back.png");
    description = QObject::tr("对单排所有单位造成3点伤害。");
    card_name = QObject::tr("撕裂");
}

QRectF Lacerate::boundingRect() const
{
    qreal penWidth = 1;
    return QRectF (0 - penWidth,0-penWidth,PixmapWidth + penWidth,PixmapHeight+ penWidth);
}

void Lacerate::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{

    if (show_front)
        painter-> drawPixmap(0,0,PixmapWidth,PixmapHeight,*pix);
    else
        painter-> drawPixmap(0,0,PixmapWidth,PixmapHeight,*back);
}
void Lacerate::card_effect()
{
    if (the_logic->order)
    {
         if(effect_row == 3)
        {
            foreach(Card *i,the_logic->row_3_B)
            {
                if (i->is_attendent)
                {
                   if(i->shield)
                       i->shield = false;
                   else
                       i->strength -=hurt;
                }
            }
         }
        else if (effect_row == 2)
        {
            foreach(Card *i,the_logic->row_2_B)
            {
                if (i->is_attendent)
                {
                   if(i->shield)
                       i->shield = false;
                   else
                       i->strength -=hurt;
                }
            }
        }
        else if (effect_row == 1)
        {
            foreach(Card *i,the_logic->row_1_B)
            {
                if (i->is_attendent)
                {
                   if(i->shield)
                       i->shield = false;
                   else
                       i->strength -=hurt;
                }
            }
        }
    }
    else
    {
        if(effect_row == 3)
       {
           foreach(Card *i,the_logic->row_3_A)
           {
               if (i->is_attendent)
               {
                  if(i->shield)
                      i->shield = false;
                  else
                      i->strength -=hurt;
               }
           }
        }
       else if (effect_row == 2)
       {
           foreach(Card *i,the_logic->row_2_A)
           {
               if (i->is_attendent)
               {
                  if(i->shield)
                      i->shield = false;
                  else
                      i->strength -=hurt;
               }
           }
       }
       else if (effect_row == 1)
       {
           foreach(Card *i,the_logic->row_1_A)
           {
               if (i->is_attendent)
               {
                  if(i->shield)
                      i->shield = false;
                  else
                      i->strength -=hurt;
               }
           }
       }
    }

}

void Lacerate::set_alternatives()
{}
void Lacerate:: card_library_effect ()
{}

int Lacerate::eaten_strength()
{return 0;}

void Lacerate::before_turncard_effect()
{}


void Lacerate:: card_hand_effect ()
{}

void Lacerate::card_turn_end_effect ()
{}

void Lacerate::card_death_effect ()
{}

void Lacerate::card_round_end_effect ()
{}

void Lacerate::card_in_tomb_effect ()
{}

void Lacerate::card_lord_effect ()
{}

void Lacerate::card_turn_begin_effect ()
{}

//Torrential_Rainv


Torrential_Rain::Torrential_Rain()
{
    ID = 5;
    total_object_id++;is_lord = false;loyality = true;race = 0;shield = false;
    object_id = total_object_id;can_revive = true;
    strength = 0;
    armor = 0;
    party = 1;
    quality = 1;
    lock =  false;
    is_active = false;

    the_chosen = NULL;
    hurt = 1;

    is_weather = true;
    is_selecting = false;
    is_put_another = false;

    is_choosing_enemy = -1;            // -1: no choose,0:enemy; 1:friend;2:all
    is_choosing_row = 0;               // -1:no choose,0:enemy;1 friend;2 all
    is_attendent = false;
    pix = new QPixmap(":/images/CardImage/Neutral/Torrential_Rain.png");
    show_front = true;
    back = new QPixmap(":/images/Widgets/Card_Back.png");
    description  = QObject::tr("在对方单排降下\"倾盆大雨\"。\r\r倾盆大雨：每当己方回合开始时，对所在排最多5个最弱的单位造成1点伤害。");
    card_name = QObject::tr("倾盆大雨");
}

QRectF Torrential_Rain::boundingRect() const
{
    qreal penWidth = 1;
    return QRectF (0 - penWidth,0-penWidth,PixmapWidth+ penWidth,PixmapHeight + penWidth);
}

void Torrential_Rain::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{

    painter-> drawPixmap(0,0,PixmapWidth,PixmapHeight,*pix);
}

int Torrential_Rain::eaten_strength()
{return 0;}

void Torrential_Rain::before_turncard_effect()
{}


void Torrential_Rain::card_effect()
{}

void Torrential_Rain::set_alternatives()
{}

void Torrential_Rain:: card_library_effect ()
{}

void Torrential_Rain:: card_hand_effect ()
{}

void Torrential_Rain::card_turn_end_effect ()
{}

void Torrential_Rain::card_death_effect ()
{}

void Torrential_Rain::card_round_end_effect ()
{}

void Torrential_Rain::card_in_tomb_effect ()
{}

void Torrential_Rain::card_lord_effect ()
{}

void Torrential_Rain::card_turn_begin_effect ()
{
    int lowest= 999;
    target.clear();
    is_active = true;
    if (the_logic->order)
    {
         if(effect_row == 3)
        {
            foreach(Card *i,the_logic->row_3_B)
                if (i->is_attendent && lowest > i->strength)
                    lowest = i->strength;

            foreach(Card *i,the_logic->row_3_B)
                if (i->strength == lowest)
                    target.push_back(i);
         }
        else if (effect_row == 2)
        {
            foreach(Card *i,the_logic->row_2_B)
                if (i->is_attendent && lowest > i->strength)
                     lowest = i->strength;

            foreach(Card *i,the_logic->row_2_B)
                if (i->strength == lowest)
                    target.push_back(i);
        }
        else if (effect_row == 1)
        {
            foreach(Card *i,the_logic->row_1_B)
                if (i->is_attendent && lowest > i->strength)
                     lowest = i->strength;

            foreach(Card *i,the_logic->row_1_B)
                if (i->strength == lowest)
                    target.push_back(i);
        }
    }
    else
    {
        if(effect_row == 3)
       {
           foreach(Card *i,the_logic->row_3_A)
               if (i->is_attendent && lowest > i->strength)
                  lowest = i->strength;

           foreach(Card *i,the_logic->row_3_A)
               if (i->strength == lowest)
                   target.push_back(i);
        }
       else if (effect_row == 2)
       {
           foreach(Card *i,the_logic->row_2_A)
               if (i->is_attendent && lowest > i->strength)
                     lowest = i->strength;
           foreach(Card *i,the_logic->row_2_A)
               if (i->strength == lowest)
                   target.push_back(i);
       }
       else if (effect_row == 1)
       {
           foreach(Card *i,the_logic->row_1_A)
               if (i->is_attendent && lowest > i->strength)
                    lowest = i->strength;

           foreach(Card *i,the_logic->row_1_A)
               if (i->strength == lowest)
                   target.push_back(i);
       }
    }
    if (!target.isEmpty())
    {
        if (target.size()>5)
            for (int i = 0 ;i <5;i++)
            {
               if(target[i]->shield)
                   target[i]->shield = false;
               else
                   target[i]->strength -= hurt;
            }
        else
            foreach(Card *i,target)
            {
               if(i->shield)
                   i->shield = false;
               else
                   i->strength -= hurt;
            }
    }
}

//Immune_Boost

Immune_Boost::Immune_Boost()
{
    ID = 6;
    total_object_id++;is_lord = false;loyality = true;race = 0;shield = false;
    object_id = total_object_id;can_revive = true;
    strength = 0;
    armor = 0;
    party = 1;
    quality = 1;
    lock =  false;

    the_chosen = NULL;
    hurt = 0;

    is_weather = false;
    is_selecting = false;
    is_put_another = false;

    is_choosing_enemy = 1;            // -1: no choose,0:enemy; 1:friend;2:all
    select_num = 1;
    is_choosing_row = -1;               // -1:no choose,0:enemy;1 friend;2 all
    is_attendent = false;
    pix = new QPixmap(":/images/CardImage/Neutral/Immune_Boost.png");
    show_front = true;
    back = new QPixmap(":/images/Widgets/Card_Back.png");
    description = QObject::tr("使3个相邻单位获得3点护甲和3点增益。");
    card_name = QObject::tr("免疫增强");
}

QRectF Immune_Boost::boundingRect() const
{
    qreal penWidth = 1;
    return QRectF (0 - penWidth,0-penWidth,PixmapWidth + penWidth,PixmapHeight+ penWidth);
}

void Immune_Boost::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{

    if (show_front)
        painter-> drawPixmap(0,0,PixmapWidth,PixmapHeight,*pix);
    else
        painter-> drawPixmap(0,0,PixmapWidth,PixmapHeight,*back);
}

int Immune_Boost::eaten_strength()
{return 0;}

void Immune_Boost::before_turncard_effect()
{}


void Immune_Boost:: card_library_effect ()
{}

void Immune_Boost::set_alternatives()
{}

void Immune_Boost:: card_hand_effect ()
{}

void Immune_Boost::card_turn_end_effect ()
{}

void Immune_Boost::card_death_effect ()
{}

void Immune_Boost::card_round_end_effect ()
{}

void Immune_Boost::card_in_tomb_effect ()
{}

void Immune_Boost::card_lord_effect ()
{}

void Immune_Boost::card_turn_begin_effect ()
{}

void Immune_Boost::card_effect()
{
    if(the_logic->order)
    {
        for (int i =0 ;i< the_logic->row_1_A.size();i++)
        {
            if (the_logic->row_1_A[i] == target[0])
            {
                for(int j = i+1;j< the_logic->row_1_A.size();j++)
                   if (the_logic->row_1_A[j]->is_attendent)
                   {
                       target.push_back(the_logic->row_1_A[j]);
                       break;
                   }
                for (int j = i-1;j>=0 ;j--)
                    if (the_logic->row_1_A[j]->is_attendent)
                    {
                        target.push_back(the_logic->row_1_A[j]);
                        break;
                    }
                break;
            }
        }
        for (int i = 0 ;i< the_logic->row_2_A.size();i++)
        {
            if (the_logic->row_2_A[i] == target[0])
            {
                for(int j = i+1;j< the_logic->row_2_A.size();j++)
                   if (the_logic->row_2_A[j]->is_attendent)
                   {
                       target.push_back(the_logic->row_2_A[j]);
                       break;
                   }
                for (int j = i-1;j>=0 ;j--)
                    if (the_logic->row_2_A[j]->is_attendent)
                    {
                        target.push_back(the_logic->row_2_A[j]);
                        break;
                    }
                break;
            }
        }
        for (int i = 0 ;i< the_logic->row_3_A.size();i++)
        {
            if (the_logic->row_3_A[i] == target[0])
            {
                for(int j = i+1;j< the_logic->row_3_A.size();j++)
                   if (the_logic->row_3_A[j]->is_attendent)
                   {
                       target.push_back(the_logic->row_3_A[j]);
                       break;
                   }
                for (int j = i-1;j>=0 ;j--)
                    if (the_logic->row_3_A[j]->is_attendent)
                    {
                        target.push_back(the_logic->row_3_A[j]);
                        break;
                    }
                break;
            }
        }
    }
    else
    {
        for (int i =0 ;i< the_logic->row_1_B.size();i++)
        {
            if (the_logic->row_1_B[i] == target[0])
            {
                for(int j = i+1;j< the_logic->row_1_B.size();j++)
                   if (the_logic->row_1_B[j]->is_attendent)
                   {
                       target.push_back(the_logic->row_1_B[j]);
                       break;
                   }
                for (int j = i-1;j>=0 ;j--)
                    if (the_logic->row_1_B[j]->is_attendent)
                    {
                        target.push_back(the_logic->row_1_B[j]);
                        break;
                    }
                break;
            }
        }
        for (int i = 0 ;i< the_logic->row_2_B.size();i++)
        {
            if (the_logic->row_2_B[i] == target[0])
            {
                for(int j = i+1;j< the_logic->row_2_B.size();j++)
                   if (the_logic->row_2_B[j]->is_attendent)
                   {
                       target.push_back(the_logic->row_2_B[j]);
                       break;
                   }
                for (int j = i-1;j>=0 ;j--)
                    if (the_logic->row_2_B[j]->is_attendent)
                    {
                        target.push_back(the_logic->row_2_B[j]);
                        break;
                    }
                break;
            }
        }
        for (int i = 0 ;i< the_logic->row_3_B.size();i++)
        {
            if (the_logic->row_3_B[i] == target[0])
            {
                for(int j = i+1;j< the_logic->row_3_B.size();j++)
                   if (the_logic->row_3_B[j]->is_attendent)
                   {
                       target.push_back(the_logic->row_3_B[j]);
                       break;
                   }
                for (int j = i-1;j>=0 ;j--)
                    if (the_logic->row_3_B[j]->is_attendent)
                    {
                        target.push_back(the_logic->row_3_B[j]);
                        break;
                    }
                break;
            }
        }
    }

    foreach(Card * i,target)
    {
        i->armor+=3;
        i->strength+=3;
    }

}

//Commanders_Horn

Commanders_Horn::Commanders_Horn()
{
    ID = 7;
    total_object_id++;is_lord = false;loyality = true;race = 0;shield = false;
    object_id = total_object_id;can_revive = true;
    strength = 0;
    armor = 0;
    party = 1;
    quality = 1;
    lock =  false;

    the_chosen = NULL;
    hurt = 0;
    is_weather = false;
    is_selecting = false;
    is_put_another = false;

    is_choosing_enemy = 1;            // -1: no choose,0:enemy; 1:friend;2:all
    select_num = 1;
    is_choosing_row = -1;               // -1:no choose,0:enemy;1 friend;2 all
    is_attendent = false;
    pix = new QPixmap(":/images/CardImage/Neutral/Commanders_Horn.png");
    show_front = true;
    back = new QPixmap(":/images/Widgets/Card_Back.png");
    description = QObject::tr("使5个相邻单位获得4点增益。");
    card_name = QObject::tr("指挥号角");
}

QRectF Commanders_Horn::boundingRect() const
{
    qreal penWidth = 1;
    return QRectF (0 - penWidth,0-penWidth,PixmapWidth + penWidth,PixmapHeight + penWidth);
}

void Commanders_Horn::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{

    if (show_front)
        painter-> drawPixmap(0,0,PixmapWidth,PixmapHeight,*pix);
    else
        painter-> drawPixmap(0,0,PixmapWidth,PixmapHeight,*back);
}
void Commanders_Horn::card_effect()
{
    int left = 0;
    int right = 0;
    if(the_logic->order)
    {
        for (int i =0 ;i< the_logic->row_1_A.size();i++)
        {
            if (the_logic->row_1_A[i] == target[0])
            {
                for(int j = i+1;j< the_logic->row_1_A.size();j++)
                   {
                        if (the_logic->row_1_A[j]->is_attendent)
                        {
                           target.push_back(the_logic->row_1_A[j]);
                           right++;
                        }
                        if (right == 2)
                            break;
                    }
                for (int j = i-1;j>=0 ;j--)
                    {
                         if (the_logic->row_1_A[j]->is_attendent)
                         {
                            target.push_back(the_logic->row_1_A[j]);
                            left++;
                         }
                         if (left == 2)
                             break;
                    }
                break;
            }
        }
        for (int i = 0 ;i< the_logic->row_2_A.size();i++)
        {
            if (the_logic->row_2_A[i] == target[0])
            {
                for(int j = i+1;j< the_logic->row_2_A.size();j++)
                   {
                        if (the_logic->row_2_A[j]->is_attendent)
                         {
                            target.push_back(the_logic->row_2_A[j]);
                            right++;
                         }
                        if(right == 2)
                            break;
                   }
                for (int j = i-1;j>=0 ;j--)
                   {
                         if (the_logic->row_2_A[j]->is_attendent)
                        {
                            target.push_back(the_logic->row_2_A[j]);
                            left++;
                         }
                         if (left == 2)
                             break;
                    }
                break;
            }
        }
        for (int i = 0 ;i< the_logic->row_3_A.size();i++)
        {
            if (the_logic->row_3_A[i] == target[0])
            {
                for(int j = i+1;j< the_logic->row_3_A.size();j++)
                   {
                        if (the_logic->row_3_A[j]->is_attendent)
                        {
                            target.push_back(the_logic->row_3_A[j]);
                            right++;
                        }
                        if (right == 2)
                            break;
                    }
                for (int j = i-1;j>=0 ;j--)
                {
                    if (the_logic->row_3_A[j]->is_attendent)
                    {
                        target.push_back(the_logic->row_3_A[j]);
                        left++;
                    }
                    if (left == 2)
                        break;
                }
                break;
            }
        }
    }
    else
    {
        for (int i =0 ;i< the_logic->row_1_B.size();i++)
        {
            if (the_logic->row_1_B[i] == target[0])
            {
                for(int j = i+1;j< the_logic->row_1_B.size();j++)
                   {
                        if (the_logic->row_1_B[j]->is_attendent)
                        {
                             target.push_back(the_logic->row_1_B[j]);
                             right++;
                        }
                        if (right == 2)
                            break;
                   }
                for (int j = i-1;j>=0 ;j--)
                {
                        if (the_logic->row_1_B[j]->is_attendent)
                        {
                            target.push_back(the_logic->row_1_B[j]);
                            left++;
                        }
                        if (left == 2)
                            break;
                }
                break;
            }
        }
        for (int i = 0 ;i< the_logic->row_2_B.size();i++)
        {
            if (the_logic->row_2_B[i] == target[0])
            {
                for(int j = i+1;j< the_logic->row_2_B.size();j++)
                   {
                        if (the_logic->row_2_B[j]->is_attendent)
                        {
                             target.push_back(the_logic->row_2_B[j]);
                             right++;
                        }
                        if(right == 2)
                            break;
                    }
                for (int j = i-1;j>=0 ;j--)
                {
                        if (the_logic->row_2_B[j]->is_attendent)
                        {
                            target.push_back(the_logic->row_2_B[j]);
                            left++;
                        }
                        if (left == 2)
                            break;
                }
                break;
            }
        }
        for (int i = 0 ;i< the_logic->row_3_B.size();i++)
        {
            if (the_logic->row_3_B[i] == target[0])
            {
                for(int j = i+1;j< the_logic->row_3_B.size();j++)
                   {
                        if (the_logic->row_3_B[j]->is_attendent)
                       {
                            target.push_back(the_logic->row_3_B[j]);
                            right++;
                        }
                        if (right == 2)
                            break;
                    }
                for (int j = i-1;j>=0 ;j--)
                    {
                         if (the_logic->row_3_B[j]->is_attendent)
                        {
                            target.push_back(the_logic->row_3_B[j]);
                            left++;
                        }
                         if (left == 2)
                             break;
                    }
                break;
            }
        }
    }

    foreach(Card * i,target)
        i->strength +=4;

}

int Commanders_Horn::eaten_strength()
{return 0;}

void Commanders_Horn::before_turncard_effect()
{}



void Commanders_Horn::set_alternatives()
{}

void Commanders_Horn:: card_library_effect ()
{}

void Commanders_Horn:: card_hand_effect ()
{}

void Commanders_Horn::card_turn_end_effect ()
{}

void Commanders_Horn::card_death_effect ()
{}

void Commanders_Horn::card_round_end_effect ()
{}

void Commanders_Horn::card_in_tomb_effect ()
{}

void Commanders_Horn::card_lord_effect ()
{}

void Commanders_Horn::card_turn_begin_effect ()
{}

//Bekkers_Twisted_Mirror

Bekkers_Twisted_Mirror::Bekkers_Twisted_Mirror()
{
    ID = 8;
    total_object_id++;is_lord = false;loyality = true;race = 0;shield = false;
    object_id = total_object_id;can_revive = true;
    strength = 0;
    armor = 0;
    party = 1;
    quality = 3;
    lock =  false;

    the_chosen = NULL;
    hurt = 0;
    is_weather = false;
    is_selecting = false;
    is_put_another = false;

    is_choosing_enemy = -1;            // -1: no choose,0:enemy; 1:friend;2:all
    is_choosing_row = -1;               // -1:no choose,0:enemy;1 friend;2 all
    is_attendent = false;
    pix = new QPixmap(":/images/CardImage/Neutral/Bekkers_Twisted_Mirror.png");
    show_front = true;
    back = new QPixmap(":/images/Widgets/Card_Back.png");
    description = QObject::tr("将最强和最弱单位的战力互换。");
    card_name  = QObject::tr("贝克尔的扭曲之镜");
}

QRectF Bekkers_Twisted_Mirror::boundingRect() const
{
    qreal penWidth = 1;
    return QRectF (0 - penWidth,0-penWidth,PixmapWidth + penWidth,PixmapHeight + penWidth);
}

void Bekkers_Twisted_Mirror::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{

    if (show_front)
        painter-> drawPixmap(0,0,PixmapWidth,PixmapHeight,*pix);
    else
        painter-> drawPixmap(0,0,PixmapWidth,PixmapHeight,*back);
}
void Bekkers_Twisted_Mirror::card_effect()
{
    int highest = 0, lowest = 999;
    Card* h = NULL, *l =NULL;

    foreach(Card *i,the_logic->row_1_A)
    {
        if(i->strength < lowest)
        {
            l = i;
            lowest = i->strength;
        }
        if (i->strength >highest)
        {
            h = i;
            highest = i->strength;
        }
    }
    foreach(Card *i,the_logic->row_2_A)
    {
        if(i->strength < lowest)
        {
            l = i;
            lowest = i->strength;
        }
        if (i->strength >highest)
        {
            h = i;
            highest = i->strength;
        }
    }
    foreach(Card *i,the_logic->row_3_A)
    {
        if(i->strength < lowest)
        {
            l = i;
            lowest = i->strength;
        }
        if (i->strength >highest)
        {
            h = i;
            highest = i->strength;
        }
    }
    foreach(Card *i,the_logic->row_1_B)
    {
        if(i->strength < lowest)
        {
            l = i;
            lowest = i->strength;
        }
        if (i->strength >highest)
        {
            h = i;
            highest = i->strength;
        }
    }
    foreach(Card *i,the_logic->row_2_B)
    {
        if(i->strength < lowest)
        {
            l = i;
            lowest = i->strength;
        }
        if (i->strength >highest)
        {
            h = i;
            highest = i->strength;
        }
    }
    foreach(Card *i,the_logic->row_3_B)
    {
        if(i->strength < lowest)
        {
            l = i;
            lowest = i->strength;
        }
        if (i->strength >highest)
        {
            h = i;
            highest = i->strength;
        }
    }

    if( h != NULL && l!= NULL)
    {
    h->strength = lowest;
    l->strength = highest;
    }

}

int Bekkers_Twisted_Mirror::eaten_strength()
{return 0;}

void Bekkers_Twisted_Mirror::before_turncard_effect()
{}


void Bekkers_Twisted_Mirror::set_alternatives()
{}

void Bekkers_Twisted_Mirror:: card_library_effect ()
{}

void Bekkers_Twisted_Mirror:: card_hand_effect ()
{}

void Bekkers_Twisted_Mirror::card_turn_end_effect ()
{}

void Bekkers_Twisted_Mirror::card_death_effect ()
{}

void Bekkers_Twisted_Mirror::card_round_end_effect ()
{}

void Bekkers_Twisted_Mirror::card_in_tomb_effect ()
{}

void Bekkers_Twisted_Mirror::card_lord_effect ()
{}

void Bekkers_Twisted_Mirror::card_turn_begin_effect ()
{}

//Geralt_Igni

Geralt_Igni::Geralt_Igni()
{
    ID = 9;
    total_object_id++;is_lord = false;loyality = true;race = 0;shield = false;
    object_id = total_object_id;can_revive = true;
    strength = 4;
    armor = 0;
    party = 1;
    quality = 3;
    lock =  false;

    the_chosen = NULL;
    hurt = 0;
    is_weather = false;
    is_selecting = false;
    is_put_another = false;

    is_choosing_enemy = -1;            // -1: no choose,0:enemy; 1:friend;2:all
    is_choosing_row = -1;               // -1:no choose,0:enemy;1 friend;2 all
    is_attendent = true;
    stand_position=4;
    pix = new QPixmap(":/images/CardImage/Neutral/Geralt_Igni.png");
    show_front = true;
    back = new QPixmap(":/images/Widgets/Card_Back.png");
    description = QObject::tr("部署：若对方同排总战力不低于25，则摧毁其上所有最强的单位。");
    card_name = QObject::tr("杰洛特：伊格尼法印");
}

QRectF Geralt_Igni::boundingRect() const
{
    qreal penWidth = 1;
    return QRectF (0 - penWidth,0-penWidth,PixmapWidth + penWidth,PixmapHeight + penWidth);
}

void Geralt_Igni::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{

    if (show_front)
        painter-> drawPixmap(0,0,PixmapWidth,PixmapHeight,*pix);
    else
        painter-> drawPixmap(0,0,PixmapWidth,PixmapHeight,*back);
}

void Geralt_Igni::set_alternatives()
{}

void Geralt_Igni::card_effect()
{
    int total = 0,highest  = 0;
    target.clear();
    if (the_logic->order)
    {
        if (stand_row == 1)
        {
           foreach(Card *i,the_logic->row_1_B)
                if (i->is_attendent)
                {
                    total += i->strength;
                    if (highest<i->strength)
                        highest = i->strength;
                }
            if (total >= 25)
            {
                foreach(Card *i,the_logic->row_1_B)
                    if (i->strength == highest)
                        target.push_back(i);
            }
        }
        else if (stand_row == 2)
        {
           foreach(Card *i,the_logic->row_2_B)
                if (i->is_attendent)
                {
                    total += i->strength;
                    if (highest<i->strength)
                        highest = i->strength;
                }
            if (total >= 25)
            {
                foreach(Card *i,the_logic->row_2_B)
                    if (i->strength == highest)
                        target.push_back(i);
            }
        }
        else if (stand_row == 3)
        {
           foreach(Card *i,the_logic->row_3_B)
                if (i->is_attendent)
                {
                    total += i->strength;
                    if (highest<i->strength)
                        highest = i->strength;
                }
            if (total >= 25)
            {
                foreach(Card *i,the_logic->row_3_B)
                    if (i->strength == highest)
                        target.push_back(i);
            }
        }
    }
    else
    {
        if (stand_row == 1)
        {
           foreach(Card *i,the_logic->row_1_A)
                if (i->is_attendent)
                {
                    total += i->strength;
                    if (highest<i->strength)
                        highest = i->strength;
                }
            if (total >= 25)
            {
                foreach(Card *i,the_logic->row_1_A)
                    if (i->strength == highest)
                        target.push_back(i);
            }
        }
        else if (stand_row == 2)
        {
           foreach(Card *i,the_logic->row_2_A)
                if (i->is_attendent)
                {
                    total += i->strength;
                    if (highest<i->strength)
                        highest = i->strength;
                }
            if (total >= 25)
            {
                foreach(Card *i,the_logic->row_2_A)
                    if (i->strength == highest)
                        target.push_back(i);
            }
        }
        else if (stand_row == 3)
        {
           foreach(Card *i,the_logic->row_3_A)
                if (i->is_attendent)
                {
                    total += i->strength;
                    if (highest<i->strength)
                        highest = i->strength;
                }
            if (total >= 25)
            {
                foreach(Card *i,the_logic->row_3_A)
                    if (i->strength == highest)
                        target.push_back(i);
            }
        }
    }
    foreach(Card *i,target)
        i->strength = 0;
}

int Geralt_Igni::eaten_strength()
{
    return strength;
}

void Geralt_Igni::before_turncard_effect()
{}


void Geralt_Igni:: card_library_effect ()
{}

void Geralt_Igni:: card_hand_effect ()
{}

void Geralt_Igni::card_turn_end_effect ()
{}

void Geralt_Igni::card_death_effect ()
{}

void Geralt_Igni::card_round_end_effect ()
{}

void Geralt_Igni::card_in_tomb_effect ()
{}

void Geralt_Igni::card_lord_effect ()
{}

void Geralt_Igni::card_turn_begin_effect ()
{}

//Dagon

Dagon::Dagon()
{
    ID = 10;
    total_object_id++;is_lord = true;loyality = true;race = 0;shield = false;
    object_id = total_object_id;can_revive = true;
    strength = 6;
    armor = 0;
    party = 2;
    quality = 3;
    lock =  false;

    the_chosen = NULL;
    hurt = 0;
    is_weather = false;
    is_selecting = true;
    is_put_another = true;

    is_choosing_enemy = -1;            // -1: no choose,0:enemy; 1:friend;2:all
    is_choosing_row = -1;               // -1:no choose,0:enemy;1 friend;2 all
    is_attendent = true;
    stand_position = 4;
    pix = new QPixmap(":/images/CardImage/Monsters/Dagon.png");
    show_front = true;
    back = new QPixmap(":/images/Widgets/Card_Back.png");
    description = QObject::tr("部署：生成\"刺骨冰霜\"、\"蔽日浓雾\"或\"倾盆大雨\"。");
    card_name = QObject::tr ("达冈");
}

QRectF Dagon::boundingRect() const
{
    qreal penWidth = 1;
    return QRectF (0 - penWidth,0-penWidth,PixmapWidth + penWidth,PixmapHeight + penWidth);
}

void Dagon::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{

    if (show_front)
        painter-> drawPixmap(0,0,PixmapWidth,PixmapHeight,*pix);
    else
        painter-> drawPixmap(0,0,PixmapWidth,PixmapHeight,*back);
}
int Dagon::eaten_strength()
{
    return strength;
}

void Dagon::before_turncard_effect()
{}


void Dagon::card_effect()
{}

void Dagon::set_alternatives()
{
    Biting_Frost *bt  = new Biting_Frost;
    Impenetrable_Fog *IF = new Impenetrable_Fog;
    Torrential_Rain *TR = new Torrential_Rain;
    bt->the_logic = the_logic;
    IF->the_logic = the_logic;
    TR->the_logic = the_logic;
    alternative.push_back(bt);
    alternative.push_back(IF);
    alternative.push_back(TR);
}

void Dagon:: card_library_effect ()
{}

void Dagon:: card_hand_effect ()
{}

void Dagon::card_turn_end_effect ()
{}

void Dagon::card_death_effect ()
{}

void Dagon::card_round_end_effect ()
{}

void Dagon::card_in_tomb_effect ()
{}

void Dagon::card_lord_effect ()
{}

void Dagon::card_turn_begin_effect ()
{}

//Foglet

bool Foglet::put_out = true;
bool Foglet::fog_exist = false;

Foglet::Foglet()
{

    ID = 11;
    total_object_id++;is_lord = false;loyality = true;race = 0;shield = false;
    object_id = total_object_id;can_revive = true;
    strength = 2;
    armor = 0;
    party = 1;
    quality = 1;
    lock =  false;

    the_chosen = NULL;
    hurt = 0;
    is_weather = false;
    is_selecting = false;
    is_put_another = false;


    is_choosing_enemy = -1;            // -1: no choose,0:enemy; 1:friend;2:all
    is_choosing_row = -1;               // -1:no choose,0:enemy;1 friend;2 all
    is_attendent = true;
    stand_position = 4;
    pix = new QPixmap(":/images/CardImage/Monsters/Foglet.png");
    show_front = true;
    back = new QPixmap(":/images/Widgets/Card_Back.png");
    description = QObject::tr("每当己方\"蔽日浓雾\"在敌排生效，便从牌组打出 1 个\"小雾妖\"至己方同排。若牌组中没有\"小雾妖\"，则复活1个\"小雾妖\"至己方同排。若场上不再存在\"蔽日浓雾\"效果，则摧毁所有\"小雾妖\"。");
    card_name = QObject::tr("小雾妖");
}

QRectF Foglet::boundingRect() const
{
    qreal penWidth = 1;
    return QRectF (0 - penWidth,0-penWidth,PixmapWidth + penWidth,PixmapHeight + penWidth);
}

void Foglet::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{

    if (show_front)
        painter-> drawPixmap(0,0,PixmapWidth,PixmapHeight,*pix);
    else
        painter-> drawPixmap(0,0,PixmapWidth,PixmapHeight,*back);
}

void Foglet::set_alternatives()
{}

int Foglet::eaten_strength()
{
    return strength;
}

void Foglet::before_turncard_effect()
{}



void Foglet::card_effect()
{}

void Foglet:: card_library_effect ()
{

    if (the_logic->order)
    {
        if (put_out)
           {
            foreach(Card *i,the_logic->row_1_B)
                 if (i->ID == 3 && i->is_active)
                {
                    put_out = false;
                    the_logic->library_A.removeOne(this);
                    the_logic->row_1_A.push_back(this);
                }
            foreach(Card *i,the_logic->row_2_B)
                 if (i->ID == 3 && i->is_active)
                {
                    put_out = false;
                    the_logic->library_A.removeOne(this);
                    the_logic->row_2_A.push_back(this);
                }
            foreach(Card *i,the_logic->row_3_B)
                 if (i->ID == 3 && i->is_active)
                {
                    put_out = false;
                    the_logic->library_A.removeOne(this);
                    the_logic->row_3_A.push_back(this);
                }
            }
    }
    else
    {
        if (put_out)
           {
            foreach(Card *i,the_logic->row_1_A)
                 if (i->ID == 3 && i->is_active)
                {
                    put_out = false;
                    the_logic->library_B.removeOne(this);
                    the_logic->row_1_B.push_back(this);
                }
            foreach(Card *i,the_logic->row_2_A)
                 if (i->ID == 3 && i->is_active)
                {
                    put_out = false;
                    the_logic->library_B.removeOne(this);
                    the_logic->row_2_B.push_back(this);
                }
            foreach(Card *i,the_logic->row_3_A)
                 if (i->ID == 3 && i->is_active)
                {
                    put_out = false;
                    the_logic->library_B.removeOne(this);
                    the_logic->row_3_B.push_back(this);
                }
            }
    }
}

void Foglet:: card_hand_effect ()
{}

void Foglet::card_turn_end_effect ()
{
    if (the_logic->order)
    {
        foreach(Card *i,the_logic->row_1_B)
             if (i->ID == 3)
                fog_exist = true;
        foreach(Card *i,the_logic->row_2_B)
             if (i->ID == 3)
                fog_exist = true;
        foreach(Card *i,the_logic->row_3_B)
             if (i->ID == 3)
                fog_exist = true;

        if (fog_exist == false)
        {

            if (the_logic->row_1_A.contains(this))
                    the_logic->row_1_A.removeOne(this);
            if (the_logic->row_2_A.contains(this))
                    the_logic->row_2_A.removeOne(this);
            if (the_logic->row_3_A.contains(this))
                    the_logic->row_3_A.removeOne(this);
        }
    }
    else
    {
        foreach(Card *i,the_logic->row_1_A)
             if (i->ID == 3)
                fog_exist = true;
        foreach(Card *i,the_logic->row_2_A)
             if (i->ID == 3)
                fog_exist = true;
        foreach(Card *i,the_logic->row_3_A)
             if (i->ID == 3)
                fog_exist = true;

        if (fog_exist == false)
        {
          emit the_logic->RemoveItem(this);
          if (the_logic->row_1_B.contains(this))
                    the_logic->row_1_B.removeOne(this);
          if (the_logic->row_2_B.contains(this))
                    the_logic->row_2_B.removeOne(this);
          if (the_logic->row_3_B.contains(this))
                    the_logic->row_3_B.removeOne(this);
        }
    }

}

void Foglet::card_death_effect ()
{}

void Foglet::card_round_end_effect ()
{}

void Foglet::card_in_tomb_effect ()
{
    if (the_logic->order)
    {
        if (put_out)
           {
            foreach(Card *i,the_logic->row_1_B)
                 if (i->ID == 3 && i->is_active)
                {
                    put_out = false;
                    the_logic->library_A.removeOne(this);
                    the_logic->row_1_A.push_back(this);
                }
            foreach(Card *i,the_logic->row_2_B)
                 if (i->ID == 3 && i->is_active)
                {
                    put_out = false;
                    the_logic->library_A.removeOne(this);
                    the_logic->row_2_A.push_back(this);
                }
            foreach(Card *i,the_logic->row_3_B)
                 if (i->ID == 3 && i->is_active)
                {
                    put_out = false;
                    the_logic->library_A.removeOne(this);
                    the_logic->row_3_A.push_back(this);
                }
            }
    }
    else
    {
        if (put_out)
           {
            foreach(Card *i,the_logic->row_1_A)
                 if (i->ID == 3 && i->is_active)
                {
                    put_out = false;
                    the_logic->library_B.removeOne(this);
                    the_logic->row_1_B.push_back(this);
                }
            foreach(Card *i,the_logic->row_2_A)
                 if (i->ID == 3 && i->is_active)
                {
                    put_out = false;
                    the_logic->library_B.removeOne(this);
                    the_logic->row_2_B.push_back(this);
                }
            foreach(Card *i,the_logic->row_3_A)
                 if (i->ID == 3 && i->is_active)
                {
                    put_out = false;
                    the_logic->library_B.removeOne(this);
                    the_logic->row_3_B.push_back(this);
                }
            }
    }
}

void Foglet::card_lord_effect ()
{}

void Foglet::card_turn_begin_effect ()
{

       put_out = true;
       fog_exist = false;
}

//Geels

Geels::Geels()
{

    ID = 12;
    total_object_id++;is_lord = true;loyality = true;race = 0;shield = false;
    object_id = total_object_id;can_revive = true;
    strength = 2;
    armor = 0;
    party = 1;
    quality = 3;
    lock =  false;

    the_chosen = NULL;
    hurt = 0;
    is_weather = false;
    is_selecting = true;
    is_put_another = true;


    is_choosing_enemy = -1;            // -1: no choose,0:enemy; 1:friend;2:all
    is_choosing_row = -1;               // -1:no choose,0:enemy;1 friend;2 all
    is_attendent = true;
    stand_position = 4;
    pix = new QPixmap(":/images/CardImage/Monsters/Geels.png");
    show_front = true;
    back = new QPixmap(":/images/Widgets/Card_Back.png");
    description = QObject::tr("部署：从牌组顶端各抽1张金色牌和银色牌。打出1张，将另1张置于牌组顶端。");
    card_name  = QObject::tr("盖尔");
}



QRectF Geels::boundingRect() const
{
    qreal penWidth = 1;
    return QRectF (0 - penWidth,0-penWidth,PixmapWidth + penWidth,PixmapHeight + penWidth);
}

void Geels::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{

    if (show_front)
        painter-> drawPixmap(0,0,PixmapWidth,PixmapHeight,*pix);
    else
        painter-> drawPixmap(0,0,PixmapWidth,PixmapHeight,*back);
}


void Geels::before_turncard_effect()
{}
int Geels::eaten_strength()
{
    return strength;
}

void Geels::card_effect()
{
    alternative.removeOne(the_chosen);

    if (the_logic->order)
        the_logic->library_A.push_front(alternative[0]);
    else
        the_logic->library_B.push_front(alternative[0]);
}
void Geels::set_alternatives()
{
    Card * gold = NULL ,*silver = NULL;

    if (the_logic->order)
    {
        for (int i =0 ;i<the_logic->library_A.size();i++)
        {
            if (the_logic->library_A[i]->quality == 2 && silver == NULL)
               {
                 silver = the_logic->library_A[i];
                 the_logic->library_A.removeOne(silver);
               }

            if (the_logic->library_A[i]->quality == 3 && gold == NULL)
               {
                gold = the_logic->library_A[i];
                the_logic->library_A.removeOne(gold);
                }
            if (gold != NULL &&silver !=NULL)
                 break;
        }
    }
    else
    {
        for (int i =0 ;i<the_logic->library_B.size();i++)
        {
            if (the_logic->library_B[i]->quality == 2 && silver == NULL)
             {
                silver = the_logic->library_B[i];
                the_logic->library_B.removeOne(silver);
             }
            if (the_logic->library_B[i]->quality == 3 && gold == NULL)
            {
                gold = the_logic->library_B[i];
                the_logic->library_B.removeOne(gold);
             }
            if (gold != NULL &&silver !=NULL)
                 break;
        }
    }
    alternative.push_back(gold);
    alternative.push_back(silver);
}

void Geels:: card_library_effect ()
{}

void Geels:: card_hand_effect ()
{}

void Geels::card_turn_end_effect ()
{}

void Geels::card_death_effect ()
{}

void Geels::card_round_end_effect ()
{}

void Geels::card_in_tomb_effect ()
{}

void Geels::card_lord_effect ()
{}

void Geels::card_turn_begin_effect ()
{}

//Celaeno_Harpy

Celaeno_Harpy::Celaeno_Harpy()
{

    ID = 13;
    total_object_id++;is_lord = false;loyality = true;race = 2;shield = false;
    object_id = total_object_id;can_revive = true;
    strength = 3;
    armor = 0;
    party = 1;
    quality = 1;
    lock =  false;

    the_chosen = NULL;
    hurt = 0;
    is_weather = false;
    is_selecting = false;
    is_put_another = false;


    is_choosing_enemy = -1;            // -1: no choose,0:enemy; 1:friend;2:all
    is_choosing_row = -1;               // -1:no choose,0:enemy;1 friend;2 all
    is_attendent = true;
    stand_position=4;
    pix = new QPixmap(":/images/CardImage/Monsters/Celaeno_Harpy.png");
    show_front = true;
    back = new QPixmap(":/images/Widgets/Card_Back.png");
    description = QObject::tr("部署：在自身左侧生成2个\"鹰身女妖蛋\"。");
    card_name = QObject::tr("赛尔伊诺鹰身女妖");
}

QRectF Celaeno_Harpy::boundingRect() const
{
    qreal penWidth = 1;
    return QRectF (0 - penWidth,0-penWidth,PixmapWidth + penWidth,PixmapHeight + penWidth);
}


void Celaeno_Harpy::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{

    if (show_front)
        painter-> drawPixmap(0,0,PixmapWidth,PixmapHeight,*pix);
    else
        painter-> drawPixmap(0,0,PixmapWidth,PixmapHeight,*back);
}
void Celaeno_Harpy::set_alternatives()
{}

int Celaeno_Harpy::eaten_strength()
{
    return strength;
}

void Celaeno_Harpy::before_turncard_effect()
{}


void Celaeno_Harpy::card_effect()
{
    Harpy_Egg *egg1 = new Harpy_Egg;
    egg1->the_logic = the_logic;
    Harpy_Egg *egg2 = new Harpy_Egg;
    egg2->the_logic = the_logic;

    emit the_logic->AddItem(egg1);
    emit the_logic->AddItem(egg2);

    if (the_logic->order)
    {
        if (stand_row == 1)
        {
            int i = the_logic->row_1_A.indexOf(the_logic->turn_card);
            the_logic->row_1_A.insert(i,egg1);
            the_logic->row_1_A.insert(i,egg2);
        }
        else if (stand_row == 2)
        {
            int i = the_logic->row_2_A.indexOf(the_logic->turn_card);
            the_logic->row_2_A.insert(i,egg1);
            the_logic->row_2_A.insert(i,egg2);
        }
        else if (stand_row == 3)
        {
            int i = the_logic->row_3_A.indexOf(the_logic->turn_card);
            the_logic->row_3_A.insert(i,egg1);
            the_logic->row_3_A.insert(i,egg2);
        }
    }
    else
    {
        if (stand_row == 1)
        {
            int i = the_logic->row_1_B.indexOf(the_logic->turn_card);
            the_logic->row_1_B.insert(i,egg1);
            the_logic->row_1_B.insert(i,egg2);
        }
        else if (stand_row == 2)
        {
            int i = the_logic->row_2_B.indexOf(the_logic->turn_card);
            the_logic->row_2_B.insert(i,egg1);
            the_logic->row_2_B.insert(i,egg2);
        }
        else if (stand_row == 3)
        {
            int i = the_logic->row_3_B.indexOf(the_logic->turn_card);
            the_logic->row_3_B.insert(i,egg1);
            the_logic->row_3_B.insert(i,egg2);
        }
    }
}

void Celaeno_Harpy:: card_library_effect ()
{}

void Celaeno_Harpy:: card_hand_effect ()
{}

void Celaeno_Harpy::card_turn_end_effect ()
{}

void Celaeno_Harpy::card_death_effect ()
{}

void Celaeno_Harpy::card_round_end_effect ()
{}

void Celaeno_Harpy::card_in_tomb_effect ()
{}

void Celaeno_Harpy::card_lord_effect ()
{}

void Celaeno_Harpy::card_turn_begin_effect ()
{}

//Harpy

Harpy::Harpy()
{
    ID = 14;
    total_object_id++;is_lord = false;loyality = true;race = 2;shield = false;
    object_id = total_object_id;can_revive = true;
    strength = 3;
    armor = 0;
    party = 1;
    quality = 1;
    lock =  false;

    the_chosen = NULL;
    hurt = 0;
    is_weather = false;
    is_selecting = false;
    is_put_another = false;

    is_choosing_enemy = -1;            // -1: no choose,0:enemy; 1:friend;2:all
    is_choosing_row = -1;               // -1:no choose,0:enemy;1 friend;2 all
    is_attendent = true;
    stand_position = 4;
    pix = new QPixmap(":/images/CardImage/Monsters/Harpy.png");
    show_front = true;
    back = new QPixmap(":/images/Widgets/Card_Back.png");
    description =QObject::tr("部署：触发相邻单位的遗愿能力。");
    card_name = QObject::tr("鹰身女妖");
}

QRectF Harpy::boundingRect() const
{
    qreal penWidth = 1;
    return QRectF (0 - penWidth,0-penWidth,PixmapWidth + penWidth,PixmapHeight + penWidth);
}

void Harpy::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{

    if (show_front)
        painter-> drawPixmap(0,0,PixmapWidth,PixmapHeight,*pix);
    else
        painter-> drawPixmap(0,0,PixmapWidth,PixmapHeight,*back);
}
void Harpy::set_alternatives()
{}

int Harpy::eaten_strength()
{
    return strength;
}

void Harpy::before_turncard_effect()
{}


void Harpy::card_effect()
{
    target.clear();
    if (the_logic->order)
    {
        if (stand_row == 1)
        {
            int i = the_logic->row_1_A.indexOf(the_logic->turn_card);

            for(int j = i+1; j< the_logic->row_1_A.size();j++)
                if(the_logic->row_1_A[j]->is_attendent)
                    target.push_back(the_logic->row_1_A[j]);
            for(int j = i-1; j>= 0;j--)
                if(the_logic->row_1_A[j]->is_attendent)
                    target.push_back(the_logic->row_1_A[j]);
        }
        else if (stand_row == 2)
        {
            int i = the_logic->row_2_A.indexOf(the_logic->turn_card);

            for(int j = i+1; j< the_logic->row_2_A.size();j++)
                if(the_logic->row_2_A[j]->is_attendent)
                    target.push_back(the_logic->row_2_A[j]);
            for(int j = i-1; j>= 0;j--)
                if(the_logic->row_2_A[j]->is_attendent)
                    target.push_back(the_logic->row_2_A[j]);
        }
        else if (stand_row == 3)
        {
            int i = the_logic->row_3_A.indexOf(the_logic->turn_card);

            for(int j = i+1; j< the_logic->row_3_A.size();j++)
                if(the_logic->row_3_A[j]->is_attendent)
                    target.push_back(the_logic->row_3_A[j]);
            for(int j = i-1; j>= 0;j--)
                if(the_logic->row_3_A[j]->is_attendent)
                    target.push_back(the_logic->row_3_A[j]);
        }
    }
    else
    {
        if (stand_row == 1)
        {
            int i = the_logic->row_1_B.indexOf(the_logic->turn_card);

            for(int j = i+1; j< the_logic->row_1_B.size();j++)
                if(the_logic->row_1_B[j]->is_attendent)
                    target.push_back(the_logic->row_1_B[j]);
            for(int j = i-1; j>= 0;j--)
                if(the_logic->row_1_B[j]->is_attendent)
                    target.push_back(the_logic->row_1_B[j]);
        }
        else if (stand_row == 2)
        {
            int i = the_logic->row_2_B.indexOf(the_logic->turn_card);

            for(int j = i+1; j< the_logic->row_2_B.size();j++)
                if(the_logic->row_2_B[j]->is_attendent)
                    target.push_back(the_logic->row_2_B[j]);
            for(int j = i-1; j>= 0;j--)
                if(the_logic->row_2_B[j]->is_attendent)
                    target.push_back(the_logic->row_2_B[j]);
        }
        else if (stand_row == 3)
        {
            int i = the_logic->row_3_B.indexOf(the_logic->turn_card);

            for(int j = i+1; j< the_logic->row_3_B.size();j++)
                if(the_logic->row_3_B[j]->is_attendent)
                    target.push_back(the_logic->row_3_B[j]);
            for(int j = i-1; j>= 0;j--)
                if(the_logic->row_3_B[j]->is_attendent)
                    target.push_back(the_logic->row_3_B[j]);
        }
    }
    foreach(Card *i ,target)
        i->card_death_effect();
}

void Harpy:: card_library_effect ()
{}

void Harpy:: card_hand_effect ()
{}

void Harpy::card_turn_end_effect ()
{}

void Harpy::card_death_effect ()
{}

void Harpy::card_round_end_effect ()
{}

void Harpy::card_in_tomb_effect ()
{}

void Harpy::card_lord_effect ()
{}

void Harpy::card_turn_begin_effect ()
{}

//Woodland_Spirit

Woodland_Spirit::Woodland_Spirit()
{
    ID = 15;
    total_object_id++;is_lord = false;loyality = true;race = 0;shield = false;
    object_id = total_object_id;can_revive = true;
    strength = 5;
    armor = 0;
    party = 1;
    quality = 3;
    lock =  false;

    is_weather = false;
    is_selecting = false;
    is_put_another = false;

    is_choosing_enemy = -1;            // -1: no choose,0:enemy; 1:friend;2:all
    is_choosing_row = -1;               // -1:no choose,0:enemy;1 friend;2 all
    is_attendent = true;
    stand_position= 4;
    pix = new QPixmap(":/images/CardImage/Monsters/Woodland_Spirit.png");
    show_front = true;
    back = new QPixmap(":/images/Widgets/Card_Back.png");
    description = QObject::tr("部署：生成3只\"暴怒的狼\"，并在对方同排降下\"蔽日浓雾\"。");
    card_name = QObject::tr("林妖");
}

QRectF Woodland_Spirit::boundingRect() const
{
    qreal penWidth = 1;
    return QRectF (0 - penWidth,0-penWidth,PixmapWidth + penWidth,PixmapHeight + penWidth);
}

void Woodland_Spirit::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{

    if (show_front)
        painter-> drawPixmap(0,0,PixmapWidth,PixmapHeight,*pix);
    else
        painter-> drawPixmap(0,0,PixmapWidth,PixmapHeight,*back);
}

int Woodland_Spirit::eaten_strength()
{
    return strength;
}

void Woodland_Spirit::before_turncard_effect()
{}


void Woodland_Spirit::set_alternatives()
{}
void Woodland_Spirit::card_effect()
{
    Raging_Wolf *w1 = new Raging_Wolf;
    Raging_Wolf *w2 = new Raging_Wolf;
    Raging_Wolf *w3 = new Raging_Wolf;
    Impenetrable_Fog *fog  = new Impenetrable_Fog;

    w1->the_logic = the_logic;
    w2->the_logic = the_logic;
    w3->the_logic = the_logic;
    fog->the_logic = the_logic;
    emit the_logic->AddItem(w1);
    emit the_logic->AddItem(w2);
    emit the_logic->AddItem(w3);

    if (the_logic->order)
    {
        if (stand_row == 1)
        {
            the_logic->row_1_A.push_back(w1);
            the_logic->row_1_A.push_back(w2);
            the_logic->row_1_A.push_back(w3);
            the_logic->row_1_B.push_back(fog);
        }
        else if (stand_row == 2)
        {
            the_logic->row_2_A.push_back(w1);
            the_logic->row_2_A.push_back(w2);
            the_logic->row_2_A.push_back(w3);
            the_logic->row_2_B.push_back(fog);
        }
        else if (stand_row == 3)
        {
            the_logic->row_3_A.push_back(w1);
            the_logic->row_3_A.push_back(w2);
            the_logic->row_3_A.push_back(w3);
            the_logic->row_3_B.push_back(fog);
        }
    }
    else
    {
        if (stand_row == 1)
        {
            the_logic->row_1_B.push_back(w1);
            the_logic->row_1_B.push_back(w2);
            the_logic->row_1_B.push_back(w3);
            the_logic->row_1_A.push_back(fog);
        }
        else if (stand_row == 2)
        {
            the_logic->row_2_B.push_back(w1);
            the_logic->row_2_B.push_back(w2);
            the_logic->row_2_B.push_back(w3);
            the_logic->row_2_A.push_back(fog);
        }
        else if (stand_row == 3)
        {
            the_logic->row_3_B.push_back(w1);
            the_logic->row_3_B.push_back(w2);
            the_logic->row_3_B.push_back(w3);
            the_logic->row_3_A.push_back(fog);
        }
    }
}

void Woodland_Spirit:: card_library_effect ()
{}

void Woodland_Spirit:: card_hand_effect ()
{}

void Woodland_Spirit::card_turn_end_effect ()
{}

void Woodland_Spirit::card_death_effect ()
{}

void Woodland_Spirit::card_round_end_effect ()
{}

void Woodland_Spirit::card_in_tomb_effect ()
{}

void Woodland_Spirit::card_lord_effect ()
{}

void Woodland_Spirit::card_turn_begin_effect ()
{}

//Earth_Elemental

Earth_Elemental::Earth_Elemental()
{
    ID = 16;
    total_object_id++;is_lord = false;loyality = true;race = 0;shield = false;
    object_id = total_object_id;can_revive = true;
    strength = 6;
    armor = 0;
    party = 1;
    quality = 1;
    lock =  false;

    the_chosen = NULL;
    hurt = 0;
    is_weather = false;
    is_selecting = false;
    is_put_another = false;

    is_choosing_enemy = -1;            // -1: no choose,0:enemy; 1:friend;2:all
    is_choosing_row = -1;               // -1:no choose,0:enemy;1 friend;2 all
    is_attendent = true;
    stand_position = 1;
    pix = new QPixmap(":/images/CardImage/Monsters/Earth_Elemental.png");
    show_front = true;
    back = new QPixmap(":/images/Widgets/Card_Back.png");
    description = QObject::tr("部署：获得护盾。\r\r遗愿：在该排末位生成2个\"次级土元素\"。");
    card_name = QObject::tr("土元素");
}

QRectF Earth_Elemental::boundingRect() const
{
    qreal penWidth = 1;
    return QRectF (0 - penWidth,0-penWidth,PixmapWidth + penWidth,PixmapHeight + penWidth);
}

void Earth_Elemental::set_alternatives()
{}

int Earth_Elemental::eaten_strength()
{
    return strength;
}

void Earth_Elemental::before_turncard_effect()
{}


void Earth_Elemental::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{

    if (show_front)
        painter-> drawPixmap(0,0,PixmapWidth,PixmapHeight,*pix);
    else
        painter-> drawPixmap(0,0,PixmapWidth,PixmapHeight,*back);
}

void Earth_Elemental::card_effect()
{
    shield = true;
}

void Earth_Elemental:: card_library_effect ()
{}

void Earth_Elemental:: card_hand_effect ()
{}

void Earth_Elemental::card_turn_end_effect ()
{}

void Earth_Elemental::card_death_effect ()
{
    Lesser_Earth *l1 = new Lesser_Earth;
    Lesser_Earth *l2 = new Lesser_Earth;

    if (the_logic->order)
    {
        if (stand_row == 1)
        {
            the_logic->row_1_A.push_back(l1);
            the_logic->row_1_A.push_back(l2);
        }
        else if (stand_row == 2)
        {
            the_logic->row_2_A.push_back(l1);
            the_logic->row_2_A.push_back(l2);
        }
        else if (stand_row == 3)
        {
            the_logic->row_3_A.push_back(l1);
            the_logic->row_3_A.push_back(l2);
        }
    }
    else
    {
        if (stand_row == 1)
        {
            the_logic->row_1_B.push_back(l1);
            the_logic->row_1_B.push_back(l2);
        }
        else if (stand_row == 2)
        {
            the_logic->row_2_B.push_back(l1);
            the_logic->row_2_B.push_back(l2);
        }
        else if (stand_row == 3)
        {
            the_logic->row_3_B.push_back(l1);
            the_logic->row_3_B.push_back(l2);
        }
    }
}

void Earth_Elemental::card_round_end_effect ()
{}

void Earth_Elemental::card_in_tomb_effect ()
{}

void Earth_Elemental::card_lord_effect ()
{}

void Earth_Elemental::card_turn_begin_effect ()
{}

//Crone_Weavess

Crone_Weavess::Crone_Weavess()
{
    ID = 17;
    total_object_id++;is_lord = false;loyality = true;race = 0;shield = false;
    object_id = total_object_id;can_revive = true;
    strength = 6;
    armor = 0;
    party = 2;
    quality = 2;
    lock =  false;

    the_chosen = NULL;
    hurt = 0;
    is_weather = false;
    is_selecting = false;
    is_put_another = false;

    is_choosing_enemy = -1;            // -1: no choose,0:enemy; 1:friend;2:all
    is_choosing_row = -1;               // -1:no choose,0:enemy;1 friend;2 all
    is_attendent = true;
    stand_position = 3;
    stand_row =3;
    pix = new QPixmap(":/images/CardImage/Monsters/Crone_Weavess.png");
    show_front = true;
    back = new QPixmap(":/images/Widgets/Card_Back.png");
    description =  QObject::tr("部署：从牌组打出\"煮婆\"和\"呢喃婆\"。");
    card_name = QObject::tr("老巫妪：织婆");
}

QRectF Crone_Weavess::boundingRect() const
{
    qreal penWidth = 1;
    return QRectF (0 - penWidth,0-penWidth,PixmapWidth + penWidth,PixmapHeight + penWidth);
}

void Crone_Weavess::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{

    if (show_front)
        painter-> drawPixmap(0,0,PixmapWidth,PixmapHeight,*pix);
    else
        painter-> drawPixmap(0,0,PixmapWidth,PixmapHeight,*back);
}

int Crone_Weavess::eaten_strength()
{
    return strength;
}

void Crone_Weavess::before_turncard_effect()
{}


void Crone_Weavess::set_alternatives()
{}

void Crone_Weavess::card_effect()
{
    if (the_logic->order)
    {
        foreach(Card *i ,the_logic->library_A)
        {
            if (i->ID == 18)
            {
                the_logic->library_A.removeOne(i);
                emit the_logic->AddItem(i);
                the_logic->row_3_A.push_back(i);
            }
            else if (i->ID == 19)
            {
                the_logic->library_A.removeOne(i);
                emit the_logic->AddItem(i);
                the_logic->row_3_A.push_back(i);

             }
        }
    }
    else
    {
        foreach(Card *i ,the_logic->library_B)
        {
            if (i->ID == 18)
            {
                the_logic->library_B.removeOne(i);
                emit the_logic->AddItem(i);
                the_logic->row_3_B.push_back(i);
            }
            else if (i->ID == 19)
            {
                the_logic->library_B.removeOne(i);
                emit the_logic->AddItem(i);
                the_logic->row_3_B.push_back(i);
             }
        }
    }
}

void Crone_Weavess:: card_library_effect ()
{}

void Crone_Weavess:: card_hand_effect ()
{}

void Crone_Weavess::card_turn_end_effect ()
{}

void Crone_Weavess::card_death_effect ()
{}

void Crone_Weavess::card_round_end_effect ()
{}

void Crone_Weavess::card_in_tomb_effect ()
{}

void Crone_Weavess::card_lord_effect ()
{}

void Crone_Weavess::card_turn_begin_effect ()
{}

//Crone_Whispess

Crone_Whispess::Crone_Whispess()
{
    ID = 18;
    total_object_id++;is_lord = false;loyality = true;race = 0;shield = false;
    object_id = total_object_id;can_revive = true;
    strength = 6;
    armor = 0;
    party = 1;
    quality = 2;
    lock =  false;

    the_chosen = NULL;
    hurt = 0;
    stand_row =3;
    is_weather = false;
    is_selecting = false;
    is_put_another = false;

    is_choosing_enemy = -1;            // -1: no choose,0:enemy; 1:friend;2:all
    is_choosing_row = -1;               // -1:no choose,0:enemy;1 friend;2 all
    is_attendent = true;
    stand_position = 3;
    pix = new QPixmap(":/images/CardImage/Monsters/Crone_Whispess.png");
    show_front = true;
    back = new QPixmap(":/images/Widgets/Card_Back.png");
    description = QObject:: tr("部署：从牌组打出\"煮婆\"和\"织婆\"。");
    card_name = QObject::tr("老巫妪：呢喃婆");
}

QRectF Crone_Whispess::boundingRect() const
{
    qreal penWidth = 1;
    return QRectF (0 - penWidth,0-penWidth,PixmapWidth + penWidth,PixmapHeight + penWidth);
}

void Crone_Whispess::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{

    if (show_front)
        painter-> drawPixmap(0,0,PixmapWidth,PixmapHeight,*pix);
    else
        painter-> drawPixmap(0,0,PixmapWidth,PixmapHeight,*back);
}

int Crone_Whispess::eaten_strength()
{
    return strength;
}

void Crone_Whispess::before_turncard_effect()
{}


void Crone_Whispess::card_effect()
{
    if (the_logic->order)
    {
        foreach(Card *i ,the_logic->library_A)
        {
            if (i->ID == 17)
            {
                the_logic->library_A.removeOne(i);
                emit the_logic->AddItem(i);
                the_logic->row_3_A.push_back(i);
            }
            else if (i->ID == 19)
            {
                the_logic->library_A.removeOne(i);
                emit the_logic->AddItem(i);
                the_logic->row_3_A.push_back(i);
             }
        }
    }
    else
    {
        foreach(Card *i ,the_logic->library_B)
        {
            if (i->ID == 17)
            {
                the_logic->library_B.removeOne(i);
                emit the_logic->AddItem(i);
                the_logic->row_3_B.push_back(i);
            }
            else if (i->ID == 19)
            {
                the_logic->library_B.removeOne(i);
                emit the_logic->AddItem(i);
                the_logic->row_3_B.push_back(i);
             }
        }
    }
}

void Crone_Whispess::set_alternatives()
{}
void Crone_Whispess:: card_library_effect ()
{}

void Crone_Whispess:: card_hand_effect ()
{}

void Crone_Whispess::card_turn_end_effect ()
{}

void Crone_Whispess::card_death_effect ()
{}

void Crone_Whispess::card_round_end_effect ()
{}

void Crone_Whispess::card_in_tomb_effect ()
{}

void Crone_Whispess::card_lord_effect ()
{}

void Crone_Whispess::card_turn_begin_effect ()
{}

//Crone_Brewess

Crone_Brewess::Crone_Brewess()
{
    ID = 19;
    total_object_id++;is_lord = false;loyality = true;race = 0;shield = false;
    object_id = total_object_id;can_revive = true;
    strength = 8;
    armor = 0;
    party = 1;
    quality = 2;
    lock =  false;
    stand_row =3;

    the_chosen = NULL;
    hurt = 0;
    is_weather = false;
    is_selecting = false;
    is_put_another = false;

    is_choosing_enemy = -1;            // -1: no choose,0:enemy; 1:friend;2:all
    is_choosing_row = -1;               // -1:no choose,0:enemy;1 friend;2 all
    is_attendent = true;
    stand_position=3;
    pix = new QPixmap(":/images/CardImage/Monsters/Crone_Brewess.png");
    show_front = true;
    back = new QPixmap(":/images/Widgets/Card_Back.png");
    description = QObject::tr("部署：从牌组打出\"呢喃婆\"和\"织婆\"。");
    card_name = QObject::tr("老巫妪：煮婆");
}

QRectF Crone_Brewess::boundingRect() const
{
    qreal penWidth = 1;
    return QRectF (0 - penWidth,0-penWidth,PixmapWidth + penWidth,PixmapHeight + penWidth);
}

void Crone_Brewess::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{

    if (show_front)
        painter-> drawPixmap(0,0,PixmapWidth,PixmapHeight,*pix);
    else
        painter-> drawPixmap(0,0,PixmapWidth,PixmapHeight,*back);
}
void Crone_Brewess::set_alternatives()
{}

void Crone_Brewess::card_effect()
{
    if (the_logic->order)
    {
        foreach(Card *i ,the_logic->library_A)
        {
            if (i->ID == 18)
            {
                the_logic->library_A.removeOne(i);
                 emit the_logic->AddItem(i);
                the_logic->row_3_A.push_back(i);
            }
            else if (i->ID == 17)
            {
                the_logic->library_A.removeOne(i);
                 emit the_logic->AddItem(i);
                the_logic->row_3_A.push_back(i);
             }
        }
    }
    else
    {
        foreach(Card *i ,the_logic->library_B)
        {
            if (i->ID == 18)
            {
                the_logic->library_B.removeOne(i);
                 emit the_logic->AddItem(i);
                the_logic->row_3_B.push_back(i);
            }
            else if (i->ID == 17)
            {
                the_logic->library_B.removeOne(i);
                 emit the_logic->AddItem(i);
                 the_logic->row_3_B.push_back(i);
             }
        }
    }
}

int Crone_Brewess::eaten_strength()
{
    return strength;
}

void Crone_Brewess::before_turncard_effect()
{}


void Crone_Brewess:: card_library_effect ()
{}

void Crone_Brewess:: card_hand_effect ()
{}

void Crone_Brewess::card_turn_end_effect ()
{}

void Crone_Brewess::card_death_effect ()
{}

void Crone_Brewess::card_round_end_effect ()
{}

void Crone_Brewess::card_in_tomb_effect ()
{}

void Crone_Brewess::card_lord_effect ()
{}

void Crone_Brewess::card_turn_begin_effect ()
{}

//Archgriffin

Archgriffin::Archgriffin()
{
    ID = 20;
    total_object_id++;is_lord = false;loyality = true;race = 2;shield = false;
    object_id = total_object_id;can_revive = true;
    strength = 7;
    armor = 0;
    party = 1;
    quality = 1;
    lock =  false;

    the_chosen = NULL;
    hurt = 0;
    is_weather = false;
    is_selecting = true;
    is_put_another = false;

    is_choosing_enemy = -1;            // -1: no choose,0:enemy; 1:friend;2:all
    is_choosing_row = -1;               // -1:no choose,0:enemy;1 friend;2 all
    is_attendent = true;
    stand_position=4;
    pix = new QPixmap(":/images/CardImage/Monsters/Archgriffin.png");
    show_front = true;
    back = new QPixmap(":/images/Widgets/Card_Back.png");
    description =  QObject::tr("部署：移除所在排的天气效果。\r\r 将1张铜色牌从一方墓场置入另一方墓场。");
    card_name = QObject::tr("大狮鹫");
}

QRectF Archgriffin::boundingRect() const
{
    qreal penWidth = 1;
    return QRectF (0 - penWidth,0-penWidth,PixmapWidth + penWidth,PixmapHeight + penWidth);
}

void Archgriffin::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{

    if (show_front)
        painter-> drawPixmap(0,0,PixmapWidth,PixmapHeight,*pix);
    else
        painter-> drawPixmap(0,0,PixmapWidth,PixmapHeight,*back);
}

int Archgriffin::eaten_strength()
{
    return strength;
}

void Archgriffin::before_turncard_effect()
{}


void Archgriffin::card_effect()
{

    if (the_logic->order)
    {
        switch (stand_row)
        {
            case 1:
                    foreach(Card * i ,the_logic->row_1_A)
                        if (i->is_weather)
                            the_logic->row_1_A.removeOne(i);
                    break;
            case 2:
                    foreach(Card * i ,the_logic->row_2_A)
                    if (i->is_weather)
                        the_logic->row_2_A.removeOne(i);
                     break;
            case 3:
                    foreach(Card * i ,the_logic->row_3_A)
                    if (i->is_weather)
                        the_logic->row_3_A.removeOne(i);
                    break;
            }
    }
        else
        {
            switch (stand_row)
            {
                case 1:
                        foreach(Card * i ,the_logic->row_1_B)
                            if (i->is_weather)
                                the_logic->row_1_B.removeOne(i);
                        break;
                case 2:
                        foreach(Card * i ,the_logic->row_2_B)
                        if (i->is_weather)
                            the_logic->row_2_B.removeOne(i);
                         break;
                case 3:
                        foreach(Card * i ,the_logic->row_3_B)
                        if (i->is_weather)
                            the_logic->row_3_B.removeOne(i);
                        break;
              }
          }

    if (the_chosen == NULL)
        return;
    if (the_logic->tomb_A.contains(the_chosen))
    {
        the_logic->tomb_A.removeOne(the_chosen);
        the_logic->tomb_B.push_back(the_chosen);
    }
    else if(the_logic->tomb_B.contains(the_chosen))
    {
        the_logic->tomb_B.removeOne(the_chosen);
        the_logic->tomb_A.push_back(the_chosen);
    }
}

void Archgriffin::set_alternatives()
{
    foreach (Card *i , the_logic->tomb_A)
        if(i->quality == 1)
            alternative.push_back(i);
    foreach (Card *i,the_logic->tomb_B)
        if(i->quality == 1)
            alternative.push_back(i);

}
void Archgriffin:: card_library_effect ()
{}

void Archgriffin:: card_hand_effect ()
{}

void Archgriffin::card_turn_end_effect ()
{}

void Archgriffin::card_death_effect ()
{}

void Archgriffin::card_round_end_effect ()
{}

void Archgriffin::card_in_tomb_effect ()
{}

void Archgriffin::card_lord_effect ()
{}

void Archgriffin::card_turn_begin_effect ()
{}

//Wild Hunt Rider

Wild_Hunt_Rider::Wild_Hunt_Rider()
{
    ID = 21;
    total_object_id++;is_lord = false;loyality = true;race = 0;shield = false;
    object_id = total_object_id;can_revive = true;
    strength = 7;
    armor = 0;
    party = 1;
    quality = 2;
    lock =  false;

    the_chosen = NULL;
    hurt = 0;
    is_weather = false;
    is_selecting = false;
    is_put_another = false;

    is_choosing_enemy = -1;            // -1: no choose,0:enemy; 1:friend;2:all
    is_choosing_row = -1;               // -1:no choose,0:enemy;1 friend;2 all
    is_attendent = true;
    stand_position = 4;
    pix = new QPixmap(":/images/CardImage/Monsters/Wild_Hunt_Rider.png");
    show_front = true;
    back = new QPixmap(":/images/Widgets/Card_Back.png");
    description = QObject:: tr("使对方此排的\"刺骨冰霜\"伤害提高 1 点。");
    card_name = QObject::tr("狂猎骑士");
}

QRectF Wild_Hunt_Rider::boundingRect() const
{
    qreal penWidth = 1;
    return QRectF (0 - penWidth,0-penWidth,PixmapWidth + penWidth,PixmapHeight + penWidth);
}

void Wild_Hunt_Rider::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{

    if (show_front)
        painter-> drawPixmap(0,0,PixmapWidth,PixmapHeight,*pix);
    else
        painter-> drawPixmap(0,0,PixmapWidth,PixmapHeight,*back);
}

int Wild_Hunt_Rider::eaten_strength()
{
    return strength;
}

void Wild_Hunt_Rider::before_turncard_effect()
{}

void Wild_Hunt_Rider::card_effect()
{
    if (the_logic->order)
    {
        switch (stand_row)
        {
            case 1:
                    foreach(Card * i ,the_logic->row_1_B)
                        if (i->ID == 1)
                            i->hurt++;
                    break;
            case 2:
                    foreach(Card * i ,the_logic->row_2_B)
                        if (i->ID == 1)
                            i->hurt++;
                     break;
            case 3:
                    foreach(Card * i ,the_logic->row_3_B)
                        if (i->ID == 1)
                            i->hurt++;
                    break;
            }
    }
        else
        {
            switch (stand_row)
            {
                case 1:
                        foreach(Card * i ,the_logic->row_1_A)
                            if (i->ID == 1)
                                i->hurt++;
                        break;
                case 2:
                        foreach(Card * i ,the_logic->row_2_A)
                            if (i->ID == 1)
                                i->hurt++;
                         break;
                case 3:
                        foreach(Card * i ,the_logic->row_3_A)
                            if (i->ID == 1)
                                i->hurt++;
                        break;
              }
          }

}
void Wild_Hunt_Rider::set_alternatives()
{}

void Wild_Hunt_Rider:: card_library_effect ()
{}

void Wild_Hunt_Rider:: card_hand_effect ()
{}

void Wild_Hunt_Rider::card_turn_end_effect ()
{}

void Wild_Hunt_Rider::card_death_effect ()
{}

void Wild_Hunt_Rider::card_round_end_effect ()
{}

void Wild_Hunt_Rider::card_in_tomb_effect ()
{}

void Wild_Hunt_Rider::card_lord_effect ()
{}

void Wild_Hunt_Rider::card_turn_begin_effect ()
{}


//Caranthir

Caranthir::Caranthir()
{
    ID = 22;
    total_object_id++;is_lord = false;loyality = true;race = 0;shield = false;
    object_id = total_object_id;can_revive = true;
    strength = 9;
    armor = 0;
    party = 1;
    quality = 3;
    lock =  false;

    the_chosen = NULL;
    hurt = 0;
    is_weather = false;
    is_selecting = false;
    is_put_another = false;

    is_choosing_enemy = 0;            // -1: no choose,0:enemy; 1:friend;2:all
    select_num = 3;
    is_choosing_row = -1;               // -1:no choose,0:enemy;1 friend;2 all
    is_attendent = true;
    stand_position = 4;
    pix = new QPixmap(":/images/CardImage/Monsters/Caranthir.png");
    show_front = true;
    back = new QPixmap(":/images/Widgets/Card_Back.png");
    description = QObject::tr("部署：将3个敌军单位移至对方同排，并在此排降下\"刺骨冰霜\"。");
    card_name = QObject::tr("卡兰希尔");
}

QRectF Caranthir::boundingRect() const
{
    qreal penWidth = 1;
    return QRectF (0 - penWidth,0-penWidth,PixmapWidth + penWidth,PixmapHeight + penWidth);
}

void Caranthir::set_alternatives()
{}

int Caranthir::eaten_strength()
{
    return strength;
}

void Caranthir::before_turncard_effect()
{}


void Caranthir::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{

    if (show_front)
        painter-> drawPixmap(0,0,PixmapWidth,PixmapHeight,*pix);
    else
        painter-> drawPixmap(0,0,PixmapWidth,PixmapHeight,*back);
}

void Caranthir::card_effect()
{
    Biting_Frost *bt = new Biting_Frost;
    bt->the_logic = the_logic;


    if (target.isEmpty())
    {
        if (the_logic->order)
        {
            switch(stand_row)
            {
            case 1:
                    the_logic->row_1_B.push_back(bt);
                    break;
            case 2:
                    the_logic->row_2_B.push_back(bt);
                    break;
            case 3:
                    the_logic->row_3_B.push_back(bt);
                    break;
            }
        }
            else
            {
                switch(stand_row)
                {
                case 1:
                        the_logic->row_1_A.push_back(bt);
                        break;
                case 2:
                        the_logic->row_2_A.push_back(bt);
                        break;
                case 3:
                        the_logic->row_3_A.push_back(bt);
                        break;
                }

            }

          return;
        }


    if (the_logic->order)
    {

            if(the_logic->row_1_B.contains(target[the_logic->have_selected-1]))
                the_logic->row_1_B.removeOne(target[the_logic->have_selected-1]);
            else if(the_logic->row_2_B.contains(target[the_logic->have_selected-1]))
                the_logic->row_1_B.removeOne(target[the_logic->have_selected-1]);
            else if(the_logic->row_3_B.contains(target[the_logic->have_selected-1]))
                the_logic->row_3_B.removeOne(target[the_logic->have_selected-1]);

            switch(stand_row)
            {
            case 1: the_logic->row_1_B.push_back(target[the_logic->have_selected-1]);
                    if(!the_logic->row_1_B.contains(bt))
                        the_logic->row_1_B.push_back(bt);
                    break;
            case 2: the_logic->row_2_B.push_back(target[the_logic->have_selected-1]);
                    if(!the_logic->row_2_B.contains(bt))
                         the_logic->row_2_B.push_back(bt);
                    break;
            case 3: the_logic->row_3_B.push_back(target[the_logic->have_selected-1]);
                    if(!the_logic->row_3_B.contains(bt))
                        the_logic->row_3_B.push_back(bt);
                    break;
            }
    }
    else
    {

        if(the_logic->row_1_A.contains(target[the_logic->have_selected-1]))
            the_logic->row_1_A.removeOne(target[the_logic->have_selected-1]);
        else if(the_logic->row_2_A.contains(target[the_logic->have_selected-1]))
            the_logic->row_1_A.removeOne(target[the_logic->have_selected-1]);
        else if(the_logic->row_3_A.contains(target[the_logic->have_selected-1]))
            the_logic->row_3_A.removeOne(target[the_logic->have_selected-1]);

        switch(stand_row)
        {
        case 1: the_logic->row_1_A.push_back(target[the_logic->have_selected-1]);
                if(!the_logic->row_1_A.contains(bt))
                    the_logic->row_1_A.push_back(bt);
                break;
        case 2: the_logic->row_2_A.push_back(target[the_logic->have_selected-1]);
                if(!the_logic->row_2_A.contains(bt))
                     the_logic->row_2_A.push_back(bt);
                break;
        case 3: the_logic->row_3_A.push_back(target[the_logic->have_selected-1]);
                if(!the_logic->row_3_A.contains(bt))
                    the_logic->row_3_A.push_back(bt);
                break;
        }
    }
}

void Caranthir:: card_library_effect ()
{}

void Caranthir:: card_hand_effect ()
{}

void Caranthir::card_turn_end_effect ()
{}

void Caranthir::card_death_effect ()
{}

void Caranthir::card_round_end_effect ()
{}

void Caranthir::card_in_tomb_effect ()
{}

void Caranthir::card_lord_effect ()
{}

void Caranthir::card_turn_begin_effect ()
{}

//Frightener

Frightener::Frightener()
{
    ID = 23;
    total_object_id++;is_lord = false;loyality = false;race = 0;shield = false;
    object_id = total_object_id;
    can_revive = false;
    strength = 10;
    armor = 0;
    party = 1;
    quality = 2;
    lock =  false;

    the_chosen = NULL;
    hurt = 0;
    is_weather = false;
    is_selecting = false;
    is_put_another = false;

    is_choosing_enemy = 2;            // -1: no choose,0:enemy; 1:friend;2:all
    select_num = 1;
    is_choosing_row = -1;               // -1:no choose,0:enemy;1 friend;2 all
    is_attendent = true;
    stand_position = 4;
    pix = new QPixmap(":/images/CardImage/Monsters/Frightener.png");
    show_front = true;
    back = new QPixmap(":/images/Widgets/Card_Back.png");
    description = QObject::tr("部署：从牌组顶端抽1张牌。将所在战场其他排的1个单位移至自身的同一排。");
    card_name = QObject::tr("畏惧者");
}

QRectF Frightener::boundingRect() const
{
    qreal penWidth = 1;
    return QRectF (0 - penWidth,0-penWidth,PixmapWidth + penWidth,PixmapHeight + penWidth);
}

int Frightener::eaten_strength()
{
    return strength;
}

void Frightener::before_turncard_effect()
{}


void Frightener::set_alternatives()
{}

void Frightener::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{

    if (show_front)
        painter-> drawPixmap(0,0,PixmapWidth,PixmapHeight,*pix);
    else
        painter-> drawPixmap(0,0,PixmapWidth,PixmapHeight,*back);
}

void Frightener::card_effect()
{
    if (the_logic->order)
    {
        the_logic->hand_A.push_back(the_logic->library_A.first());
        emit  the_logic->AddItem(the_logic->library_A.first());
        the_logic->library_A.removeFirst();

        if (!target.isEmpty())
        {
            switch(target[0]->stand_row)
            {
            case 1:
                the_logic->row_1_B.removeOne(target[0]);
                break;
            case 2:
                the_logic->row_2_B.removeOne(target[0]);
                break;
            case 3:
                the_logic->row_3_B.removeOne(target[0]);
                break;
            }
            switch(stand_row)
            {
            case 4:
                the_logic->row_1_B.push_back(target[0]);
                break;
            case 5:
                the_logic->row_2_B.push_back(target[0]);
                break;
            case 6:
                the_logic->row_3_B.push_back(target[0]);
             }
        }
    }
    else
    {
        the_logic->hand_B.push_back(the_logic->library_B.first());
        emit  the_logic->AddItem(the_logic->library_B.first());
        the_logic->library_B.removeFirst();

        if (!target.isEmpty())
        {
            switch(target[0]->stand_row)
            {
            case 1:
                the_logic->row_1_A.removeOne(target[0]);
                break;
            case 2:
                the_logic->row_2_A.removeOne(target[0]);
                break;
            case 3:
                the_logic->row_3_A.removeOne(target[0]);
                break;
            }
            switch(stand_row)
            {
            case 4:
                the_logic->row_1_A.push_back(target[0]);
                break;
            case 5:
                the_logic->row_2_A.push_back(target[0]);
                break;
            case 6:
                the_logic->row_3_A.push_back(target[0]);
             }
        }
    }
    emit the_logic->PaintView();
}

void Frightener:: card_library_effect ()
{}

void Frightener:: card_hand_effect ()
{}

void Frightener::card_turn_end_effect ()
{}

void Frightener::card_death_effect ()
{}

void Frightener::card_round_end_effect ()
{}

void Frightener::card_in_tomb_effect ()
{}

void Frightener::card_lord_effect ()
{}

void Frightener::card_turn_begin_effect ()
{}

//Unseen_Elder

Unseen_Elder::Unseen_Elder()
{
    ID = 24;
    total_object_id++;is_lord = true;loyality = true;race = 0;shield = false;
    object_id = total_object_id;
    can_revive = false;
    strength = 5;
    armor = 0;
    party = 1;
    quality = 3;
    lock =  false;

    the_chosen = NULL;
    hurt = 0;
    is_weather = false;
    is_selecting = false;
    is_put_another = false;

    is_choosing_enemy = 1;            // -1: no choose,0:enemy; 1:friend;2:all
    select_num = 3;
    is_choosing_row = -1;               // -1:no choose,0:enemy;1 friend;2 all
    is_attendent = true;
    stand_position = 4;
    pix = new QPixmap(":/images/CardImage/Monsters/Unseen_Elder.png");
    show_front = true;
    back = new QPixmap(":/images/Widgets/Card_Back.png");
    description = QObject::tr("部署：吞噬3个友军单位，吸收它们的战力为自身的基础战力。");
    card_name  = QObject::tr("暗影长者");
}

QRectF Unseen_Elder::boundingRect() const
{
    qreal penWidth = 1;
    return QRectF (0 - penWidth,0 - penWidth,PixmapWidth + penWidth,PixmapHeight + penWidth);
}

void Unseen_Elder::set_alternatives()
{}

int Unseen_Elder::eaten_strength()
{
    return strength;
}

void Unseen_Elder::before_turncard_effect()
{}


void Unseen_Elder::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{

    if (show_front)
        painter-> drawPixmap(0,0,PixmapWidth,PixmapHeight,*pix);
    else
        painter-> drawPixmap(0,0,PixmapWidth,PixmapHeight,*back);
}

void Unseen_Elder::card_effect()
{
    if (!target.isEmpty())
    {
        strength += target[the_logic->have_selected-1]->eaten_strength();
        target[the_logic->have_selected-1]->strength = 0;
        the_logic->friend_eaten_perturn++;
    }
}

void Unseen_Elder:: card_library_effect ()
{}

void Unseen_Elder:: card_hand_effect ()
{}

void Unseen_Elder::card_turn_end_effect ()
{}

void Unseen_Elder::card_death_effect ()
{}

void Unseen_Elder::card_round_end_effect ()
{}

void Unseen_Elder::card_in_tomb_effect ()
{}

void Unseen_Elder::card_lord_effect ()
{}

void Unseen_Elder::card_turn_begin_effect ()
{}

//Arachas

Arachas::Arachas()
{
    ID = 25;
    total_object_id++;is_lord = false;loyality = true;race = 0;shield = false;
    object_id = total_object_id;can_revive = true;
    strength = 3;
    armor = 0;
    party = 1;
    quality = 2;
    lock =  false;

    the_chosen = NULL;
    hurt = 0;
    is_weather = false;
    is_selecting = false;
    is_put_another = false;

    is_choosing_enemy = -1;            // -1: no choose,0:enemy; 1:friend;2:all
    is_choosing_row = -1;               // -1:no choose,0:enemy;1 friend;2 all
    is_attendent = true;
    stand_position = 2;
    pix = new QPixmap(":/images/CardImage/Monsters/Arachas.png");
    show_front = true;
    back = new QPixmap(":/images/Widgets/Card_Back.png");
    description = QObject::tr("部署：从牌组打出所有\"蟹蜘蛛\"。");
    card_name = QObject::tr("蟹蜘蛛");
}

QRectF Arachas::boundingRect() const
{
    qreal penWidth = 1;
    return QRectF (0 - penWidth,0-penWidth,PixmapWidth + penWidth,PixmapHeight + penWidth);
}

int Arachas::eaten_strength()
{
    return strength;
}

void Arachas::before_turncard_effect()
{}


void Arachas::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{

    if (show_front)
        painter-> drawPixmap(0,0,PixmapWidth,PixmapHeight,*pix);
    else
        painter-> drawPixmap(0,0,PixmapWidth,PixmapHeight,*back);
}
void Arachas::card_effect()
{
    if (the_logic->order)
    {
        foreach(Card *i ,the_logic->library_A)
        {
            if (i->ID == 25)
            {
                the_logic->library_A.removeOne(i);
                switch(stand_row)
                {
                case 1:the_logic->row_1_A.push_back(i);
                        break;
                case 2:the_logic->row_2_A.push_back(i);
                        break;
                case 3:the_logic->row_3_A.push_back(i);
                        break;
                }
            }
        }
    }
    else
    {
        foreach(Card *i ,the_logic->library_B)
        {
            if (i->ID == 25)
            {
                the_logic->library_B.removeOne(i);
                switch(stand_row)
                {
                case 1:the_logic->row_1_B.push_back(i);
                        break;
                case 2:the_logic->row_2_B.push_back(i);
                        break;
                case 3:the_logic->row_3_B.push_back(i);
                        break;
                }
            }
        }
    }
}

void Arachas::set_alternatives()
{}

void Arachas:: card_library_effect ()
{}

void Arachas:: card_hand_effect ()
{}

void Arachas::card_turn_end_effect ()
{}

void Arachas::card_death_effect ()
{}

void Arachas::card_round_end_effect ()
{}

void Arachas::card_in_tomb_effect ()
{}

void Arachas::card_lord_effect ()
{}

void Arachas::card_turn_begin_effect ()
{}

//Arachas_Behemoth

Arachas_Behemoth::Arachas_Behemoth()
{
    ID = 26;
    total_object_id++;is_lord = false;loyality = true;race = 0;shield = false;
    object_id = total_object_id;can_revive = true;
    strength = 6;
    armor = 0;
    party = 1;
    quality = 1;
    lock =  false;

    the_chosen = NULL;
    hurt = 0;
    is_weather = false;
    is_selecting = false;
    is_put_another = false;

    is_choosing_enemy = -1;            // -1: no choose,0:enemy; 1:friend;2:all
    is_choosing_row = -1;               // -1:no choose,0:enemy;1 friend;2 all
    is_attendent = true;
    stand_position=3;
    pix = new QPixmap(":/images/CardImage/Monsters/Arachas_Behemoth.png");
    show_front = true;
    back = new QPixmap(":/images/Widgets/Card_Back.png");
    description = QObject::tr("每当有友军单位吞噬1张牌，便生成1只\"蟹蜘蛛幼虫\"，随后受到1点伤害（无视护甲）。部署：获得2点护甲。");
    card_name = QObject::tr("蟹蜘蛛巨兽");
}

QRectF Arachas_Behemoth::boundingRect() const
{
    qreal penWidth = 1;
    return QRectF (0 - penWidth,0-penWidth,PixmapWidth + penWidth,PixmapHeight + penWidth);
}

int Arachas_Behemoth::eaten_strength()
{
    return strength;
}

void Arachas_Behemoth::before_turncard_effect()
{}


void Arachas_Behemoth::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{

    if (show_front)
        painter-> drawPixmap(0,0,PixmapWidth,PixmapHeight,*pix);
    else
        painter-> drawPixmap(0,0,PixmapWidth,PixmapHeight,*back);
}
void Arachas_Behemoth::card_effect()
{
    armor+=2;
}

void Arachas_Behemoth::set_alternatives()
{}

void Arachas_Behemoth:: card_library_effect ()
{
    Arachas_Larva * AL[the_logic->friend_eaten_perturn];
    for (int i =0 ;i <the_logic->friend_eaten_perturn;i++ )
    {
        AL[i] = new Arachas_Larva;
        AL[i]->the_logic = the_logic;

        if (the_logic->order)
        {
            switch(stand_row)
            {
                case 1:
                    the_logic->row_1_A.push_back(AL[i]);
                    break;
                case 2:
                    the_logic->row_2_A.push_back(AL[i]);
                    break;
                 case 3:
                    the_logic->row_3_A.push_back(AL[i]);
                    break;
            }
        }
        else
        {
            switch(stand_row)
            {
                case 1:
                    the_logic->row_1_B.push_back(AL[i]);
                    break;
                case 2:
                    the_logic->row_2_B.push_back(AL[i]);
                    break;
                 case 3:
                    the_logic->row_3_B.push_back(AL[i]);
                    break;
            }
        }
        emit the_logic->AddItem(AL[i]);
    }

}

void Arachas_Behemoth:: card_hand_effect ()
{}

void Arachas_Behemoth::card_turn_end_effect ()
{}

void Arachas_Behemoth::card_death_effect ()
{}

void Arachas_Behemoth::card_round_end_effect ()
{}

void Arachas_Behemoth::card_in_tomb_effect ()
{}

void Arachas_Behemoth::card_lord_effect ()
{}

void Arachas_Behemoth::card_turn_begin_effect ()
{}

//Vran_Warrior

Vran_Warrior::Vran_Warrior()
{
    ID = 27;
    total_object_id++;is_lord = false;loyality = true;race = 0;shield = false;
    object_id = total_object_id;can_revive = true;
    strength = 5;
    armor = 0;
    party = 1;
    quality = 1;
    lock =  false;

    the_chosen = NULL;
    hurt = 0;
    is_weather = false;
    is_selecting = false;
    is_put_another = false;
    round_count = 0;

    is_choosing_enemy = -1;            // -1: no choose,0:enemy; 1:friend;2:all
    is_choosing_row = -1;               // -1:no choose,0:enemy;1 friend;2 all
    is_attendent = true;
    stand_position = 4;
    pix = new QPixmap(":/images/CardImage/Monsters/Vran_Warrior.png");
    show_front = true;
    back = new QPixmap(":/images/Widgets/Card_Back.png");
    description = QObject::tr("部署：吞噬右侧单位。\r\r每2回合，己方回合开始时，吞噬右侧单位。");
    card_name = QObject::tr("蜥蜴人战士");
}

QRectF Vran_Warrior::boundingRect() const
{
    qreal penWidth = 1;
    return QRectF (0 - penWidth,0-penWidth,PixmapWidth + penWidth,PixmapHeight + penWidth);
}

void Vran_Warrior::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{

    if (show_front)
        painter-> drawPixmap(0,0,PixmapWidth,PixmapHeight,*pix);
    else
        painter-> drawPixmap(0,0,PixmapWidth,PixmapHeight,*back);
}
void Vran_Warrior::card_effect()
{
    Card *right = NULL;
    int i,size;
    if (the_logic->order)
    {
        switch (stand_row)
        {
            case 1:
                i = the_logic->row_1_A.indexOf(the_logic->turn_card);
                size = the_logic->row_1_A.size();
                for (int j = i ;j< size;j++)
                    if (the_logic->row_1_A[j]->is_attendent)
                    {
                    right = the_logic->row_1_A[j];
                    break;
                    }
                break;

            case 2:
                i = the_logic->row_2_A.indexOf(the_logic->turn_card);
                size = the_logic->row_2_A.size();
            for (int j = i ;j< size;j++)
                if (the_logic->row_2_A[j]->is_attendent)
                {
                right = the_logic->row_2_A[j];
                break;
                }
            break;
            case 3:
                i = the_logic->row_3_A.indexOf(the_logic->turn_card);
                size = the_logic->row_3_A.size();
            for (int j = i ;j< size;j++)
                if (the_logic->row_3_A[j]->is_attendent)
                {
                right = the_logic->row_3_A[j];
                break;
                }
            break;
        }
    }
    else
    {
        switch (stand_row)
        {
            case 1:
                    i = the_logic->row_1_B.indexOf(the_logic->turn_card);
                    size = the_logic->row_1_B.size();
                for (int j = i ;j< size;j++)
                    if (the_logic->row_1_B[j]->is_attendent)
                    {
                    right = the_logic->row_1_B[j];
                    break;
                    }
                break;

            case 2:
                 i = the_logic->row_2_B.indexOf(the_logic->turn_card);
                size = the_logic->row_2_B.size();
            for (int j = i ;j< size;j++)
                if (the_logic->row_2_B[j]->is_attendent)
                {
                right = the_logic->row_2_B[j];
                break;
                }
            break;
            case 3:
                i = the_logic->row_3_B.indexOf(the_logic->turn_card);
                size = the_logic->row_3_B.size();
            for (int j = i ;j< size;j++)
                if (the_logic->row_3_B[j]->is_attendent)
                {
                right = the_logic->row_3_B[j];
                break;
                }
            break;
        }
    }
    if (right != NULL)
    {
        strength += right->eaten_strength();
        right->strength = 0;
        the_logic->friend_eaten_perturn++;
    }
}

int Vran_Warrior::eaten_strength()
{
    return strength;
}

void Vran_Warrior::before_turncard_effect()
{}


void Vran_Warrior::set_alternatives()
{}

void Vran_Warrior:: card_library_effect ()
{
}

void Vran_Warrior:: card_hand_effect ()
{}

void Vran_Warrior::card_turn_end_effect ()
{}

void Vran_Warrior::card_death_effect ()
{}

void Vran_Warrior::card_round_end_effect ()
{}

void Vran_Warrior::card_in_tomb_effect ()
{}

void Vran_Warrior::card_lord_effect ()
{}

void Vran_Warrior::card_turn_begin_effect ()
{
    round_count++;
    if (round_count == 2 )
    {
        round_count = 0;
        Card *right = NULL;
        int i,size;
        if (the_logic->order)
        {
            switch (stand_row)
            {
                case 1:
                    i = the_logic->row_1_A.indexOf(the_logic->turn_card);
                    size = the_logic->row_1_A.size();
                    for (int j = i ;j< size;j++)
                        if (the_logic->row_1_A[j]->is_attendent)
                        {
                        right = the_logic->row_1_A[j];
                        break;
                        }
                    break;

                case 2:
                    i = the_logic->row_2_A.indexOf(the_logic->turn_card);
                    size = the_logic->row_2_A.size();
                for (int j = i ;j< size;j++)
                    if (the_logic->row_2_A[j]->is_attendent)
                    {
                    right = the_logic->row_2_A[j];
                    break;
                    }
                break;
                case 3:
                    i = the_logic->row_3_A.indexOf(the_logic->turn_card);
                    size = the_logic->row_3_A.size();
                for (int j = i ;j< size;j++)
                    if (the_logic->row_3_A[j]->is_attendent)
                    {
                    right = the_logic->row_3_A[j];
                    break;
                    }
                break;
            }
        }
        else
        {
            switch (stand_row)
            {
                case 1:
                        i = the_logic->row_1_B.indexOf(the_logic->turn_card);
                        size = the_logic->row_1_B.size();
                    for (int j = i ;j< size;j++)
                        if (the_logic->row_1_B[j]->is_attendent)
                        {
                        right = the_logic->row_1_B[j];
                        break;
                        }
                    break;

                case 2:
                    i = the_logic->row_2_B.indexOf(the_logic->turn_card);
                    size = the_logic->row_2_B.size();
                for (int j = i ;j< size;j++)
                    if (the_logic->row_2_B[j]->is_attendent)
                    {
                    right = the_logic->row_2_B[j];
                    break;
                    }
                break;
                case 3:
                    i = the_logic->row_3_B.indexOf(the_logic->turn_card);
                    size = the_logic->row_3_B.size();
                for (int j = i ;j< size;j++)
                    if (the_logic->row_3_B[j]->is_attendent)
                    {
                    right = the_logic->row_3_B[j];
                    break;
                    }
                break;
            }
        }
        if (right != NULL)
        {
            strength += right->strength;
            right->strength = 0;
            the_logic->friend_eaten_perturn++;
        }
    }


}

//Sunny_Day

Sunny_Day::Sunny_Day()
{
    ID = 28;
    total_object_id++;is_lord = false;loyality = true;race = 0;shield = false;
    object_id = total_object_id;can_revive = true;
    strength = 0;
    armor = 0;
    party = 1;
    quality = 1;
    lock =  false;

    the_chosen = NULL;
    hurt = 0;
    is_weather = false;
    is_selecting = false;
    is_put_another = false;

    is_choosing_enemy = -1;            // -1: no choose,0:enemy; 1:friend;2:all
    is_choosing_row = 2;               // -1:no choose,0:enemy;1 friend;2 all
    is_attendent = false;
    pix = new QPixmap(":/images/CardImage/Neutral/Sunny_Day.png");
    show_front = true;
    back = new QPixmap(":/images/Widgets/Card_Back.png");
    description = QObject::tr("消除指定排的天气效果");
    card_name = QObject::tr("晴空");
}

QRectF Sunny_Day::boundingRect() const
{
    qreal penWidth = 1;
    return QRectF (0 - penWidth,0-penWidth,PixmapWidth + penWidth,PixmapHeight + penWidth);
}

void Sunny_Day::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{

    if (show_front)
        painter-> drawPixmap(0,0,PixmapWidth,PixmapHeight,*pix);
    else
        painter-> drawPixmap(0,0,PixmapWidth,PixmapHeight,*back);
}

void Sunny_Day::set_alternatives()
{}
void Sunny_Day::card_effect()
{
    if (the_logic->order)
    {
        switch (effect_row)
        {
            case 1:
                    foreach(Card * i ,the_logic->row_1_B)
                        if (i->is_weather)
                            the_logic->row_1_B.removeOne(i);
                    break;
            case 2:
                    foreach(Card * i ,the_logic->row_2_B)
                    if (i->is_weather)
                        the_logic->row_2_B.removeOne(i);
                     break;
            case 3:
                    foreach(Card * i ,the_logic->row_3_B)
                    if (i->is_weather)
                        the_logic->row_3_B.removeOne(i);
                    break;
            case 4:
                    foreach(Card * i ,the_logic->row_1_A)
                    if (i->is_weather)
                        the_logic->row_1_A.removeOne(i);
                     break;
             case 5:
                    foreach(Card * i ,the_logic->row_2_A)
                    if (i->is_weather)
                        the_logic->row_2_A.removeOne(i);
                    break;
             case 6:
                    foreach(Card * i ,the_logic->row_3_A)
                    if (i->is_weather)
                          the_logic->row_3_A.removeOne(i);
                     break;
            }
    }
        else
        {
            switch (effect_row)
            {
                case 1:
                        foreach(Card * i ,the_logic->row_1_A)
                            if (i->is_weather)
                                the_logic->row_1_A.removeOne(i);
                        break;
                case 2:
                        foreach(Card * i ,the_logic->row_2_A)
                        if (i->is_weather)
                            the_logic->row_2_A.removeOne(i);
                         break;
                case 3:
                        foreach(Card * i ,the_logic->row_3_A)
                        if (i->is_weather)
                            the_logic->row_3_A.removeOne(i);
                        break;
                case 4:
                        foreach(Card * i ,the_logic->row_1_B)
                        if (i->is_weather)
                            the_logic->row_1_B.removeOne(i);
                         break;
                 case 5:
                        foreach(Card * i ,the_logic->row_2_B)
                        if (i->is_weather)
                            the_logic->row_2_B.removeOne(i);
                        break;
                 case 6:
                        foreach(Card * i ,the_logic->row_3_B)
                        if (i->is_weather)
                              the_logic->row_3_B.removeOne(i);
                         break;
              }
            }

}

void Sunny_Day:: card_library_effect ()
{}

void Sunny_Day:: card_hand_effect ()
{}

void Sunny_Day::card_turn_end_effect ()
{}

void Sunny_Day::card_death_effect ()
{}

void Sunny_Day::card_round_end_effect ()
{}

void Sunny_Day::card_in_tomb_effect ()
{}

void Sunny_Day::card_lord_effect ()
{}

void Sunny_Day::card_turn_begin_effect ()
{}

int Sunny_Day::eaten_strength()
{return 0;}

void Sunny_Day::before_turncard_effect()
{}

//Restart

Restart::Restart()
{
    ID = 29;
    total_object_id++;is_lord = false;loyality = true;race = 0;shield = false;
    object_id = total_object_id;can_revive = true;

    strength = 0;
    armor = 0;
    party = 1;
    quality = 1;
    lock =  false;

    the_chosen = NULL;
    hurt = 0;
    is_weather = false;
    is_selecting = true;
    is_put_another = true;

    is_choosing_enemy = -1;            // -1: no choose,0:enemy; 1:friend;2:all
    is_choosing_row = -1;               // -1:no choose,0:enemy;1 friend;2 all
    is_attendent = false;
    pix = new QPixmap(":/images/CardImage/Neutral/Restart.png");
    show_front = true;
    back = new QPixmap(":/images/Widgets/Card_Back.png");
    description = QObject::tr("从牌组随机抽一张铜色牌打出。");
    card_name = QObject::tr("重整");
}

QRectF Restart::boundingRect() const
{
    qreal penWidth = 1;
    return QRectF (0 - penWidth,0-penWidth,PixmapWidth + penWidth,PixmapHeight + penWidth);
}

void Restart::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{

    if (show_front)
        painter-> drawPixmap(0,0,PixmapWidth,PixmapHeight,*pix);
    else
        painter-> drawPixmap(0,0,PixmapWidth,PixmapHeight,*back);
}


void Restart::set_alternatives()
{
    Card *temp = NULL;
    if (the_logic->order)
    {
        int total=the_logic->library_A.size();;
        do
        {
        qsrand(QTime::currentTime().msec());
        temp = the_logic->library_A[qrand()%total];
        }while(temp->quality!= 1);
    }
    else
    {
        int total=the_logic->library_B.size();;
        do
        {
        qsrand(QTime::currentTime().msec());
        temp = the_logic->library_B[qrand()%total];
        }while(temp->quality!= 1);
    }
    alternative.push_back(temp);
}
int Restart::eaten_strength()
{return 0;}

void Restart::before_turncard_effect()
{}


void Restart::card_effect()
{}

void Restart:: card_library_effect ()
{}

void Restart:: card_hand_effect ()
{}

void Restart::card_turn_end_effect ()
{}

void Restart::card_death_effect ()
{}

void Restart::card_round_end_effect ()
{}

void Restart::card_in_tomb_effect ()
{}

void Restart::card_lord_effect ()
{}

void Restart::card_turn_begin_effect ()
{}

//Lesser_Earth

Lesser_Earth::Lesser_Earth()
{
    ID = 30;
    total_object_id++;is_lord = false;loyality = true;race = 0;shield = false;
    object_id = total_object_id;can_revive = true;
    strength = 2;
    armor = 0;
    party = 2;
    quality = 1;
    lock =  false;

    the_chosen = NULL;
    hurt = 0;
    is_weather = false;
    is_selecting = false;
    is_put_another = false;

    is_choosing_enemy = -1;            // -1: no choose,0:enemy; 1:friend;2:all
    is_choosing_row = -1;               // -1:no choose,0:enemy;1 friend;2 all
    is_attendent = true;
    stand_position = 1;
    pix = new QPixmap(":/images/CardImage/Monsters/Lesser_Earth.png");
    show_front = true;
    back = new QPixmap(":/images/Widgets/Card_Back.png");
    description.clear();
    card_name = QObject::tr("次级土元素");
}

QRectF Lesser_Earth::boundingRect() const
{
    qreal penWidth = 1;
    return QRectF (0 - penWidth,0-penWidth,PixmapWidth + penWidth,PixmapHeight + penWidth);
}

void Lesser_Earth::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{

    if (show_front)
        painter-> drawPixmap(0,0,PixmapWidth,PixmapHeight,*pix);
    else
        painter-> drawPixmap(0,0,PixmapWidth,PixmapHeight,*back);
}
int Lesser_Earth::eaten_strength()
{
    return strength;
}

void Lesser_Earth::before_turncard_effect()
{}


void Lesser_Earth::card_effect()
{}

void Lesser_Earth::set_alternatives()
{}

void Lesser_Earth:: card_library_effect ()
{}

void Lesser_Earth:: card_hand_effect ()
{}

void Lesser_Earth::card_turn_end_effect ()
{}

void Lesser_Earth::card_death_effect ()
{}

void Lesser_Earth::card_round_end_effect ()
{}

void Lesser_Earth::card_in_tomb_effect ()
{}

void Lesser_Earth::card_lord_effect ()
{}

void Lesser_Earth::card_turn_begin_effect ()
{}

//Harpy_Egg

Harpy_Egg::Harpy_Egg()
{
    ID = 31;
    total_object_id++;is_lord = false;loyality = true;race = 0;shield = false;
    object_id = total_object_id;can_revive = false;
    strength = 1;
    armor = 0;
    party = 2;
    quality = 1;
    lock =  false;

    the_chosen = NULL;
    hurt = 0;
    is_weather = false;
    is_selecting = false;
    is_put_another = false;

    is_choosing_enemy = -1;            // -1: no choose,0:enemy; 1:friend;2:all
    is_choosing_row = -1;               // -1:no choose,0:enemy;1 friend;2 all
    is_attendent = true;
    stand_position = 4;
    pix = new QPixmap(":/images/CardImage/Monsters/Harpy_Egg.png");
    show_front = true;
    back = new QPixmap(":/images/Widgets/Card_Back.png");
    description= QObject::tr("被1张怪兽单位牌吸收战力时，使吸收者额外获得+5的战力，本牌被移至墓场时，将被直接放逐。\r\r遗愿：生成鹰身女妖幼崽。");
    card_name = QObject::tr("鹰身女妖蛋");
}

QRectF Harpy_Egg::boundingRect() const
{
    qreal penWidth = 1;
    return QRectF (0 - penWidth,0-penWidth,PixmapWidth + penWidth,PixmapHeight + penWidth);
}

void Harpy_Egg::set_alternatives()
{}
int Harpy_Egg::eaten_strength()
{
      if (the_logic->turn_card->race == 2)
        return strength +5 ;
      else
        return strength;
}

void Harpy_Egg::before_turncard_effect()
{}


void Harpy_Egg::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{

    if (show_front)
        painter-> drawPixmap(0,0,PixmapWidth,PixmapHeight,*pix);
    else
        painter-> drawPixmap(0,0,PixmapWidth,PixmapHeight,*back);
}

void Harpy_Egg::card_effect()
{}

void Harpy_Egg:: card_library_effect ()
{}

void Harpy_Egg:: card_hand_effect ()
{}

void Harpy_Egg::card_turn_end_effect ()
{}

void Harpy_Egg::card_death_effect ()
{
    Harpy_Cub *hc = new Harpy_Cub;
    hc->the_logic = the_logic;
    if (the_logic->order)
    {
        switch(stand_row)
        {
        case 1:
                the_logic->row_1_A.push_back(hc);
                break;
        case 2:
                the_logic->row_2_A.push_back(hc);
                break;
        case 3:
                the_logic->row_3_A.push_back(hc);
                break;
        }
    }
    else
    {
        switch(stand_row)
        {
        case 1:
                the_logic->row_1_B.push_back(hc);
                break;
        case 2:
                the_logic->row_2_B.push_back(hc);
                break;
        case 3:
                the_logic->row_3_B.push_back(hc);
                break;
        }
    }


}

void Harpy_Egg::card_round_end_effect ()
{}

void Harpy_Egg::card_in_tomb_effect ()
{}

void Harpy_Egg::card_lord_effect ()
{}

void Harpy_Egg::card_turn_begin_effect ()
{}

//Harpy_Cub

Harpy_Cub::Harpy_Cub()
{
    ID = 32;
    total_object_id++;is_lord = false;loyality = true;race = 0;shield = false;
    object_id = total_object_id;can_revive = true;
    strength = 1;
    armor = 0;
    party = 2;
    quality = 1;
    lock =  false;


    the_chosen = NULL;
    hurt = 0;
    is_weather = false;
    is_selecting = false;
    is_put_another = false;

    is_choosing_enemy = -1;            // -1: no choose,0:enemy; 1:friend;2:all
    is_choosing_row = -1;               // -1:no choose,0:enemy;1 friend;2 all
    is_attendent = true;
    stand_position = 4;
    pix = new QPixmap(":/images/CardImage/Monsters/Harpy_Cub.png");
    show_front = true;
    back = new QPixmap(":/images/Widgets/Card_Back.png");
    description.clear();
    card_name = QObject::tr("鹰身女妖幼崽");
}

QRectF Harpy_Cub::boundingRect() const
{
    qreal penWidth = 1;
    return QRectF (0 - penWidth,0-penWidth,PixmapWidth + penWidth,PixmapHeight + penWidth);
}

int Harpy_Cub::eaten_strength()
{
     return strength;
}

void Harpy_Cub::before_turncard_effect()
{}

void Harpy_Cub::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{

    if (show_front)
        painter-> drawPixmap(0,0,PixmapWidth,PixmapHeight,*pix);
    else
        painter-> drawPixmap(0,0,PixmapWidth,PixmapHeight,*back);
}
void Harpy_Cub::card_effect()
{}

void Harpy_Cub::set_alternatives()
{}

void Harpy_Cub:: card_library_effect ()
{}

void Harpy_Cub:: card_hand_effect ()
{}

void Harpy_Cub::card_turn_end_effect ()
{}

void Harpy_Cub::card_death_effect ()
{}

void Harpy_Cub::card_round_end_effect ()
{}

void Harpy_Cub::card_in_tomb_effect ()
{}

void Harpy_Cub::card_lord_effect ()
{}

void Harpy_Cub::card_turn_begin_effect ()
{}

//Arachas_Larva

Arachas_Larva::Arachas_Larva()
{
    ID = 33;
    total_object_id++;is_lord = false;loyality = true;race = 0;shield = false;
    object_id = total_object_id;can_revive = true;
    strength = 3;
    armor = 0;
    party = 2;
    quality = 1;
    lock =  false;

    the_chosen = NULL;
    hurt = 0;
    is_weather = false;
    is_selecting = false;
    is_put_another = false;

    is_choosing_enemy = -1;            // -1: no choose,0:enemy; 1:friend;2:all
    is_choosing_row = -1;               // -1:no choose,0:enemy;1 friend;2 all
    is_attendent = true;
    stand_position = 4;
    pix = new QPixmap(":/images/CardImage/Monsters/Arachas_Larva.png");
    show_front = true;
    back = new QPixmap(":/images/Widgets/Card_Back.png");
    description.clear();
    card_name = QObject::tr("蟹蜘蛛幼崽");
}

QRectF Arachas_Larva::boundingRect() const
{
    qreal penWidth = 1;
    return QRectF (0 - penWidth,0-penWidth,PixmapWidth + penWidth,PixmapHeight + penWidth);
}

void Arachas_Larva::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{

    if (show_front)
        painter-> drawPixmap(0,0,PixmapWidth,PixmapHeight,*pix);
    else
        painter-> drawPixmap(0,0,PixmapWidth,PixmapHeight,*back);
}
void Arachas_Larva::card_effect()
{}

int Arachas_Larva::eaten_strength()
{
     return strength;
}

void Arachas_Larva::before_turncard_effect()
{}


void Arachas_Larva::set_alternatives()
{}

void Arachas_Larva:: card_library_effect ()
{}

void Arachas_Larva:: card_hand_effect ()
{}

void Arachas_Larva::card_turn_end_effect ()
{}

void Arachas_Larva::card_death_effect ()
{}

void Arachas_Larva::card_round_end_effect ()
{}

void Arachas_Larva::card_in_tomb_effect ()
{}

void Arachas_Larva::card_lord_effect ()
{}

void Arachas_Larva::card_turn_begin_effect ()
{}

//Raging_Wolf

Raging_Wolf::Raging_Wolf()
{
    ID = 34;
    total_object_id++;is_lord = false;loyality = true;race = 0;shield = false;
    object_id = total_object_id;can_revive = true;
    strength = 1;
    armor = 0;
    party = 2;
    quality = 1;
    lock =  false;

    the_chosen = NULL;
    hurt = 0;
    is_weather = false;
    is_selecting = false;
    is_put_another = false;

    is_choosing_enemy = -1;            // -1: no choose,0:enemy; 1:friend;2:all
    is_choosing_row = -1;               // -1:no choose,0:enemy;1 friend;2 all
    is_attendent = true;
    stand_position = 4;
    pix = new QPixmap(":/images/CardImage/Monsters/Raging_Wolf.png");
    show_front = true;
    back = new QPixmap(":/images/Widgets/Card_Back.png");
    description.clear();
    card_name = QObject::tr("暴怒的狼");
}

QRectF Raging_Wolf::boundingRect() const
{
    qreal penWidth = 1;
    return QRectF (0 - penWidth,0-penWidth,PixmapWidth + penWidth,PixmapHeight + penWidth);
}

void Raging_Wolf::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{

    if (show_front)
        painter-> drawPixmap(0,0,PixmapWidth,PixmapHeight,*pix);
    else
        painter-> drawPixmap(0,0,PixmapWidth,PixmapHeight,*back);
}

int Raging_Wolf::eaten_strength()
{
     return strength;
}

void Raging_Wolf::before_turncard_effect()
{}

void Raging_Wolf::card_effect()
{}

void Raging_Wolf::set_alternatives()
{}

void Raging_Wolf:: card_library_effect ()
{}

void Raging_Wolf:: card_hand_effect ()
{}

void Raging_Wolf::card_turn_end_effect ()
{}

void Raging_Wolf::card_death_effect ()
{}

void Raging_Wolf::card_round_end_effect ()
{}

void Raging_Wolf::card_in_tomb_effect ()
{}

void Raging_Wolf::card_lord_effect ()
{}

void Raging_Wolf::card_turn_begin_effect ()
{}

//Roach
Roach::Roach()
{
    ID = 35;
    total_object_id++;is_lord = false;loyality = true;race = 0;shield = false;
    object_id = total_object_id;can_revive = true;
    strength = 1;
    armor = 0;
    party = 2;
    quality = 1;
    lock =  false;

    the_chosen = NULL;
    hurt = 0;
    is_weather = false;
    is_selecting = false;
    is_put_another = false;

    is_choosing_enemy = -1;            // -1: no choose,0:enemy; 1:friend;2:all
    is_choosing_row = -1;               // -1:no choose,0:enemy;1 friend;2 all
    is_attendent = true;
    stand_position = 4;
    pix = new QPixmap(":/images/CardImage/Monsters/Roach.png");
    show_front = true;
    back = new QPixmap(":/images/Widgets/Card_Back.png");
    description.clear();
    card_name = QObject::tr("萝卜");
    description = QObject::tr("己方每次从手牌打出金色牌时（领袖牌除外），便将牌组中的\"萝卜\"在其能力结算之前召唤至随机位置。");
}

QRectF Roach::boundingRect() const
{
    qreal penWidth = 1;
    return QRectF (0 - penWidth,0-penWidth,PixmapWidth + penWidth,PixmapHeight + penWidth);
}

void Roach::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{

    if (show_front)
        painter-> drawPixmap(0,0,PixmapWidth,PixmapHeight,*pix);
    else
        painter-> drawPixmap(0,0,PixmapWidth,PixmapHeight,*back);
}

int Roach::eaten_strength()
{
     return strength;
}

void Roach::before_turncard_effect()
{
    if (the_logic->turn_card->quality == 3 && !the_logic->turn_card->is_lord)
    {
        qsrand(QTime::currentTime().msec());
        int row = qrand() % 3;
        int size;

        if (the_logic->order)
        {
            the_logic->library_A.removeOne(this);
            switch(row)
            {
              case 0:
                     size  = the_logic->row_1_A.size();
                     if(size == 0) the_logic->row_1_A.push_back(this);
                     else the_logic->row_1_A.insert(qrand()%size,this);
                     break;
              case 1:
                   size  = the_logic->row_2_A.size();
                   if(size == 0) the_logic->row_2_A.push_back(this);
                   else the_logic->row_2_A.insert(qrand()%size,this);
                   break;
              case 2:
                   size  = the_logic->row_3_A.size();
                   if(size == 0) the_logic->row_3_A.push_back(this);
                   else the_logic->row_3_A.insert(qrand()%size,this);
                   break;
             }
        }
        else
        {
            the_logic->library_B.removeOne(this);
            switch(row)
            {
              case 0:
                     size  = the_logic->row_1_B.size();
                     if(size == 0) the_logic->row_1_B.push_back(this);
                     else the_logic->row_1_B.insert(qrand()%size,this);
                     break;
              case 1:
                   size  = the_logic->row_2_B.size();
                   if(size == 0) the_logic->row_2_B.push_back(this);
                   else the_logic->row_2_B.insert(qrand()%size,this);
                   break;
              case 2:
                   size  = the_logic->row_3_B.size();
                   if(size == 0) the_logic->row_3_B.push_back(this);
                   else the_logic->row_3_B.insert(qrand()%size,this);
                   break;
               }
            }
    }


}

void Roach::card_effect()
{}

void Roach::set_alternatives()
{}

void Roach:: card_library_effect ()
{}

void Roach:: card_hand_effect ()
{}

void Roach::card_turn_end_effect ()
{}

void Roach::card_death_effect ()
{}

void Roach::card_round_end_effect ()
{}

void Roach::card_in_tomb_effect ()
{}

void Roach::card_lord_effect ()
{}

void Roach::card_turn_begin_effect ()
{}



