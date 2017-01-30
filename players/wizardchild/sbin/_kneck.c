#include "/bin/ghost.c"
 
#pragma strict_types
#pragma save_types
 
int cmd_kneck(string str) {
  object who;
  if(ghost() || !str) 
    return 0;
  who = present(str, environment(this_player()));
  if(!who || !living(who) || who == this_player())
    return 0;
  write("You kiss "+capitalize(str)+"'s neck passionately.\n");
  tell_object(who, this_player()->query_name()+" kisses your neck passionately.\n");
  say(this_player()->query_name()+" kisses "+capitalize(str)+"'s neck passionately.\n", who);
  return 1;
}
