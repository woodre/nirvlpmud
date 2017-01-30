#include "def.h"

inherit AROOM;

reset(arg) {
  ::reset(arg);
  if(arg)return;
  set_light(1);
  short_desc="A gnarly oak tree";
  long_desc=
"  The higher branches of this gnarly oak tree offer an excellent\n"+
"vantage of the clearing below, but you find it difficult to see\n"+
"any of the surrounding terrain due to the taller trees around you.\n";
  items=({
    "clearing","I bet nobody ever reads these",
  });
  dest_dir=({
    PATH+"m6","down"
  });
}
long(str) {
  if(str=="clearing") view_room(PATH+"m6");
  else ::long(str);
}

