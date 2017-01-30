/* Boardwalk, Created <5/4/00> by Jara */

#include "defs.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="The boardwalk";
  long_desc=
    "  The boardwalk stretches out to the east and west, and a narrow, dirt\n"+
    "path leads up the beach through the high grasses. A covered building\n"+
    "stands beside the path, with an opening and a dimly lit light coming\n"+
    "from within. A large warehouse is to the east.\n";
  items=({
    "boardwalk",
    "The boardwalk is made of wooden planks and is approximately twelve feet wide",
    "path",
    "A well worn dirt path leading from the boardwalk into the high grass\n"+
    "just beyond the beach",
    "grasses",
    "The thick grass is several feet high",
    "building",
    "A small, enclosed building with a beacon light",
    "warehouse",
    "The warehouse is a large, two-story building" });
  dest_dir=({
    PATH+"walk2","east",
    PATH+"walk4","west",
    PATH+"path1","north" });
}
