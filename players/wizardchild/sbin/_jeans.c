#include "/bin/gender.c"
#include "/bin/ghost.c"
 
#pragma strict_types
#pragma save_types
 
int cmd_jeans(string str) {
  object who;
  if(ghost() || !str)
    return 0;
  who = present(str, environment(this_player()));
  if(!who || !living(who) || who == this_player())
    return 0;
  write("You sneak your hands into the back pockets of "+capitalize(str)+"'s jeans,"+
        " pull "+noun(who)+" very close and give "+noun(who)+" a deep, lingering kiss.\n");
  tell_object(who, this_player()->query_name()+" sneaks "+posessive()+" hands into the "+
              "back pockets of your jeans, pulls you very close and gives you a deep "+
              "lingering kiss.\n");
  say(this_player()->query_name()+" sneaks "+posessive()+" hands into the back pockets of "+
      capitalize(str)+"'s jeans, pulls "+noun(who)+" very close and gives "+noun(who)+
      " a deep, lingering kiss.\n", who);
  return 1;
}
