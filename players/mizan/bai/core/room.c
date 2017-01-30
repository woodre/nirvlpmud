/* Modified for use as cell rooms in Mizan's maze */

query_light() {
    return set_light(0);
}
/*
 * Nirvana Room Inherit
 * Authored by Vertebraker@Nirvana
 * <tmieczkowski@gmail.com>
 * Started: 8-27-03
 *
 */

#include "/room/clean.c"
#define ROOM_DM "/players/mizan/bai/daemons/gridDM.c"
#define ROOM_HOME "/players/mizan/opl/daemons/gridboxDM"

/* An array with destinations and directions: "room/church", "north" ... */
string *dest_dir;

/* Short description of the room */
string short_desc;

/* Long description of the room */
string long_desc;

/* Special items in the room. "table", "A nice table", "window", "A window" */
string *items;

/* Fact about this room. ex: "no_fight", "no_steal" */
mixed property;

/* No castles are allowed to be dropped here */
int no_castle_flag;

/* Custom exits flag */
int custom_exits;

/* This is the icon we use for our grid. Mizan specific code. */
string terrain_icon;
string current_icon;

#include "/obj/ansi.h"
#include "/room/lib/func.h"
#include "/room/lib/sensory.h"

/* I rigidly enforce no players under L19 in the maze with this modified init(). */
void init()
{
    int i;
    object enteringPlayer;
    object leader;
    mixed followers;

    if (this_object()->query_property("fight_area") &&
            (enteringPlayer=this_player()) && enteringPlayer->is_player())
        enteringPlayer->set_fight_area();

    if (this_object()->query_property("spar_area") &&
            (enteringPlayer=this_player()) && enteringPlayer->is_player())
        enteringPlayer->set_spar();

    if (!dest_dir) return;
    i = 1;
    while (i < sizeof(dest_dir))
    {
        add_action("move", dest_dir[i]);
        i += 2;
    }

    ROOM_DM->render_icon(this_object());

    /* hardcoded level check */
    if(enteringPlayer->query_level() < 19 && enteringPlayer->is_player())
    {
        /* get the leader and force a follow stop. this section mimics _follow.c */
        leader = (object) enteringPlayer->query_leader();
        followers = (mixed) enteringPlayer->query_followers();
        if(leader)
        {
            write("You stop following "+ leader->query_name() + ".\n");
            leader->remove_follower((string) enteringPlayer->query_real_name());
        }
        call_other(enteringPlayer, "end_follow_calls");

        if(followers && sizeof(followers))
        {
            write("You disallow all follows.\n");
            call_other(enteringPlayer, "clear_followers");
        }

        tell_object(enteringPlayer, "You get the feeling that you are not supposed to be here.\nYou are less than player level 19.\n");
        enteringPlayer->move_player("out#/room/wild1.c");
    }

}

status id(string str)
{
    return ((items && member_array(str, items) > -1) ||
            (dest_dir && member_array(ROOM_DM->convert_dir(str), dest_dir) > -1));
}

int check_light()
{
    return set_light(0);
}

varargs void long(string str)
{
    int i;
    if ((set_light(0) <= 0) && !present("dark_sight_object", this_player()))
    {
        write("It is dark.\n");
        return;
    }

    if (!str)
    {
        write(long_desc);
        if (custom_exits)
            return;
        if (!dest_dir)
            write("    No obvious exits.\n");
        else
        {
            int s;
            i = 1;
            if ((s=sizeof(dest_dir))==2)
                write("\
    There is one obvious exit:");
            else
                write("\
    There are "+(string)this_object()->convert_number(s/2)+" obvious exits:");
            while (i < s)
            {
                write(" " + dest_dir[i]);
                i += 2;
                if (i == s-1)
                    write(" and");
                else if (i < s)
                    write(",");
            }
            write("\n");
        }
        return;
    }
    if (items && (i = member_array(str, items)) > -1)
        write(items[i+1]+".\n");
}


/*
 * Does this room has a special property ?
 * The 'property' variable can be both a string and array of strings.
 * If no argument is given, return the 'property' variable.
 */

mixed query_property(string str)
{
    int i;

    if (!str)
        return property;
    if (!property)
        return 0;
    if (stringp(property))
        return str == property;

    if (pointerp(property))
        return (member_array(str, property) > -1);
}

void set_property(mixed str)
{
    property = str;
}

void add_property(mixed str)
{
    if (!str)
        return;
    if (!property)
        property=str;
    if (stringp(property))
        property=( { property, str });
    if (pointerp(property))
        property += ( { str });
}

void remove_property(mixed str)
{
    if (!str)
        return;
    if (stringp(property) && property==str)
        property=0;
    if (pointerp(property))
    {
        if (member_array(str, property) > -1)
            property -= ( { str });
        if (!sizeof(property))
            property = 0;
    }
}



status move(string str)
{
    int i;
    if ((i = member_array(query_verb(), dest_dir)) > -1)
    {
        /* 08/07/07 Earwax: ghetto fix for mages doing hit/run tactic */
        if ((string)this_player()->query_guild_name() == "mage"
                && (int)present("spellbook", this_player())->query_cmd_count_max())
        {
            write("You are still recovering from spellcasting and can't move yet!\n");
            return 1;
        }
        /* add by mizan to open up terrain a bit */
        call_other(dest_dir[i-1], "???");
        call_other(ROOM_DM, "load_neighbors", dest_dir[i-1]);

        this_player()->move_player(dest_dir[i] + "#" + dest_dir[i-1]);
        return 1;
    }
}

string short()
{
    int i, s;
    string temp;
    /* <= conversion by verte 9.14.01 */
    if ((set_light(0) > 0) || (this_player() && environment(this_player()) == this_object() && present("dark_sight_object", this_player())))
    {
        temp = short_desc + " [";
        if (!dest_dir) temp += "no exits";
        else if ((s=sizeof(dest_dir)) >= 12) temp += "many exits";
        else
            for (i=1;i<s;i+=2)
            {
                temp += (string)this_object()->translate_exit(dest_dir[i]);
                if (i < s-2)
                    temp += ",";
            }
        temp += "]";
        return temp;
    }
    return "Dark room";
}

string translate_exit(string fullDirection)
{
    switch (fullDirection)
    {
    case "north":
        return "n";
    case "south":
        return "s";
    case "east":
        return "e";
    case "west":
        return "w";
    case "up":
        return "u";
    case "down":
        return "d";
    default:
        return fullDirection;
    }
}

status query_drop_castle() {
    return no_castle_flag;
}
string query_short() {
    return short_desc;
}
string * query_dest_dir() {
    return dest_dir;
}

/* mizan addition - so that roaming monsters only stay in the discovered.loaded
 * parts of the maze, and don't wander to open it up fully.
  */
string * query_dest_dir_available() {
    string *temp;
    object ob;
    int i;
    int j;

    temp = ( { "none", "none", "none", "none" });

    i = 0;
    j = 0;
    while (i < sizeof(dest_dir))
    {
        ob = find_object(dest_dir[i]);
        /*        if(ob && !ob->query_npc_traversable()) temp[j] = dest_dir[i + 1]; */
        if (ob && ob->query_npc_traversable()) temp[j] = dest_dir[i + 1];
        /* temp[j] = dest_dir[i + 1]; */
        i += 2;
        j ++;
    }

    return temp;
}

string query_long() {
    return long_desc;
}

mixed convert_number(int inputNum)
{
    if (inputNum > 9)
        return "lot of";
    else return ROOM_DM->query_number_index(inputNum);
}

query_numbers() 
{
    return ROOM_DM->query_numbers();
}

string realm()
{
    if (query_property("no_teleport")) return "NT";
    if (query_property("no_follow")) return "LA";
}

status okay_follow()
{
    /* change by mizan to allow follow, but no teleport */
    /*    if (realm() == "NT" || query_property("no_follow")) return 0; */
    return 1;
}

varargs status exit(object exitingPlayer)
{
    if (query_property("fight_area") && exitingPlayer)
        exitingPlayer->clear_fight_area();
    if (query_property("spar_area") && exitingPlayer)
        exitingPlayer->rm_spar();
    if (exitingPlayer) exitingPlayer->invs_counter();
    /* mizan addition */
    if (exitingPlayer) ROOM_DM->render_icon(this_object());
}

status query_no_fight() {
    return query_property("no_fight");
}
status query_spar_area() {
    return query_property("spar_area");
}
status query_NM() {
    return query_property("no_magic");
}

reset() {
  move_object(this_object(), ROOM_HOME);
}



set_dest_dir(x) {
    dest_dir = x;
}
set_items(x) {
    items = x;
}

set_short(x) {
    short_desc = x;
}
set_long(x) {
    long_desc = x;
}

string query_current_icon() {
    return current_icon;
}

void set_current_icon(string arg) {
    current_icon = arg;
}

string query_terrain_icon() {
    return terrain_icon;
}

