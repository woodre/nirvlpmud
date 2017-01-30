/* SW corner of the warehouse, Created <4/28/00> by Jara */

#include "defs.h"
inherit "room/room";

object ob;

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="A warehouse";
  long_desc=
    "  The warehouse opens up into a large, open space, with crates pushed\n"+
    "against the wall. A round table stands in the center, lit by a rusted\n"+ 
    "lamp, and several chairs surround the table. An empty mug, tipped over\n"+
    "on the tabletop, has stained the surface with a black colored drink.\n"+
    "A window in the southern wall lets light in through the thick layer of\n"+
    "grime\n";
  items=({
    "crates",
    "The wooden crates vary in size. The wood is splintered and worn, and\n"+
    "many of the crates are empty",
    "table",
    "A sturdy, metal table with four legs and a hole in the center",
    "lamp",
    "The lamp stands approximately five feet high and dimly lights the table",
    "chairs",
    "The chairs have been pushed away from the table, and one is sideways on\n"+
    "the floor",
    "mug",
    "A cracked, ceramic mud, light in color. A damp ring of liquid has\n"+
    "seeped from the cup",
    "window",
    "A rectangular window high on the wall. A thick layer of dust blocks out\n"+
    "much of the light" });
  dest_dir=({
    PATH+"wrhs1","north",
    PATH+"wrhs4","east" });
  if(!present("worker")) {
    ob=clone_object("/players/jara/area1/docks/mon/worker1.c");
    move_object(ob,this_object());
  }
}
