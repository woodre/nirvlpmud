/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
General Notes

The target for this monster is 15k XP.
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
inherit "/obj/monster";
inherit "/players/darkfire/obj/color";

#include <ansi.h>
#include "/players/darkfire/castle/circus/circus.h"

reset(arg) {

    ::reset(arg);

    if(arg) return;

    set_alt_name("scavenger");
    set_race("scavenger");
    set_level(20);
    set_hp(1600);
    set_al(0);
    set_wc(30);
    set_ac(22);

	set_chat_chance(3);
    load_chat("The scavenging animal foams at the mouth.\n");

    set_wander(1);
    set_wander_interval(30 + random(10));
    set_wander_realm(PATH_ROOMS);

    add_spell("rabid_bite",
      "#MN# snarls and sinks its teeth into you!\n",
      "#MN# snarls and sinks its teeth into #TN#!\n",
      10,"20-40","physical", 3 );
}
