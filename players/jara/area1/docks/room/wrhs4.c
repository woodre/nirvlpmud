/* SE corner of the warehouse, Created <4/28/00> by Jara */

#include "defs.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="A warehouse";
  long_desc=
    "  The warehouse is a large, open building with high ceilings and very\n"+
    "muddied floors. Stacks of crates have been piled against the walls and\n"+
    "in the center of the warehouse. A wide double door is closed in the\n"+
    "southern wall, and another, smaller door is open beside it. An office\n"+
    "is to the north.\n";
  items=({
    "mud",
    "The mud is mostly made of moist sand, hardened and crumbling",
    "floors",
    "Stone floors, muddied from the high use of the building",
    "crates",
    "Wooden crates of various sizes, splintered from use and several are\n"+
    "covered in a light layer of dust",
    "door",
    "The double doors slide open for a wider enterance into the warehouse",
    "office",
    "A small office in the northeastern corner of the warehouse" });
  dest_dir=({
    PATH+"wrhs3","north",
    PATH+"wrhs2","west",
    PATH+"walk1","out" });
}
