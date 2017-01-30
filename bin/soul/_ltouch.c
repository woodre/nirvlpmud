#include "/bin/ghost.c"
 
#pragma strict_types
#pragma save_types
 
int cmd_ltouch(string str) {
  object who;
  string where, wh;
  if(!str || ghost())
    return 0;
  if(sscanf(str, "%s %s", wh, where) != 2) {
    wh = str;
    where = "body";
  }
  who = present(wh, environment(this_player()));
  if(!who || !living(who) || who == this_player())
    return 0;
  write("You touch "+capitalize(wh)+"'s "+where+" with loving hands.\n");
  tell_object(who, this_player()->query_name()+" touches your "+where+" with loving hands.\n");
  say(this_player()->query_name()+" touches "+capitalize(wh)+"'s "+where+
      " with loving hands.\n", who);
  return 1;
}
