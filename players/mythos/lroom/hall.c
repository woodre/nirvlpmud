#include "/players/mythos/closed/guild/def.h"
inherit "room/room";

reset(arg) {
  if(!arg) {
  set_light(1);
    short_desc = "Library Entrance";
    long_desc =
    "You have entered the "+BLU+"GREAT LIBRARY"+NORM+".\n"+
    "Here most of the great works known to man are placed.\n"+
    "Only the fabled Eternal Library- where all knowledge is kept-\n"+
    "holds more.  Know that one must be quiet, when in this area.\n";
  items = ({
    "north","You see the library through a set of crystal doors",
    "portal","The shimmering portal leads back to the Chamber of Realms",
  });

  dest_dir = ({
    "/players/mythos/entrance.c", "portal",
    "/players/mythos/lroom/library.c","north",
  });
} }

init() {
  ::init();
  if(present(fear,this_player())) {
   present(fear,this_player())->set_defence(0);} 
}
