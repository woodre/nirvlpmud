#include "/players/pestilence/ansi.h"
inherit "/obj/monster.c";
 
reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("pig"); 
  set_alias("pig");
  set_short("Pig");
  set_long("Pig is short and stocky.  He is currently studying here at\n"+
           "the school.\n");
  set_race("pig");
  set_gender("male");
  set_level(6);
  set_wc(10);
  set_ac(5);
  set_hp(90);
  set_ep(1000);
  add_money(0);
  set_aggressive(0);
  set_al(200);
  load_chat("Pig says: will you help me with my homework?\n");
  load_chat("Pig says: do i look fat?\n");
  set_chat_chance(20);
  move_object(clone_object("/players/pestilence/blue/obj/paper.c"),
        this_object()); }
