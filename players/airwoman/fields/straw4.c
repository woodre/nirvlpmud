inherit "room/room";
object bmuff;
reset(arg){  
        if(!present("muffin")){
            bmuff = clone_object("players/airwoman/MONSTER/bmuff");
            move_object(bmuff, this_object());
            }
        if(!arg){
        set_light(1);
        short_desc="fields room 4";
        long_desc=
        "hmmm... The smell of blueberries.....\n"+
        "YUM YUM...And there's Blueberry Muffin.....\n"+
        "Look at her eyes...\n"+ 
        "\n\n";
        dest_dir = ({"players/airwoman/fields/straw3", "west"});
        }
}
