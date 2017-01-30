#include "/bin/gender.c"
#include "/bin/ghost.c"
 
#pragma strict_types
#pragma save_types
 
int cmd_lgaze(string str) {
  object who;
  if(ghost() || !str)
    return 0;
  who = present(str, environment(this_player()));
  if(!who || !living(who) || who == this_player())
    return 0;
  write("You gaze lovingly at "+capitalize(str)+", staring "+noun(who)+" deep in the eyes.\n");
  tell_object(who, this_player()->query_name()+
              " gazes lovingly at you, staring you deep in the eyes.\n");
  say(this_player()->query_name()+" gazes lovingly at "+capitalize(str)+", staring "+noun(who)+
      " deep in the eyes.\n", who);
  return 1;
}
