/*
  paralyze_curse.c - this is a curse that prevents you from moving
                     for 60 seconds
*/

object who_obj, this_room;

query_save_flag() { return 1; }

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

dont_move() {
  write("You can't seem to move!\n");
  return 1;
}

do_paralyze(who) {
  int start_time, end_time;
  who_obj=find_living(who);
  start_time = time();
  end_time = start_time + 60;
  call_out("trash_this", end_time);
  this_room = environment(who_obj);
  call_out("check_room", 2);
  tell_object(who_obj, "You suddenly feel very sluggish.\n");
}

trash_this() {
  if (!find_object(who_obj)) {
    destruct(this_object());
    return 0;
  }
  tell_object(who_obj,
    "You feel as if you have just been released.  You can move now!\n");
  destruct(this_object());
}

check_room() {
  if (!find_object(who_obj)) {
    destruct(this_object());
    return 0;
  }
  if (environment(who_obj)!=this_room) move_object(who_obj, this_room);
  call_out("check_room", 2);
}

long() { write("How can you look at a curse ?\n"); }

drop() { return 1; }

id(str) { return str=="paralysis curse" || str=="curse"; }
