
#include "/players/molasar/sunndi/include/filter_color.h"
#include "/players/molasar/sunndi/include/sunndi.h"

inherit "obj/monster";

#include "/players/molasar/sunndi/include/mob.h"

reset(arg) {
   if(arg) 
      return;

   set_name("bandit");
   set_alias("badguy");
   set_short(filter_color("A Bandit",HIR));
   set_long("A mean guy wear a fur coat made out of baby pandas.\n");
   set_level(10);
   set_hp(150);
   set_ac(5);
   set_wc(16);
   set_al(200);
   set_alignment_adjust(ALADJ_BANDIT);

   ::reset();

}


