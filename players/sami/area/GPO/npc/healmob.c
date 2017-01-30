inherit "/obj/monster.c";
#include <ansi.h>
#define TPN this_player()->query_name()
#include "/sys/lib.h"

reset(arg) {
string adj;
   ::reset(arg);
   if(arg) return;
  set_name("animation");
  set_alias("heal");
  set_race("demon");
set_short("An animated heal");
  set_long(
    " An animated minion of the dark one.\n");
  set_level(4);
  set_hp(150+random(150));
  set_al(-800);
  set_heal(1,1);
  set_ac(random(10)+10);
  set_wc(random(5)+10);
  set_aggressive(6);
#if 0 /* Gnar */
add_spell("ring_pulse", 
   "#MN# claws "+RED+"tear"+NORM+" into your "+HIY+"flesh"+NORM+".\n",
   "#MN# claws "+RED+"tear"+NORM+" into #TN#'s "+HIY+"flesh"+NORM+".\n",
  10,({0,25}),({"other|evil","physical"}),1);
		}
#endif
}

