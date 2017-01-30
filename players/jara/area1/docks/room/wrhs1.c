/* NW corner of the warehouse, Created <4/28/00> by Jara */

#include "defs.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="A warehouse";
  long_desc=
    "  The northwest corner of the warehouse is cluttered with old, wooden\n"+
    "crates and boxes. A thin layer of dust covers many of the boxes and\n"+
    "the floor is littered with splinters of wood and bits of mud. Against\n"+
    "the wall, an elevator equipped with a pulley leads to the upper level\n"+
    "of the warehouse.\n";
  items=({
    "crates",
    "The crates are slightly sturdier than the boxes in design and quality",
    "splinters",
    "Small pieces of wooden splinters",
    "mud",
    "The mud is mostly made of moist sand, hardened and crumbling",
    "pulley",
    "The pulley has a broken rope that falls from the pulley to the base of\n"+
    "the elevator",
    "boxes",
    "The wooden boxes vary in size. The wood is splintered and worn, and\n"+
    "many of the crates are empty",
    "dust",
    "A thin layer of dust that covers the contents of the warehouse. One\n"+
    "crate is free of the dust",
    "crate",
    "The crate appears untouched by the dust and mud that covers the other\n"+
    "boxes",
    "elevator",
    "The elevator is rusted and the pulley appears well worn" });
  dest_dir=({
    PATH+"wrhs2","south",
    PATH+"wrhs3","east" });
}

init() {
  ::init();
  add_action("search","search");
}
search(str) {
  write("You find nothing.\n");
  return 1;
}
