inherit"/room/room";
#include <ansi.h>
#include "../def.h";
 
reset(arg)
{
::reset(arg);
  if(!present("furrball"))
    move_object(clone_object(MOB+"furrball.c"),this_object());
if(arg)return;
  set_light(1);
  short_desc = "A Small "+HIB+"Alley "+NORM;
  long_desc = " A small paved alley way full of trash cans and trash. Small rats run\n\
  around searching for the smallest crumb. Cardboard boxes, newspaper\n\
  and all kinds of trash are cluttering the ground all over the place.\n\
  A dumpster seems to fill the whole surrounding area with an ungodly\n\
  odor. A small box can be seen next to the dumpster. Even the sewer\n\
  drains are clogged with trash and clutter.\n";
  items = 
  ({
    "box",
    "A small cardboard box that seems to be the home for a small animal",
    "dumpster",
    "An over flowing dumpster that smells really bad and is overflowing with trash",
    "trash cans",
    "A simple wire basket trashcan that looks like it has been used to burn trash to keep warm",
    "drain",
    "A Small metal grate that lets off excess rain water into the sewers",
    "rats",
    "Little rodents running around trying to find a single crumb to eat",
    "newspaper",
    "Wet old newspapers that are piled up and discarded in the alley making a mess",
    "drains",
    "Old Storm drains with rusted grates that are covered by the trash in the alley",
  });
    dest_dir=({
      ROOM+"toonroad2.c","east"
  });
  } 
