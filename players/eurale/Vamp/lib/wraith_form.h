/*
  wriath_form.h
*/

#include "/players/eurale/defs.h"

/* --------------- Sneak into a room --------------- */
wraith_form(str) {
  int success_percent;

if(!str || str != "form") return 0;
if(TPL < 14 || TPGEXP < 668) {
  write("You haven't mastered the skills for that ability.\n");
  return 1; }

  /* already sneaking? */
if(EFANGS->query_sneak_seconds() > 0) {
  EFANGS->set_sneak_seconds(0);
  if(TP->query_invis() > 0) TP->visible();
  write("You've changed back from wraith form to normal form.\n");
  EFANGS->tell_my_room(capitalize(TPRN)+" slowly fades into view...");
  return 1; }

  /* base time */
EFANGS->set_sneak_seconds(5 + TPL);
  /* base chance */
success_percent = 25 + (TPL * 2);
  /* dex & int adjustments */
if (TPINT > TPL && TPSTE > TPL)
  success_percent += 10;
else if(TPINT < TPL || TPSTE < TPL)
  success_percent -= 5;
else if(TPINT >= TPL || TPSTE >= TPL)
  success_percent += 5;

  /* now do it */
if(TPSP < 25) {
    write("You don't have enough spell points.\n");
  return 1; }

TP->add_spell_point(-25);
if(success_percent >= random(100)) {
  TP->set_invs_sp();
  write("You feel yourself starting to dematerialize....\n");
  EFANGS->tell_my_room(
    capitalize(TPRN)+" fades into the surrounding terrain...\n");
  }
else { EFANGS->set_sneak_seconds(0); }
EFANGS->start_wraith_form();
return 1;
}
