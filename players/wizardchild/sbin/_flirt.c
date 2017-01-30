#include "/bin/ghost.c"
 
#pragma strict_types
#pragma save_types
 
int cmd_flirt(string str) {
  object who;
  if(!str) {
    write("You flirt with everyone and they percieve you as being easy.\n");
    say(this_player()->query_name()+" flirts with the entire room.\n");
    return 1;
  }
  who = present(str, environment(this_player()));
  if(who && living(who)) {
    if(who == this_player())
      return 0;
    write("You begin flirting with "+capitalize(str)+".\n");
    tell_object(who, this_player()->query_name()+" begins making advances towards you.\n");
    say(this_player()->query_name()+" begins flirting with "+capitalize(str)+".\n", who);
  } else {
    who = find_player(str);
    if(!who || who == this_player() || in_editor(who) || who->query_invis() >= 20)
      return 0;
    write("You begin flirting with "+capitalize(str)+" from afar.\n");
    tell_object(who, this_player()->query_name()+" starts to flirt with you from afar.\n");
  }
  return 1;
}
