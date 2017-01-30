#include <ansi.h>
#include "../defs.h"

int firsttime, earth, fire, air, water;

id(str) { return (str == "book" || str == "temp_ele_gobj" || str == "GI"); }

short() { return "History Book of the "+RED+"Ele"+YEL+"men"+GRN+"tal"+CYN+"ists"+NORM+"\n";}

long() {
	write("This book has seen better days. The black, shiny leather is ripped\n");
	write("and rugged. The pages are stuck together by an unknown liquid that\n");
	write("seems to have dried up. The book binding is the only thing on this\n");
	write("book that looks like it is in excellent condition. Maybe you could\n");
	write("'read' the 'book' and learn more of what it is about.\n");
}

get() {
   return 1;
}

drop() {
   return 1;
}

reset(arg){
	if(arg) return;
	set_heart_beat(1);
        call_out("bsave", 300);
}

bsave(){
	save_object(BOOKPATH+environment(this_object())->query_real_name());
	return 1;
}

init() {
	if(!environment()) return;
	restore_object(BOOKPATH+environment(this_object())->query_real_name());
	if(environment(this_object())->query_level() < 1000){
		environment(this_object())->set_guild_name(0);
                environment(this_object())->set_guild_file(basename(this_object()));
	}
	
	add_action("read", "read");
	add_action("teleport", "teleport");
	add_action("review", "review");
	add_action("bsave", "bsave");
	add_action("check", "check");
	add_action("quit", "quit");
	add_action("drop_book", "i_am_no_elementalist");
}

check()
{
	if(!air)
	{
		write("Aeolos still requires your help.\n");
	}
	
	if(!earth)
	{
		write("Aatami still requires your help.\n");
	}
	
	if(!fire)
	{
		write("Adroushan still requires your help.\n");
	}
	
	if(!water)
	{
		write("Glyndwr still requires your help.\n");
	}
	return 1;
}

review(str)
{
	if(!str)
	{
		write("You can only review 'air', 'earth', 'fire', or 'water'\n");
		return 1;
	}
	
	if(str != "air" && str != "earth" && str != "fire" && str != "water")
	{
		write("You can only review 'air', 'earth', 'fire', or 'water'\n");
		return 1;
	}
	
	if(str == "air")
	{
		if(air)
		{
			write("You've already finished Aeolos' task.\n");
			return 1;
		}
		
		if(!air)
		{
			write("Aeolos wants you to find the Lightning Elemental that resides\n");
			write("near \"He Who Must Wait\" and bring back the Bolt of Lightning.\n");
			return 1;
		}
		return 1;
	}
	
	if(str == "earth")
	{
		if(earth)
		{
			write("You've already done Aatami's task.\n");
			return 1;
		}
		
		if(!earth)
		{
			write("Aatami wants you to find Ragnok the Geomancer deep within the\n");
			write("Storm Mountains and bring back his Robes of the Earth.\n");
			return 1;
		}
		return 1;
	}
	
	if(str == "fire")
	{
		if(fire)
		{
			write("You've already done Adroushan's task.\n");
			return 1;
		}
		
		if(!fire)
		{
			write("Adroushan wants you to adventure into the Elemental Tower and\n");
			write("find Saal, the fire lord. Kill him and bring back his eyes of fire.\n");
			return 1;
		}
		return 1;
	}
	
	if(str == "water")
	{
		if(water)
		{
			write("You've already done Glyndwr's task.\n");
			return 1;
		}
		
		if(!water)
		{
			write("Glyndwr wants you to find the Troglodyte King that holds the\n");
			write("Tsunami weapon. Kill him and bring the weapon to Glyndwr.\n");
			return 1;
		}
		return 1;
	}
	return 1;
}

drop_book()
{
	write("You decide to not become an Elementalist.\n");
	destruct(this_object());
	this_player()->set_guild_name(0);
	this_player()->set_guild_file(0);
	return 1;
}

read(str)
{
	if(!str)
	{
		write("Usage: 'read book'\n");
		return 1;
	}
	
	if(str != "book")
	{
		write("Usage: 'read book'\n");
		return 1;
	}
	
	if(str == "book")
	{
		cat("/players/wicket/guild/help/book/basic.txt");
		return 1;
	}
	return 1;
}

quit()
{
	save_object(BOOKPATH+environment()->query_real_name());
	this_player()->do_quit();
    return 1;
}

teleport()
{
	object player;
	string name;
	
	if(!this_player()->realm() == "NT")
	{
		write("Khnum exclaims, \"You can't teleport from there! There's too many magical energies interfering!\"\n");
		return 1;
	}
	
 	if(environment(this_player())->query_elemental_guild())
 	{
	 	write("Khnum taps you on your shoulder and says, \"You are already here...\"\n");
	 	return 1;
 	}
	
 	player = this_player();
 	name = player->query_real_name();
	this_player()->move_player("through a portal#/players/wicket/guild/hall/rooms/entrance.c");
	say("The portal closes behind "+this_player()->query_name()+".\n");
	if(!firsttime)
	{
		command("recruit_process", player);
		firsttime = 1;
		return 1;
	}
	return 1;
}

query_fire() { return fire; }
set_fire(int x) { fire = x; }
query_water() { return water; }
set_water(int x) { water = x; }
query_air() { return air; }
set_air(int x) { air = x; }
query_earth() { return earth; }
set_earth(int x) { earth = x; }
