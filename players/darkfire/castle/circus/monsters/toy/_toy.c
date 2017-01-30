/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
General Notes

The target for this monster is 8k XP.
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

inherit "/obj/monster";
inherit "/players/darkfire/obj/color";

#include <ansi.h>
#include "/players/darkfire/castle/circus/path.h"

#define PRE "The tattered remains of a stuffed "
#define POST " with matted fur that smells of " + grn("mildew") + ". It is missing an eye, and "+hiw("stuffing")+" oozes from a ripped seam in its belly."
#define HAUNTED " It is wandering around the area, perhaps inhabited by an unseen spirit."

reset(arg) {

    ::reset(arg);

    if(arg) return;

    set_alt_name("toy");
    set_race("toy");
    set_level(20);
    set_hp(400);
    set_al(0);
    set_wc(25);
    set_ac(20);

	add_spell("club",
		"#MN# snarls and slices into you with its claws!\n",
		"#MN# snarls and slices into #TN# with its claws!\n",
		10,"20-30","physical", 3 );
}
