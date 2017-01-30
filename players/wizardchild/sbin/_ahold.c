#include "/bin/gender.c"
#include "/bin/ghost.c"
 
#pragma strict_types
#pragma save_types
 
int cmd_ahold(string str) {
  object who;
  if(ghost() || !str) 
    return 0;
  who = present(str, environment(this_player()));
  if(!who || !living(who) || who == this_player())
    return 0;
  write("You hold "+capitalize(str)+" tightly making "+noun(who)+" feel warm and cosy.\n");
  tell_object(who, this_player()->query_name()+" holds you tightly making you feel warm and cosy.\n");
  say(this_player()->query_name()+" holds "+capitalize(str)+
      " tightly making "+noun(who)+" feel warm and cosy.\n", who);
  return 1;
}
