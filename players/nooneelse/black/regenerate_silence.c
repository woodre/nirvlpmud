/*
  regenerate_silence.c
*/


query_save_flag() { return 1; }

id(str) { return str=="regenerate silence" || str=="silence"; }

get() { return 1; }

drop() { return 1; }

init() {
#ifndef __LDMUD__
  add_action("trap_command");add_xverb("");
#else
  add_action("trap_command", "", 3);
#endif
}

/* trap all commands */
trap_command(str) {
  object obj, return_room, silence_room;
  string str1;

  if (!environment(this_object())) {
    destruct(this_object());
  }
  if (!this_player()) return;
  if (this_player() != environment(this_object())) return;

  if (sscanf(str, "help %s", str1)==1) return;

  if (lower_case(str)=="check health") {
    environment(this_object())->score();
    environment(this_object())->score2();
    return 1;
  }

  if (lower_case(str)=="end regenerate") {
    write("You become aware of your surroundings once again as you make\n"+
          "your way above ground.\n");
    return_room = environment(environment(environment(this_object())));
    silence_room = environment(environment(this_object()));
    move_object(this_player(), return_room);
    if (silence_room) destruct(silence_room);
    present("vampire fangs", environment(this_object()))->tell_my_room(
      "A mist seems to seep up from the ground and slowly takes the shape of "+
      this_player()->query_name()+".");
    destruct(this_object());
    return 1;
  }

  if (this_player()->query_real_name()=="nooneelse") return;

  write("While regenerating, you can only:\n"+
        "'end regenerate' to leave this state\n"+
        "'check health' to check your health\n"+
        "use vampire guild or mud helps\n");
  return 1;
}
