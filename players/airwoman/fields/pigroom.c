inherit "room/room";
object pig;
reset(arg){                
        int i;
        i = 0;
        if(!present("pig")){
        while(i<13) {
        i +=1;
           pig = clone_object("players/airwoman/MONSTER/pig");
           move_object(pig, this_object());
           }       
           }
        if(!arg){
        set_light(1);
        short_desc="pig pen";
        long_desc=
        "HA!  You have encountered a pig pen!...\n"+
        "These pigs are locked in a pen.  Look at those dirty\n"+
        "pigs.  They are rolling all over the mud!  YECK!\n";
        dest_dir = ({"players/airwoman/fields/prarie2", "west"});
        }
}
