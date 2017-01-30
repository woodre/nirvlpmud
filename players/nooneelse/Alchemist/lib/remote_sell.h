/*
  remote_sell.h
*/

#include "/players/nooneelse/Alchemist/lib/defs.h"

int recurse_flag;

/* -------- sell an item to alchemist shop at a distance ---------- */
remote sell_item(str) {
  object obj, guild_shop_obj, guild_store_obj, next_obj;
  int item_value, item_weight;
  string these;

  if (present(ALCHEMIST_PENANCE_MARK, this_player())) {
    write(NORM+CYN+"You cannot use that skill while you are doing penance.\n"+NORM);
    return 1;
  }
  if (MY_PLAYER->query_ghost()) {
    write(NORM+CYN+"How can you do anything? You are a ghost!\n"+NORM);
    return 1;
  }
  if (!str) return 0;
  if (MY_GUILD_RANK < 80) {
    write(NORM+CYN+"You can't use that abilitiy yet.\n"+NORM);
    return 1;
  }
  if (MY_POUCH->query_quantity("arrow") < 1) {
    write(NORM+CYN+"You don't have the appropriate component (arrow).\n"+NORM);
    return 1;
  }
  if (MY_POUCH->query_quantity("mercury") < 1) {
    write(NORM+CYN+"You don't have the appropriate component (mercury).\n"+NORM);
    return 1;
  }
  if (MY_POUCH->query_quantity("iron rod") < 1) {
    write(NORM+CYN+"You don't have the appropriate component (iron rod).\n"+NORM);
    return 1;
  }
  if (MY_POUCH->query_quantity("crystal bead") < 1) {
    write(NORM+CYN+"You don't have the appropriate component (crystal bead).\n"+NORM);
    return 1;
  }
  if (MY_SPELL_POINTS < 25) {
    write(NORM+CYN+"You don't have enough spell points.\n"+NORM);
    return 1;
  }
  if (str=="all") {
    write(NORM+CYN+
          "To remote sell all, you must use 'asell everything'.\n"+
          "It was changed to prevent accidents with the\n"+
          "'asell all <item>' command.\n"+NORM);
    return 1;
  }
  /* sell all */
  if (str=="everything") {
    obj = first_inventory(MY_PLAYER);
    while(obj) {
      next_obj = next_inventory(obj);
      if (!obj->drop() && obj->query_value()) do_sell(obj);
      obj = next_obj;
    }
    MY_POUCH->subtract_quantity("arrow", 1);
    MY_POUCH->subtract_quantity("mercury", 1);
    MY_POUCH->subtract_quantity("iron rod", 1);
    MY_POUCH->subtract_quantity("crystal bead", 1);
    MY_PLAYER->add_spell_point(- 25);
    write(NORM+CYN+"Ok.\n"+NORM);
    return 1;
  }
  /* sell all of a particular item */
  if (sscanf(str, "all %s", these) == 1) {
    sell_all_these(these);
    MY_POUCH->subtract_quantity("arrow");
    MY_POUCH->subtract_quantity("mercury");
    MY_POUCH->subtract_quantity("iron rod");
    MY_POUCH->subtract_quantity("crystal bead");
    MY_PLAYER->add_spell_point(- 25);
    write(NORM+CYN+"Ok.\n"+NORM);
    return 1;
  }
  obj=present(str, MY_PLAYER);
  if (!obj) {
    write(NORM+CYN+"But, you don't have a '"+str+"'.\n"+NORM);
    return 1;
  }
  item_value = obj->query_value();
  if (!item_value) {
    write(NORM+CYN+capitalize(str)+" has no value.\n"+NORM);
    return 1;
  }
  if (environment(obj)==MY_PLAYER) {
    if (obj->drop()) {
      write(NORM+CYN+"The water elemental says:  I can't take it from you!\n"+NORM);
      return 1;
    }
    item_weight = obj->query_weight();
    this_player()->add_weight(- item_weight);
  }
  if (item_value > 1000) {
    write(NORM+CYN+"The shop is low on money...\n"+NORM);
    item_value = 950 + random(150);
  }
  MY_POUCH->tell_my_room(
              NORM+CYN+MY_NAME_CAP+
              " summons a strong-looking, water elemental which takes\n"+
              obj->short()+" and flows off to the Alchemist's shop.\n\n"+
              "After a few moments, it returns, gives "+
              MY_PLAYER->query_objective()+" some gold, and fades away."+NORM);
  write(NORM+CYN+"A water elemental takes the "+str+
        ", flowss away with it and returns after a\n"+
        "few moments to give you "+item_value+" gold coins.\n"+NORM);
  MY_PLAYER->add_money(item_value);
  if (item_value > SHOP_DESTROY_VALUE) destruct(obj);
  call_other(GUILD_SHOP_STOREROOM, "???");
  guild_store_obj = find_object(GUILD_SHOP_STOREROOM);
  guild_store_obj->store(obj);
  if (!recurse_flag)  {
    MY_POUCH->subtract_quantity("arrow");
    MY_POUCH->subtract_quantity("mercury");
    MY_POUCH->subtract_quantity("iron rod");
    MY_POUCH->subtract_quantity("crystal bead");
    MY_PLAYER->add_spell_point(- 25);
  }
  return 1;
}

/* handle the selling of the item */
do_sell(obj) {
  object guild_store_obj;
  int item_value, do_destroy, item_weight;
  item_value = obj->query_value();
  if (!item_value) {
    write(NORM+CYN+"The gold water elemental says:  "+obj->short()+
          " has no value.\n"+NORM);
    return 1;
  }
  if (environment(obj)==MY_PLAYER) {
    if (obj->drop()) {
      write(NORM+CYN+"The gold water elemental says:  I can't take it from you!\n"+NORM);
      return 1;
    }
    item_weight = obj->query_weight();
    MY_PLAYER->add_weight(- item_weight);
  }
  if (item_value > SHOP_DESTROY_VALUE) do_destroy = 1;
  if (item_value > 1000) item_value = 950 + random(150);
  MY_POUCH->tell_my_room(
              NORM+CYN+MY_NAME_CAP+
              " summons a strong-looking, water elemental which takes\n"+
              obj->short()+" and flys off to the Alchemist's shop.\n\n"+
              "After a few moments, it returns, gives "+
              MY_PLAYER->query_objective()+" some gold, and flys away."+NORM);
  write(NORM+CYN+"A water elemental takes the "+obj->short()+
        ", flows away with it and returns after a\n"+
        "few moments to give you "+item_value+" gold coins.\n"+NORM);
  MY_PLAYER->add_money(item_value);
  if (do_destroy) {
    destruct(obj);
    return 1;
  }
  call_other(GUILD_SHOP_STOREROOM, "???");
  guild_store_obj = find_object(GUILD_SHOP_STOREROOM);
  guild_store_obj->store(obj);
  return 1;
}

sell_all_these(these) {
  object list;
  int i;
  list = all_inventory(MY_PLAYER);
  for (i = 0; i < sizeof(list); i++) {
    if (list[i]->id(these)==0) continue;
    recurse_flag = 1;
    command("remote sell " + these, MY_PLAYER);
    recurse_flag = 0;
  }
}
