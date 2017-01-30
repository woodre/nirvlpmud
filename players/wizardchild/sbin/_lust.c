#include "/bin/ghost.c"
 
#pragma strict_types
#pragma save_types
 
int cmd_lust(string str) {
  object who;
  if(!str || ghost())
    return 0;
  who = present(str, environment(this_player()));
  if(!who || !living(who) || who == this_player())
    return 0;
  write("You lust for "+capitalize(str)+".\n");
  tell_object(who, this_player()->query_name()+" lusts for you.\n");
  say(this_player()->query_name()+" lusts for "+capitalize(str)+".\n", who);
  return 1;
}
