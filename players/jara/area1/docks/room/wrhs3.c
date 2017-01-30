/* NE corner of the warehouse, Created <4/28/00> by Jara */

#include "/players/jara/misc/ansi.h"
#include "defs.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="A warehouse";
  long_desc=
    "  A small office built in the corner of the warehouse holds a desk and\n"+
    "a small box. An oil lamp sits on the desk, and several sheets of paper\n"+
    "are visible within a drawer. A stool has been pushed under the desk,\n"+
    "and the drawer left ajar. Crates stacked against the north wall hold\n"+
    "goods ready for shipment, and a"+HIW+" mirror"+NORM+" leans against the wall.\n";
    "office.\n";
  items=({
    "box",
    "A small, wooden box, filled with a varitety of tools",
    "reflection", "You feel as though you could "+HIW+"touch"+NORM+" the "+HIW+"reflection"+NORM+"",
    "tools",
    "A saw, a hammer, and a set of nails",
    "lamp",
    "A glass oil lamp with a metal base",
    "paper",
    "A small slip of paper with shipping orders for the mirror",
    "mirror",
    "An oval shaped mirror with an oak frame, the"+HIW+" reflection"+NORM+" within is\n"+
    "of a ruined throne room",
    "orders",
    "Try to"+HIW+" read"+NORM+" the orders",
    "stool",
    "A three-legged stool, made of wood",
    "door",
    "A wooden door with a pane of glass in the center",
    "boxes",
    "The empty wooden boxes vary in size",
    "office",
    "The small, cramped office holds a small desk and supplies",
    "desk",
    "The desk is aged and well worn from years of use",
    "drawer",
    "Sheets of paperwork have been stuffed carelessly in the drawer. The\n"+
    "handle is missing",
    "crates",
    "Wooden crates, holding smaller boxes of packaged goods" });
  dest_dir=({
    PATH+"wrhs1","west",
    PATH+"wrhs4","south" });
}

init() {
  ::init();

  add_action("mirror_touch","touch");
  add_action("reader","read");
}

mirror_touch(str) {
  if(!str) {
    notify_fail("What do you want to touch?\n");
  return 0;
  }
    if(str == "reflection") {
    write("You place your hand on the reflection in the mirror...\n"+
    "You have been pulled into the mirror!\n");
    say(this_player()->query_name()+" touches the mirror and vanishes!\n");
    this_player()->move_player("into the mirror#players/jara/area1/entrance");
  return 1;
  }
  else {
    notify_fail("What do you want to touch?\n");
  return 0;
  }
}
reader(str) {
   if(!str) {
     notify_fail("What do you want to read?\n");
   return 0;
   }
  if(str == "orders") {
    write("The shipping orders read: This mirror is to be shipped to Zerchar Castle.\n");
  say(this_player()->query_name()+" reads the shipping orders.\n");
  return 1;
  }
  else {
    notify_fail("What do you want to read?\n");
  return 0;
  }
}
