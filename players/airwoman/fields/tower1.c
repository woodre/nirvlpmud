inherit "room/room";
 
reset(arg){  
           
        if(!arg){
        set_light(1);
        short_desc="tower 1";
        long_desc=
        "You are standing at the bottom of a water tower.\n"+
        "You are crazy if you are thinking of going up.\n"+
        "There's nothing up there really.  You've seen\n"+
        "lots and lots of them before.\n";
        dest_dir = ({"players/airwoman/fields/tower2", "up",
                     "players/airwoman/fields/cotton3", "east"});
        }
}
