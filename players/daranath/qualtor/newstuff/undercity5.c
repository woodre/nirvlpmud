#define tp this_player()->query_name()
#define ROOT "/players/daranath/qualtor/newstuff/"
#include <ansi.h>

inherit "room/room";

reset(int arg){
  if(!arg){
    
    set_light(1);
short_desc= (BLK+BOLD+"City of Qual'tor "+NORM+"("+BOLD+"UnderCity"+NORM+")");
    long_desc=
"               "+BOLD+"Under the City of Qual'tor"+NORM+"\n"+
"Abruptly ending at a wall made of the same dark grey stone as the rest\n"+
"of Qual'tors UnderCity, the tunnel comes to an abrupt end here. A solid\n"+
"wooden door sits in the southern wall, a carved bone plaque mounted\n"+
"directly at eye level.\n";

    items=({
"wall","The wall is made of the same grey stone that gives Qual'tor is signature style",
"stone","The dark grey stone found everywhere within the cities limits is also prevalent here",
"city","You are under the city of Qual'tor",
"undercity","The old sewer system was nickname the 'UnderCity' long ago",
"system","The main tunnels of the sewer system are far to the west",
"door","A steel reinforced wooden door sits in the southern wall, a carved bone\n"+
     "plaque mounted in the door itself",
"plaque","The bone plaque reads: "+HIW+"Bone Market Shop"+NORM+" ",
"bone","The bone of the plaque is human in origin",
    });

    dest_dir=({
ROOT+"bone_shop.c","south",
ROOT+"undercity4.c","west",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    }

search() {
write("Bits of bone are mixed in with the thick dust about the flooring here.\n");
  say(tp +" searches the area.\n");
return 1;
}

