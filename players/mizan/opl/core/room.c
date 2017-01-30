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

/* No exits shown flag */
int no_exits;

/* Custom exits flag */
int custom_exits;

/* Handling number of exits */
string *numbers;

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

    this_object()->render_icon();

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

string convert_dir(string str)
{
    /* we don't need all the extra directions */
    switch (str)
    {
    case "n":
        return "north";
    case "e":
        return "east";
    case "s":
        return "south";
    case "w":
        return "west";
    case "d":
        return "down";
    case "u":
        return "up";
    }
    return str;
}

status id(string str)
{
    return ((items && member_array(str, items) > -1) ||
            (dest_dir && member_array(convert_dir(str), dest_dir) > -1));
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
        if (!dest_dir || no_exits)
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
        call_other(dest_dir[i-1], "load_neighbors");

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
        if (!dest_dir || no_exits) temp += "no exits";
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

string convert_number(int inputNum)
{
    if (!pointerp(numbers))
        numbers = (string*)this_object()->query_numbers();
    if (inputNum > 9)
        return "lot of";
    return numbers[inputNum];
}

string * query_numbers()
{
    if (!numbers)
    {
        if (object_name(this_object()) == "room/room")
            numbers = ( {"no", "one", "two", "three", "four", "five",
                         "six", "seven", "eight", "nine"
                        });
        else
            numbers = (string*)"/room/room"->query_numbers();
    }
    return numbers;
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
    if (exitingPlayer) this_object()->render_icon();
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

reset() { }  /* left in for solidarity */



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


/* additions by mizan specific to grid engine */

/* This function is called whenever init() is triggered locally by the room.
 * It serves to mark whatever the "dominant" icon in the room is at the time.
 * The item which is set by this function is then called later by the function
 * render_map() in gridDM.c, which builds up a listing of what terrain types
 * are to be depicted in the top-down map. Shit, I really didn't make a whole
 * lot of sense explaining that, did I?
 */
void render_icon()
{
    object ob;

    /* if we are not inside this room, discard */
    if (!this_player()) return;
    if (this_player() &&
            environment(this_player()) &&
            (environment(this_player()) != this_object())) return;

    ob = first_inventory(this_object());

    /* certain properties of this cell will override whatever
      * is occupying it.
     */
    /* not supported yet
     * if(is_portal) return TERRAIN_DM->get_icon(10);
     */

    /* our current icon is our terrain icon, unless something below overrides it. */
    current_icon = terrain_icon;
    while (ob)
    {
        /* the order of operations is simple */
        if (ob->is_boss()) {
            current_icon = BYEL + HIR + "*" + NORM;
            break;
        }
        else if (ob->is_miniboss()) {
            current_icon = BYEL + RED + "*" + NORM;
            break;
        }
        else if (ob->is_player() && ob != this_player()) {
            current_icon = BYEL + BLK + "@" + NORM;
            break;
        }

        else if (ob->is_vehicle()) {
            current_icon = BYEL + HIW + "O" + NORM;
            break;
        }
        /*		else if(ob->is_player() && !ob->query_invis()) { current_icon = BYEL + HIC + "*" + NORM; break; } */
        /*		else if(ob->is_npc()) return TERRAIN_DM->get_icon(8); */
        else if (ob->is_exit_blocker()) {
            current_icon = BYEL + RED + "*" + NORM;
            break;
        }
        else if (ob->query_value() > 100 || ob->is_money()) {
            current_icon = BYEL + HIY + "*" + NORM;
            break;
        }
        ob = next_inventory(ob);
    }

}

string query_current_icon() {
    return current_icon;
}

string query_terrain_icon() {
    return terrain_icon;
}

load_neighbors()
{
    return "/players/mizan/opl/daemons/gridDM.c"->load_neighbors(this_object()->query_index());
}

