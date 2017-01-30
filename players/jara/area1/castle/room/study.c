/* Upstairs Study, Created <8/4/01> by Jara */

#include "/players/jara/misc/ansi.h"
#include "defs.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="Zercher Castle- Study";
  long_desc=
    "  A small room, with a wooden floor and stone walls. An oak desk stands\n"+
"in one corner, with a stained glass lamp dimly lighting the scrolls and\n"+
"charts spread across the desktop. A painting stands out on the west wall,\n"+
"framed with a golden trim. An alcove in the northern wall opens up to a\n"+
"window overlooking a lush, green forest, and door leads south.\n";
  items=({
    "floor", 
    "The wooden floorboards are well worn and scratched",
    "walls",
    "The walls of this room are made of textured grey stones",
    "stones", 
    "The darkened grey stones are lightly textured and thick",
    "desk",
    "The oak desk has a polished finish, one drawer, and a small scratch",
    "doorway",
    "The doorway is marked with the royal insignia and made of a dark,\n"+
    "oak wood",
    "drawer",
    "A small drawer, set into the wood of the desk. There is a keyhole",
    "lamp",
    "An exquisite lamp, made with glass stained a deep red color",
    "scrolls",
    "The yellowed scrolls, rolled up and tied, are strewn across the desk",
    "charts",
    "The charts are detailed maps of the coastline",
    "painting",
    "An oil painting of a young woman dressed in fine clothing",
    "trim",
    "The frame of the painting is trimmed with a dull gold",
    "alcove",
    "Set apart from the study, the small alcove has a view of of the forest\n"+
    "beyond",
    "forest",
    "The sinister forest has a strange beauty with the lush foliage of the\n"+
    "trees",
    "insigina",
    "A unicorn and lion facing each other in peace", });
  dest_dir=({
    PATH+"hall1","south" });
}

void init() {
  ::init();

  add_action("search","search");
}
search(str) {
  if(!str) {
    write("You find nothing.\n");
  return 1;
 }
}
