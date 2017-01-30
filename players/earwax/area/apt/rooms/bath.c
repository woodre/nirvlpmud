#include "defs.h"
inherit ROOM;

void on_create() {
  set_light(0);
  set_area("area");
  set_short("Bathroom in Earwax's Old Apartment");
  set_long("This is a small, cramped bathroom.  Apparently it's laundry \
day, because there are no towels to be seen, but for the most part, it \
looks like a normal bathroom, only smaller, and probably a little messier \
although the toilet is spotless.  You can go back to the hallway to the \
south.");
  add_exit("south",APTR+"hall.c");
  add_desc("toilet","This toilet is "+HIW+"GLEAMING"+NORM+" and spotless.  \
Earwax hates shitting in a dirty toilet, and keeps it incredibly clean.  \
Too bad he doesn't treat the sink or shower the same.");
  add_desc("sink","There are beard trimmings in it in various shades of \
brown to red, apparently both Earwax and Midget trim their beards here, but \
neither of them cleans the sink out very well.");
  add_desc("shower","It's just like a regular shower, except smaller.");
}
