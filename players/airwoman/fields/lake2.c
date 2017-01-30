inherit "room/room";
 
reset(arg){  
           
        if(!arg){
        set_light(1);
        short_desc="lake 2";
        long_desc=
        "You are at the edge of the lake.\n"+
        "Looking down at the lake you see a reflection of\n"+
         "yourself...(ugly of course)...anyways..\n"+
        "Across the lake you see a tiny little lodge.\n"+
        "But the only way to get across there is probably to"+
        " swim.\n";
        dest_dir = ({"players/airwoman/fields/lake1", "east"});
        }
}
 
init()
{
  add_action("swim","swim");
  ::init();
}
 
swim()
   {
        write("You jump into the lake!?!?!?!\n\n\n\n");
        write("Your feet start to kick and you swim...\n\n\n");
        write("Swimming faster and harder as you quickly end up "+
        "up on the other side of the lake\n\n\n\n");
        this_player()->move_player(" into#players/airwoman/fields/prarie1");
        return 1;
    }
