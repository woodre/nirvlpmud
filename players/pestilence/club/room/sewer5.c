#include "/players/pestilence/define.h"
inherit "/players/vertebraker/closed/std/room";

reset(arg) {
  if(arg) return;

if (!present("animal")) {
  move_object(clone_object("/players/pestilence/club/mob/animal.c"),
        this_object()); }

long_desc =
  "    This is the inside of a large sewer pipe.  The pipe is 8 feet\n"+
  "in diameter.  Murkey looking water flows through the pipe.  The\n"+
  "water is only one foot deep here.  The pipe continues to the east\n"+
  "and west.  Also pipes lead to the north and south.\n";
add_property("NT");
set_light(0);

items = ({
  "pipe","A large steel pipe, 8 feet in diameter",
  "wall","Is the steel inside of the pipe",
  "water","About 1 foot deep of water flowing through the pipe",
  "light","A faint light coming from the far east",
  "murkey water","Dark colored water, with little movement in it",
});

dest_dir = ({
"/players/pestilence/club/room/sewer4.c","west",
"/players/pestilence/club/room/sewer3.c","east",
"/players/pestilence/club/room/nsewer.c","south",
"/players/pestilence/club/room/sewer6.c","north"});

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
