#include "/bin/ghost.c"
 
#pragma strict_types
#pragma save_types
 
int cmd_pout(string str) {
  object who;
  if(ghost())
    return 0;
  if(!str) {
    write("Ah, don't take it so hard.\n");
    say(this_player()->query_name()+" pouts.\n");
    return 1;
  }
  who = present(str, environment(this_player()));
  if(who && living(who)) {
    if(who == this_player())
      return 0;
    write("You pout on "+capitalize(str)+"'s shoulder.\n");
    tell_object(who, this_player()->query_name()+" pouts on your shoulder.\n");
    say(this_player()->query_name()+" pouts on "+capitalize(str)+"'s shoulder.\n", who);
  } else {
    who = find_player(str);
    if(!who || who == this_player() || in_editor(who) || who->query_invis() >= 20) 
      return 0;
    write("You pout on "+capitalize(str)+"'s shoulder from afar.\n");
    tell_object(who, this_player()->query_name()+" pouts on your shoulder from afar.\n");
  }
  return 1;
}
