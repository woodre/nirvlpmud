/*
 beach_1.c
*/

inherit "room/room";

int search_count, search_target;

init() {
  ::init();

  add_action("search", "search");
}

search() {
  if (search_count < search_target) {
    write("You find nothing unusual.\n");
    return 1;
  }
  write("You find a small path and climb up into the mountains!\n");
  say(this_player()->query_name()+
        " follows a small trail up into the mountains.\n");
  call_other("players/nooneelse/sea/mountain_1", "???", 0);
  move_object(this_player(), "players/nooneelse/sea/mountain_1");
  command("look", this_player());
  search_count=0;
  search_target=random(3)+3;
  return 1;
}

reset(arg) {
  if (arg) return;

  set_light(1);
  short_desc = "a beach with warm sand";
  no_castle_flag=1;
  long_desc =
    "This clean, trackless warm beach between the sea and a jungle.\n"+
    "There doesn't seem to be a path into the mountains to the north.\n";
  dest_dir =
    ({
      "players/nooneelse/sea/island_hall", "southwest",
      "players/nooneelse/sea/beach_2", "east",
      "players/nooneelse/sea/beach_4", "west",
      "players/nooneelse/sea/jungle_1", "south",
      "players/nooneelse/sea/sea_1", "down",
    });
  search_count=0;
  search_target=random(3)+3;
}
