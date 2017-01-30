pris(str) {
  object w, env;
  if(!str) {
    write("Usage: pris <who>\n");
    return 1;
  }
  if(!(w = find_player(str))) {
    write("Player not found.\n");
    return 1;
  }
  if(w->query_level() >= 100) {
    write("I think not.\n");
    tell_object(w, this_player()->query_real_name()+" tried to place you in /roo
m/prison\n");
    return 1;
  }
  write("You move "+capitalize(str)+" to the prison.\n");
  tell_object(w, "You are sent to prison by "+this_player()->query_name()+".\n")
;
  env = environment(w);
  move_object(w, "room/prison");
  tell_room(env, capitalize(str)+" is imprisoned.\n");
  return 1;
}
