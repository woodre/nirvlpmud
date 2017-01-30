/*
  scratch_enemy.h
*/

#include "defs.h"

/* -------- scratch an opponent for damage ---------- */
scratch_enemy(str) {
  int success_chance, random_nbr;
  object target_obj;
  if (MY_PLAYER->query_ghost()) {
    write("How can you attack anything? You are a ghost.\n");
    return 1;
  }
  if(MY_FANGS->query_in_flight()) {
    write("You cannot do that while in flight.\n");
    return 1;
  }
  if (!str)
    if (MY_PLAYER->query_attack() && MY_PLAYER->query_attack()->query_name()) {
      str = MY_PLAYER->query_attack()->query_name();
      if (!present(str, MY_ROOM)) str = 0;
    }
  if (!str) str = MY_FANGS->query_target_name();
  if (!str) {
    write("You must specify who you want to scratch.\n");
    write("Use: scratch [<who>]\n");
    return 1;
  }
  if (MY_LEVEL < 1 || MY_GUILD_EXP < 667) {
    write("You can't use that abilitiy yet.\n");
    return 1;
  }
  if (MY_SPELL_POINTS < 10) {
    write("You don't have enough spell points.\n");
    return 1;
  }
  target_obj = present(str, MY_ROOM);
  if (!target_obj) {
    write("That creature is not here.\n");
    return 1;
  }
  MY_FANGS->set_target_name(str);
  if (MY_LEVEL < 21 &&
      (!target_obj->query_npc() && !target_obj->query_pl_k())) {
    write("You can't scratch a player that hasn't set player-killer!\n");
    return 1;
  }
  if (MY_LEVEL < 21 &&
      !target_obj->query_npc() &&
      !MY_PLAYER->query_pl_k()) {
    write("You can't scratch a player unless you set player-killer!\n");
    return 1;
  }
  if (MY_LEVEL < 21 && !target_obj->query_npc()) {
    write("You can't use guild spells against players anymore!\n");
    return 1;
  }
  target_obj->attacked_by(MY_PLAYER);
  MY_PLAYER->attacked_by(target_obj);
/* Give em a chance to fail */
  success_chance = ((MY_GUILD_EXP - 666) + 1) * 2 + 75;
  random_nbr = random(100)+1;
  if (success_chance < random_nbr) {
    MY_PLAYER->add_spell_point(- 5);
    write("You missed "+capitalize(str)+" with your claws.\n");
    return 1;
  }
  MY_PLAYER->add_spell_point(- 10);
  target_obj->hit_player(2+random(6));
/* changed from 10+rand(10 to 2+rand(6) to conform to cost rules -Bp */
  write("You reach out with your claws and rake "+capitalize(str)+"!\n");
  MY_FANGS->tell_my_room(
              MY_NAME_CAP+" reaches out with "+MY_PLAYER->query_possessive()+
              " claws and rakes "+capitalize(str)+"!");
  return 1;
}
