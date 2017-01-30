#include "/players/jaraxle/define.h"
inherit "/players/jaraxle/room.c";

reset(arg) {
  if(arg) return;
set_light(-1);

long_desc =
        ""+BOLD+""+BLK+"  Mounds of sand cover the southeast area of the pyramid.\n"+
        "Columns line the west side of the room.  Piles of rocks\n"+
        "sit undisturbed on the ground.  A skeleton lays crumpled\n"+
        "on the floor, leaning against one of the columns."+NORM+"\n";

items = ({
  "sand","Tan colored sand covers the pyramid floor",
  "skeleton","An incomplete skeleton of a human",
  "pyramid","A large structure made from clay stone",
  "rocks","Piles of rock which seem to come from a hole in the wall\nwhich has been untouched in ages",
  "hole","A dark, empty hole in the wall",
  "ground","The ground of the pyramid is coverd with sand",
  "columns","Thick columns of stacked clay cylinder blocks",
  "walls","Thick walls made of clay stone stacks",
});

dest_dir = ({
  "/players/jaraxle/3rd/pyramid/rooms/room.c","west",
  "/players/jaraxle/3rd/pyramid/rooms/roome2.c","north",
  "/players/jaraxle/3rd/pyramid/rooms/room2.c","northwest",
});

}

short(){ return ""+BOLD+""+BLK+"Dark Pyramid"+NORM+""; }
realm() { return "NT"; }

init(){
    ::init();
  add_action("search","search");
  add_action("push","push");
}

search(arg){
if(arg == "skeleton" || arg == "human skeleton" || arg == "incomplete skeleton"){
write("You search the skeleton and find nothing.\n");
return 1; }
if(arg == "hole" || arg == "empty hole"){
write("You search the hole and feel a square panel inside.\n");
return 1; }
write("Search what?\n");
return 1; }

push(arg){
  if(arg == "panel" || arg == "square" || arg == "square panel"){      
switch(random(12)){
case 0:
  write("You fall through a trap door!\n");
  say(TPN+" falls theough a trap door in thr floor!\n");
 move_object(this_player(), "/players/jaraxle/3rd/pyramid/rooms/square_room.c");
  say(TPN+" falls into the room through the trap door in the ceiling.\n");
break;
case 1..10:
  write("You push the panel and nothing happens.\n");
break;
case 11:
  write(HIR+"You fall through a trap door!\n"+NORM);
  say(TPN+" falls theough a trap door in thr floor!\n");
  move_object(this_player(), "/players/jaraxle/3rd/pyramid/rooms/square_room.c");
  say(TPN+" falls into the room through the trap door in the ceiling.\n");
this_player()->add_hit_point(-5-random(6));
break;
}
return 1; }                         
write("Push what?\n");  
return 1; }

