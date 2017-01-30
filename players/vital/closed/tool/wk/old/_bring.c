#include "/players/vital/closed/headers/vital.h" /*universal header*/
#include <ansi.h>

main(str) {
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
  tell_object(who, "You watch as your surroundings disolve.\n");
  env = environment(who);
  move_object(who, environment(this_player()));
  tell_object(who, "As the world comes back into focus, you see "+C(TPN)+" standing before you.\n");
  tell_room(env,capitalize(str)+" is slowly dissolved in front of you.\n");
  return 1;
}
