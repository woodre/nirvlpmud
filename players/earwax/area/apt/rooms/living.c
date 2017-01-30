#include "defs.h"
inherit ROOM;

void on_create() {
  set_area("area");
  set_short("Living Room in Earwax's Old Apartment");
  set_long("You're sitting in the living room in Earwax's old \
apartment.  To the north is the computer area, where Earwax and his \
roomate Midget have their computers.  To the south is the TV area, \
where they have the PSIIs, TV, VCR, etc.  Earwax's brother is probably \
over there getting high and drinking Earwax's beer.  The rest of the \
apartment is to the east, or you can go west to leave.  There are a \
couple of couches here, but I wouldn't advise sitting on them or even \
getting too close, as Earwax and Midget have probably done some nasty \
things on them (although never at the same time) when drunk.");
  add_desc("couches", "&couch_desc");
  add_desc("couch", "&couch_desc");
  add_desc("stains","You don't know what they're from, but there are a lot.");
  add_desc("springs","Yup, they are springs, and they're sticking out from the back of the couch, all right.");
  add_exit("west",APTR+"entry.c");
  add_exit("east",APTR+"hall.c");
  add_exit("north",APTR+"comps.c");
  add_exit("south",APTR+"tv_room.c");
}

void couch_desc() {
  write(line_wrap("These couches have seen better days.  There are \
springs jutting from one the backs, stains all over them from unknown \
(probably beer, spooge, and worse), sources, cigarette burn-marks, and \
just a generally unappealing aura to them.\n"));
}
