#include <ansi.h>
#define tp this_player()->query_name()
#define ROOT "/players/daranath/wastes/"
inherit "room/room";

reset(int arg){
  if(!arg){
    
set_light(1);
short_desc= (BLK+BOLD+"Gundar Wastes"+NORM);
long_desc=
"A small clearing just to the north of the Gundar Plateau base, this area looks\n"+
"like it was scoured by magic years ago. Blackened tree stumps stick from the \n"+
"earth, while scorched rocks are plentiful.\n"+
"The remains of a ruined tower lies here, having fallen upon its side.\n";

items=({
"clearing","This clearing was probably made by a magical battle, given the destruction\n"+
     "that is all around you",
"stumps","Blackened stumps of trees that were blown away during the magical battle are everywhere",
"plateau","The plateau rises up, looming overhead. A small trail starts up to the south",
"rocks","The rock in the area is sorched by magical flames",
"tower","The tower has fallen upon its side, another casualty of the magical\n"+
     "warfare that rocked Gundar years ago. You believe you can enter\n"+
     "the tower's remains",
    });

    dest_dir=({
  ROOT+"plateau_base.c","south",
  ROOT+"pyro_tower1.c","enter",
    });

    }
  }

init(){
  ::init();
add_action("search","search");
}

search(){
write("The dirt and earth in the area is blackened and heavily sorched.\n");
  say(tp +" searches the area.\n");
 return 1;
}

realm() {return "NT"; }
