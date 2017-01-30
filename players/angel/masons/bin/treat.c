#include "defs.h"

mapping start_time;

status main(string str, int glevel) {
  string me, who;
  object target, dest2;
  
  me = (string)this_player()->query_name();
  dest2=environment(this_player());
  if (!start_time)
    start_time = ([ ]);

  if(glevel < 3) {
    write("You must have a guild ranking of 3 to use this.\n");
    return 1;
  }
  if (member(start_time, me) && time() < start_time[me]) {
    write("You are too tired to treat anyone now.\n");
    return 1;
  } 
  if(!str) {
    write("Usage:  treat <player>\n");
    return 1;
  }
  if(sscanf(str, "%s",   who) != 1) {
    write("Usage:  treat <player>\n");
    return 1;
  }
  if(call_other(this_player(),"query_spell_point") < TREAT_COST) {
    write("You are too low on power.\n");
    return 1;
  }
  if(!find_player(who)) {
    write("Player is not on.\n");
    return 1;
  }
  if(!present(find_player(who),dest2)) {
    write("That player is not here.\n");
    return 1;
  } else
  call_other(find_player(who),"add_hit_point",TREAT_HEAL);
  call_other(this_player(),"add_spell_point",-TREAT_COST);
  tell_object(find_player(who),capitalize(me)+" heals you!\n");
  tell_room(dest2,capitalize(me)+" places his hands on "+capitalize(who)+" and concentrates.\n");
  write("You heal "+capitalize(who)+".\n");
  start_time[me] = time();
  return 1;
}
