#include "/players/pestilence/define.h"
inherit "/players/vertebraker/closed/std/room";

reset(arg) {
  if(arg) return;

if (!present("animal")) {
  move_object(clone_object("/players/pestilence/club/mob/animal.c"),
        this_object()); }

long_desc =
  "    This is a junctioning room, where several sewer pipes meet.\n"+
  "The large eight foot pipe continues to the north, east, and west.\n"+
  "To the south, is a smaller pipe of four feet in diameter.  This\n"+
  "room is square with cement blocks making up the walls, and\n"+
  "enclosing the pipes\n";
add_property("NT");
set_light(0);

items = ({
  "pipes","Large steel pipes, 8 feet in diameter",
  "cement","Gray cement blocks that make up the walls",
  "block","Gray cement blocks that make up the walls",
  "blocks","Gray cement blocks that make up the walls",
  "cement blocks","Gray cement blocks that make up the walls",
  "walls","The walls are made of cement blocks",
  "wall","The wall is made of cement blocks",
  "small pipe","A smaller pipe, 4 feet in diameter, heading off to the south",
  "water","About 1 foot deep of water flowing through the pipe",
  "light","A faint light coming from the far east",
  "murkey water","Dark colored water, with little movement in it",
});

dest_dir = ({
"/players/pestilence/club/room/sewer2.c","west",
"/players/pestilence/club/room/sewer4.c","east",
"/players/pestilence/club/room/nsewer.c","north",
"/players/pestilence/club/room/ssewer.c","south",
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
