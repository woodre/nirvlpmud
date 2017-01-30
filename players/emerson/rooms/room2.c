inherit "room/room";
 
reset(arg) {
    object customer,customer2;
    int abc;
    if(arg) return;
    set_light(1);
    long_desc ="You have entered the dining room, it seems to stretch\n"+
     "for miles around. You watch as the customers enjoy their pizza and\n"+
     "begin to feel a little hungry yourself...\n";
   short_desc = "The Dining Area";
    dest_dir = ({ "/players/emerson/rooms/enter.c","west",
           "players/emerson/rooms/dine1.c","east",
                  "/players/emerson/rooms/room3.c","south"});

	customer2=clone_object("players/emerson/mons/donald.c");
	move_object(customer2,this_object());
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
