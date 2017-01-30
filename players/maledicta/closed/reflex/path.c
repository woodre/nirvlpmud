#include "/players/reflex/lib/include/ansi.h"
inherit "/players/vertebraker/closed/std/room";

reset(arg){
int blah;
   if(!present("templar_guard", this_object())){
    for(blah = 0; blah < 2; blah++){
    move_object(clone_object("/players/maledicta/cont/war/templar_guard.c"), this_object());
    }
   }
 if(arg) return;
    set_short("A path leading West");
    set_long(
        "You are on a path heading west to the coastal mountain range.\n"+
	"The sky is overcast and there is a brisk wind that chills you\n"+
	"to your bones.  The mountain range to the west is small, and\n"+
	"you can see a break in the hills leading to the coast.  To the\n"+
	"east the path widens and heads to the main village.  There is\n"+
	"no path to the north or south.\n");
    add_item("path","This is a dusty path leading east and west."); 
    add_item("mountain",
        "This is a small mountain range blocking your path to the west.\n"+
        "You think you could pass it by the small opening between two hills\n"+
	     "directly westward.");
    add_item("range",
        "This is a small mountain range blocking your path to the west.\n"+
        "You think you could pass it by the small opening between two hills\n"+
        "directly westward.");
    add_item("sky",
        "The sky is overcast and you can feel the slightest drizzel in the\n"+
	     "air around you.  It looks like rain is coming.");
    add_item("hills",
        "This is a small mountain range blocking your path to the west.\n"+
        "You think you could pass it by the small opening between two hills\n"+
	     "directly westward.");
    add_smell("main","You detect the slight smell of ozone in the salty sea air.");
	 add_smell("wind","It smells like rain is coming...");

    add_listen("default","You hear the sound of the breeze through the mountains ahead.");
	 add_listen("wind","You hear thunder in the distance to the west.");
	
    set_chance(10);
    add_msg("Thunder rumbles in the distance.");
	 add_msg("The wind whistles through the mountains to the west.");
	 add_msg("You hear armor clanging in the distance.");
	 add_msg("Lightning "+BOLD+YEL+"strikes"+NORM+" in the distance...");

    add_exit("/players/reflex/realms/coastline/pass_ent","west");
	 add_exit("/room/orc_dump","east");
       
    set_light(1);
    }


query_no_fight(){ return 1; }