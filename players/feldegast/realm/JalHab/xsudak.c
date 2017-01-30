#include "defs.h"

inherit MAPROOM;

void reset(int arg)
{
  if(arg) return;
  set_light(1);
  short_desc="City of "+HIR+"Sudakan"+NORM;
  long_desc=
"  Wind and sand buffet themselves against the city of Sudakan, and\n"+
"are turned back by its mighty sandstone walls.  The city has no\n"+
"visible means of supporting itself except by trade, which it gets\n"+
"in abundance being at a crossroads between several major trade routes.\n"+
"It's gates are spread open so that travellers may enter with their\n"+
"coin and others goods.\n";
  items=({
    "sudakan","The city of Sudakan is surrounded by tall sandstone walls\n"+
              "that protect it from the wind and sand.  Inside the city,\n"+
              "you can make out large plazas at each of the cardinal\n"+
              "points, with long curving streets connecting them",
    "walls","The walls surround the city in a complete circle",
    "gates","They're tall wooden gates that guard the city from the rare\n"+
            "bandit attack",
  });
  dest_dir=({
    "blank","north",
    "blank","west",
    "blank","east",
    "blank","south",
  });

}

void init() {
  ::init();
  add_action("cmd_enter","enter");
}

int cmd_enter(string str) {
  if(!str || (str!="gates" && str!="sudakan") && str!="gate" && str!="city") {
    notify_fail("Enter what?\n");
    return 0;
  }
  write("You enter the gates of Sudakan.\n");
  say(TPN+" enters the gates of Sudakan.\n");
  move_object(TP,PATH+"sgate.c");
  say(TPN+" enters the gates of Sudakan.\n");
  command("look",TP);
  return 1;
}

