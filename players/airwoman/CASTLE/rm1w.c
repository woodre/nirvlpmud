inherit "room/room";
 
reset(arg){  
           
        if(!arg){
        set_light(1);
        short_desc="room 1 west:  Welcome to Mudville";
        long_desc= 
	"WELCOME to MUDville, CO.  Where mudder neanderthals\n"+
        "dwell.  Under development.\n";
        dest_dir = ({"players/airwoman/CASTLE/entrance", "east",
/*
                     "players/airwoman/CASTLE/rm2w", "west"});
*/
           });
        }
}
