#include "/players/coldwind/define.h"

inherit "room/room";
reset(arg) {	
  if(arg) return;
set_light(1);

short_desc = ""+HIY+"Dahna desert"+NORM+"";
long_desc =
"    The few clouds that float in the sky seems closer as you stand \n"+
"on the mountain.  Few holes and curves shape the face of the\n"+
"mountain.  Some large rocks block you from entering any of the \n"+
"caves around you.  The air seems thick here forcing you to do some \n"+
"effort to continue breathing.  A cold breeze ruffles your hair as it\n"+
"passes by.  The yellow desert is touching the blue sky at the limit  \n"+
"of your vision.\n";

items = ({
  "rocks",
  "Large brown rocks block you from walking east or west!",
  "desert",
  "The yellow desert touches the sky at the end of your vission limit",
  "clouds",
  "Few white clouds float freely in the blue sky",
  "sky",
  "Clear blue sky except for few clouds that floats in it randomly",
  "sand",
  "The golden sand spreads covering the face of the ground",
  "ground",
  "The golden sand spreads covering the face of the ground",  
  "mountain",
  "The rocky mountain stands proudly carrying you few thousand feet above the\n"+
  "desert. Some caves and curves shape its face",
  "caves",
  "Large holes were formed by nature in the rocky mountain. They would make\n"+
  "perfect shelters.",
  "holes",
  "Large caves were formed by nature in the rocky mountain. They would make \n"+
  "perfect shelters.",
  "curves",
  "It might be possible to "+BOLD+"descend or climb"+NORM+" up using the natural\n"+
  "curves in the rocky mountain",
  
});


}

init(){
  ::init();
  add_action("climb_up", "climb");
  add_action("descend_mountain", "descend");
  }
 
  climb_up(){
move_object(this_player(), "/players/coldwind/desert/rooms/ma10.c");
say(""+tpn+" arrives.\n");
command("look", this_player());
return 1;
}	

descend_mountain(){
move_object(this_player(), "/players/coldwind/desert/rooms/ma5.c");
say(""+tpn+" arrives.\n");
command("look", this_player());
return 1;
}

	