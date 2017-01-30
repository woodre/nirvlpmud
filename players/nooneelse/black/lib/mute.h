#include "defs.h"

mute_enemy(str) {
int success_chance, random_nbr, spell_damage, spell_cost;
object target_obj;
string spell_name, caster_msg, target_msg, room_msg;

if(MY_PLAYER->query_spell_dam()) return 1;
if (MY_PLAYER->query_ghost()) {
  write("How can you attack anything? You are a ghost.\n");
  return 1; }

if (str==MY_NAME) {
  write("It makes no sense to mute yourself.\n");
  return 1; }

if (!str)
if (MY_PLAYER->query_attack() && MY_PLAYER->query_attack()->query_name()) {
  str = MY_PLAYER->query_attack()->query_name();
  if (!present(str, MY_ROOM)) str = 0;
  }

if (!str) str = MY_FANGS->query_target_name();

if (!str) {
  write("You must specify who you want to mute.\n");
  write("Use: mute [<who>]\n");
  return 1; }

if (MY_LEVEL < 17 || MY_GUILD_EXP < 671) {
  write("You can't use that abilitiy yet.\n");
  return 1; }

target_obj = present(str, MY_ROOM);
if (!target_obj) {
  write("That creature is not here.\n");
  return 1; }

MY_FANGS->set_target_name(str);

if(!target_obj->query_is_player()) {
  write("You can only mute players.\n");
  return 1; }

caster_msg =
  "You reach out with your "+BOLD+"DEATH COLD"+NORM+" hands and "+
  HIR+"GRASP "+NORM+capitalize(str)+"!\n";
target_msg = MY_NAME_CAP+" reaches out with "+MY_PLAYER->query_possessive()+
             BOLD+" DEATH COLD"+NORM+" hands and "+HIR+"GRASPS"+NORM+" you!";
room_msg = MY_NAME_CAP+" reaches out with "+MY_PLAYER->query_possessive()+
         BOLD+" DEATH COLD "+NORM+"hands and "+HIR+"GRASPS "+NORM+
         capitalize(str)+"!\n";

MY_PLAYER->spell_object(target_obj, spell_name, spell_damage, spell_cost,
                        caster_msg, target_msg, room_msg);

  return 1;
}
