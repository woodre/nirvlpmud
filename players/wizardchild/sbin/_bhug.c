#include "/bin/ghost.c"
 
#pragma strict_types
#pragma save_types
 
int cmd_bhug(string str) {
  object who;
  if(!str || ghost())
    return 0;
  who = present(str, environment(this_player()));
  if(!who || !living(who) || who == this_player())
    return 0;
  write("You give "+capitalize(str)+" a giant bearhug. "+capitalize(str)
       +" gasps for air.\n");
  tell_object(who, this_player()->query_name()+" gives you a giant bearhug. You gasp for air.\n");
  say(this_player()->query_name()+" gives "+capitalize(str)+" a giant bearhug. "+capitalize(str)+
      " gasps for air.\n", who);
  return 1;
}
