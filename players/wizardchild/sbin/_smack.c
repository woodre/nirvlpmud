#include "/bin/ghost.c"
 
#pragma strict_types
#pragma save_types
 
int cmd_smack(string str) {
  object who;
  if(ghost() || !str)
    return 0;
  who = present(str, environment(this_player()));
  if(who && living(who)) {
    if(who == this_player())
      return 0;
    write("You smack "+capitalize(str)+" across the face.\n");
    tell_object(who, this_player()->query_name()+" smacks you across the face!\n");
    say(this_player()->query_name()+" smacks "+capitalize(str)+".\n", who);
  } else {
    who = find_player(str);
    if(!who || who == this_player() || in_editor(who) || who->query_invis() >= 20)
      return 0;
    write("You smack "+capitalize(str)+" across the face from afar.\n");
    tell_object(who, this_player()->query_name()+" smacks you across the face from afar!\n");
  }
  return 1;
}
