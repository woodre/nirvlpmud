inherit "room/room";
 
reset(arg) {
object customer,vito;
    int abc;
    if(arg) return;
    set_light(1);
    long_desc = "You have entered the back room of the dining area which is\n"+
    "reserved for VERY special guests. I wouldn't disturb em if I were you!\n";
   short_desc = "The Dining Area";
    dest_dir = ({ "/players/emerson/rooms/dine2.c","west",
                  "/players/emerson/rooms/dine10.c","north"});

     vito = clone_object("players/emerson/mons/vito.c");
     move_object(vito,this_object());

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
