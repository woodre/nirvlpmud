#include "/bin/ghost.c"
 
#pragma strict_types
#pragma save_types
 
int cmd_high5(string str) {
  object who;
  if(ghost() || !str)
    return 0;
  who = present(str, environment(this_player()));
  if(who && living(who)) {
    if(who == this_player())
      return 0;
    write("You run up and slap "+capitalize(str)+" a high-five!\n");
    tell_object(who, this_player()->query_name()+" runs up to you and "+
                "slaps you a high-five!\n");
    say(this_player()->query_name()+" slaps "+capitalize(str)+" a high-five!\n", who);
  } else {
    who = find_player(str);
    if(!who || who == this_player() || in_editor(who) || who->query_invis() >= 20)
      return 0;
    write("You run up and slap "+capitalize(str)+" a high-five from afar!\n");
    tell_object(who, this_player()->query_name()+" runs up to you and "+
                "slaps you a high-five from afar!\n");
  }
  return 1;
}
