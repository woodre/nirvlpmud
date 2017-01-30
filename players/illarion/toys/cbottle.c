/*
 * cbottle.c - an object that produces a limited number of glasses of
 * champagne: see champagne.c (no benefits from the champagne
 * Illarion 4/00
 */

#include "/players/illarion/dfns.h"
inherit "/obj/treasure";
#define GLASS "/players/illarion/toys/cglass.c"
status is_open;
int amount;

void reset(status arg) {
  if(arg) return;
  
  amount=50;
  set_id("bottle");
  set_short("A bottle of champagne");
  set_long("A tall, thick champagne bottle.  The label reports that it's\n"+
           "from France, bottled sometime around the beginning of the\n"+
           "twentieth century.\n");
  set_weight(4);
}
void long() {
  ::long();
  write("It is "+(is_open?"open":"closed")+", and ");
  if(amount)
    write("holds enough to "+BLD("pour")+" about "+amount/5+" more glasses.\n");
  else
    write("empty.\n");
}
void init() {
  ::init();
  add_action("cmd_open","open");
  add_action("cmd_pour","pour");
}
status cmd_open(string str) {
  if(!str || present(str,TP) != this_object())
    FAIL("Open what?\n");
  if(is_open) {
    write("The bottle is already open.\n");
    return 1;
  }
  write("You work the cork out of the champagne bottle with an impressive POP!\n");
  say(TPN+" uncorks a champagne bottle with an impressive POP!\n");
  is_open=1;
  return 1;
}
status cmd_pour(string str) {
  string who;
  object glass,pers;
  if(!str || !sscanf(str,"for %s",who))
    FAIL("Pour for whom?\n");
  pers=present(who,environment(TP));
  if(!pers || !pers->is_player())
    FAIL("You can't pour a glass for someone who isn't here.\n");
  if(!amount)
    FAIL("The bottle is empty.\n");
  if(!is_open)
    FAIL("You can't pour champagne from a closed bottle.\n");
  glass=present("champagne glass",pers);
  if(!glass) {
    glass=clone_object(GLASS);
    move_object(glass,pers);
  }
  amount=(int)glass->top_off(amount);
  if(pers == TP) {
    write("You fill a glass full of champagne.\n");
    say(TPN+" fills a glass full of champagne.\n");
  } else {
    write("You fill a glass of champagne for "+pers->query_name()+".\n");
    tell_object(pers,TPN+" fills a glass of champagne for you.\n");
    say(TPN+" fills a glass of champagne for "+pers->query_name()+".\n",pers);
  }
  if(amount==0)
    write("You have emptied the bottle.\n");
  return 1;
}
