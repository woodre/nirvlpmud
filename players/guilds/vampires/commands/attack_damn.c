/*
  scratch_enemy.h
*/

#include "/players/eurale/defs.h"

/* -------- scratch an opponent for damage ---------- */
attack_damn(str) {
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
  write("You must specify who you want to damn.\n");
  write("Use: damn [<who>]\n");
  return 1; }

if(TPL < 17 || TPGEXP < 669 || TP->query_attrib("int") < 19) {
  write("You lack the skills necessary for that spell.\n");
  return 1; }

target_obj = present(str, ROOM);
if(!target_obj) {
  write("That creature is not here.\n");
  return 1; }

if(TPBPTS < 2) {
  write("You lack the blood energy to damn.\n");
  return 1; }

PFANGS->set_target_name(str);

PFANGS->add_BLOODPTS(-2);
  /* new code to switch over to spell_object */
spell_name = "damn";
spell_damage = 5 + random(25);
spell_cost = 20;
caster_msg =
  "     You concentrate your "+BOLD+"MENTAL POWER"+NORM+" and "+HIR+
  "DAMN THE SOUL"+NORM+" of "+capitalize(str)+"!\n";

target_msg =
  capitalize(TPRN)+" "+BOLD+"GLARES"+NORM+" at you until your "+HIR+
  "SOUL FEELS DAMNED"+NORM+"!\n";

room_msg =
  capitalize(TPRN)+" concentrates "+TP->query_possessive()+BOLD+
  " MENTAL POWERS"+NORM+" and "+capitalize(str)+" "+HIY+
  "HOWLS IN PAIN"+NORM+"!\n";

TP->spell_object(target_obj, spell_name, spell_damage, spell_cost,
                      caster_msg, target_msg, room_msg);

  TP->set_spell_dtype("other|mental");
  return 1;
}
