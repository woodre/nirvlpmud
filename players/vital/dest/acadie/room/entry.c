/************************************/
/*    Owner:      Vital@Nirvana     */
/*    Created:    12/18/00          */
/*    Modified:   2/9/01            */
/*    Realm:      Acadie            */
/************************************/

#include <ansi.h>
#include "/players/vital/closed/headers/vital.h"                    /*color header*/
#include "/players/vital/dest/include/dest.h"

inherit "room/room";

reset(arg) {
  if(!present("human",TO)) MO(CO(NPC+"human.c"),TO);
  if(!arg) {

set_light(1);

short_desc = "Office Entryway";
long_desc =
  "  The Acadie Spaceport Entryway\n\
This is the entryway to the Acadie Spaceport office. The entryway \n\
is composed of a large covered archway of stone that leads into the \n\
office. The floor is marble and the columns are made of large \n\
conglomerations of ivory from the verruls. The entryway is designed \n\
for show and not for function. The flashy entryway stands out in \n\
stark contrast to the minimalist world around it.\n ";

items = ({
    "spaceport",
    "The Acadie Spaceport stands before you. Passengers travel in and out as they approach the office",
    "entryway",
    "The stone archway is translucent and frosted. The columns are created from the ivory tusks of the verruls and the floor is marble",
    "stone",
    "The stone is a strange material that sometimes looks frosted, sometimes clear, and lets some light pass through",
    "archway",
    "The archway is made of large stones of strange origin",
    "passengers",
    "These are the people who travel the stars",
    "office",
    "The Acadie Spaceport stands before you. Passengers travel in and out as they approach the office",
    "tusks",
    "The tusks are harvested from the dead verruls from the ring-hockey farms",
    "floor",
    "The floor here is formed of large slabs of marble of a pale white with small ribboned traces of blue-green and black strands",
    "world",
    "All around you notice the stark and unadorned reality of a harsh world"
});

dest_dir = ({
    ACADIE+"room/landingoffice.c","office",
    ACADIE+"room/sidewalk1.c","south"
  });

  }
}

init() {
    ::init();
    add_action("search_me","search");
}

search_me(str) {
  if(!str) {
    notify_fail("What are trying to search?\n");
    return 0;
  }
  else write("You furiously search the "+str+" but find nothing.\n");
}
