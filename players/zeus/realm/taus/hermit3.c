inherit "room/room";
#include "/players/zeus/closed/all.h"

int teleport, searched;

reset(arg){

 teleport = 0;  if(random(TFL_TLP)) teleport = 1;
 searched = 0;  /* haven't */

 if(arg) return;
 short_desc="The Fallen Lands";
 long_desc=
"You are in a small clearing behind the shack.  There are towering trees\n"+
"all around, some growing just feet from the old building.  Many full\n"+
"plants are crowding in around the area.  There is a small puddle in the\n"+
"ground, full of dirty brown water.  The only way out is to go back around\n"+
"the shack.\n";
 set_light(1);
 items=({
	 "clearing",
"This is a very small clearing just behind the old shack.  Enough light\n"+
"is getting through the canopy of branches above to allow you to see",
	 "trees",
"In every direction towering evergreen trees can be seen climbing high\n"+
"into the sky, their branches fanning out over you",
	 "branches",
"The branches of the evergreen trees fan out over the forest, creating a\n"+
"canopy which blocks out much of the sky",
	 "canopy",
"The branches create a thick canopy which blocks out much of the sky.\n"+
"There is a patch of blue sky visible almost directly above you",
	 "sky",
"The beautiful blue sky is painstakingly hard to see through the branches",
	 "plants",
"The full green plants make the small clearing very distinct.  The wall\n"+
"of plants is surrounding the area on all sides",
	 "puddle",
"The puddle of brown water looks fairly deep, however you can't actually\n"+
"see the bottom because the water is so thick looking",
	 "water",
"The water in the puddle is very thick and is actually mostly dirt",
	 "shack",
"The old shack is to the east.  A small path is leading back around it\n"+
"to the front.  There are no windows or doors on this side of the shack",
 });
 dest_dir=({ "/players/zeus/realm/taus/hermit1.c", "back",  });
}

void init(){
	::init();
	add_action("search_cmd", "search");
	add_action("dive_cmd", "dive");
}

exit(){    if(TP) TP->clear_fight_area();     }
realm(){   if(teleport) return "NT";    }
okay_follow(){ return 1; }

status search_cmd(string str){
	if(!str){
		write("You search the room generally and discover nothing.\n");
		return 1;
	}
	if((str == "puddle" || str == "water") && !searched){
		if(random(4)){
			write("You drag your hand through the water and find nothing.\n");
			searched = 0;
			return 1;
		}
		else {
			write("You plunge your hand into the puddle....\n"+
				"It goes down as far as you can reach...\n"+
				"You have the bizarre feeling you could 'dive' into it.\n");
			searched = 1;
			return 1;
		}
		return 1;
	}
	if((str == "puddle" || str == "water") && searched){
		write(
"Staring at the puddle, you feel as though you could 'dive' into it.\n");
		return 1;
	}
	else return 0;
	return 1;
}

status dive_cmd(){
	if(!searched) return 0;
	write("You dive into the puddle...\n");
	TP->MP("into the puddle#/players/zeus/realm/taus/puddle.c");
	return 1;
}