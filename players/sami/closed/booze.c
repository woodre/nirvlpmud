inherit "/obj/treasure";

#include <ansi.h>

void reset(status arg) {
  ::reset(arg);
  if (arg) return;

  set_name("shot");
  set_short("A " + HIR + "bloody" + NORM + " shot");
  set_long("A shot of " + BOLD + "Samis" + NORM + " blood.\n");
  set_weight(0);
  set_value(0);
}

void init() {
  ::init();
  add_action("drink_shot", "drink");
}

int drink_shot(string str) {
  if (!str || str != "shot")
    return 0;
  write("You throw back a shot of " + BOLD + "sami's" + NORM + " blood!\n");
  say(this_player()->query_name() + " slams a shot of " + BOLD +"sami's" + NORM + " blood!\n");
  if (this_player()->query_level() <= 19)
    this_player()->drink_alcohol(10);
  destruct(this_object());
  return 1;
}