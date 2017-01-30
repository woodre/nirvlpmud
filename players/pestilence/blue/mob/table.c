#include "/players/pestilence/ansi.h"
inherit "/obj/monster.c";
 
reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("Side Table"); 
  set_alt_name("side table");
  set_alias("table");
  set_short("Side Table");
  set_long("A small red and orange side table that sits beside the Thinking\n"+
           "chair.  It has one drawer.  Sitting on top of the side table is\n"+
           "a red telephone.\n");
  set_race("furniture");
  set_gender("female");
  set_level(4);
  set_wc(8);
  set_ac(5);
  set_hp(60);
  set_ep(1000);
  add_money(0);
  set_aggressive(0);
  set_al(200);
  load_chat("The side table practices singing.\n");
  set_chat_chance(20);
  move_object(clone_object("/players/pestilence/blue/obj/notebook.c"),
        this_object()); }
