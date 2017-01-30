/* 
 * Help system for Shardak guild - (tm) Dragnar/John
 * Help system is (c) Balowski/Rasmus, January 22nd 1995.
 * Change log:
 * 950124 - Bal.. something
 * 950423 - moved to cmds\info.c (load on call)
 * 950430 - level check, 'help guild' moved to file, move to cmds\help.c
 * 950505 - playing with alists for fast search
 *          (avoids problems with ".." too)
 */
#pragma strict_types
#include "../def.h"
#include "../std.h"
inherit CMD;

mixed           *list;

status
main(string str)
{
    int         i, level;
    string x;

    if (!str)
	return 0;
    if (str == "conjure flame" || str == "conjure flames" || str == "conjure fire") str = "conjure";
    if (str == "call merchant") str = "call";
    if (str == "guild topics") {
	level = (int) this_player()->query_guild_rank();
	x = "";
	for (i = 0; i < sizeof(list[0]); i++) {
	    if (level >= list[2][i]) {
		x += pad(list[0][i], 10);
	    }
	}
	print(x);
	write("\n");
	return 1;
    }
    if ((i = assoc(str, list[0])) == -1) {
	notify_fail("You search in vain for that information.\n");
	return 0;
    }

    if ((int) this_player()->query_guild_rank() >= list[2][i]) {
	write( "\
You flip through the pages and find the '" + str + "' section.\n\
Eagerly you begin reading...\n");
	cat(HELPDIR + list[1][i]);
    }
    else {
	write( "\
You are not able to understand such strong magik before you attain\n\
rank " + list[2][i] + ".\n");
    }
    return 1;
}

void
reset(int arg)
{
    string      *helps;
    string      *keys;
    int         *ranks;

    if (!list) {
	helps = files(HELPDIR);
	helps = filter_array( helps, "notempty", this_object());
	ranks = map_array( helps, "getrank", this_object());
	keys = map_array( helps, "getkey", this_object());

	list = order_alist( keys, helps, ranks);
    }
}

status
notempty(string file)
{
    return ((file[0] != '.') && (file_size( HELPDIR + file) > 0));
}

int
getrank(string file)
{
    string      name;
    int         rank;

    sscanf(file, "%s.%d", name, rank);
    return rank;
}

string
getkey(string file)
{
    string      name;
    int         rank;

    if (sscanf(file, "%s.%d", name, rank))
	return name;
    else
	return file;
}
