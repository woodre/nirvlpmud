/*
  scratch_enemy.h
*/

#include "defs.h"

/* -------- scratch an opponent for damage ---------- */
scratch_enemyx(str) {
  int success_chance, random_nbr, spell_damage, spell_cost;
  object target_obj;
  string spell_name, caster_msg, target_msg, room_msg;

  if(MY_PLAYER->query_spell_dam()) return 1;
  if (MY_PLAYER->query_ghost()) {
    write("How can you attack anything? You are a ghost.\n");
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

  /* new code to switch over to spell_object */
  spell_name = "Scratch";
  spell_damage = 5+random(20);
  spell_cost = 15;
caster_msg =
  "\n"+
  "You reach out with your "+BOLD+"TALONED CLAWS"+NORM+
  " and "+HIC+"RAKE "+NORM+capitalize(str)+"!\n\n";

  target_msg = MY_NAME_CAP+" reaches out with "+MY_PLAYER->query_possessive()+
               " claws and rakes you!\n";
  room_msg = MY_NAME_CAP+" reaches out with "+MY_PLAYER->query_possessive()+
             " claws and rakes "+capitalize(str)+"!\n";
  MY_PLAYER->spell_object(target_obj, spell_name, spell_damage, spell_cost,
                          caster_msg, target_msg, room_msg);

  return 1;
}
