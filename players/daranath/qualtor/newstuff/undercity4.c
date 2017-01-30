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
"A newly constructed tunnel runs here from the old sewer system to the\n"+
"east. A large stone archway leads southwards, its dark stone laced\n"+
"with bits of bleached bone. The tunnel itself continues eastwards.\n";

    items=({
"tunnel","This tunnel has been carved from the stone here recently, allowing access\n"+
     "to the Bone Marketplace",
"stone","The dark grey stone prevalent in the city is here as well",
"system","The sewer system runs west of the bone marketplace",
"market","The bone market is south of here",
"archway","The stone archway is dark grey in color, as is most of the stone around the city.\n"+
     "Its ornate carving represents how much care has been given to its construction",
"bone","Careful examination leads you to believe the archway is laced with human bone",
"carving","The construction of the archway is laced with bits of bone, strengthening the\n"+
     "stone and giving a menacing feel to the area",
    });

    dest_dir=({
ROOT+"bone_market.c","south",
ROOT+"undercity5.c","east",
ROOT+"undercity1.c","west",
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

