#include "/bin/ghost.c"
 
#pragma strict_types
#pragma save_types
 
int cmd_tackle(string str) {
  object who;
  if(ghost() || !str)
    return 0;
  who = present(str, environment(this_player()));
  if(who && living(who)) {
    if(who == this_player())
      return 0;
    write("You tackle "+capitalize(str)+" to the ground.\n");
    tell_object(who, this_player()->query_name()+" tackles you!\n");
    say(this_player()->query_name()+" tackles "+capitalize(str)+" to the ground.\n", who);
  } else {
    who = find_player(str);
    if(!who || who == this_player() || in_editor(who) || who->query_invis() >= 20)
      return 0;
    write("You tackle "+capitalize(str)+" to the ground from afar.\n");
    tell_object(who, this_player()->query_name()+" tackles you to the ground from afar!\n");
  }
  return 1;
}
