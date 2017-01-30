/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
General Notes

The target for this monster is 40k XP.
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
inherit "/obj/monster";
inherit "/players/darkfire/obj/color";

#include <ansi.h>
#include "/players/darkfire/castle/circus/path.h"

reset(arg) {

    ::reset(arg);
    if(arg) return;

    set_alt_name("golem");
    set_race("golem");
    set_level(20);
    set_hp(1600);
    set_al(0);
    set_wc(30);
    set_ac(22);
}