#ifndef CARDLIBRARY_H
#define CARDLIBRARY_H

#include "card.h"
#include "game_local_logic.h"

#define PixmapWidth 70
#define PixmapHeight 80

//NETRUAL
//Biting_Frost
class Biting_Frost:public Card
{

public:
    static int total_object_id;static bool has_switched;
    int object_id;
    int get_object_id (){return object_id;}

    Biting_Frost();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    Game_Local_Logic *the_logic;

    void card_library_effect () ;void card_has_switched(){has_switched = true;}
    void card_hand_effect () ;bool get_has_switched(){return has_switched;}
    void card_turn_begin_effect () ;
    void card_turn_end_effect ();
    void card_death_effect () ;
    void card_round_end_effect () ;
    void card_in_tomb_effect () ;
    void card_lord_effect () ;void before_turncard_effect ();int  eaten_strength();
    void card_effect(); void set_alternatives();
};


//First_Light
class First_Light:public Card
{

public:
    static int total_object_id;static bool has_switched;
    int object_id;
   int get_object_id (){return object_id;}

    First_Light();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    Game_Local_Logic *the_logic;

    void card_library_effect () ;void card_has_switched(){has_switched = true;}
    void card_hand_effect () ;bool get_has_switched(){return has_switched;}
    void card_turn_begin_effect () ;
    void card_turn_end_effect ();
    void card_death_effect () ;
    void card_round_end_effect () ;
    void card_in_tomb_effect () ;
    void card_lord_effect () ;void before_turncard_effect ();int  eaten_strength();
    void card_effect(); void set_alternatives();
};

//Impenetrable_Fog
class Impenetrable_Fog:public Card
{

public:
    static int total_object_id;static bool has_switched;
    int object_id;
    int get_object_id (){return object_id;}
    Impenetrable_Fog();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    Game_Local_Logic *the_logic;

    void card_library_effect () ;void card_has_switched(){has_switched = true;}
    void card_hand_effect () ;bool get_has_switched(){return has_switched;}
    void card_turn_begin_effect () ;
    void card_turn_end_effect ();
    void card_death_effect () ;
    void card_round_end_effect () ;
    void card_in_tomb_effect () ;
    void card_lord_effect () ;void before_turncard_effect ();int  eaten_strength();
    void card_effect();
    void set_alternatives();
};

//Torrential_Rain
class Torrential_Rain:public Card
{

public:
    static int total_object_id;static bool has_switched;
    int object_id;
   int get_object_id (){return object_id;}
    Torrential_Rain();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    Game_Local_Logic *the_logic;

    void card_library_effect () ;void card_has_switched(){has_switched = true;}
    void card_hand_effect () ;bool get_has_switched(){return has_switched;}
    void card_turn_begin_effect () ;
    void card_turn_end_effect ();
    void card_death_effect () ;
    void card_round_end_effect () ;
    void card_in_tomb_effect () ;
    void card_lord_effect () ;void before_turncard_effect ();int  eaten_strength();
    void card_effect(); void set_alternatives();
};

//Lacerate
class Lacerate:public Card
{

public:
    static int total_object_id;static bool has_switched;
    int object_id;
    int get_object_id (){return object_id;}
    Lacerate();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    Game_Local_Logic *the_logic;

    void card_library_effect () ;void card_has_switched(){has_switched = true;}
    void card_hand_effect () ;bool get_has_switched(){return has_switched;}
    void card_turn_begin_effect () ;
    void card_turn_end_effect ();
    void card_death_effect () ;
    void card_round_end_effect () ;
    void card_in_tomb_effect () ;
    void card_lord_effect () ;void before_turncard_effect ();int  eaten_strength();
    void card_effect(); void set_alternatives();
};

//Immune_Boost
class Immune_Boost:public Card
{

public:
    static int total_object_id;static bool has_switched;
    int object_id;
   int get_object_id (){return object_id;}
    Immune_Boost();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    Game_Local_Logic *the_logic;

    void card_library_effect () ;void card_has_switched(){has_switched = true;}
    void card_hand_effect () ;bool get_has_switched(){return has_switched;}
    void card_turn_begin_effect () ;
    void card_turn_end_effect ();
    void card_death_effect () ;
    void card_round_end_effect () ;
    void card_in_tomb_effect () ;
    void card_lord_effect () ;void before_turncard_effect ();int  eaten_strength();
    void card_effect(); void set_alternatives();
};

//Commanders_Horn
class Commanders_Horn:public Card
{

public:
    static int total_object_id;static bool has_switched;
    int object_id;
   int get_object_id (){return object_id;}
    Commanders_Horn();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    Game_Local_Logic *the_logic;

    void card_library_effect () ;void card_has_switched(){has_switched = true;}
    void card_hand_effect () ;bool get_has_switched(){return has_switched;}
    void card_turn_begin_effect () ;
    void card_turn_end_effect ();
    void card_death_effect () ;
    void card_round_end_effect () ;
    void card_in_tomb_effect () ;
    void card_lord_effect () ;void before_turncard_effect ();int  eaten_strength();
    void card_effect(); void set_alternatives();
};

//Bekkers_Twisted_Mirror
class Bekkers_Twisted_Mirror:public Card
{

public:
    static int total_object_id;static bool has_switched;
    int object_id;
   int get_object_id (){return object_id;}
    Bekkers_Twisted_Mirror();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    Game_Local_Logic *the_logic;

    void card_library_effect () ;void card_has_switched(){has_switched = true;}
    void card_hand_effect () ;bool get_has_switched(){return has_switched;}
    void card_turn_begin_effect () ;
    void card_turn_end_effect ();
    void card_death_effect () ;
    void card_round_end_effect () ;
    void card_in_tomb_effect () ;
    void card_lord_effect () ;void before_turncard_effect ();int  eaten_strength();
    void card_effect(); void set_alternatives();
};

//Geralt_Igni
class Geralt_Igni:public Card
{

public:
    static int total_object_id;static bool has_switched;
    int object_id;
   int get_object_id (){return object_id;}
    Geralt_Igni();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    Game_Local_Logic *the_logic;

    void card_library_effect () ;void card_has_switched(){has_switched = true;}
    void card_hand_effect () ;bool get_has_switched(){return has_switched;}
    void card_turn_begin_effect () ;
    void card_turn_end_effect ();
    void card_death_effect () ;
    void card_round_end_effect () ;
    void card_in_tomb_effect () ;
    void card_lord_effect () ;void before_turncard_effect ();int  eaten_strength();
    void card_effect(); void set_alternatives();
};

//MONSTERS
//Dagon
class Dagon:public Card
{

public:
    static int total_object_id;static bool has_switched;
    int object_id;
   int get_object_id (){return object_id;}
    Dagon();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    Game_Local_Logic *the_logic;

    void card_library_effect () ;void card_has_switched(){has_switched = true;}
    void card_hand_effect () ;bool get_has_switched(){return has_switched;}
    void card_turn_begin_effect () ;
    void card_turn_end_effect ();
    void card_death_effect () ;
    void card_round_end_effect () ;
    void card_in_tomb_effect () ;
    void card_lord_effect () ;void before_turncard_effect ();int  eaten_strength();
    void card_effect(); void set_alternatives();
};

//Foglet
class Foglet:public Card
{

public:
    static int total_object_id;static bool has_switched;
    int object_id;
    int get_object_id (){return object_id;}
    Foglet();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    Game_Local_Logic *the_logic;
    static bool put_out;
    static bool fog_exist;

    void card_library_effect () ;void card_has_switched(){has_switched = true;}
    void card_hand_effect () ;bool get_has_switched(){return has_switched;}
    void card_turn_begin_effect () ;
    void card_turn_end_effect ();
    void card_death_effect () ;
    void card_round_end_effect () ;
    void card_in_tomb_effect () ;
    void card_lord_effect () ;void before_turncard_effect ();int  eaten_strength();
    void card_effect(); void set_alternatives();
};

//Geels
class Geels:public Card
{
public:
    static int total_object_id;static bool has_switched;
    int object_id;
   int get_object_id (){return object_id;}
    Geels();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    Game_Local_Logic *the_logic;

    void card_library_effect () ;void card_has_switched(){has_switched = true;}
    void card_hand_effect () ;bool get_has_switched(){return has_switched;}
    void card_turn_begin_effect () ;
    void card_turn_end_effect ();
    void card_death_effect () ;
    void card_round_end_effect () ;
    void card_in_tomb_effect () ;
    void card_lord_effect () ;void before_turncard_effect ();int  eaten_strength();
    void card_effect(); void set_alternatives();
};

//Celaeno_Harpy
class Celaeno_Harpy:public Card
{

public:
    static int total_object_id;static bool has_switched;
    int object_id;
  int get_object_id (){return object_id;}
    Celaeno_Harpy();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    Game_Local_Logic *the_logic;

    void card_library_effect () ;void card_has_switched(){has_switched = true;}
    void card_hand_effect () ;bool get_has_switched(){return has_switched;}
    void card_turn_begin_effect () ;
    void card_turn_end_effect ();
    void card_death_effect () ;
    void card_round_end_effect () ;
    void card_in_tomb_effect () ;
    void card_lord_effect () ;void before_turncard_effect ();int  eaten_strength();
    void card_effect(); void set_alternatives();
};

//Harpy
class Harpy:public Card
{

public:
    static int total_object_id;static bool has_switched;
    int object_id;
int get_object_id (){return object_id;}
    Harpy();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    Game_Local_Logic *the_logic;

    void card_library_effect () ;void card_has_switched(){has_switched = true;}
    void card_hand_effect () ;bool get_has_switched(){return has_switched;}
    void card_turn_begin_effect () ;
    void card_turn_end_effect ();
    void card_death_effect () ;
    void card_round_end_effect () ;
    void card_in_tomb_effect () ;
    void card_lord_effect () ;void before_turncard_effect ();int  eaten_strength();
    void card_effect(); void set_alternatives();
};

//Woodland_Spirit
class Woodland_Spirit:public Card
{

public:
    static int total_object_id;static bool has_switched;
    int object_id;
  int get_object_id (){return object_id;}
    Woodland_Spirit();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    Game_Local_Logic *the_logic;

    void card_library_effect () ;void card_has_switched(){has_switched = true;}
    void card_hand_effect () ;bool get_has_switched(){return has_switched;}
    void card_turn_begin_effect () ;
    void card_turn_end_effect ();
    void card_death_effect () ;
    void card_round_end_effect () ;
    void card_in_tomb_effect () ;
    void card_lord_effect () ;void before_turncard_effect ();int  eaten_strength();
    void card_effect(); void set_alternatives();
};

//Earth_Elemental
class Earth_Elemental:public Card
{

public:
    static int total_object_id;static bool has_switched;
    int object_id;
  int get_object_id (){return object_id;}
    Earth_Elemental();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    Game_Local_Logic *the_logic;

    void card_library_effect () ;void card_has_switched(){has_switched = true;}
    void card_hand_effect () ;bool get_has_switched(){return has_switched;}
    void card_turn_begin_effect () ;
    void card_turn_end_effect ();
    void card_death_effect () ;
    void card_round_end_effect () ;
    void card_in_tomb_effect () ;
    void card_lord_effect () ;void before_turncard_effect ();int  eaten_strength();
    void card_effect(); void set_alternatives();
};

//Crone_Weavess
class Crone_Weavess:public Card
{

public:
    static int total_object_id;static bool has_switched;
    int object_id;
  int get_object_id (){return object_id;}
    Crone_Weavess();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    Game_Local_Logic *the_logic;

    void card_library_effect () ;void card_has_switched(){has_switched = true;}
    void card_hand_effect () ;bool get_has_switched(){return has_switched;}
    void card_turn_begin_effect () ;
    void card_turn_end_effect ();
    void card_death_effect () ;
    void card_round_end_effect () ;
    void card_in_tomb_effect () ;
    void card_lord_effect () ;void before_turncard_effect ();int  eaten_strength();
    void card_effect(); void set_alternatives();
};

//Crone_Whispess
class Crone_Whispess:public Card
{

public:
    static int total_object_id;static bool has_switched;
    int object_id;
  int get_object_id (){return object_id;}
    Crone_Whispess();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    Game_Local_Logic *the_logic;

    void card_library_effect () ;void card_has_switched(){has_switched = true;}
    void card_hand_effect () ;bool get_has_switched(){return has_switched;}
    void card_turn_begin_effect () ;
    void card_turn_end_effect ();
    void card_death_effect () ;
    void card_round_end_effect () ;
    void card_in_tomb_effect () ;
    void card_lord_effect () ;void before_turncard_effect ();int  eaten_strength();
    void card_effect(); void set_alternatives();
};

//Crone_Brewess
class Crone_Brewess:public Card
{

public:
    static int total_object_id;static bool has_switched;
    int object_id;
  int get_object_id (){return object_id;}
    Crone_Brewess();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    Game_Local_Logic *the_logic;

    void card_library_effect () ;void card_has_switched(){has_switched = true;}
    void card_hand_effect () ;bool get_has_switched(){return has_switched;}
    void card_turn_begin_effect () ;
    void card_turn_end_effect ();
    void card_death_effect () ;
    void card_round_end_effect () ;
    void card_in_tomb_effect () ;
    void card_lord_effect () ;void before_turncard_effect ();int  eaten_strength();
    void card_effect(); void set_alternatives();
};

//Archgriffin
class Archgriffin:public Card
{

public:
    static int total_object_id;static bool has_switched;
    int object_id;
  int get_object_id (){return object_id;}
    Archgriffin();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *widget);
    Game_Local_Logic *the_logic;

    void card_library_effect () ;void card_has_switched(){has_switched = true;}
    void card_hand_effect () ;bool get_has_switched(){return has_switched;}
    void card_turn_begin_effect () ;
    void card_turn_end_effect ();
    void card_death_effect () ;
    void card_round_end_effect () ;
    void card_in_tomb_effect () ;
    void card_lord_effect () ;void before_turncard_effect ();int  eaten_strength();
    void card_effect(); void set_alternatives();
};

//Wild_Hunt_Rider
class Wild_Hunt_Rider:public Card
{

public:
    static int total_object_id;static bool has_switched;
    int object_id;
 int get_object_id (){return object_id;}
    Wild_Hunt_Rider();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    Game_Local_Logic *the_logic;

    void card_library_effect () ;void card_has_switched(){has_switched = true;}
    void card_hand_effect () ;bool get_has_switched(){return has_switched;}
    void card_turn_begin_effect () ;
    void card_turn_end_effect ();
    void card_death_effect () ;
    void card_round_end_effect () ;
    void card_in_tomb_effect () ;
    void card_lord_effect () ;void before_turncard_effect ();int  eaten_strength();
    void card_effect(); void set_alternatives();
};

//Caranthir
class Caranthir:public Card
{

public:
    static int total_object_id;static bool has_switched;
    int object_id;
 int get_object_id (){return object_id;}
    Caranthir();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    Game_Local_Logic *the_logic;

    void card_library_effect () ;void card_has_switched(){has_switched = true;}
    void card_hand_effect () ;bool get_has_switched(){return has_switched;}
    void card_turn_begin_effect () ;
    void card_turn_end_effect ();
    void card_death_effect () ;
    void card_round_end_effect () ;
    void card_in_tomb_effect () ;
    void card_lord_effect () ;void before_turncard_effect ();int  eaten_strength();
    void card_effect(); void set_alternatives();
};

//Frightener
class Frightener:public Card
{

public:
    static int total_object_id;static bool has_switched;
    int object_id;
  int get_object_id (){return object_id;}
    Frightener();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    Game_Local_Logic *the_logic;

    void card_library_effect () ;void card_has_switched(){has_switched = true;}
    void card_hand_effect () ;bool get_has_switched(){return has_switched;}
    void card_turn_begin_effect () ;
    void card_turn_end_effect ();
    void card_death_effect () ;
    void card_round_end_effect () ;
    void card_in_tomb_effect () ;
    void card_lord_effect () ;void before_turncard_effect ();int  eaten_strength();
    void card_effect(); void set_alternatives();
};

//Unseen_Elder
class Unseen_Elder:public Card
{

public:
    static int total_object_id;static bool has_switched;
    int object_id;
   int get_object_id (){return object_id;}
    Unseen_Elder();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    Game_Local_Logic *the_logic;

    void card_library_effect () ;void card_has_switched(){has_switched = true;}
    void card_hand_effect () ;bool get_has_switched(){return has_switched;}
    void card_turn_begin_effect () ;
    void card_turn_end_effect ();
    void card_death_effect () ;
    void card_round_end_effect () ;
    void card_in_tomb_effect () ;
    void card_lord_effect () ;void before_turncard_effect ();int  eaten_strength();
    void card_effect(); void set_alternatives();
};

//Arachas
class Arachas:public Card
{

public:
    static int total_object_id;static bool has_switched;
    int object_id;
    int get_object_id (){return object_id;}
    Arachas();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    Game_Local_Logic *the_logic;

    void card_library_effect () ;void card_has_switched(){has_switched = true;}
    void card_hand_effect () ;bool get_has_switched(){return has_switched;}
    void card_turn_begin_effect () ;
    void card_turn_end_effect ();
    void card_death_effect () ;
    void card_round_end_effect () ;
    void card_in_tomb_effect () ;
    void card_lord_effect () ;void before_turncard_effect ();int  eaten_strength();
    void card_effect(); void set_alternatives();
};

//Arachas_Behemoth
class Arachas_Behemoth:public Card
{

public:
    static int total_object_id;static bool has_switched;
    int object_id;
   int get_object_id (){return object_id;}
    Arachas_Behemoth();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    Game_Local_Logic *the_logic;

    void card_library_effect () ;void card_has_switched(){has_switched = true;}
    void card_hand_effect () ;bool get_has_switched(){return has_switched;}
    void card_turn_begin_effect () ;
    void card_turn_end_effect ();
    void card_death_effect () ;
    void card_round_end_effect () ;
    void card_in_tomb_effect () ;
    void card_lord_effect () ;void before_turncard_effect ();int  eaten_strength();
    void card_effect(); void set_alternatives();
};

//Vran_Warrior
class Vran_Warrior:public Card
{

public:
    static int total_object_id;static bool has_switched;
    int object_id;
    int round_count;
 int get_object_id (){return object_id;}
    Vran_Warrior();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    Game_Local_Logic *the_logic;

    void card_library_effect () ;void card_has_switched(){has_switched = true;}
    void card_hand_effect () ;bool get_has_switched(){return has_switched;}
    void card_turn_begin_effect () ;
    void card_turn_end_effect ();
    void card_death_effect () ;
    void card_round_end_effect () ;
    void card_in_tomb_effect () ;
    void card_lord_effect () ;void before_turncard_effect ();int  eaten_strength();
    void card_effect(); void set_alternatives();
};


//Sunny_Day
class Sunny_Day:public Card
{

public:
    static int total_object_id;static bool has_switched;
    int object_id;
   int get_object_id (){return object_id;}
    Sunny_Day();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    Game_Local_Logic *the_logic;

    void card_library_effect () ;void card_has_switched(){has_switched = true;}
    void card_hand_effect () ;bool get_has_switched(){return has_switched;}
    void card_turn_begin_effect () ;
    void card_turn_end_effect ();
    void card_death_effect () ;
    void card_round_end_effect () ;
    void card_in_tomb_effect () ;
    void card_lord_effect () ;void before_turncard_effect ();int  eaten_strength();
    void card_effect(); void set_alternatives();
};

//Restart
class Restart:public Card
{

public:
    static int total_object_id;static bool has_switched;
    int object_id;
   int get_object_id (){return object_id;}
    Restart();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    Game_Local_Logic *the_logic;

    void card_library_effect () ;void card_has_switched(){has_switched = true;}
    void card_hand_effect () ;bool get_has_switched(){return has_switched;}
    void card_turn_begin_effect () ;
    void card_turn_end_effect ();
    void card_death_effect () ;
    void card_round_end_effect () ;
    void card_in_tomb_effect () ;
    void card_lord_effect () ;void before_turncard_effect ();int  eaten_strength();
    void card_effect(); void set_alternatives();
};

//Lesser_Earth
class Lesser_Earth:public Card
{

public:
    static int total_object_id;static bool has_switched;
    int object_id;
    int get_object_id (){return object_id;}
    Lesser_Earth();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    Game_Local_Logic *the_logic;

    void card_library_effect () ;void card_has_switched(){has_switched = true;}
    void card_hand_effect () ;bool get_has_switched(){return has_switched;}
    void card_turn_begin_effect () ;
    void card_turn_end_effect ();
    void card_death_effect () ;
    void card_round_end_effect () ;
    void card_in_tomb_effect () ;
    void card_lord_effect () ;void before_turncard_effect ();int  eaten_strength();
    void card_effect(); void set_alternatives();
};

//Raging_Wolf
class Raging_Wolf:public Card
{

public:
    static int total_object_id;static bool has_switched;
    int object_id;
    int get_object_id (){return object_id;}
    Raging_Wolf();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    Game_Local_Logic *the_logic;

    void card_library_effect () ;void card_has_switched(){has_switched = true;}
    void card_hand_effect () ;bool get_has_switched(){return has_switched;}
    void card_turn_begin_effect () ;
    void card_turn_end_effect ();
    void card_death_effect () ;
    void card_round_end_effect () ;
    void card_in_tomb_effect () ;
    void card_lord_effect () ;void before_turncard_effect ();int  eaten_strength();
    void card_effect(); void set_alternatives();
};

//Arachas_Larva
class Arachas_Larva:public Card
{

public:
    static int total_object_id;static bool has_switched;
    int object_id;
 int get_object_id (){return object_id;}
    Arachas_Larva();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    Game_Local_Logic *the_logic;

    void card_library_effect () ;void card_has_switched(){has_switched = true;}
    void card_hand_effect () ;bool get_has_switched(){return has_switched;}
    void card_turn_begin_effect () ;
    void card_turn_end_effect ();
    void card_death_effect () ;
    void card_round_end_effect () ;
    void card_in_tomb_effect () ;
    void card_lord_effect () ;void before_turncard_effect ();int  eaten_strength();
    void card_effect(); void set_alternatives();
};

//Harpy_Egg
class Harpy_Egg:public Card
{

public:
    static int total_object_id;static bool has_switched;
    int object_id;
   int get_object_id (){return object_id;}
    Harpy_Egg();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    Game_Local_Logic *the_logic;

    void card_library_effect () ;void card_has_switched(){has_switched = true;}
    void card_hand_effect () ;bool get_has_switched(){return has_switched;}
    void card_turn_begin_effect () ;
    void card_turn_end_effect ();
    void card_death_effect () ;
    void card_round_end_effect () ;
    void card_in_tomb_effect () ;
    void card_lord_effect () ;void before_turncard_effect ();int  eaten_strength();
    void card_effect(); void set_alternatives();
};

//Harpy_Cub
class Harpy_Cub:public Card
{

public:
    static int total_object_id;static bool has_switched;
    int object_id;
  int get_object_id (){return object_id;}
    Harpy_Cub();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    Game_Local_Logic *the_logic;

    void card_library_effect () ;void card_has_switched(){has_switched = true;}
    void card_hand_effect () ;bool get_has_switched(){return has_switched;}
    void card_turn_begin_effect () ;
    void card_turn_end_effect ();
    void card_death_effect () ;
    void card_round_end_effect () ;
    void card_in_tomb_effect () ;
    void card_lord_effect () ;void before_turncard_effect ();int  eaten_strength();
    void card_effect(); void set_alternatives();
};

//Roach
class Roach:public Card
{
public:
    static int total_object_id;static bool has_switched;
    int object_id;
    int get_object_id (){return object_id;}
    Roach();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    Game_Local_Logic *the_logic;

    void card_library_effect () ;void card_has_switched(){has_switched = true;}
    void card_hand_effect () ;bool get_has_switched(){return has_switched;}
    void card_turn_begin_effect () ;
    void card_turn_end_effect ();
    void card_death_effect () ;
    void card_round_end_effect () ;
    void card_in_tomb_effect () ;
    void card_lord_effect () ;void before_turncard_effect ();int  eaten_strength();
    void card_effect();
    void set_alternatives();
};

#endif // CARDLIBRARY_H

