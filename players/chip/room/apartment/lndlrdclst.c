      /*                                                                    
       *    File: /players/chip/room/apartment/lndlrdclst.c                
       *    Function: room
       *    Author(s): Chip@Nirvana       
       *    Copyright: Copyright (c) 2009 Chip      
       *               All Rights Reserved   
       *    Source: 5/13/09           
       *    Notes:  Added to expand on f3lndlrd.c in my                                                        
       *            my apartment area                                                        
       *                                                                    
       *    Change History:                                                 
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

short_desc = ""+HIK+"A dark closet"+NORM+"";

long_desc =
	"It is too dark to make anything out other than a cold spot\n"+
	"that can be felt right in the center of the closet.\n";

add_smell("mold", "The scent is strong and makes it difficult to breathe properly");
add_smell("urine", "The scent is strong and makes it difficult to breathe properly");
add_smell("death", "It really does smell as if something died in here");


items =
({
	"spot",
	"That is not something that can be seen, especially in this darkness",
	"cold spot",
	"That is not something that can be seen, especially in this darkness",
	});

dest_dir =
({
	"/players/chip/room/apartment/f3lndlrd.c",     "escape",
	});

}
void init(){::init();add_action("cmd_feel", "feel");}
status cmd_feel(string str){
if(!str){
write("Are you stupid?\n");
return 1;
}
if(str == "spot" && dead){
write("The cold spot seems to have dissipated.\n");
return 1;
}
if(str == "spot" && !dead){
write("A wispy spirit seems to form amidst the cold spot you just waved your hand through. It suddenly howls in rage!\n");
move_object(clone_object("/players/chip/mobs/apartment/lndlrdsprt.c"), this_object());
dead = 1;
return 1;
}
}
