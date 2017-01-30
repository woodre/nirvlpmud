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
  set_short("A dirty living room");
  set_long(
"It looks like a very dirty unkeept human male lives here.\n" +
"A stairway leads down, and a door further in.\n");
  dest_dir = ({
    "players/kantele/wagon_stall", "down",
    "players/kantele/dirty_sleepingroom", "east"
  });
}

void
populate() {
  object mechanic;
  if (!present("mechanic", this_object())) {
    object wrench;
    mechanic = clone_object("obj/monster");
    mechanic->set_name("mechanic");
    mechanic->set_level(12);
    mechanic->set_wc(16);
    mechanic->set_ac(9);
    mechanic->set_hp(180);
    mechanic->set_al(200);
    mechanic->set_aggressive(1);
    mechanic->set_short("A huge dirty mechanic is here");
    move_object(clone_object("obj/beer"), mechanic);
    wrench = clone_object("obj/weapon");
    wrench->set_name("wrench");
    wrench->set_value(100);
    wrench->set_class(12);
    move_object(wrench, mechanic);
    command("wield wrench", mechanic);
    move_object(mechanic, this_object());
  }
}
