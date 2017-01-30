/*
 * Shardak guild is (tm) Dragnar/John
 * Change log:
 * 950525 - created
 */
inherit "/players/balowski/std/random/room";
#include "/players/balowski/lib.h"
#include "../def.h"
#include "../tasks.h"


object          beast;          /* the monster residing here */

void
create()
{
    ::create();
    set_short("The pit");
    set_long("\
You are in the pit. A little light is seeping in through the grating\n\
high above you. Underneath your feet bones and broken weapons lie\n\
scattered, half covered in the soft filth on the floor.\n\
There is no way out.\n");
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
    ]));
    set_property("no teleport", 1);
    set_property("fight area", 1);
    set_light(1);
  if(!beast) {
    beast = clone_object(PATH + "beast");
    beast->move_player("in#"+file_name(this_object()));
  }
}

/*
void
reset(int arg)
{
    ::reset(arg);
    if (!beast) {
	beast = clone_object(PATH + "beast");
	beast->move_player("in#" + file_name(this_object()));
    }
}
*/

/*
 * Fully heal the beast when somebody enters
 */
void
init()
{
    ::init();
    add_action("null", "xcharm");	/* succubus peace spell */
    if(beast && this_player()->is_player())
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
