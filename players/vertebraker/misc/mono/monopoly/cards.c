/* cards.c
 * This has all the Chance and Community Chest cards
 */
#include "path.h"

#define PAY(x) TPMOBJ->add_cash(-x)
#define GET(x) TPMOBJ->add_cash(x)     /* just for readability */
#define W writecard
#define S(x) SHOUT(NAME+x)
#define SF MAIN->square_file
#define NS MAIN->num_square
#define THIS_SQUARE NS(TPMOBJ->query_square())
#define ADVANCE(x) advance(x);

advance(to) {
  int f,t;

  f=THIS_SQUARE;
  t=NS(to);
  if(f==t || f==t-1 || (f==SQSZ-1 && t==0)) SF(t)->bounce(1);
  else {
    t=t-f;
    if(t<0) t+=SQSZ;
    write("Moving "+t+" squares.\n");
    SF(f+1)->bounce(t);
  }
}

writecard(str) {
  string *arr;
  int i;

  arr=explode(str,"\n");
  for(i=0;i<sizeof(arr);i++)
    write(PAD(arr[i],-30-strlen(arr[i])/2)+"\n");
  write("\n");
}

#define CHANCESIZE 16
chance() {
/* cards can cause a second set of bounces and screw up recursion depth */
  TPMOBJ->set_lock();
  call_out("chanceout",1);
  return 1;
}

chanceout() {
  string card;

  TPMOBJ->clear_lock();
  remove_call_out("chanceout");
  card="chance"+(random(CHANCESIZE)+1);
  write("You pick up a Chance card which says:\n");
  call_other(this_object(),card);
  return 1;
}

#define CHESTSIZE 16
chest() {
/* cards can cause a second set of bounces and screw up recursion depth */
  TPMOBJ->set_lock();
  call_out("chestout",1);
  return 1;
}

chestout() {
  string card;

  TPMOBJ->clear_lock();
  remove_call_out("chestout");
  card="chest"+(random(CHESTSIZE)+1);
  write("You pick up a Community Chest card which says:\n");
  call_other(this_object(),card);
  return 1;
}


chance1() {
  W("This card may be kept\nuntil needed or sold\n\nGET OUT OF JAIL\nFREE\n");
  write("Type 'use card' when in jail\n");
  S(" gets a Get Out Of Jail Free card.\n");
  TPMOBJ->add_out_of_jail(1);
}

chance2() {
  W("PAY\nPOOR TAX\nOF "+MS+"15\n");
  S(" has to pay a poor tax of "+MS+"15\n");
  PAY(15);
}

chance3() {
  int i;
  object a;

  W("You Have Been\nELECTED\nCHAIRMAN\nOf The Board\n\n"
   +"PAY\nEACH PLAYER\n"+MS+"50\n");
  S(" has been elected Chairman of the Board.  "+NAME+" pays you "
    +MS+"50\n");
  a=MAIN->query_players(TPMOBJ->query_gamename());
  for(i=0;i<sizeof(a);i++)
    if(a[i]!=TPMOBJ) {
      TPMOBJ->add_cash(-50);
      tell_object(a[i]->query_player(),NAME+" gives you "
                  +MS+"50 because of a Chance card.\n");
      a[i]->add_cash(50);
    }
}

chance4() {
  W("Go Directly\nTO JAIL\n\nDO NOT PASS GO, DO NOT COLLECT "+MS+"200\n");
  S(" goes directly to jail.\n");
  (PATH+"/_goto")->land();
}

chance5() {
#ifdef LAND_GO
  W("ADVANCE\nTO GO\n\n(Collect "+MS+LAND_GO+")\n");
#else
  W("ADVANCE\nTO GO\n\n(Collect "+MS+"200)\n");
#endif
  S(" advances to Go.\n");

  ADVANCE("go")
}

chance6() {
  W("Advance to\nSt. Charles Place\n\nIF YOU PASS GO, COLLECT "+MS+"200\n");
  S(" advances to St. Charles Place.\n");
  ADVANCE("charles")
}

chance7() {
  W("Take a Walk\nOn The Board Walk\n\nADVANCE TOKEN\nTO BOARD WALK\n");
  S(" advances to Board Walk\n");
  ADVANCE("boardwalk")
}

chance8() {
  int i,w,e;

  W("Advance Token\nTo Nearest Utility.\n\n"
  +"IF UNOWNED you may\nbuy it from bank\n\n"
  +"IF OWNED, pay owner the rent due.\n");
  S(" advances to the nearest utility.\n");
/* this isn't correct..  should be: */
/*"IF OWNED, throw dice and pay owner a total ten times the amount thrown." */
/* but this would be hard to do..  adjust rent temporarily??? */
  i=THIS_SQUARE;
  w=NS("water");
  e=NS("electric");
  if((w>e && i>=e && i<w) || (e>w && (i>=e || i<w)))
    ADVANCE(extract(SF(w),strlen(PATH)+2))
  else ADVANCE(extract(SF(e),strlen(PATH)+2))
}

chance9() {
  W("Bank pays you\ndividend of "+MS+"50\n");
  S(" gets paid a dividend of "+MS+"50\n");
  GET(50);
}

chance10() {
  W("Advance to\nIllinois Ave.\n");
  S(" advances to Illinois Ave.\n");
  ADVANCE("illinois")
}

chance11() {
  W("Your Building\nAnd Loan Matures\n\nCOLLECT "+MS+"150\n");
  S(" collects "+MS+"150\n");
  GET(150);
}

chance12() {
  W("Take a Ride\nOn The Reading\nIF YOU PASS GO\nCOLLECT "+MS+"200\n");
  S(" advances to the Reading RailRoad.\n");
  ADVANCE("reading")
}

chance13() {
  int i,c,tmp;

  W("Make General Repairs\nOn All Your Property\n\n"
   +"FOR EACH HOUSE\nPAY "+MS+"25\nFOR EACH HOTEL "+MS+"100\n");
  S(" has to make general repairs to "
    +({"its","his","her"})[TP->query_gender()]+" properties.\n");
  c=0;
  for(i=0;i<SQSZ;i++)
    if((tmp=TPMOBJ->query_house(i))>MONOPOLY) 
      if(tmp==5) c+=100;
      else c+=tmp*25;
  write("You pay "+MS+c+" in house repairs.\n");
  S(" pays "+MS+c+" in house repairs.\n");
  PAY(c);
}

chance14() {
  int i;
  W("GO BACK\n3 SPACES\n");
  S(" goes back three spaces.\n");
  i=THIS_SQUARE;
  SF(i-3)->bounce(1);
}

chance15() {
  int i,r;

  W("Advance token to the\nnearest Railroad and\npay owner Twice the\n"
   +"Rental to which he is\notherwise entitled.\n\n"
   +"If RailRoad is unowned, you may buy it from the Bank.\n");
  S(" advances to the nearest RailRoad.\n");
  i=THIS_SQUARE;
  r=(i+5)/10*10+5;
  if(r>SQSZ) r-=SQSZ;
  ADVANCE(extract(SF(r),strlen(PATH)+2))
  SF(r)->land();  /* pay rent twice */
}

/* there are two of these cards */
chance16() { return chance15(); }

chest1() {
  W("You Have Won\nSECOND PRIZE\nIn A\nBEAUTY CONTEST\nCOLLECT "+MS+"10\n");
  S(" wins second prize in a beauty contest.\n");
  GET(10);
}

chest2() {
  W("Bank Error\nIn Your Favor\n\nCollect "+MS+"200\n");
  S(" collects "+MS+"200.\n");
  GET(200);
}

chest3() {
  W("Life\nInsurance\nMatures\n\nCollect "+MS+"100\n");
  S(" collects "+MS+"100.\n");
  GET(100);
}

chest4() {
  W("Income Tax\nRefund\n\nCollect "+MS+"20\n");
  S(" collects "+MS+"20\n");
  GET(20);
}

chest5() {
  int i;
  object a;

  W("Grand Opera Opening\n\nCOLLECT "+MS+"50\n"
   +"For opening night seats\n");
  S(" has a Grand Opera Opening.  You pay "+
    ({"it","him","her"})[TP->query_gender()]+" "+MS+"50 for seats.\n");
  a=MAIN->query_players(TPMOBJ->query_gamename());
  for(i=0;i<sizeof(a);i++)
    if(a[i]!=TPMOBJ) {
      TPMOBJ->add_cash(50);
      tell_object(a[i]->query_player(),"You give "+NAME
                  +" "+MS+"50 because of a Community Chest card.\n");
      a[i]->add_cash(-50);
    }
}

chest6() {
  W("RECEIVE\nFor\nServices\n"+MS+"25\n");
  S(" collects "+MS+"25.\n");
  GET(25);
}

chest7() {
  W("YOU INHERIT\n"+MS+"100\n");
  S(" collects "+MS+"100.\n");
  GET(100);
}

chest8() {
  W("Get Out\nOf JAIL, Free\n\nThis card may be kept until needed or sold\n");
  S(" gets a Get Out Of Jail Free card.\n");
  write("Type 'use card' when in jail\n");
  TPMOBJ->add_out_of_jail(1);
}

chest9() {
  int i,c,tmp;

  W("You are assessed\nFor Street Repairs\n\n"+MS+"40 PER HOUSE\n"
   +MS+"115 PER HOTEL\n");
  S(" has to make general repairs to "
    +({"its","his","her"})[TP->query_gender()]+" properties.\n");
  c=0;
  for(i=0;i<SQSZ;i++)
    if((tmp=TPMOBJ->query_house(i))>MONOPOLY)
      if(tmp==5) c+=115;
      else c+=tmp*40;
  write("You pay "+MS+c+" in house repairs.\n");
  PAY(c);
}

chest10() {
  W("XMAS FUND\nMATURES\n\nCOLLECT "+MS+"100\n");
  S(" collects "+MS+"100.\n");
  GET(100);
}

chest11() {
  W("From Sale of\nStock\n\nYou Get\n"+MS+"45\n");
  S(" collects "+MS+"45.\n");
  GET(45);
}

chest12() {
#ifdef LAND_GO
  W("ADVANCE TO GO\n\n(Collect "+MS+LAND_GO+")\n");
#else
  W("ADVANCE TO GO\n\n(Collect "+MS+"200)\n");
#endif
  S(" advances to Go.\n");

  ADVANCE("go");
}

chest13() {
  W("Doctor's Fee\n\nPAY "+MS+"50\n");
  S(" pays "+MS+"50 in doctors fees.\n");
  PAY(50);
}

chest14() {
  W("Pay\nSchool Tax\nOf "+MS+"150\n");
  S(" pays "+MS+"150 in school taxes.\n");
  PAY(150);
}

chest15() {
  W("Pay\nHospital\n"+MS+"100\n");
  S(" pays "+MS+"100 in hospital fees.\n");
  PAY(100);
}

chest16() {
  string gotojail;

  W("GO TO JAIL\nGo Directly to Jail\n\n"
   +"DO NOT PASS GO, DO NOT COLLECT "+MS+"200\n");
  S(" goes directly to jail.\n");
  gotojail=PATH+"/_goto";
  gotojail->land();
}
