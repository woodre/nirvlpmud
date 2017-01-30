/*
 * Shardak guild is (tm) Dragnar/John
 * Change log:
 * 950422 - created
 * 001108 - path changed from bal's arena to new one [verte]
 * 010513 - fiddled with the desc [vital]
 * 020624 - Added total pks at the bottom [maledicta]
 * 030715 - Added color and exits readable by Shardaks only
 *          Also fiddled some more with desc [linus]
 * 030719 - Changed long again.  Was messing up set_items [linus]
 */

#pragma strict_types
#include "/players/balowski/lib.h"
#include "../include/def.h"
#include "../include/tasks.h"
#include "../include/ansi.h"

inherit ROOM;

int total_pks;

void
create()
{
    ::create();
    set_short(RED+"Altar of Sacrifice"+NORM);
    set_long(HIK+"\
The eastern gallery opens into this high vaulted cavern that \n\
disappears into the darkness above. There are stalagtites and \n\
stalactites scattered around the ceiling and floor of the cavern. \n\
A large brass statue has been mounted in a twenty-foot high niche \n\
set into the rock wall to the east.  The cavern exits into the\n\
gallery to the west.\n"+NORM);
    set_exits( ([
        "west" : (PATH + "deepdown"),
/*
        "north": (PATH + "arena"),
*/
    ]) );
    set_items(([
    "inscription" : "\n\t"+RED+"To reveal the murderous histories of your Brothers,\n\
\tyou may divine it from them."+NORM+"\n\n",
    ({ "cavern", "vaulted cavern", "ceiling", "stalactites" }) : "\
The high vaulted cavern extends all over your head, littered\n\
with "+YEL+"dark brown"+NORM+" rocky stalactites.\n",
    ({ "floor", "stalagtites", "down" }) : "\
The floor has several large stalagtites. Each stalagtite corresponds to \n\
a matching stalactite on the ceiling.\n",
    ({ "brass statue", "statue", "niche", "east" }) : "\
A polished "+HIY+"brass"+NORM+" statue of Baal rests in a well-hewn niche\n\
tucked away in the rock wall.  An inscription has been scribed beneath it,\n\
written in some "+RED+"dark red"+NORM+" script.\n",
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

/* Room long description, shows exits only to Shards */
void
long(string arg){
 if(!arg) {
  if ((int)this_player()->query_brief() != 2)
   write(RED+"Altar of Sacrifice\n"+NORM);
    ::long(arg);
/*
"+BLINK+"light"+NORM+" emanating from the north and the gallery returns to the west.\n");
*/
 if (present("shardak_mark",this_player()))
  write("\t"+NORM+RED+"\The only exit is: west.\n"+NORM);
   return;
 }
  else ::long(arg);
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




