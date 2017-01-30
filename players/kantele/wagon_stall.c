#pragma strong_types

inherit "room/room";

void populate();

void
reset(status arg) {
  ::reset(arg);
  populate();
  if (arg)
    return;
  set_light(1);
  set_short("The wagon stall");
  set_long(
"This is the place where visitors park their wagons.\n" +
"A stairway leads up, and an open portal leads out to the \n" +
"courtyard.\n");
  dest_dir = ({
    "players/kantele/courtyard", "east",
    "players/kantele/mechanic_room", "up"
  });
}

void
populate() {
  if (!present("ferrari")) {
    object ferrari;
    ferrari = clone_object("obj/treasure");
    ferrari->set_id("ferrari");
    ferrari->set_alias("red ferrari");
    ferrari->set_short("A brand new Ferrari stands here");
    ferrari->set_weight(1000);
    ferrari->set_value(1000);
    move_object(ferrari, this_object());
  }
}
