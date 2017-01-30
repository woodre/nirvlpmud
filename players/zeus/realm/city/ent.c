inherit "room/room";
#include "/players/zeus/closed/all.h"
#include "/players/zeus/closed/fl_demon.h"

int teleport;

reset(arg){
 if(!arg){

 teleport = 0;  if(random(TFL_TLP)) teleport = 1;
 if(!present("monk")) MO(CO("/players/zeus/realm/NPC/tyborlek.c"), TO);

  set_light(1);
  short_desc="The Fallen Lands";
  long_desc=
"This is a circular shaped clearing in the forest.  The ground has\n"+
"been burnt so badly that it is black.  The forest is very thick all\n"+
"around, however there is a somewhat well used path leading off to\n"+
"the east.  The blue sky can be seen through the trees above. In the\n"+
"center of the clearing is a black portal.\n";
  items=({
  "portal",
"This black portal is floating in the center of the clearing.  It is\n"+
"spiraling backwards into itself.  To get back to the black room,\n"+
"you just need to walk into the portal and it will take you there",
  "ground",
"The ground looks as though a large fireball hit it, burning"+
" all the\nleaves and plants away from the spot.  It is about"+
" 20 feet across",
  "clearing",
"The ground looks as though a large fireball hit it, burning,"+
" all the\nleaves and plants away from the spot.  It is about"+
" 20 feet across",
"sky", "A patch of light blue sky can be seen directly above",
"trees", "The tall, thick trees climb high into the sky",
"forest", 
"The ancient forest is full of large trees and thick undergrowth",
  "path", 
"The dirt path leads off to the east from here.  It is crowded on\n"+
"the north and south by the undergrowth of the forest",
"undergrowth",
"The undergrowth consists of a variety of different types of plants,\n"+
"making travel off of the path extremely difficult.  Some of the plants\n"+
"are very bright and colorful, lighting up the forest floor",
  });
  dest_dir=({
"/players/zeus/realm/main", "portal",
/*
"/players/maledicta/cont/rooms/166", "continent",
*/
"/players/zeus/realm/city/path10", "east",  });
}   }

  init(){
  ::init();
  add_action("e_dir", "east");
  add_action("leave_cmd", "portal");
  add_action("walk_cmd", "walk");
}

exit(){    if(TP) TP->clear_fight_area();     }
realm(){   if(teleport) return "NT"; }

status leave_cmd(){
  if("/players/zeus/closed/fl_demon.c"->check_demon(TP)) return 1;
    write("You walk into the black portal....\n");
}

status walk_cmd(string str){
 if(!str) return 0;
  if(str == "into portal"){
  if("/players/zeus/closed/fl_demon.c"->check_demon()) return 1;
    write("You walk into the black portal....\n");
  TP->MP("into the black portal#/players/zeus/realm/main.c");
 return 1; }
}
