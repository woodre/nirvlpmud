/*
  demon_wrath.h
*/

#include "defs.h"

/* -------- Demon Wrath - high level area effect spell ---------- */
demon_wrath(str) {
  object target_obj, next_target_obj;
  string target_name;
  int target_hit, nbr_critters, total_damage, damage_each;

write("Demon wrath has been deactivated until i can figure out how to make it legal again.\n");
return 1;

  if (MY_PLAYER->query_ghost()) {
    write("How can you attack anything? You are a ghost.\n");
    return 1;
  }
  if (MY_FANGS->query_in_flight()) {
    write("You cannot do that while in flight.\n");
    return 1;
  }
  if (!str || str != "wrath") return 0;
  if (MY_LEVEL < 16 || MY_GUILD_EXP < 671) {
    write("You can't use that abilitiy yet.\n");
    return 1;
  }
  if (MY_SPELL_POINTS < 50) {
    write("You don't have enough spell points.\n");
    return 1;
  }
  if (MY_FANGS->demon_wrath_pause()>=time()) {
    write("You're too tired from the last one to use it so soon.\n");
    return 1;
  }
  /* (same as 3 heartbeats) */
  MY_FANGS->set_demon_wrath_pause(time()+6);
  target_hit=0;
  total_damage = 25+random(50);
  nbr_critters = 0;
  target_obj = first_inventory(MY_ROOM);
  if (target_obj != MY_PLAYER &&
      target_obj->query_npc() &&
      living(target_obj) &&
      !target_obj->am_i_a_servant() &&
      !target_obj->is_kid() &&
      !target_obj->is_pet())
    nbr_critters++;
  while (target_obj) {
    next_target_obj=next_inventory(target_obj);
    if (target_obj != MY_PLAYER &&
        target_obj->query_npc() &&
        living(target_obj) &&
        !target_obj->am_i_a_servant() &&
        !target_obj->is_kid() &&
        !target_obj->is_pet())
      nbr_critters++;
  }
  damage_each = total_damage / nbr_critters;
  target_obj = first_inventory(MY_ROOM);
  if (target_obj != MY_PLAYER &&
      target_obj->query_npc() &&
      living(target_obj) &&
      !target_obj->am_i_a_servant() &&
      !target_obj->is_kid() &&
      !target_obj->is_pet())
    target_name = lower_case(target_obj->query_name());
  while (target_obj) {
    next_target_obj=next_inventory(target_obj);
    if (target_obj != MY_PLAYER &&
        target_obj->query_npc() &&
        living(target_obj) &&
        !target_obj->am_i_a_servant()  &&
        !target_obj->is_kid() &&
        !target_obj->is_pet()) {
      target_obj->attacked_by(MY_PLAYER);
      MY_PLAYER->attacked_by(target_obj);
      target_obj->hit_player(damage_each);
      target_hit=1;
    }
    target_obj=next_target_obj;
  }
  if (target_hit) {
    MY_PLAYER->add_spell_point(- 50);
    write("You drone some unspeakable words and a raging demon appears\n"+
        "to wither your enemies with its anger!\n");
    MY_FANGS->tell_my_room(
        MY_NAME_CAP+
        " drones some unspeakable words and a raging demon appears\n"+
        "to wither "+MY_PLAYER->query_possessive()+" enemies with its anger!");
  }
  else
    write("There are no monsters here to blast in the anger of the demons!\n");
  return 1;
}
