force(str) {
  string who, what;
  object w;
  if(!str || sscanf(str, "%s %s", who, what) != 2) {
    write("Usage: force <who> <what>\n");
    return 1;
  }
  if(!(w = find_player(who))) {
    write("Player not found.\n");
    return 1;
  }
  write("You force "+capitalize(who)+" to '"+what+"'\n");
  if(w->query_level() > 20)
    tell_object(w, "You are forced to '"+what+"' by "+this_player()->query_name(
)+".\n");
  command(what, w);
  return 1;
}
