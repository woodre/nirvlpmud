/*
  hell_fire.h
*/

#include "defs.h"

/* -------- Hellfire ---------- */
hell_fire() {
  object target_obj, next_target_obj;
  string target_name;
  int target_hit;
  if (MY_PLAYER->query_ghost()) {
    write("How can you attack anything? You are a ghost.\n");
    return 1;
  }
  if (MY_LEVEL < 12 || MY_GUILD_EXP < 670) {
    write("You can't use that abilitiy yet.\n");
    return 1;
  }
  if (MY_SPELL_POINTS < 25) {
    write("You don't have enough spell points.\n");
    return 1;
  }
  if (MY_FANGS->query_hell_fire_pause()) {
    MY_FANGS->set_hell_fire_pause(0);
    return 1;
  }
  MY_FANGS->set_hell_fire_pause(1);
  target_obj = first_inventory(MY_ROOM);
  if (target_obj->query_npc() &&
      living(target_obj) &&
        !target_obj->is_pet() &&
      !target_obj->am_i_a_servant()  &&
      !target_obj->is_kid())
    target_name = lower_case(target_obj->query_name());
  while (target_obj) {
    next_target_obj=next_inventory(target_obj);
    if (target_obj->query_npc() &&
        living(target_obj) &&
        !target_obj->am_i_a_servant()  &&
        !target_obj->is_kid()) {
      target_obj->attacked_by(MY_PLAYER);
      MY_PLAYER->attacked_by(target_obj);
      target_obj->hit_player(8+random(8));
      target_hit=1;
    }
    target_obj=next_target_obj;
  }
  if (target_hit) {
    MY_PLAYER->add_spell_point(- 25);
    write("You shriek some gutteral words and the gates of hell\n"+
        "open to blast your enemies with flame!\n");
    MY_FANGS->tell_my_room(
                MY_NAME_CAP+
                " shrieks some gutteral words and the gates of hell\n"+
                "open to blast "+MY_PLAYER->query_possessive()+
                " enemies with flame!");
  }
  else
    write("There are no monsters here to roast in the fires of hell!\n");
  return 1;
}
