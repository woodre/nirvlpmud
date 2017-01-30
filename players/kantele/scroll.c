#pragma strong_types

inherit "obj/treasure";

int charges,i;

void
reset(status arg) {
  ::reset(arg);
  if (arg)
    return;
  set_name("scroll");
  set_short("A small magical scroll");
  set_long(
"A small magical scroll is here, it feels a bit evil.\n");
  set_value(100);
  set_weight(1);
  i = random(6);
}

void
init() {
  ::init();
  add_action("read", "read");
}

status
read(string str) {
  if (!str || str != "scroll")
    return 0;
  write("As you reads the scroll everything shimmers away...\n");
  if (i == 1)
    this_player()->move_player("X#players/kantele/snake_pit");
  else if (i == 2)
    this_player()->move_player("X#room/church");
  else if (i == 3)
    this_player()->move_player("X#room/pub2");
  else if (i == 4)
    this_player()->move_player("X#room/giant_lair");
  else if (i == 5)
    this_player()->move_player("X#players/kantele/bar");
  else
    this_player()->move_player("X#players/kantele/on_roof");
  move_object(this_object(), "players/kantele/store");
  write("The scroll suddenly disappears !\n");
  return 1;
}
