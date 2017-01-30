/*
 * OTHERS command for the Shardak guild
 * who command..
 * by Drag and Bal
 */
#pragma strict_types
#include <security.h>
#include "../std.h"
inherit CMD;
int     *levels;

/*
012345670123456701234567012345670123456701234567
Name:       Level:  Gender: Guild:      Location: 
*/

int
level_sort(int a, int b)
{
    return levels[a] > levels[b];
}

int
query_level(object ob)
{
    int l;

    l = (int) ob->query_level();
    if(l >= APPRENTICE)
	l += 200;
    else
	if (l == 19)
	    l += (int) ob->query_extra_level();
    return l;
}

status
main(string arg)
{
    int             i, level, lvl, xlvl, *indexes, count;
    string          gname;
    mixed           *list, player;
    string          where, inside, str;

    i = sizeof(list = users());

    /*
     * to lower the number of call_others:
     * make an array of indexes to list
     * make an array of levels of the users
     * sort the indexes, using levels array for comparing
     */

    for (indexes = allocate(i); i--; ) indexes[i] = i;
    levels = map_array(list, "query_level", this_object());
    i = sizeof(indexes = sort_array(indexes, "level_sort", this_object()));

    level = (int) this_player()->query_level();

    write("\nName:       Level:  Gender: Guild:      Location:\n");
    write("[-----------------------------------------------------------------------------]\n");
    while (i--) {
	if (!environment(player = list[indexes[i]]) ||
            (int)player->query_invis())
	    continue;

	str = pad((string) player->query_name(), 12);

	lvl = levels[indexes[i]];
        if(lvl < 120) {
	    if (lvl >= 19)
		str += pad("19/" + (lvl - 19), -6);
	    else
		str += pad(lvl, -6);
	}
	else if ((lvl -= 200) < SENIOR)
	    str += "   wiz";
	else if (lvl < ELDER)
	    str += "  arch";
	else if (lvl < GOD)
	    str += " elder";
	else
	    str += "   god";

	str += player->query_pl_k() ? "* " : "  ";
	str += pad((string) player->query_gender_string(), 8);
        gname = (string) player->query_guild_name();
        if(gname == "Knights Templar") gname = "Knights";
        str += pad(gname || "None", 12);
	where = (string) environment(player)->short();
	if (!stringp(where))
	    where = "The unknown";
	if (living(environment(player)) && environment(environment(player))) {
	    inside = (string) environment(environment(player))->short();
	    if (stringp(inside)) {
		where += " (" + inside + ")";
		count += 2;
	    }
	}
	if (index(where, 27) >= 0) str += where;
	else str += where[0..36];
	write(str + "\n");
    }
    write("[-----------------------------------------------------------------------------]\n");
    levels = 0;
    this_player()->add_spell_point(-count);
    return 1;
}
