#include "/players/softly/closed/ansi.h"
inherit "/players/softly/closed/std/monster";

reset(arg) {
  ::reset(arg);
  if (arg) return;
   
  set_name("peacie");
  set_alt_name("lady");   
  set_alias("woman");
  set_long("\nPeacie is a very young woman, her thin body barely developed.\n\
Her dark shoulder length hair is clipped back with bright\n\
barrettes revealing a pretty face with large surprised eyes.\n\
She is wearing a tight red sweater over a very short denim\n\
skirt.  Her bare feet swing while she runs her finger around\n\
the top edge of a can of cola.\n");
  set_short("Peacie");
  set_race("human");
  set_gender("female");
  set_level(9);
  set_al(0);
  set_aggressive(0);
  add_money(10+random(15));
}
