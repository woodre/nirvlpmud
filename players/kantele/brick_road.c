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
  set_short("A small brickroad leading south");
  set_long(
"A small brickroad leading south, to the north you can exit\n" +
"through an iron gate. To the east and west you can see a beautiful\n" +
"garden.\n");
  dest_dir = ({
    "players/kantele/garden_west", "west",
    "room/south/sforst17", "north",
    "players/kantele/garden_east", "east",
    "players/kantele/courtyard", "south"
  });
}

void
populate() {
  object rotweiler;
  if (!present("rotweiler")) {
    int i;
    object collar;
    i = 2;
    while(i>0) {
      i -= 1;
      rotweiler = clone_object("obj/monster");
      rotweiler->set_name("rotweiler");
      rotweiler->set_alias("dog");
      rotweiler->set_level(2);
      rotweiler->set_short("A huge rotweiler");
      rotweiler->set_long(
"A mean hungry rotweiler is snaring at you....\n");
      rotweiler->set_wc(8);
      rotweiler->set_aggressive(1);
      rotweiler->set_move_at_reset();
      rotweiler->set_move_at_reset();
      move_object(rotweiler, this_object());
      collar = clone_object("obj/treasure");
      collar->set_id("collar");
      collar->set_alias("dog collar");
      collar->set_short("A heavy studded dog collar");
      collar->set_value(25);
      move_object(collar, rotweiler);
    }
  }
}
