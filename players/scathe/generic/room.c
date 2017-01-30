/*
 * Generic room. A product of the rejuvenation project
 * first cut by Balowski@Nirvana, 1996
 * 09/11/2015 - Gnar - Added inherit from /room/room.c
 */
/*#include "lib.h"*/
inherit "room/room";

#if 0
private string Long, LongExits;
private string Short, ShortExits;
#endif
private mapping Exits;

#if 0
static string translate_exit(string str);
static string convert_number(int n);
#endif

/********************************************************************
 * Gnar - Useless, but kept to avoid changing all the rooms
 ********************************************************************/
void create();

/********************************************************************
 * Gnar - Wrapper for the set_dest_dir function, again so we don't
 *        have to update all of the rooms.
 ********************************************************************/
void
show_exits()
{
    int i; string *ks;
    string *dirs;

    if (!Exits) return;

    i = sizeof(ks = keys(Exits));

    while (i--) {
        if(!dirs)
          dirs = ({ Exits[ ks[i] ], ks[i] });
        else
          dirs += ({ Exits[ ks[i] ], ks[i] });
    }
    set_dest_dir( dirs );
}

void
set_exits(mapping m)
{
    Exits = m;
    show_exits();
}

void create()
{
  short_desc = 0;
}

void
reset(int arg)
{
  ::reset(arg);
    if (!arg) create();
}
/********************************************************************
 * Gnar - Removed most of the functions that are no longer needed,
 *        using functionality from /room/room instead.
 ********************************************************************/
#if 0
void
set_long(string str)
{
    Long = str;
}

void
set_short(string str)
{
    Short = str;
}

void
show_exits()
{
    int i; string *ks;
    string *dirs;

    if (!Exits) return;

    i = sizeof(ks = keys(Exits));
    ShortExits = "";
    if (!i) {
        ShortExits = "no exits";
        LongExits = "    No obvious exits.\n";
    }
    else if (i == 1)
        LongExits = "    There is one obvious exit: ";
    else
        LongExits = "    There are " + convert_number(i) + " obvious exits: ";


    while (i--) {
        if(!dirs)
          dirs = ({ Exits[ ks[i] ], ks[i] });
        else
          dirs += ({ Exits[ ks[i] ], ks[i] });
        LongExits += ks[i];
        if (i == 1) LongExits += " and ";
        else if (i) LongExits += ", ";

        ShortExits += translate_exit(ks[i]);
        if (i) ShortExits += ",";
    }
    set_dest_dir( dirs );
    LongExits += "\n";
    ShortExits = " [" + ShortExits + "]";
}

void
long(string item)
{
  int i;
    if (set_light(0)) {
        if (!item) {
            write(Long);
            write("dirs: :"+sizeof(dest_dir)+"\n");
            for( i=0; i < sizeof(dest_dir); i += 2 )
              write("\t"+dest_dir[i]+" : "+dest_dir[i+1]+"\n");
            write(LongExits);
        }
    }
    else
        write("It is too dark.\n");
}

string
short()
{
    if (set_light(0)) {
        return Short + ShortExits;
    }
    return "A dark room";
}

void
init()
{
    int i; string *ks;
    if (!Exits) return;
    i = sizeof(ks = keys(Exits));
    while (i--) add_action("move", ks[i]);
}

status
move(string arg)
{
    mixed exit;
    if (exit = Exits[query_verb()]) {
        if (exit[0] == '_')
            exit = (mixed) call_other(this_object(), exit);
        if (intp(exit))
            return exit;
        else
            this_player()->move_player(query_verb() + "#" + exit);
        return 1;
    }
    notify_fail("You can't go that way.\n");
    return 0;
}

static string
translate_exit(string str)
{
    switch(str) {
        case "north":   return "n";
        case "south":   return "s";
        case "east":    return "e";
        case "west":    return "w";
        case "northeast": return "ne";
        case "northwest": return "nw";
        case "southeast": return "se";
        case "southwest": return "sw";
        case "up":      return "u";
        case "down":    return "d";
        default:        return str;
    }
  return 0; /* Rumplemintz */
}

static string
convert_number(int n)
{
    switch (n) {
        case 0: return "no";
        case 1: return "one";
        case 2: return "two";
        case 3: return "three";
        case 4: return "four";
        case 5: return "five";
        case 6: return "six";
        case 7: return "seven";
        case 8: return "eight";
        case 9: return "nine";
        default: return "lot of";
    }
  return 0; /* Rumplemintz */
}

#include "/room/clean.c"
#endif
