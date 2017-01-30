/*
  process_skins.h
*/

#include "/players/nooneelse/Alchemist/lib/defs.h"

/* ------ process skins (combine their strengths) ------ */
process_skins(str) {
  object skin_obj, next_obj;
  int n, skin_strength, total_skins_strength, random_nbr, success_chance;

  if (MY_PLAYER->query_ghost()) {
    write(NORM+CYN+"How can you do anything? You are a ghost!\n"+NORM);
    return 1;
  }
  if (MY_GUILD_RANK < 10) {
    write(NORM+CYN+"You can't use that abilitiy yet.\n"+NORM);
    return 1;
  }
  if(!str || str != "skins") {
    write(NORM+CYN+"use:  process skins\n"+NORM);
    return 1;
  }
  skin_obj = present("skin", MY_PLAYER);
  if (!skin_obj) {
    write(NORM+CYN+"You don't have any skins.\n"+NORM);
    return 1;
  }
  if (MY_POUCH->query_quantity("acid") < 1) {
    write(NORM+CYN+"You don't have the appropriate component (acid).\n"+NORM);
    return 1;
  }
  if (MY_SPELL_POINTS < 50) {
    write(NORM+CYN+"You don't have enough spell points.\n"+NORM);
    return 1;
  }
  MY_POUCH->subtract_quantity("acid", 1);
  MY_PLAYER->add_spell_point(- 50);
  skin_strength = skin_obj->query_skin_strength();
  MY_PLAYER->add_weight(- skin_obj->query_weight());
  destruct(skin_obj);
  total_skins_strength = skin_strength;
  skin_obj = first_inventory(MY_PLAYER);
  while(skin_obj) {
    next_obj = next_inventory(skin_obj);
    if (skin_obj->id("skin")) {
      total_skins_strength=total_skins_strength+skin_obj->query_skin_strength();
      MY_PLAYER->add_weight(- skin_obj->query_weight());
      destruct(skin_obj);
    }
    skin_obj=next_obj;
  }
  success_chance=random(100);
  if (success_chance < 5) total_skins_strength=total_skins_strength - 3;
  if (success_chance > 95) total_skins_strength=total_skins_strength + 3;
  if (total_skins_strength < 1) total_skins_strength=1;
  if (total_skins_strength > 20) total_skins_strength=20;
  skin_obj = clone_object(ALCHEMIST_WOVEN_SKIN);
  skin_obj->set_skin_strength(total_skins_strength);
  move_object(skin_obj, MY_PLAYER);
  write(NORM+CYN+"You successfully weave the skins together.\n"+NORM);
  MY_POUCH->tell_my_room(NORM+CYN+MY_NAME_CAP+
                      " pours a foul smelling liquid on some skins.\n"+
                      "They glow for a moment. When glow disappears you\n"+
                      "see that the skins are joined as one.\n"+NORM);
  return 1;
}
