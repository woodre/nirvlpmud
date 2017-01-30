#include "/players/fakir/color.h"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("eyeless");
set_race("spirit");
set_short("Eyeless");
set_long(
  "Trapped so long in the Ways, Sir San Ar'vel has lost all sight and hope,\n"+
  "and wanders blindly from island to island in search of a way out.  The\n"+
  "pervasive evil long ago took his mortal soul, and all that remains is\n"+
  "a spirit of no substance....clinging to its last shred of existence...\n");

set_level(19);
set_hp(475 +random(100));
set_al(0);
set_wc(28);
set_ac(16);
set_aggressive(0);
set_dead_ob(this_object());
}

monster_died() {
  move_object(clone_object("/players/fakir/ways/WEP/lance.c"),
      environment(this_object()));
  tell_room(environment(this_object()),
	CYAN+"Something slips from the eyeless's grip as it dies..."+OFF+" \n");
return 0;
}
