/*  a teleporting maze for higher level players  */

#include "defs.h"
inherit "room/room";

reset(arg) {

if(!present("bart")) {
  move_object(clone_object("players/eurale/Cave/NPC/bart"),TO); }

  if(arg) return;
set_light(0);

short_desc = "a dark cave";
long_desc =
  "  A tunnel carved out through the solid rock surrounds you. Dark\n"+
  "shadows cover the rough, ragged walls.  The air is cool and smells\n"+
  "fairly  musty like there isn't much movement inside the cave.  The\n"+
  "darkness prevents you from making out much as you inch your way\n"+
  "along.  Even your footsteps seem to echo slightly as you walk.\n";

items = ({
	"sides","The shadows make the sides of the cave appear and then \n"+
		"seem to disappear into the blackness",
  "shadows","Deeper black than the tunnel itself. One seems to cover\n"+
            "some kind of wall imperfection",
});

dest_dir = ({
	"/players/eurale/Cave/cav5.c","east",
});

}

init() {
  ::init();
  add_action("search","search");
  add_action("squeeze","squeeze");
}

search(str) {
if(present("bart")) {
  write("Bart kicks you as you take your eyes off him.\n");
  TP->hit_player(random(20));
  return 1; }
if(!str) {
  write("You search around in the darkness and find nothing.\n");
  return 1; }
if(str != "shadow" && str != "shadows") {
  write("You search the "+str+" but find nothing of importance.\n");
  return 1; }
if(str == "shadow" || str == "shadows") {
  write("You search the dark shadows and find a crack in the solid\n"+
      "rock you might be able to squeeze into.\n");
  return 1; }
else write("You search the "+str+" but find nothing of importance.\n");
return 1;
}

squeeze(str) {
if(present("bart")) {
  write("You take your eyes off of Bart for just a second and he\n"+
        "sucker punches you in the side of the face...\n");
  TP->hit_player(random(25));
  return 1; }
if(str == "crack") {
  write("You squeeze yourself into the dark crack.\n");
  TP->move_player("into the shadows#players/eurale/Cave/cav7.c");
  return 1; }
}
