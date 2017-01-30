#include "/bin/ghost.c"
 
#pragma strict_types
#pragma save_types
 
int cmd_ruffle(string str) {
  object who;
  if(ghost() || !str)
    return 0;
  who = present(str, environment(this_player()));
  if(who && living(who)) {
    if(who == this_player())
      return 0;
    write("You ruffle "+capitalize(str)+"'s hair playfully.\n");
    tell_object(who, this_player()->query_name()+" ruffles your hair playfully.\n");
    say(this_player()->query_name()+" ruffles "+capitalize(str)+"'s hair playfully.\n", who);
  } else {
    who = find_player(str);
    if(!who || who == this_player() || in_editor(who) || who->query_invis() >= 20)
      return 0;
    write("You ruffle "+capitalize(str)+"'s hair playfully from afar.\n");
    tell_object(who, this_player()->query_name()+" ruffles your hair playfully from afar.\n");
  }
  return 1;
}
