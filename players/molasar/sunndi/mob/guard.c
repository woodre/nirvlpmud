
#include "/players/molasar/sunndi/include/filter_color.h"
#include "/players/molasar/sunndi/include/sunndi.h"

inherit "obj/monster";

#include "/players/molasar/sunndi/include/mob.h"

reset(arg) {
   if(arg) 
      return;

   set_name("Sunndi Guard");
   set_alias("guard");
   set_short(filter_color("A Sunndi Guard",HIG));
   set_long("A strong looking soldier clad in a suit of leather armor.\n");
   set_level(10);
   set_hp(150);
   set_ac(5);
   set_wc(16);
   set_al(200);
   set_alignment_adjust(ALADJ_GUARD);

   ::reset();

}

