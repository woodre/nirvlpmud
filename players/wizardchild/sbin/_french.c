#include "/bin/ghost.c"
 
#pragma strict_types
#pragma save_types
 
int cmd_french(string str) {
  object who;
  if(!str || ghost())
    return 0;
  who = present(str, environment(this_player()));
  if(who && living(who)) {
    if(who == this_player())
      return 0;
    write("You give "+capitalize(str)+" a REAL kiss..it lasts a long time...\n");
    tell_object(who, this_player()->query_name()+
      " gives you a deep and passionate kiss..it seems to take forever...\n");  
    say(this_player()->query_name()+" gives "+capitalize(str)+
        " a deep and passionate kiss..it seems to take forever...\n", who);
  } else {
    who = find_player(str);
    if(!who || who == this_player() || in_editor(who) || who->query_invis() >= 20)
      return 0;
/* long tongues */
    write("You give "+capitalize(str)+" a REAL kiss from afar..it lasts a long time...\n");
    tell_object(who, this_player()->query_name()+
      " gives you a deep and passionate kiss from afar..it seems to take forever...\n");
  }
  return 1;
}
