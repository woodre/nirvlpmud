inherit "obj/monster.c";
#include "/players/jareel/define.h"
reset(arg)  {
object gold,shield,spear;
  ::reset(arg);
  if(arg) return;
set_name("Orlanth Initiate");
set_alias("initiate");
set_alt_name("guard");
set_short("An "+BLU+"Orlanthi "+NORM+"initiate");
set_long(
        "The figure standing before you bears the mark of\n"+
        "the Orlanthi infantry.  The infantry are the troops\n"+
        "sent to protect the land.\n" );
 if(!random(2)) set_gender("male"); else set_gender("female");
set_race("human");
set_al((500-random(1000)));
set_level(17);
set_hp(350);
MOCO("/players/jareel/weapons/orlanthi_sword.c"),this_object());
init_command("wield sword");
set_wc(24);
set_ac(14);
set_aggressive(0);
add_money(600+random(500));
set_dead_ob(this_object());
}
