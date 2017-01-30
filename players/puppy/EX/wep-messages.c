/*
This is an example of a simple weapon with modified messages.
			-Feldegast
*/

#include "/players/feldegast/defines.h"

inherit "obj/weapon.c";

reset(arg) {
  ::reset(arg);
  if (arg) return;

  set_name("bow");
  set_alias("shortbow");
  set_short(HIW+"The Silver Bow"+NORM);
  set_long(
"This is a shortbow made from a rare silverwood tree.\n"
  );
  set_type("bow");
  set_class(18);
  set_weight(2);
  set_value(1500);
  message_hit=({
    "impaled","",   
    "pierced","",
    "wounded","",
    "shot","",
    "hit","",
    "winged","",
    "grazed","",
  });
}

