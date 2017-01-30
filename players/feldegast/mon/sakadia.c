#include "defs.h"

inherit MONSTER;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("abdullah");
  set_alt_name("sakadi");
  set_short("Abdullah Sakadi");
  set_long(
    "Abdullah Sakadi is the eldest of the three Sakadi brothers, and\n"+
    "has brokered the family business into a merchant empire.  He is\n"+
    "an infamous connosieur of spirits, cigars, and antiquities.\n"
  );
  set_gender("male");
  set_race("human");
  set_level(10);
  set_wc(14);
  set_ac(8);
  set_hp(150);
  set_al(-150);
  set_chat_chance(5);
  load_chat("Abdullah says: What brings you here?\n");
  set_a_chat_chance(4);
  load_a_chat("Abdullah shouts: Help!  Help!\n");
  load_a_chat("Abdullah cowers before you.\n");
  add_money(450);
}

void init() {
  add_action("cmd_give", "give");
}

cmd_give(str) {
  string one,two;
  if(sscanf(str,"%s to %s",one,two) !=2)
    return 0;
  if(!id(two)) return 0;
  if(one!="chest") return 0;
  reward1();
  return 1;
}
  
void reward1() {
  object chest;
  chest=present("miniquest-like chest-sorta thingy",TP);
  if(!chest) return;
  transfer(chest,this_object());
  destruct(chest);
  write("Abdullah Sakadi accepts the mahogany chest with a smile and says,\n"+
        "\"You have done me a great service this day, "+TPN+".  I wish to\n"+
        " give you a reward.  Would you like money?\"\n");
  input_to("reward2");
}

void reward2(string str) {
  str=lower_case(str);
  if(str=="yes" || str=="y") {
    write("Abdullah opens the chest and pulls out a sack of gold coins!\n"+
          "\"Take this gold, with my thanks!\"\n");
    TP->add_money(3000+(random(10)*100));
    return;
  }
  if(str=="no" || str=="n") {
    write("Abdullah says, \"Perhaps you are a connoseur.  Would you accept something\n"+
          "  from my wine cellar?\"\n");
    input_to("reward3");
    return;
  }
  write("Abdullah says, \"I'm sorry.  Yes or no?\"\n");
  input_to("reward2");
}

void reward3(string str) {
  str=lower_case(str);
  if(str=="yes" || str=="y") {
    write("Abdullah opens the chest and pulls out a fine bottle of wine!\n"+
          "\"Take this Cabernet Savignon, with my thanks!\"\n");
    move_object(clone_object(HEAL_PATH+"cabernet.c"),this_player());
    TP->add_weight(1);
    return;
  }
  if(str=="no" || str=="n") {
    write("Abdullah says, \"Perhaps you prefer antiquities.  Would you accept something\n"+
          "  from my collection?\"\n");
    input_to("reward4");
    return;
  }
  write("Abdullah says, \"I'm sorry.  Yes or no?\"\n");
  input_to("reward3");
}

void reward4(string str) {
  str=lower_case(str);
  if(str=="yes" || str=="y") {
    write("Abdullah opens the chest and pulls out an ancient object!\n"+
          "\"Take this rare artifact, with my thanks!\"\n");
    move_object(clone_object(OBJ_PATH+"key-fire.c"),this_player());
    return;
  }
  if(str=="no" || str=="n") {
    write("Abdullah says, \"It is so rare to meet an individual who feels no need to\n"+
          "  be rewarded.  You have my thanks, "+TPN+".\"\n");
    TP->add_alignment(350);
    return;
  }
  write("Abdullah says, \"I'm sorry.  Yes or no?\"\n");
  input_to("reward4");
}

