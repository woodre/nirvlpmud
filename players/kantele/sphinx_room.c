#pragma strong_types

inherit "room/room";

void populate();

void reset(status arg) {
  ::reset(arg);
  populate();
  if (arg)
    return;
  set_light(1);
  set_short("The Sphinx room");
  set_long("This is the Sphinx room.\n");
  dest_dir = ({ "players/kantele/west_bridge", "north" });
}

void populate() {
  object sphinx;
  
  if (!sphinx || !present("sphinx")) {
    sphinx = clone_object("obj/treasure");
    sphinx->set_id("sphinx");
    sphinx->set_short("A huge stone Sphinx stands here");
    sphinx->set_weight(1000);
    move_object(sphinx, this_object());
  }
}
