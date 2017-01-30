/*
 *    An unholy scythe carried by sentinels of Arate.
 */

#define tp this_player()->query_name()

int w;

inherit "obj/weapon.c";
#include "/players/saber/closed/esc.h"
#include "/players/saber/closed/ansi.h"

 reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("unholy scythe");
    set_alias("scythe");
    set_type("polearm");
    set_short("An unholy scythe");
    set_long("A huge scythe with a blade forged from cold steel.\n"+
             "It has been "+BOLD+"blessed"+NORM+" by the priests of Arate to "+
             "battle the forces of good.\n");
    set_class(17);
    set_weight(2);
    set_value(1000);
    set_hit_func(this_object());
}

weapon_hit(attacker){
if(call_other(this_player(), "query_attrib", "pie") > random (60))  {

  if(attacker->query_alignment() > 0)  {
    tell_room(environment(this_player()),
    "The unholy scythe glows with an evil "+HIM+"purple"+NORM+" light.\n");
    return 8;
        }
    }
    return;
}
