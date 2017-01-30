#include "/players/softly/closed/ansi.h"
inherit "/players/softly/closed/std/monster";

reset(arg) {
  ::reset(arg);
  if (arg) return;
   
  set_name("octave");
  set_alt_name("gardener");   
  set_alias("man");
  set_long("\nOctave is a very large man, his muscular arms stretching\n\
the sleeves of his dark blue t-shirt.  Long locks of hair fall\n\
forward onto his sweaty forehead.  His jeans are covered\n\
with dust from working the earth and he stands beside a large\n\
tree that he was planting.  He glances up then glances at the\n\
slightly open door as you approach.\n");
  set_short("Octave");
  set_race("human");
  set_gender("male");
  set_level(17);
  set_attrib("str", 20);
  set_al(0);
  set_aggressive(0);
  add_money(1800+random(300));
}
