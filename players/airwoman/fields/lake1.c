inherit "room/room";
 
reset(arg){  
           
        if(!arg){
        set_light(1);
        short_desc="lake 1";
        long_desc=
        "Looking further west you see a lake.\n"+
        "Perhaps you should go further west to take a look\n"+
        "at the lake?...\n\n";
        dest_dir = ({"players/airwoman/fields/straw1", "east",
                     "players/airwoman/fields/lake2", "west"});
        }
}
