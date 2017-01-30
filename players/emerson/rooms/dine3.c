inherit "room/room";
 
reset(arg) {
object customer,sonny;
    int abc;
    if(arg) return;
    set_light(1);
    long_desc = "There seem to be bullet holes in the walls of this room.\n"+
    "Maybe there was a gun fight between the mobsters in here!\n"+
     "Maybe you better get outta here before you get shot!\n";
   short_desc = "The Dining Area";
    dest_dir = ({ "/players/emerson/rooms/room4.c","west",
                  "/players/emerson/rooms/dine2.c","north"});

    sonny=clone_object("players/emerson/mons/sonny.c");
     move_object(sonny,this_object());

    abc = 0;
    if (!present("customer")) 
     {
      while(abc<3) 
       {
        abc += 1;
        customer=clone_object("players/emerson/closed/button.c");
        move_object(customer,this_object());
       }
     }
}
