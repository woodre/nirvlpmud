inherit "room/room";
#include "/players/zeus/closed/all.h"

int teleport;

reset(arg){
 if(!arg){

 teleport = 0;  if(random(2)) teleport = 1;

  set_light(0);
  long_desc=
"This part of the forest has very thick undergrowth.  There is no defined\n"+
"path at all here, you are completely surrounded by plants.  The trees\n"+
"are creating a very thick canopy, which is blocking out almost all light.\n";
  items=({
   "forest",
"The forest is extremely thick here, making it impossible to see in which\n"+
"directions travel is possible.  The undergrowth is crowding in all around\n"+
"you, and the trees are blocking out nearly all of the light",
   "undergrowth",
"The undergrowth here is made of many different plants, including huge\n"+
"leafy ferns and flowery bushes.  They are growing extremely close together,\n"+
"making it practically impossible to see the forest floor",
   "ferns",
"There are some very large, green ferns growing here, blocking your line of\n"+
"sight in nearly every direction",
   "bushes",
"Some of the bushes growing here are over six feet tall, making travel\n"+
"extremely difficult.  A few of them have pretty blossoms on them",
   "floor",
"The forest floor is all but invisible because of the undergrowth",
   "ground",
"The ground, which is somewhat grassy here, is very hard to see because of\n"+
"the amount of plants which are growing here",
   "grass",
"A few small, delicate blades of green grass can be seen beneath the plants",
   "trees",
"The towering evergreen trees are creating a very thick canopy here, which\n"+
"is blocking out nearly all the avalible light.  It's strange that the\n"+
"plants are growing so well here",
   "plants",
"There are many different types of plants here, and they are growing so\n"+
"thickly that they are making travel next to impossible",
   "canopy",
"The canopy created by the branches of the trees is blocking out nearly\n"+
"all of the light.  Only tiny fragments of the blue sky can be seen",
   "sky",
"It is next to impossible to see the sky from here, there are just way\n"+
"too many branches on the evergreen trees",
  });
}  }

short(){ return "The Fallen Lands"; }

  init(){
    ::init();
  add_action("n_dir", "north");
  add_action("ne_dir", "northeast");
  add_action("e_dir", "east");
  add_action("se_dir", "southeast");
  add_action("s_dir", "south");
  add_action("sw_dir", "southwest");
  add_action("w_dir", "west");
  add_action("nw_dir", "northwest");
}

exit(){    if(TP) TP->clear_fight_area();     }
okay_follow(){ return 1; }
realm(){   if(teleport) return "NT"; }

status n_dir(){
	write("You walk north through the undergrowth...\n");
	TP->MP("north#/players/zeus/realm/city/path24.c");
return 1; }

status ne_dir(){
	write("You walk northeast through the undergrowth...\n");
	TP->MP("northeast#/players/zeus/realm/city/path25.c");
return 1; }

status e_dir(){
	write("You walk east through the undergrowth...\n");
	TP->MP("east#/players/zeus/realm/city/path24.c");
return 1; }

status se_dir(){
	write("You walk southeast through the undergrowth...\n");
	TP->MP("southeast#/players/zeus/realm/city/path24.c");
return 1; }

status s_dir(){
	write("You walk south through the undergrowth...\n");
	TP->MP("south#/players/zeus/realm/city/path24.c");
return 1; }

status sw_dir(){
	write("You walk southwest through the undergrowth...\n");
	TP->MP("southwest#/players/zeus/realm/city/path19.c");
return 1; }

status w_dir(){
	write("You walk west through the undergrowth...\n");
	TP->MP("west#/players/zeus/realm/city/path24.c");
return 1; }

status nw_dir(){
	write("You walk northwest through the undergrowth...\n");
	TP->MP("northwest#/players/zeus/realm/city/path24.c");
return 1; }
