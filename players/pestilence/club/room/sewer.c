#include "/players/pestilence/define.h"
inherit "/players/vertebraker/closed/std/room";

reset(arg) {
  if(arg) return;

long_desc =
  "    This is a square entrance room into the sewer system.  A large\n"+
  "steel pipe runs from east to west.  There is a small amount of\n"+
  "water flowing through the pipe.  A real faint light can be seen\n"+
  "coming from the east.  A small ladder rests in the middle of this\n"+
  "part of the sewer system, leading up to the manhole cover.\n";
add_property("NT");
set_light(0);

items = ({
  "pipe","A large steel pipe, 8 feet in diameter",
  "wall","The walls are made of brick",
  "ladder","A small ladder leading back up to the alley",
  "cover","A manhole cover that leads back out to the alley",
  "manhole cover","A manhole cover that leads back out to the alley",
  "water","About 1 foot deep of water flowing through the pipe",
  "light","A faint light coming from the far east",
  "brick","A large brick, that makes up the wall",
});

dest_dir = ({
"/players/pestilence/club/room/sewer2.c","east",
});

}
short() {
    return ""+YEL+"Sewer"+NORM+"";
}

init() {
  ::init();
add_action("stop","quit");
add_action("enter","climb");
}
stop() {
if(TP->query_ghost() == 1) { return 0; }
else{
write("You can't quit from here.\n");
return 1; }
}
enter(arg){
  if (arg == "ladder"){
    write("You climb up the ladder.\n");
 move_object(this_player(), "/players/pestilence/club/room/alley.c");  
  command("look",this_player());
    write("You pull yourself out of the manhole, and now stand in the alley.\n");
return 1; }
    write("Climb what?\n");
return 1; }
