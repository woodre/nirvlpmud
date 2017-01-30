#include "/players/jaraxle/define.h"
inherit "/players/jaraxle/room.c";

int OPEN;
reset(arg) {
OPEN == 0;
  if(arg) return;
set_light(-1);

long_desc =
        ""+BLK+BOLD+"  This room is in the shape of a circle.  There are\n"+
        "several carvings along the wall.  A ladder leans against\n"+
        "the wall, leading up to the door overhead.  A table stands\n"+
        "in middle of the room with an old wooden box on it."+NORM+"\n";

items = ({
  "walls","Large stone walls circling the room.\nThere are very tiny holes about three\nfeet apart on the bottom of the walls",
  "carvings","Egyptian heiroglyphics chiseled into the walls",
  "table","A small stone table with a wooden box on the top",
  "ladder","A long wooden ladder you can "+HIW+"climb"+NORM+"",
  "trap door","A wooden trap door in the ceiling",
  "ceiling","The ceiling closes you into the room.\nThere is a trap door in the middle", 
  "holes","Tiny holes in the bottom of the walls",
  "box","blah",
});

}

short(){ return ""+BOLD+""+BLK+"Dark Pyramid"+NORM+""; }
realm() { return "NT"; }

init(){
    ::init();
  add_action("open","open");
  add_action("climb","climb");
}
long(arg)
{
    if(arg == "box")
    {
      string mod;

      if(OPEN == 1)
        mod = "open";
      else
        mod = "closed";

      write("A small box on top of the table.\n" +
            "The box is " + HIW + "[" + NORM + mod + HIW + "]" + NORM
            +".\n");

      return;
    }

    ::long(arg);
}


open(arg){
if(OPEN == 1){ write("The box is already open.\n"); return 1; }
if(arg == "box"){
switch(random(10)){
case 0:
write("You open the box and find an item!\n");
  MOCO("/players/jaraxle/3rd/pyramid/items/prize3.c"),TP);
OPEN += 1;
break;
case 1..9:
   write("You open the box and find an item, and some coins!\n");
MOCO("/players/jaraxle/3rd/pyramid/items/prize3.c"),TP);
write("A horde of scorpions swarm the room through the holes in the wall!\n");
say("A horde of scorpions swarm into the room through the holes in the wall!\n");
MOCO("/players/jaraxle/3rd/pyramid/mon/scorpion.c"),environment(TP));
MOCO("/players/jaraxle/3rd/pyramid/mon/scorpion.c"),environment(TP));
MOCO("/players/jaraxle/3rd/pyramid/mon/scorpion.c"),environment(TP));
MOCO("/players/jaraxle/3rd/pyramid/mon/scorpion.c"),environment(TP));
MOCO("/players/jaraxle/3rd/pyramid/mon/scorpion.c"),environment(TP));
MOCO("/players/jaraxle/3rd/pyramid/mon/scorpion.c"),environment(TP));
MOCO("/players/jaraxle/3rd/pyramid/mon/scorpion.c"),environment(TP));
MOCO("/players/jaraxle/3rd/pyramid/mon/scorpion.c"),environment(TP));
MOCO("/players/jaraxle/3rd/pyramid/mon/scorpion.c"),environment(TP));
MOCO("/players/jaraxle/3rd/pyramid/mon/scorpion.c"),environment(TP));
call_other(this_player(), "add_money", 5000); 
OPEN += 1;
break;
}
return 1; }
write("Open what?\n");
return 1; }

climb(arg){
  if(arg == "ladder"){      
  write("You climb out of the room on the ladder.\n");
  say(TPN+" uses the ladder to climb out of the room.\n");
 move_object(this_player(), "/players/jaraxle/3rd/pyramid/rooms/room2.c");
return 1; }
}
