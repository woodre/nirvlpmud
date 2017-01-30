short() { return "A small pebble"; }
long()  {
  write("You know, like the ones you find on the ground.\n");
  write("Type 'toss at <who>'\n");
  return 1;
}
get() { 
  return 1; 
}
id(str) { return str == "rock" || str == "pebble" || str == "small pebble"; }
init() {
  add_action("toss", "toss");
}
toss(str) {
  object ob;
  string who;
  if(!sscanf(str, "at %s", who))
    who = str;
  ob = find_player(who);
  if(!ob || ob->query_invis() > this_player()->query_level()) {
    write("That person is not logged in.\n");
    return 1;
  }
  if(ob->query_level() > 21) {
    write("You cannot throw it at a wizard!\n");
    return 1;
  }
  say(this_player()->query_name()+" gently tosses a pebble at "+ob->query_name()+"\n");
  write("You toss a pebble at "+ob->query_name()+"\n");
  tell_object(ob, "A pebble comes flying out of the sky and hits you in the head.\n");
  tell_room(environment(ob), ob->query_name()+" is hit in the head with a flying pebble.\n");
  move_object(this_object(), ob);
  return 1;
}
