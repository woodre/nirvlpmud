/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
General Notes

The target for this monster is 120k XP.
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
inherit "/obj/monster";
inherit "/players/darkfire/obj/color";

#include <ansi.h>
#include "/players/darkfire/castle/circus/path.h"

reset(arg) {

    ::reset(arg);
    if(arg) return;

    set_alt_name("mutant");
    set_race("mutant");
    set_level(20);
    set_hp(1600);
    set_al(0);
    set_wc(30);
    set_ac(22);

    /* Mutants should wander around. */
    set_wander(1);
    set_wander_interval(30);
    set_wander_realm(PATH_TUNNELS);
}