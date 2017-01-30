/* 
 * Shardak guild - (tm) Dragnar/John
 * Dragon Trainer is (c) Balowski/Rasmus, July 5th 1995.
 * Last change:
 * One day I must make this a little more generic..
 */
#include "/players/balowski/lib.h"
#include "../def.h"
#include "../tasks.h"

inherit "/obj/monster";

string          text;           /* reply from catch_tell */
object          receiver;       /* talk to this object */

reset(x)
{
    if(x) return;
    ::reset();
    set_race("human");
    set_name("the keeper");
    set_alias("bowed man");
    set_alt_name("man");
    set_gender("male");
    set_short("A bowed man is sitting on the stool");
    set_long("\
The small bowed man is clad in padded armour. His scarred and furrowed\n\
face makes him look very old, but his bright blue eyes are quite alive\n\
and following your every move.\n");
    set_level(15);
    set_ac(10);
    set_wc(20);
    set_hp(600);
    set_al(-100);
    set_ghost(1);
}

void DoTell(mixed *arr) {
    object receiver;
    string text;
    if (objectp(receiver = arr[0]) && stringp(text = arr[1])) {
	tell_object(receiver, text);
    }
}

void catch_tell(string str)
{
    string      who, what;
    object      mark;

    if (this_player())
	mark= present(GUILD_ID, this_player());
    if (!mark || !str)
	return;

    if (sscanf( str, "%s says: %s\n", who, what) == 2 ||
	sscanf( str, "%s asks: %s\n", who, what) == 2 ||
	sscanf( str, "%s tells you: %s\n", who, what) == 2) {

	if (sscanf(lower_case(what), "%strial", who)) {
	    if (mark->query_solved(DRAGON_TASK))
	      text = "\
The man answers, \"Your next trial awaits in the temple of Baal.\"\n";
	    else
	      text = read_file(ABSPATH + "dragon_task");
	    call_out("DoTell", 2, ({ this_player(), text }));
	}
	else if (what == "I am ready") {
	    call_out("enter_pit", 2, this_player());
	}
    }
}

void enter_pit(object who)
{
    object room, beast, opp;

    /* see if the pit is loaded at all */
    if (room = find_object(PATH + "pit")) {

	/* see if the beast has been slain */
	if (!(beast = present("beast", room))) {
	    tell_object(who, "\
The bowed man peers intently into the darkness in the pit below. He\n\
shakes his head and says, \"My champion is regenerating. You must wait.\"\n");
	    return;
	}

	/* see if the beast is fighting */
	if ((opp = (object) beast->query_attack()) && present(opp, room)) {
	    tell_object(who, "\
The bowed man grins sinisterly as he speaks, \"My champion is already\n\
busy tearing somebody apart. Your wait will not be a long one.\"\n");
	    return;
	}
    }

    command("pull lever");
    tell_object(who, "\
Somebody sends you tumbling down the hole with a push in your back.\n");
    command("down", who);
}
