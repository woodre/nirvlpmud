/*
  pigeon.c - a pigeon to poop on players
*/

inherit "/obj/treasure";

string target_name;
object target_obj;

init() {
  ::init();
  add_action("seek_player", "seek");
}

seek_player(str) {
  if (!str) return 0;
  target_name = str;
  target_obj = find_player(str);
  if (!target_obj) {
    write("The pigeon can't find "+capitalize(str)+".\n");
    return 1;
  }
  tell_object(target_obj,
    "\nAs you look up, you see a rather large pigeon that seems to "+
    "be circling.\n\n");
  call_out("seek_2", 6);
  return 1;
}

seek_2() {
  tell_object(target_obj,
    "\nThe pigeon seems to be circling in toward you.\n\n");
  call_out("seek_3", 6);
  return 1;
}

seek_3() {
  tell_object(target_obj,
    "\nThe pigeon dives toward you!  As it passes overhead you hear "+
    "it squawk.\n"+
    "A second later you are hit in the face with white goo.\n\n");
  move_object(clone_object("/players/nooneelse/obj/pigeon_poop"), target_obj);
  return 1;
}

reset(arg) {
  if (arg) return 0;
  set_id("pigeon");
  set_short("A pigeon");
  set_long("A pigeon.  Use: seek <who>\n"+
           "\n  A small label says: Made by Nooneelse's Doodads Inc.\n");
  set_value(10);
  set_weight(1);
}
