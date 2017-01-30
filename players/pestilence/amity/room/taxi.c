#include "/open/ansi.h"
#define TP this_player()
inherit "/players/vertebraker/closed/std/room";

reset(arg) {
  if(arg) return;

if (!present("Mr. Duke")) {
  move_object(clone_object("/players/pestilence/amity/mob/duke.c"),
        this_object()); }

short_desc = ""+HIB+"Taxidermist"+NORM+"";
long_desc =
  "    This is the main room for the taxidermist.  There is a large desk\n"+
  "near the west wall.  There are stuffed animals mounted on all the walls.\n"+
  "The floor is hardwood.  There is a sign hanging near the desk.\n";
set_light(1);

items = ({
  "desk","A large oak desk, with a few papers on it",
  "papers","A few white papers on the desk, you can't quite make out the writing",
  "animals","A few deer, moose, and elk heads mounted on the walls",
"moose head","A large furry moose head, with forty-inch antlers hanging on the wall",
"deer head","A large deer head, with twenty-inch antlers hanging on the wall",
"elk head","A large elk, with antlers spreading out sixty-inches from tip to tip, is hanging on the wall",
  "floor","An oak hardwood floor",
"stuffed animals","Some assorted animals that have been stuffed",
  "sign",
"_________________________________________________________\n"+
"|                                                        |\n"+
"|      WE BUY PARTS OF ANIMALS  WHOLE ANIMALS            |\n"+
"|                                                        |\n"+
"|      USE THE COMMAND BARTER TO RECIEVE VALUE           |\n"+
"|                                                        |\n"+
"|      FOR THE ANIMAL PARTS                              |\n"+
"|________________________________________________________|\n",

});

dest_dir = ({
  "/players/pestilence/amity/room/nmain1.c","out",
});

}
