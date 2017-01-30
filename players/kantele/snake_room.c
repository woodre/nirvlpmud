#pragma strong_types

inherit "room/room";

int rope;

void populate();

void
reset(status arg) {
  ::reset(arg);
  populate();
  if (arg)
    return;
  set_short("In a room with a pit");
  set_long(
"You are in a room with a pit, the only exit seems to be west,\n"+
"and you can see a large pillar standing beside the pit.\n");
  dest_dir = ({
    "players/kantele/kitiaras_crossing", "west"
  });
  items = ({
    "pit", "You look down in the pit, it seems slipery, and imposible"+
           " to climb down",
    "pillar", "A large pillar"
  });
}

void
populate() {
  rope = 0;
}

void
init() {
  ::init();
  add_action("down", "down");
  add_action("down", "climb");
  add_action("jump_down", "jump");
}

status
down() {
  if (!rope) {
    write("You would fall down the pit and possible hurt yourself.\n");
    return 1;
  }
  this_player()->move_player("down#players/kantele/snake_pit");
  return 1;
}

status
tie(string str) {
  if (str != "pillar")
    return 0;
  rope = 1;
  write("You tie a rope to the pillar.\n");
  say(this_player()->query_name()+" ties a rope to the pillar.\n");
  remove_item("pillar");
  add_item("pillar","A large pillar with a rope tied to it");
  return 1;
}

status untie(string str) {
  rope = 0;
  write("You untie the rope from the pillar.\n");
  say(this_player()->query_name()+" unties a rope from the pillar.\n");
  remove_item("pillar");
  add_item("pillar", "A large pillar");
  return 1;
}

status query_rope() { return rope; }

status
jump_down(string arg) {
  if (arg != "down")  {
    write("You throw yourself into the pit !\n");
    write("You hit the dirt hard......\n");
    this_player()->hit_player(20);
    this_player()->move_player("jump_down#players/kantele/snake_pit");
  }
  return 0;
}
