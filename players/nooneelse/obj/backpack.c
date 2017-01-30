/*
  backpack.c
*/

inherit "obj/container";

string str, these;

init() {
  add_action("put_in_backpack",   "put");
  add_action("get_from_backpack", "get");
  add_action("help_backpack",     "help");
}

put_in_backpack(str) {
  string item;
  if (!str) return;
  item=0;
  /* put all of a particular item in the backpack */
  if (sscanf(str, "all %s in backpack", these) == 1) {
    put_all_these(these);
    write("Ok.\n");
    return 1;
  }
  if (sscanf(str, "all %s in pack", these) == 1) {
    put_all_these(these);
    write("Ok.\n");
    return 1;
  }
  sscanf(str, "in backpack %s", item);
  if (!item) return;
  /* put all of a particular item in the backpack using an alias */
  if (sscanf(item, "all %s", these) == 1) {
    put_all_these(these);
    write("Ok.\n");
    return 1;
  }
  if (!present(item, this_player())) return;
  command("put "+item+" in backpack", this_player());
  return 1;
}

get_from_backpack(str) {
  string item;
  if (!str) return;
  item=0;
  /* get all of a particular item from the backpack */
  if (sscanf(str, "all %s from backpack", these) == 1) {
    get_all_these(these);
    write("Ok.\n");
    return 1;
  }
  if (sscanf(str, "all %s from pack", these) == 1) {
    get_all_these(these);
    write("Ok.\n");
    return 1;
  }
  sscanf(str, "from backpack %s", item);
  if (!item) return;
  /* get all of a particular item from the backpack */
  if (sscanf(item, "all %s", these) == 1) {
    get_all_these(these);
    write("Ok.\n");
    return 1;
  }
  if (!present(item, this_object())) return;
  command("get "+item+" from backpack", this_player());
  return 1;
}

help_backpack(str) {
  if (!str || (str != "backpack" && str != "pack")) return;
  write("You can:\n"+
        "   put [all] <item> in backpack\n"+
        "   get [all] <item> from backpack\n\n"+
        "   (You can also 'alias pp put in backpack' & use\n"+
        "    'pp crown' to put a crown in the backpack\n"+
        "    & similar for get.)\n");
  return 1;
}

reset(arg) {
  ::reset(arg);

  short_desc="A leather backpack";
  long_desc="A sturdy leather backpack.  (Use: help backpack).\n";
  value=100;
  max_weight=40;
  local_weight=0;
}

put_all_these(these) {
  object list;
  int i;
  list = all_inventory(this_player());
  for (i = 0; i < sizeof(list); i++) {
    if (list[i]->id(these)==0) continue;
    command("put "+these+" in backpack", this_player());
  }
}

get_all_these(these) {
  object list;
  int i;
  list = all_inventory(this_object());
  for (i = 0; i < sizeof(list); i++) {
    if (list[i]->id(these)==0) continue;
    command("get "+these+" from backpack", this_player());
  }
}

prevent_insert() {
  write("The backpack is too bulky to put in there.\n");
  return 1;
}

id(str) { return str=="backpack" || str=="leather backpack" || str=="pack"; }
