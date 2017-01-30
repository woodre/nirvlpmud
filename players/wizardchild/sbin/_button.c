#include "/bin/gender.c"
#include "/bin/ghost.c"
 
#pragma strict_types
#pragma save_types
 
int cmd_button(string str) {
  object who;
  if(ghost() || !str) 
    return 0;
  who = present(str, environment(this_player()));
  if(!who || !living(who) || who == this_player())
    return 0;
  write("You stick your tongue into "+capitalize(str)+"'s belly button "+
        "and place hot kisses around it making "+noun(who)+" shiver with delight.\n");
  tell_object(who, this_player()->query_name()+" sticks "+posessive()+" tongue "+
        "into your belly button and places hot kisses around it making you shiver "+
        "with delight.\n"); 
  say(this_player()->query_name()+" sticks "+posessive()+" tongue into "+capitalize(str)+
      "'s belly button and places hot kisses around it making "+noun(who)+" shiver with "+
      "delight.\n", who); 
  return 1;
}
