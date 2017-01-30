inherit "/room/room";
#include <ansi.h>
#include "../../defs.h"

reset(arg)
{
::reset(arg);

if(!present("element fire")){
	move_object(clone_object(HALLNPC+"firetrainer.c"), this_object());
}

if(arg) return;
        set_light(1);
        short_desc = "An Ancient Room of "+RED+"El"+YEL+"em"+GRN+"en"+CYN+"ts "+NORM+"("+RED+"Fire"+NORM+")";
        long_desc =
	        "A room of blazing for that radiates immense heat and power.\n"+
	        "Fire dances around the room and and flickers and flare. Strange\n"+
	        "enough the room is at a constant shift of colors as the flames\n"+
	        "bounce from blue and read to orange. The fire just spins and whips\n"+
	        "as if it has a mind if its own.\n";
                
        dest_dir =
({
        HALLRMS+"entrance.c",  "south",
        });
}

realm(){ return "NT"; }
query_no_fight(){ return 1; }


init(){
	::init();
	
	add_action("train", "train");
}

train(){
	object gob;
	
	gob = present("wicket_element_orb", this_player());
	
	if(!gob) return;
	
	if(!present("element fire"))
	{
		write("The element is not here to train.\n");
		return 1;
	}
	
	if(gob->query_FIRE() == 0){
		if(this_player()->query_free_exp() < GLVL1COST){
			write("You do not have the extra experience for that.\n");
			return 1;
		}
		
		if(this_player()->query_free_exp() >= GLVL1COST){
			write("You are trained in the art of the Fire Elementals.\n");
			write(RED+"\n\n\nYOU HAVE ADVANCED YOUR FIRE SPELLS TO GLVL 1!\n\n\n"+NORM);
			gob->add_FIRE(1);
			this_player()->add_exp(-GLVL1COST);
			command("gsave", this_player());
			return 1;
		}
	}
	else if(gob->query_FIRE() == 1){
		if(this_player()->query_free_exp() < GLVL2COST){
			write("You do not have the extra experience for that.\n");
			return 1;
		}
		
		if(this_player()->query_free_exp() >= GLVL2COST){
			write("You are trained in the art of the Fire Elementals.\n");
			write(RED+"\n\n\nYOU HAVE ADVANCED YOUR FIRE SPELLS TO GLVL 2!\n\n\n"+NORM);
			gob->add_FIRE(1);
			this_player()->add_exp(-GLVL2COST);
			command("gsave", this_player());
			return 1;
		}
	}
	
	else if(gob->query_FIRE() == 2){
		if(this_player()->query_free_exp() < GLVL3COST){
			write("You do not have the extra experience for that.\n");
			return 1;
		}
		
		if(this_player()->query_free_exp() >= GLVL3COST){
			write("You are trained in the art of the Fire Elementals.\n");
			write(RED+"\n\n\nYOU HAVE ADVANCED YOUR FIRE SPELLS TO GLVL 3!\n\n\n"+NORM);
			gob->add_FIRE(1);
			this_player()->add_exp(-GLVL3COST);
			command("gsave", this_player());
			return 1;
		}
	}
		
	else if(gob->query_FIRE() == 3){
		if(this_player()->query_free_exp() < GLVL4COST){
			write("You do not have the extra experience for that.\n");
			return 1;
		}
		
		if(this_player()->query_free_exp() >= GLVL4COST){
			write("You are trained in the art of the Fire Elementals.\n");
			write(RED+"\n\n\nYOU HAVE ADVANCED YOUR FIRE SPELLS TO GLVL 4!\n\n\n"+NORM);
			gob->add_FIRE(1);
			this_player()->add_exp(-GLVL4COST);
			command("gsave", this_player());
			return 1;
		}
	}
		
	else if(gob->query_FIRE() == 4){
		if(this_player()->query_free_exp() < GLVL5COST){
			write("You do not have the extra experience for that.\n");
			return 1;
		}
		
		if(this_player()->query_free_exp() >= GLVL5COST){
			write("You are trained in the art of the Fire Elementals.\n");
			write(RED+"\n\n\nYOU HAVE ADVANCED YOUR FIRE SPELLS TO GLVL 5!\n\n\n"+NORM);
			gob->add_FIRE(1);
			this_player()->add_exp(-GLVL5COST);
			command("gsave", this_player());
			return 1;
		}
	}
		
	else if(gob->query_FIRE() == 5){
		if(this_player()->query_free_exp() < GLVL6COST){
			write("You do not have the extra experience for that.\n");
			return 1;
		}
		
		if(this_player()->query_free_exp() >= GLVL6COST){
			write("You are trained in the art of the Fire Elementals.\n");
			write(RED+"\n\n\nYOU HAVE ADVANCED YOUR FIRE SPELLS TO GLVL 6!\n\n\n"+NORM);
			gob->add_FIRE(1);
			this_player()->add_exp(-GLVL6COST);
			command("gsave", this_player());
			return 1;
		}
	}
	
	else if(gob->query_FIRE() == 6){
		if(this_player()->query_free_exp() < GLVL7COST){
			write("You do not have the extra experience for that.\n");
			return 1;
		}
		
		if(this_player()->query_free_exp() >= GLVL7COST){
			write("You are trained in the art of the Fire Elementals.\n");
			write(RED+"\n\n\nYOU HAVE ADVANCED YOUR FIRE SPELLS TO GLVL 7!\n\n\n"+NORM);
			write(RED+"\n\n\nYOU HAVE MASTERED THE ART OF THE FIRE ELEMENTALS!!!\n\n\n"+NORM);
			gob->add_FIRE(1);
			this_player()->add_exp(-GLVL7COST);
			command("gsave", this_player());
			return 1;
		}
	}
	
	else if(gob->query_FIRE() == 7){
		write("You have already mastered the art of the Fire Elementals!\n");
		return 1;
	}
	return 1;
}