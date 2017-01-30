inherit "/room/room";
#include <ansi.h>
#include "../../defs.h"

reset(arg)
{
::reset(arg);

if(!present("drakganoth")) {
        move_object(clone_object(HALLNPC+"drakganoth.c"),this_object());
}

if(arg) return;
	set_light(1);
	short_desc = HIK+"The Alchemy Lab"+NORM;
	long_desc =
	"The room glows with bright colors coming from the flasks\n"+
	"on the burners of the lab desk. Bright flames ignite from\n"+
	"Bunsen burner that keep the liquids at their boiling points\n"+
	"There is a door that leads back out to the entrace hall from\n"+
	"which you arrived from.\n";

items =

({
	"colors",
	"All the colors of the rainbow",
	"bright colors",
	"All the colors of the rainbow",
	"flasks",
	"Large glass containers holding chemicals",
	"chemicals",
	"Different liquids that you can combine together to create new stuff",
	"flames",
	"The flames are a bright red and orange",
	"bright flames",
	"The flames are a bright red and orange",
	"burner",
	"A special burner that was developed by Robert Bunsen",
	"Bunsen burner",
	"A special burner that was developed by Robert Bunsen",
	"liquids",
	"Different chemicals that you can combine together to create new stuff",
	"door",
	"A door that leads back to the entrance hall",
	});

dest_dir =
({
	HALLRMS+"entrance.c",	"south",
	});
}

realm(){ return "NT"; }
query_no_fight(){ return 1; }

init(){
	::init();
	
	add_action("ask", "ask");
	add_action("mix", "mix");
	add_action("boil", "boil");
}

ask(str)
{
	if(!str)
	{
		write("You can ask him 'about poisons', 'about making', 'about instant', or 'about deadly'.\n");
		return 1;
	}
	
	if(str != "about poisons" && str != "about making" && str != "about instant" && str != "about deadly")
	{
		write("You can only ask Drak'Ganoth 'about poisons', 'about making', 'about instant', or 'about deadly'.\n");
		return 1;
	}
	
	if(str == "about poisons")
	{
		write("Drak'Ganoth explains: There are two types of poisons that I have\n");
		write("current discovered. I have the 'instant' poison and the 'deadly'\n");
		write("poison. I do not have the ingredients to sell these poisons. However\n");
		write("you can bring me the ingredients and I will teach you how to make it.\n");
		write("Just 'ask' me 'about making' them together.\n");
		return 1;
	}
	
	if(str == "about making")
	{
		write("Drak'Ganoth explains: As I explained before, I have only discovered\n");
		write("two poisons at this time. I do not have the ingredients on hand to\n");
		write("make these poisons but if you were to bring me them, I could easily\n");
		write("teach you how to make these poisons yourself with my alchemy lab.\n");
		return 1;
	}
	
	if(str == "about instant")
	{
		write("Drak'Ganoth explains: In order to make the instant poison which will\n");
		write("instantly course through your enemies veins.. You must first mix\n");
		write("some woodbine berries with some yew berries to make a thick paste.\n");
		write("Only then will you be able to boil together the thick paste with some\n");
		write("yew berries to create your instant poison.\n");
		return 1;
	}
	
	if(str == "about deadly")
	{
		write("Drak'Ganoth explains: In order to make your deadly poison that will\n");
		write("slowly float through your enemies veins and do damage over time.. You\n");
		write("must first mix some pokeweed berries with some yew berries to make a\n");
		write("thin paste. Only then will you be able to boil together the thin paste\n");
		write("with some bittersweet berries to create your deadly poisons.\n");
		return 1;
	}
	return 1;
}

mix(str)
{
	object thick, thin;
	string what, what2;
	
	if(!str || sscanf(str, "%s with %s", what, what2) != 2)
	{
		write("Usage: mix <berry 1> with <berry 2>\n");
		return 1;
	}
	
	
	if(!present(what, this_player()))
	{
		write("You do not have "+what+"!\n");
		return 1;
	}
	
	if(!present(what2, this_player()))
	{
		write("You do not have "+what2+"!\n");
		return 1;
	}
	
	if(what == "woodbine" && what2 == "yew")
	{
		write("You combine together some woodbine berries and yew berries\n");
		write("to make a thick paste.\n");
		destruct(present(what, this_player()));
		destruct(present(what2, this_player()));
		thick = clone_object(OBJPATH+"thickpaste.c");
		move_object(thick, this_player());
	}
	
	if(what == "yew" && what2 == "woodbine")
	{
		write("You combine together some yew berries and woodbine berries\n");
		write("to make a thick paste.\n");
		destruct(present(what, this_player()));
		destruct(present(what2, this_player()));
		thick = clone_object(OBJPATH+"thickpaste.c");
		move_object(thick, this_player());
	}
	
	if(what == "pokeweed" && what2 == "yew")
	{
		write("You combine together some pokeweed berries and yew berries\n");
		write("to make a thin paste.\n");
		destruct(present(what, this_player()));
		destruct(present(what2, this_player()));
		thin = clone_object(OBJPATH+"thinpaste.c");
		move_object(thin, this_player());
	}
	
	if(what == "yew" && what2 == "pokeweed")
	{
		write("You combine together some pokeweed berries and yew berries\n");
		write("to make a thin paste.\n");
		destruct(present(what, this_player()));
		destruct(present(what2, this_player()));
		thin = clone_object(OBJPATH+"thinpaste.c");
		move_object(thin, this_player());
	}	
	return 1;
}

boil(str)
{
	object instant, deadly;
	string what, what2;
	
	if(!str || sscanf(str, "%s with %s", what, what2) != 2)
	{
		write("Usage: boil <paste> with <berry>\n");
		return 1;
	}
	
	
	if(!present(what, this_player()))
	{
		write("You do not have "+what+"!\n");
		return 1;
	}
	
	if(!present(what2, this_player()))
	{
		write("You do not have "+what2+"!\n");
		return 1;
	}
	
	if(what == "thick paste" && what2 == "yew")
	{
		write("You boil together some thick paste and some yew berries\n");
		write("to make some instant poison.\n");
		destruct(present(what, this_player()));
		destruct(present(what2, this_player()));
		instant = clone_object(OBJPATH+"instant.c");
		move_object(instant, this_player());
	}
	
	if(what == "thin paste" && what2 == "bittersweet")
	{
		write("You boil together some thin paste and some bittersweet berries\n");
		write("to make some deadly poison.\n");
		destruct(present(what, this_player()));
		destruct(present(what2, this_player()));
		deadly = clone_object(OBJPATH+"deadly.c");
		move_object(deadly, this_player());
	}
	
	return 1;
}