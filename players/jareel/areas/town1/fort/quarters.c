inherit "/players/jareel/room";
#include "/players/jareel/define.h"

#define l1 "  Militant clean beds and lockers run along the buildings"
#define l2 "  walls.  Everything has its place and there is nothing"
#define l3 "  out of place.  Personal rooms lie off the main living"
#define l4 "  area.  The only exit is to the east."
#define l5 "  "

  reset(arg) {
  if(!present("general"))  {
    MOCO("/players/jareel/monsters/YELMALIAN/general.c"),this_object());
  }
    if(arg) return;
  
  set_light(3);
  short_desc=(BOLD+GRN+"Yelmalian Barracks"+NORM);
  long_desc=
    "  "+HIY+"Y"+NORM+" - Holy Temple of Yelm : "+CYN+"Q"+NORM+" - Quarters  : "+HIK+"B"+NORM+" - Blacksmith\n"+
    "  "+YEL+"Y"+NORM+" - Yelmalian Temple    : "+RED+"A"+NORM+" - Alchemist : "+BOLD+"T"+NORM+" - Trainer\n"+
    "\n"+
    BYEL+"%%%%%%%"+NORM+l1+"\n"+
    BYEL+"%"+NORM+HIK+"B"+NORM+"---"+YEL+"Y"+BYEL+"%"+NORM+l2+"\n"+
    "--+"+HIY+"Y"+NORM+"+"+RED+"A"+BYEL+"%"+NORM+l3+"\n"+
    BYEL+"%"+NORM+""+CYN+"X"+NORM+"---"+BOLD+"T"+NORM+BYEL+"%"+NORM+l4+"\n"+
    BYEL+"%%%%%%%"+NORM+l5+"\n";

  items = ({
    "road","The road is made of a grayish dirt, it has seen a lot of travel",
    "dirt","The fine grey dirt sifts between your fingers as you examine it",
    "canopy","Most of the sky is obscured here due to the large amount of trees",
    "sky","The sky is hard to see past the tree cover",
    "trees","The trees here seem to be super tall",
    "town","Several buildings and a fountain can be seen to the north",
    "buildings","You're still pretty far away to get any details",
    "path","The road is made of a grayish dirt, it has seen a lot of travel",
    "fountain","You're still pretty far away to get any details",
    "merchants","They seem to be bickering with the customers over prices",
    "goods","Items that the merchants seem to be selling", 
  });

  dest_dir = ({
    "/players/jareel/areas/town1/fort/road1","east",

  });

}
  init() {
    ::init();
  add_action("Search","search");
  }

  Search(str) {
    if(!str) { write("Search what?\n"); return 1; }
      write("You search the "+str+" but find nothing special.\n");
      say(this_player()->query_name()+" searches around for something.\n");
    return 1;
  }
