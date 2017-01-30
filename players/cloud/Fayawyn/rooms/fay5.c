/*  Fayawyn Bridgeway
 *  fay5
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
			""+HIC+"A small hut is built onto the western ledge of the platform here."+NORM+"\n" +
			""+HIC+"Words are carved into the tree just beside the hut. Attatched to"+NORM+"\n" +
			""+HIC+"the hut door is a lantern that lights the surrounding area well."+NORM+"\n" +
			""+HIC+"The bridgeway continues south across a rope bridge covered in fog."+NORM+"\n";
 
		items=
		({	
  			"hut",
  				"Red shutters cover the window edges, while plain wood makes up the rest of the hut",
  			"shutters",
  				"They need to be cleaned",
  			"window",
  				"The windows are too dirty to see through",
  			"wood",
  				"It looks to be the same wood that the tree is",
  			"door",
  				"A lantern is built ontp the top portion of the door",
  			"platform",
  				"It is very close to the large tree that supports it",
  			"words",
  				""+HIR+"KEEP OUT"+NORM+" is freshly carved into the tree",
  			"lantern",
  				"Blackened iron wrapped around a glass vase, in a manner that looks like vines",
  			"iron",
  				"It twists around the vase like wild vines",
  			"vase",
  				"Its made of glass",
  			"tree",
  				"The marvelous tree sprouts branches in all directions",
  			"branches",
  				"The branches shoot off in all directions from the tree",
  			"ledge",
  				"Giant wooden blocks are fastened to the ledge giving the hut somewhere to hang from",
  			"blocks",
  				"Like a footer for a building, the blocks support the huts weight",
  			"bridge",
  				"It seems sturdy enough",	
  			
 		});

		dest_dir=
		({
 			"/players/cloud/Fayawyn/rooms/fay6.c", "south",
 			"/players/cloud/Fayawyn/rooms/fay4.c", "north",
 			"/players/cloud/Fayawyn/rooms/fayhut.c", "hut",
		});
	}
}


