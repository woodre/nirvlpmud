inherit "room/room";  /* path1.c  */
#include "/players/zeus/closed/fl_demon.h"
int teleport;

reset(arg){
 if(!arg){

  teleport = 0;  if(random(TFL_TLP)) teleport = 1;
  short_desc="The Fallen Lands";
  long_desc=
"The forest is moderatly dark here, and only seems to get darker to\n"+
"the west.  The mighty evergreen trees tower high above your head,\n"+
"blocking out a good portion of the light.  The undergrowth grows\n"+
"quite thick here, making travel off the defined path impossible.\n";
  set_light(1);
  items=({
   "trees",
"The evergreen trees reach high into the sky around the clearing.  Their\n"+
"branches are reaching out to each other, creating a canopy",
   "canopy",
"The branches of the evergreen trees are blocking out a lot of the\n"+
"sky from view, only some light is able to get through",
   "sky",
"The beautiful blue sky can barely be seen through the trees above",
   "branches",
"The branches of the evergreen trees are touching one another, doing\n"+
"their best to block out the light from the forest floor",
   "dirt",
"The dirt is very dry here.  There are a number of pieces of stone here,\n"+
"which are almost entirely covered in dirt",
   "leaves", 
"There are some dead brown leaves scattered across the clearing",
   "path",
"The path is open here, consisting of dry dirt, a couple large pieces\n"+
"of flat stone, and some dead brown leaves",
   "stone",
"The flat pieces of stone are white and very dirty.  Long ago they\n"+
"were part of a building, but now just decorate the path like garbage",
   "pieces", 
"There are a number of flat pieces of white stone scattered around the\n"+
"ground here.  They are covered in dirt and leaves",
   "forest", 
"The forest isn't extremely thick here.  There are some beautiful\n"+
"plants growing amongst the undergrowth",
   "plants",
"Some of the plants visible among the undergrowth are displaying a\n"+
"rather stunning amount of color",
   "undergrowth",
"The undergrowth is very thick around the path.  It would be impossible\n"+
"to deviate from the path at this point",
  });
  dest_dir=({
"/players/zeus/realm/taus/guth6.c", "east",
"/players/zeus/realm/x/path2.c", "west",
  });
 }
}

void init(){
  ::init();
  add_action("e_dir", "east");
  add_action("w_dir", "west");
}

exit(){    if(this_player()) 
			this_player()->clear_fight_area();     }
realm() { if(teleport) return "NT"; }
