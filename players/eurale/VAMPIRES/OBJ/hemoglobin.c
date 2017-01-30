/* 42 tox / 150 heal = .28 = 12 coins/pt healed
   12 coins/pt * 150 pts = 1800 coins
   1800 coins * 2/3 for single sps heal = 1200 coins
       calculated per /doc/build/RULES/heals/heal3 - Eurale */


/* Approved by Pain, 6/5/03 */
#include "/open/ansi.h"
inherit "/obj/generic_heal.c";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

set_name("hemoglobin");
add_alias("globin");
set_short(HIR+"hemoglobin"+NORM);
set_long(
  "A protein yielding substance that carries oxygen from the lungs to the\n"+
  "tissues and carbon dioxide from the tissues to the lungs.  A quick way to\n"+
  "more energy is to 'transfuse' it.\n");

add_cmd("transfuse");
set_type("transfusions");
set_type_single("transfusion");
set_msg(
  HIR+"You feel an increase of energy as you infuse the hemoglobin.\n"+NORM);
set_heal(0,45+random(10));
set_charges(3);
  set_msg_precharges(HIR+"^"+NORM);
  set_msg_postcharges(HIR+"^"+NORM);
set_soak(14);
set_value(400);
set_msg_soaked(
  HIR+"Your body refuses to be infused any more and convulses.\n"+NORM);
set_empty_msg(
  HIR+"You transfuse the last of your hemoglobin.\n"+NORM);
}
