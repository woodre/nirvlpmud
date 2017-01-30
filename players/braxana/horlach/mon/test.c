inherit "players/braxana/horlach/mon";

#include "/players/mythos/closed/guild/name.h"

reset(arg)  {
  ::reset(arg);
  if(arg) return;
  set_name("test");
  set_short("test");
  set_alias("test");
  set_race("test");
  set_long("This is a test\n");
  set_hp(1000);
  set_level(1);
  set_al(0);
  set_wc(100);
  set_ac(100);
  set_chance(30,0);
  set_spell_tell("Chance of 30 dam 5 [0]",0);
  set_spell_mess("Chance of 30 dam 5 [0]",0);
  set_spell_dam(5,0);
  set_chance(20,1);
  set_spell_tell("Chance of 20 dam 50 [1]",1);
  set_spell_mess("Chance of 20 dam 50 [1]",1);
  set_spell_dam(50,1);
  set_chance(70,2);
  set_spell_tell("Chance of 70 dam 2 [2]",2);
  set_spell_mess("Chance of 70 dam 2 [2]",2);
  set_spell_dam(2,2);
  set_chat_chance(30);
  set_chat_att_chance(30);
  set_chat_mess("Chat Mess 1 [0]\n",0);
  set_chat_mess("Chat Mess 2 [1]\n",1);
  set_chat_mess("Chat Mess 3 [2]\n",2);
  set_chat_att_mess("ATT Chat 1 [0]\n",0);
  set_chat_att_mess("ATT Chat 2 [1]\n",1);
  set_chat_att_mess("ATT Chat 3 [2]\n",2);
}

