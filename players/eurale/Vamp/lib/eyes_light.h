/*
  eyes_light.h
*/

#include "/players/eurale/defs.h"

/* -------- Make a light ---------- */
eyes_light() {

if(TPL < 7 || TPGEXP < 667 || TP->query_attrib("int") < 12) {
  write("You don't have the skills for that ability yet.\n");
  return 1; }

if(TPSP < 5) {
  write("You lack the magic to do that.\n");
  return 1; }

TP->add_spell_point(-5);
present("vampire fangs",TP)->set_glowing_eyes(1);
write("Your eyes "+HIY+"begin to glow"+NORM+".\n");
EFANGS->tell_my_room(
  capitalize(TPRN)+"'s eyes "+HIY+"begin to glow"+NORM+"!\n");
return 1;
}
