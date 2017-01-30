/*
 * Storm spell for Shardak guild
 * By Dragnar, modified by Balowski
 */
#pragma strict_types
#include "../std.h"
#include "../def.h"
#include "../macros.h"
inherit CMD;

#define COST 59

status
main(string str)
{
    object          storm;

    if (str)
	return 0;

    needrank(8);
    needmana(COST);
    if (storm = present("lightningspell", this_player())) {
	write("You can only control one storm at a time.\n");
	return 1;
    }

    write("You raise your hands to the sky and summon a deadly storm.\n");
    say(capname + " raises " + this_player()->query_possessive() +
	" hands to the sky and summons a storm.\n");

    storm = clone_object(OBJDIR + "stormob");
    move_object(storm, this_player());
    this_player()->add_spell_point(-COST);
    return 1;
}
