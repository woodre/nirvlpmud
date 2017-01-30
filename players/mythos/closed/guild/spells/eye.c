#include "/players/mythos/closed/guild/def.h"
inherit "room/room";
reset(arg) {
  if(!arg) {
  set_light(0);
    short_desc = "Blizzard";
    long_desc =
    "You are in the midst of a blizzard....  All is white all is cold....\n"+
    "You may go any of the four directions, for it doesnt matter which way you\n"+
    "go...\n";
  items = ({
    "west","....",
    "east","....",
    "north","....",
    "south","....",
  });
} }
realm() { return "NT";}

init() {
  ::init();
  add_action("rand","north");
  add_action("rand","east");
  add_action("rand","south");
  add_action("rand","west");
}

rand() {  
  if(random(5) == 0) {
  move_object(tp,"/room/church.c"); }
  else {
  tp->move_player("blizzard#players/mythos/closed/guild/spells/eye.c"); }
return 1;}

