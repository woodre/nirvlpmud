/*  Zelda Dungeon6
 *  /Nintendo/Zelda/rooms/dun6.c
 *  Cloud 2015
 */
 
#include "/obj/ansi.h"
inherit "room/room";

reset(arg) 
{	
	::reset(arg);
	
	if(!present("gohma")) 
	{	
		move_object(clone_object("/players/cloud/Nintendo/Zelda/mobs/gohma.c"),this_object());
	}
	
	if(!arg)
 	{
		set_light(1);

		short_desc = ""+HIB+"Death Mountain"+NORM+"" ;
		
		long_desc =
		""+HIB+"         ***"+NORM+"\n"+
     	""+HIB+"        *"+HIK+"["+HIR+"B"+HIK+"]"+HIB+"*"+NORM+"\n"+
     	""+HIB+"       **"+HIK+"[ ]"+HIB+"**"+NORM+"\n"+
     	""+HIB+"      ***"+HIK+"[ ]"+HIB+"***"+NORM+"\n"+
     	""+HIB+"     ****"+HIK+"["+HIR+"@"+HIK+"]"+HIB+"****"+NORM+"\n"+
     	""+HIB+"    *****"+HIK+"[ ]"+HIB+"*****"+NORM+"\n"+
     	""+HIB+"   ******"+HIK+"[ ]"+HIB+"******"+NORM+"\n"+
     	""+HIB+"  *******"+HIK+"[ ]"+HIB+"*******"+NORM+"\n"+
     	""+HIB+" ********"+HIK+"[ ]"+HIB+"********"+NORM+"\n"+
     	""+HIB+"*********"+HIK+"[ ]"+HIB+"*********"+NORM+"\n";
     			
		dest_dir = 
		({
			"players/cloud/Nintendo/Zelda/rooms/dun7.c","up",
			"players/cloud/Nintendo/Zelda/rooms/dun5.c","down",
		});
	}
}