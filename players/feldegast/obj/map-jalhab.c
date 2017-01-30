#include "defs.h"

inherit "/obj/treasure.c";

void reset(int arg) {
  if(arg) return;
  set_id("map");
  set_alias("jalhab map");
  set_short("Map of the Jal-Hab");
  set_long("The map is drawn on a sheepskin hide with a fine pen.  The notations\n"+
           "and the legend are written with a neat but not flashy scrawl.  You\n"+
           "can 'read' it.\n");
  set_weight(1);
  set_value(50);
}

void init() {
  add_action("cmd_read","read");
}

int cmd_read(string str) {
  if(!str || str!="map") {
    notify_fail("Read what?\n");
    return 0;
  }
  write(
"\n\t\tThe Jal-Hab\
\n\
\n\
                        ~~~~~~~~~~~~~~\n\
 Legend                O~~~~~~~~~~~~~~~\n\
 ------                  ~~..........~~\n\
 S - Sudakan             ~~..F.......~~\n\
 O - Oasis               ~~......S...~~\n\
 P - P'kalian Village    ~~..........~~\n\
 M - Mound               ~~..........~~\n\
 F - Fingers of God      ~~.C....M...~~\n\
 C - Castle Magnarn      ~~..........~~\n\
                         ~~...P...O..~~\n\
                         ~~..........~~\n\
                         ~~..........~~\n\
                       O~~~~~~~~~~~~~~~\n\
                        ~~~~~~~~~~~~~~\n\
\n\n");
  return 1;
}

