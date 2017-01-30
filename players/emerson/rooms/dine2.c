inherit "room/room";
 
reset(arg) {
object customer,fredo;
    int abc;
    if(arg) return;
    set_light(1);
    long_desc = "It seems the whole Corleone family has made an outing to Pizza Hut!\n"+
    "They seem to have overrun the place, maybe you should try to kick em out!\n"+
    "Be careful though, they look pretty tough!\n";
   short_desc = "The Dining Area";
    dest_dir = ({ "/players/emerson/rooms/dine1.c","north",
                 "/players/emerson/rooms/dine11.c","east",
            "/players/emerson/rooms/room3.c","west",
                  "/players/emerson/rooms/dine3.c","south"});

     fredo=clone_object("players/emerson/mons/fredo.c");
     move_object(fredo,this_object());

    abc = 0;
/* if (!present("customer")) changed to check for man  -Snow */
  if(!present("button man"))
     {
      while(abc<3) 
       {
        abc += 1;
        customer=clone_object("players/emerson/closed/button.c");
        move_object(customer,this_object());
       }
     }
}
