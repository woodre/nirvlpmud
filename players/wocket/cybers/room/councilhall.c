#include "../defs.h"
inherit ROOM;

reset(int arg){
	if(!arg){
		set_light(1);
		short_desc=HIY+"Cyberninja Council Hall"+OFF;
		long_desc="  "+
		"A spacious room with a bamboo flooring and wood walls. Paper walls give\n"+
		"structure to the room and let a small amount of sunlight in.  Scrolls \n"+
		"line the sides of the rooms covered by markings filled with hidden meaning.\n"+
		"Sliding doors lead out of the room to other parts of the dojo while a\n"+
		"wooden gate leads to the outside.\n";		
		items = ({
			"walls","They are made of paper and are slightly translucent.",
			"floor","Soft bamboo lines the floor giving it a certain spring.",
			"scrolls","They are covered in ancient markings",
			"markings","You are unable to completely decipher them",
			});
					
		dest_dir=({
			PATH+"/room/dojo2.c","south",
		});
		
		add_property("no_teleport");
		add_property("no_follow");
		add_property("fight_area");
	}
}