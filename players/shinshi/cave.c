/*
 * Shardak guild - (tm) Dragnar/John
 * Cave is (c) Balowski/Rasmus, March 12th 1995.
 * The first actual guild room.
 * The ghost is a source of information
 * log:
 * 950415 - ensure that joiners are at least level 3
 * 950421 - inherit ROOM
 */
#pragma strict_types
#include "/players/balowski/lib.h"
#include "../def.h"
#include "../macros.h"

inherit ROOM;

object  *Invited;               /* list of people allowed to join */

void
create()
{
    ::create();
    set_short("A cave");
    set_long("\
An ominously cold wind rushes out of the dark depths of the cave\n\
chilling you despite the brilliance of the sun's rays. Within, a\n\
dangerously steep carved staircase winds its way deeper into the\n\
womb of the rock. You can go either in or out.\n");
    set_exits(([
	"out" : DEST,
	"in" : this_object(),
	"west" : this_object(),
    ]));
    set_items(([
      "staircase" : "\
A roughly carved staircase winds its way through the maze of rock\n\
into the cave you see before you.\n",
    ]));
    set_light(1);
    set_property("fight area", 1);
    set_property("no teleport", 1);  
}

void
reset(int arg)
{
    object monster;

    ::reset(arg);
    if (!present("ghost", this_object())) {
	tell_room(this_object(), "A ghost drifts into the cave.\n");
	monster = clone_object(PATH + "ghost");
	monster->move_player("in#" + file_name( this_object()));
    }
    if (!present("shadow demon", this_object())) {
        monster = clone_object("/obj/monster");
	monster->set_name("shadow demon");
	monster->SetMultipleIds(({"demon", "creature", }));
	monster->set_gender("creature");
	monster->set_short(0);  /* invisible */
	monster->set_long("\
As your eyes grow accustomed to the darkness and you scrutinize, a\n\
dark skinned creature is noticeable in the shadows. Its warped, yet\n\
human-like, body is in perfect condition and its hands are fitted\n\
with long claws. This demon was created by Shardak to guard the\n\
entrance to his apartments against trespassers.\n");
	monster->set_level(18);
	monster->set_ac(14);
	monster->set_wc(30);
	monster->set_hp(400);
	monster->set_al(-150);  /* low evil */
	monster->set_chance(15);
	monster->set_spell_dam(30);
	monster->set_spell_mess1("The demon's claws flash in the darkness.");
	monster->set_spell_mess2("The demon swipes you with its claws.");
	monster->set_dead_ob(this_object());
	move_object(monster, this_object());
    }
}

status
monster_died(object monster)
{
    CHANNELD->broadcast("You hear the death rattle of the Shadow demon.\n",
			0, "[Servants]");
    return 0;
}

void
init()
{
    ::init();
    add_action("join", "join");
    add_action("rejoin", "rejoin"); 
}

status
west()
{
    if (this_interactive()->is_player() && !friend(this_interactive())) {
	write("Only the servants and their allies may enter.\n");
	return 1;
    }
    this_player()->move_player("in#" + PATH + "bar");
    return 1;
}

status
in()
{
    /*
     * only let guild members in, also if riding dragon/whatever
     * this_interactive() returns 'the player who pressed enter'
     */
    if (this_interactive()->is_player()
    &&  (!friend(this_interactive()) && !servant(this_interactive()))) {
	if (present("shadow demon", this_object())) {
	    write("\
A tall dark creature steps out of the shadows and says: No visitors.\n\
It disappears back into the darkness.\n");
	    return 1;
	}
	CHANNELD->broadcast("An intruder has entered the guild complex.\n",
			    1, "[Servants]");
	SHARDAK->add_intruder(this_player());
    }

    if (present("shadow demon", this_object()))
	write("You slip by the Shadow demon.\n");
    this_player()->move_player("in#" + PATH + "grotto");
    return 1;
}

void
invited(object p)
{
    if (!Invited)
	Invited = ({ p });

    if (member_array(p, Invited) == -1)
	Invited += ({ p });
}

status
join()
{
    if (!interactive(this_player()))
	return 0;               /* keep kids out */

    if (!Invited || member_array(this_player(), Invited) == -1) {
	write("Only those invited may join.\n");
	return 1;
    }
    if ((int) this_player()->query_guild_exp()) {
	write("You still have bonds to another guild.\n");
	return 1;
    }
    if ((int) this_player()->query_level() < 5) {
	write("You must attain level five before you can join.\n");
	return 1;
    }
    if (first_inventory(PATH + "joinroom")) {
	write("Someone else is being initiated at the moment.\n");
	return 1;
    }
    if (present("allymark", this_player()))
	command("leave alliance", this_player());
    write( "\
You feel strange..\n\
Everything goes hazy and your body suddenly becomes light as a feather.\n\
As if commanded, you lift up and travel into and through the rock.\n\
You reach a small hollow with nothing but a bowl filled with a dark\n\
red fluid placed on the floor.\n");
    say(this_player()->query_name() + " vanishes.\n");
    move_object(this_player(), PATH + "joinroom");
    return 1;
}

status
rejoin()
{
    object      gob;

    if (present(OBJID, this_player()))
	return 0;               /* no rejoin if already inside */

    gob = clone_object(GUILDOBJ);
    move_object(gob, this_player());
    if (gob->restore_me()) {
	write("Restoring mark ...\n");
	return 1;
    }
    write("You are not registered as a member of the guild.\n\
Mail Vertebraker if this is wrong.\n");
    destruct(gob);
    return 1;
}
