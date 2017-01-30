inherit "obj/armor";
#include "/players/jareel/ansi.h"
reset() {
  set_name("yelmalian shield");
  set_alias("shield");
  set_short("A "+BOLD+YEL+"Yelmalian "+NORM+"Shield");
  set_long(
"This shield is golden in color.  A crest of the\n"+
"sun is placed in the centre of the shield.\n");
  set_ac(1);
  set_type("shield");
  set_weight(2);
  set_value(500);
}
