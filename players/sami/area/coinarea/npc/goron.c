inherit "/obj/monster.c";
#include <ansi.h>
#define tpn this_player()->query_name()
#include "/sys/lib.h"

reset(arg) {
  ::reset(arg);
  if(arg) return;
	
  set_name("goron");
  set_alias("goron_1");
  set_race("hologram");
  set_short(""+HIK+"Goron"+NORM);
  set_long(
    " From Hyrule, its a beast known as"+HIK+" Goron"+NORM+". This large beast is covered\n"+
    " with a large shell and massive fists. Its hair is grey and it appears \n"+
    " to have many years on it. \n");
  set_level(21);
  set_hp(1200+random(250));
  set_al(-800);
  set_ac(30+random(4));
  set_wc(40);
  set_aggressive(0);
  move_object(clone_object("/players/sami/area/coinarea/obj/barter/projector.c"),this_object());
  set_multi_cast(2);
  add_spell("goron_punch",
  ""+HIK+"#MN#"+NORM+" throws a right hook from "+HIR+"H E L L"+NORM+" at your "+HIY+"S K U L L"+NORM+"!!!\n",
  " "+HIK+"#MN#"+NORM+" Devastates #TN# with a Right hook to the "+HIR+"S K U L L"+NORM+"\n",
  50,({15,15}),({"other|earth","other|earth"}),1);
   add_spell("roll_of_death", 
   ""+HIK+"#MN# "+NORM+" curls into a "+HIB+"Ball"+NORM+" and "+HIR+" C R A S H E S"+NORM+"into "+HIR+"#TN#"+NORM+"\n",
  ""+HIK+"#MN#"+NORM+" balls up and  "+HIY+"C R A S H E S"+NORM+" into #TN#.\n",
  30,({55,20}),({"other|earth","other|sonic"}),1);
   } 
