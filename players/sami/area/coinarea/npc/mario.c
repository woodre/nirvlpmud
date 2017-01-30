inherit "/obj/monster.c";
#include <ansi.h>
#define tpn this_player()->query_name()
#include "/sys/lib.h"

reset(arg) {
  ::reset(arg);
  if(arg) return;
	
  set_name("mario");
  set_alias("mario_1");
  set_race("hologram");
  set_short(""+HIR+"Mario"+NORM);
  set_long(
    " What do you expect? its"+HIR+" Mario"+NORM+" in all his 8-bit glory.\n"+
    " Equipped with his plummers hat and overalls, i'ts the peoples"+HIY+" Hero"+NORM+".\n"+
    " You notice light pouring out from under his"+HIR+" hat"+NORM+" \n");
  set_level(21);
  set_hp(1200+random(250));
  set_al(-800);
  set_ac(30+random(4));
  set_wc(40);
  set_aggressive(0);
   move_object(clone_object("/players/sami/area/coinarea/obj/barter/projector.c"),this_object());
  set_multi_cast(2);
  add_spell("super_jump",
  ""+HIR+"#MN#"+NORM+" jumps out of sight and lands on your"+HIY+" H E A D"+NORM+"!!!\n",
  " "+HIR+"#MN#"+NORM+" jumps out of sight and lands on #TN#'s "+HIR+"S K U L L"+NORM+".\n",
  50,({20,20}),({"other|good","other|light"}),1);
   add_spell("flower_power", 
   ""+HIR+" #MN# "+NORM+" picks a "+HIB+"F L O W E R"+NORM+" and shoots "+HIR+"\n"+
                       "@@@@@@@@   @@@@   @@@@@@@@      @@@@@@@@\n"+
                       "@@@@@@@@   @@@@   @@@@   @@     @@@@@@@@\n"+
                       "@@@@       @@@@   @@@@    @@    @@@@\n"+
                       "@@@@       @@@@   @@@@     @@   @@@@\n"+
                       "@@@@@@@@   @@@@   @@@@@@@@@@@   @@@@@@@@\n"+
                       "@@@@@@@@   @@@@   @@@@@@@       @@@@@@@@\n"+
                       "@@@@       @@@@   @@@@ @@@      @@@@\n"+
                       "@@@@       @@@@   @@@@  @@@     @@@@\n"+
                       "@@@@       @@@@   @@@@   @@@    @@@@@@@@\n"+
                       "@@@@       @@@@   @@@@    @@@   @@@@@@@@"+NORM+"\n"+
  "and you"+HIY+" bursts "+NORM+"into "+HIR+"FLAMES "+NORM+"\n", 
  " #TN# bursts into "+HIR+" FLAMES"+NORM+"\n",
  60,({45,20}),({"other|fire","other|good"}),1);
   }
