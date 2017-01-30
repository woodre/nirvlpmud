#include "../std.h"
inherit NPC;

reset(x)
{
   if(x) return;
   ::reset();
   set_name("verte");
   set_alias("lil_verte");
   set_gender("male");
   set_race("wizard");
   set_short("Verte the Wizard (smiling)");
   set_long(
      "This is Verte, proprietor of the Halloween shop.\n"+
      "He has a large smile on his face, and beams at you\n"+
      "as you approach.\n");
   set_level(1);
   set_wc(1);
   set_ac(1);
   set_no_exp_value();
   set_dead_ob(TO);
}

monster_died()
{
   tell_room(USER,
      "\n\tVerte disappears in a puff of smoke.\n"+
      "\tYou gain 0 experience.\n\n");
   destruct(present("corpse",USER));
   return 0;
}
