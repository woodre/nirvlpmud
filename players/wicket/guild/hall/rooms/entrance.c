inherit "/room/room";
#include <ansi.h>
#include "../../defs.h"

reset(arg) {
		if (!present("board")) {
		move_object(clone_object("/players/wicket/guild/hall/objs/board2.c"), this_object());
	}
::reset(arg);
if(!present("khnum", this_object()))move_object(clone_object("/players/wicket/guild/hall/mobs/master.c"), this_object());
if(arg) return;
  set_light(1);
  short_desc = "The Cathedral of "+RED+"El"+YEL+"em"+GRN+"en"+CYN+"ts"+NORM;
  long_desc = 
  "An Ancient room within the elemental guild. This room radiates the \n"+
  "power of the four ancient elements of earth, air, fire, and water. The\n"+
  "energy can be felt tugging from several directions into other rooms.\n"+
  "The ancient symbol of fire is carved into the north end of the room\n"+
  "and ancient symbol of earth can be seen in the southern side of the room.\n"+
  "To the east side of the room the ancient symbol of water is also engraved\n"+
  "into the floor and to the west the  ancient symbol of air appears on the\n"+
  "floor. A beam of massive energy floods and lights the room from the\n"+
  "skylight in the center of the room.\n";
                
    dest_dir =
({
    HALLRMS+"fire.c",   "north",
    HALLRMS+"water.c",	 "east",
    HALLRMS+"earth.c",  "south",
    HALLRMS+"air.c",	 "west",
    HALLRMS+"elderplace.c",	 "up",
	"/players/pestilence/hall.c",	"down",
        
    });
}

realm(){ return "NT"; }
query_no_fight(){ return 1; }
query_elemental_guild() { return 1; }

init(){
	::init();
	
	add_action("move_up", "up");
	add_action("raise_mag", "raise");
}

move_up(){
	object ob, gob;
	
	ob = this_player();
	
	gob = present("wicket_element_orb", ob);
	
	if(!gob)
	{
		write("You are not yet an Elementalist!\n");
		return 1;
	}
	
	if(!gob->query_elder()){
		write("You are not an Elder and may not continue.\n");
		return 1;
	}
	
	if(gob->query_elder()){
		write("You have gained access to the Room of Elders.\n");
		say(ob->query_name()+" is granted access to the Room of Elders.\n");
		move_object(ob, HALLRMS+"elderplace.c");
		command("look", ob);
		return 1;
	}
	return 1;
}

raise_mag(str){
	int mag, freexp, max;
	
	if(!str){
		write(BOLD+"Khnum"+NORM+", "+HIW+"Ancient Master "+NORM+"of the "+RED+"El"+YEL+"em"+GRN+"en"+CYN+"ts"+NORM+" says, \"I can only teach you to learn more magic aptitude.\"\n");
		return 1;
	}
	
	if(str != "mag"){
		write("Try just typing 'raise mag'\n");
		return 1;
	}
	
	mag = this_player()->query_attrib("mag");
	freexp = this_player()->query_free_exp();
	
	if(str == "mag"){
		if(mag < 30){
			write(BOLD+"Khnum"+NORM+", "+HIW+"Ancient Master "+NORM+"of the "+RED+"El"+YEL+"em"+GRN+"en"+CYN+"ts"+NORM+" says, \"You must advance first at the adventurers guild.\"\n");
			return 1;
		}
		
		if(mag > 49){
			write("Khnum smacks you across the face.\n");
			write(BOLD+"Khnum"+NORM+", "+HIW+"Ancient Master "+NORM+"of the "+RED+"El"+YEL+"em"+GRN+"en"+CYN+"ts"+NORM+" says, \"You can only go to a maximum of 50!\"\n");
			return 1;
		}
		
		if(freexp < 50000){
			write("Khnum smacks you across the face.\n");
			write(BOLD+"Khnum"+NORM+", "+HIW+"Ancient Master "+NORM+"of the "+RED+"El"+YEL+"em"+GRN+"en"+CYN+"ts"+NORM+" says, \"You do not have enough experience yet!\"\n");
			return 1;
		}
		
		max = mag + 1;
		this_player()->add_exp(-50000);
		this_player()->set_attrib("mag", max);
		write("Khnum smiles and teaches you the way of his magic!\n");
		return 1;
	}
	return 1;
}
		
	
	
