/*
  damn.h
*/

#include "defs.h"

/* -------- Damn ---------- */
damn(str) {
  object obj, curse_obj, target_obj;
  string target_name;
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
    write("You must specify who you want to damn.\n");
    write("Use: damn [<who>]\n");
    return 1;
  }
  if (MY_LEVEL < 12 || MY_GUILD_EXP < 670) {
    write("You can't use that abilitiy yet.\n");
    return 1;
  }
  if (MY_SPELL_POINTS < 30) {
    write("You don't have enough spell points.\n");
    return 1;
  }
  target_obj=present(str, MY_ROOM);
  if (!target_obj) {
    write("That creature is not here.\n");
    return 1;
  }
  MY_FANGS->set_target_name(str);
  if (MY_LEVEL < 21 &&
      (!target_obj->query_npc() && !target_obj->query_pl_k())) {
    write("You can't damn a player that hasn't set player-killer!\n");
    return 1;
  }
  if (MY_LEVEL < 21 &&
      !target_obj->query_npc() &&
      !my_player()->query_pl_k()) {
    write("You can't damn a player unless you set player-killer!\n");
    return 1;
  }
  if (MY_LEVEL < 21 && !target_obj->query_npc()) {
    write("You can't use guild spells against players anymore!\n");
    return 1;
  }
  curse_obj=present("vamp curse", target_obj);
  if (curse_obj) {
    write(capitalize(str)+" is already damned!\n");
    return 1;
  }
  if (!target_obj->query_npc() &&
      target_obj->query_level() > 19 &&
      MY_LEVEL < 21) {
    write("You can't damn a wizard!\n");
    return 1;
  }
  MY_PLAYER->add_spell_point(- 30);
  obj = clone_object("/players/nooneelse/black/guild_damn_curse.c");
  obj->set_damner(MY_NAME);
  move_object(obj, target_obj);
  obj->start_curse(str);
  write(capitalize(str)+" is now damned!\n");
  MY_FANGS->tell_my_room(
              MY_NAME_CAP+" gives "+capitalize(str)+" the evil eye!");
  if(!MY_PLAYER->query_attack()) MY_PLAYER->attack_object(target_obj);
  if(!target_obj->query_attack()) target_obj->attack_object(MY_PLAYER);
  return 1;
}
