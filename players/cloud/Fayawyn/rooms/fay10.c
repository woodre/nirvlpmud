/*  Fayawyn Throne Room
 *  fay10.c
 *  Cloud 2009
 */
 
#include "/obj/ansi.h"

inherit "room/room";

int num;

string color;
 
reset(arg) 
{
	num = random(6);
	if(num == 0) {color = HIR+"Fayawyn Throne Room"+NORM;}
	if(num == 1) {color = HIW+"Fayawyn Throne Room"+NORM;}
	if(num == 2) {color = HIY+"Fayawyn Throne Room"+NORM;}
	if(num == 3) {color = HIB+"Fayawyn Throne Room"+NORM;}
	if(num == 4) {color = HIC+"Fayawyn Throne Room"+NORM;}
	if(num == 5) {color = HIG+"Fayawyn Throne Room"+NORM;}
	
	::reset(arg);

	if(!present("queen")) 
		{
			move_object(clone_object("/players/cloud/Fayawyn/mobs/queen.c"),this_object());
		}	
 
 	if(!arg)
 	{

		set_light(1);

  		short_desc= ""+color+"";
 
		long_desc=
			""+HIC+"The staircase opens to this magnificent throne room. Three"+NORM+"\n" +
			""+HIC+"stained glass windows on the ceiling make the room shimmer with"+NORM+"\n" +
			""+HIC+"an array of colors. A huge crystal throne in the middle of the"+NORM+"\n" +
			""+HIC+"room steals the spotlight from its surroundings. It glows a soft"+NORM+"\n" +
			""+HIC+"purple when the light shines on it just right. A true sight indeed."+NORM+"\n";
 
		items=
		({	
  		"staircase",
  			"It leads back down into the tower",
  		"glass",
  			"Three moon-shaped windows with stained glass shimmer from the light",
  		"windows",
  			"Three moon-shaped windows with stained glass shimmer from the light",
  		"ceiling",
  			"Three windows cover the ceiling letting light in",
  		"colors",
  			"ROYGBIV",
  		"throne",
  			"Made of a light purple crystal, the throne is beautiful to say the least",
  		"crystal",
  			"It makes up the entire throne",
  		"light",
  			"A shimmering array of colors",
  		"tower",
  			"The person that constructed such a tower must have put years of work into it",  		
  
 		});

		dest_dir=
		({
 			"/players/cloud/Fayawyn/rooms/fay9.c", "down" 
		});
	}
}