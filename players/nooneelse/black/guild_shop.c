/*
  guild_shop.c
*/

#define SHOP_DESTROY_VALUE 6000

inherit "room/room";
inherit "players/nooneelse/black/guild_rooms";

object shop_storeroom_obj;
string shop_storeroom_name;

init() {
  ::init();

  add_action("sell_items",  "sell");
  add_action("value_items", "value");
  add_action("buy_items",   "buy");
  add_action("list_items",  "list");
  add_action("south", "south");
  check_membership(this_player());
}

sell_items(item_name) {
  object obj, next_obj;
  string these;
  if (!item_name) return;
  if (item_name=="all") {
    write("To sell all here, you must use 'sell everything'.\n"+
          "It was changed here to prevent accidents with the\n"+
          "'sell all <item> command.\n");
    return 1;
  }
  /* sell all */
  if (item_name=="everything") {
    obj = first_inventory(this_player());
    while(obj) {
      next_obj = next_inventory(obj);
      if (!obj->drop() && obj->query_value()) {
        write(obj->short()+":\t");
        do_sell(obj);
      }
      obj = next_obj;
    }
    write("Ok.\n");
    return 1;
  }
  /* sell all of a particular item */
  if (sscanf(item_name, "all %s", these) == 1) {
    sell_all_these(these);
    write("Ok.\n");
    return 1;
  }
  /* sell individual item */
  obj = present(item_name, this_player());
  if (!obj) obj = present(item_name, this_object());
  if (!obj) {
    write("There's no '"+item_name+"' here.\n");
    return 1;
  }
  do_sell(obj);
  return 1;
}

value_items(item_name) {
  int item_value;
  string name_of_item;
  if (!item_name) return;
  name_of_item = present(item_name);
  if (!name_of_item) name_of_item = find_item_in_player(item_name);
  if (!name_of_item) {
    if (shop_storeroom_obj->value(item_name)) return 1;
    write("There is no '"+item_name+"' here or in the store.\n");
    return 1;
  }
  item_value = call_other(name_of_item, "query_value", 0);
  if (!item_value) {
    write(capitalize(item_name)+" has no value.\n");
    return 1;
  }
  if (item_value > 1000)
    write("It's worth "+item_value+" gold coins, but I can't "+
          "give you that much.\n");
  else
    write("It's worth "+item_value+" gold coins.\n");
  return 1;
}

buy_items(item_name) {
  if (!item_name) return;
  shop_storeroom_obj->buy(item_name);
  return 1;
}

list_items(item_name) {
  shop_storeroom_obj->inventory(item_name);
  return 1;
}

south() {
  if (this_player()->query_level() < 21) {
    write("A previously invisible force screen flashes black preventing\n"+
          "you from going south.\n");
    say("As "+capitalize(this_player()->query_name())+" tries to go south\n"+
        "into the back room, a previously invisible force screen flashes\n"+
        "black stopping "+this_player()->query_objective()+".\n");
    return 1;
  }
  write("The force screen flashes black, but permits you to pass.\n");
  say("As "+capitalize(this_player()->query_name())+" goes south\n"+
      "into the back room, a previously invisible force screen flashes\n"+
      "black but allows "+this_player()->query_objective()+" to pass.\n");
  this_player()->move_player("south#"+shop_storeroom_name);
  return 1;
}

reset(arg) {
  if (arg) return;

  set_light(1);
  no_castle_flag=1;
  short_desc="The Vampire Guild's Shop\n";
/* This has been annoying for too long.... -Bp
             "\nIn an effort to eliminate confusion when buying items,\n"+
             "you can now buy items by number as well as name.\n";
*/
  long_desc="You are in a shop.  You can buy or sell things here.\n"+
            "\nIn an effort to eliminate confusion when buying items,\n"+
            "you can now buy items by number as well as name.\n\n";
            "You can: 'buy <item>', 'sell <item>', 'sell all <item>'\n"+
            "         'sell everything', 'list', 'list weapons',\n"+
            "         'list armors', 'list misc' & 'value <item>'.\n";
  dest_dir =
    ({
      "/players/nooneelse/black/guild_equip", "north",
/*
      "/players/nooneelse/souvenir_shop", "east",
*/
  "/players/eurale/Vamp/RMS/souvenir_shop.c","east",
      "/players/nooneelse/black/guild_storeroom", "south",
    });
  shop_storeroom_name = "/players/nooneelse/black/guild_storeroom";
  call_other(shop_storeroom_name, "???", 0);
  shop_storeroom_obj = find_object(shop_storeroom_name);
  if (!present("nooneelsetrashcan"))
    move_object(clone_object("players/nooneelse/obj/trashcan"), this_object());
}

do_sell(obj) {
  int item_value, do_destroy, item_weight, random_value;
  item_value = obj->query_value();
  if (!item_value) {
    write(obj->short()+" has no value.\n");
    return 1;
  }
  if (environment(obj)==this_player()) {
    if (obj->drop()) {
      write("I can't take it from you!\n");
      return 1;
    }
    item_weight = obj->query_weight();
    this_player()->add_weight(- item_weight);
  }
  if (item_value > SHOP_DESTROY_VALUE) do_destroy = 1;
  if (item_value > 1000) {
    random_value = 1000 + random(150);
    if (item_value > random_value)
      item_value = random_value;
      write("The shop is low on money...\n");
  }
  write("You get "+item_value+" gold coins.\n");
  say(capitalize(this_player()->query_name())+" sells "+obj->short()+".\n");
  this_player()->add_money(item_value);
  if (do_destroy) {
    write("The valuable item is hidden away.\n");
    destruct(obj);
    return 1;
  }
  shop_storeroom_obj->store(obj);
  return 1;
}

sell_all_these(these) {
  object list;
  int i;
  list = all_inventory(this_player());
  for (i = 0; i < sizeof(list); i++) {
    if (list[i]->id(these)==0) continue;
    command("sell " + these, this_player());
  }
}

find_item_in_player(item_name) {
  object obj;
  obj = first_inventory(this_player());
  while(obj) {
    if (obj->id(item_name)) return obj;
    obj = next_inventory(obj);
  }
  return;
}

realm() { return "NT"; }
