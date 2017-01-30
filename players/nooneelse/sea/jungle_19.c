/*
 jungle_19.c
*/

inherit "room/room";

string str, long_desc_here;
int dig_count, depth_setting;

init() {
  ::init();

  add_action("dig", "dig");
}

dig() {
  string str2;
  if (!str) return;
  str2=0;
  sscanf(str, "%s shovel", str2);
  if (str != "hole" && !str2) return;
  if (!present("shovel", this_player())) {
    write("Dig?  You don't have a shovel!\n");
    return 1;
  }
  if (dig_count < depth_setting) {
    write("You dig in the soft dirt.\n");
    dig_count++;
    return 1;
  }
  write("You found something!\n");
/*  move_object(clone_object("players/nooneelse/sea/chest_1"), this_object());*/
  return 1;
}

reset(arg) {
  if (arg) return;

  set_light(1);
  short_desc = "a damp warm jungle";
  no_castle_flag=1;
  long_desc_here=
    "You are in a jungle of dark green, leafy plants.  It looks\n"+
    "like something has been scratching at the ground here.\n";
  long_desc=long_desc_here;
  dest_dir =
    ({
      "players/nooneelse/sea/jungle_1", "north",
      "players/nooneelse/sea/jungle_20", "east",
      "players/nooneelse/sea/jungle_7", "west",
      "players/nooneelse/sea/jungle_1", "south",
    });
  depth_setting=random(3)+3;
  dig_count=0;
}

look_at_here(str) {
  if (dig_count) {
    write("There is a small hole in the soft dirt.\n");
  }
  return 1;
}

id(str) {
  if (str=="hole" || str=="ground" || str=="dirt") {
    look_at_here("hole");
    return 1;
  }
}
