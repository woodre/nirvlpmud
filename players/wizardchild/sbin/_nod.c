#include "/bin/ghost.c"
 
#pragma strict_types
#pragma save_types
 
int cmd_nod(string str) {
  object who;
  if(ghost())
    return 0;
  if(!str) {
    write("You nod solemnly.\n");
    say(this_player()->query_name()+" nods solemnly.\n");
    return 1;
  }
  who = present(str, environment(this_player()));
  if(who && living(who)) {
    if(who == this_player())
      return 0;
    write("You nod solemnly at "+capitalize(str)+".\n");
    say(this_player()->query_name()+" nods solemnly at "+capitalize(str)+".\n", who);
    tell_object(who, this_player()->query_name()+" nods solemnly at you.\n");
  } else {
    who = find_player(str);
    if(!who || who == this_player() || in_editor(who) || who->query_invis() >= 20)
      return 0;
    write("You nod solemnly at "+capitalize(str)+" from afar.\n");
    tell_object(who, this_player()->query_name()+" nods solemnly at you from afar.\n");
  }
  return 1;
}
