/*                                                                   
 *    File:              /players/jareel/areas/town1/fort/alcamist.c                                   
 *    Author(s):         Jareel                            
 *    Change History:    corrected many grammar errors    
 *                       Angel 07-18-09                                          
 */

inherit "/players/jareel/room";
#include "/players/jareel/define.h"

#define l1 "  You have entered an Alchemist's workroom.  Lining stone"
#define l2 "  walls are several shelves and strata, each covered with"
#define l3 "  multi-colored potions and mystical vines.  Near the rear"
#define l4 "  of the store a steel box and a wood sign sit on the counter."
#define l5 "  The door to the west leads back to the road outside."

  reset(arg) {
  if(!present("alcamist"))  {
    MOCO("/players/jareel/monsters/YELMALIAN/alcamist.c"),this_object());
  }
  if(!present("sign"))  {
    MOCO("/players/jareel/general_stuff/alc_shop_sign.c"),this_object());
  }
    if(arg) return;
  
  set_light(3);
  short_desc=(YEL+"Yelmalian Alchemist Shop"+NORM);
  long_desc=
    "  "+HIY+"Y"+NORM+" - Holy Temple of Yelm : "+CYN+"Q"+NORM+" - Quarters  : "+HIK+"B"+NORM+" - Blacksmith\n"+
    "  "+YEL+"Y"+NORM+" - Yelmalian Temple    : "+RED+"A"+NORM+" - Alchemist : "+BOLD+"T"+NORM+" - Trainer\n"+
    "\n"+
    BYEL+"%%%%%%%"+NORM+l1+"\n"+
    BYEL+"%"+NORM+HIK+"B"+NORM+"---"+YEL+"Y"+BYEL+"%"+NORM+l2+"\n"+
    "--+"+HIY+"Y"+NORM+"+"+RED+"X"+BYEL+"%"+NORM+l3+"\n"+
    BYEL+"%"+NORM+""+CYN+"Q"+NORM+"---"+BOLD+"T"+NORM+BYEL+"%"+NORM+l4+"\n"+
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
    "/players/jareel/areas/town1/fort/road7","west",
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