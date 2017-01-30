#include "/players/pestilence/define.h"
inherit "/players/vertebraker/closed/std/room";

reset(arg) {
  if(arg) return;

long_desc =
  "    This is the inside of a large sewer pipe.  The pipe is 8 feet\n"+
  "in diameter.  Murkey looking water flows through the pipe.  The\n"+
  "water is only one foot deep here.  The pipe continues to the east\n"+
  "and west.  Also pipes lead to the north and south.  There seems\n"+
  "to be a crack in the wall of the pipe.\n";
add_property("NT");
set_light(0);

items = ({
  "pipe","A large steel pipe, 8 feet in diameter",
  "wall","Is the steel inside of the pipe",
  "water","About 1 foot deep of water flowing through the pipe",
  "light","A faint light coming from the far east",
  "murkey water","Dark colored water, with little movement in it",
  "crack","A large crack in the pipe, that appears someone could 'enter'",
});

dest_dir = ({
"/players/pestilence/club/room/sewer4.c","west",
"/players/pestilence/club/room/sewer7.c","east",
"/players/pestilence/club/room/sewer5.c","south",
"/players/pestilence/club/room/sewer6.c","north"});

}
short() {
    return ""+YEL+"Sewer"+NORM+"";
}

init() {
  ::init();
add_action("stop","quit");
add_action("enter","enter");
}
stop() {
if(TP->query_ghost() == 1) { return 0; }
else{
write("You can't quit from here.\n");
return 1; }
}

enter(arg) {
/*
  write("Closed. -administration.\n");
  return 1;
*/
   if(!arg) { notify_fail("You must enter crack.\n");
       return 0;}
  if(arg == "crack"){
  if (this_player()->query_level() > 8) {
     write("You enter the through the crack.\n");
     TP->move_player("into the crack#/players/pestilence/closed/dark/room/hall.c");
     return 1; }
        else
            write("You must enter crack.\n");
        return 1;
    }
}
