#include "/bin/ghost.c"
#include "/bin/posessive.c"
 
#pragma strict_types
#pragma save_types
 
int cmd_shake(string str) {
  object who;
  if(ghost())
    return 0;
  if(!str) {
    write("You shake your head.\n");
    say(this_player()->query_name()+" shakes "+posessive()+" head.\n");
    return 1;
  }
  who = present(str, environment(this_player()));
  if(who && living(who)) {
    write("You shake "+capitalize(str)+"'s hand.\n");
    tell_object(who, this_player()->query_name()+" shakes your hand.\n");
    say(this_player()->query_name()+" shakes "+capitalize(str)+"'s hand.\n", who);
  } else {
    who = find_player(str);
    if(!who || who == this_player() || in_editor(who) || who->query_invis() >= 20)
      return 0;
    write("You shake "+capitalize(str)+"'s hand from afar.\n");
    tell_object(who, this_player()->query_name()+" shakes your hand from afar.\n");
  }
  return 1;
}
