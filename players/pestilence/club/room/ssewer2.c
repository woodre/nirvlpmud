inherit "/players/vertebraker/closed/std/room";

#include "/players/pestilence/define.h"

reset(arg) {
  if(arg) return;

if (!present("animal")) {
  move_object(clone_object("/players/pestilence/club/mob/animal.c"),
        this_object()); }

long_desc =
  "    This is a small sewer pipe.  It is too small for a person to\n"+
  "stand comfortably in, and to walk through.  The water that flows\n"+
  "through here takes up about half of the pipe.  The pipe goes to\n"+
  "the north and south.\n";
add_property("NT");
set_light(0);

items = ({
  "pipes","Large steel pipes, 8 feet in diameter",
  "walls","The walls are made of cement blocks",
  "wall","The wall is made of cement blocks",
  "small pipe","A smaller pipe, 4 feet in diameter, heading off to the south",
  "water","About 1 foot deep of water flowing through the pipe",
  "light","A faint light coming from the far east",
  "murkey water","Dark colored water, with little movement in it",
});

dest_dir = ({
"/players/pestilence/club/room/ssewer.c","north",
"/players/pestilence/club/room/ssewer3.c","south",
});

}
short() {
    return ""+YEL+"Sewer"+NORM+"";
}

init() {
  ::init();
add_action("stop","quit");
}
stop() {
if(TP->query_ghost() == 1) { return 0; }
else{
write("You can't quit from here.\n");
return 1; }
}
