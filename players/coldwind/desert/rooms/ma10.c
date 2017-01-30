#include "/players/coldwind/define.h"

inherit "room/room";
reset(arg) {	
if(!present("giant", this_object())){
move_object(clone_object("/players/coldwind/desert/mobs/gwhite.c"), this_object());
}
  if(arg) return;
set_light(1);

short_desc = ""+HIY+"Dahna desert"+NORM+"";
long_desc =
"    You are standing on the top of the mountain.  As you look \n"+
"downward, you can watch a few clouds floating around the mountain.  \n"+
"Beautiful white snow covers the surrounding area.  Some holes and \n"+
"curves shape the face of the mountain, while large rocks and snow \n"+
"blocks you from entering any of the caves around you.  The air seems \n"+
"very thick here forcing you to do some effort to continue breathing.  \n"+
"Freezing wind blows directly at you making you shiver from the cold.\n";

items = ({
  "rocks",
  "Large brown rocks blocks you from walking east or west!",
  "clouds",
  "Bright white mists floating near the mountain",
  "sky",
  "Clear blue sky except for few clouds that floats in it randomly",
  "snow",
  "White soft snow covers the area and block you from moving in\n"+
  "almost any direction area.", 
  "mountain",
  "This is a rocky mountain with random caves and curves decorate its body",
  "caves",
  "Large holes were formed by nature in the rocky mountain. They would have made\n"+
  "perfect shelters from the cold wind if the rocks and snow didn't block you\n"+
  "from proceeding toward them",
  "holes",
  "Large caves were formed by nature in the rocky mountain.",
  "curves",
  "Mostly covered by snow; nevertheless, they can be used to "+BOLD+"descend"+NORM+" the\n"+
  "rocky mountain",
  
});


}

init(){
  ::init();
  add_action("descend_mountain", "descend");
  }

descend_mountain(){
move_object(this_player(), "/players/coldwind/desert/rooms/ma9.c");
say(""+tpn+" arrives.\n");
command("look", this_player());
return 1;
}
	