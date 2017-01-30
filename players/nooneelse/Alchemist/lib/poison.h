/*
  poison.h
*/

#include "/players/nooneelse/Alchemist/lib/defs.h"

/* -------- poison ---------- */
poison(str) {
  object obj, poison_obj, target_obj;
  string target_name;

  if (present(ALCHEMIST_PENANCE_MARK, this_player())) {
    write(NORM+CYN+"You cannot use that skill while you are doing penance.\n"+NORM);
    return 1;
  }
  if (MY_PLAYER->query_ghost()) {
    write(NORM+CYN+"How can you do anything? You are a ghost!\n"+NORM);
    return 1;
  }
  if (MY_PLAYER->query_ghost()) {
    write(NORM+CYN+"How can you attack anything? You are a ghost!\n"+NORM);
    return 1;
  }
  if (!str) str = MY_PLAYER->query_attack()->query_name();
  if (MY_PLAYER->query_attack() && str) {
    if (!present(str, MY_ROOM)) str = 0;
  }
  if (!str) str = MY_POUCH->query_target_name();
  if (!str) {
    write(NORM+CYN+"You must specify who you want to poison.\n"+
          "use: poison [<who>]\n"+NORM);
    return 1;
  }
  if (MY_GUILD_RANK < 60) {
    write(NORM+CYN+"You can't use that abilitiy yet.\n"+NORM);
    return 1;
  }
  if (MY_POUCH->query_quantity("arrow") < 1) {
    write(NORM+CYN+"You don't have the appropriate component (arrow).\n"+NORM);
    return 1;
  }
  if (MY_POUCH->query_quantity("adder's venom") < 1) {
    write(NORM+CYN+"You don't have the appropriate component (adder's venom).\n"+NORM);
    return 1;
  }
  if (MY_POUCH->query_quantity("vial of blood") < 1) {
    write(NORM+CYN+"You don't have the appropriate component (vial of blood).\n"+NORM);
    return 1;
  }
  if (MY_SPELL_POINTS < 30) {
    write(NORM+CYN+"You don't have enough spell points.\n"+NORM);
    return 1;
  }
  target_obj=present(str, MY_ROOM);
  if (!target_obj) {
    write(NORM+CYN+capitalize(str)+" is not here!\n")+NORM;
    return 1;
  }
  MY_POUCH->set_target_name(str);
  poison_obj=present("alchemist poison", target_obj);
  if (poison_obj) {
    write(NORM+CYN+capitalize(str)+" is already poisoned!\n"+NORM);
    return 1;
  }
  if (MY_LEVEL < 21 &&
      (!target_obj->query_npc() && !target_obj->query_pl_k())) {
    write(NORM+CYN+"You can't poison a player that hasn't set player-killer!\n"+NORM);
    return 1;
  }
  if (MY_LEVEL < 21 &&
      !target_obj->query_npc() &&
      !my_player()->query_pl_k()) {
    write(NORM+CYN+"You can't poison a player unless you set player-killer!\n"+NORM);
    return 1;
  }
  if (MY_LEVEL < 21 && !target_obj->query_npc()) {
    write(NORM+CYN+"You can't use guild spells against players anymore!\n"+NORM);
    return 1;
  }
  if (!target_obj->query_npc() &&
      target_obj->query_level() > 19 &&
      MY_LEVEL < 21) {
    write(NORM+CYN+"You can't poison a wizard!\n"+NORM);
    return 1;
  }
  MY_POUCH->subtract_quantity("arrow", 1);
  MY_POUCH->subtract_quantity("adder's venom", 1);
  MY_POUCH->subtract_quantity("vial of blood", 1);
  MY_PLAYER->add_spell_point(- 30);
  obj=clone_object(ALCHEMIST_POISON);
  obj->set_poisoner(MY_NAME);
  move_object(obj, target_obj);
  obj->start_poison(str);
  write("You throw some foul-smelling liquid on"+NORM+CYN+capitalize(str)+"!\n"+
        capitalize(str)+" is now poisoned!\n"+NORM);
  MY_POUCH->tell_my_room(
              NORM+CYN+MY_NAME_CAP+" throws some foul-smelling liquid on "+
              capitalize(str)+"!"+NORM);
  return 1;
}
