#pragma strong_types

inherit "room/room";

void populate();

int i;

void
reset(status arg) {
  ::reset(arg);
  populate();
  if (arg)
    return;
  set_light(1);
  set_short("In a dark passage");
  set_long(
"In a dark passage, going north/south. The passage is lighted\n"+
"with torches.\n");
  dest_dir = ({
    "players/kantele/cellar_east", "south",
    "players/kantele/cellar_passage1", "north"
  });
  items = ({
    "torches", "You can see some torches",
    "torch", "You can see some torches"
  });
}

void
populate() {
  i = 0;
}

void
init() {
  ::init();
  add_action("get_torch", "get");
  add_action("get_torch", "grab");
}

status
get_torch(string arg) {
  object torch;
  if (arg == "torch") {
    if (!present("torch", this_player()) && i < 3) {
      i = i+1;
      torch = clone_object("obj/torch");
      torch->set_name("torch");
      torch->set_fuel(2000);
      torch->set_weight(1);
      move_object(torch, this_object());
      write("As you reach for the torch, it falls to the ground.\n");
      return 1;
    }
    return 0;
  }
  return 0;
}
