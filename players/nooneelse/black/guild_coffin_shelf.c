/*
  guild_coffin_shelf.c
*/

int value_on_shelf;

init() {
  int save_value_on_shelf;
  save_value_on_shelf=value_on_shelf;
  restore_object("players/nooneelse/black/shelf/"+
                 environment(this_object())->query_coffin_owner_name());
  if (!save_value_on_shelf==0 && value_on_shelf==0)
    value_on_shelf = save_value_on_shelf;
/*
  if (!save_value_on_shelf==0 &&
      !value_on_shelf==0 &&
      !save_value_on_shelf==value_on_shelf)
    value_on_shelf += save_value_on_shelf;
*/
  save_object("players/nooneelse/black/shelf/"+
              environment(this_object())->query_coffin_owner_name());
/* if you cannot clean the logs, dont make them -Bp
  write_file("/players/nooneelse/COFFIN_SHELF_LOG",
             environment(this_object())->query_coffin_owner_name()+"#"+
             ctime(time())+"#'init'#0#"+value_on_shelf+".\n");
*/
  add_action("place",         "place");
  add_action("retrieve",      "retrieve");
  add_action("value_shelf",   "value");
  add_action("restore_value", "restore");
  add_action("put",           "put");
  add_action("get",           "get");
  add_action("get",           "take");
}

id(str) { return str=="shelf"; }

short() { return "A shelf"; }

long() {
  write("A shelf in the side of your coffin.\n");
  write("\nYou can 'place <item> on shelf', 'retrieve <item> from shelf',\n"+
        "'value shelf' or 'restore value from shelf'\n"+
        "NOTE: If you restore value when items are on the shelf, they\n"+
        "      will be destroyed & their $ value given to you.\n"+
        "\nThe value of the items put on the shelf will be saved in case\n"+
        "of a crash and/or reboot of the mud and restored to you, but\n"+
        "not the items themselves.\n"+
        "note: the mud now has a cleanup routine running. this will at\n"+
        "      times reset the coffins & shelves. if this happens, your\n"+
        "      items will disappear from the shelf, but the cash value\n"+
        "      will be there.\n");
}

can_put_and_get() { return 1; }

place(str) {
  int item_value;
  string item;
  object item_obj, item_on_shelf_obj;

  if (!str) return;
  if (sscanf(str, "%s on shelf", item) != 1) {
    write("Place what ?\n");
    return 1;
  }
  if (item=="all") {
    write("No!  You must place each item on individually.\n");
    return 1;
  }
  if (item=="shelf") {
    write("Huh?  You want to place the shelf on the shelf?\n");
    return 1;
  }
  item = lower_case(item);
  item_obj = present(item, this_player());
  if (!item_obj) {
    write("You have no "+item+"!\n");
    return 1;
  }
  if (call_other(item_obj, "prevent_insert")) return 1;
  if (call_other(item_obj, "drop")) return 1;
  item_value = item_obj->query_value();
  if (item_value > 1000) item_value=1000;
  if (item_value <= 0) {
    write("That item has no value.  "+
          "There's no sense in storing it on the shelf.\n");
    return 1;
  }
  restore_object("players/nooneelse/black/shelf/"+
                 environment(this_object())->query_coffin_owner_name());
  item_on_shelf_obj=first_inventory(this_object());
  if (!item_on_shelf_obj && value_on_shelf) {
    write("You take the "+value_on_shelf+
          " coins from the shelf to make room or the new items.\n");
    this_player()->add_money(value_on_shelf);
    value_on_shelf=0;
    save_object("players/nooneelse/black/shelf/"+
                environment(this_object())->query_coffin_owner_name());
/*
  write_file("/players/nooneelse/COFFIN_SHELF_LOG",
             environment(this_object())->query_coffin_owner_name()+"#"+
             ctime(time())+"#'place (1)'#"+item_value+"#"+value_on_shelf+".\n");
*/
  }
  this_player()->add_weight(- item_obj->query_weight());
  move_object(item_obj, this_object());
  value_on_shelf += item_value;
  save_object("players/nooneelse/black/shelf/"+
              environment(this_object())->query_coffin_owner_name());
/*
  write_file("/players/nooneelse/COFFIN_SHELF_LOG",
             environment(this_object())->query_coffin_owner_name()+"#"+
             ctime(time())+"#'place (2)'#"+item_value+"#"+value_on_shelf+".\n");
*/
  say(this_player()->query_name()+" places the "+item+" on the shelf.\n");
  write("Ok.\n");
  return 1;
}

retrieve(str) {
  int item_value;
  string item;
  object item_obj;

  if (!str) return;
  if (sscanf(str, "%s from shelf", item) != 1) {
    write("Retreive what ?\n");
    return 1;
  }
  if (item=="all") {
    write("No!  You must retrieve each item individually.\n");
    return 1;
  }
  if (item=="shelf") {
    write("Huh?  You want to retrieve the shelf from the shelf?\n");
    return 1;
  }
  item = lower_case(item);
  item_obj = present(item, this_object());
  if (!item_obj) {
    write("There is no "+item+" on the shelf!\n");
    return 1;
  }
  item_value = item_obj->query_value();
  if (item_value > 1000) item_value=1000;
  restore_object("players/nooneelse/black/shelf/"+
                 environment(this_object())->query_coffin_owner_name());
  this_player()->add_weight(item_obj->query_weight());
  move_object(item_obj, this_player());
  value_on_shelf -= item_value;
  if (value_on_shelf < 0) value_on_shelf=0;
  save_object("players/nooneelse/black/shelf/"+
              environment(this_object())->query_coffin_owner_name());
/*
  write_file("/players/nooneelse/COFFIN_SHELF_LOG",
             environment(this_object())->query_coffin_owner_name()+"#"+
             ctime(time())+"#'retrieve'#"+item_value+"#"+value_on_shelf+".\n");
*/
  say(this_player()->query_name()+" retrieves the "+item+" from the shelf.\n");
  write("Ok.\n");
  return 1;
}

value_shelf(str) {
  if (!id(str)) return;
  restore_object("players/nooneelse/black/shelf/"+
                 environment(this_object())->query_coffin_owner_name());
  write("The value of the items on the shelf is "+value_on_shelf+" coins.\n");
  return 1;
}

restore_value(str) {
  object item_obj, save_item_obj;

  if (!str=="value from shelf") return;
  restore_object("players/nooneelse/black/shelf/"+
                 environment(this_object())->query_coffin_owner_name());
  item_obj=first_inventory(this_object());
  while (item_obj) {
    save_item_obj=item_obj;
    item_obj=next_inventory(item_obj);
    destruct(save_item_obj);
  }
  write("You take the "+value_on_shelf+" coins from the shelf.\n");
  this_player()->add_money(value_on_shelf);
/*
  write_file("/players/nooneelse/COFFIN_SHELF_LOG",
             environment(this_object())->query_coffin_owner_name()+"#"+
             ctime(time())+"#'restore'#0#"+value_on_shelf+".\n");
*/
  value_on_shelf=0;
  save_object("players/nooneelse/black/shelf/"+
              environment(this_object())->query_coffin_owner_name());
  return 1;
}

put(str) {
  string str2;
  if (!str) return;
  if (sscanf(str, "%s on shelf", str2)==1) {
    write("You must use 'place <item> on shelf'\n");
    return 1;
  }
}

get(str) {
  string str2;
  if (!str) return;
  if (sscanf(str, "%s from shelf", str2)==1) {
    write("You must use 'retrieve <item> from shelf'\n");
    return 1;
  }
}

reset(arg) {
  if (arg) return;
}
clean_up() { return 0; }
