#include "/players/pestilence/ansi.h"
inherit "obj/weapon.c";

reset(arg) {
  ::reset(arg);
  if (arg) return;

  set_name("quill");
  set_alias("quill");
  set_short("a quill");
  set_long(
"This is a white quill about 10 inches in length.  It is fat around the bottom and\n"+
"pointed at the other end.  This quill comes from the body of Porcupine.\n"
  );
  set_type("exotic");
  set_class(14);
  set_weight(2);
  set_value(250);
  message_hit=({
    ""+HIR+"evicerated"+NORM+"","",   
    ""+RED+"lacerated"+NORM+"","",
    ""+HIK+"punctured"+NORM+"","",
    ""+HIK+"stabbed"+NORM+"","",
    ""+HIK+"jabbed"+NORM+"","",
    ""+WHT+"poked"+NORM+"","",
    ""+WHT+"grazed"+NORM+"","",
  });
}
