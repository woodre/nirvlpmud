inherit "room/room";
 
reset(arg) {
    object customer;
    int abc;
    if(arg) return;
    set_light(1);
   long_desc = "You are in the waiting room of Pizza Hut. You watch as\n" +
   "the customers wait for a table to become available. To the south you see\n" +
   "a door with a sign that reads EMPLOYEES ONLY\n";
   short_desc = "The Waiting Room";
    dest_dir = ({ "/players/emerson/rooms/enter.c","east",
                  "/players/emerson/rooms/room21.c","south"});

    abc = 0;
    if (!present("customer")) 
     {
      while(abc<5) 
       {
        abc += 1;
        customer=clone_object("players/emerson/closed/patron.c");
        move_object(customer,this_object());
       }
     }
}
