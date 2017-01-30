/*
  cult_coffin_drawer.c
*/

int drawer_is_open, value_in_drawer;

init() {
  int save_drawer_is_open, save_value_in_drawer;
  save_value_in_drawer=value_in_drawer;
  save_drawer_is_open=drawer_is_open;
  restore_object("players/nooneelse/black/drawer/"+
                 environment(this_object())->query_coffin_owner_name());
  if (!save_value_in_drawer==0 && value_in_drawer==0)
    value_in_drawer = save_value_in_drawer;
  if (!save_value_in_drawer==0 && !value_in_drawer==0)
    value_in_drawer += save_value_in_drawer;
  drawer_is_open=save_drawer_is_open;
  save_object("players/nooneelse/black/drawer/"+
              environment(this_object())->query_coffin_owner_name());
  add_action("open",          "open");
  add_action("close",         "close");
  add_action("place",         "place");
  add_action("retreive",      "retreive");
  add_action("value_drawer",  "value");
  add_action("restore_value", "restore");
}

id(str) { return str=="drawer"; }

short() {
  if (drawer_is_open)
    return "An open drawer";
  else
    return "A closed drawer";
}

long() {
  write("A drawer in the side of your coffin.\n");
  if (drawer_is_open)
    write("It is open.\n");
  else
    write("It is closed.\n");
  write("\nYou can 'place <item> in drawer', 'retreive <item> from drawer',\n"+
        "'value drawer' or 'restore value from drawer'\n"+
        "NOTE: If you restore value when items are in the drawer, they\n"+
        "      will be destroyed & their $ value given to you.\n"+
        "\nThe value of the items put in the drawer will be saved in case\n"+
        "of a crash and/or reboot of the mud and restored to you, but\n"+
        "not the items themselves.\n");
}

can_put_and_get() { return drawer_is_open; }

open(str) {
  if (!id(str)) return;
  drawer_is_open = 1;
  write("Ok.\n");
  return 1;
}

close(str) {
  if (!id(str)) return;
  drawer_is_open = 0;
  write("Ok.\n");
  return 1;
}

place(str) {
  int item_value;
  string item;
  object item_obj;

  if (!str) return;
  if (sscanf(str, "%s in drawer", item) != 1) {
    write("Place what ?\n");
    return 1;
  }
  if (item=="all") {
    write("No!  You must place each item in individually.\n");
    return 1;
  }
  if (item=="drawer") {
    write("Huh?  You want to place the drawer in the drawer?\n");
    return 1;
  }
  if (!drawer_is_open) {
    write("You can't.  The drawer is not open.\n");
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
  if (item_value > 1200) item_value=1200;
  if (item_value <= 0) {
    write("That item has no value.  "+
          "There's no sense in storing it in the drawer.\n");
    return 1;
  }
  restore_object("players/nooneelse/black/drawer/"+
                 environment(this_object())->query_coffin_owner_name());
  this_player()->add_weight(- item_obj->query_weight());
  move_object(item_obj, this_object());
  value_in_drawer += item_value;
  save_object("players/nooneelse/black/drawer/"+
              environment(this_object())->query_coffin_owner_name());
  say(this_player()->query_name()+" places the "+item+" in the drawer.\n");
  write("Ok.\n");
  return 1;
}

retreive(str) {
  int item_value;
  string item;
  object item_obj;

  if (!str) return;
  if (sscanf(str, "%s from drawer", item) != 1) {
    write("Retreive what ?\n");
    return 1;
  }
  if (item=="all") {
    write("No!  You must retreive each item individually.\n");
    return 1;
  }
  if (item=="drawer") {
    write("Huh?  You want to retreive the drawer from the drawer?\n");
    return 1;
  }
  if (!drawer_is_open) {
    write("You can't.  The drawer is not open.\n");
    return 1;
  }
  item = lower_case(item);
  item_obj = present(item, this_object());
  if (!item_obj) {
    write("There is no "+item+" in the drawer!\n");
    return 1;
  }
  item_value = item_obj->query_value();
  if (item_value > 1200) item_value=1200;
  restore_object("players/nooneelse/black/drawer/"+
                 environment(this_object())->query_coffin_owner_name());
  this_player()->add_weight(item_obj->query_weight());
  move_object(item_obj, this_object());
  value_in_drawer -= item_obj->query_value();
  if (value_in_drawer < 0) value_in_drawer=0;
  save_object("players/nooneelse/black/drawer/"+
              environment(this_object())->query_coffin_owner_name());
  say(this_player()->query_name()+" retreives the "+item+" from the drawer.\n");
  write("Ok.\n");
  return 1;
}

value_drawer(str) {
  if (!id(str)) return;
  restore_object("players/nooneelse/black/drawer/"+
                 environment(this_object())->query_coffin_owner_name());
  write("The value in the drawer is "+value_in_drawer+" coins.\n");
  return 1;
}

restore_value(str) {
  object item_obj, save_item_obj;

  if (!str=="value from drawer") return;
  restore_object("players/nooneelse/black/drawer/"+
                 environment(this_object())->query_coffin_owner_name());
  item_obj=first_inventory(this_object());
  while (item_obj) {
    save_item_obj=item_obj;
    item_obj=next_inventory(item_obj);
    destruct(save_item_obj);
  }
  write("You take the "+value_in_drawer+" coins from the drawer.\n");
  this_player()->add_money(value_in_drawer);
  value_in_drawer=0;
  save_object("players/nooneelse/black/drawer/"+
              environment(this_object())->query_coffin_owner_name());
  return 1;
}

reset(arg) {
  if (arg) return;

  drawer_is_open=0;
}
