#include <ansi.h>
#define tp this_player()->query_name()
#define ROOT "/players/daranath/wastes/"
inherit "room/room";

reset(int arg){
  if(!arg){
    
set_light(1);
short_desc= (BLK+BOLD+"Gundar "+BLU+"Vapor Springs"+NORM);
long_desc=
"The ancient roadway ends here, having never been built any further by the \n"+
"people who used to live in Gundar. A number of small ponds and lakes have \n"+
"formed here, small pathways of rock and stone winding around them. Superheated\n"+
"by all the volcanic activity in the area, they have become a series of hot\n"+
"springs and vapor pools.\n";

items=({
"roadway","The roadway ends here, at the Gundar vapor pools",
"springs","The springs have been heated by the lava that flowed through the area",
"pools","The pools are superheated, becoming the famous Gundar vapor pools",
"rock","Small pathways of rock and stone allow for further passage through the area",
"stone","Small pathways of rock and stone allow for further passage through the area",
    });

    dest_dir=({
  ROOT+"west_road3.c","east",
  ROOT+"vapor2.c","west",
    });

    }
  }

init(){
  ::init();
add_action("search","search");
}

search(){
write("The Gundar vapor pools are teeming with small bugs and lizards.\n");
  say(tp +" searches the area.\n");
 return 1;
}

realm() {return "NT"; }
