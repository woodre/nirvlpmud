#include "DEFS.h"
inherit "room/room";

reset(arg) {

if(!present("seamstress")) {
  move_object(clone_object("players/eurale/Dis/Hood/NPC/seam"),TO); }

  if(arg) return;
set_light(1);

short_desc = "A Merchant Shop";
long_desc =
	"  This is the shop of the local seamstress.  Around the shop\n"+
	"are strewn bolts of cloth as well as huge animal hides.  There\n"+
	"is a large table for laying out work and a chair.\n";

items = ({
	"bolts","Various brightly colored cloths",
	"hides","Cow, deer and bear hides for armor and clothing",
	"table","A long, flat wooden table",
	"chair","A wooden, high backed rocking chair",
});

dest_dir = ({
	"players/eurale/Dis/Hood/rh20.c","southwest",
});

}
