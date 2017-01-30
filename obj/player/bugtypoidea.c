/* 05/16/06 Earwax: Pulled this code verbatim from player.c, as it's
 * already in /bin/play in its correct form.
 */

static bug(str) {
  int s; string *sh;

  if (!str) {
  write("Give an argument.\n");
  return 1;
  }
  s = sizeof(sh = explode(str, " "));
  if(s < 2) { write("You need more than one argument.\n"); return 1; }
  current_room=object_name(environment(this_object()));
  log_file("BUGS", "\n");
  log_file("BUGS", ctime()[4..15] + " " + cap_name + " (" + current_room + "):\n");
  log_file("BUGS", str + "\n");
  smart_report("Bug " + cap_name + "\n" + str);
  write("Ok.\n");
  return 1;
}

static typo(str) {
  if (!str) {
  write("Give an argument.\n");
  return 1;
  }
  current_room=object_name(environment(this_object()));
  log_file("TYPO", ctime()[4..15] + " " + cap_name + " (" + current_room + "\n");
  log_file("TYPO", str + "\n");
  smart_report("Typo " + cap_name + "\n" + str);
  write("Ok.\n");
  return 1;
}

static idea(str) {
  if (!str) {
  write("Give an argument.\n");
  return 1;
  }
  current_room=object_name(environment(this_object()));
  log_file("IDEA", ctime()[4..15] + " " + cap_name + ":\n");
  log_file("IDEA", str + "\n");
  smart_report("Idea " + cap_name + "\n" + str);
  write("Ok.\n");
  return 1;
}
