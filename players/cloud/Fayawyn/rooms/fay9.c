/*  Fayawyn Tower
 *  fay9.c
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
	if(num == 0) {color = HIR+"Fayawyn Tower"+NORM;}
	if(num == 1) {color = HIW+"Fayawyn Tower"+NORM;}
	if(num == 2) {color = HIY+"Fayawyn Tower"+NORM;}
	if(num == 3) {color = HIB+"Fayawyn Tower"+NORM;}
	if(num == 4) {color = HIC+"Fayawyn Tower"+NORM;}
	if(num == 5) {color = HIG+"Fayawyn Tower"+NORM;}
	
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
			""+HIC+"The inside of the tower is very cold. A large, winding staircase"+NORM+"\n" +
			""+HIC+"lines the inner wall heading far upwards in a corkscrew pattern."+NORM+"\n" +
			""+HIC+"Symbols follow the staircase, lighting the path to the unknown above."+NORM+"\n";
 
		items=
		({	
  		"staircase",
  			"It seems to go on forever upwards",
  		"wall",
  			"Glowing symbols line the walls",
  		"symbols",
  			"Pulsating softly, they light the way upwards",
  		"path",
  			"It is the staricase leading upwards",
  		"tower",
  			"The inside of the tower is lit by glowing symbols",
  
 		});

		dest_dir=
		({
 			"/players/cloud/Fayawyn/rooms/fay10.c", "up",
 			"/players/cloud/Fayawyn/rooms/fay8.c", "out",  
		});
	}
}