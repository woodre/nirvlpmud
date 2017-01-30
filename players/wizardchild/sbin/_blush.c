#include "/bin/ghost.c"
 
#pragma strict_types
#pragma save_types
 
int cmd_blush(string str) {
  object who;
  if(ghost())
    return 0;
  if(!str) {
    write("Your cheeks are burning.\n");
    say(this_player()->query_name()+" blushes.\n");
    return 1;
  } 
  who = present(str, environment(this_player()));
  if(who && living(who)) {
    if(who == this_player())
      return 0;
    write("You blush at "+capitalize(str)+".\n");
    tell_object(who, this_player()->query_name()+" blushes at you.\n");
    say(this_player()->query_name()+" blushes at "+capitalize(str)+".\n", who);
  } else {
    who = find_player(str);
    if(!who || who == this_player() || in_editor(who) || who->query_invis() >= 20)
      return 0;
    write("You blush at "+capitalize(str)+" from afar.\n");
    tell_object(who, this_player()->query_name()+" blushes at you from afar.\n");
  }
  return 1;
}
