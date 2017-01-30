chr(str) {
  object w, env;
  if(!str) {
    write("Usage: chr <who>\n");
    return 1;
  }
  if(!(w = find_player(str))) {
    write("Player not found.\n");
    return 1;
  }
  tell_object(w, "You are moved to the church by "+this_player()->query_name()+"
.\n");
  write("You move "+capitalize(str)+" to the church.\n");
  env = environment(w);
  move_object(w, "room/church");
  tell_room(env, capitalize(str)+" dissappears in a cloud of darkness.\n");
  return 1;
}
