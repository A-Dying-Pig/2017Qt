#include "card_local_logic.h"
#include "cardlibrary.h"

Card_Local_Logic::Card_Local_Logic()
{
    //initialize;
    Biting_Frost *BT = new Biting_Frost;
    Lacerate *L = new Lacerate;
    Commanders_Horn *CH = new Commanders_Horn;
    Harpy *Hp  = new Harpy;
    Crone_Weavess *CW = new Crone_Weavess;
    Dagon* D = new Dagon;
    Arachas *A = new Arachas;
    First_Light *FL = new First_Light;
    Impenetrable_Fog *IF =new Impenetrable_Fog;
    Immune_Boost *IB = new Immune_Boost;
    Bekkers_Twisted_Mirror *BTM = new Bekkers_Twisted_Mirror;
    Geralt_Igni *GI = new Geralt_Igni;
    Foglet *F = new Foglet;
    Geels *G = new Geels;
    Celaeno_Harpy *CHp = new Celaeno_Harpy;
    Woodland_Spirit *WS = new Woodland_Spirit;
    Earth_Elemental *EE = new Earth_Elemental;
    Crone_Whispess *CWss = new Crone_Whispess;
    Crone_Brewess *CB  = new Crone_Brewess;
    Archgriffin *Ag = new Archgriffin;
    Wild_Hunt_Rider *N = new Wild_Hunt_Rider;
    Caranthir *C = new Caranthir;
    Frightener *Ft = new Frightener;
    Unseen_Elder *UE = new Unseen_Elder;
    Arachas_Behemoth *AB = new Arachas_Behemoth;
    Vran_Warrior *VW = new Vran_Warrior;
    Sunny_Day *SD = new Sunny_Day;
    Restart *R = new Restart;
    Lesser_Earth *LE =new Lesser_Earth;
    Raging_Wolf *RW = new Raging_Wolf;
    Arachas_Larva *AL = new Arachas_Larva;
    Harpy_Egg *HE = new Harpy_Egg;
    Harpy_Cub *HC = new Harpy_Cub;



    ALL_Selectable_Card.push_back(CH);
    ALL_Selectable_Card.push_back(L);
    ALL_Selectable_Card.push_back(BT);
    ALL_Selectable_Card.push_back(Hp);
    ALL_Selectable_Card.push_back(CW);
    ALL_Selectable_Card.push_back(D);
    ALL_Selectable_Card.push_back(A);
    ALL_Selectable_Card.push_back(FL);
    ALL_Selectable_Card.push_back(IF);
    ALL_Selectable_Card.push_back(IB);
    ALL_Selectable_Card.push_back(BTM);
    ALL_Selectable_Card.push_back(GI);
    ALL_Selectable_Card.push_back(F);
    ALL_Selectable_Card.push_back(G);
    ALL_Selectable_Card.push_back(CHp);
    ALL_Selectable_Card.push_back(WS);
    ALL_Selectable_Card.push_back(EE);
    ALL_Selectable_Card.push_back(CWss);
    ALL_Selectable_Card.push_back(CB);
    ALL_Selectable_Card.push_back(Ag);
    ALL_Selectable_Card.push_back(N);
    ALL_Selectable_Card.push_back(C);
    ALL_Selectable_Card.push_back(Ft);
    ALL_Selectable_Card.push_back(UE);
    ALL_Selectable_Card.push_back(AB);
    ALL_Selectable_Card.push_back(SD);
    ALL_Selectable_Card.push_back(R);
    ALL_Selectable_Card.push_back(RW);
    ALL_Selectable_Card.push_back(LE);
    ALL_Selectable_Card.push_back(AL);
    ALL_Selectable_Card.push_back(HE);
    ALL_Selectable_Card.push_back(HC);
    ALL_Selectable_Card.push_back(VW);

    bronzeCard = 0;
    silverCard = 0;
    goldCard = 0;
    totalCard = 0;
}

