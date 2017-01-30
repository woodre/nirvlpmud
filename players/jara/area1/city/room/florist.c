/* City Florist, Created <8/05/01> by Jara */

#include "defs.h"
#include "/players/jara/misc/ansi.h"
inherit "room/room";

reset(arg) {

object ob;

  if(arg) return;
  set_light(1);
  short_desc="Cherry Hill Florist";
  long_desc=
    "  The front of the store is very chilly and filled with flowers of many\n"+
    "varieties. There is a counter that spans the entire width of the shop,\n"+ 
    "with a beautiful arrangement of pink roses and tulips that have been\n"+
    "pulled open. A sign hangs on the wall just behind the counter, and the\n"+
    "door in the eastern wall leads to the street.\n";
    items=({
    "sign",
    "."+HIR+".............................."+NORM+".\n"+
    ".                              .\n"+
    ".  1. A pretty"+HIY+" Rose"+NORM+"     150 c  .\n"+
    ".  2. An Iris           100 c  .\n"+
    ".  3. A delicate"+HIR+" Rose"+NORM+"   200 c  .\n"+
    ".  4. A Lily            100 c  .\n"+
    ".  5. A friendship"+HIM+" Rose"+NORM+" 150 c  .\n"+
    ".  6. Six"+BLU+" Violets"+NORM+"       150 c  .\n"+ 
    ".                              .\n"+
    ".      "+HIW+"Purchase"+NORM+" by the "+HIW+"#"+NORM+"       .\n"+
    ".                              .\n"+
    "."+HIR+".............................."+NORM,
    "flowers", 
    "The delicately scented flowers come in many types, colors, and shapes",
    "arrangement",
    "The arrangement is standing in a crystal vase, etched with what appears\n"+
    "to be leaves",
    "roses",
    "These roses are very hearty, yet uniquely beautiful",
    "tulips",
    "The tulips are a dusty pink in color, and the petals have been opened",
    "wall",
    "The walls of the florist have been painted an off white",
    "counter",
    "A simple countertop, made of an offwhite material",
    "door",
    "The doors lead back to the street" });
  dest_dir=({ 
    "/players/jara/area1/city/road13.c","east" });
}
