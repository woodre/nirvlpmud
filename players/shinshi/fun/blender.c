inherit "/obj/treasure.c";
#include <ansi.h>

id(str) {
return str == "blender" || str == "shinshi_blender";
}

short() { return "A Blender"; }
long() {
	write("This is a simple blender. It has two speeds:\n"+
		  "Puree and Holy shit. Maybe you could press one.\n");
}

get() { return 1; }
query_weight() { return 3; }
query_value(){ return 0; }


init()
{
	::init();
	
	add_action("press", "press");
}

press(str)
{
	object me;
	
	me = this_player();
	
	if(!str)
	{
		write("What would you like to press?\n");
		return 1;
	}
	
	if(str != "puree" && str != "holy shit")
	{
		write("That button is not here!\n");
		return 1;
	}
	
	if(str == "puree")
	{
		write("The blender begins to run smoothly.\n");
		return 1;
	}
	
	if(str == "holy shit")
	{
		write("The blender goes BERSERK and cuts you before falling apart.\n");
		me->hit_player(random(200), "other|blender");
		destruct(this_object());
		return 1;
	}
}