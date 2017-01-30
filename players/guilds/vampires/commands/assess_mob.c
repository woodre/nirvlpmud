/*
  Assess the wc/ac/level of a monster
*/

#include "/players/eurale/defs.h"

/* -------- Compare player's strength vs monster's ---------- */
assess_mob(str) {
  int level_diff, wc_diff, ac_diff;
  object target_obj;

if(!str) { write("Assess who?\n"); return 1; }

if(TPL < 5 || TP->query_attrib("int") < 12) {
  write("You don't have the skills to use that ability yet.\n");
  return 1; }

if(TPSP < 10) {
  write("You don't have enough magic left.\n");
  return 1; }

if(TPBPTS < 2) {
  write("You'll need more blood energy to do that.\n");
  return 1; }

target_obj=present(str, ROOM);
if(!target_obj) target_obj = find_living(str);
if(!target_obj || !living(target_obj)) {
  write(capitalize(str)+" cannot be found!\n");
  return 1; }

TP->add_spell_point(-10);
PFANGS->add_BLOODPTS(-2);

level_diff = TPL - target_obj->query_level();
if(level_diff > 0)
  write("You're higher in level.\n");
else if(level_diff < 0)
  write("You're lower in level.\n");
else write("You're about the same level.\n");

wc_diff = TPWC - target_obj->query_wc();
if(wc_diff > 0)
  write("You're higher in weapon class.\n");
else if(wc_diff < 0)
  write("You're lower in weapon class.\n");
else write("You're about the same weapon class.\n");

ac_diff = TPAC - target_obj->query_ac();
if(ac_diff > 0)
  write("You're higher in armor class.\n");
else if(ac_diff < 0)
  write("You're lower in armor class.\n");
else write("You're about the same armor class.\n");
return 1;
}
