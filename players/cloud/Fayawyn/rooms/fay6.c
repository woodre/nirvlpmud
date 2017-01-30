/*  Fayawyn Bridgeway
 *  fay6
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
			""+HIC+"Traveling the way onto this platform reveals that a thick, green"+NORM+"\n" +
			""+HIC+"moss is growing all over it. A "+HIM+"ring"+HIC+" of purple-spotted mushrooms"+NORM+"\n" +
			""+HIC+"is growing in the center of the platform. The bridgeway continues"+NORM+"\n" +
			""+HIC+"northeast to a platform with a ladder leading upwards into the tree."+NORM+"\n";
 
		items=
		({	
			"mushrooms",
				"A perfectly round ring of mushrooms grows here. Perhaps you should "+HIM+"enter"+NORM+" the "+HIM+"ring"+NORM+"",
			"canopy",
  				"Providing a wonderful habitat, the canopy shelters\n" +
 	 			"the village from unpredictable weather",
			"ring",
				"A perfectly round ring of mushrooms grows here. Perhaps you should "+HIM+"enter"+NORM+" the "+HIM+"ring"+NORM+"",	
			"moss",
  				"Covering the wooden platform is a thick squishy green moss",
  			"platform",
  				"The Platform is covered in moss",
  			"platforms",
  				"They are doing to good job of holding up the village",
  			"village",
  				"Wooden platforms and huts populate this area creating a small village",
  			"ladder",
  				"It seems to lead up through the canopy to the top of the tree",
  			"tree",
  				"It grows into a large tower. It must be magical.",
  			"bridges",
  				"The series of platforms, bridges, and huts that makes up this village",
  			"bridgeway",
  				"The series of platforms, bridges, and huts that makes up this village",
  			"huts",
  				"They are scattered here and there throughout the village",
  			"tower",
  				"The tower is barley visible through the canopy above. It seems to be glowing",
  	
		});

		dest_dir=
		({
 			"/players/cloud/Fayawyn/rooms/fay7.c", "northeast",
 			"/players/cloud/Fayawyn/rooms/fay5.c", "north", 
        });
	}
}

	init()
	{
		::init();
		add_action("enter","enter");
	}

	enter(string str)
	{		
		if(str == "ring")
  		{	
			tell_object(this_player(),
	  			"\n"+HIW+"As you step into the ring you are sucked downward into the platform."+NORM+"\n\n");
			tell_room(environment(this_player()),
				"\n"+HIW+this_player()->query_name()+" steps into the ring and is sucked downward into the platform."+NORM+"\n\n", ({ this_player() }));
            move_object(this_player(), "/players/cloud/Fayawyn/rooms/fayring.c");
            command("look", this_player());
			return 1;
 		}
 		 
  		else
  		{
	  		write("Enter what?\n");
	  		return 1;
  		}
	}
