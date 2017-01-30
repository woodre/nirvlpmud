/*  Clouds Workroom
 *  workroom.c
 *  Cloud 2012
 */
#include "/obj/ansi.h"

inherit "room/room";

reset(arg) 
{

	::reset(arg);		

	
 	if(!arg)
 	{
		set_light(1);

 	 	short_desc= ""+HIW+"Cloud's Cloud"+NORM+"";
 
		long_desc=
			""+HIW+"This is Cloud's Cloud. Its Puffy."+NORM+"\n" ;

		dest_dir=
		({
 			"/room/church", "church",
 			"/room/post",   "post",
 			"/players/cloud/Nintendo/rooms/inhub.c", "hub",
        });
	}
}