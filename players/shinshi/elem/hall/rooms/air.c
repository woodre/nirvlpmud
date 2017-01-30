inherit "/room/room";
#include <ansi.h>
#include "../../defs.h"

reset(arg)
{
::reset(arg);
if(!present("element air", this_object()))move_object(clone_object("/players/wicket/guild/hall/mobs/airtrainer.c"), this_object());
if(arg) return;
        set_light(1);
        short_desc = "An Ancient Room of "+RED+"El"+YEL+"em"+GRN+"en"+CYN+"ts "+NORM+"("+YEL+"Air"+NORM+")";
        long_desc =
		    "An ancient room that is flooded with gust of air. This is a very\n"+
		    "ancient spot where the generations of Elementalists come to train\n"+
		    "in the abilities of air. The strength of the wind just whirls about\n"+
		    "beckoning any life to flow with its movements as it radiates pure\n"+
		    "power and energy.\n";
                
        dest_dir =
({
        HALLRMS+"entrance.c",  "east",
        });
}

query_elemental_guild() { return 1; }

init(){
	::init();
	
	add_action("train", "train");
}

train(){
	object gob;
	
	gob = present("wicket_element_orb", this_player());
	
	if(!gob) return;
	
	if(gob->query_AIR() == 0){
		if(this_player()->query_free_exp() < GLVL1COST){
			write("You do not have the extra experience for that.\n");
			return 1;
		}
		
		if(this_player()->query_free_exp() >= GLVL1COST){
			write("You are trained in the art of the AIR Elementals.\n");
			write(RED+"\n\n\nYOU HAVE ADVANCED YOUR AIR SPELLS TO GLVL 1!\n\n\n"+NORM);
			gob->add_AIR(1);
			this_player()->add_exp(-GLVL1COST);
			command("gsave", this_player());
			return 1;
		}
	}
	else if(gob->query_AIR() == 1){
		if(this_player()->query_free_exp() < GLVL2COST){
			write("You do not have the extra experience for that.\n");
			return 1;
		}
		
		if(this_player()->query_free_exp() >= GLVL2COST){
			write("You are trained in the art of the AIR Elementals.\n");
			write(RED+"\n\n\nYOU HAVE ADVANCED YOUR AIR SPELLS TO GLVL 2!\n\n\n"+NORM);
			gob->add_AIR(1);
			this_player()->add_exp(-GLVL2COST);
			command("gsave", this_player());
			return 1;
		}
	}
	
	else if(gob->query_AIR() == 2){
		if(this_player()->query_free_exp() < GLVL3COST){
			write("You do not have the extra experience for that.\n");
			return 1;
		}
		
		if(this_player()->query_free_exp() >= GLVL3COST){
			write("You are trained in the art of the AIR Elementals.\n");
			write(RED+"\n\n\nYOU HAVE ADVANCED YOUR AIR SPELLS TO GLVL 3!\n\n\n"+NORM);
			gob->add_AIR(1);
			this_player()->add_exp(-GLVL3COST);
			command("gsave", this_player());
			return 1;
		}
	}
		
	else if(gob->query_AIR() == 3){
		if(this_player()->query_free_exp() < GLVL4COST){
			write("You do not have the extra experience for that.\n");
			return 1;
		}
		
		if(this_player()->query_free_exp() >= GLVL4COST){
			write("You are trained in the art of the AIR Elementals.\n");
			write(RED+"\n\n\nYOU HAVE ADVANCED YOUR AIR SPELLS TO GLVL 4!\n\n\n"+NORM);
			gob->add_AIR(1);
			this_player()->add_exp(-GLVL4COST);
			command("gsave", this_player());
			return 1;
		}
	}
		
	else if(gob->query_AIR() == 4){
		if(this_player()->query_free_exp() < GLVL5COST){
			write("You do not have the extra experience for that.\n");
			return 1;
		}
		
		if(this_player()->query_free_exp() >= GLVL5COST){
			write("You are trained in the art of the AIR Elementals.\n");
			write(RED+"\n\n\nYOU HAVE ADVANCED YOUR AIR SPELLS TO GLVL 5!\n\n\n"+NORM);
			gob->add_AIR(1);
			this_player()->add_exp(-GLVL5COST);
			command("gsave", this_player());
			return 1;
		}
	}
		
	else if(gob->query_AIR() == 5){
		if(this_player()->query_free_exp() < GLVL6COST){
			write("You do not have the extra experience for that.\n");
			return 1;
		}
		
		if(this_player()->query_free_exp() >= GLVL6COST){
			write("You are trained in the art of the AIR Elementals.\n");
			write(RED+"\n\n\nYOU HAVE ADVANCED YOUR AIR SPELLS TO GLVL 6!\n\n\n"+NORM);
			gob->add_AIR(1);
			this_player()->add_exp(-GLVL6COST);
			command("gsave", this_player());
			return 1;
		}
	}
	
	else if(gob->query_AIR() == 6){
		if(this_player()->query_free_exp() < GLVL7COST){
			write("You do not have the extra experience for that.\n");
			return 1;
		}
		
		if(this_player()->query_free_exp() > GLVL7COST){
			write("You are trained in the art of the AIR Elementals.\n");
			write(RED+"\n\n\nYOU HAVE ADVANCED YOUR AIR SPELLS TO GLVL 7!\n\n\n"+NORM);
			write(RED+"\n\n\nYOU HAVE MASTERED THE ART OF THE AIR ELEMENTALS!!!\n\n\n"+NORM);
			gob->add_AIR(1);
			this_player()->add_exp(-GLVL7COST);
			command("gsave", this_player());
			return 1;
		}
	}
	
	else if(gob->query_AIR() == 7){
		write("You have already mastered the art of the AIR Elementals!\n");
		return 1;
	}
	return 1;
}
