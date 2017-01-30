#include "DEF.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
if(!present("knight")) {
  move_object(clone_object("players/eurale/Chess/NPC/b_knight"),TO); }
set_light(1);

short_desc = HIW+"Chess Board"+NORM;
long_desc =
  "  The floating feel of the board underneath your feet makes you uneasy.  A \n"+
  "strange mist surrounds the area preventing vision in any direction.  Muffled\n"+
  "sounds like people whispering can be heard somewhere deep within the mist.\n";

items = ({
 "board","The board is some kind of smooth, white material",
 "mist","A thick, watery fog that moistens your skin",
});

dest_dir = ({
});

}

realm() { return "NT"; }

init() {
  ::init();
  add_action("South","south");
  add_action("East","east");
  add_action("West","west");
  add_action("North","north");
}

East() {
  TP->move_player("into the mist#players/eurale/Chess/h7.c");
  return 1; }

West() {
  TP->move_player("into the mist#players/eurale/Chess/f7.c");
  return 1; }

North() {
  TP->move_player("into the mist#players/eurale/Chess/g6.c");
  return 1; }

South() {
  TP->move_player("into the mist#players/eurale/Chess/g8.c");
  return 1; }
