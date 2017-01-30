#include "/players/softly/closed/ansi.h"
inherit "/players/softly/closed/std/monster";

reset(arg) {
  ::reset(arg);
  if (arg) return;
   
  set_name("rita");
  set_alt_name("shopkeeper");   
  set_alias("rita");
  set_long("\nRita is a middle aged woman who would be diminuitive if\n\
it were not for her large pregnant abdomen projecting before\n\
her.  She wears grey sweat pants and an oversized t-shirt\n\
that says 'baby' above an arrow pointing downward.  Her\n\
medium length hair curls out in all directions.  She greets\n\
everyone with a large open smile.\n");
  set_short("Rita, A shopkeeper");
  set_race("human");
  set_gender("female");
  set_level(12);
  set_attrib("sta", 20);
  set_al(-200);
  set_aggressive(0);
  add_money(400+random(150));
}
