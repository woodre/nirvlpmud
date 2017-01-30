/*
 *  A Sode no Shirayuki for players to fight with.
 * 
 *                                             Kyrain/sami */

/* This give the weapon the basic characteristics of weapon.c   */
inherit "obj/weapon.c";
#include "/sys/lib.h"
#include <ansi.h>
#define tpn this_player()->query_name()
#define ATT USER->query_attack()

 int i;
 reset(arg) {
    ::reset(arg);
    if (arg) return;

  
    set_name("Sode");
	set_alt_name("shirayuki");
	set_id("sode");
    set_alias("sword");
    set_short(""+RED+"Sode"+NORM+" no "+YEL+"Shirayuki"+NORM+"");
    set_long("Sode no Shirayuki the white blade.\n");
    set_class(17);
    set_weight(10);
    set_value(2500);
	
	set_params("other|fire",3,0);
	set_params("other|electric",3,0);
	 message_hit = 
    ({
        BOLD+" OWNZ "+NORM," blood gushes everywhere",
        HIR+" DOMINATES   "+NORM," extremely hard",
        HIY+" --==SLICES==-- "+NORM," viciously",
        HIC+" snapped "+NORM,", with precision",
        HIG+" sliced "+NORM," drawing a little blood",
        HIB+" pierced "+NORM," lightly",
        HIW+" nicked "+NORM," very lightly"
    });

      set_hit_func(this_object());
}
	query_wear() {
   return 1;
}
weapon_breaks() {
   return 1;
}
weapon_hit(attacker) {
  i=random(10);
  if (i>6) {

        say(this_player()->query_name()+"'s "+HIK+"Sode no Shirayuki"+HIY+" hums"+NORM+" with a "+RED+" fiery"+NORM+" aura.\n");
        write(this_player()->query_name()+"'s "+HIK+"Sode no Shirayuki"+HIY+" hums"+NORM+" with a "+RED+" fiery"+NORM+" aura.\n");
  return 3;
    }
   return 0;
}