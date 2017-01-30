#include "/bin/gender.c"
#include "/bin/ghost.c"
 
#pragma strict_types
#pragma save_types
 
int cmd_smother(string str) {
  object who;
  if(!str || ghost())
    return 0;
  who = present(str, environment(this_player()));
  if(!who || !living(who) || who == this_player())
    return 0;
  write("You smother "+capitalize(str)+" with kisses, leaving "+noun(who)+
        " happily out of breath.\n");
  tell_object(who, this_player()->query_name()+" smothers you with kisses."+
        " You're happily out of breath.\n"); 
  say(this_player()->query_name()+" smothers "+capitalize(str)+" with kisses.\n",who);
  return 1;
}
