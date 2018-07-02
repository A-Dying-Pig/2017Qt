#ifndef CARD_H
#define CARD_H

#include <QGraphicsItem>


class Card:public QGraphicsItem
{

public:
    Card();

public:
    int ID;
// Card Property
    int strength;
    int armor;
    bool shield;
    int hurt;

    bool can_revive;
    bool is_attendent;                  //false NOT,true YES
    bool is_weather;
    int stand_row;                      //for all stand attendent
    bool is_put_another;
    bool is_selecting;
    QList<Card *> alternative;
    Card * the_chosen;

    bool is_active;
    bool is_lord;

    unsigned int party;                 //1 for NEUTRAL
    unsigned int quality;               //1 for BRONZE,2 for SILVER, 3 for GOLD
    bool lock;                          //false for UNLOCKED, true for LOCKED
    QString description;
    QString card_name;
    bool loyality;
    int stand_position;                 //1,2,3;4:all
    int race;                          //2 for monsters
    QPixmap *pix;
    QPixmap *back;
    bool show_front;
    //int
    static int same_name_num;

//  Variables For Effect
    int is_choosing_enemy;            // -1: no choose,0:enemy; 1:friend;2:all
    QList<Card*> target;
    int select_num;

    int is_choosing_row;            //-1:no choose;0 enemy;1 friend;2 all
    int effect_row;                 //enemy:  3 2 1 4 5 6


//effect
   virtual void before_turncard_effect () = 0;
   virtual int  eaten_strength() = 0;

   virtual void set_alternatives() = 0;
   virtual void card_effect() = 0;
   virtual void card_library_effect () =0 ;
   virtual void card_hand_effect () =0;
   virtual void card_turn_begin_effect () =0;
   virtual void card_turn_end_effect () =0;
   virtual void card_death_effect () =0;
   virtual void card_in_tomb_effect () =0;
   virtual void card_lord_effect () =0;

   virtual void card_has_switched() = 0;
   virtual bool get_has_switched() = 0;

    //id
    virtual int get_object_id() = 0;
};

#endif // CARD_H
