#include "/bin/ghost.c"
 
#pragma strict_types
#pragma save_types
 
int cmd_wink(string str) {
  object who;
  if(ghost())
    return 0;
  if(!str) {
    write("You wink.\n");
    say(this_player()->query_name()+" winks suggestively.\n");
    return 1;
  }
  who = present(str, environment(this_player()));
  if(who && living(who)) {
    if(who == this_player())
      return 0;
    write("You wink at "+capitalize(str)+".\n");
    tell_object(who, this_player()->query_name()+" winks at you suggestively.\n");
    say(this_player()->query_name()+" winks at "+capitalize(str)+" suggestively.\n", who);
  } else {
    who = find_player(str);
    if(!who || who == this_player() || in_editor(who) || who->query_invis() >= 20)
      return 0;
    write("You wink at "+capitalize(str)+" from afar.\n");
    tell_object(who, this_player()->query_name()+" winks at you suggestively from afar.\n");
  }
  return 1;
}
