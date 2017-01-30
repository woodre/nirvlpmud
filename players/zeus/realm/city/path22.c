inherit "room/room";
#include "/players/zeus/closed/all.h"
#include "/players/zeus/closed/fl_demon.h"

int teleport;

reset(arg){
 if(!arg){

 teleport = 0;  if(random(2)) teleport = 1;
  if(!present("gorilla")) MO(CO("/players/zeus/realm/NPC/gorilla1.c"), TO);

  set_light(1);
  short_desc="The Fallen Lands";
  long_desc=
"The path is somewhat narrow here, only about a few feet wide.  The\n"+
"undergrowth is thick and very wet.  Barely visible about ten feet\n"+
"north of the path is a large structure.  The path is extremely muddy\n"+
"here.  A number of small twigs are scatted across the path.\n";
  items=({
   "trees",
"The mighty evergreen trees loom high above your head, their branches\n"+
"reaching out across the forest",
   "branches",
"The branches of the mighty evergreen trees criss cross, making a fairly\n"+
"dense canopy which blocks out much of the blue sky",
   "canopy",
"The canopy of trees is thick and patchy.  Small pieces of blue sky pierce\n"+
"through, allowing beams of light to touch the forest floor",
    "twigs",
"There are quite a few small brown twigs laying across the path, most of\n"+
"which have been broken into small pieces",
   "path", 
"The path is muddy and crowded by the undergrowth.  There are many small\n"+
"twigs littered across it",
   "undergrowth",
"There are many thick green bushes growing all around the path here, their\n"+
"leaves hold water like buckets which in turn make you soaking wet",
   "shrine",
"There is a lot of forest in between you and the shrine, but there is no\n"+
"question that it is a shrine.  The domed roof is held up by four large\n"+
"pillars, all of which is made from a dirty white stone.  There is no way\n"+
"to reach the shrine from here",
   "structure", 
"It is very hard to see through the undergrowth, but the structure is\n"+
"clearly a shrine, and it looks to still be entirely intact",
   "river", 
"You can't see the river from here because of the forest",
    "sky",
"Only tiny pieces of blue sky are visible through the canopy of branches\n"+
"which hovers above you like a blanket",
  });
  dest_dir=({
"/players/zeus/realm/city/path23.c", "east",
"/players/zeus/realm/city/path20.c", "south",
  });
}    }

  init(){
  ::init();
  add_action("s_dir", "south");
  add_action("e_dir", "east");
  add_action("listen_cmd", "listen");
}

exit(){    if(TP) TP->clear_fight_area();     }
okay_follow(){ return 1; }
realm() { if(teleport) return "NT"; }


status listen_cmd()
{
	write("You listen carefully...    water can be heard to the east.\n");
	say(TP->QN+" listens carefully.\n");
	return 1;
}
