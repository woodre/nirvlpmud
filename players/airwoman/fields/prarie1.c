inherit "room/room";
 
reset(arg){  
           
        if(!arg){
        set_light(1);
        short_desc="prarie room 1";
        long_desc=
        "You are at the edge of the lake.\n"+
        "Looking north you see a lodge.\n"+
         "Across the lake you see fields and fields of \n"+
        "fruits and vegetables.\n"+
	"You may swim to the underside if desired.\n";
        dest_dir = ({"players/airwoman/fields/prarie2", "north"});
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
this_player()->move_player("into#players/airwoman/fields/lake2"); 
               
        return 1;
    }
