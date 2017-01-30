#include "/bin/gender.c"
#include "/bin/ghost.c"
 
#pragma strict_types
#pragma save_types
 
int cmd_kcheek(string str) {
  object who;
  if(ghost() || !str) 
    return 0;
  who = present(str, environment(this_player()));
  if(!who || !living(who) || who == this_player()) 
    return 0;
  write("You walk up to "+capitalize(str)+" and kiss "+noun(who)+" on the cheek.\n");
  tell_object(who, this_player()->query_name()+" walks up to you and kisses you on the cheek.\n");
  say(this_player()->query_name()+" walks up to "+capitalize(str)+" and kisses "+
      noun(who)+" on the cheek.\n", who);
  return 1;
}
