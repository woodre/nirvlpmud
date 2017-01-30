#include "/bin/ghost.c"
 
#pragma strict_types
#pragma save_types
 
int cmd_cry(string str) {
  object who;
  if(ghost())
    return 0;
  if(!str) {
    write("WAAAAAAHHH!!!\n");
    say(this_player()->query_name()+" bursts into tears.\n");
    return 1;
  }
  who = present(str, environment(this_player()));
  if(who && living(who)) {
    if(who == this_player())
      return 0;
    write("You cry on "+capitalize(str)+"'s shoulder.\n");
    tell_object(who, this_player()->query_name()+" crys on your shoulder.\n");
    say(this_player()->query_name()+" crys on "+capitalize(str)+"'s shoulder.\n", who);
  } else {
    who = find_player(str);
    if(!who || who == this_player() || in_editor(who) || who->query_invis() >= 20)
      return 0;
    write("You cry on "+capitalize(str)+"'s shoulder from afar.\n");
    tell_object(who, this_player()->query_name()+" crys on your shoulder from afar.\n");
  }
  return 1;
}
