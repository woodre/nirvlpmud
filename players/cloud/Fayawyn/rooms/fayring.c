/*
 *  Fayawyn Fairy Ring
 *  fayring
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
	if(num == 0) {color = HIR+"Fayawyn Fairy Ring"+NORM;}
	if(num == 1) {color = HIW+"Fayawyn Fairy Ring"+NORM;}
	if(num == 2) {color = HIY+"Fayawyn Fairy Ring"+NORM;}
	if(num == 3) {color = HIB+"Fayawyn Fairy Ring"+NORM;}
	if(num == 4) {color = HIC+"Fayawyn Fairy Ring"+NORM;}
	if(num == 5) {color = HIG+"Fayawyn Fairy Ring"+NORM;}

	::reset(arg);		

	if(!present("fairy")) 
	{	
		spawn = random(3);
		if (spawn == 0) 
			{
				move_object(clone_object("/players/cloud/Fayawyn/mobs/pofay.c"),this_object());
			}
		if (spawn == 1)
			{
				move_object(clone_object("/players/cloud/Fayawyn/mobs/pofay.c"),this_object());
				move_object(clone_object("/players/cloud/Fayawyn/mobs/pofay.c"),this_object());
			}	
		if (spawn == 2)
			{
				move_object(clone_object("/players/cloud/Fayawyn/mobs/pofay.c"),this_object());
				move_object(clone_object("/players/cloud/Fayawyn/mobs/pofay.c"),this_object());
				move_object(clone_object("/players/cloud/Fayawyn/mobs/pofay.c"),this_object());
			}	
	}
	if(!present("doorknob"))
		{
			move_object(clone_object("/players/cloud/Fayawyn/mobs/doorknob.c"),this_object());
		}	

 	if(!arg)
 	{
  		set_light(1);

 	 	short_desc= ""+color+"";
 
		long_desc=
			""+HIC+"Everything is different here. There is no ground, but standing is possible."+NORM+"\n" +
			""+HIC+"Up seems to be down, left is right. Laughing can be heard in all directions."+NORM+"\n" +
			""+HIC+"The entire area is lit up bright white, but there are not any sources of light."+NORM+"\n" +
			""+HIC+"The once small ring of mushrooms now towers upwards like huge skyscrapers."+NORM+"\n" +
			""+HIC+"The platform, which grew the mushroom ring, now resides above the mushrooms."+NORM+"\n";
 
		items=
		({	
			"ring",
				"Fay are tricky little things. Think twice before entering one of their rings",
			"mushrooms",
				"Previously inches high, these one hundred foot shrooms seem much more indimidating",
  			"mushroom",
  				"Previously inches high, these one hundred foot shrooms seem much more indimidating",
  			"platform",
  				"It is hard to see the platform above. Now how to get back?",
		});

		dest_dir=
		({
 			
        });
	}
}