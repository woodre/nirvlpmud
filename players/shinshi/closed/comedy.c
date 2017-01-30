inherit "/room/room";
#include <ansi.h>

reset(arg)
{
::reset(arg);

if(arg) return;
	set_light(-1);
	short_desc = "A Comedy Event";
	long_desc =
		"A large open room with thousands and thousands of seats\n"+
		"circle around the center stage where the comedian will\n"+
		"stand and entertain you for the next hour or two.\n";
		
	dest_dir =
({
	"/players/shinshi/workroom.c",	"workroom",
	"/room/vill_green.c",	"green",
	});
}

no_light_damage() { return 1; }

init(){
	::init();
	add_action("danecook","dane");
}

danecook(){
	
	if(!present("dane_cook")) {
	move_object(clone_object("/players/shinshi/closed/danecook.c"),this_object());
	write("Dane Cook runs through the crowd, jumps onto the stage.\n");
	say("Dane Cook runs through the crowd, jumps onto the stage.\n");
	return 1;
}
	else {
	write("Dane Cook looks at you, and yells, \"BABY... I'M HERE!\"\n");
	return 1;
	}
}