#include "/bin/gender.c"
#include "/bin/ghost.c"
 
#pragma strict_types
#pragma save_types
 
int cmd_kwrap(string str) {
  object who;
  if(ghost() || !str) 
    return 0;
  who = present(str, environment(this_player()));
  if(!who || !living(who) || who == this_player())
    return 0;
  write("You wrap your arms around "+capitalize(str)+" and start kissing "+noun(who)+" all over.\n");
  tell_object(who, this_player()->query_name()+" wraps "+posessive()+
              " arms around you and starts kissing you all over.\n");
  say(this_player()->query_name()+" wraps "+posessive()+" arms around "+
  capitalize(str)+" and starts kissing "+noun(who)+" all over.\n", who);
  return 1;
}
