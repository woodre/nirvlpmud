#include "/players/jaraxle/define.h"
inherit "/players/jaraxle/room.c";

reset(arg) {
  if(arg) return;
set_light(-1);

long_desc =
  ""+BLK+BOLD+"  The archway comes to an abrupt end here.  A large\n"+ 
  "stone door stands defiantly at the end of the tunnel.\n"+
  "A large statue of a gargoyle sits on top of a shelf\n"+
  "over the door."+NORM+"\n";
items = ({
  "door","A huge stone door, there seems to be a message on the door",
  "message","Beyond, is evil.\nIf you are ready, you may "+HIW+"pass through"+NORM+" the "+HIW+"door"+NORM+"",
  "gargoyle","A large sized gargoyle overlooking the door",
  "shelf","A stone shelf, holding a stone gargoyle",
  "archway","A curved overhang making a short walkway",
  "statue","A large stone gargoyle, sitting protectivly above the archway",
});

dest_dir = ({
  "/players/jaraxle/3rd/pyramid/rooms/archway2.c","east",
});

MOCO("/players/jaraxle/3rd/pyramid/mon/revenant.c"),TO);
}
short(){ return ""+BOLD+""+BLK+"Dark Pyramid"+NORM+""; }
realm() { return "NT"; }

init(){
    ::init();
  add_action("pass","pass");
}

pass(arg){
if(arg == "door" || arg == "through door"){

if(TP->query_level() < 16){
  write("The door does not budge!\n");
return 1; }
write("You warrily push through the stone door.\n");                       
say(TPN+" enters into evil.\n");
move_object(this_player(), "/players/jaraxle/3rd/pyramid/rooms/mumra.c");  
command("look",TP);
say(TPN+" arrives.\n");
return 1; }
write("Pass through what?\n");
return 1; }

