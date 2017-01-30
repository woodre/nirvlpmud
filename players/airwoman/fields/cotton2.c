inherit "room/room";
object moses;
reset(arg){  
        if(!present("moses")){
            moses = clone_object("players/airwoman/MONSTER/moses");
            move_object(moses, this_object());
            }
        if(!arg){
        set_light(1);
        short_desc="cotton fields 2";
        long_desc=
        "Cotton fields forever...It is the season to be\n"+
        "jolly fa la la la la la la la la....\n"+
        "Cotton picking season it is!\n\n\n";
        dest_dir = ({"players/airwoman/fields/cotton1", "west",
		     "players/airwoman/fields/cotton3", "north"});
        }
}
