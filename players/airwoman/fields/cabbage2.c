inherit "room/room";
object cpatch;
reset(arg){ 
        int i;
        i=0;
     
        if(!present("kid")){
            while (i<10) {
           i+=1;
            cpatch = clone_object("players/airwoman/MONSTER/cpatch");
            move_object(cpatch, this_object());
            }                  
          }
        if(!arg){
        set_light(1);
        short_desc="cabbage room 2";
        long_desc=
        "YECK!  Cabbage Patch Kids !....\n"+
        "Kill these little overrated things...\n"+
        "Dont know why people were crazy about them in the first "+ 
        "place.\n\n";
        dest_dir = ({"players/airwoman/fields/cabbage1", "east",
                     "players/airwoman/fields/onion1", "south"});
        }
}
