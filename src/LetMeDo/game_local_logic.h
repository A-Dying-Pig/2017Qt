#ifndef LOGIC_H
#define LOGIC_H

#include <QObject>
#include <QList>
#include "card.h"
#include <QTimer>
#include <QMap>

class Game_Local_Logic: public QObject
{
    Q_OBJECT

public:
    Game_Local_Logic(QObject *parent = 0);

    QList<Card *>   hand_A;
    QList<Card *>   row_3_A;
    QList<Card *>   row_2_A;
    QList<Card *>   row_1_A;
    QList<Card *>   tomb_A;
    QList<Card *>   aLL_A;
    QList<Card *>   library_A;

    QList<Card *>   hand_B;
    QList<Card *>   row_3_B;
    QList<Card *>   row_2_B;
    QList<Card *>   row_1_B;
    QList<Card *>   tomb_B;
    QList<Card *>   aLL_B;
    QList<Card *>   library_B;

    QMap <QList<int> ,Card*> m_map1;
    QMap <Card*,QList<int>>m_map2;


    int step;   //for two sides choose card
    QTimer* game_start_timer;
    QTimer* one_second_timer;
    int time_past;
    Card* turn_card;    //本回合要打出的牌
    bool order; //true: A; false:B
    int stage;  //1:choosing enemy target;2:choosing friend target;3:choosing  target;4 choosing row;
    int have_selected;
    void turn_logic_run ();
    bool paint_side;

    //Round info
    int round;
    bool round_continue;
    int round_winner[3];       //round_winner[0] for 1st round; 1 for A, 0 for B, 3 For tie
    int game_winner;           //1 for A,0 for B,2 for tie
    bool A_stop_putting;
    bool B_stop_putting;

    //Strength info
    int A_total_strength;
    int A_row1_strength;
    int A_row2_strength;
    int A_row3_strength;
    int B_total_strength;
    int B_row1_strength;
    int B_row2_strength;
    int B_row3_strength;

    int A_strength_round[3];
    int B_strength_round[3];

    int friend_eaten_perturn;

    void strength_reset();
    void get_A_total_strength();
    void get_A_row1_strength();
    void get_A_row2_strength();
    void get_A_row3_strength();
    void get_B_total_strength();
    void get_B_row1_strength();
    void get_B_row2_strength();
    void get_B_row3_strength();

    void clear_death();
    void change_front();

signals:
    void TurnProcess();
    void TurnStart();
    void TurnChanged();
    void RoundEnd();
    void RoundStart();
    void PaintView();
    void UpdateStrength();
    void To_RoundEnd();
    void KeyPressedTimerStop();
    void RoundDrawCard();
    void RoundDrawCardViewUpdate();
    void ReceiveData();
    void ReceiveTurnInfo();
    void SendTurnInfo();
    void InitStrength();
    void SelectCard();
    void AddItem(Card * );
    void RemoveItem(Card *);


public slots:
    void turn_changed();
    void turn_process();
    void turn_time_up();
    void turn_start();
    void round_end();
    void round_start();
    void stop_putting();
    void round_draw_card();
    void turn_card_run();
};

#endif // LOGIC_H
