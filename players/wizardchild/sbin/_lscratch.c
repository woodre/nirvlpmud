#include "/bin/ghost.c"
 
#pragma strict_types
#pragma save_types
 
int cmd_lscratch(string str) {
  object who;
  if(!str || ghost())
    return 0;
  who = present(str, environment(this_player()));
  if(!who || !living(who) || who == this_player())
    return 0;
  write("You reach over and start scratching "+capitalize(str)+"'s back lovingly.\n");
  tell_object(who, this_player()->query_name()+" reaches over and starts scratching your "+
    "back lovingly. It feels sooo\ngood you just curl up and smile.\n");
  say(this_player()->query_name()+" reaches over and starts scratching "+
      capitalize(str)+"'s back lovingly.\n",who);
  return 1;
}
