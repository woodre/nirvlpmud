/*
  paralyze_curse.c - A curse that prevents you from moving for 3 minutes
*/

string who;

object who_obj;

int start_time, end_time;

init() {
  add_action("dont_move",   "north");
  add_action("dont_move",   "northeast");
  add_action("dont_move",   "east");
  add_action("dont_move",   "southeast");
  add_action("dont_move",   "south");
  add_action("dont_move",   "southwest");
  add_action("dont_move",   "west");
  add_action("dont_move",   "northwest");
  add_action("dont_move",   "enter");
  add_action("dont_move",   "in");
  add_action("dont_move",   "exit");
  add_action("dont_move",   "out");
  add_action("dont_move",   "use");
}

do_paralyze(who) {
  who_obj=find_player(who);
  start_time = time();
  end_time = start_time + 180;
  tell_object(who_obj, "You suddenly feel very sluggish.\n");
}

dont_move() {
  if (time() >= end_time) {
    write("You feel as if you have just been released.  You can move now!\n");
    destruct(this_object());
    return 1;
  }
  write("You can't seem to move!\n");
  say(this_player()->query_name()+" seems to be trying to move, but can't.\n");
  return 1;
}

long() { write("How can you look at a curse ?\n"); }

drop() { return 1; }

id(str) { return str=="paralyze curse" || str=="paralysis curse"; }
