/*  Fayawyn Bridgeway
 *  fay2
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
 		""+HIC+"A large branch makes its home here just above the platform, creating"+NORM+"\n" +
		""+HIC+"a nice place to sit and relax. A small, run-down hut can be seen to"+NORM+"\n" +
 		""+HIC+"the northwest. Across the rope bridge westward a blanket of darkness"+NORM+"\n" +
 		""+HIC+"covers the area like an unforgiving fog bank. Something is not right."+NORM+"\n";


		items=
		({
		"fog",
			"Out of place, the darkness overcomes the area ahead",
		"bank",
			"Out of place, the darkness overcomes the area ahead",
		"village",
  			"Wooden platforms and huts populate this area creating a small village",
		"canopy",
  			"Providing a wonderful habitat, the canopy shelters\n" +
 	 		"the village from unpredictable weather",
  		"darkness",
  			"Out of place, the darkness overcomes the area ahead",
  		"blanket",
  			"Out of place, the darkness overcomes the area ahead",
  		"branch",
  			"Reaching five feet in diameter, the branch grew its\n" +
  			"way around the tree entwining itself into the village", 
  		"platform",
  			"Finely constructed, the wooden platform holds\n" + 
  			"strongly beneath your feet",
  		"tree",
  			"It continues above the village about thirty feet\n" +
  			"before branching out in a marvelous canopy of shelter",
  		"hut",
  			"Blackened wood constructs the small hut. It looks out of place",
  		"bridge",
  			"It seems sturdy enough",
 		});


		dest_dir=
		({
 		"/players/cloud/Fayawyn/rooms/fay1.c","southwest",
 		"/players/cloud/Fayawyn/rooms/fay3.c","west",
		});
	
	}
}
