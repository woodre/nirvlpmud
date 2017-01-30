#include "/bin/gender.c"
#include "/bin/ghost.c"
 
#pragma strict_types
#pragma save_types
 
int cmd_huggle(string str) {
  object who;
  if(!str || ghost())
    return 0;
  who = present(str, environment(this_player()));
  if(!who || !living(who) || who == this_player())
    return 0;
  write("You huggle "+capitalize(str)+" warmly, making "+noun(who)+" cuddle up with you.\n");
  tell_object(who, this_player()->query_name()+" huggles you warmly, making you cuddle up with "
                  +noun()+".\n"); 
  say(this_player()->query_name()+" huggles "+capitalize(str)+
      " warmly, making "+noun(who)+" cuddle up with "+noun()+".\n", who);
  return 1;
}
