#include "/bin/gender.c"
#include "/bin/ghost.c"
 
#pragma strict_types
#pragma save_types
 
int cmd_neck(string str) {
  object who;
  if(!str || ghost())
    return 0;
  who = present(str, environment(this_player()));
  if(!who || !living(who) || who == this_player())
    return 0;
  write("You lean closer to "+capitalize(str)+" and bite "+posess(who)+" neck lustily.\n");
  tell_object(who, this_player()->query_name()+" leans closer and bites your neck lustily."+
    " It feels very nice, sending shivers of delight down your spine.\n");
  say(this_player()->query_name()+" leans closer to "+capitalize(str)+" and bites "
    +posess(who)+" neck lustily.\n", who);
  return 1;
}
