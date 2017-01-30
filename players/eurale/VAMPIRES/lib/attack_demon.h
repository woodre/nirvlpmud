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

if(!str && !TP->query_attack())
{
  write("Use: demon [<who>]\n");
  return 1;
}

if(!str)
  target_obj = TP->query_attack();

if(!target_obj)
  target_obj = present(str, ROOM);

if(!target_obj && !present(str, ROOM))
{
  write("You don't see "+str+" here.\n");
  return 1;
}

if(TPXL < 5 || TPGEXP < 670 ||
  TP->query_attrib("cha") < 20 || TP->query_attrib("dex") < 20 ||
  TP->query_attrib("sta") < 20 || TP->query_attrib("mag") < 20 ||
  TP->query_attrib("str") < 20 || TP->query_attrib("wil") < 20 ||
  TP->query_attrib("luc") < 20 || TP->query_attrib("ste") < 20 ||
  TP->query_attrib("pie") < 20 || TP->query_attrib("int") < 20) {
  write("You lack the skills necessary to use that ability.\n");
  return 1; }

if(TPBPTS < 2) {
  write("You lack the blood energy to summon a demon.\n");
  return 1; }

PFANGS->add_BLOODPTS(-2);
  /* new code to switch over to spell_object */
spell_name = "Demon";
spell_damage = random(33) + 12;
spell_cost = 25;

caster_msg =
  BOLD+"A HOWLING BLACK DEMON appears and attacks "+capitalize(target_obj->query_name())+
  " and then disappears...\n"+NORM;

target_msg =
  BOLD+"A HOWLING BLACK DEMON appears and attacks you and then "+
  "disappears...\n"+NORM;

room_msg =
  BOLD+"A HOWLING BLACK DEMON appears and attacks "+capitalize(target_obj->query_name())+
  " and then disappears...\n"+NORM;
  

  TP->spell_object(target_obj, spell_name, spell_damage, spell_cost,
                        caster_msg, target_msg, room_msg);
  TP->set_spell_dtype("other|evil");

  return 1;
}
