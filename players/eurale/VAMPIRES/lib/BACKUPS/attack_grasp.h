/*
  'grasp' and opponent for damage
*/

#include "/players/eurale/defs.h"

attack_grasp(str) {
int success_chance, random_nbr, spell_damage, spell_cost;
object target_obj;
string spell_name, caster_msg, target_msg, room_msg;

if(TP->query_spell_dam()) return 1;

if (TP->query_ghost()) {
  write("How can you attack anything? You are a ghost.\n");
  return 1; }

if (str == TPRN) {
  write("Pervert!  Quit grasping yourself in public!\n");
  return 1; }

if (!str)
if (TP->query_attack() && TP->query_attack()->query_name()) {
  str = TP->query_attack()->query_name();
  if (!present(str, ROOM)) str = 0;
  }

if (!str) str = PFANGS->query_target_name();

if (!str) {
  write("You must specify who you want to grasp.\n");
  write("Use: grasp [<who>]\n");
  return 1; }

if(TPL < 19 || TPGEXP < 670 || TP->query_attrib("ste") < 20 ||
     TP->query_attrib("str") < 20) {
  write("You lack the skills necessary to use that ability.\n");
  return 1; }

target_obj = present(str, ROOM);
if (!target_obj) {
  write("That creature is not here.\n");
  return 1; }

if(TPBPTS < 2) {
  write("You lack the blood energy to grasp.\n");
  return 1; }

PFANGS->set_target_name(str);

if(!target_obj->query_npc()) {
  write("You CANNOT use this spell against players!\n");
  return 1; }

PFANGS->add_BLOODPTS(-2);
  /* new code to switch over to spell_object */
spell_name = "Grasp";
spell_damage = 12+random(30);
spell_cost = 25;
caster_msg =
  "You reach out with your "+BOLD+"DEATH COLD"+NORM+" hands and "+
  HIR+"GRASP "+NORM+capitalize(str)+"!\n";
target_msg = capitalize(TPRN)+" reaches out with "+TP->query_possessive()+
           BOLD+" DEATH COLD"+NORM+" hands and "+HIR+"GRASPS"+NORM+" you!";
room_msg = capitalize(TPRN)+" reaches out with "+TP->query_possessive()+
         BOLD+" DEATH COLD "+NORM+"hands and "+HIR+"GRASPS "+NORM+
         capitalize(str)+"!\n";

TP->spell_object(target_obj, spell_name, spell_damage, spell_cost,
                        caster_msg, target_msg, room_msg);

  return 1;
}
