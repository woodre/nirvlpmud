#include "/sys/lib.h"
#include "/players/pestilence/ansi.h"
inherit "room/room";

reset(arg) {
  if(arg) return;

short_desc = ""+HIC+"Amity Memorial Hospital <408>"+NORM+"";
long_desc =
  "    This room appears to be some sort of solitary confinement room.\n"+
  "The whole room is covered with padding, which would seem to protect\n"+
  "the patient from hurting themself.  The room is empty, with not even\n"+
  "a bed nor a window\n";
set_light(1);

items = ({
  "lobby","It's to the east, but hard to make out.",
  "door","The door to the north, swings easily open.",
});

dest_dir = ({
  "/players/pestilence/hospital/room/4whall4.c","out",});
}
