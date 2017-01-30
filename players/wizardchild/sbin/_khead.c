#include "/bin/gender.c"
#include "/bin/ghost.c"
 
#pragma strict_types
#pragma save_types
 
int cmd_khead(string str) {
  object who;
  if(ghost() || !str)
    return 0;
  who = present(str, environment(this_player()));
  if(!who || !living(who) || who == this_player())
    return 0;
  write("You caress "+capitalize(str)+"'s hair and kiss "+posessive()+" forehead.\n");
  tell_object(who, this_player()->query_name()+" caresses your hair and kisses your forehead.\n");
  say(this_player()->query_name()+" caresses "+capitalize(str)+
      " and kisses "+posess(who)+" forehead.\n", who);
  return 1;
}
