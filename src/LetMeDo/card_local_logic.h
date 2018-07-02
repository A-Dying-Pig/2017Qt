#ifndef CARD_LOCAL_LOGIC_H
#define CARD_LOCAL_LOGIC_H

#include "card.h"
#include <QList>

class Card_Local_Logic
{
public:
    Card_Local_Logic();
    int party;                          //1:monsters;2:
    QList <Card *>  ALL_Selectable_Card;
    QList <Card *>  SelectedCard;
    QList <Card *>  row_1;
    QList <Card *>  row_2;
    QList <Card *>  row_3;
    QList <Card *>  row_4;
    int silverCard;
    int goldCard;
    int bronzeCard;
    int totalCard;
};

#endif // CARD_LOCAL_LOGIC_H
