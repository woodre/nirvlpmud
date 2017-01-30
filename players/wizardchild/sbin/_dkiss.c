#include "/bin/gender.c"
#include "/bin/ghost.c"
 
#pragma strict_types
#pragma save_types
    
int cmd_dkiss(string str) {
  object who;
  if(ghost() || !str)
    return 0;
  who = present(str, environment(this_player()));
  if(!who || !living(who) || who == this_player())
    return 0;
  write("You give "+capitalize(str)+" a deep kiss, leaving "+noun(who)+" gasping for air.\n");
  tell_object(who, this_player()->query_name()+" gives you a deep kiss, leaving you "+
              "gasping for air. Wow!\n");
  say(this_player()->query_name()+" gives "+capitalize(str)+" a deep kiss, leaving "+
      noun(who)+" gasping for air.\n", who);
  return 1;
}
