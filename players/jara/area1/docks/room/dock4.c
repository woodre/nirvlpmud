/* Pier 2, Created <5/8/00> by Jara */

#include "defs.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="An old pier";
  long_desc=
    "  The southern end of the pier extends into deeper waters. A small,\n"+
    "sailing craft is docked at the far end of the pier, tied to one of\n"+
    "the numerous posts that line the edges of the pier. The boat has a\n"+
    "small mast, and a worn, grey sail is tied down to the boat. A plank\n"+
    "leads from the boat to the pier.\n";
  items=({
    "waters",
    "The waters beneath the pier are a bit clearer here. Several pieces of seaweed\n"+
    "cling to the pilings that hold up the pier",
    "craft",
    "A wooden sailing ship, approximately twenty feet long",
    "boat",
     "A wooden sailing ship, approximately twenty feet long",
    "ship",
     "A wooden sailing ship, approximately twenty feet long",
    "posts",
    "Thick, wooden posts, worn around the midsection from years of use",
    "mast",
    "The mast of the ship is a tall, round post rising upwards from the center\n"+
    "boat",
    "sail",
    "A well worn sail, tied down while the boat is docked",
    "plank",
    "A wooden plank used to walk from the pier to the deck of the boat" });
  dest_dir=({
    PATH+"dock3","north",
    PATH+"boat1","board" });
}
