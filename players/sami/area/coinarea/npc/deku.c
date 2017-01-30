inherit "/obj/monster.c";
#include <ansi.h>
#define tpn this_player()->query_name()
#include "/sys/lib.h"

reset(arg) {
  ::reset(arg);
  if(arg) return;
	
  set_name("deku");
  set_alias("scrub");
  set_race("hologram");
  set_short(""+HIK+"Deku"+NORM+" scrub");
  set_long(
    " From Hyrule, its a beast known as"+HIG+" Deku"+NORM+" scrub. Short and made\n"+
    " of what appears to be shrubbery and wood. Deku is playing on his Deku Pipes.\n");
  set_level(21);
  set_hp(1200+random(250));
  set_al(-800);
  set_ac(30+random(4));
  set_wc(42);
  set_aggressive(0);
  move_object(clone_object("/players/sami/area/coinarea/obj/barter/projector.c"),this_object());
  set_multi_cast(2);
  add_spell("Deku_bubble",
  ""+HIK+"#MN#"+NORM+" blows a huge bubble and "+HIR+"Shoots"+NORM+" you in the "+HIY+"C H E S T"+NORM+"!!!\n",
  " "+HIK+"#MN#"+NORM+" devastates #TN# with a Bubble Shot to the "+HIR+"C H E S T"+NORM+".\n",
  50,({25,25}),({"other|earth","other|water"}),1);
   add_spell("spin_attack", 
   ""+HIK+"#MN# "+NORM+" screams and"+HIB+" spins"+NORM+" towards you and "+HIR+" C R A S H E S"+NORM+" into"+HIR+" you"+NORM+".\n",
  ""+HIK+"#MN#"+NORM+" spins and "+HIY+"C R A S H E S"+NORM+" into #TN#.\n",
  30,({40,40}),({"other|earth","other|dark"}),1);
   } 
