inherit "room/room";
 
reset(arg) {
    object customer;
    int abc;
    if(arg) return;
    set_light(1);
   long_desc = "You are in the dining area of Pizza Hut.  You watch as the customers enjoy their\n" +
   "hot slices of pizza.  You begin to feel hunger pains building inside you, maybe you should kill a customer and snag the pizza...\n";
   short_desc = "The Dining Area";
    dest_dir = ({ "/players/emerson/rooms/room3.c","north",
          "/players/emerson/rooms/dine3.c","east",
                  "/players/emerson/rooms/room5.c","west"});

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