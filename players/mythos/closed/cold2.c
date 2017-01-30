/* Players will never get this */


#include "/players/mythos/closed/ansi.h"

inherit "players/mythos/closed/guild/spells/dwep.c";
 reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("cold");
    set_alt_name("fire");
    set_alias("cold fire");
    set_short(CYN+"Cold Fire Blade"+NORM);
    set_long("A blade made of PURE COLD FIRE!\n");
    set_path("players/mythos/awep/forest/air");
    set_class(18);
    set_weight(1);
    set_owner("priest");
    set_slaying("demon");
    set_vampire();
    set_steal();
    set_life();
    set_sharp();
    set_berserk();
    set_speed();
    set_wound();
    set_spell();
    set_value(10000);
    set_hit_func(this_object());
}
