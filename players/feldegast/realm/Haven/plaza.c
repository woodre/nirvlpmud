#include "../def.h"
inherit ROOM;
reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="Plaza of the Merchants";
  long_desc=
"  Marble street, Haven's main thoroughfare, widens here to form the\n"+
"Plaza of the Merchants, a place of commerce for as long as Haven\n"+
"itself has existed.  In the center of the plaza is the large statue\n"+
"of some ancient hero.  To the south is an armour shop.  Marble street\n"+
"runs east-west while bronze street starts to the north.\n";
  items=({

  });
  dest_dir=({
    PATH+"Haven/bronze1","north",
    PATH+"Haven/marble6","west",
    PATH+"Haven/marble7","east",
    PATH+"Haven/armor_shop","south"
  });
}   
