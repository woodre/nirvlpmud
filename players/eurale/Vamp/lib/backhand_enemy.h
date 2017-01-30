/*
  backhand_enemy.h
*/

#define "/players/eurale/defs.h"

/* -------- Backhand an opponent for damage ---------- */
backhand_enemy(str) {
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

if(!str) str = EFANGS->query_target_name();
if(!str) {
  write("You must specify who you want to backhand.\n");
  write("Use: backhand [<who>]\n");
  return 1; }

if(TPL < 12 || TPGEXP < 668 || TP->query_attrib("str") < 16) {
  write("You lack the skills for backhand.\n");
  return 1; }

target_obj = present(str, ROOM);
if(!target_obj) {
  write("'"+str+"' is not here.\n");
  return 1; }

EFANGS->set_target_name(str);
if(TPXL < 5 && !target_obj->query_npc()) {
  write("You must be higher level to use backhand in PK.\n");
  return 1; }

  /* new code to switch over to spell_object */
spell_name = "Backhand";
spell_damage = 10+random(20);
spell_cost = 20;
caster_msg =
  "\n"+
  "You "+BOLD+"SLAP "+capitalize(str)+" HARD"+NORM+" across the face "+
  "making them "+HIR+"STAGGER BACK"+NORM+".\n\n";

target_msg =
  capitalize(TPRN)+BOLD+" SLAPS YOU HARD"+NORM+" across the face "+
  "making you "+HIR+"STAGGER BACK"+NORM+"!\n\n";

room_msg =
  capitalize(TPRN)+BOLD+" SLAPS "+capitalize(str)+" HARD"+NORM+
  " across the face!\n";

TP->spell_object(target_obj, spell_name, spell_damage, spell_cost,
                          caster_msg, target_msg, room_msg);

return 1;
}
