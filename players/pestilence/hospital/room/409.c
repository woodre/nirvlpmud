#include "/sys/lib.h"
#include "/players/pestilence/ansi.h"
inherit "room/room";

reset(arg) {
  if(arg) return;

short_desc = ""+HIC+"Amity Memorial Hospital <409>"+NORM+"";
long_desc =
  "    This is a room that appears to be used for shock therapy.  There \n"+
  "are two beds here, with several body restraints attached to them.\n"+
  "The floor consists of white tiles with some dark red stains.  In\n"+
  "the corner of the room there is an electrical machine, which appears\n"+
  "to be the thing that gives the shocks.  There are some cords and straps\n"+
  "coming from it that appear to fit on ones head and genitals.\n";
set_light(1);

items = ({
  "lobby","It's to the east, but hard to make out.",
  "door","The door to the north, swings easily open.",
});

dest_dir = ({
  "/players/pestilence/hospital/room/4whall5.c","out",
});
}
