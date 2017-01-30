/*
*      Function:
*      Change History: NEED HIDDEN EXIT TO HALLWAY
*       ONE C.O.T.C. TAKES SPS, ONE DEALS A WOUND, ONE DISARMS, ONE DOES STRAIGHT DAMAGE
*/
#include <ansi.h>
inherit "/room/room";

int dead;

reset(arg)
{
::reset(arg);

if(arg) return;

set_light(1);

dead = 0;

short_desc = "A huge "+HIY+"corn field"+NORM+"";

long_desc =
	"Cornstalks fill your vision in what seems to be forever in any given\n"+
	"direction. You hear evil voices, but for some reason cannot make out\n"+
	"what they are saying. You try to run, but only find yourself deeper\n"+
	"and deeper in this immense corn field. There is alot of movement in\n"+
	"the stalks around you suddenly, and you feel you need to know if it's\n"+
	"something that may be an immediate threat.\n";

add_listen("voices", "You cannot decipher the strange, ominous mumbles and chatter.");
items =
({
	"cornstalks",
	"They fill the field for as far as the eye can see",
	"field",
	"You see the sheer vastness of it and realize you may never make it out",
	"movement",
	"What the hell was that..",
	});

dest_dir =
({
	"/players/chip/room/movies/room10.c",     "?????",
	});
		
}
void init(){::init();add_action("cmd_search", "search");}
status cmd_search(string str){
if(!str){
write("Are you SURE you want to know?\n");
return 1;
}
if(str == "field" && dead){
write("Merely stalks of corn for what looks to be miles.\n");
return 1;
}
if(str == "field" && !dead){
write("Several evil-looking youngsters with sharp objects leap out from the stalks around you\n");
move_object(clone_object("/players/chip/mobs/movies/cotc1.c"), this_object());
move_object(clone_object("/players/chip/mobs/movies/cotc2.c"), this_object());
move_object(clone_object("/players/chip/mobs/movies/cotc3.c"), this_object());
move_object(clone_object("/players/chip/mobs/movies/cotc4.c"), this_object());
dead = 1;
return 1;
}
}
