#include "/bin/gender.c"
#include "/bin/ghost.c"
 
#pragma strict_types
#pragma save_types
 
int cmd_tlip(string str) {
  object who;
  if(!str || ghost()) 
    return 0;
  who = present(str, environment(this_player()));
  if(!who || !living(who) || who == this_player())
    return 0;
  write("You trace a finger down "+capitalize(str)+"'s cheek and and let it rest "+
        "gently on "+posess(who)+" lips for a little while.\n");
  tell_object(who, this_player()->query_name()+" traces a finger down your cheek "+
       "and lets it rest gently on your lips for a little while.\n");
  say(this_player()->query_name()+" traces a finger down "+capitalize(str)+
    "'s cheek and lets it rest gently on "+posess(who)+" lips for a little while.\n", who);
  return 1;
}
