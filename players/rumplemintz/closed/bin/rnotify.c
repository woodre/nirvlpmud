int rnotify(string str) {
  object bug;

  bug = clone_object("/players/rumplemintz/obj/notifier");

  if (!str) {
    write("Usage: rnotify <room path>\n");
    return 1;
  }
  if (!find_object(str)) str->short();
  move_object(bug, str);
  write("Notifier placed in " + str->short() + "\n");
  return 1;
}
