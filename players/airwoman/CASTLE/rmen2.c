inherit "room/room";

object corpse;
reset(arg){

	if(!present("corpse")){
       corpse = clone_object("players/airwoman/MONSTER/frost");
	move_object(corpse, this_object());
     }
    if (!arg){
	set_light(1);
	short_desc = "Room north 2 on the east";
        long_desc =
	"OH my gawd!  Look at.......\n"+
	"The road less taken and this is what happens...\n"+
        "The grass seems to grow beyond your height as you look further\n"+
	"north.  Do you dare eat a peach?  Do you dare venture further north?\n";
	dest_dir =
	({"players/airwoman/CASTLE/rmen1", "south",
	"players/airwoman/CASTLE/rmen3", "north"});
}

}
