#pragma strong_types

#include <ansi.h>

inherit "obj/monster";

string *dest_room;

void reset(int arg) {
  ::reset(arg);
  if (arg)
    return;
  set_name("workroom");
  set_short(HIG+"Rumplemintz's"+NORM+" workroom");
  set_long("My Workroom test.\n");
  set_level(1000);
}

void init() {
  ::init();
  add_action("Rexit", "down");
  add_action("Rexit", "church");
  add_action("Rexit", "green");
  call_out("move_me", 20);
}

int Rexit() {
  string exit_room;
  switch(query_verb()) {
    case "down": exit_room = (string)environment(this_object()); break;
    case "church": exit_room = "/room/church"; break;
    case "green": exit_room = "/room/vill_green"; break;
    default: exit_room = "/room/void"; break;
  }
  this_player()->move_player(query_verb+"#"+exit_room+"");
  return 1;
}

int move_me() {
  int i;
  string *dest_room;

  dest_room = allocate[3];
  i = random(3);

  dest_room[0] = "void";
  dest_room[1] = "alley";
  dest_room[2] = "attic";

  write("The workroom sinks into the ground.\n");
  move_object(this_object(), "room/"+dest_room[i]);
  write("Rumplemintz's workroom arrises from the ground.\n");
  call_out("move_me", 20);
  return 1;
}
