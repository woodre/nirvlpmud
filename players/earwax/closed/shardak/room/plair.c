/* Vertebraker - 2000
 * 030715 - added color, tweaked desc, made exit only visible
 *          to shardaks [linus]
 * 030719 - fixed long so items work again [linus]
 */

#pragma strict_types
#include "/players/balowski/lib.h"
#include "../include/def.h"
#include "../include/tasks.h"
#include "../include/ansi.h"

inherit ROOM;

void
create()
{
    ::create();
    set_short(RED+"The pyromancer's lair"+NORM);
    set_long(HIK+"\
Waves of heat swirl around this warm section of the cave.  A stone\n\
dragon's head extends from the southern side of the cavern, hot lava\n\
spews from it's mouth into an obsidian dish on the cavern floor.\n"+NORM);
    set_exits( ([
        "north" : (PATH + "descent"),
    ]) );
    set_items( ([
        ({ "cave", "cavern" }) : "\
The cave leads back up in a northward area to the\n\
main section of the grotto.\n",
        "heat" : "\
The thick steam rises all around you, pounding into\n\
your pores...\n",
        ({ "dragon's head", "head" }) : "\
The stone dragon's head pumps a porous "+HIR+"dark red lava"+NORM+"\n\
into a thick "+HIK+"obsidian dish"+NORM+", where it seems to disappear.\n",
        ({ "obsidian dish", "dish" }) : "\
The black obsidian dish appears to be some sort of portal\n\
to another world.. or dimension.\n",
        ({ "hot lava", "lava" }) : "\
Burning hotly, the lava flows effortlessly through the\n\
stone dragon head to the dish, where it dissolves into\n\
nothingness.  It is pouring out of the wall with no end\n\
in sight, apparently.\n", 
       ]) );

    set_light(2);
    set_property("fight area", 1);
    set_property("no teleport", 1);
}

void
long(string arg) {
 if(!arg) {
  if((int)this_player()->query_brief() != 2) 
   write(RED+"The Pyromancer's lair\n"+NORM);
    ::long(arg);
  if (present("shardak_mark",this_player())) 
   write("\t"+NORM+RED+"\The only exit is: north.\n"+NORM);
    return;
 }
  else ::long(arg);
}

void
reset(int arg)
{
    ::reset(arg);
    if (!present("pyromancer", this_object()))
      move_object(clone_object(PATH + "pyromancer"), this_object());
}
