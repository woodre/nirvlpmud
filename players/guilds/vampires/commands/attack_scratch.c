/*
  scratch_enemy.h
*/

#include "/players/eurale/defs.h"

/* -------- scratch an opponent for damage ---------- */
attack_scratch(str) {
  int success_chance, random_nbr, spell_damage, spell_cost;
  object target_obj;
  string spell_name, caster_msg, target_msg, room_msg;

if(TP->query_spell_dam()) return 1;

if(TP->query_ghost()) {
  write("How can you attack anything? You are a ghost.\n");
  return 1; }

if(!str)
  if(TP->query_attack() && TP->query_attack()->query_name()) {
  str = TP->query_attack()->query_name();
    if(!present(str, ROOM)) str = 0; }

if(!str) str = PFANGS->query_target_name();
if(!str) {
  write("You must specify who you want to scratch.\n");
  write("Use: scratch [<who>]\n");
  return 1; }

target_obj = present(str, ROOM);
if(!target_obj) {
  write("That creature is not here.\n");
  return 1; }

if(TPBPTS < 2) {
  write("You lack the blood energy to scratch.\n");
  return 1; }

if(TPL < 7 || TPGEXP < 667 || TP->query_attrib("str") < 16) {
  write("You cannot use that ability yet.\n");
  return 1; }

PFANGS->set_target_name(str);

PFANGS->add_BLOODPTS(-2);
  /* new code to switch over to spell_object */
spell_name = "scratch";
spell_damage = 1 + random(20);
spell_cost = 10;
caster_msg =
  "\n"+
  "You reach out with your "+BOLD+"TALONED CLAWS"+NORM+
  " and "+BOLD+"RAKE "+NORM+capitalize(str)+"!\n\n";

target_msg =
  capitalize(TPRN)+" reaches out with "+TP->query_possessive()+
  BOLD+" TALONED CLAWS"+NORM+" and "+BOLD+"RAKES"+NORM+" you!\n";

room_msg =
  capitalize(TPRN)+" reaches out with "+TP->query_possessive()+
  BOLD+" TALONED CLAWS"+NORM+" and "+BOLD+"RAKES "+NORM+
  capitalize(str)+"!\n";

TP->spell_object(target_obj, spell_name, spell_damage, spell_cost,
                      caster_msg, target_msg, room_msg);

  return 1;
}
