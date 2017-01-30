#include "/bin/ghost.c"
 
#pragma strict_types
#pragma save_types
 
int cmd_massage(string str) {
  object who;
  if(!str || ghost())
    return 0;
  who = present(str, environment(this_player()));
  if(!who || !living(who) || who == this_player())
    return 0;
  write("You give "+capitalize(str)+" a long and tender massage.\n");
  tell_object(who, this_player()->query_name()+" gives you a long and tender "
   +"massage. You feel completely relaxed.\n");
  say(this_player()->query_name()+" gives "+capitalize(str)+" a long and "
   +"tender massage.\n", who);
  return 1;
}
