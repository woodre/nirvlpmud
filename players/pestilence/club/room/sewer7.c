#include "/players/pestilence/define.h"
inherit "/players/vertebraker/closed/std/room";

reset(arg) {
  if(arg) return;

if (!present("jamie")) {
  move_object(clone_object("/players/pestilence/club/mob/jamie.c"),
        this_object()); }

if (!present("jim bob")) {
  move_object(clone_object("/players/pestilence/club/mob/jimbob.c"),
        this_object()); }

if (!present("ray")) {
  move_object(clone_object("/players/pestilence/club/mob/ray.c"),
        this_object()); }

long_desc =
  "    This is a square entrance room into the sewer system.  A large\n"+
  "steel pipe runs to the west and south.  There is a small amount of\n"+
  "water flowing through the pipe.  A real faint light can be seen\n"+
  "coming from above.  A small ladder rests in the middle of this\n"+
  "part of the sewer system, leading up to the manhole cover.\n";
add_property("NT");
set_light(0);

items = ({
  "pipe","A large steel pipe, 8 feet in diameter",
  "wall","The walls are made of brick",
  "ladder","A small ladder leading back up to the alley",
  "cover","A manhole cover that leads back out to somewhere unknown",
  "manhole cover","A manhole cover that leads back out to somwhere unknown",
  "water","About 1 foot deep of water flowing through the pipe",
  "light","A faint light coming from the far east",
  "brick","A large brick, that makes up the wall",
});

dest_dir = ({
"/players/pestilence/club/room/sewer6.c","west",
"/players/pestilence/club/room/sewer4.c","south",
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
    write("The ladder appears to be broken.\n");
/*
 move_object(this_player(), "/players/pestilence/amity/room/nmain1.c");  
  command("look",this_player());
    write("You pull yourself out of the manhole, and now stand in the street.\n");
*/
return 1; }
    write("Climb what?\n");
return 1; }

