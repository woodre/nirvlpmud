#include "/bin/gender.c"
#include "/bin/ghost.c"
 
#pragma strict_types
#pragma save_types
 
int cmd_khand(string str) {
  object who;
  if(ghost() || !str) 
    return 0;
  who = present(str, environment(this_player()));
  if(!who || !living(who) || who == this_player())
    return 0;
  write("You stare "+capitalize(str)+" in the eyes as you softly kiss "+posess(who)+" hand.\n");
  tell_object(who, this_player()->query_name()+" stares you in the eyes as "+pronoun()+" softly kisses your hand.\n");
  say(this_player()->query_name()+" stares "+capitalize(str)+" in the eyes as "+pronoun()+
      " softly kisses "+posess(who)+" hand.\n", who);
  return 1;
}
