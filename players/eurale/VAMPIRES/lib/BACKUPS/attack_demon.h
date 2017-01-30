/*
  'grasp' and opponent for damage
*/

#include "/players/eurale/defs.h"

attack_demon(str) {
int success_chance, random_nbr, spell_damage, spell_cost;
object target_obj;
string spell_name, caster_msg, target_msg, room_msg;

if(TP->query_spell_dam()) return 1;

if (TP->query_ghost()) {
  write("You can't cast spells, you're dead...\n");
  return 1; }

if (str == TPRN) {
  write("The demon appears, shakes its head, then disappears...\n");
  return 1; }

if(!str)
if (TP->query_attack() && TP->query_attack()->query_name()) {
  str = TP->query_attack()->query_name();
  if (!present(str, ROOM)) str = 0;
  }

if (!str) str = PFANGS->query_target_name();

if (!str) {
  write("You must specify who the demon is to attack.\n");
  write("Use: demon [<who>]\n");
  return 1; }

if(TPXL < 5 || TPGEXP < 670 ||
  TP->query_attrib("sta") < 20 || TP->query_attrib("mag") < 20 ||
  TP->query_attrib("str") < 20 || TP->query_attrib("wil") < 20 ||
  TP->query_attrib("luc") < 20 || TP->query_attrib("ste") < 20 ||
  TP->query_attrib("pie") < 20 || TP->query_attrib("int") < 20) {
  write("You lack the skills necessary to use that ability.\n");
  return 1; }

if(TPBPTS < 2) {
  write("You lack the blood energy to summon a demon.\n");
  return 1; }

target_obj = present(str, ROOM);
if (!target_obj) {
  write("That creature is not here.\n");
  return 1; }

PFANGS->set_target_name(str);

PFANGS->add_BLOODPTS(-2);
  /* new code to switch over to spell_object */
spell_name = "Demon";
spell_damage = 12+random(32);
spell_cost = 25;

caster_msg =
  BOLD+"A HOWLING BLACK DEMON appears and attacks "+capitalize(str)+
  " and then disappears...\n"+NORM;

target_msg =
  BOLD+"A HOWLING BLACK DEMON appears and attacks you and then "+
  "disappears...\n"+NORM;

room_msg =
  BOLD+"A HOWLING BLACK DEMON appears and attacks "+capitalize(str)+
  " and then disappears...\n"+NORM;

TP->spell_object(target_obj, spell_name, spell_damage, spell_cost,
                        caster_msg, target_msg, room_msg);

  return 1;
}
