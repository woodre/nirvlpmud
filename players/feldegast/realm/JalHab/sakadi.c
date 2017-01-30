#include "defs.h"

inherit ROOM;

void reset(int arg) {
  if(arg) return;
  move_object(clone_object(MON_PATH+"sakadia.c"),this_object());
  set_light(1);
  short_desc="Sakadi's Home";
  long_desc=
"  This is the home of Abdullah Sakadi, the merchant prince.  It\n\
is impeccably decorated with courtyards and gardens, ivory fountains\n\
and marble tiles.\n";
  items=({
    "home", "It is practically a palace",
    "courtyards", "The home has several courtyards in it",
    "gardens", "The gardens are irrigated by an ingenious system",
    "fountains", "They are made of ivory",
    "tiles", "They are made of marble",
  });
  dest_dir=({
    PATH+"salley.c", "leave",
  });
}
