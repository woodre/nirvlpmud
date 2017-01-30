#include "/players/coldwind/define.h"

inherit "room/room";
reset(arg) {	
if(!present("villager", this_object())){
move_object(clone_object("/players/coldwind/desert/mobs/villagers.c"), this_object());
move_object(clone_object("/players/coldwind/desert/mobs/villagers.c"), this_object());
move_object(clone_object("/players/coldwind/desert/mobs/villagers.c"), this_object());
}
  if(arg) return;
set_light(1);

short_desc = ""+HIY+"Dahna desert"+NORM+"";
long_desc =
"    You stand among the arabian villagers in what looks like the \n"+
"ruins of their village.  It's very clear that the village was under a\n"+
"malicious attack lately.  Some palm trees have been knocked down \n"+
"destroying some tents under them, while many palm trees are still \n"+
"standing tall shielding the area from the burning sunrays.  The smoke\n"+
"and the smell of the burned tents make your eyes water down in tears.\n"+
"The fallen trees block you from proceeding southwest.\n";

items = ({
  "villagers",
  "They are wounded and wearing dirty torn clothes. The villagers\n"+
  "eye you with a strange mix of fear and hope",
  "houses",
  "Burned and destroyed tents extend south and southwest",
  "tents",
  "Burned and destroyed tents extend south and southwest",
  "ruins",
  "You are looking at the remains of what was once a village...",
  "sun",
  "The palm trees and the smoke are blocking the sunlight!",
  "sunrays",
  "The palm trees and the smoke are blocking the sunlight...",
  "palm trees",
  "They stand around 30 feet tall, while others have fallen over some\n"+
  "of the tents destroying them",
  "fallen trees",
  "A few palm trees have fallen over some tents destroying them and\n"+
  "blocking you from walking east and southwest",
  "smoke",
  "Dark smokes rises from the burned tents preventing you from having \n"+
  "a better look at the sarrounding",
  
});

dest_dir = ({
  "/players/coldwind/desert/rooms/v3.c","south",
  "/players/coldwind/desert/rooms/v5.c","west",
});

}

	