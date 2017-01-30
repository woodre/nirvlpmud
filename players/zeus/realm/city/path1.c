inherit "room/room";
#include "/players/zeus/closed/all.h"
#include "/players/zeus/closed/fl_demon.h"

int snake, teleport;

reset(arg){
 if(!arg){

 teleport = 0;  if(random(TFL_TLP)) teleport = 1;
 if(!present("snake")){
  for(snake = 0; snake < 3;  snake++) {
  MO(CO("/players/zeus/realm/NPC/snake1.c"), TO);
}  }

  set_light(1);
  short_desc="The Fallen Lands";
  long_desc=
"The forest is very thick and dark at this point, making it hard to\n"+
"see the fallen remains of the city.  The dark path continues\n"+
"deeper into the forest to the southwest, however it is blocked by\n"+
"two fallen trees.  A broken sign is laying amongst the plants to the south,\n"+
"half covered in growth.  Footprints of creatures can be seen pressed\n"+
"into the ground.\n";
  items=({
   "footprints", 
"There are multiple sets of footprints in the ground, some very old\n"+
"and faded while others are fresh.  Who or what made them is not\n"+
"discernable",
   "sign", 
"The sign has been broken in half and is laying in the dirt.  It is\n"+
"faded from the weather but still readable",
   "trees", 
"Two massive trees are blocking the path to the southwest.  There is\n"+
"no way at all to pass them at this point",
   "forest", 
"The forest is extremely thick here.  The canopy overhead is blocking\n"+
"out almost all light",
   "path", 
"The rocky path is easy to see because of the lack of undergrowth\n"+
"here.  There are numerous sets of footprints in the dirt",
   "growth",
"The sign is partially covered in moss and dirt",
   "ground",
"The ground is easy to see because of the lack of undergrowth here.\n"+
"There are numerous sets of footprints in the dirt",
   "plants",
"Some green and yellow bushes are growing here",
   "bushes",
"A number of large bushes with faded green and yellow leaves are growing\n"+
"around the path here",
  });
  dest_dir=({
"/players/zeus/realm/city/path2.c", "east",
/* "/players/zeus/realm/forest/sent.c", "southwest", */
  });
} }

int toggle() {   return toggle(); }

  init(){
  ::init();
  add_action("e_dir", "east");
  add_action("sw_dir2", "southwest");
  add_action("read_cmd", "read");
}

exit(){    if(TP) TP->clear_fight_area();     }
okay_follow(){ return 1; }
realm() { if(teleport) return "NT"; }

status read_cmd(string str){
  string tmp1, tmp2;
   if(!str) { write("What?\n");  return 1; }
   if(sscanf(str, "%ssign%s", tmp1, tmp2)) {
   write("Beware the Forest and what lies within.\n");
   say(TP->QN+" reads the sign.\n");
  return 1; }
return 0; }

sw_dir2(){
 if(present("snake")){
  write("As you try to move, one of the snakes bites you!\n");
  say("A snake bites "+TP->QN+"!\n");
  TP->hit_player(10+random(15));
 return 1; }
 else
 write("Two gigantic trees have fallen across the path making it"+
            " impossible\nto pass at this point.\n");
say(TP->QN+" tries to go southwest.\n");
return 1; }
