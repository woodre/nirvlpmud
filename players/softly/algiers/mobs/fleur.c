#include "/players/softly/closed/ansi.h"
inherit "/players/softly/closed/std/monster";

reset(arg) {
  ::reset(arg);
  if (arg) return;
   
  set_name("fleur");
  set_alt_name("shopkeeper");   
  set_alias("fleur");
  set_long("\nFleur is young woman with a serious expression on her\n\
face.  Her very long hair flows freely over her shoulders.\n\
She wears a long soft dress of woodland colors and light\n\
leather sandals.  Her knowing fingers tease pieces of bark\n\
from a small stick and drop the pieces into a glass bowl.\n");
  set_short("Fleur, A shopkeeper");
  set_race("human");
  set_gender("female");
  set_level(12);
  set_attrib("pie", 20);
  set_al(600);
  set_aggressive(0);
  add_money(350+random(200));
}
