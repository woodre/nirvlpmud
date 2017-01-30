#include "/players/jaraxle/define.h"
inherit "/players/jaraxle/room.c";

int SEARCH;
reset(arg) {
   SEARCH = 0;
   if(arg) return;
   set_light(-1);
   
   long_desc =
   ""+BLK+""+BOLD+"  The room is very empty with no exits other than a ladder\n"+
   "leading up through the trap door.  The walls have been built\n"+
   "into a perfect square."+NORM+"\n";
   
   items = ({
         "walls","Large stone walls.\nYou notice a thin crevice splitting down one of the walls",
         "crevice","A small splinter of a slit down a stone wall",
         "room","A dark, empty room in the pyramid",
         "ladder","A long wooden ladder you can "+HIW+"climb"+NORM+"",
         "trap door","A wooden trap door in the ceiling",
         "door","A wooden trap door in the ceiling",
         "ceiling","The ceiling closes you into the room.\nThere is a trap door in the middle",
});
   MOCO("/players/jaraxle/3rd/pyramid/mon/defender.c"),TO);
}

short(){ return ""+BOLD+""+BLK+"Dark Pyramid"+NORM+""; }
realm() { return "NT"; }

init(){
    ::init();
  add_action("find_it","search");
  add_action("climb","climb");
}

find_it(arg){
if(SEARCH >= 1){
write("You search the crevice and find nothing.\n");
return 1; }
if(arg == "crevice"){
switch(random(10)){
case 0..4:
write("You search the crevice and find an item!\n");
  MOCO("/players/jaraxle/3rd/pyramid/items/prize1.c"),TP);
MOCO("/players/jaraxle/3rd/pyramid/items/prize3.c"),TP);
SEARCH +=1;
break;
case 5..9:
write(GRN+"You stick your hand in the crevice and feel a prick in your skin!\n"+NORM);
TP->add_hit_point(-1-random(4));
SEARCH +=1;
break;
}
return 1; }
write("Search what?\n");
return 1; }

climb(arg){
  if(arg == "ladder"){      
  write("You climb out of the room on the ladder.\n");
  say(TPN+" uses the ladder to climb out of the room.\n");
 move_object(this_player(), "/players/jaraxle/3rd/pyramid/rooms/roome.c");
  say(TPN+" arrives.\n");
return 1; }                         
write("Climb what?\n");  
return 1; }

