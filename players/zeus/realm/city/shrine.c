inherit "room/room";
#include "/players/zeus/closed/all.h"
#include "/players/zeus/closed/fl_demon.h"

int teleport;

reset(arg){
 if(!arg){

  teleport = 0;  if(random(2)) teleport = 1;
  if(!present("murdok")) MO(CO("/players/zeus/realm/NPC/murdok.c"), TO);

  set_light(1);
  short_desc="The Fallen Lands";
  long_desc=
"This is a very old shrine.  It appears to be in nearly perfect condition.\n"+
"There are four large pillars at each corner, holding up a domed roof.\n"+
"Everything is made from a faded white stone.  To the north, east, and\n"+
"south, all that can be seen is dense forest.  Green vines are wrapped\n"+
"around one of the four pillars.  The floor is very cracked and uneven.\n";
  items=({
   "pillars",
"There are four thick white pillars standing at each corner of the\n"+
"shrine.  They are holding up a domed roof, which is made of the same\n"+
"white stone as the rest of the shrine.  There is a faded pattern\n"+
"painted all along the pillars.  One of the pillars is wrapped in vines",
   "roof",
"The domed roof looks very heavy, and you wonder about just how secure\n"+
"it is sitting on top of the four pillars",
   "dome",
"The domed roof is made of the same white stone as the rest of the\n"+
"shrine.  It has small cracks in a number of places, but is still in\n"+
"very good condition",
   "stone",
"The whole shrine is made from the same type of white stone.  In certain\n"+
"places, like on the pillars, a pattern was painted long ago, but has\n"+
"now faded to the point where it is nearly gone",
   "pattern",
"The pattern which is on the pillars is a very soft red.  It curls up\n"+
"each of the pillars, wrapping around them like three intertwined snakes",
   "floor",
"The white stone which makes up the floor is cracked and uneven.  In\n"+
"some places, moss is beginning to grow",
   "moss",
"In the cracks of the floor, fluffy green moss is beginning to grow",
   "vines",
"There are dark green vines hanging down from the ceiling of the shrine,\n"+
"as well as wrapped around one of the pillars",
   "forest",
"To the north, east, and south the forest is extremely thick.  Any travel\n"+
"at all in those directions would be impossible.  Some light is breaking\n"+
"through the trees, illuminating the shrine",
   "undergrowth",
"The undergrowth is amazingly thick to the north, east, and south of the\n"+
"shrine, preveting any and all travel in those directions.  It is composed\n"+
"mainly of dark green bushes and tangly vines",
   "path",
"The only path is very undefined, and is leading off to the west",
  });
  dest_dir=({ "/players/zeus/realm/city/path25.c", "west",  });
}  }

  init(){
  ::init();
  add_action("w_dir", "west");
  }

exit(){    if(TP) TP->clear_fight_area();     }
okay_follow(){ return 1; }
realm(){   if(teleport) return "NT"; }
