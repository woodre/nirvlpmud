#include "/sys/lib.h"
#include "/players/pestilence/ansi.h"
inherit "room/room";

reset(arg) {
  if(arg) return;

short_desc = ""+HIC+"Amity Memorial Hospital <407>"+NORM+"";
long_desc =
  "    This room appears to have been a patient's room but has been \n"+
  "converted to a storage room.  There are several boxes scattered\n"+
  "throughout the room with what appears to be the personal affects of\n"+
  "the patients.  A few folded up beds lean against the east wall.\n"+
  "A dvd like disc sits on top of one of the closed boxes, and appears\n"+
  "to be labeled 'Hospital Porn directed by Dirty Randy'.\n";
set_light(1);

items = ({
  "lobby","It's to the east, but hard to make out.",
  "door","The door to the north, swings easily open.",
});

dest_dir = ({
  "/players/pestilence/hospital/room/4whall4.c","out",
});
}
