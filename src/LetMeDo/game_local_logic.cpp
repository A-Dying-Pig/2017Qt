#include "game_local_logic.h"
#include "cardlibrary.h"
#include <QObject>
#define TurnInterval 30000

Game_Local_Logic::Game_Local_Logic(QObject *parent):
    QObject(parent)
{
    step = 0;
    paint_side = true;
    order = true;
    //round_info
    round = 0;
    round_continue = true;
    //initialize
    game_start_timer = new QTimer(this);
    one_second_timer = new QTimer(this);
    one_second_timer ->setInterval(1000);
    game_start_timer ->setInterval(TurnInterval);

    connect(game_start_timer,SIGNAL(timeout()),this,SLOT(turn_time_up()));
    connect(this,SIGNAL(TurnStart()),this,SLOT(turn_start()));
    connect(this,SIGNAL(TurnChanged()),this,SLOT(turn_changed()));
    connect(this,SIGNAL(RoundEnd()),this,SLOT(round_end()));
    connect(this,SIGNAL(RoundStart()),this,SLOT(round_start()));
    connect(this,SIGNAL(TurnProcess()),this,SLOT(turn_process()));
}

void Game_Local_Logic::round_start()
{
    foreach(Card *i,row_1_A)
        tomb_A.push_back(i);
    foreach(Card *i,row_2_A)
        tomb_A.push_back(i);
    foreach(Card *i,row_3_A)
        tomb_A.push_back(i);

    foreach(Card *i,row_1_B)
        tomb_A.push_back(i);
    foreach(Card *i,row_2_B)
        tomb_A.push_back(i);
    foreach(Card *i,row_3_B)
        tomb_A.push_back(i);

    row_1_A.clear();
    row_2_A.clear();
    row_3_A.clear();
    row_1_B.clear();
    row_2_B.clear();
    row_3_B.clear();

    A_total_strength = 0;
    A_row1_strength = 0;
    A_row2_strength = 0;
    A_row3_strength = 0;
    B_total_strength = 0;
    B_row1_strength = 0;
    B_row2_strength = 0;
    B_row3_strength = 0;

    A_stop_putting = false;
    B_stop_putting = false;
    round++;
    stage = -2;
    //在此添加顺序
    order = true;

    emit PaintView();
    emit TurnStart();
}

void Game_Local_Logic::round_end()
{
   if (A_total_strength > B_total_strength)
       round_winner[round-1] = 1;
   else if (A_total_strength < B_total_strength)
       round_winner[round-1] = 0;
   else
       round_winner[round-1] = 3;

    A_strength_round[round-1]  =  A_total_strength;
    B_strength_round[round-1]  =  B_total_strength;

    if (round == 1)
       ;
    else if (round == 2)
    {
        int sum = round_winner[0] + round_winner[1];
        if ( sum == 0)
        {
            game_winner = 0;
            round_continue = false;
        }
        else if ( sum == 2)
        {
            game_winner = 1;
            round_continue = false;
        }
        else if ( sum == 4)
        {
            game_winner = 1;
            round_continue = false;
        }
        else if (sum == 3)
        {
            game_winner = 0;
            round_continue = false;
        }
        else if (sum == 6)
        {
            game_winner = 2;
            round_continue = false;
        }
    }
    else if (round == 3)
    {
        round_continue = false;
        int sum = round_winner[0] + round_winner[1] + round_winner[2];
        if (sum == 1 )
            game_winner = 0;
        else if (sum == 2 )
            game_winner = 1;
        else if (sum == 4)
            game_winner = 2;
    }
    step = 2;

    foreach (Card* i ,hand_A)
        i->show_front = true;
    foreach (Card* i ,hand_B)
        i->show_front = true;
    emit To_RoundEnd();
}


void Game_Local_Logic::turn_card_run()
{
    if (order)
    {
        foreach (Card *i, library_A)
           i->before_turncard_effect();
        turn_card->card_effect();
        clear_death();
    }
    else
    {
        foreach (Card *i, library_B)
           i->before_turncard_effect();
        turn_card->card_effect();
        clear_death();
    }
    if (stage == -2)
    {
        turn_card->card_effect();
        if (order)
            hand_A.removeOne(turn_card);
        else
            hand_B.removeOne(turn_card);
        emit TurnChanged();
    }
}


void Game_Local_Logic::turn_process()
{
    if (turn_card->is_selecting && turn_card->the_chosen == NULL)
    {
        turn_card->set_alternatives();
        if (turn_card->alternative.isEmpty())
        {
            turn_card->card_effect();
            emit TurnChanged();
        }
        else
            emit SelectCard();
    }
    else if (turn_card->is_selecting && turn_card->the_chosen != NULL)
    {

             if (turn_card->is_put_another)
            {
                emit AddItem(turn_card->the_chosen);

                 if (order)
                 {
                     hand_A.push_back(turn_card->the_chosen);
                     foreach (Card *i, library_A)
                        i->before_turncard_effect();
                 }
                 else
                 {
                     hand_B.push_back(turn_card->the_chosen);
                     foreach (Card *i, library_B)
                        i->before_turncard_effect();
                 }

                turn_card->card_effect();
                turn_card = turn_card->the_chosen;

            if (turn_card->is_attendent)
                 stage = 1;
            else
                 stage = 2;
             }
            else
            {
                turn_card->card_effect();
                emit TurnChanged();
            }
    }
    else
    {   
        if (order)
            foreach (Card *i, library_A)
               i->before_turncard_effect();
        else
            foreach (Card *i, library_B)
               i->before_turncard_effect();
        turn_card->card_effect();
        emit TurnChanged();
    }

}

void Game_Local_Logic::turn_changed()
{
    game_start_timer ->stop();
    one_second_timer ->stop();

    turn_logic_run();

    clear_death();
    strength_reset();
    get_A_row1_strength();
    get_A_row2_strength();
    get_A_row3_strength();
    get_A_total_strength();
    get_B_row1_strength();
    get_B_row2_strength();
    get_B_row3_strength();
    get_B_total_strength();
    //paintEvent

    emit UpdateStrength();
    emit PaintView();
    if (A_stop_putting&&B_stop_putting)
        emit RoundEnd();
    else
    {
        order = !order;
        emit TurnStart();
    }

    QList<int> p;
    p.push_back(0);
    p.push_back(0);
    m_map1.insert(p,NULL);
    m_map2.insert(NULL,p);
}

void Game_Local_Logic::turn_time_up()
{
    turn_card = NULL;
    //惩罚函数


    //
    turn_changed();
}

void Game_Local_Logic::turn_logic_run()
{
    if (order)
    {
         foreach (Card* i,hand_A)
             i->card_hand_effect();

         foreach(Card* i,library_A)
             i->card_library_effect();

         foreach(Card* i,tomb_A)
             i->card_in_tomb_effect();

         foreach (Card* i,row_1_A)
             i->card_turn_end_effect();
         foreach (Card* i,row_2_A)
             i->card_turn_end_effect();
         foreach (Card* i,row_3_A)
             i->card_turn_end_effect();
     }
    else
    {
        foreach (Card* i,hand_B)
            i->card_hand_effect();

        foreach(Card* i,library_B)
            i->card_library_effect();

        foreach(Card* i,tomb_B)
            i->card_in_tomb_effect();

        foreach ( Card* i,row_1_B)
            i->card_turn_end_effect();
        foreach (Card* i,row_2_B)
            i->card_turn_end_effect();
        foreach ( Card* i,row_3_B)
            i->card_turn_end_effect();
    }

}

void Game_Local_Logic::stop_putting()
{
    if (order)
    {
        stage = -2;
        A_stop_putting  = true;
    }
    else
    {
        stage = -2;
        B_stop_putting  = true;
    }

    emit KeyPressedTimerStop();
    turn_card = NULL;
    emit TurnChanged();
}

void Game_Local_Logic::turn_start()
{
    game_start_timer->start();
    one_second_timer->start();
    time_past = 0;
    friend_eaten_perturn = 0;
    have_selected = 0;

    stage = -2;
    change_front();

         if (order)
      {
        foreach ( Card* i,row_1_A)
            if (!i->is_weather)
                i->card_turn_begin_effect();
        foreach (Card* i,row_2_A)
            if (!i->is_weather)
                i->card_turn_begin_effect();
        foreach ( Card* i,row_3_A)
            if (!i->is_weather)
                i->card_turn_begin_effect();
        foreach ( Card* i,row_1_B)
            if (i->is_weather)
                i->card_turn_begin_effect();
        foreach (Card* i,row_2_B)
            if (i->is_weather)
                i->card_turn_begin_effect();
        foreach ( Card* i,row_3_B)
            if (i->is_weather)
                i->card_turn_begin_effect();

        clear_death();

        strength_reset();
        get_A_row1_strength();
        get_A_row2_strength();
        get_A_row3_strength();
        get_A_total_strength();
        get_B_row1_strength();
        get_B_row2_strength();
        get_B_row3_strength();
        get_B_total_strength();
        emit UpdateStrength();

        emit PaintView();
        if (A_stop_putting)
            emit turn_changed();
        else if (hand_A.isEmpty())
            stop_putting();
        else if (!hand_A.isEmpty())
            stage = 0;
    }

    else
    {
        foreach ( Card* i,row_1_B)
            if(!i->is_weather)
                i->card_turn_begin_effect();
        foreach (Card* i,row_2_B)
            if(!i->is_weather)
                i->card_turn_begin_effect();
        foreach ( Card* i,row_3_B)
            if(!i->is_weather)
                i->card_turn_begin_effect();
        foreach ( Card* i,row_1_A)
            if(i->is_weather)
                i->card_turn_begin_effect();
        foreach (Card* i,row_2_A)
            if(i->is_weather)
                i->card_turn_begin_effect();
        foreach ( Card* i,row_3_A)
            if(i->is_weather)
                i->card_turn_begin_effect();

        clear_death();

        strength_reset();
        get_A_row1_strength();
        get_A_row2_strength();
        get_A_row3_strength();
        get_A_total_strength();
        get_B_row1_strength();
        get_B_row2_strength();
        get_B_row3_strength();
        get_B_total_strength();
        emit UpdateStrength();

        emit PaintView();

        //emit ReceiveTurnInfo();

        if (B_stop_putting)
            emit turn_changed();
        else if (hand_B.isEmpty())
            stop_putting();
        else if (!hand_B.isEmpty())
            stage = 0;
    }

}


void Game_Local_Logic::get_A_row1_strength()
{
    foreach ( Card* i,row_1_A)
       if (i->is_attendent)
           A_row1_strength += i->strength;
}

void Game_Local_Logic::get_A_row2_strength()
{
    foreach ( Card* i,row_2_A)
       if (i->is_attendent)
           A_row2_strength += i->strength;
}

void Game_Local_Logic::get_A_row3_strength()
{
    foreach ( Card* i,row_3_A)
       if (i->is_attendent)
           A_row3_strength += i->strength;
}

void Game_Local_Logic::get_A_total_strength()
{
    A_total_strength = A_row1_strength+A_row2_strength+A_row3_strength;
}

void Game_Local_Logic::get_B_row1_strength()
{
    foreach ( Card* i,row_1_B)
       if (i->is_attendent)
           B_row1_strength += i->strength;
}

void Game_Local_Logic::get_B_row2_strength()
{
    foreach ( Card* i,row_2_B)
       if (i->is_attendent)
           B_row2_strength += i->strength;
}

void Game_Local_Logic::get_B_row3_strength()
{
    foreach ( Card* i,row_3_B)
       if (i->is_attendent)
           B_row3_strength += i->strength;
}

void Game_Local_Logic::get_B_total_strength()
{
    B_total_strength = B_row1_strength + B_row2_strength + B_row3_strength;
}

void Game_Local_Logic::strength_reset()
{
    A_total_strength = 0;
    A_row1_strength = 0;
    A_row2_strength = 0;
    A_row3_strength = 0;
    B_total_strength = 0;
    B_row1_strength = 0;
    B_row2_strength = 0;
    B_row3_strength = 0;
}

void Game_Local_Logic::round_draw_card()
{
        if (round == 1)
        {
            hand_A.push_back(library_A[0]);
            hand_A.push_back(library_A[1]);
            library_A.removeFirst();
            library_A.removeFirst();
            hand_B.push_back(library_B[0]);
            hand_B.push_back(library_B[1]);
            library_B.removeFirst();
            library_B.removeFirst();
        }
        else if (round == 2)
        {
            hand_A.push_back(library_A[0]);
            library_A.removeFirst();
            hand_B.push_back(library_B[0]);
            library_B.removeFirst();
        }

    emit RoundDrawCardViewUpdate();
}

void Game_Local_Logic::clear_death()
{
    foreach (Card *i,row_1_A)
        if(i->strength <= 0 && i->is_attendent)
          {
            row_1_A.removeOne(i);
            i->card_death_effect();
            emit RemoveItem(i);
            if (i->can_revive)
                tomb_A.push_back(i);
          }
    foreach (Card *i,row_2_A)
        if(i->strength <= 0 && i->is_attendent)
          {
            row_2_A.removeOne(i);
            i->card_death_effect();
            emit RemoveItem(i);
            if (i->can_revive)
                tomb_A.push_back(i);
          }
    foreach (Card *i,row_3_A)
        if(i->strength <= 0 && i->is_attendent)
          {
            row_3_A.removeOne(i);
            i->card_death_effect();
            emit RemoveItem(i);
            if (i->can_revive)
                tomb_A.push_back(i);
          }
    foreach (Card *i,row_1_B)
        if(i->strength <= 0 && i->is_attendent)
          {
            row_1_B.removeOne(i);
            i->card_death_effect();
            emit RemoveItem(i);
            if (i->can_revive)
                tomb_B.push_back(i);
          }
    foreach (Card *i,row_2_B)
        if(i->strength <= 0 && i->is_attendent)
          {
            row_2_B.removeOne(i);
            i->card_death_effect();
            emit RemoveItem(i);
            if (i->can_revive)
                tomb_B.push_back(i);
          }
    foreach (Card *i,row_3_B)
        if(i->strength <= 0 && i->is_attendent)
          {
            row_3_B.removeOne(i);
            i->card_death_effect();
            emit RemoveItem(i);
            if (i->can_revive)
                tomb_B.push_back(i);
          }
}

void Game_Local_Logic::change_front()
{
    if (order)
    {
        foreach(Card* i,hand_A)
            i->show_front = true;
        foreach(Card *i,hand_B)
            i->show_front = false;
    }
    else
    {
        foreach(Card* i,hand_A)
            i->show_front = false;
        foreach(Card *i,hand_B)
            i->show_front = true;
    }
}
