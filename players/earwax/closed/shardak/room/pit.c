/*
 * Shardak guild is (tm) Dragnar/John
 * Change log:
 * 950525 - created
 * 030715 - added color, and tweaked desc [linus]
 * 030719 - tweaked it some more [linus]
 */

#pragma strict_types
#include "/players/balowski/lib.h"
#include "../include/def.h"
#include "../include/tasks.h"
#include "../include/ansi.h"

inherit ROOM;

object beast;          /* the monster residing here */

void
create()
{
    ::create();
    set_short(RED+"The pit"+NORM);
    set_long(HIK+"\
A little light is seeping in through the grating high above.\n\
The walls of this pit are bare and smooth, as if to prevent\n\
escape.  The floor is littered with bones and broken weapons,\n\
half covered in soft filth.\n\
There is no way out.\n"+NORM);
    set_items( ([
"grating" : "\
It looks like somebody is watching you through it. Anyway, it is too\n\
high up to reach.\n",
"bones" : "\
Some are smashed beyond recognition, but most are definitely of human\n\
origin. A fractured skull long seperated from its body is grinning at\n\
you from the ground.\n",
"weapons" : "\
You see worn and broken blades and axe heads, hilts of swords with\n\
patterns and runes inlaid with gold and silver. All broken and no\n\
longer of any use.\n",
({ "filth","floor", }) : "\
Soft dirt and dust covers the bones and weapons on the floor of\n\
the pit.\n",
    ]));
    set_property("no teleport", 1);
    set_property("fight area", 1);
    set_light(1);
}

void
reset(int arg)
{
    ::reset(arg);
    if (!beast) {
	beast = clone_object(PATH + "beast");
	beast->move_player("in#" + file_name(this_object()));
    }
}

/*
 * Fully heal the beast when somebody enters
 */
void
init()
{
    ::init();
    add_action("null", "xcharm");	/* succubus peace spell */
    if (beast)
	beast->heal_self(10000);
}

status null(string arg) { write("Nothing happens.\n"); return 1;}

/*
 * Give some cool messages when slaying the beast
 */
void
beast_died(object who)
{
    /* the beast calls this function to initiate end sequence */
    call_out("reward", 2, who);
}

void
reward(object who)
{
    string name;
    object gob;

    if (who && (gob = present(OBJID, who))) {
	gob->add_solved(DRAGON_TASK);
	gob->save_me();

	name = (string) who->query_name();
	say("\
The corpse of the beast glows briefly.\n\
Bright purple sparks spring from the corpse into " + name + ".\n\
For several seconds the ozone filled air crackles with energy,\n" +
name + " shines with power.\n\n", who);
	tell_object(who, "\
The corpse of the beast glows briefly.\n\
Bright purple sparks spring from the corpse into your chest.\n\
For several seconds the ozone filled air crackles with energy.\n\
Your charged body shines with power.\n\n");

	call_out("wear_off", 25, who);
    }
    call_out("empty_room", 10);
}

void
wear_off(object who)
{
    object man;

    if (who) {
	tell_object(who, "The glow surrounding your body disappears.\n");
	tell_room(environment(who), "The glow surrounding " +
		(string) who->query_name() + " disappears.\n", ({ who }));

	if (man = present("the keeper", environment(who))) {
	    tell_object(who, "\
The little man smiles at you and says, \"Well done. You have earned\n\
your reward. The energy from the beast blended with your soul and\n\
has given you the ability to summon a dragon to this plane. Look in\n\
your tome for further instructions.\"\n");
	    tell_object(who, "\
He continues, \"You must also choose a name for your dragon. When you\n\
have made your decision, come back to me and 'name dragon'.\"\n");
	}
    }
}

void
empty_room()
{
    object ob, next;

    tell_room(this_object(), "\
The grating rumbles open above you.\n\
A ladder falls down and you are compelled to climb up.\n\n");
    /* move everybody up */
    next = first_inventory(this_object());
    while (ob = next) {
	next = next_inventory(ob);
	ob->move_player("up#" + PATH + "stable");
    }
}

/* Rooms long description.  No need for exits.  Shardak trial room */

void
long(string arg) {
 if(!arg) {
  if((int)this_player()->query_brief() != 2)
   write(RED+"The pit\n"+NORM);
    ::long(arg);
     return;
 }
 else ::long(arg);
}
