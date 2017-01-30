/*
  fumble_curse.h - This is a curse of fumbling.  It will make the cursed
                   creature drop 50 coins or one item that can be dropped
                   (not if worn or wielded though) whenever the player does
                   certain actions (see init).
*/

#include "defs.h"

/* -------- Fumble curse ---------- */
fumble_curse(str) {
  object obj, curse_obj, target_obj;
  string target_name;
  if (MY_PLAYER->query_ghost()) {
    write("How can you curse anything?  You are a ghost.\n");
    return 1;
  }
  if (MY_FANGS->query_in_flight()) {
    write("You cannot do that while in flight.\n");
    return 1;
  }
  if (!str) {
    write("You must specify who you want to curse with fumble.\n");
    write("Use: fumble <who>\n");
    return 1;
  }
  if (MY_LEVEL < 11 || MY_GUILD_EXP < 669) {
    write("You can't use that abilitiy yet.\n");
    return 1;
  }
  if (MY_SPELL_POINTS < 35) {
    write("You don't have enough spell points.\n");
    return 1;
  }
  target_obj=present(str, MY_ROOM);
  if (!target_obj) {
    write(capitalize(str)+" is not here.\n");
    return 1;
  }
  target_name = str;
  if (MY_LEVEL < 21 && !target_obj->query_npc()) {
    write("You can't use guild spells against players anymore!\n");
    return 1;
  }
  curse_obj=present("vamp fumble curse", target_obj);
  if (curse_obj) {
    write(capitalize(str)+" is already fumble cursed!\n");
    return 1;
  }
  if (!target_obj->query_npc() &&
      target_obj->query_level() > 19 &&
      MY_LEVEL < 21) {
    write("You can't fumble curse a wizard!\n");
    return 1;
  }
  MY_PLAYER->add_spell_point(- 35);
  obj=clone_object(VAMPIRE_FUMBLE_CURSE);
  move_object(obj, target_obj);
  write(capitalize(str)+" is now fumble cursed!\n");
  MY_FANGS->tell_my_room(MY_NAME_CAP+" looks at "+capitalize(str)+
                         " strangly, then smirks!");
  return 1;
}
