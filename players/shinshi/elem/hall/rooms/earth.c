inherit "/room/room";
#include <ansi.h>
#include "../../defs.h"

reset(arg)
{
::reset(arg);

if(!present("element earth")){
	move_object(clone_object(HALLNPC+"earthtrainer.c"), this_object());
}

if(arg) return;
        set_light(1);
        short_desc = "An Ancient Room of "+RED+"El"+YEL+"em"+GRN+"en"+CYN+"ts "+NORM+"("+GRN+"Earth"+NORM+")";
        long_desc =
	        "An ancient room of stone and earth that vibrates of pure\n"+
	        "energy. Grass seems to grow on the floor of the room as\n"+
	        "the smell of fresh soil fills the air. Diamonds and gemstones\n"+
	        "in the walls catch the light from within the room and glisten\n"+
	        "and shine with pure beauty. The Earth on the floor and walls\n"+
	        "hum with pure energy and power.\n";
        dest_dir =
({
        HALLRMS+"entrance.c",  "north",
        });
}

realm(){ return "NT"; }
query_no_fight(){ return 1; }
query_elemental_guild() { return 1; }

init(){
	::init();
	
	add_action("train", "train");
}

train(){
	object gob;
	
	gob = present("wicket_element_orb", this_player());
	
	if(!gob) return;
	
	if(!present("element earth"))
	{
		write("The element is not here to train.\n");
		return 1;
	}
	
	if(gob->query_EARTH() == 0){
		if(this_player()->query_free_exp() < GLVL1COST){
			write("You do not have the extra experience for that.\n");
			return 1;
		}
		
		if(this_player()->query_free_exp() >= GLVL1COST){
			write("You are trained in the art of the EARTH Elementals.\n");
			write(RED+"\n\n\nYOU HAVE ADVANCED YOUR EARTH SPELLS TO GLVL 1!\n\n\n"+NORM);
			gob->add_EARTH(1);
			this_player()->add_exp(-GLVL1COST);
			command("gsave", this_player());
			return 1;
		}
	}
	else if(gob->query_EARTH() == 1){
		if(this_player()->query_free_exp() < GLVL2COST){
			write("You do not have the extra experience for that.\n");
			return 1;
		}
		
		if(this_player()->query_free_exp() >= GLVL2COST){
			write("You are trained in the art of the EARTH Elementals.\n");
			write(RED+"\n\n\nYOU HAVE ADVANCED YOUR EARTH SPELLS TO GLVL 2!\n\n\n"+NORM);
			gob->add_EARTH(1);
			this_player()->add_exp(-GLVL2COST);
			command("gsave", this_player());
			return 1;
		}
	}
	
	else if(gob->query_EARTH() == 2){
		if(this_player()->query_free_exp() < GLVL3COST){
			write("You do not have the extra experience for that.\n");
			return 1;
		}
		
		if(this_player()->query_free_exp() >= GLVL3COST){
			write("You are trained in the art of the EARTH Elementals.\n");
			write(RED+"\n\n\nYOU HAVE ADVANCED YOUR EARTH SPELLS TO GLVL 3!\n\n\n"+NORM);
			gob->add_EARTH(1);
			this_player()->add_exp(-GLVL3COST);
			command("gsave", this_player());
			return 1;
		}
	}
		
	else if(gob->query_EARTH() == 3){
		if(this_player()->query_free_exp() < GLVL4COST){
			write("You do not have the extra experience for that.\n");
			return 1;
		}
		
		if(this_player()->query_free_exp() >= GLVL4COST){
			write("You are trained in the art of the EARTH Elementals.\n");
			write(RED+"\n\n\nYOU HAVE ADVANCED YOUR EARTH SPELLS TO GLVL 4!\n\n\n"+NORM);
			gob->add_EARTH(1);
			this_player()->add_exp(-GLVL4COST);
			command("gsave", this_player());
			return 1;
		}
	}
		
	else if(gob->query_EARTH() == 4){
		if(this_player()->query_free_exp() < GLVL5COST){
			write("You do not have the extra experience for that.\n");
			return 1;
		}
		
		if(this_player()->query_free_exp() >= GLVL5COST){
			write("You are trained in the art of the EARTH Elementals.\n");
			write(RED+"\n\n\nYOU HAVE ADVANCED YOUR EARTH SPELLS TO GLVL 5!\n\n\n"+NORM);
			gob->add_EARTH(1);
			this_player()->add_exp(-GLVL5COST);
			command("gsave", this_player());
			return 1;
		}
	}
		
	else if(gob->query_EARTH() == 5){
		if(this_player()->query_free_exp() < GLVL6COST){
			write("You do not have the extra experience for that.\n");
			return 1;
		}
		
		if(this_player()->query_free_exp() >= GLVL6COST){
			write("You are trained in the art of the EARTH Elementals.\n");
			write(RED+"\n\n\nYOU HAVE ADVANCED YOUR EARTH SPELLS TO GLVL 6!\n\n\n"+NORM);
			gob->add_EARTH(1);
			this_player()->add_exp(-GLVL6COST);
			command("gsave", this_player());
			return 1;
		}
	}
	
	else if(gob->query_EARTH() == 6){
		if(this_player()->query_free_exp() < GLVL7COST){
			write("You do not have the extra experience for that.\n");
			return 1;
		}
		
		if(this_player()->query_free_exp() >= GLVL7COST){
			write("You are trained in the art of the EARTH Elementals.\n");
			write(RED+"\n\n\nYOU HAVE ADVANCED YOUR EARTH SPELLS TO GLVL 7!\n\n\n"+NORM);
			write(RED+"\n\n\nYOU HAVE MASTERED THE ART OF THE EARTH ELEMENTALS!!!\n\n\n"+NORM);
			gob->add_EARTH(1);
			this_player()->add_exp(-GLVL7COST);
			command("gsave", this_player());
			return 1;
		}
	}
	
	else if(gob->query_EARTH() == 7){
		write("You have already mastered the art of the EARTH Elementals!\n");
		return 1;
	}
	return 1;
}
