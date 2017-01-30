inherit "room/room";
object daedalus;
reset(arg){  
        if(!present("daedalus")){
           daedalus = clone_object("players/airwoman/MONSTER/daedalus");
           move_object(daedalus, this_object());
           }       
 
        if(!arg){
        set_light(1);
        short_desc="tower 3";
        long_desc=
        "You have reached the top of the water tower.\n"+
        "Looking far beyond you can see the mountains.\n"+
        "The wind blows against you here.  You shudder a bit.\n";
        dest_dir = 
                   ({"players/airwoman/fields/tower2", "down"});
        }
}
