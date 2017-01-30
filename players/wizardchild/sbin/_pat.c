#include "/bin/ghost.c"
 
#pragma strict_types
#pragma save_types
 
int cmd_pat(string str) {
  object who;
  if(ghost() || !str)
    return 0;
  who = present(str, environment(this_player()));
  if(who && living(who)) {
    if(who == this_player())
      return 0;
    write("You pat "+capitalize(str)+" on the head.\n");
    tell_object(who, this_player()->query_name()+" pats you on the head.\n");
    say(this_player()->query_name()+" pats "+capitalize(str)+" on the head.\n", who);
  } else {
    who = find_player(str);
    if(!who || who == this_player() || in_editor(who) || who->query_invis() >= 20)
      return 0;
    write("You pat "+capitalize(str)+" on the head from afar.\n");
    tell_object(who, this_player()->query_name()+" pats you on the head from afar.\n");
  }
  return 1;
}
