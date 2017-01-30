#include "/bin/ghost.c"
 
#pragma strict_types
#pragma save_types
 
int cmd_smile(string str) {
  object who;
  if(ghost()) {
    write("You smile inwardly.\n");
    return 1;
  }
  if(!str) {
    write("You smile happily.\n");
    say(this_player()->query_name()+" smiles happily.\n");
    return 1;
  }
  who = present(str, environment(this_player()));
  if(who && living(who)) {
    if(who == this_player())
      return 0;
    write("You smile at "+capitalize(str)+".\n");
    tell_object(who, this_player()->query_name()+" smiles at you.\n");
    say(this_player()->query_name()+" smiles at "+capitalize(str)+".\n", who);
  } else {
    who = find_player(str);
    if(!who || who == this_player() || in_editor(who) || who->query_invis() >= 20)
      return 0;
    write("You smile at "+capitalize(str)+" from afar.\n");
    tell_object(who, this_player()->query_name()+" smiles at you from afar.\n");
  }
  return 1;
}
