inherit "room/room";
 
reset(arg){  
           
        if(!arg){
        set_light(1);
        short_desc="room 1 west:  Welcome to Mudville";
        long_desc= 
	"WELCOME to MUDville, CO.  Where mudder neanderthals\n"+
	"dwell.  Further west you can see a faint glimpse of\n"+
	"enchantment...\n\n";
        dest_dir = ({"players/airwoman/CASTLE/entrance", "east",
/* Exit commented out 5.23.01 by Vertebraker, redundant. */
/*
                     "players/airwoman/CASTLE/rm2w", "west",
*/
           });
        }
}
