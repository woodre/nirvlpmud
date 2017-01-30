/*
 * Shardak guild is (tm) Dragnar/John
 * Change log:
 * 950422 - created
 * 030715 - Added color, tweaked desc, and added exits viewable by shardaks
 *          only [linus]
 * 030719 - fixed long to allow set_items [linus]
 */

#pragma strict_types
#include "/players/balowski/lib.h"
#include "../include/def.h"
#include "../include/ansi.h"

inherit ROOM;

void
create()
{
    ::create();
    set_short(RED+"Deep inside the rock"+NORM);
    set_long(HIK+"\
The tunnel has been carved through the rock, with openings in the\n\
western and eastern walls.  An acrid odor drifts in from the west\n\
and mingles with the cold stale air.  The tunnel permits travel\n\
to the south, and opens into a chamber to the north.\n\
There is a ladder sticking up from a small hole in the floor.\n"+NORM);
    set_exits( ([
        "south": (PATH + "descent"),
        "west" : (PATH + "stable"),
        "east" : (PATH + "altar"),
        "north": (PATH + "throne"),
        "down" : (PATH + "garden"),
    ]) );
    set_items( ([
        "tunnel": "The tunnel leads south further into the cave...\n"+
                  "West to the dragon keeper's stable...\n"+
                  "East to the altar of sacrifice...\n"+
                  "North to the throne of Lord Shardak...\n"+
                  "Or down to the Imp's Garden...\n",
        ({ "western wall", "wall" }) : "\
The opening to the western wall leads to the dragon keeper's stable.\n",
        "gallery" : "Which gallery? (northbound/southbound)\n",
        "northbound gallery" : "\
The tunnel wraps perilously to the throne room.\n",
        "southbound gallery" : "\
The tunnel leads south, deeper into the grotto.\n",
       ]));
    set_light(0);
    set_property("fight area", 1);
    set_property("no teleport", 1);
}

/* Rooms long description, shows exits only to Shardaks */

void
long(string arg) {
 if(!arg) {
  if((int)this_player()->query_brief() != 2)
   write(RED+"Deep inside the rock\n"+NORM);
    ::long(arg);
  if (present("shardak_mark",this_player())) 
   write("\t"+NORM+RED+"\The exits are: north, south, east, west, and down.\n"+NORM);
    return;
 }
  else ::long(arg);
}





