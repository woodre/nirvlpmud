/*
  grasp_enemy.h
*/

#include "defs.h"

/* -------- Grasp an opponent for damage ---------- */

grasp_enemy(str) {
int success_chance, random_nbr;
object target_obj;

if (MY_PLAYER->query_ghost()) {
  write("How can you attack anything? You are a ghost.\n");
  return 1; }

if (MY_FANGS->query_in_flight()) {
  write("You cannot do that while in flight.\n");
  return 1; }

if (str==MY_NAME) {
  write("Pervert!  Quit grasping yourself in public!\n");
  return 1; }

if (!str)
if (MY_PLAYER->query_attack() && MY_PLAYER->query_attack()->query_name()) {
  str = MY_PLAYER->query_attack()->query_name();
  if (!present(str, MY_ROOM)) str = 0;
  }

  if (!str) str = MY_FANGS->query_target_name();
  if (!str) {
    write("You must specify who you want to grasp.\n");
    write("Use: grasp [<who>]\n");
    return 1;
  }
  if (MY_LEVEL < 18 || MY_GUILD_EXP < 672) {
    write("You can't use that abilitiy yet.\n");
    return 1;
  }
  if (MY_SPELL_POINTS < 52) {
    write("You don't have enough spell points.\n");
    return 1;
  }
  target_obj = present(str, MY_ROOM);
  if (!target_obj) {
    write("That creature is not here.\n");
    return 1;
  }
  MY_FANGS->set_target_name(str);
/*
  if (MY_LEVEL < 21 &&
      (!target_obj->query_npc() && !target_obj->query_pl_k())) {
    write("You can't grasp a player that hasn't set player-killer!\n");
    return 1;
  }
  if (MY_LEVEL < 21 &&
      !target_obj->query_npc() &&
      !my_player()->query_pl_k()) {
    write("You can't grasp a player unless you set player-killer!\n");
    return 1;
  }
*/
  if (MY_LEVEL < 21 && !target_obj->query_npc()) {
    write("You can't use guild spells against players anymore!\n");
    return 1;
  }
  target_obj->attacked_by(MY_PLAYER);
  MY_PLAYER->attacked_by(target_obj);
/*
  target_obj->hit_player(25+random(50));
  Fixed by mizan. ILLEGAL SPELL! 60 hp dam for a measly 25 sp when
  the spell dam formula is SP = 2x + y = damage = x + random(y)
 */
/* Give em a chance to fail */
  success_chance = ((MY_GUILD_EXP - 666) + 1) * 2 + 75;
  random_nbr = random(100)+1;
  if (success_chance < random_nbr) {
    MY_PLAYER->add_spell_point(- 15);
    write("You missed in your attempt to grasp "+capitalize(str)+".\n");
    return 1;
  }
/*
  MY_PLAYER->add_spell_point(- 25);
  target_obj->hit_player(40+random(10));
*/
/* changing for rules. see doc on guild spells. -Bp */
  MY_PLAYER->add_spell_point(-52);
  /* 5 sp off doc settings for failure chance. */
  target_obj->hit_player(12+random(33));
/*
  target_obj->hit_player(25+random(50));
*/
  write("You reach out with your death cold hands and grasp "+
        capitalize(str)+"!\n");
  MY_FANGS->tell_my_room(
              MY_NAME_CAP+" reaches out with "+MY_PLAYER->query_possessive()+
              " death cold hands and grasps "+capitalize(str)+"!\n");
  return 1;
}
