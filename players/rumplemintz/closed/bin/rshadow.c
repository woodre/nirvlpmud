object shadowob, stick;

int unshadow_me() {
  shadowob->remove_player_shadow();
  stick->set_shadowed(0);
  return 1;
}
  
int rshadow(string str) {
  string shad, arg;

  if (!str) {
    this_player()->unshadow();
    write("Shadows removed.\n");
    return 1;
  }

  if (sscanf(str, "%s %s", shad, arg) != 2) {
    notify_fail("Usage: rshadow <thing> <what>\n");
    return 0;
  }

  stick = present("rumpstick", this_player());

  if (stick->query_shadowed()) {
    write("You remove your current shadow.\n");
    unshadow_me();
    return 1;
  }

  write("You transform your " + shad + " to " + str + "\n");
  shadowob = clone_object("/players/rumplemintz/closed/shadows/shadowob");
  shadowob->set_shad(shad);
  shadowob->set_arg(arg);
  shadowob->set_player_shadow(this_player());
  stick->set_shadowed(1);
  return 1;
}
