#include "/bin/posessive.c"
#include "/bin/ghost.c"
 
#pragma strict_types
#pragma save_types
 
int cmd_nuzzle(string str) {
  object who;
  if(!str || ghost())
    return 0;
  who = present(str, environment(this_player()));
  if(!who || !living(who) || who == this_player())
    return 0;
  write("You bury your face in "+capitalize(str)+"'s neck and purr happily.\n");
  tell_object(who, this_player()->query_name()+" buries "+posessive()+" face in your neck and purrs happily.\n");
  say(this_player()->query_name()+" buries "+posessive()+" face in "+capitalize(str)+
      "'s neck and purrs happily.\n", who);
  return 1;
}
