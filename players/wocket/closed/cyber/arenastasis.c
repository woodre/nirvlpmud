#include "/players/wocket/closed/ansi.h"
inherit "/players/wocket/std/tvroom.c";

reset(arg){
  if(arg) return 1;
short_desc = HIY+"CyberNinja Stasis"+NORM;
long_desc = "   "+
"Water surrounds you, as you are in a glass stasis unit.  Tubes and wires\n"+
"are connected to your body all around you leading off in all different\n"+
"directions.  Many monitors and fancy computers surround you beeping\n"+
"and flashing your every movement.  If you are feeling better you may\n"+
"leave at any time.\n";
items = ({
"water","It is blue and wet",
"unit","A large glass tube that holds and heals a patient",
"tubes","Long tubes that carry healing nutriants to the patient",
"wires","All sorts of different colors.  They monitor the patient",
"monitors","Computer screes that flash different numbers and diagrams",
"computers","They look very high tech and expensive",
});
listens = ({
"default","You hear the buzz of the machines and bubbles of your breathing",
});
smells = ({
"default","You smell cleanliness",
});

dest_dir = ({
"/players/wocket/closed/cyber/a_entrance.c","leave",
});
set_light(1);
}

init(){
  if(this_player()->query_ghost()){
      this_player()->remove_ghost();
  write(HIR+"*~*  You are brought back to life and given your equipment.\n"+NORM);
  }
::init();
}
