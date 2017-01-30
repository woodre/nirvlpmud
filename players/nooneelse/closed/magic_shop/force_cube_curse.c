/*
  force_cube_curse.c - This is a curse that encloses someone in a cube for
                       2 minutes, then returns them to where they were.
*/

inherit "obj/treasure";

object who_obj, return_room_obj, cube_obj;

reset(arg) {
  set_weight(0);
  set_value(0);
}

id(str) { return str=="force cube curse" ||
                 str=="force cube" ||
                 str=="cube" ||
                 str=="curse";
}

start_curse(who) {
  who_obj=environment(this_object());
  return_room_obj = environment(who_obj);
  tell_object(return_room_obj,
    "\nA cube of force appears around "+who_obj->query_name()+".\n");
  cube_obj=clone_object("/players/nooneelse/closed/magic_shop/force_cube");
  move_object(who_obj, cube_obj);
  move_object(cube_obj, return_room_obj);
  command("look", who_obj);
  call_out("check_location", 2);
  call_out("release_from_cube", 120);
}

check_location() {
  if (environment(who_obj)!=cube_obj) move_object(who_obj, cube_obj);
  call_out("check_location", 2);
}

release_from_cube() {
  remove_call_out("check_location");
  if (!environment(this_object()) ||
      !find_object(who_obj) ||
      (environment(this_object()) &&
       environment(this_object()) != who_obj))
    destruct(this_object());
  call_other(return_room_obj, "???", 0);
  tell_object(return_room_obj,
    "\nA cube of force disappears from around "+who_obj->query_name()+".\n");
  move_object(who_obj, return_room_obj);
  command("look", who_obj);
  destruct(this_object());
  destruct(cube_obj);
}
