#include <ansi.h>
inherit "/obj/treasure.c";
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()

reset (arg) {
	set_id("tape");
      set_weight(0);
}

init(){
  ::init();
    add_action("tellem","tell"); 
    add_action("tellem","say");
#ifndef __LDMUD__
    add_action("tellem"); add_xverb("'");
    add_action("tellem"); add_xverb(":");
#else
  add_action("tellem", "'", 3);
  add_action("tellem", ":", 3);
#endif
    add_action("tellem","gossip");
    add_action("tellem","star");
    add_action("tellem","junk");
    add_action("tellem","babble");
    add_action("tellem","shout");
    add_action("tellem","equip");
    add_action("tellem","ring");
    add_action("tellem","be");
    add_action("tellem","newbie");
    add_action("tellem","risque");
    add_action("tellem","derv");
    add_action("tellem","derve");
/*
    add_action("tellem","tc");
*/
    add_action("tellem","tce");
    add_action("tellem","net");
    add_action("tellem","nem");
    add_action("tellem","rt");
    add_action("tellem","rte");
    add_action("tellem","emote");
    add_action("tellem","bleat");
    add_action("tellem","gt");
    add_action("tellem","te");
    add_action("tellem","tf");
    add_action("tellem","tt");
    add_action("tellem","techie");
    add_action("tellem","farem");
    add_action("tellem"); add_verb("?");
    add_action("tellem","bdt");
    add_action("tellem","bbe");
    add_action("tellem","bts");
    add_action("tellem","mtell");
    add_action("tellem","reply");
    add_action("tellem","hte");
    add_action("tellem","ht");
    add_action("tellem","hta");
    add_action("tellem","att");
    add_action("tellem","ate");
    add_action("tellem","chat");
    add_action("tellem","chate");
    add_action("tellem","brag");
    add_action("tellem","recite");
    add_action("tellem","recitee");
    add_action("tellem","Recite");
    add_action("tellem","brage");
    add_action("tellem","meow");
    add_action("tellem","meowe");
    add_action("tellem","story");
    add_action("tellem","storye");
    add_action("tellem","tempt");
    add_action("tellem","tempte");
    add_action("tellem","sp");
    add_action("tellem","fdraw");
    add_action("tellem","punt");
   add_action("tellem","party say");
 }

tellem(){
  write("You can't talk with duct tape on your mouth!!!\n");
  return 1; }

drop(){ return 1; }
give(){ return 1; }

extra_look(){
  return ""+tpn+" has a thick piece of duct tape placed over "+tpp+" mouth"; }

