inherit "room/room";
object david;
reset(arg){  
        if(!present("david")){
           david = clone_object("players/airwoman/MONSTER/david");
           move_object(david, this_object());
           }       
 
        if(!arg){
        set_light(1);
        short_desc="prarie 2";
        long_desc=
        "We finally meet the Romantic King....\n"+
        "Henry David Thoreau...Simplicity simplicity simplicity\n"+
         "He lives in the woods.  Read his book Walden\n"+
        "He sits here getting a sun tan of course.\n"+
        "The lodge is right in front of your face.\n";
        dest_dir = ({"players/airwoman/fields/prarie1", "south",
                     "players/airwoman/fields/pigroom", "east",
                     "players/airwoman/fields/lodge", "enter"});
        }
}
