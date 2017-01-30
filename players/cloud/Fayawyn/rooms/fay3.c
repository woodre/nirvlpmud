/*  Fayawyn Bridgeway
 *  fay3
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
		""+HIC+"A strange darkness surrounds the area. The sun's rays seem to be blocked"+NORM+"\n" +
 		""+HIC+"by a thick purple mist that hovers just under the tree top. Screams and"+NORM+"\n" + 
 		""+HIC+"ringing bells can be heard from within the ruined hut built here. A rope"+NORM+"\n" +
 		""+HIC+"bridge leads southwest to yet another platform that makes up this village."+NORM+"\n"; 
 
 		items=
		({	
		"platforms",
  			"Near the hut, part of this platform is charred",
  		"hut",
  			"Evidence of fire surrounds the hut, with charred wood and half a roof",
  		"roof",
  			"It really has taken a beating",
  		"wood",
  			"The wood is charred to a crisp",
  		"mist",
  			"It surrounds the air above defying reality",
  		"tree",
  			"The tree dissapears above the strange mist",
  		"bridge",
  			"It seems sturdy enough",
  		"platform",
  			"Near the hut, part of this platform is charred",
  		"village",
  			"Wooden platforms and huts populate this area creating a small village",
  		"rays",
  			"The mist is stopping them from coming through to the village",
  		"darkness",
  			"The darkness overcomes the sky above",
  		"huts",
  			"They are scattered here and there throughout the village",
  		"sky",
  			"The canopy blocks the view of the sky",
  		"canopy",
  			"Providing a wonderful habitat, the canopy shelters\n" +
 	 		"the village from unpredictable weather",
  		});


		dest_dir=
		({
		"/players/cloud/Fayawyn/rooms/fay2.c","east",
		"/players/cloud/Fayawyn/rooms/fay4.c","southwest",
		"/players/cloud/Fayawyn/rooms/faydealer.c","hut",
		});
	}
}


