#include "/bin/ghost.c"
 
#pragma strict_types
#pragma save_types
 
int cmd_beg(string str) {
  object who;
  if(ghost())
    return 0;
  if(!str) {
    write("You beg like a dog.\n");
    say(this_player()->query_name()+" begs like a dog.\n");
    return 1;
  }
  who = present(str, environment(this_player()));
  if(who && living(who)) {
    if(who == this_player())
      return 0;
    write("You beg "+capitalize(str)+" like a dog.\n");
    tell_object(who, this_player()->query_name()+" begs you like a dog.\n");
    say(this_player()->query_name()+" begs "+capitalize(str)+" like a dog.\n", who);
  } else {
    who = find_player(str);
    if(!who || who == this_player() || in_editor(who) || who->query_invis() >= 20)
      return 0;
    write("You beg "+capitalize(str)+" like a dog from afar.\n");
    tell_object(who, this_player()->query_name()+" begs you like a dog from afar.\n");
  }
  return 1;
}
