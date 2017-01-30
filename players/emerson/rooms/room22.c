inherit "room/room";
 
reset(arg) {
    object customer;
  object manager;
    object driver;
    int abc;
    if(arg) return;
    set_light(1);
long_desc = "You have entered the back part of Pizza Hut where all the\n" +
            "managers and drivers hang out.\n";
short_desc ="The Back Room";
    dest_dir = ({ "/players/emerson/rooms/room21.c","east",
                  "/players/emerson/rooms/room23.c","west"});
manager=clone_object("players/emerson/mons/manager.c");
driver=clone_object("/players/emerson/mons/driver.c");
move_object(driver,this_object());
move_object(manager,this_object());

    abc = 0;
    if (!present("customer")) 
     {
      while(abc<3) 
       {
        abc += 1;
        customer=clone_object("players/emerson/mons/driverm.c");
        move_object(customer,this_object());
       }
     }
}
