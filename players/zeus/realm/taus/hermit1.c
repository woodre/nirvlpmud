inherit "room/room";
#include "/players/zeus/closed/all.h"
#include "/players/zeus/closed/fl_demon.h"

int teleport, door;

reset(arg){

 teleport = 0;  if(random(TFL_TLP)) teleport = 1;
 door = 0;  /*       closed to start    */

 if(arg) return;
 short_desc="The Fallen Lands";
 long_desc=
"You are on a small side path of the forest, only a few feet wide.  The\n"+
"dense undergrowth is crowding the path, making it difficult to see.  From\n"+
"where you stand, a building is visible to the west.  The trees are so\n"+
"thick that almost no natural light is reaching the forest floor here.\n";
 set_light(0);
 items=({
	     "path",
"The path is rather muddy here.  The whole environment is very moist.\n"+
"The path continues to the northeast, and there is a small path which\n"+
"goes around the building to the west",
		 "forest",
"The forest is very dark around you.  The towering evergreen trees climb\n"+
"high into the sky, their branches reaching out to block the sky",
		 "undergrowth",
"The undergrowth is incredibly dense around the path here.  It is bizarre\n"+
"that the plants are able to grow so well when there is so little light",
		 "plants",
"Among the undergrowth are some very full, leafy bushes and ferns\n",
         "bushes",
"The bushes are very full and moist.  They crowd the path on all sides",
		 "ferns",
"The beautiful green ferns fan out among the undergrowth",
		 "building",
"The building is an old shack.  It is made from wooden boards, most of\n"+
"which are in terrible shape.  There are a few windows, and a door on the\n"+
"east side of the building.  A path is leading around the building",
		 "door",
"It is a simple wooden door which is in dire need of repair",
		 "trees",
"The evergreens reach so high into the sky that their tops remain unseen\n"+
"from this vantage point.  They look as if they've existed for centuries",
		 "branches",
"The branches of the trees reach out across the sky.  They create a sort\n"+
"of canopy which blocks out the light",
		 "sky",
"Only the smallest of fragments of blue sky are visible through the trees",
		 "canopy",
"The canopy of branches is incredibly thick, blocking out nearly all light",
		 "light",
"A few beam of light can be seen shining down into the forest",
		 "floor",
"The forest floor is very muddy and wet here.  It is difficult to walk",
 });
 dest_dir=({
	 "/players/zeus/realm/taus/road3.c", "northeast",
	 "/players/zeus/realm/taus/hermit2.c", "enter",
 });
}

  void init(){
	  ::init();
  add_action("ne_dir", "ne");
  add_action("enter_cmd", "enter");
  add_action("open_cmd", "open");
  add_action("close_cmd", "close");
  add_action("around_dir", "around");
  }


exit(){    if(TP) TP->clear_fight_area();     }
okay_follow(){ return 1; }
realm(){   if(teleport) return "NT";    }

status enter_cmd(string str){
  if(door == 0){ write("The door is closed!\n");
      return 1; }     else return 0;	  return 1; 
}

status open_cmd(string str){
	if(!str){     write("Open what?\n"); return 1; }
	if(str == "door"){  if(door == 0){  write("You open the door.\n");
	say(TP->QN+" opens the door.\n");    door = 1;
	return 1; }
	if(door == 1){ write("The door is already open.\n");  return 1; }
	return 1; }  else return 0;  return 1; 
}

status close_cmd(string str){
	if(!str){ write("Close what?\n"); return 1; }
	if(str == "door"){  if(door == 0){ write("The door is already closed.\n");
	return 1; }  if(door == 1){ write("You close the door.\n");
	say(TP->QN+" closes the door.\n");  door = 0;  return 1; } 
	return 1; }  else return 0;  return 1; 
}

status around_dir(){
	write("You walk around the building...\n");
	TP->MP("around#/players/zeus/realm/taus/hermit3.c");
	return 1; 
}