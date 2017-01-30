inherit "room/room";
 
reset(arg) {
  object customer,luca;
    int abc;
    if(arg) return;
    set_light(1);
    long_desc = "As you enter the room you begin to smell something like fish.\n"+
    "While you are puzzling over the smell, you notice a very tough looking\n"+
    "person is in the room with you. If you are quiet maybe\n"+
    "you can sneak out before he notices you\n";
   short_desc = "The Dining Area";
    dest_dir = ({ "/players/emerson/rooms/dine1.c","west",
                  "/players/emerson/rooms/dine11.c","south"});

    luca=clone_object("players/emerson/mons/luca.c");
    move_object(luca,this_object());

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
