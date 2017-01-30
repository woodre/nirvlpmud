#include "/players/pestilence/ansi.h"
inherit "/obj/monster.c";
 
reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("slippery"); 
  set_alias("slippery");
  set_short("Slippery Soap");
  set_long("Slippery Soap is a rectangular bar of soap, white in color.  He is covered\n"+
         "with bubbles.\n");
  set_gender("male");
  set_race("soap");
  set_level(2);
  set_wc(6);
  set_ac(3);
  set_hp(30);
  set_ep(1000);
  add_money(0);
  set_aggressive(0);
  set_al(200);
  load_chat("Slippery says: look at all of those bubbles.\n");
  set_chat_chance(20);
  move_object(clone_object("/players/pestilence/blue/obj/bubbles.c"),
        this_object()); }
