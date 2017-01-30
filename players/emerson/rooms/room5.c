inherit "room/room";
 
reset(arg) {
    object customer;
    int abc;
    if(arg) return;
    set_light(1);
   long_desc = "You have come to a hallway in the back of the dining area.\n" +
   "To the north is a door with a sign reading MEN ONLY and to the south\n" +
   "is a door with a sign reading WOMEN ONLY\n";
   short_desc = "The Dining Area";
    dest_dir = ({ "/players/emerson/rooms/mbath.c","north",
                 "/players/emerson/rooms/fbath.c","south",
                  "/players/emerson/rooms/room4.c","east"});

    abc = 0;
    if (!present("customer")) 
     {
      while(abc<5) 
       {
        abc += 1;
        customer=clone_object("players/emerson/closed/customer.c");
        move_object(customer,this_object());
       }
     }
}
