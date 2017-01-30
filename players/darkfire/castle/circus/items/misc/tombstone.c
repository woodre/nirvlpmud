#pragma strict_types, verbose_errors

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
General Notes: The tombstone is meant to be loaded into graveyard rooms, to
facilitate the raising of a ghoulish clown. It selects a random name from a
list of possibilities and uses that for its descriptions and for the ghoul.
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Inherits
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
inherit "/players/darkfire/obj/dfobj_visible";
inherit "/players/darkfire/obj/color";

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Includes
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
#include <ansi.h>
#include "../../circus.h"

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Constants
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
#define CLOWN_NAMES ({"calvero", "clarabell", "carequinha", "cha-u-kao", "cepillin", "cairoli", "carl", "coco", "chuckles", "charlie chalk", "chuchin"})

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Global Variables
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
string clown_name;

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Method Declarations
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
void construct();
void init();
int shatter_tombstone(string str);
void thrash();
void collapse();
void claws();
void shatter();
string get_clown_name();

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Initial construction of the object.
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
void construct() {
	::construct();
    clown_name = (string)UTIL->get_random_array_member(CLOWN_NAMES);
	set_name("tombstone");
	SetMultipleIds(({"stone"}));
	set_short(hiw("A tombstone: ") + gry("( R.I.P. ") + get_clown_name() + gry(" )"));
	set_long(UTIL->wrap("An imposingly large, " +hiw("white marble") + " stone with the "
		+ "words \n" + gry("( R.I.P. ") + get_clown_name() + gry(" )") + " carved into it. "
		+ "The name of the clown is in eerily glowing letters. "
		+ "There are cracks running through the headstone, you wonder "
		+ "if you dare release the power within. If you do, you might try to "
		+ hiw("shatter") + " it.")
	);
}

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Handle a player coming into contact with it.
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
void init() {
    add_action("shatter_tombstone", "shatter");
}

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Shatter the tombstone, summoning a ghoul and possibly opening a route into the
tunnels below the graveyard.
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
int shatter_tombstone(string str) {
    if( !str || !id(str) ) {
        return 0;
    }

	/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
	Only allow one ghoul at a time, no loading up
	rooms full of ghouls without killing them.
	=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
    if (present("ghoul")) {
        write("The ghoul snarls and blocks you from the tombstone.\n");
        return 1;
    }

	/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
	Some tasty room chat to kick things off, then
	call out for the next messages.
	=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
    write("You whack the tombstone and cracks appear in the "
    	+ hiw("marble") + "!\n");

    say(this_player()->query_name()+" whacks the tombstone and cracks appear in the "
    	+ hiw("marble") + "!\n\n");

    call_out("thrash", 3);
    return 1;
}

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Create a little atmosphere...
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
void thrash() {
    say("The soft dirt at your feet begins to heave as something below awakens.\n");
    call_out("collapse", 3);
}

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Create a little more atmosphere...
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
void collapse() {
    say("The grave collapses, revealing a deep hole, and "
    	+ "the tombstone falls in broken pieces into it.\n\n");
    call_out("claws", 3);
}

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Create a little more atmosphere...
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
void claws() {
    say("A pair of hands with long razor-sharp "
    	+ hir("claws") + " appear at the edge of the hole.\n\n");
    call_out("shatter", 3);
}

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Finally we get a ghoul, and possibly a tunnel entrance.
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
void shatter() {
    say("A hideous ghoul named " + get_clown_name() + " crawls forth from the grave and snarls at you.\n\n");
    move_object(clone_object(GHOUL_CLOWN), environment(this_object()));

	/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
	Find the ghoul we just created and alias the
	name so that can be used to see/attack/etc.
	=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
    find_living("clown")->set_short("A ghoulish clown named " + get_clown_name());
    find_living("clown")->set_alias(clown_name);
    find_living("clown")->set_name(get_clown_name());

	/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
	Chance of creating a tunnel entrance here.
	=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
    if (random(5) == 0) {
	    move_object(clone_object(ITEM_MISC_GRAVE), environment(this_object()));
    }

	/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
	Destroy the tombstone in the process.
	=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
    destruct(this_object());
}

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Get the nice, colorful version of the clown name.
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
string get_clown_name() {
	return UTIL->alternate(capitalize(clown_name), CH_BRY, 2) + NORM;
}
