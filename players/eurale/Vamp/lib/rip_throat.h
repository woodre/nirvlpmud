/*
  rip_throat.h - a deathblow type of spell
*/

#include "/players/eurale/defs.h"

rip_throat(str) {
  object target_obj;
  string target_name, msg;
  int target_hp, hp_percent, hp_max;

  hp_percent = 10;
  hp_max = 30;

if(TP->query_ghost()) {
  write("How can you attack anything? You are a ghost.\n");
  return 1; }

if(!str) {
  if(TP->query_attack() && TP->query_attack()->query_name()) {
  str = TP->query_attack()->query_name();
  if(!present(str, ROOM)) str = 0; }
}

if(!str) str = EFANGS->query_target_name();
if(!str) {
  write("You must specify who's throat you want to rip.\n");
  write("Use: rip [<who>]\n");
  return 1; }

if(TPL < 6 || TP->query_attrib("str") < 14) {
  write("You can't use that abilitiy yet.\n");
  return 1; }

target_obj = present(str, ROOM);
if(!target_obj) {
  write("'"+str+"' is not here.\n");
  return 1; }

if(TPL < 21 && !target_obj->query_npc()) {
  write("You can't use this spell against players!\n");
  return 1; }

target_name = capitalize(target_obj->query_name());

target_hp = target_obj->query_mhp() / 10;
  /* target's hp must be <= max_hp and <= max_hp */
if(target_obj->query_hp() > target_hp ||
    target_obj->query_hp() > hp_max) {
  write(target_name+" is TOO HEALTHY to die in one stroke.\n");
  return 1; }

if(TPSP < 2 * target_hp) {
    write("You don't have enough magic.\n");
  return 1; }

write("You grab "+capitalize(str)+"'s shoulder with one hand and "+
      target_obj->query_possessive()+"\n"+
      " head with the other and bend them apart\n"+
      "to expose "+target_obj->query_possessive()+" neck, then you rip "+
      target_obj->query_possessive()+"\n"+
      " throat out!\n");

EFANGS->tell_my_room(
  capitalize(TPRN) + " grabs "+capitalize(str)+"'s shoulder with one"+
  " hand and "+target_obj->query_possessive()+"\n"+
  " head with the other and bends them apart to expose "+
  target_obj->query_possessive()+"\n"+
  " neck, then "+TP->query_pronoun()+" rips "+
  target_obj->query_possessive()+" throat out!\n");

TP->add_spell_point(- 2 * target_hp);
target_obj->attacked_by(TP);
TP->attacked_by(target_obj);
target_obj->hit_player(target_hp);

return 1;
}

