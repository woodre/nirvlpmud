inherit "/obj/monster.c";
#include <ansi.h>
#define tpn this_player()->query_name()
#include "/sys/lib.h"

reset(arg) {
  ::reset(arg);
  if(arg) return;
	
  set_name("crab");
  set_alias("crab");
  set_race("seafood");
  set_short("Maryland "+HIB+"Blue"+RED+" crab"+NORM+"");
  set_long(
	" Aggrovated looking Marylad blue crab. He really looks PISSED.\n");
  set_level(10);
  set_hp(100+random(150));
  set_al(-800);
  set_ac(10+random(8));
  set_wc(10+random(12));
  set_aggressive(0);
  set_chat_chance(5);
        load_chat("Crab gurgles: YOU ATE MY BROTHER ASSHOLE!\n");
  }
  