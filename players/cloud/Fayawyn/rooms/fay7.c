/*  Fayawyn Bridgeway
 *  fay7
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
	if(num == 0) {color = HIR+"Fayawyn Bridge Way"+NORM;}
	if(num == 1) {color = HIW+"Faywayn Bridge Way"+NORM;}
	if(num == 2) {color = HIY+"Fayawyn Bridge Way"+NORM;}
	if(num == 3) {color = HIB+"Fayawyn Bridge Way"+NORM;}
	if(num == 4) {color = HIC+"Fayawyn Bridge Way"+NORM;}
	if(num == 5) {color = HIG+"Fayawyn Bridge Way"+NORM;}

	::reset(arg);

	if(!present("matriarch")) 
	{	
		spawn = random(3);
		if (spawn == 0) 
			{
				move_object(clone_object("/players/cloud/Fayawyn/mobs/matriarch.c"),this_object());
			}
		if (spawn == 1)
			{
				move_object(clone_object("/players/cloud/Fayawyn/mobs/matriarch.c"),this_object());
				move_object(clone_object("/players/cloud/Fayawyn/mobs/matriarch.c"),this_object());
			}	
		if (spawn == 2)
			{
				move_object(clone_object("/players/cloud/Fayawyn/mobs/matriarch.c"),this_object());
				move_object(clone_object("/players/cloud/Fayawyn/mobs/matriarch.c"),this_object());
				move_object(clone_object("/players/cloud/Fayawyn/mobs/matriarch.c"),this_object());
			}	
	}	

 	if(!arg)
 	{

  		set_light(1);

  		short_desc= ""+color+"";
 
		long_desc=
			""+HIC+"This platform is very plain except for the large ladder that"+NORM+"\n" +
			""+HIC+"makes its way upwards before dissapearing into the canopy above."+NORM+"\n" +
			""+HIC+"The branches of the tree entwine the platform and ladder making"+NORM+"\n" +
			""+HIC+"it appear that these platforms were not built, but grown in place."+NORM+"\n" ;
 
		items=
		({	
  			"platform",
  				"A solid slab of wood supported by the branches of this tree",
  			"ladder",
  				"The ladder seems grow from out of the platform",
  			"canopy",
  				"Looking upwards, the enormous canopy shelters this small village",
  			"branches",
  				"They grow out of every direction of the tree acting as supports", 
  			"tree",
  				"It grows into a large tower. It must be magical.",
  			"village",
  				"Wooden platforms and huts populate this area creating a small village",
  			"platforms",
  				"They are doing to good job of holding up the village",
  			"huts",
  				"They are scattered here and there throughout the village",
  			"wood",
  				"Its has a very tight grain. It looks very strong",
  			"grain",
  				"It flows in a wave pattern",
  			"tower",
  				"The tower is barley visible through the canopy above. It seems to be glowing",
 		});


		dest_dir=
		({	
			"/players/cloud/Fayawyn/rooms/fay6.c", "southwest",
			"/players/cloud/Fayawyn/rooms/fay8.c", "up",
        });
	}
}


