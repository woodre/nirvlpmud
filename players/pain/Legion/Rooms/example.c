int a;
inherit "room/room";
 
reset(arg) {
        object bed;
    if(arg) return;
    set_light(1);
   a=0;
   long_desc = "You're in a comfortable and lowlit room,you feel someway healed by the restful\n"+
        "atmosphere that surrounds you. The room has wooden walls and a stone chimney\n"+
        "in which a red and warm fire is lit and Trix comes here when he's tired of the\n"+
         "real world.\n";
   short_desc = "A room";
    dest_dir = ({ "/players/trix/workroom.c", "east"});
    items = ({ "picture", "Trix's picture : he's handsome and in a good mood!" });
        bed = clone_object( "/players/trix/closed/obj/bed.c" );
        move_object( bed, this_object() );
}
