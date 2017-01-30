#include "/players/wocket/closed/ansi.h"
inherit "/obj/treasure.c";


reset(arg){
if(arg) return;
set_id("orb");
set_alias("sliver");
set_short("A sliver of an orb "+HIY+"(@)"+NORM);
set_long("This is a sliver of a glowing orb of swirling light.  This mystic energy\n"+
    "source will teleport you back to the source of power if you're located near\n"+
    "the orb itself.  You need only 'go angel' and you will be whisked away.  Many\n"+
    "would pay dearly for such a treasure so it might be possible to 'cash' the\n"+
    "sliver in to someone.\n");
set_value(100);
set_weight(1);
}

init(){
  add_action("angelgo","go");
  add_action("cash","cash");
}

angelgo(str){
string envo,begin,tail;
  if(!str || str != "angel"){
    notify_fail("Where would you like to go?\n");
    return 0;
}
envo = file_name(environment(this_player()));
sscanf(envo,"%splayers/wocket/%s",begin,tail);
if(!tail){
    notify_fail("You are not in the right area for this sliver to work.\n");
    return 0;
}
write("You touch the sliver.\n");
write("A mist of light envelopes you as your surroundings change.\n\n");
say("A mist of light envelopes "+this_player()->query_name()+".\n");
move_object(this_player(),"/room/south/sforst45.c");
command("glance",this_player());
say("A mist of light unfolds and "+this_player()->query_name()+" steps out.\n");
destruct(this_object());
return 1;
}

cash(str){
int i;
if(!str || str != "sliver"){
  notify_fail("What would you like to cash?\n");
  return 0;
}
i = 4000+random(1000);
write("You cash in the sliver for "+i+" coins.\n");
say(this_player()->query_name()+" cashes in a sliver of an orb.\n");
this_player()->add_money(i);
destruct(this_object());
return 1;
}

