/*
  translate_item.h
*/

#include "defs.h"

int recurse_flag;

/* -------- sell an item to vamp shop at a distance ---------- */
translate_item(str) {
  object obj, guild_shop_obj, guild_store_obj, next_obj;
  int item_value, item_weight;
  string these;
  if (!str) return 0;
  if (MY_LEVEL < 5 || MY_GUILD_EXP < 668) {
    write("You can't use that abilitiy yet.\n");
    return 1;
  }
  if (MY_SPELL_POINTS < 20) {
    write("You don't have enough spell points.\n");
    return 1;
  }
  if (str=="all") {
    write("To translate all, you must use 'translate everything'.\n"+
          "It was changed to prevent accidents with the\n"+
          "'translate all <item>' command.\n");
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
    MY_PLAYER->add_spell_point(- 20);
    write("Ok.\n");
    return 1;
  }
  /* sell all of a particular item */
  if (sscanf(str, "all %s", these) == 1) {
    sell_all_these(these);
    MY_PLAYER->add_spell_point(- 20);
    write("Ok.\n");
    return 1;
  }
  obj=present(str, MY_PLAYER);
  if (!obj) {
    write("But, you don't have a '"+str+"'.\n");
    return 1;
  }
  item_value = obj->query_value();
  if (!item_value) {
    write(capitalize(str)+" has no value.\n");
    return 1;
  }
  if (environment(obj)==MY_PLAYER) {
    if (obj->drop()) {
      write("The bat squeaks:  I can't take it from you!\n");
      return 1;
    }
    item_weight = obj->query_weight();
    this_player()->add_weight(- item_weight);
  }
  if (item_value > 1000) {
    write("The shop is low on money...\n");
    item_value = 950 + random(150);
  }
  MY_FANGS->tell_my_room(
              MY_NAME_CAP+
              " summons a strong-looking, gold colored bat which takes\n"+
              obj->short()+" and flys off to someplace unknown.\n\n"+
              "After a few moments, it returns, gives "+
              MY_PLAYER->query_objective()+" some gold, and flys away.");
  write("A gold-colored bat takes the "+str+
        ", flys away with it and returns after a\n"+
        "few moments to give you "+item_value+" gold coins.\n");
  MY_PLAYER->add_money(item_value);
  if (item_value > SHOP_DESTROY_VALUE) destruct(obj);
  call_other(GUILD_SHOP_STOREROOM, "???");
  guild_store_obj = find_object(GUILD_SHOP_STOREROOM);
  guild_store_obj->store(obj);
  if (!recurse_flag)  MY_PLAYER->add_spell_point(- 20);
  return 1;
}

/* handle the selling of the item */
do_sell(obj) {
  object guild_store_obj;
  int item_value, do_destroy, item_weight;
  item_value = obj->query_value();
  if (!item_value) {
    write("The gold bat squeaks:  "+obj->short()+" has no value.\n");
    return 1;
  }
  if (environment(obj)==MY_PLAYER) {
    if (obj->drop()) {
      write("The gold bat squeaks:  I can't take it from you!\n");
      return 1;
    }
    item_weight = obj->query_weight();
    MY_PLAYER->add_weight(- item_weight);
  }
  if (item_value > SHOP_DESTROY_VALUE) do_destroy = 1;
  if (item_value > 1000) item_value = 950 + random(150);
  MY_FANGS->tell_my_room(
              MY_NAME_CAP+
              " summons a strong-looking, gold-colored bat which takes\n"+
              obj->short()+" and flys off to the Guild's shop.\n\n"+
              "After a few moments, it returns, gives "+
              MY_PLAYER->query_objective()+" some gold, and flys away.");
  write("A gold-colored bat takes the "+obj->short()+
        ", flys away with it and returns after a\n"+
        "few moments to give you "+item_value+" gold coins.\n");
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
    command("translate " + these, MY_PLAYER);
    recurse_flag = 0;
  }
}
