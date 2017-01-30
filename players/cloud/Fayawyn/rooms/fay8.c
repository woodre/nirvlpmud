/*  
 *  Fayawyn Tower Landing 
 *  fay8
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
	if(num == 0) {color = HIR+"Fayawyn Tower Landing"+NORM;}
	if(num == 1) {color = HIW+"Fayawyn Tower Landing"+NORM;}
	if(num == 2) {color = HIY+"Fayawyn Tower Landing"+NORM;}
	if(num == 3) {color = HIB+"Fayawyn Tower Landing"+NORM;}
	if(num == 4) {color = HIC+"Fayawyn Tower Landing"+NORM;}
	if(num == 5) {color = HIG+"Fayawyn Tower Landing"+NORM;}

	::reset(arg);
	
	if(!present("guard")) 
	{	
		spawn = random(3);
		if (spawn == 0) 
			{
				move_object(clone_object("/players/cloud/Fayawyn/mobs/guard.c"),this_object());
			}
		if (spawn == 1)
			{
				move_object(clone_object("/players/cloud/Fayawyn/mobs/guard.c"),this_object());
				move_object(clone_object("/players/cloud/Fayawyn/mobs/guard.c"),this_object());
			}	
		if (spawn == 2)
			{
				move_object(clone_object("/players/cloud/Fayawyn/mobs/guard.c"),this_object());
				move_object(clone_object("/players/cloud/Fayawyn/mobs/guard.c"),this_object());
				move_object(clone_object("/players/cloud/Fayawyn/mobs/guard.c"),this_object());
			}	
	}

 
 	if(!arg)
 	{

  		set_light(1);

		short_desc= ""+color+"";
 
		long_desc=
			""+HIC+"The top of the great oak tree is actually a magnificent tower that"+NORM+"\n" +
			""+HIC+"overlooks the small village below. It is about four hundred feet tall."+NORM+"\n" +
			""+HIC+"The tower gleams with strange glowing symbols that pulsate softly."+NORM+"\n" +
			""+HIC+"The landing here, that the ladder led up to, also has the strange."+NORM+"\n" +
			""+HIC+"symbols. An iron-strapped, wooden door guards entrance to the tower."+NORM+"\n";
 


		items=
		({	
  			"ladder",
  				"The wooden ladder leads down to the bridgeway below",
  			"tree",
  				"It must be truly magical grow into a tower like this",
  			"tower",
  				"It is glowing with symbols",
  			"village",
  				"You can see the bridgeway below through the canopy",
  			"symbols",
  				"They pulsate softly, shifting from cyan to purple",
  			"landing",
  				"Much like the platforms below, it is supported by the great tree",
  			"door",
  				"Truly a work of art, the door looks very strong",
  			"canopy",
  				"Providing a wonderful habitat, the canopy shelters\n" +
 	 			"the village from unpredictable weather",
 	 		"platforms",
 	 			"You can barley make them out from up here",
 	 		"bridgeway",
 	 			"You can see the bridgeway wrap around the tree",
  				
 
 		});

		dest_dir=
		({
			"/players/cloud/Fayawyn/rooms/fay7.c", "down",
 			"/players/cloud/Fayawyn/rooms/fay9.c", "enter",  
		});
	}
}


