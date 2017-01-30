#include "/players/pestilence/ansi.h"
inherit "obj/weapon.c";

reset(arg) {
  ::reset(arg);
  if (arg) return;

  set_name("pen");
  set_alias("ink pen");
  set_short("an "+BLU+"ink pen"+NORM+" ");
  set_long(
"This is a "+BLU+"ink"+NORM+" pen used by Gopher to do his homework.\n"
  );
  set_type("dagger");
  set_class(14);
  set_weight(2);
  set_value(250);
  message_hit=({
    ""+HIR+"evicerated"+NORM+"","",   
    ""+RED+"lacerated"+NORM+"","",
    ""+HIK+"punctured"+NORM+"","",
    ""+HIK+"stabbed"+NORM+"","",
   ""+HIK+"jabbed"+NORM+"","",
    ""+BLU+"inked"+NORM+"","",
    ""+BLU+"skinned"+NORM+"","",
  });
}
