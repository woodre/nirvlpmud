/* 
 * Shardak guild - (tm) Dragnar/John
 * Priestess is (c) Balowski/Rasmus, April 9th 1996.
 * Last change: August 12th '96
 */
#include "/players/balowski/lib.h"
#include "../def.h"
#include "../tasks.h"

inherit "/obj/monster";
object Baby, Solvee;

reset(x)
{
    if(x) return;
    ::reset();
    set_race("human");
    set_name("priestess");
    set_gender("female");
    set_short("A priestess");
    set_long("\
The priestess is draped in a deep red robe with golden embroideries\n\
along the selvage. She has swarty skin and jet black hair, which is\n\
neatly arranged by a heavy hair slide made of gold.\n\
");
    set_level(17);
    set_al(-800);
}

void DoTell(mixed *arr) {
    object receiver;
    string text;
    if (objectp(receiver = arr[0]) && stringp(text = arr[1])) {
	tell_object(receiver, text);
    }
}

void long(string str)
{
    ::long(str);
    call_out("DoTell", 2, ({ this_player(),
"The priestess turns towards you and greets you with a crooked smile.\n"
    }));
}

void catch_tell(string str)
{
    string      who, what, text;
    object      mark;

    if (!(str && this_player() && (mark = present(GUILD_ID, this_player()))))
	return;
    
    if (sscanf(str, "%s says: %s\n", who, what) == 2 ||
	sscanf(str, "%s asks: %s\n", who, what) == 2 ||
	sscanf(str, "%s tells you: %s\n", who, what) == 2) {

	if (sscanf(lower_case(what), "%strial", who)) {
	    if (mark->query_solved(CHILD_TASK))
	      text= "The priestess answers, \"You have passed the last trial.\"\n";
	    else
	      text = read_file(ABSPATH + "child_task");
	}
	else return;
	call_out("DoTell", 2, ({ this_player(), text }));
    }
}

add_weight(w)
{
    if (this_player() && this_player() != this_object())
	call_out("received", 1, this_player());
    return ::add_weight(w);
}

void sacrifice(int seqno);

void
received(object from)
{
    object ob;

    if (!(ob = first_inventory(this_object()))) return;

    if (objectp(Baby) || !ob->is_kid()) {
	tell_object(from, "The Priestess scowls at you.\n");
	tell_room(environment(),
		  "The Priestess drops " + ob->query_name() + ".\n");
	if (transfer(ob, environment()))
	  destruct(ob);
	return;
    }

    if((int)ob->query_level() == 1)
    {
	Baby = ob;
	Solvee = from;
	call_out("sacrifice", 2, 1);
    }
    else {
	tell_object(from, "The Priestess speaks to you, \"The child must be newly born.\"\n");
	tell_room(environment(),
		  "The Priestess drops " + ob->query_name() + ".\n");
	if (transfer(ob, environment()))
	  destruct(ob);
    }
}

void
sacrifice(int seqno)
{
    object ob;

    if (!objectp(Baby)) {
	tell_room(environment(), "The ceremony is cancelled.\n");
	return;
    }
    switch (seqno) {
    case 1:
	tell_room(environment(), "\
The Priestess smiles wickedly and turns towards the statue of Baal\n\
with the newborn clutched in her arms.\n\n");
	break;

    case 2:
	tell_room(environment(), "\
The Priestess raises the newborn in the air, presenting the sacrifice\n\
to the statue of Baal.\n\
The light lowers and a low droning sound emerges from the silence.\n\n");
	break;

    case 3:
	tell_room(environment(), "\
The room grows warmer and the brass statue is starting to glow slightly\n\
in the dim light. With a grating noise it begins to lower its arms.\n\n");
	if (ob = find_object("room/church")) {
	    tell_room(ob, "\
You hear a grating noise from deep down in the pit.\n\
A sudden spurt of flame from below sends you staggering back.\n\n");
	}
	break;
	
    case 4:
	tell_room(environment(), "\
The fire within the statue is making it glow orange. Flames are licking\n\
the lips of Baal's demanding mouth.\n\
The Priestess carefully places the child in the extended palms of Baal,\n\
and the arms slowly begin to lift the child up.\n\n");
	if (ob = find_object("room/church")) {
	    tell_room(ob, "\
You hear the distant sound of beating drums.\n\
Flames are now constantly licking the sides of the pit.\n\n");
	}
	break;
	
    default:
        tell_room(environment(), "\
Right before the hands of Baal reaches his mouth, the child topples over\n\
and plunges into the flames. The fire blazes up and the raging inferno\n\
drowns out the cries of the burning child.\n\n");
        tell_room(environment(), "\
Baal's hands reach their original position and cover his mouth completely.\n\
The statue stops glowing as the fire dies out.\n\n");

	if (ob = find_object("room/church")) {
	    tell_room(ob, "\
A huge ball of fire flies from the muzzle of the pit and up under the\n\
arches of the church. Immediately the flames in the pit vanish.\n\
Somehow you know that a newborn child has been sacrificed.\n");
	}
	if (objectp(Baby) && objectp(Solvee)
	&&  (ob = present(GUILD_ID, Solvee))) {
	    tell_object(Solvee, "Baal has accepted your sacrifice.\n");
	    ob->add_solved(CHILD_TASK);
	    ob->save_me();
	}
	if (objectp(Baby)) destruct(Baby);
	return;
    }
    call_out("sacrifice", 8, seqno + 1);
}
