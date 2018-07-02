#ifndef TCPCONNECTION_H
#define TCPCONNECTION_H

#include <QtNetwork>
#include "game_local_logic.h"
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QDataStream>

#define WaitTime 10000
#define TurnWaitTime 29000


class TcpConnection:public QObject
{
    Q_OBJECT

public:
    bool ready;
    int loop_times;
    TcpConnection();
    QString ip_address;
    int server_port;
    QTcpSocket *m_socket;
    QTcpSocket *m_socket1;
    Game_Local_Logic *m_logic;
    QXmlStreamReader m_reader;
    QXmlStreamWriter m_writer;
    QTimer *wait_timer;
    QTimer *wait_timer2;
    QTimer *connect_order;
signals:
    void ReceiveALLCARD();
    void FinishALLCARD();
public slots:
    void send_ALLCARD();
    void receive_ALLCARD_data();
    void receive_turn_info();
    void send_turn_info();
    void connect1();
    void connect2();
};

#endif // TCPCONNECTION_H
