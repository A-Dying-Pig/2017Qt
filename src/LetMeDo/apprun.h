#ifndef APPRUN_H
#define APPRUN_H

#include "welcomeinterface.h"
#include "battleinterfaceview.h"
#include "choosecardinterface.h"
#include "battleendinterface.h"
#include "preparebattle.h"
#include "switchhandcard.h"
#include "roundendinterface.h"
#include "game_local_logic.h"
#include "selectturncard.h"
#include "tcpconnection.h"
#include <QTime>


class AppRun:public QObject
{
    Q_OBJECT

public:
    AppRun();
    QString file_dir;
    ChooseCardInterface *m_editcard;
    WelcomeInterface *m_welcome;
    BattleInterfaceView *m_battle;
    PrepareBattle *m_prepare;
    SwitchHandCard *m_switch;
    SelectTurnCard *m_select;
    BattleEndInterface *m_battle_end;
    RoundEndInterface *m_round_end;
    Game_Local_Logic *game_logic;
    TcpConnection *m_tcp;

signals:
    void GameStart();
    void SetDir();
private slots:
    void show_welcome_interface();
    void welcome_to_prepare();
    void prepare_to_welcome();
    void prepare_to_switch();
    void switch_to_battle();
    void battle_to_roundend();
    void roundend_to_battle_or_battleend();
    void battleend_to_welcome();
    void welcome_to_editcard();
    void editcard_to_welcome();
    void battle_to_select();
    void select_to_battle();
    void set_dir();

};

#endif // APPRUN_H
