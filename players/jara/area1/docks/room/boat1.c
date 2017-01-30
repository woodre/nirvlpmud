/* A small boat, Created <5/8/00> by Jara */

#include "defs.h"
inherit "room/room";

reset(arg) {

object ob;

  if(arg) return;
  set_light(1);
  short_desc="A sailing ship";
  long_desc=
    "  The deck of the ship has recently been scrubbed clean, and a bucket\n"+
    "of water sits near a filthy mop. A cabin in the center of the ship\n"+
    "leads to the hull, and a small pile of fishing nets have been piled\n"+
    "near the stern. A plank leads back to the pier.\n";
  items=({
    "door",
    "The door of the cabin holds a small handle with a keyhole",
    "handle",
    "A round, metal handle, rusted at the base",
    "keyhole",
    "A small keyhole just under the handle of the door",
    "water",
    "The water within the bucket has bits of debris and dirt floating\n"+
    "on the surface",
    "debris",
    "The debris within the water is mostly bits of wood and pieces of\n"+
    "netting",
    "dirt",
    "Bits of mud and dirt from the deck of the ship",
    "deck",
    "The wooden deck of the ship is made of darkly colored planks. The wood is well\n"+
    "worn, and several scratches and deep grooves are visible",
    "bucket",
    "An old, rusty bucket with a metal handle. The water is filthy\n",
    "mop",
    "A mop, used to scrub the upper deck. It has a long handle and a white mop",
    "cabin",
    "A small, wooden cabin with a window in each side. The rear of the cabin holds\n"+
    "a door",
    "rail",
    "The railing of the ship is carved of wood and rounded at the top",
    "plank",
    "The narrow, wooden plank is approximately three feet wide and made\n"+
    "old, wooden boards",
    "seaweed",
    "The seaweed within the nets is still moist and a deep green in color",
    "nets",
    "The fishing nets have been placed beside the rail of the ship, near the stern.\n"+
    "Small bits of seaweed and debris still cling to the netting" });
  dest_dir=({ 
    PATH+"dock4","pier" });
  if(!present("deckhand")) {
    ob=clone_object("/players/jara/area1/docks/mon/hand.c");
    move_object(ob,this_object());
  }
}
void init() {
  ::init();

  add_action("door_open","open");
}

door_open(str) {
  if(!str) {
    write("What are you trying to open?\n");
  return 1;
}

  if(str == "door") {
  write("The door is locked.\n");
  return 1;
  }
}
