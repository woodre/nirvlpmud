bring(str) {
  object who, env;
  if(!str) {
    write("Usage: bring <who>  or  trans <who>\n");
    return 1;
  }
  if(!(who = find_player(str))) {
    write("Player not found.\n");
    return 1;
  }
  write(capitalize(str)+" answers your summons.\n");
  tell_object(who, "You are summoned by "+this_player()->query_name()+".\n");
  env = environment(who);
  move_object(who, environment(this_player()));
  tell_room(env,capitalize(str)+" is summoned by a higher force.\n");
  return 1;
}
