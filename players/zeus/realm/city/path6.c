inherit "room/room";
#include "/players/zeus/closed/all.h"
#include "/players/zeus/closed/fl_demon.h"

int brgold, teleport;

reset(arg){
 if(!arg){

  brgold = 1;
  teleport = 0;  if(random(2)) teleport = 1;

  set_light(1);
  short_desc="The Fallen Lands";
  long_desc=
"The path begins to open up here, allowing much light to touch\n"+
"the ground.  To the west is a large pillar sticking straight into\n"+
"the air.  Under the plants to the northeast of the path there is a\n"+
"small burrow.  A few rocks are laying scattered about the forest.\n";
  items=({
   "trees", 
"The tall, ancient trees tower high into the sky.  They appear to\n"+
"have been here for centuries",
   "canopy", 
"The canopy is very open here, allowing much light through",
   "path", 
"The path is dry here, making travel easy.  It is covered by some\n"+
"leaves, branches and rocks",
   "leaves",
"There are some brown and green leaves covering parts of the path",
   "branches",
"There are a few broken branches littered across the path",
   "undergrowth", 
"There are some very large bushes growing to the east of the path,\n"+
"blocking nearly everything in that direction, with the exception of\n"+
"the pillar",
   "plants", 
"The plants are very healthy here because of the light.  To the\n"+
"northeast some colorful plants are blossoming",
   "pillar", 
"The pillar is standing about 10 feet in the air.  It looks like it once\n"+
"was a main support for a building.  It has a faded pattern painted all\n"+
"along it.  There also appears to be a carving in it",
   "carving",
"Some writing has been carved into the pillar",
   "rocks", 
"There are pieces of rock scattered about the ground here",
   "burrow", 
"This is a tiny little burrow which has been built under some of the\n"+
"plants here.  It looks like it was abandoned a long time ago",
   "ground", 
"The ground is dry here, and mostly flat.  There are leaves, branches\n"+
"and rocks scattered across it",
  });
  dest_dir=({
"/players/zeus/realm/city/path11.c", "north",
"/players/zeus/realm/city/path7.c", "east",
"/players/zeus/realm/city/path2.c", "south",
  });
}  }

int brgold() {   return brgold(); }

  init(){
  ::init();
  add_action("search_cmd", "search");
  add_action("n_dir", "north");
  add_action("s_dir", "south");
  add_action("e_dir", "east");
  add_action("enter_cmd", "enter");
  add_action("read_cmd", "read");
}

realm(){   if(teleport) return "NT"; }
okay_follow(){ return 1; }

status search_cmd(string str){
object gold;
 if(!str) return 0;
  if(str=="burrow"){ 
   if(brgold != 1){ write("You search the burrow and find nothing.\n");
   return 1; }
  write("You search the burrow and uncover some money!\n");
  say(TP->QN+" searches around.\n");
  gold = CO("obj/money");
  gold->set_money(10+random(11));
  MO(gold,TO);
  brgold = 0;
return 1; } }

status enter_cmd(string str){
 if(!str) return 0;
 if(str=="burrow"){
  write("You can't fit into the burrow!\n");
  say(TP->QN+" tries to fit into the burrow, but only succeeds in\n"+
          "making "+TP->OBJ+"self look extremely dumb.\n");
 }
return 1; }

status read_cmd(string str){
 if(!str) return 0;
 if(str=="carving" || str=="writing" || str == "pillar"){
  write("The carving reads:\n\n"+
	  "\t\t\tHumanity shall prevail!\n");
  say(TP->QN+" reads the carving.\n");
 }
 else return 0;
return 1; }
