#include "/bin/ghost.c"
 
#pragma strict_types
#pragma save_types
 
int cmd_kiss(string str) {
  object who;
  if(ghost() || !str)
    return 0;
  who = present(str, environment(this_player()));
  if(who && living(who)) {
    if(who == this_player())
      return 0;
    tell_object(who, this_player()->query_name()+" kisses you.\n");
    say(this_player()->query_name()+" kisses "+capitalize(str)+".\n", who);
    if(who->query_frog()) {
      this_player()->frog_curse(1);
      who->frog_curse(0);
      return 1;
    }
    write("You kiss "+capitalize(str)+".\n");
  } else {
    who = find_player(str);
    if(!who || who == this_player() || in_editor(who) || who->query_invis() >= 20)
      return 0;
    tell_object(who, this_player()->query_name()+" kisses you from afar.\n");
    if(who->query_frog()) {
      this_player()->frog_curse(1);
      who->frog_curse(0);
      return 1;
    }
    write("You kiss "+capitalize(str)+" from afar.\n");
  }
  return 1;
}
