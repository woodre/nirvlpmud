#include "/bin/ghost.c"
 
#pragma strict_types
#pragma save_types
 
int cmd_thold(string str) {
  object who;
  if(!str || ghost())
    return 0;
  who = present(str, environment(this_player()));
  if(!who || !living(who) || who == this_player())
    return 0;
  write("You hold "+capitalize(str)+" damn tight!\n");
  tell_object(who,this_player()->query_name()+" holds you damn tight!\n"); 
  say(this_player()->query_name()+" holds "+capitalize(str)+" damn tight!\n", who);
  return 1;
}
