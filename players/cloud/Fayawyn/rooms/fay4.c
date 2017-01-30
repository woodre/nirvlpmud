/*  Fayawyn Bridgeway
 *  fay4
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
		""+HIC+"The darkness continues across the bridge to this new platform."+NORM+"\n" +
		""+HIC+"An outline of another hut can be seen to the southwest through"+NORM+"\n" + 
		""+HIC+"the mist. The bridgeway contiunes south to another platform."+NORM+"\n"; 
 
		items=
		({	
  		"hut",
  			"Just the outline can be seen from here",
  		"mist",
  			"It surrounds the area, obsructing the area ahead",
  		"platform",
  			"All made of the same wood, they all look the same",
  		"wood",
  			"It looks to be part of the tree",
 		"darkness",
  			"The darkness overcomes the entire area",  
		"outline",
			"The hut seems to be about the same size as the rest",
		"huts",
  			"They are scattered here and there throughout the village",
  		"bridge",
  			"It seems sturdy enough",
  		
		 });

		dest_dir=
		({
 		"/players/cloud/Fayawyn/rooms/fay5.c","south",
 		"/players/cloud/Fayawyn/rooms/fay3.c","northeast",
		});
	}
}


