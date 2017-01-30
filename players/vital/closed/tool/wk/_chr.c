#include "/players/vital/closed/headers/vital.h"
#include <ansi.h>

main(str) {
  object who, env;
  if(!str) {
    write("Usage: chr <who>\n");
    return 1;
  }
  if(!(who = find_player(str))) {
    write("Player not found.\n");
    return 1;
  }
  tell_object(who, "You are surrounded in darkness by " +
  this_player()->query_name() + ".\n");
  write("You move " + capitalize(str) + " to the church.\n");
  env = environment(who);
  move_object(who, "room/church");
  tell_object(who, "The darkness parts to reveal the familiar surroundings of the church.\n");
  tell_room(env, capitalize(str)+" dissappears in a cloud of darkness.\n");
  return 1;
}

get_help()
{
  string help;
  help = "Syntax: chr <player>";
  return help;
}
