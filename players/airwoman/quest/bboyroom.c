inherit "room/room";
object bboy;
reset(arg){  
        if(!present("bboy")){
            bboy = clone_object("players/airwoman/quest/bboy");
            move_object(bboy, this_object());
            }
        if(!arg){
        set_light(1);
        short_desc="blind boy room";
        long_desc=
        "AHHH Finally you have reached the blind boy.\n"+
        "The blind boy is actually a genius.....\n"+
        "but by giving him his sight he can be a mega-genius!\n"+ 
        "Try to rub eyes with tears..\n"+
        "\n\n";
        dest_dir = ({"room/church", "church"});
        }
}
