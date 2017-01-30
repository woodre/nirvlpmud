int rgoto(string str) {
  object obj;

  if (!str) { 
    write("Usage: goto <player>\n");
    return 1;
  }

  obj = find_player(str);
  if (!obj) {
    write("No such player logged in.\n");
    return 1;
  }
  move_object(this_player(), environment(obj));
  write("Moved.\n");
  return 1;
}
