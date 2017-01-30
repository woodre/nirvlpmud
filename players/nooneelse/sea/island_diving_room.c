/*
 island_diving_room.c
*/

inherit "room/room";

object guard, coins;

init() {
  ::init();

  add_action("south", "south");
  add_action("dive",  "dive");
}

south() {
  if (present("guard")) {
    write("The guard jumps in your way, saying:\n"+
          "   You are not allowed in there.\n");
    return 1;
  }
}

dive() {
  if (!present("bag", this_player()) &&
      !present("diving suit", this_player())) {
    write("You need an air supply before you can dive.\n");
    return 1;
  }
}

reset(arg) {
  if (arg) return;

  set_light(1);
  short_desc = "hall";
  no_castle_flag=1;
  long_desc =
    "This large room was carved out of the solid rock!  There is a hole\n"+
    "In the center that is filled with water.\n";
  dest_dir =
    ({
      "players/nooneelse/sea/island_hall", "east",
      "players/nooneelse/sea/island_equipment_room", "south",
      "players/nooneelse/sea/sea_19", "dive",
    });
    if (!present("guard")) {
      guard=clone_object("obj/monster");
      guard->set_name("guard");
      guard->set_level(3);
      guard->set_hp(100);
      guard->set_wc(9);
      guard->set_ac(3);
      guard->set_al(-60);
      guard->set_ep(10500);
      guard->set_short("A guard");
      guard->set_long("A guard with well tanned skin.\n");
      guard->set_aggressive(0);
      coins=clone_object("obj/money");
      coins->set_money(60);
      move_object(coins, guard);
      move_object(guard, this_object());
      guard=clone_object("obj/monster");
      guard->set_name("guard");
      guard->set_level(3);
      guard->set_hp(100);
      guard->set_wc(9);
      guard->set_ac(3);
      guard->set_al(-60);
      guard->set_ep(10500);
      guard->set_short("A guard");
      guard->set_long("A guard with well tanned skin.\n");
      guard->set_aggressive(0);
      coins=clone_object("obj/money");
      coins->set_money(60);
      move_object(coins, guard);
      move_object(guard, this_object());
    }
}
