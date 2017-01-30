/*  Fayawyn Entrance
 *  fay1
 *  Cloud 2009
 */
#include "/obj/ansi.h"
 
inherit "room/room";

int num;
int spawn;

string color;

reset(arg)
{
	num = random(6);
   	if(num == 0) {color = HIR+"Fayawyn Entrance"+NORM;}
   	if(num == 1) {color = HIW+"Faywayn Entrance"+NORM;}
   	if(num == 2) {color = HIY+"Fayawyn Entrance"+NORM;}
   	if(num == 3) {color = HIB+"Fayawyn Entrance"+NORM;}
   	if(num == 4) {color = HIC+"Fayawyn Entrance"+NORM;}
   	if(num == 5) {color = HIG+"Fayawyn Entrance"+NORM;}
   	
	::reset(arg);
	
	if(!present("fairy")) 
	{	
		spawn = random(3);
		if (spawn == 0) 
			{
				move_object(clone_object("/players/cloud/Fayawyn/mobs/fairy.c"),this_object());
			}
		if (spawn == 1)
			{
				move_object(clone_object("/players/cloud/Fayawyn/mobs/fairy.c"),this_object());
				move_object(clone_object("/players/cloud/Fayawyn/mobs/fairy.c"),this_object());
			}	
		if (spawn == 2)
			{
				move_object(clone_object("/players/cloud/Fayawyn/mobs/fairy.c"),this_object());
				move_object(clone_object("/players/cloud/Fayawyn/mobs/fairy.c"),this_object());
				move_object(clone_object("/players/cloud/Fayawyn/mobs/fairy.c"),this_object());
			}	
	}

	
	
 	if(!arg)
 	{

	 	set_light(1);

  		short_desc=""+color+"";

		long_desc=
 		""+HIC+"The circular platform hidden well within the mysterious tree"+NORM+"\n" +
 		""+HIC+"unveils a small village. Sun rays cut through the canopy above,"+NORM+"\n" +
 		""+HIC+"providing supple lighting. Other platforms can be seen around,"+NORM+"\n" +
 		""+HIC+"all connected by rope bridges like the one to the northeast."+NORM+"\n" +
 		""+HIC+"You can "+HIM+"climb down"+HIC+" the rope ladder to get back to the forest."+NORM+"\n" ;


		items=
		({	
  		"canopy",
  			"Providing a wonderful habitat, the canopy shelters\n" +
 	 		"the village from unpredictable weather",
 	 	"rays",
  			"Staring into the sun probably is not the best idea",
  		"platform",
  			"Finely constructed, the wooden platform holds\n" + 
  			"strongly beneath your feet",
  		"platforms",
  			"Finely constructed, the wooden platform holds\n" + 
  			"strongly beneath your feet",
  		"tree",
  			"It continues above the village about thirty feet\n" +
  			"before branching out in a marvelous canopy of shelter",
  		"village",
  			"Wooden platforms and huts populate this area creating a small village",
  		"bridge",
  			"It seems sturdy enough",
  		"ladder",
  			"The only way for a non-flyer to enter or exit this village",
  		"huts",
  			"They are scattered here and there throughout the village",
 		});	


		dest_dir=
		({
 		"/players/cloud/Fayawyn/rooms/fay2.c","northeast",
		});
	
	}
}

init() 
{
    ::init();
    add_action("climb","climb");
}

climb(string str) 
{
    if(str == "down")
    {
    	move_object(this_player(), "room/forest6");
    	command("look", this_player());
    	return 1;
	}
    else
    {
	    write("Climb which way?\n");
	  	return 1;
  	}
}