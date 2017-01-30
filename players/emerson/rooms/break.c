inherit "room/room";
 
reset(arg) {
object customer,cooler,cook,driver,manager;
    if(arg) return;
    set_light(1);
     long_desc ="You have entered the break room where all the employees\n" +
    "come and relax on their breaks. They look very tired and don't look\n" +
      "like they want to be disturbed.\n";
     short_desc = "A Break Room";
   dest_dir = ({ "/players/emerson/rooms/room29.c","east"});

     cook=clone_object("/players/emerson/obj/box.c");
     move_object(cook,this_object());
        customer=clone_object("players/emerson/mons/cooler.c");
        move_object(customer,this_object());
     driver = clone_object("players/emerson/mons/driverm.c");
     move_object(driver,this_object());
     manager = clone_object("players/emerson/mons/manager.c");
      move_object(manager,this_object());
}
