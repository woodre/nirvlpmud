/*
  shut_em_up.c.
*/

id(str) { return str=="silence curse" || str=="silence"; }

get() { return 1; }

drop() { return 1; }

init() {
  add_action("trap_command");add_xverb("");
}

/* trap all commands */
trap_command(str) {
  object obj;

  if (!environment(this_object())) {
    destruct(this_object());
  }
  if (!this_player()) return;
  if (this_player() != environment(this_object())) return;

  if (lower_case(str)=="quit") {
    this_player()->quit();
    return 1;
  }

  write("You've been silenced by a wizard.  You can do two things:\n"+
        "   1 - wait till they release you\n"+
        "   2 - quit\n");
  return 1;
}
