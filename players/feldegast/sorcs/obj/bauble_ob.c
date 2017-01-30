#include "/players/wocket/closed/ansi.h"
#include "../def.h"
#define mage this_player()
inherit "/obj/treasure.c";

id(str){ return ( str == "bauble" || str == "ball" || str == "trinket" || str == "w_bauble" || str ==  "ball of light" ); }

reset(arg){
  if(arg) return;
  set_short("A ball of light");
  set_long("A shimmering ball of light.  This little trinket can be used to\n"+
           "juggle, peg people, bounce, or toss into the air.  It gives off\n"+
           "a bright glow but is not hot to the touch.  It sparkles with magic.\n");
  set_weight(1);
  set_value(0);
  set_dest_flag(1);
  set_save_flag(1);
}

init(){
  add_action("juggle","juggle");
  add_action("peg","peg");
  add_action("bounce","bounce");
  add_action("toss","toss");
  add_action("toss","toss");
}

toss(str){
  if(!id(str)){
    notify_fail("What would you like to toss?\n"); 
    return 0;
  }
  write("You toss your bauble high into the air and catch it.\n");
  say(mage->query_name()+" tosses "+mage->query_possessive()+" babule high into the air.\n");
  mage->chan_msg("You can see a small light rise and fall in the distance.\n","junk");
  return 1;
}
