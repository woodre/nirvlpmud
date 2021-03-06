/*
 * Shardak guild is (tm) Dragnar/John
 * Change log:
 * 950422 - created
 * 001108 - path changed from bal's arena to new one [verte]
 * 010513 - fiddled with the desc [vital]
 * 020624 - Added total pks at the bottom [maledicta]
 */
#pragma strict_types
#include "/players/vertebraker/ansi.h"
#include "/players/balowski/lib.h"
#include "../def.h"
#include "../tasks.h"

inherit ROOM;

int total_pks;

void
create()
{
    ::create();
    set_short("Altar of Sacrifice");
    set_long("\
The eastern gallery has entered into this high vaulted cavern that \n\
disappears into the darkness above. There are stalagtites and \n\
stalactites scattered around the ceiling and floor of the cavern. \n\
There is a large brass statue mounted in a twenty-foot high niche \n\
set into the rock wall to the east.\n");
/*
"+BLINK+"light"+NORM+" emanating from the north and the gallery returns to the west.\n");
*/
    set_exits( ([
        "west" : (PATH + "deepdown"),
/*
        "north": (PATH + "arena"),
*/
    ]) );
    set_items(([ 
    "inscription" : "\n\tTo reveal the murderous histories of your Brothers,\n\tyou may divine it from them.\n\n",
    ({ "cavern", "vaulted cavern", "ceiling", "stalactites" }) : "\
The high vaulted cavern extends all over your head, littered\n\
with dark brown rocky stalactites.\n",
    ({ "floor", "stalagmites", "down" }) : "\
The floor has several large stalagmites. Each stalagmite correspondes \n\
a matching stalactite on the ceiling.\n",
    ({ "brass statue", "statue", "niche", "east" }) : "\
A polished "+HIY+"brass"+NORM+" statue of Baal rests in a well-hewn niche\n\
tucked away in the rock wall.  An inscription has been scribed beneath it,\n\
written in some dark red script.\n",
/*
    ({ "shifting light", "light", "north wall", "north" }) : "\
"+BLINK+"Glimmers"+NORM+" of "+HIW+"light"+NORM+" echo radiantly throughout the cavern, leading\n\
from the path leading north.\n",
*/

    ({ "gallery" }) : "\
The gallery leads west to beneath the grotto.\n",
    ]));

    set_light(1);
    set_property("fight area", 1);
    set_property("no teleport", 1);
}

void
reset(int arg)
{
    ::reset(arg);
    if (!present("priestess", this_object()))
      move_object(clone_object(PATH + "priestess"), this_object());
}

void
init()
{
    ::init();
    add_action("cmd_read", "read");
    add_action("cmd_divine", "divine");
}

int
cmd_read(string arg)
{
    if(arg == "inscription") return (long("inscription"), 1);
    return 0;
}

mixed *PKills;

void
analyze_this(string who)
{
    int i;
    mixed *pk;

    pk = PKills;
    if((i = member_array(who, pk)) > -1)
    {
      pk = pk[i+1];
      for(i = 0; i < sizeof(pk); i ++){
        write("\t" + pk[i] + "\n");
        total_pks += 1;
        }
    }
}
status
cmd_divine(string arg)
{
    int i;
    total_pks = 0;
    PKills=({});
    if(!arg) return (notify_fail("You must specify a name.\n"), 0);
    if(!file_size("/"+SAVE_PATH + arg + ".o"))
      return (notify_fail("You may only divine the kill-stats of another Servant.\n"), 0);
    else
    {
      restore_object(SAVE_PATH + arg);

      if(!PKills || !sizeof(PKills)) return (write(capitalize(arg) + 
        " has not slain anyone as a Shardak.\n"), 1);
      write(HIR + "\n\t\t\t[" + capitalize(arg) + "'s PKList]\n\n" + NORM);
      for(i = 0; i < sizeof(PKills); i += 2)
      {
        write("   " + (i/2+1) + ": " + BOLD + capitalize(PKills[i]) + NORM + "\n");
        analyze_this(PKills[i]);
        write("\n");
      }
      write(HIR+"\tTotal Pks: "+HIW+total_pks+"\n"+NORM);
      total_pks = 0;
      write("\n");
      return 1;
    }
}
