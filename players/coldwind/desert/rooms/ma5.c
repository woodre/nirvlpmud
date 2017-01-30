#include "/players/coldwind/define.h"

inherit "room/room";
reset(arg) {	
if(!present("giant", this_object())){
move_object(clone_object("/players/coldwind/desert/mobs/gblue.c"), this_object());
}
  if(arg) return;
set_light(1);

short_desc = ""+HIY+"Dahna desert"+NORM+"";
long_desc =
"    The few clouds that float in the sky seems closer as you stand \n"+
"on the mountain about two thousand feet above the sandy ground.  A \n"+
"cold breeze ruffles your hair as it passes by.  Some holes and curves \n"+
"shape the face of the mountain.  A large cave stands to the east, \n"+
"while a pile of rocks prevents you from proceeding west.  The air \n"+
"seems thick here forcing you to do some effort to continue breathing.\n"+  
"The yellow desert is touching the blue sky at the limit of your \n"+
"vision.\n";

items = ({
  "rocks",
  "Dark brown heavy rocks piled up. It looks as if someone stacked\n"+
  "them here to prevent you from proceeding west!",
  "pile",
  "A large pile of heavy rocks. Maybe you should "+HIW+"search"+NORM+" them well..",
  "opening",
  "A small cave in the mountain. You didn't notice it at the\n"+
  "begining because it was hidden behind the large rocks. If you\n"+
  "can go "+HIW+"around"+NORM+" the rocks, you should find yourself\n"+
  "at the enterance of the cave or maybe in it",
  "desert",
  "The yellow desert touches the sky at the limit of your vision",
  "clouds",
  "Few white clouds float freely in the blue sky",
  "sky",
  "Clear blue sky except for few clouds that floats in it randomly",
  "sand",
  "The golden sand spreads covering the face of the ground",
  "ground",
  "The golden sand spreads covering the face of the ground",  
  "mountain",
  "You are standing on the rocky mountain, two thousand feet above the\n"+
  "desert. Some caves and curves decorate the mountain",
  "caves",
  "Large holes were formed by nature in the rocky mountain. They would make perfect\n"+
  "shelters. You notice a nearby cave to the east",
  "cave",
  "A large cave seems inviting to the east",
  "holes",
  "Large caves were formed by nature in the rocky mountain. They would make\n"+
  "perfect shelters. You notice a nearby cave to the east",
  "curves",
  "It might be possible to "+BOLD+"descend or climb"+NORM+" up using the natural\n"+
  "curves in the rocky mountain",
  
});


}

init(){
  ::init();
  add_action("climb_up", "climb");
  add_action("east_cave", "east");
  add_action("east_cave", "e");
  add_action("around_rocks", "around");
  add_action("search_rocks", "search");
  add_action("descend_mountain", "descend");
  }
  search_rocks(){
  write("You notice a small opening behind the pile of rocks!\n");
  return 1;
  }
  climb_up(){
move_object(this_player(), "/players/coldwind/desert/rooms/ma9.c");
say(""+tpn+" arrives.\n");
command("look", this_player());
return 1;
}	

  east_cave(){
move_object(this_player(), "/players/coldwind/desert/rooms/ma6.c");
say(""+tpn+" arrives.\n");
command("look", this_player());
return 1;
}

 around_rocks(){
move_object(this_player(), "/players/coldwind/desert/rooms/ma7.c");
say(""+tpn+" arrives.\n");
command("look", this_player());
return 1;
}

descend_mountain(){
move_object(this_player(), "/players/coldwind/desert/rooms/ma3.c");
say(""+tpn+" arrives.\n");
command("look", this_player());
return 1;
}

	