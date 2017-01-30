#include "../DEFS.h"

status walk_delay(string str) {
  string message, name;
  object player, ob;
  sscanf(str, "%s %s", message, name);
  player = find_player(name);
  ob = environment(player);
  if(command(message, ob))
    command("look",player);
  return 1;
}

status main(string str) {
  /* allows pilot to move the mech around      */
  /* works on a delay, according to mech speed */
  int speed;
  string name;
  if(!str) {
    write("Usage: walk <direction>\n");
    return 1;
  }
  name = TPN;
  name = lower_case(name);
  speed = (int)(ETP->query_speed());
  call_out("walk_delay", speed, str+" "+name);
  return 1;
}
