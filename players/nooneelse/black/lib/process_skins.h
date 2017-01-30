/*
  process_skins.h
*/

#include "defs.h"

/* ------ process skins (combine their strengths) ------ */
process_skins(str) {
  object skin_obj, next_obj;
  int n, skin_strength, total_skins_strength, random_nbr, success_chance;
  if (MY_GUILD_EXP < 666) {
    write("You can't use that abilitiy yet.\n");
    return 1;
  }
  if(!str || str != "skins") {
    write("Use:  process skins\n");
    return 1;
  }
  skin_obj = present("skin", MY_PLAYER);
  if (!skin_obj) {
    write("You don't have any skins.\n");
    return 1;
  }
  skin_strength = skin_obj->query_skin_strength();
  if (MY_GUILD_EXP==666) n=10;
  if (MY_GUILD_EXP==667) n=20;
  if (MY_GUILD_EXP==668) n=30;
  if (MY_GUILD_EXP==669) n=40;
  if (MY_GUILD_EXP==670) n=50;
  if (MY_GUILD_EXP==671) n=60;
  if (MY_GUILD_EXP==672) n=70;
  n = n+30;
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
  skin_obj = clone_object(VAMPIRE_WOVEN_SKIN);
  skin_obj->set_skin_strength(total_skins_strength);
  move_object(skin_obj, MY_PLAYER);
  write("You successfully weave the skins together.\n");
  return 1;
}
