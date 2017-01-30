#include "/bin/ghost.c"
 
#pragma strict_types
#pragma save_types
 
int cmd_kass(string str) {
  object who;
  if(ghost() || !str)
    return 0;
  who = present(str, environment(this_player()));
  if(!who || !living(who) || who == this_player()) 
    return 0;
  write("You bend over "+capitalize(str)+"'s cute little ass.\n");
  tell_object(who, this_player()->query_name()+" bends over and kisses your cute little ass.\n");
  say(this_player()->query_name()+" bends over and kisses "+capitalize(str)+"'s cute little ass.\n", who);
  return 1;
}
