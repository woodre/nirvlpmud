inherit "room/room";
#include "/players/zeus/closed/all.h"

int d_east, teleport;

reset(arg){

  d_east = 0;                  /*  hasn't been called   */

 if(!arg){

 teleport = 0;  if(random(2)) teleport = 1;

  set_light(0);
  long_desc=
"The forest here is extremely thick.  The evergreen trees are creating\n"+
"such a thick canopy that almost no light is able to penetrate through.\n"+
"The undergrowth is so dense that it is impossible to determine which\n"+
"way the path leads.  To the east pieces of a structure are visible.\n";
  items=({
   "forest",
"The forest of evergreen trees is very thick here, making the area quite\n"+
"dark.  It is strange that the plants are surviving so well here",
   "trees",
"The evergreen trees are growing very close to each other here.  Their\n"+
"branches are criss crossing, making a thick canopy which is blocking\n"+
"out almost all of the blue sky",
   "sky",
"The blue sky is almost entirely invisible through the trees",
   "canopy",
"The canopy created by the branches of the evergreen tress is so thick\n"+
"that only miniscule little pieces of the sky can be seen",
   "undergrowth",
"The undergrowth is so thick here that it is impossible to determine\n"+
"which way the path leads.  There are some vines growing around the\n"+
"trees, and dangling down from the branches",
   "vines",
"The green vines appear are wrapped around many of the evergreen trees,\n"+
"and are dangling down from the branches",
   "branches",
"The branches of the towering evergreen trees are creating a thick canopy\n"+
"which is preventing almost all light from reaching the forest floor",
   "ground",
"The ground is all but invisible beneath the thick layer of plants",
   "plants",
"The plants grow well here despite the aparent lack of light.  Almost all\n"+
"of them are dark shades of green, especially the vines",
   "path",
"The path is hidden beneath the plants here",
   "structure",
"Through the trees to the east pieces of a large structure can be seen.\n"+
"It looks as though it may even still be standing",
  });
}  }

short(){ return "The Fallen Lands"; }
int d_east(){  return d_east();  }

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
	 if(present("demon"))
 {
	 write("A demon blocks your way!\n");
	 say("A demon blocks "+TP->QN+"'s way!\n");
	 return 1;
 }
	write("You walk north through the undergrowth...\n");
	TP->MP("north#/players/zeus/realm/city/path25.c");
return 1; }

status ne_dir(){
	 if(present("demon"))
 {
	 write("A demon blocks your way!\n");
	 say("A demon blocks "+TP->QN+"'s way!\n");
	 return 1;
 }
	write("You walk northeast through the undergrowth...\n");
	TP->MP("northeast#/players/zeus/realm/city/path25.c");
return 1; }

status se_dir(){
	 if(present("demon"))
 {
	 write("A demon blocks your way!\n");
	 say("A demon blocks "+TP->QN+"'s way!\n");
	 return 1;
 }
	write("You walk southeast through the undergrowth...\n");
	TP->MP("southeast#/players/zeus/realm/city/path25.c");
return 1; }

status s_dir(){
	 if(present("demon"))
 {
	 write("A demon blocks your way!\n");
	 say("A demon blocks "+TP->QN+"'s way!\n");
	 return 1;
 }
	write("You walk south through the undergrowth...\n");
	TP->MP("south#/players/zeus/realm/city/path25.c");
return 1; }

status sw_dir(){
	 if(present("demon"))
 {
	 write("A demon blocks your way!\n");
	 say("A demon blocks "+TP->QN+"'s way!\n");
	 return 1;
 }
	write("You walk southwest through the undergrowth...\n");
        TP->MP("southwest#/players/zeus/realm/city/path24.c");
return 1; }

status w_dir(){
	 if(present("demon"))
 {
	 write("A demon blocks your way!\n");
	 say("A demon blocks "+TP->QN+"'s way!\n");
	 return 1;
 }
	write("You walk west through the undergrowth...\n");
        TP->MP("west#/players/zeus/realm/city/path25.c");
return 1; }

status nw_dir(){
 if(present("demon"))
 {
	 write("A demon blocks your way!\n");
	 say("A demon blocks "+TP->QN+"'s way!\n");
	 return 1;
 }	
	write("You walk northwest through the undergrowth...\n");
	TP->MP("northwest#/players/zeus/realm/city/path25.c");
return 1; }


status e_dir(){
object bring_demon;
int demon, random_num;
 if(present("demon"))
 {
	 write("A demon blocks your way!\n");
	 say("A demon blocks "+TP->QN+"'s way!\n");
	 return 1;
 }
 if(d_east == 0)
 {
	 random_num = random(4);
	 if(random_num == 0)
	 {
	 	write("You walk east through the undergrowth...\n");
		TP->MP("east#/players/zeus/realm/city/shrine.c");
		d_east = 1;
		return 1; 
	 }
	 if(random_num == 1)
	 {
		say("A demon suddenly appears from the forest...\n");
		write("A demon suddenly appears from the forest...\n");
        bring_demon = CO("/players/zeus/realm/NPC/demon1.c");
		MO(bring_demon, TO);
		bring_demon -> attack_object(TP);
		d_east = 1;
		return 1;
	 }
	 if(random_num == 2)
	 {
		say("Two demons suddenly appear from the forest...\n");
		write("Two demons suddenly appear from the forest...\n");
		for(demon = 0; demon < 2; demon++)
		{
			bring_demon = CO("/players/zeus/realm/NPC/demon1.c");
			MO(bring_demon, TO);
			bring_demon -> attack_object(TP);
		}
	 d_east = 1;
	 return 1;
	 }
	 if(random_num == 3)
	 {
		say("Three demons suddenly appear from the forest...\n");
		write("Three demons suddenly appear from the forest...\n");
		for(demon = 0; demon < 3; demon++)
		{
			bring_demon = CO("/players/zeus/realm/NPC/demon1.c");
			MO(bring_demon, TO);
			bring_demon -> attack_object(TP);
		}
	 d_east = 1;
	 return 1;
	 }
 return 1;
 }
 else {
	write("You walk east through the undergrowth...\n");
	TP->MP("east#/players/zeus/realm/city/shrine.c");
 return 1; 
 }
 return 1;
}
