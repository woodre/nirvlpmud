/* Pier 2, Created <5/8/00> by Jara */

#include "defs.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="An old pier";
  long_desc=
    "  The old pier is approximately fifteen feet wide and made of wooden\n"+
    "planks. Several posts, used to tie boats to the dock, are spaced out\n"+
    "in wide intervals along the edges of the pier. The waters beneath the\n"+
    "pier are dark and somewhat murky, clouded by bits of seaweed and other\n"+
    "debris that have washed up against the shore. A small boat is docked\n"+
    "to the pier further south.\n";
  items=({
    "debris",
    "Small bits of wood and other items float within the tangles of seaweed",
    "planks",
    "The planks on the pier are worn and old. Many are splintered and waterlogged",
    "posts",
    "Thick, wooden posts, worn around the midsection from years of use",
    "waters",
    "The tide is in, and the waters are littered with seaweed and other debris",
    "seaweed",
    "Green strands of vegetation from the sea",
    "shore",
    "The shore stretches for several miles in each direction, covered with high\n"+
    "sand dunes and rock formations",
    "boat",
    "A small wooden craft, with a small mast and a sail" });
  dest_dir=({
    PATH+"walk4","north",
    PATH+"dock4","south" });
}
