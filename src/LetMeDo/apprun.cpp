#include "apprun.h"

AppRun::AppRun()
{
    //initialize_random_num
    qsrand(QTime::currentTime().msec());

    //initialize_interfaces
    m_editcard = new ChooseCardInterface;
    m_welcome = new WelcomeInterface;
    m_battle = new BattleInterfaceView;
    m_prepare = new PrepareBattle;
    m_switch = new SwitchHandCard;
    m_battle_end = new BattleEndInterface;
    m_round_end = new RoundEndInterface;
    m_select  = new SelectTurnCard;
    game_logic = new Game_Local_Logic;

    //all_interfaces_using_the_only_logic
    m_battle->m_logic = game_logic;
    m_prepare->m_logic = game_logic;
    m_switch->m_logic = game_logic;
    m_round_end -> m_logic = game_logic;
    m_battle_end -> m_logic = game_logic;
    m_select->m_logic = game_logic;

    connect(game_logic,SIGNAL(InitStrength()),m_battle,SLOT(init_strength()));
    emit game_logic->InitStrength();

    //show_Welcome
    connect(this,SIGNAL(GameStart()),this,SLOT(show_welcome_interface()));
    //Welcome_TO_Prepare
    connect(m_welcome->begin_game_btn,SIGNAL(clicked()),this,SLOT(welcome_to_prepare()));
    //Welcome_TO_Editcard
    connect(m_welcome->edit_card_btn,SIGNAL(clicked()),this,SLOT(welcome_to_editcard()));
    //Editcard_TO_Welcome
    connect(m_editcard->back_btn,SIGNAL(clicked()),this,SLOT(editcard_to_welcome()));
    //Editcard
    //Prepare
    connect(m_prepare,SIGNAL(CardInit()),m_prepare,SLOT(card_initialize()));
    //Prepare_TO_Welcome
    connect(m_prepare->back_btn,SIGNAL(clicked()),this,SLOT(prepare_to_welcome()));
    //Prepare_TO_Switchhandcard
    connect(m_prepare->confirm_btn,SIGNAL(clicked()),this,SLOT(prepare_to_switch()));
    connect(m_prepare,SIGNAL(FinishProcess()),m_switch,SLOT(initialize()));
    //Switch_TO_Battle
    connect(m_switch->confirm_btn,SIGNAL(clicked()),this,SLOT(switch_to_battle()));
    connect(m_switch,SIGNAL(RestoreHandCard()),m_switch,SLOT(restore_handcard()));
    connect (m_switch,SIGNAL(FinishProcess()),m_battle,SLOT(initialize()));


    //Battle
    connect(m_battle->key_pressed_timer,SIGNAL(timeout()),m_battle->m_logic,SLOT(stop_putting()));
    connect(game_logic,SIGNAL(KeyPressedTimerStop()),m_battle->key_pressed_timer,SLOT(stop()));
    connect(m_battle->m_logic,SIGNAL(UpdateStrength()),m_battle,SLOT(update_strength()));
    connect(m_battle->m_logic->one_second_timer,SIGNAL(timeout()),m_battle,SLOT(time_left_show()));
    connect(m_battle->m_logic,SIGNAL(PaintView()),m_battle,SLOT(view_update()));
    connect(game_logic,SIGNAL(RoundDrawCardViewUpdate()),m_battle,SLOT(round_initialize()));
    connect(game_logic,SIGNAL(RoundDrawCard()),game_logic,SLOT(round_draw_card()));
    connect(m_battle,SIGNAL(RoundToSwitch()),m_switch,SLOT(initialize()));
    //Battle_TO_Roundend
    connect(game_logic,SIGNAL(To_RoundEnd()),this,SLOT(battle_to_roundend()));
    //Roundend_TO_Battle/Battleend
    connect(m_round_end->m_timer,SIGNAL(timeout()),this,SLOT(roundend_to_battle_or_battleend()));
    //Battleend_TO_Welcome
    connect(m_battle_end->confirm_btn,SIGNAL(clicked()),this,SLOT(battleend_to_welcome()));
    //choose_card
    connect (m_editcard->confirm_btn,SIGNAL(clicked()),m_editcard,SLOT(write_ALLCARD()));

    //TCP
    m_tcp = new TcpConnection;
    m_tcp->m_logic = game_logic;


    connect(game_logic,SIGNAL(SelectCard()),this,SLOT(battle_to_select()));
    connect(m_select,SIGNAL(FinishSelect()),this,SLOT(select_to_battle()));
    connect(game_logic,SIGNAL(AddItem(Card*)),m_battle,SLOT(add_item(Card*)));
    connect(game_logic,SIGNAL(RemoveItem(Card*)),m_battle,SLOT(remove_item(Card*)));

    connect(m_battle,SIGNAL(TurnCardRun()),game_logic,SLOT(turn_card_run()));
    connect(this,SIGNAL(SetDir()),this,SLOT(set_dir()));
}

void AppRun::show_welcome_interface()
{
    m_welcome->show();
}

void AppRun::welcome_to_prepare()
{
    m_welcome->hide();
    m_prepare->receiveCard();
    m_prepare->view_initialize();
    m_prepare->show();
}

void AppRun::prepare_to_switch()
{
    emit m_prepare->CardInit();

}

void AppRun::prepare_to_welcome()
{
    m_prepare->hide();
    m_welcome->show();
}

void AppRun::switch_to_battle()
{
    emit m_switch->RestoreHandCard();
}

void AppRun::battle_to_roundend()
{
    m_battle->hide();
    m_round_end->set_result();
    m_round_end->show();
    m_round_end->m_timer->start();
}

void AppRun::roundend_to_battle_or_battleend()
{
    m_round_end->m_timer->stop();

    if (game_logic->round_continue)
       {
        m_round_end->hide();
        emit game_logic->RoundDrawCard();
       }
    else
    {
        m_battle_end->set_result();
        m_battle_end->show();
        m_round_end->hide();
    }
}

void AppRun::battleend_to_welcome()
{
    m_battle_end->hide();
    m_welcome->show();
}

void AppRun::welcome_to_editcard()
{
    m_welcome->hide();
    m_editcard->show();
}

void AppRun::editcard_to_welcome()
{
    m_editcard->hide();
    m_welcome->show();
}


void AppRun::battle_to_select()
{
    m_select->initialize();
    m_battle->hide();
    m_select->show();
}

void AppRun::select_to_battle()
{
    m_select->restore();
    m_select->hide();
    m_battle->show();
    emit game_logic->TurnProcess();
}

void AppRun::set_dir()
{
    m_prepare->file_dir = file_dir;
    m_editcard->file_dir = file_dir;

}
