#include "/bin/ghost.c"
 
#pragma strict_types
#pragma save_types
 
int cmd_poke(string str) {
  object who;
  if(ghost() || !str)
    return 0;
  who = present(str, environment(this_player()));
  if(who && living(who)) {
    if(who == this_player())
      return 0;
    write("You poke "+capitalize(str)+" in the ribs.\n");
    tell_object(who, this_player()->query_name()+" pokes you in the ribs.\n");
    say(this_player()->query_name()+" pokes "+capitalize(str)+" in the ribs.\n", who);
  } else {
    who = find_player(str);
    if(!who || who == this_player() || in_editor(who) || who->query_invis() >= 20)
      return 0;
    write("You poke "+capitalize(str)+" in the ribs from afar.\n");
    tell_object(who, this_player()->query_name()+" pokes you in the ribs from afar.\n");
  }
  return 1;
}
