/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
General Notes

The target for this monster is 90k XP.
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Inherits
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
inherit "/obj/monster";
inherit "/players/darkfire/obj/color";

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Includes
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
#include <ansi.h>
#include "/players/darkfire/castle/circus/path.h"

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Global Variables
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
status eating;

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Method Declarations
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
void eat_scavenger();
void heart_beat();
void reset(int arg);
void init();

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Reset the object.
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
void reset(int arg) {

    ::reset(arg);
    if(arg) return;

    eating = 0;

    set_alt_name("ghoul");
    set_race("ghoul");
    set_level(20);
	set_hp(800+random(200));
	set_hp_bonus(650);
    set_al(-100);
    set_wc(40);
    set_ac(32);
	set_multi_cast(5);

	set_chat_chance(3);
    load_chat("The ghoul scrapes its claws through the dirt, leaving deep gouges.\n");

	add_spell("swipe",
		"#MN# snarls and slices into you with its claws!\n",
		"#MN# snarls and slices into #TN# with its claws!\n",
		10,"40-80","physical", 3 );

	add_spell("gouge",
		"#MN# gouges its huge teeth into you!\n",
		"#MN# gouges #TN# with its huge teeth!\n",
		10,"40-80","physical", 3 );
}

void init() {
	::init();
}

void heart_beat() {
	::heart_beat();
	eat_scavenger();
}

void eat_scavenger() {
	object scavenger;
	scavenger = present("scavenger");
	if (scavenger && eating == 0) {
		say(query_name() + " eyes " + scavenger->query_name() + " with a leer.\n\n");
		call_out("eat1", 3);
		eating = 1;
	}
}

void eat1() {
	object scavenger;
	scavenger = present("scavenger");
	if (scavenger) {
		say(query_name() + " hungrily snatches " + scavenger->query_name()
			+ " and shoves it into his " + grn("slavering") + " mouth.\n\n");
		say(scavenger->short() + " squeals horribly.\n\n");
		move_object(scavenger, this_object());
		call_out("eat2", 3);
	}
}

void eat2() {
	object scavenger;
	scavenger = present("scavenger", this_object());
	if (scavenger) {
		say(query_name() + " chews happily and " + scavenger->query_name()
			+ " disappears with the sickening crunch of " + hiw("bone") + ".\n\n");
		this_object()->heal_self(200);
		destruct(scavenger);

		/* Eat faster when in combat. */
		if (attacker_ob) {
			eating = 0;
		} else {
			call_out("hungry", 60);
		}
	}
}

void hungry() {
    say(query_name() + " looks around for something juicy to eat.\n");
	eating = 0;
}