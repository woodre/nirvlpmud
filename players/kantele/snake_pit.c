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
  set_short("You are in the snake pit");
  dest_dir = ({
    "players/kantele/snake_room", "up"
  });
}

void
long() {
  write("You are in the snake pit,  it seems impossible to get out !!\n");
  if ("players/kantele/snake_room"->query_rope())
    write("There is a rope hanging down through the hole.\n");
}

void
populate() {
  object snake, orb, bar;
  if (!present("snake", this_object())) {
    int i;
    i = random(10);
    while (i > 0 ) {
      i -= 1;
      snake = clone_object("obj/monster");
      snake->set_name("snake");
      snake->set_level(random(5));
      snake->set_short("A small poison snake");
      snake->set_wc(random(30));
      snake->set_aggressive(1);
      move_object(snake, this_object());
    }
    orb = clone_object("obj/treasure");
    orb->set_name("orb");
    orb->set_value(750);
    orb->set_short("A small gold orb");
    orb->set_alias("gold orb");
    move_object(orb, this_object());
    bar = clone_object("obj/treasure");
    bar->set_name("bar");
    bar->set_value(750);
    bar->set_short("A gold bar");
    bar->set_alias("gold bar");
    move_object(bar, this_object());
  }
}

void
init() {
  ::init();
  add_action("go_up", "up");
}

status
go_up() {
  if (!"players/kantele/snake_room"->query_rope()) {
    write("You can't go stright up with some kind of support.\n");
    return 1;
  }
  return 0;
}
