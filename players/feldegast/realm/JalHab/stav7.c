#include "defs.h"

inherit ROOM;

void reset(int arg) {
  if(!present("gambler"))
    move_object(clone_object(MON_PATH+"gambler.c"),this_object());
  if(arg) return;
  set_light(1);
  short_desc=HIY+"Casino"+NORM;
  long_desc=
"  This part of the tavern is well-decorated with persian carpets and\n"+
"brass fittings.  Scattered about the floor are several tables where\n"+
"gamblers play their games, groaning and shouting in jubilation as\n"+
"Lady Luck dictates.\n";
  items=({
    "carpets","Upon closer inspection, the persian carpets appear to be\n"+
              "cheap knock-offs",
    "fittings","The furniture has expensive brass fittings",
    "tables", "They appear to be playing craps with a pair of dice, but there\n"+
              "aren't any tables open for you to play at",
    "gamblers", "It appears to be a mixed crowd of people, with some young sheiks,\n"+
                "a few merchants, and a smattering of peasants",
  });
  dest_dir=({
    PATH+"stav6.c","south",
  });
}
