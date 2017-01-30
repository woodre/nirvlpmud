#pragma strict_types, verbose_errors

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
General Notes: A heal that changes how it distributes the points based on which
action the player chooses to use. The number of charges is also higher than
normal, but the player must enable those charges by adding souls (corpses).
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Inherits
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
inherit "/obj/generic_heal.c";
inherit "/players/darkfire/obj/color";

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Includes
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
#include <ansi.h>
#include "../../circus.h"

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Global Variables
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
int max_heal;
int max_charges;
int max_souls;
int curr_souls;

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Method Declarations
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
void reset(int arg);
void init();
int id(string str);
int shuffle_deck(string str);
int cut_deck(string str);
int turn_card(string str);
int add_soul(string str);
int query_souls();
void add_souls(int number);

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Initial construction of the object.
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
void reset(int arg) {
	::reset(arg);
	if (arg) return;

	max_heal = 100;
	max_charges = 100;
	max_souls = 100;
	curr_souls = 0;

	set_name("deck");
	add_alias("cards");
	add_alias("tarot");
	add_alias("card");

	set_short("A deck of Tarot cards.");

	set_long(UTIL->wrap("A beautiful deck of Tarot cards which you may "
		+ "shuffle, cut, deal, or ensoul. The deck currently holds "
		+ query_souls() + " souls which may be converted into futures for "
		+ "a reasonable fee by the right person. Perhaps someone who deals "
		+ "in futures on a regular basis?")
		+ "\n"
	);

	/* The Tarot deck contains your potential futures. */
	set_type("potential futures");

	set_heal(50,50);
	set_charges(30);

	set_stuff(6);
	set_soak(6);
	set_value(700);
}

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Handle a player coming into contact with it.
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
void init() {
	add_action("shuffle_deck", "shuffle");
	add_action("cut_deck", "cut");
	add_action("turn_card", "turn");
	add_action("turn_card", "deal");
	add_action("add_soul", "ensoul");
}

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
See if a string matches the name or any aliases of the object.
NOTE: This should really be in a base object class. I'd use mine but
I don't want to mix it into the generic heal quite yet.
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
int id(string str) {
	return (str == query_name() || (member_array(str, query_alias()) > -1));
}

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Shuffling the deck makes your future hold more potential. This heals SPS.
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
int shuffle_deck(string str) {
	if (!id(str)) {
		return 0;
	}
	set_msg("You shuffle the deck of Tarot cards, adding to your potential future paths.\n");
	set_msg2(" shuffles the deck of Tarot cards, adding to their potential future paths.\n");
	set_heal(0, max_heal);

	return cmd_imbibe("deck");
}

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Cutting the deck divides your fortunes. This heals SPS and HPS.
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
int cut_deck(string str) {
	if (!id(str)) {
		return 0;
	}
	set_msg("You cut the deck of Tarot cards, dividing your fortunes evenly.\n");
	set_msg2(" cuts the deck of Tarot cards, dividing their fortunes evenly.\n");
	set_heal(max_heal/2, max_heal/2);

	return cmd_imbibe("deck");
}

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Dealing from the deck shows you a path to victory. This heals HPS.
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
int turn_card(string str) {
	if (!id(str)) {
		return 0;
	}
	set_msg("You deal one card from the Tarot deck, revealing a path to victory.\n");
	set_msg2(" deals one card from the Tarot deck, revealing a path to victory.\n");
	set_heal(max_heal, 0);

	return cmd_imbibe("deck");
}

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Capturing a soul adds more potential charges to the deck, up to a maximum.
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
int add_soul(string str) {
	object corpse;

	if (!id(str)) {
		return 0;
	}

	corpse = present("corpse", environment(this_player()));

	if (corpse) {
		if (curr_souls < max_souls) {
			/* Should bigger kills be worth more? Yes, but how much? */
			write("Souls: " + curr_souls);
			add_souls(1);
			write("Souls: " + curr_souls);
			destruct(corpse);
			write("You add a soul to the deck.\n");
			write("Souls: " + curr_souls);
		} else {
			write("The deck cannot contain any more souls.\n");
		}
	} else {
		write("There is no corpse present to harvest a soul from.\n");
	}
	return 1;
}

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Adds a trapped soul to the deck, ensuring the count doesn't go above a maximum.
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
void add_souls(int number) {
	curr_souls = curr_souls + number;
	if (curr_souls > max_souls) {
		curr_souls = max_souls;
	}
}

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Returns the number of trapped souls.
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
int query_souls() {
	return curr_souls;
}
