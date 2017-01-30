#pragma strong_types

inherit "room/room";

void
reset(status arg) {
  ::reset(arg);
  if (arg)
    return;
  set_light(1);
  set_short("You are on the roof");
  set_long(
"You are on the roof, if you hadn't known better you could swear\n"+
"The building to the north looks like a stable. You can think you\n"+
"can smell sulphur here.\n");
  dest_dir = ({
    "players/kantele/stable", "north",
    "players/kantele/upper_hall", "south"
  });
}

void
init() {
  ::init();
  add_action("down", "jump");
}

status
down(string str) {
  if (str != "down" && str != "out") {
    write("You throw yourself over the edge !\n");
    write("You hit the dirt hard......\n");
    this_player()->hit_player(20);
    say(this_player()->query_name()+" throws himself down from the rof.\n");
    this_player()->move_player("down#players/kantele/garden_west");
    return 1;
  }
}
