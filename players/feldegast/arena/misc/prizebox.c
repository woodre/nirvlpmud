#define REFEREE "Symbio"
#include "defs.h"

int money;
string *contestants;

inherit "/obj/treasure.c";

void reset(int arg) {
  if(arg) return;
  contestants=({ });
  set_id("box");
  set_short("Prize Box");
  set_weight(999);
  set_value(0);
}

void long(string str) {
  int i;
  write("This box holds the prize money for the tournament.  The fee\n"+
        "for entering the tournament is only 5,000 coins.  You may\n"+
        "sign up for the tournament by typing 'pay fee'.  Whoever is\n"+
        "managing the tournament may 'award 1st place,2nd place,3rd place'\n");
  write("Current pot = "+money+"\n");
  write("The following players have signed up:\n");
  for(i=0; i < sizeof(contestants); i++)
    write(contestants[i]+"\n");
}

void init() {
  add_action("cmd_pay", "pay");
  if(TPRN==REFEREE)
    add_action("cmd_award","award");
}

int cmd_pay(string str) {
  if(str!="fee") return 0;
  if((int)TP->query_money() < 5000) {
    write("You don't have enough money.\n");
    return 1;
  }
  TP->add_money(-5000);
  money+=5000;
  contestants+=({ TPRN });
  write("You pay the fee of 5000 coins to enter the tournament.\n");
  say(TPN+" pays the fee to enter the tournament.\n");
  return 1;
}

int cmd_award(string str) {
  object first,second,third;
  string un,deux,troix;
  int one,two,three;
  notify_fail("Usage: award <player1>,<player2>,<player3>\n");
  if(sscanf(str,"%s,%s,%s",un,deux,troix)!=3)
    return 0;
  first=find_player(un);
  second=find_player(deux);
  third=find_player(troix);
  if(!first || !second || !third) {
    write("Player not found.\n");
    return 0;
  }
  one=money/2;
  two=money*3/10;
  three=money/5;
  first->add_money(one);
  second->add_money(two);
  third->add_money(three);
  tell_object(first,"You are awarded "+one+" coins for coming in 1st!\n");
  tell_object(second,"You are awarded "+two+" coins for coming in 2nd!\n");
  tell_object(third,"You are awarded "+three+" coins for coming in 3rd!\n");
  write("You award the prizes to "+str+".\n");
  say(TPN+" distributes the prize money to the winners.\n");
  write_file(LOG_PATH+"arena.log",ctime(time())+" "+TPN+" awarded "+str+".\n"+
             "Pot = "+money+"\n");
  money=0;
  return 1;
}

get() { return 0; }
