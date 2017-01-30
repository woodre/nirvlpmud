#include "/bin/ghost.c"
 
#pragma strict_types
#pragma save_types
 
int cmd_ballad(string str) {
  object who;
  if(ghost() || !str)
    return 0;
  who = present(str, environment(this_player()));
  if(!who || !living(who) || who == this_player())
    return 0;
  write("You go down on one knee and sing a beautiful ballad in "+capitalize(str)+"'s honour.\n");
  tell_object(who, this_player()->query_name()+
      " goes down on one knee and sings a beautiful ballad in your honour.\n");
  say(this_player()->query_name()+" goes down on one knee and sings a "+
      "beautiful ballad in "+capitalize(str)+"'s honour.\n", who);
  return 1;
}
