inherit "room/room";

void
reset(status arg) {
  object cauldron;
  object listener;

  if (!present("cauldron", this_object())) {
    cauldron = clone_object("/players/angmar/o/cauldron");
    move_object(cauldron, this_object());
  }
  if (!present("listener", this_object())) {
    listener = clone_object("/players/angmar/o/catch_password.c");
    listener->set_object(cauldron);
    listener->set_call("catch_it");
    move_object(listener, this_object());
  }
  
  if (arg)
    return;
  set_light(1);
  short_desc = "Magic workroom";
  long_desc = 
"This seems to be a magic workroom.  Many different kinds of magic\n" +
"tools are scattered around the place.\n";
  dest_dir = ({
    "players/angmar/castle/midstairs", "east",
    "players/angmar/castle/library", "west",
  });
  items = ({
    "tools", "You can't determine the function of half of them",
    "sign", "The sign says: 'Entrance to Fairyland'.  It points west",
    "west", "You cannot see further.  You must go west",
    "workroom", "It is obviously a place where magic is performed routinely",
  });
}

void
init() {
  room::init();
  add_action("put", "put");
}

status
put(string str) {
  int i;
  string item;
  string container;
  object item_o;
  object container_o;
  
  if (!str)
    return 0;
  if (sscanf(str, "%s in %s", item, container) != 2) {
    write("put what ?\n");
    return 1;
  }
  container = lower_case(container);
  container_o = present(container, this_player());
  if (!container_o)
    container_o = present(container, environment(this_player()));
  if (!container_o) {
    write("There are no " + container + "s here!\n");
    return 1;
  }
  item = lower_case(item);
  item_o = present(item, this_player());
  if (!item_o) {
    write("You have no " + item + "!\n");
    return 1;
  }
  if (!container_o->can_put_and_get()) {
    write("You can't do that.\n");
    return 1;
  }
  if (item_o == container_o)
    return 0;
  if (!(item_o->id("corpse") && (container=="cauldron"))) {
    if (item_o->prevent_insert())
      return 1;
  }
  if (item_o->drop())
    return 1;
  i = (int)item_o->query_weight();
  if (container_o->add_weight(i)) {
    /* Remove the weight from the previous container. */
    environment(item_o)->add_weight(-i);
    move_object(item_o, container_o);
    say(this_player()->query_name()+" puts the "+
      item +" in the "+ container +".\n");
    write("Ok.\n");
    return 1;
  }
  write("There is not room for more.\n");
  return 1;
}
