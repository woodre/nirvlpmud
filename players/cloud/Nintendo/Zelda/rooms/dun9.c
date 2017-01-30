/*  Zelda Dungeon9
 *  /Nintendo/Zelda/rooms/dun9.c
 *  Cloud 2013
 */
 
#include "/obj/ansi.h"
inherit "room/room";

reset(arg) 
{	
	::reset(arg);
	
	if(!present("ganon")) 
	{	
		move_object(clone_object("/players/cloud/Nintendo/Zelda/mobs/ganon.c"),this_object());
	}
	
	if(!arg)
 	{
		set_light(1);

		short_desc = ""+HIB+"Death Mountain"+NORM+"" ;
		
		long_desc =
		""+HIB+"         ***"+NORM+"\n"+
     	""+HIB+"        *"+HIK+"["+HIR+"@"+HIK+"]"+HIB+"*"+NORM+"\n"+
     	""+HIB+"       **"+HIK+"[ ]"+HIB+"**"+NORM+"\n"+
     	""+HIB+"      ***"+HIK+"[ ]"+HIB+"***"+NORM+"\n"+
     	""+HIB+"     ****"+HIK+"[ ]"+HIB+"****"+NORM+"\n"+
     	""+HIB+"    *****"+HIK+"[ ]"+HIB+"*****"+NORM+"\n"+
     	""+HIB+"   ******"+HIK+"[ ]"+HIB+"******"+NORM+"\n"+
     	""+HIB+"  *******"+HIK+"[ ]"+HIB+"*******"+NORM+"\n"+
     	""+HIB+" ********"+HIK+"[ ]"+HIB+"********"+NORM+"\n"+
     	""+HIB+"*********"+HIK+"[ ]"+HIB+"*********"+NORM+"\n";
     			
		dest_dir = 
		({
			"players/cloud/Nintendo/Zelda/rooms/dun8.c","down",
		});
	}
}